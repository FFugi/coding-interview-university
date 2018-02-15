#include "MyList.hpp"
#include "gtest/gtest.h"

TEST(Confirming_setup_ok, dummy){
}

TEST(LIST, size){
	MyList<int> list;
	EXPECT_EQ(list.getSize(), 0);
	list.pushBack(1);
	EXPECT_EQ(list.getSize(), 1);
	list.pushBack(-121);
	list.pushBack(345);
	list.pushBack(42);
	list.pushBack(314);
	list.pushBack(78);
	EXPECT_EQ(list.getSize(), 6);
	list.popBack();
	list.popBack();
	EXPECT_EQ(list.getSize(), 4);
}

TEST(LIST, empty){
	MyList<int> list;
	EXPECT_EQ(list.empty(), true);
	list.pushBack(1);
	EXPECT_EQ(list.empty(), false);
	list.pushBack(-121);
	list.pushBack(67);
	list.pushBack(42);
	EXPECT_EQ(list.empty(), false);
	list.popBack();
	EXPECT_EQ(list.empty(), false);
	list.popBack();
	list.popBack();
	list.popBack();
	EXPECT_EQ(list.empty(), true);
}

TEST(LIST, erase){
	MyList<int> list;
	list.pushBack(5090);
	list.pushBack(3);
	list.pushBack(81);
	list.pushBack(6);
	list.eraseAt(1);

	EXPECT_EQ(list.valueAt(0), 5090);
	EXPECT_EQ(list.valueAt(1), 81);
	EXPECT_EQ(list.valueAt(2), 6);
	EXPECT_EQ(list.getSize(), 3);

	list.eraseAt(0);

	EXPECT_EQ(list.valueAt(0), 81);
	EXPECT_EQ(list.valueAt(1), 6);
	EXPECT_EQ(list.getSize(), 2);

	list.pushFront(-8);
	list.pushFront(58);
	list.pushBack(123);
	list.pushBack(321);

	EXPECT_EQ(list.valueAt(0), 58);
	EXPECT_EQ(list.valueAt(1), -8);
	EXPECT_EQ(list.valueAt(2), 81);
	EXPECT_EQ(list.valueAt(3), 6);
	EXPECT_EQ(list.valueAt(4), 123);
	EXPECT_EQ(list.valueAt(5), 321);
	EXPECT_EQ(list.getSize(), 6);
}

TEST(LIST, reverse){
	MyList<int> list;
	list.pushBack(5090);
	list.pushBack(3);
	list.pushBack(81);
	list.pushBack(6);

	list.reverse();
	EXPECT_EQ(list.getSize(), 4);	
	
	EXPECT_EQ(list.valueAt(0), 6);	
	EXPECT_EQ(list.valueAt(1), 81);	
	EXPECT_EQ(list.valueAt(2), 3);	
	EXPECT_EQ(list.valueAt(3), 5090);	
}
