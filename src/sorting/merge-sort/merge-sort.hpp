#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
void mergeSort(T * arr, std::size_t size){
	if(size == 1){
		return;
	}	
	std::size_t midpoint = size / 2; 
	T left[midpoint];
	T right[size - midpoint];
	for(std::size_t i = 0; i < midpoint; i++){
		left[i] = arr[i];
	}
	for(std::size_t i = 0; i < size - midpoint; i++){
		right[i] = arr[midpoint + i];
	}
	mergeSort(left, midpoint);
	mergeSort(right, size - midpoint);
	std::size_t leftIndex = 0, rightIndex = 0, i = 0;
	//merge
	while(i < size){
		if(leftIndex >= midpoint){
			arr[i] = right[rightIndex];
			rightIndex++;
		}
		else if(rightIndex >= size - midpoint){
			arr[i] = left[leftIndex];
			leftIndex++;
		}
		else if(left[leftIndex] < right[rightIndex]){
			arr[i] = left[leftIndex];
			leftIndex++;
		}
		else{
			arr[i] = right[rightIndex];
			rightIndex++;
		}
		i++;
	}
}
