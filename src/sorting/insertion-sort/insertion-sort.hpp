#pragma once
#include <cstddef>
#include <algorithm>

template <typename T>
void insertionSort(T * arr, std::size_t size){
	for(std::size_t i = 1; i < size; i++){
		if(arr[i] < arr[i-1]){
			std::size_t j = i;
			while(arr[j] < arr[j-1] && j > 0){
				std::swap(arr[j], arr[j-1]);
				j--;
			}
		}	
	}
}
