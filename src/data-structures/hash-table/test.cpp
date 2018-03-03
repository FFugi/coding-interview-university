#include "Dictionary.hpp"
#include "gtest/gtest.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

#define X_EXPECT_EQ(a, b, format, ...) \
	EXPECT_EQ(a, b); \
	if (a != b) printf(format, __VA_ARGS__);

std::string generateString(std::size_t length){
	std::string alfanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string output;
	for(std::size_t i = 0; i < length; i++){
		int position = rand() % alfanum.size();
		output += alfanum[position];	
	}
	return output;
}

template <typename T>
struct testRecord {
	std::string key;
	T record;
};

TEST(ConfirmingSetupOk, dummy){
}

TEST(Dictionary, exists){
	Dictionary<int> dict;
	dict.add("Andrzej", 42);
	dict.add("Mieciu", 256);
	dict.add("Monika", 128);
	dict.add("Wiesiu", 64);
	dict.add("Zosia", 1024);
	dict.add("Anna", 32);
	EXPECT_TRUE(dict.exists("Andrzej"));	
	EXPECT_TRUE(dict.exists("Mieciu"));	
	EXPECT_TRUE(dict.exists("Monika"));	
	EXPECT_TRUE(dict.exists("Wiesiu"));	
	EXPECT_TRUE(dict.exists("Zosia"));	
	EXPECT_TRUE(dict.exists("Anna"));	

	dict.remove("Andrzej");
	dict.remove("Wiesiu");
	EXPECT_FALSE(dict.exists("Andrzej"));	
	EXPECT_TRUE(dict.exists("Mieciu"));	
	EXPECT_TRUE(dict.exists("Monika"));	
	EXPECT_FALSE(dict.exists("Wiesiu"));	
	EXPECT_TRUE(dict.exists("Zosia"));	
	EXPECT_TRUE(dict.exists("Anna"));	

	dict.remove("Mieciu");
	dict.add("Wiesiu", 256);
	EXPECT_TRUE(dict.exists("Wiesiu"));	


}

TEST(Dictionary, resize){
	Dictionary<int> dict;
	dict.add("Andrzej", 42);
	dict.add("Mieciu", 256);
	dict.add("Monika", 128);
	dict.add("Wiesiu", 64);
	dict.add("Zosia", 1024);
	dict.add("Anna", 32);
	dict.add("Wojtek", 32);
	dict.add("Marysia", 32);
	dict.add("Waldek", 32);
	dict.add("Jan", 32);
	dict.add("Grzegorz", 32);
	dict.add("Zenon", 32);
	dict.add("Arek", 32);
	dict.add("Marek", 32);
	dict.add("Marej", 32);
}

TEST(Dictionary, printing){
	Dictionary<int> dict;
	dict.add("Andrzej", 42);
	dict.add("Mieciu", 256);
	dict.add("Monika", 128);
	dict.add("Wiesiu", 64);
	dict.add("Zosia", 1024);
	dict.add("Anna", 32);
	dict.add("Wojtek", 32);
	dict.add("Marysia", 32);
	dict.add("Waldek", 32);
	dict.add("Jan", 32);
	dict.add("Greg", 32);
	dict.add("Zenon", 32);
	dict.add("Arek", 32);
	dict.add("Marek", 32);
	dict.add("Marej", 32);
	std::cout << dict;
}

TEST(Dictionary, get){
	srand(time(0));
	std::size_t records = 100;
	Dictionary<int> dict;

	testRecord<int> * testArr = new testRecord<int>[records];
	for(std::size_t i = 0; i < records; i++){
		std::size_t length = rand() % 6 + 1; 
		int record = rand() % 100 - 50;
		testArr[i].key = generateString(length);	
		testArr[i].record = record;
		dict.add(testArr[i].key, testArr[i].record);
	}
	for(std::size_t i = 0; i < records; i++){
		std::cout << i << ".\t" << testArr[i].key << std::endl;
	}
	for(std::size_t i = 0; i < records; i++){
		X_EXPECT_EQ(dict.get(testArr[i].key), testArr[i].record, "%i, %s, %i\n", i, testArr[i].key.c_str(), testArr[i].record);	
	}
}
