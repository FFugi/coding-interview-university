#include "Dictionary.hpp"
#include "gtest/gtest.h"
#include <stdio.h>
#include <iostream>

TEST(ConfirmingSetupOk, dummy){
	std::cout << sizeof(bool);
}


TEST(Dictionary, get){
	Dictionary<int> dict;
	dict.add("Andrzej", 42);
	dict.add("Mieciu", 256);
	dict.add("Monika", 128);
	dict.add("Wiesiu", 64);
	dict.add("Zosia", 1024);
	dict.add("Anna", 32);
	EXPECT_EQ(dict.get("Andrzej"), 42);
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
