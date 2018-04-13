#include "heap.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <string>

TEST(CheckingSetupOk, dummy){
}

TEST(Heap, getMax){
	Heap<int> hip;
	hip.insert(-42);
	EXPECT_EQ(hip.getMax(), -42);
	hip.insert(42);
	EXPECT_EQ(hip.getMax(), 42);
	hip.insert(700);
	EXPECT_EQ(hip.getMax(), 700);
	hip.insert(151);
	EXPECT_EQ(hip.getMax(), 700);
	hip.insert(32);
	EXPECT_EQ(hip.getMax(), 700);
}

TEST(Heap, isEmpty){
	Heap<int> hip;
	EXPECT_TRUE(hip.isEmpty());
	hip.insert(42);
	EXPECT_FALSE(hip.isEmpty());
}

TEST(Heap, getSize){
	Heap<int> hip;
	EXPECT_EQ(hip.getSize(), 0);

	hip.insert(232);
	EXPECT_EQ(hip.getSize(), 1);

	hip.insert(123);
	EXPECT_EQ(hip.getSize(), 2);

	hip.insert(0);
	EXPECT_EQ(hip.getSize(), 3);

	hip.insert(-19);
	EXPECT_EQ(hip.getSize(), 4);
}

TEST(Heap, extractMax){
	Heap<int> hip;
	hip.insert(30);
	hip.insert(0);
	hip.insert(42);
	hip.insert(-100);
	hip.insert(-200);
	EXPECT_EQ(hip.extractMax(), 42);
	EXPECT_EQ(hip.extractMax(), 30);
	EXPECT_EQ(hip.extractMax(), 0);
	EXPECT_EQ(hip.extractMax(), -100);
	EXPECT_EQ(hip.extractMax(), -200);

	hip.insert(15);
	hip.insert(5);
	hip.insert(10);
	hip.insert(3);
	hip.insert(4);
	hip.insert(7);
	hip.insert(6);
	EXPECT_EQ(hip.extractMax(), 15);
	EXPECT_EQ(hip.extractMax(), 10);
	EXPECT_EQ(hip.extractMax(), 7);
	EXPECT_EQ(hip.extractMax(), 6);
	EXPECT_EQ(hip.extractMax(), 5);
	EXPECT_EQ(hip.extractMax(), 4);
	EXPECT_EQ(hip.extractMax(), 3);
}

TEST(Heap, heapSort){
	int testData[] {5,4,10,-123,2354};
	Heap<int>::heapSort(testData, 5);
	EXPECT_EQ(testData[0], -123);
	EXPECT_EQ(testData[1], 4);
	EXPECT_EQ(testData[2], 5);
	EXPECT_EQ(testData[3], 10);
	EXPECT_EQ(testData[4], 2354);

	int testData2[] {1, 1, 998, 1, 999, -3, 90, 42, 997, 232};
	Heap<int>::heapSort(testData2, 10);
	EXPECT_EQ(testData2[0], -3);
	EXPECT_EQ(testData2[1], 1);
	EXPECT_EQ(testData2[2], 1);
	EXPECT_EQ(testData2[3], 1);
	EXPECT_EQ(testData2[4], 42);
	EXPECT_EQ(testData2[5], 90);
	EXPECT_EQ(testData2[6], 232);
	EXPECT_EQ(testData2[7], 997);
	EXPECT_EQ(testData2[8], 998);
	EXPECT_EQ(testData2[9], 999);

	int testData3[] {15,5,10,3,4,7,6};
	Heap<int>::heapSort(testData3, 7);
	EXPECT_EQ(testData3[0], 3);
	EXPECT_EQ(testData3[1], 4);
	EXPECT_EQ(testData3[2], 5);
	EXPECT_EQ(testData3[3], 6);
	EXPECT_EQ(testData3[4], 7);
	EXPECT_EQ(testData3[5], 10);
	EXPECT_EQ(testData3[6], 15);
}

