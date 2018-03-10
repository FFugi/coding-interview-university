#ifndef BST_HPP
#define BST_HPP
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stack>

template <typename T>
class Bst{
	private:

		struct Node{
			Node() : greater(nullptr), lesser(nullptr), parent(nullptr) {}
			Node * greater;
			Node * lesser;
			Node * parent;
			T value;
		};

		Node * root;
		std::size_t nodeCount;

	public:

		Bst() : nodeCount(0){
			root = new Node();
		}


		void insert(T value){
			if(nodeCount == 0){
				root->value = value;
				nodeCount++;
				return;
			}
			Node * toInsert = new Node();
			toInsert->value = value;
			toInsert->parent = nullptr;
			Node * iterator = root;
			bool found = false;
			while(!found){
				if(value > iterator->value){
					if(iterator->greater == nullptr){
						found = true;
					}
					else{
						iterator = iterator->greater;
					}	
				}	
				else if(value < iterator->value){
					if(iterator->lesser == nullptr){
						found = true;
					}
					else{
						iterator = iterator->lesser;
					}
				}
				else{
					return;
				}
			}
			toInsert->parent = iterator;
			if(value < iterator->value){
				iterator->lesser = toInsert;
			}
			else{
				iterator->greater = toInsert;
			}
			nodeCount++;
		}

		T getMin(){
			return getMinOfSubtree(root)->value;
		}

		T getMax(){
			return getMaxOfSubtree(root)->value;
		}

		std::size_t getNodeCount(){
			return nodeCount;
		}

		bool isInTree(T value){
			Node * iterator = root;
			while(iterator->value != value){
				if(value < iterator->value && iterator->lesser != nullptr){
					iterator = iterator->lesser;	
				}
				else if(value > iterator->value && iterator->greater != nullptr){
					iterator = iterator->greater;	
				}
				else{
					return false;
				}
			}
			return true;
		}

		void printValues(std::stringstream & sstream){
			if(nodeCount == 0){
				return;
			}
			else if(nodeCount == 1){
				sstream << root->value << " ";
				return;
			}
			std::stringstream ss;
			std::stack<Node*> toPrint;
			Node * current = root;
			toPrint.push(current);
			bool goingLeft = true;
			std::size_t printed = 0;
			while(printed != nodeCount){	
				if(goingLeft){
					toPrint.push(current);
				}
				if(current->lesser != nullptr && goingLeft){
					current = current->lesser;
				}
				else{
					sstream << current->value << " ";
					printed++;
					toPrint.pop();
					if(current->greater != nullptr){
						current = current->greater;
						goingLeft = true;
					}
					else{
						current = toPrint.top();
						goingLeft = false;
					}
				}
			}
		}

		std::size_t getHeight(){
			if(nodeCount == 0){
				return 0;
			}
			struct heightInfoNode{
				heightInfoNode():node(nullptr), height(0){};
				Node * node;
				std::size_t height;
			};
			std::size_t maxHeight = 1;
			std::size_t currentHeight = 1;
			std::size_t visited = 1;
			Node * iterator = root;
			std::stack<heightInfoNode> nodes;
			heightInfoNode current;
			bool goingLeft = true;
			while(visited != nodeCount){
				if(maxHeight < currentHeight){
					maxHeight = currentHeight;	
				}
				if(goingLeft){
					current.node = iterator;
					current.height = currentHeight;
					nodes.push(current);
					visited++;
				}
				if(iterator->lesser != nullptr && goingLeft){
					currentHeight++;
					iterator = iterator->lesser;
				}
				else{
					nodes.pop();
					if(iterator->greater != nullptr){
						currentHeight++;
						iterator = iterator->greater;
						goingLeft = true;
					}
					else{
						iterator = nodes.top().node;
						currentHeight = nodes.top().height;
						goingLeft = false;
					}
				}
			}
			return maxHeight;
		}

		void deleteValue(T value){
			
		}

		~Bst(){
			std::stack<Node*> toDelete;
			Node * current = root;
			Node * greaterFromDeleted;
			toDelete.push(current);
			bool goingLeft = true;
			std::size_t deleted = 0;
			while(deleted != nodeCount){	
				if(goingLeft){
					toDelete.push(current);
				}
				if(current->lesser != nullptr && goingLeft){
					current = current->lesser;
				}
				else{
					greaterFromDeleted = current->greater;
					delete current;
					deleted++;
					toDelete.pop();
					if(greaterFromDeleted != nullptr){
						current = greaterFromDeleted;
						goingLeft = true;
					}
					else{
						current = toDelete.top();
						goingLeft = false;
					}
				}
			}
		}

	private:
		Node * getMinOfSubtree(Node * subRoot){
			Node * iterator = subRoot;
			while(iterator->lesser != nullptr){
				iterator = iterator->lesser;
			}
			return iterator;
		}

		Node * getMaxOfSubtree(Node * subRoot){
			Node * iterator = subRoot;
			while(iterator->greater != nullptr){
				iterator = iterator->greater;
			}
			return iterator;
		}
};


#endif
