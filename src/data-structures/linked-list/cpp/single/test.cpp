#include "SingleList.hpp"
#include "gtest/gtest.h"

TEST(SingleList, pushBack){
	SingleList<int> list;
	list.pushBack(3);
	EXPECT_EQ(list.seeFront(), 3);
	EXPECT_EQ(list.seeBack(), 3);
	list.pushBack(9);
	EXPECT_EQ(list.seeFront(), 3);
	EXPECT_EQ(list.seeBack(), 9);
	list.pushBack(-42);
	EXPECT_EQ(list.seeFront(), 3);
	EXPECT_EQ(list.seeBack(), -42);
}

TEST(SingleList, pushFront){
	SingleList<int> list;
	list.pushFront(10);
	EXPECT_EQ(list.seeFront(), 10);
	EXPECT_EQ(list.seeBack(), 10);
	list.pushFront(42);
	EXPECT_EQ(list.seeFront(), 42);
	EXPECT_EQ(list.seeBack(), 10);
	list.pushFront(314);
	EXPECT_EQ(list.seeFront(), 314);
	EXPECT_EQ(list.seeBack(), 10);
}

TEST(SingleList, valueAt){
	SingleList<int> list;
	list.pushFront(10);
	list.pushFront(11);
	list.pushFront(12);
	list.pushBack(512);
	EXPECT_EQ(list.valueAt(0), 12);
	EXPECT_EQ(list.valueAt(1), 11);
	EXPECT_EQ(list.valueAt(2), 10);
	EXPECT_EQ(list.valueAt(3), 512);
}

TEST(SingleList, pop){
	SingleList<int> list;
	list.pushFront(10);
	list.pushFront(11);
	list.pushFront(12);
	list.pushBack(512);
	EXPECT_EQ(list.popFront(), 12);
	EXPECT_EQ(list.getSize(), 3);
	EXPECT_EQ(list.popBack(), 512);
	EXPECT_EQ(list.getSize(), 2);

}

TEST(SingleList, insertAt){
	SingleList<int> list;
	list.pushFront(10);
	list.pushFront(11);
	list.pushFront(12);
	list.pushBack(512);
	list.insertAt(0, 4);
	EXPECT_EQ(list.seeFront(), 4);
	EXPECT_EQ(list.getSize(), 5);

	EXPECT_EQ(list.valueAt(0), 4);
	EXPECT_EQ(list.valueAt(1), 12);
	EXPECT_EQ(list.valueAt(2), 11);
	EXPECT_EQ(list.valueAt(3), 10);
	EXPECT_EQ(list.valueAt(4), 512);

	list.insertAt(4, 94);
	EXPECT_EQ(list.valueAt(4), 94);

}
