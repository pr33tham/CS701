/*
main.cpp : This file contains the 'main' function.
Program execution begins and ends there.
*/

#include<iostream>
#include <chrono>
#include <iomanip> 
#include <random>
#include "vEBTreePriorityQueue.h"
#include "BinaryHeapPriorityQueue.h"

int randomNumber(int min, int max) {
	static std::vector<int> numbers;
	static std::mt19937 gen(std::random_device{}());

	if (numbers.empty()) {
		for (int i = min; i <= max; ++i) {
			numbers.push_back(i);
		}
		std::shuffle(numbers.begin(), numbers.end(), gen);
	}

	int num = numbers.back();
	numbers.pop_back();
	return num;
}

int main() {
	int nValues[5] = { 100, 1000, 10000, 100000, 1000000 };
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<int> dis();
	std::uniform_int_distribution<> randInt(0, 2);

	for (int i = 0; i < 5;  i++) {
		BinaryHeapPriorityQueue<int> heapPriorityQueue(nValues[i]);
		vEBTreePriorityQueue<int> vEBPriorityQueue(nValues[i]);

		//CASE 1
		auto start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < nValues[i]; j++) {
			int priority = randomNumber(0, nValues[i] - 1);
			heapPriorityQueue.Insert(priority, priority);
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end -start);
		double computedTime = duration.count();
		std::cout << "Total time to insert " << nValues[i] << " elements "
			<< " into HeapBinaryPriorityQueue is " << std::fixed << computedTime << std::setprecision(1)<< " ms." << std::endl;

		//CASE 2
		start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < nValues[i]; j++) {
			int priority = randomNumber(0, nValues[i] - 1);
			vEBPriorityQueue.Insert(priority, priority);
		}
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		computedTime = duration.count();
		std::cout << "Total time to insert " << nValues[i] <<" elements "
			<< " into vEBPriorityQueue is " << std::fixed << computedTime << std::setprecision(1) <<" ms." << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		BinaryHeapPriorityQueue<int> queue(nValues[i]);
		vEBTreePriorityQueue<int> vebqueue(nValues[i]);

		int offset = nValues[i] + 100;
		int m = randomNumber(nValues[i], offset);

		//CASE 3
		auto start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < m; j++) {

			int priority = randomNumber(0, nValues[i] - 1);
			int oldPriority = priority;
			int operation = randInt(gen);

			if (operation == 0) {
				// ExtractMax operation
				if (!queue.SIZE == 0)
					queue.ExtractMax();
			}
			else if (operation == 1) {
				// Insert operation
				queue.Insert(priority, priority);
			}
			//else {
			//	// IncreaseKey operation
			//	queue.IncreaseKey(oldPriority , oldPriority+10);
			//}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		auto computedTime = duration.count();
		std::cout << "Time to do m >= n operation on " << nValues[i] << " elements "
			<< " for BinaryHeap Prioritiy Queue is  " << std::fixed << computedTime << std::setprecision(1) << " ms." << std::endl;

		//CASE 4
		start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < m; j++) {

			int priority = randomNumber(0, nValues[i] - 1);
			int oldPriority = priority;
			int operation = randInt(gen);

			if (operation == 0) {
				// ExtractMax operation
				try {
				vebqueue.ExtractMax();
				}
				catch (...) {

				}
			}
			else if (operation == 1) {
				// Insert operation
				queue.Insert(oldPriority, priority);
			}
			//else {
			//	// IncreaseKey operation
			//	queue.IncreaseKey(priority , priority+10);
			//}
		}
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		computedTime = duration.count();
		std::cout << "Time to do m >= n operation on " << nValues[i] << " elements "
			<< " for vEBPrioritiy Queue is  " << std::fixed << computedTime << std::setprecision(1) << " ms." << std::endl;
	}
}