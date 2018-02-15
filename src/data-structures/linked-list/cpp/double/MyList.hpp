#ifndef MYLIST_HPP
#define MYLIST_HPP
#include <cstddef>
#include <iostream>

template <typename E>
class MyList{
	private:
		class Node{
			public:
			Node *prev;
			Node *next;
			E value;
		};

		Node *front;
		Node *tail;
		std::size_t size;

		inline Node *getNodeAtIndex(std::size_t index){
			Node *searchNode;
			if(index < size/2){
				searchNode = front;
				for(std::size_t i = 0; i < index;i++){
					searchNode=searchNode->prev;					
				}
			}
			else{
				searchNode = tail;
				for(std::size_t i = size-1; i > index;i--){
					searchNode=searchNode->next;					
				}
			}
			return searchNode;
		}

	public:
		MyList(){
			front = NULL;
			tail = NULL;
			size = 0; 
		}

		MyList(const MyList &list){
			size = list.size;
			if(size == 0){
				return;
			}
			Node *toInsert = new Node;
			Node *iterationNode = list.front;
			toInsert->value = list.front->value;
			toInsert->next = NULL;
			front = toInsert;
			for(std::size_t i = 0; i<list.size; i++){
				iterationNode = iterationNode->prev;
				Node *prevToInsert;
				if(i != 0){
					prevToInsert = toInsert;
				}
				if(i != list.size-1){
					toInsert->prev = new Node;
					toInsert = toInsert->prev;	
					toInsert->next = prevToInsert;
					toInsert->value = iterationNode->value;
				}
			}
			toInsert->prev = NULL;
			tail = toInsert;
		}

		~MyList(){
			if(size<0){
				return;
			}
			Node *iterationNode = front;
			for(std::size_t i = 0; i < size; i++){
				Node *toDelete = iterationNode;
				iterationNode = iterationNode->prev;	
				delete toDelete;
			}
		}

		std::size_t getSize(){
			return size;
		}

		bool empty(){
			return !size;	
		}

		void pushBack(E item){
			Node *node = new Node();
			node->value = item;
			node->prev = NULL;
			if(!size){	
				node->next = NULL;
				front = node;
			}
			else{
				tail->prev = node;
				node->next = tail;
			}
			tail = node;
			size++;
		}

		E popBack(){
			if(size){
				E value = tail->value;
				Node *toDelete = tail;
				if(size!=1){
					tail = tail->next;
					tail->prev = NULL;
				}
				else{
					front = NULL;
					tail = NULL;
				}
				delete toDelete;
				size--;
				return value;
			}
			else{
				//place for exception
			}
		}

		void pushFront(E item){
			Node *node = new Node();
			node->value = item;
			node->next = NULL;
			if(!size){	
				node->prev = NULL;
				tail = node;
			}
			else{
				front->next = node;
				node->prev = front;
			}	
			front = node;
			size++;
		}

		E popFront(){
			if(size){
				E value = front->value;
				Node *toDelete = front;
				if(size!=1){
					front = front->prev;
					front->next = NULL;
				}
				else{
					front = NULL;
					tail = NULL;
				}
				delete toDelete;
				size--;
				return value;
			}
			else{
				//place for exception
			}
		}

		E seeFront(){
			return front->value;
		}

		E seeBack(){
			return tail->value;
		}

		E valueAt(std::size_t index){
			if(index<size){
				Node *node = getNodeAtIndex(index);
				return node->value;
			}
		}

		E valueAtFromEnd(std::size_t index){
			return valueAt(size-index-1);
		}
		
		void insertAt(std::size_t index, E item){
			Node *toInsertNode = new Node();
			toInsertNode->value = item; 
			if(index==0){
				toInsertNode->prev = front;
				toInsertNode->next = NULL;
				front->next = toInsertNode;
				front = toInsertNode;
			}
			else{
				Node *searchNode = getNodeAtIndex(index);
				toInsertNode->next = searchNode->next;		
				toInsertNode->prev = searchNode;
				searchNode->next->prev = toInsertNode;
				searchNode->next = toInsertNode;
			}
			size++;
		}

		void eraseAt(std::size_t index){
			Node *toErase;
			if(index == 0){
				toErase = front;
				if(size == 1){
					front = NULL;
					tail = NULL;	
				}
				else{
					front = front->prev;
					front->next = NULL;
				}
			}
			else if(index == size-1){
				toErase = tail;
				tail = tail->next;
				tail->prev = NULL;
			}
			else{
				Node *searchNode = getNodeAtIndex(index);
				toErase = searchNode;
				toErase->next->prev = toErase->prev;
				toErase->prev->next = toErase->next;
			}
			delete toErase;
			size--;
		}

		void remove(E value){
			Node *searchNode = front;
			std::size_t i = 0;
			for(;i < size && searchNode->value != value; i++){
				searchNode=searchNode->prev;	
			}
			if(searchNode->value == value){
				eraseAt(i);
			}
		}

		void reverse(){
			if(size < 2){
				return;
			}
			Node *iterationFront = front;
			Node *iterationTail = tail;
			for(std::size_t i = 0; i < size/2; i++){
				E tmp = iterationFront->value;
				iterationFront->value = iterationTail->value;
				iterationTail->value = tmp;
				iterationTail = iterationTail->next;
				iterationFront = iterationFront->prev;
			}
		}
};

#endif
