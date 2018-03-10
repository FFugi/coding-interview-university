#include "bst.hpp"
#include "gtest/gtest.h"

TEST(CheckingSetupOk, dummy){
}

TEST(BinarySearchTree, insert){
	Bst<int> tree;	
	tree.insert(10);
	tree.insert(20);
	tree.insert(42);
	tree.insert(0);
	tree.insert(-100);
}

TEST(BinarySearchTree, getMinGetMax){
	Bst<int> tree;	
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

TEST(BinarySearchTree, isInTree){
	Bst<int> tree;	
	tree.insert(10);
	tree.insert(20);
	tree.insert(999);
	tree.insert(0);
	tree.insert(-112);
	tree.insert(321);
	tree.insert(123);
	EXPECT_TRUE(tree.isInTree(10));
	EXPECT_TRUE(tree.isInTree(20));
	EXPECT_TRUE(tree.isInTree(999));
	EXPECT_TRUE(tree.isInTree(0));
	EXPECT_TRUE(tree.isInTree(-112));
	EXPECT_TRUE(tree.isInTree(321));
	EXPECT_TRUE(tree.isInTree(123));
	EXPECT_FALSE(tree.isInTree(124));
	EXPECT_FALSE(tree.isInTree(1));
	EXPECT_FALSE(tree.isInTree(-1));
}	

TEST(BinarySearchTree, print){
	Bst<int> tree;	
	tree.insert(42);
	tree.insert(0);
	tree.insert(201);
	tree.insert(-300);
	tree.insert(-303);
	tree.insert(-301);
	tree.insert(-298);
	tree.printValues();
}

TEST(BinarySearchTree, print2){
	Bst<int> tree;	
	tree.insert(42);
	tree.insert(0);
	tree.insert(201);
	tree.insert(-300);
	tree.insert(300);
	tree.insert(255);
	tree.insert(100000);
	tree.insert(-10000);
	tree.insert(-303);
	tree.insert(-301);
	tree.insert(-298);
	tree.printValues();
}

TEST(BinarySearchTree, getHeight){
	Bst<int> tree;	
	tree.insert(42);
	tree.insert(0);
	tree.insert(201);
	tree.insert(-300);
	tree.insert(-303);
	tree.insert(-301);
	tree.insert(-298);
	EXPECT_EQ(tree.getHeight(), 5);
	tree.insert(-304);
	EXPECT_EQ(tree.getHeight(), 5);
	tree.insert(-302);
	EXPECT_EQ(tree.getHeight(), 6);
	tree.insert(-2302);
	EXPECT_EQ(tree.getHeight(), 6);
	tree.insert(-10004);
	EXPECT_EQ(tree.getHeight(), 7);
	tree.insert(1000);
	tree.insert(1024);
	tree.insert(2000);
	tree.insert(3000);
	tree.insert(4000);
	tree.insert(5000);
	tree.insert(5500);
	tree.insert(6000);
	EXPECT_EQ(tree.getHeight(), 9);
}

