#include "bst.hpp"
#include "gtest/gtest.h"

TEST(CheckingSetupOk, dummy){
}

TEST(BinarysearchTree, insert){
	bst<int> tree;	
	tree.insert(10);
	tree.insert(20);
	tree.insert(42);
	tree.insert(0);
	tree.insert(-100);
}

TEST(BinarysearchTree, getMinGetMax){
	bst<int> tree;	
	tree.insert(42);
	EXPECT_EQ(tree.getMax(), 42);
	EXPECT_EQ(tree.getMin(), 42);
	tree.insert(0);
	tree.insert(201);
	tree.insert(-300);
	EXPECT_EQ(tree.getMin(), -300);
	EXPECT_EQ(tree.getMax(), 201);
	tree.insert(-303);
	tree.insert(-301);
	EXPECT_EQ(tree.getMin(), -303);
}
