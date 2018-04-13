#pragma once
#include <cstddef>
#include <algorithm>
#include <iostream>


template <typename T>
class Heap{
	private:
		T * data;
		std::size_t size;
		std::size_t capacity;

		bool isDataOnStack;

		std::size_t getLeft(std::size_t index){
			return (index + 1) * 2 - 1;
		}

		std::size_t getRight(std::size_t index){
			return (index + 1) * 2;
		}

		std::size_t getParent(std::size_t index){
			return index == 0 ? 0 :(index + 1) / 2 - 1;
		}

		void siftUp(std::size_t index){
			if(index == 0){
				return;
			}
			std::size_t parentIndex = getParent(index);
			if(data[parentIndex] < data[index]){
				std::swap(data[parentIndex], data[index]);
			}
			siftUp(parentIndex);
		}

		void siftDown(std::size_t index){
			std::size_t leftIndex = getLeft(index);
			std::size_t rightIndex = getRight(index);
			if(leftIndex >= size && rightIndex >= size){
				return;
			}
			else if(leftIndex >= size || rightIndex >= size){
				std::size_t correctIndex = 
					leftIndex >= size ? rightIndex : leftIndex;
				if(data[correctIndex] > data[index]){
					std::swap(data[correctIndex], data[index]);
				}
				return;
			}
			std::size_t indexToSwap =
			   	data[leftIndex] > data[rightIndex] ? leftIndex : rightIndex;
			if(data[indexToSwap] > data[index]){
				std::swap(data[indexToSwap], data[index]);
				siftDown(indexToSwap);
			}
		}

	public:
		Heap():size(0), capacity(8), isDataOnStack(false){
			data = new T[capacity];
		}

		Heap(T * data, std::size_t size)
			:data(data), size(size), capacity(size), isDataOnStack(true){}

		~Heap(){
			if(!isDataOnStack){
				delete [] data;
			}
		}

		void insert(T value){
			data[size] = value;
			siftUp(size);
			size++;
		}

		T getMax(){
			if(size == 0){
				// TODO exception
			}
			return data[0];
		}

		T extractMax(){
			T max = getMax();	
			std::swap(data[0], data[size-1]);
			size--;
			siftDown(0);
			return max;
		}

		std::size_t getSize(){
			return size;
		}

		bool isEmpty(){
			return size == 0;
		}
	
		void display(){
			for(std::size_t i = 0; i < size; i++){
				std::cout << data[i] << " ";
			}
			std::cout << "\n";
		}

		static void heapSort(T * items, std::size_t size){
			Heap<T> heap(items, size);
			// Heapify
			for(std::size_t i = 0; i < size; i++){
				heap.siftDown(size - 1 - i);
			}
			for(std::size_t i = 0; i < size; i++){
				heap.extractMax();
			}	
		}
};
