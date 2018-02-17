#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP
#include <cstddef>

template<typename E>
class SingleList{
	private:
		class Node{
			public:
				Node *next;
				E value;
		};	
		
		Node * front;
		Node * tail;

		std::size_t size;

		inline Node * getNodeAt(std::size_t index){
			Node * iterator = front;
			for(std::size_t i = 0; i < index; i++){
				iterator = iterator->next;
			}
			return iterator;
		}
	public:
		SingleList(){
			size = 0;
			front = NULL;
			tail = NULL;
		}

		// TO DO: copying constructor
		
		~SingleList(){
		// TO DO: delete all nodes	
		}

		std::size_t getSize(){
			return size;
		}

		bool empty(){
			return !size;
		}

		void pushBack(E item){
			Node * node = new Node();
			node->value = item;
			node->next = NULL;
			if(size > 0){
				tail->next = node;
			}
			else{
				front = node;
			}
			tail = node;		
			size++;
		}

		void pushFront(E item){
			Node * node = new Node();
			node->value = item;
			if(size > 0){
				node->next = front;
			}
			else{
				tail = node;
			}
			front = node;
			size++;

		}

		E popBack(){
			E value = tail->value;	
			Node * newTail = getNodeAt(size-2);
			delete tail;
			tail = newTail;
			size--;
			return value;
		}

		E popFront(){
			E value = front->value;	
			Node * newFront = front->next;
			delete front;
			front = newFront;
			size--;
			return value;
		}

		E valueAt(std::size_t index){
			if(index >= size){
				// place for exception
			}
			Node * iterator = getNodeAt(index);
			return iterator->value;
		}

		E valueAtFromEnd(std::size_t index){
			return valueAt(size - 1 - index);
		}

		void insertAt(std::size_t index, E value){
			if(index >= size){
				// place for exception
			}
			// TO DO: egde situations
			if(index == 0){
				pushFront(value);
				return;
			}
			else{
				Node * toInsert = new Node;
				toInsert->value = value;
				Node * prev = getNodeAt(index-1);
				toInsert->next = prev->next;
				prev->next = toInsert;
				size++;
			}	
		}
		
		E seeFront(){
			if(empty()){
				//place for exception
			}
			return front->value;	
		}

		E seeBack(){
			if(empty()){
				//place for exception
			}
			return tail->value;	
		}

		void erase(std::size_t index){
			if(index >= size){
				//place for exception
			}
			Node * prev = getNodeAt(index-1);
			Node * toDelete = prev->next;
			prev->next = toDelete->next;
			delete toDelete;
			size--;
		}

		void reverse(){

		}
};

#endif
