#ifndef BST_HPP
#define BST_HPP
#include <cstddef>
#include <iostream>

template <typename T>
class bst{
	private:

		struct Node{
			Node() : greater(nullptr), lesser(nullptr) {}
			Node * greater;
			Node * lesser;
			Node * parent;
			T value;
		};

		Node * root;
		std::size_t nodeCount;

	public:

		bst() : nodeCount(0){
		}

		bst(T value) : nodeCount(1){
			root = new Node();
			root->value = value; 
			root->parent = nullptr; 
			root->greater = nullptr; 
			root->lesser = nullptr; 
		}

		void insert(T value){
			Node * toInsert = new Node();
			toInsert->value = value;
			toInsert->parent = nullptr;
			if(nodeCount == 0){
				root = toInsert;
				root->value = value;
				nodeCount++;
				return;
			}
			Node * searchNode = root;
			bool found = false;
			while(!found){
				//std::cout << searchNode->value << std::endl;
				if(value > searchNode->value){
					if(searchNode->greater == nullptr){
						found = true;
					}
					else{
						searchNode = searchNode->greater;
					}	
				}	
				else if(value < searchNode->value){
					if(searchNode->lesser == nullptr){
						found = true;
					}
					else{
						searchNode = searchNode->lesser;
					}
				}
				else{
					// to do exception when exists
				}
			}
			toInsert->parent = searchNode;
			if(value < searchNode->value){
				searchNode->lesser = toInsert;
			}
			else{
				searchNode->greater = toInsert;
			}
			nodeCount++;
		}

		T getMin(){
			Node * searchNode = root;
			while(searchNode->lesser != nullptr){
				searchNode = searchNode->lesser;
			}
			return searchNode->value;
		}

		T getMax(){
			Node * searchNode = root;
			while(searchNode->greater != nullptr){
				searchNode = searchNode->greater;
			}
			return searchNode->value;
		}

		std::size_t getNodeCount(){
			return nodeCount;
		}

		bool isInTree(){
			return false;
		}

		void printValues(){

			

		}



};

#endif
