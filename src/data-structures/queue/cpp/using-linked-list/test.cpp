#include "MyQueue.hpp"
#include "gtest/gtest.h"
#include <iostream>

TEST(CheckingSetup, dummy){

}

TEST(MyQueue_exceptionTest, exceptions){
	MyQueue<float> que;
//	EXPECT_THROW(que.seeHead(), std::exception);
	EXPECT_THROW(que.seeHead(), MyQueue<float>::ExceptionEmpty);
}

TEST(MyQueue, size){
	MyQueue<float> que;
	EXPECT_EQ(que.getSize(), 0);
	que.enqueue(3.14);
	EXPECT_EQ(que.getSize(), 1);
	que.enqueue(5.12);
	EXPECT_EQ(que.getSize(), 2);
	que.enqueue(0.2);
	que.enqueue(0.4);
	que.enqueue(0.8);
	EXPECT_EQ(que.getSize(), 5);
	que.dequeue();
	EXPECT_EQ(que.getSize(), 4);
	que.dequeue();
	que.dequeue();
	que.dequeue();
	EXPECT_EQ(que.getSize(), 1);
	que.dequeue();
	EXPECT_EQ(que.getSize(), 0);
}

TEST(MyQueue, enqueuingAndDequeuing){
	MyQueue<int> que;
	que.enqueue(128);
	EXPECT_EQ(que.dequeue(), 128);
	que.enqueue(256);
	que.enqueue(512);
	que.enqueue(1024);
	que.enqueue(2048);
	EXPECT_EQ(que.dequeue(), 256); 
	EXPECT_EQ(que.dequeue(), 512); 
	EXPECT_EQ(que.dequeue(), 1024); 
	EXPECT_EQ(que.dequeue(), 2048); 

}
