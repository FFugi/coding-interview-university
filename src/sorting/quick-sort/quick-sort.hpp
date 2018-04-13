#pragma once
#include <cstddef>
#include <algorithm>
#include <iostream>


template <typename T>
void quickSort(T * arr, std::size_t begin, std::size_t end){
	if(end - begin == 0){
		return;
	}
	T * pivot = arr + end;
	T * current = arr + begin;
	T * wall = arr + begin;
	while(*wall < *pivot){
		wall++;
		current++;
	}
	if(wall == pivot){
		quickSort(arr, begin, end-1);	
		return;
	}
	while(current != pivot){
		if(*current < *pivot){
			std::swap(*wall, *current);
			wall++;
		}
		current++;
	}
	std::swap(*pivot, *wall);
	wall = wall == arr + begin ? arr + begin : wall - 1;
	quickSort(arr, begin, wall - arr);
	quickSort(arr, wall + 1 - arr, end);
}
