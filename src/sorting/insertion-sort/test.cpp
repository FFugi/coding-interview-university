#include "insertion-sort.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <string>

TEST(CheckingSetupOk, dummy){
}

TEST(insertionSort, sort1){
	int arr [] ={115,10,-70,-123,45,32,45};
	insertionSort<int>(arr, 7);
	EXPECT_EQ(arr[0], -123); 
	EXPECT_EQ(arr[1], -70); 
	EXPECT_EQ(arr[2], 10); 
	EXPECT_EQ(arr[3], 32); 
	EXPECT_EQ(arr[4], 45); 
	EXPECT_EQ(arr[5], 45); 
	EXPECT_EQ(arr[6], 115); 

}

TEST(insertionSort, sort2){
	int arr [] ={10,10,10,10,10,10};
	insertionSort<int>(arr, 6);
	EXPECT_EQ(arr[0], 10); 
	EXPECT_EQ(arr[1], 10); 
	EXPECT_EQ(arr[2], 10); 
	EXPECT_EQ(arr[3], 10); 
	EXPECT_EQ(arr[4], 10); 
	EXPECT_EQ(arr[5], 10); 
}
