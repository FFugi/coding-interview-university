#include "bst.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <string>

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
	std::stringstream ss;
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-303 -301 -300 -298 0 42 201 ");
	tree.insert(1000);
	tree.insert(-1000);
	ss.str("");
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-1000 -303 -301 -300 -298 0 42 201 1000 ");
	tree.insert(2);
	tree.insert(2);
	ss.str("");
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-1000 -303 -301 -300 -298 0 2 42 201 1000 ");
	tree.insert(3);
	tree.insert(123);
	tree.insert(321);
	ss.str("");
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-1000 -303 -301 -300 -298 0 2 3 42 123 201 321 1000 ");
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

TEST(BinarySearchTree, deletionWithNoChildren){
	std::stringstream ss;
	Bst<int> tree;	
	tree.insert(0);
	tree.insert(-10);
	tree.insert(-5);
	tree.insert(20);
	tree.insert(31);
	tree.insert(25);
	tree.deleteValue(25);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-10 -5 0 20 31 ");
	EXPECT_EQ(tree.getNodeCount(), 5);
	ss.str("");
	tree.deleteValue(5);							// value that doesn't exist
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-10 -5 0 20 31 ");
	EXPECT_EQ(tree.getNodeCount(), 5);
	ss.str("");
	tree.deleteValue(31);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-10 -5 0 20 ");
	EXPECT_EQ(tree.getNodeCount(), 4);
}

TEST(BinarySearchTree, deletionWithOneChild){
	std::stringstream ss;
	Bst<int> tree;	
	tree.insert(0);
	tree.insert(-20);
	tree.insert(-30);
	tree.insert(-40);
	tree.insert(-60);
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(50);
	tree.deleteValue(20);
	tree.deleteValue(-20);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-60 -40 -30 0 10 30 50 ");
	EXPECT_EQ(tree.getNodeCount(), 7);
}

TEST(BinarySearchTree, deletionWithTwoChildren){
	std::stringstream ss;
	Bst<int> tree;	
	tree.insert(0);
	tree.insert(-20);
	tree.insert(-30);
	tree.insert(-40);
	tree.insert(-60);
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(50);
	tree.insert(40);
	tree.insert(15);
	tree.insert(5);
	tree.insert(45);
	tree.insert(60);
	tree.insert(39);
	tree.deleteValue(10);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-60 -40 -30 -20 0 5 15 20 30 39 40 45 50 60 ");
	EXPECT_EQ(tree.getNodeCount(), 14);

	ss.str("");
	tree.deleteValue(40);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-60 -40 -30 -20 0 5 15 20 30 39 45 50 60 ");
	EXPECT_EQ(tree.getNodeCount(), 13);

	ss.str("");
	tree.deleteValue(15);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-60 -40 -30 -20 0 5 20 30 39 45 50 60 ");
	EXPECT_EQ(tree.getNodeCount(), 12);

	ss.str("");
	tree.deleteValue(50);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-60 -40 -30 -20 0 5 20 30 39 45 60 ");
	EXPECT_EQ(tree.getNodeCount(), 11);

}

TEST(BinarySearchTree, deletionRoot){
	std::stringstream ss;
	Bst<int> tree;
	tree.insert(0);
	tree.insert(-10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(10);
	
	tree.deleteValue(0);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-10 5 10 15 ");
	EXPECT_EQ(tree.getNodeCount(), 4);

	ss.str("");
	tree.deleteValue(5);
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-10 10 15 ");
	EXPECT_EQ(tree.getNodeCount(), 3);

	tree.deleteTree();
	tree.insert(123);
	tree.insert(124);
	tree.deleteValue(123);

	ss.str("");
	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "124 ");
	EXPECT_EQ(tree.getNodeCount(), 1);
}

TEST(BinarySearchTree, deletionNonExisting){
	std::stringstream ss;
	Bst<int> tree;
	tree.insert(0);
	tree.insert(-10);
	tree.insert(-15);
	tree.insert(5);
	tree.insert(15);
	tree.insert(10);
	tree.deleteValue(666);

	tree.printValues(ss);
	EXPECT_EQ(ss.str(), "-15 -10 0 5 10 15 ");
	EXPECT_EQ(tree.getNodeCount(), 6);


}

TEST(BinarySearchTree, deletionWholeTree){
	Bst<int> tree;
	// one node
	tree.insert(232);
	tree.deleteValue(232);
	EXPECT_EQ(tree.getNodeCount(), 0);

	// all greater 
	tree.insert(151);
	tree.insert(189);
	tree.insert(207);
	tree.deleteValue(151);
	tree.deleteValue(189);
	tree.deleteValue(207);

	EXPECT_EQ(tree.getNodeCount(), 0);

	// all lesser
	tree.insert(10);
	tree.insert(5);
	tree.insert(0);
	tree.deleteValue(10);
	tree.deleteValue(5);
	tree.deleteValue(0);

	EXPECT_EQ(tree.getNodeCount(), 0);

	// both sides
	tree.insert(5);
	tree.insert(8);
	tree.insert(0);
	tree.deleteValue(5);
	tree.deleteValue(8);
	tree.deleteValue(0);

	EXPECT_EQ(tree.getNodeCount(), 0);
}

TEST(BinarySearchTree, getSuccessor){
	Bst<int> tree;
	tree.insert(10);
	tree.insert(40);
	tree.insert(70);
	tree.insert(0);
	tree.insert(-15);
	EXPECT_EQ(tree.getSuccessor(-15), 0);


}
