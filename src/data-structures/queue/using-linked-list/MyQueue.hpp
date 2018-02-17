#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP
#include <cstddef>
#include <cstdio>

template <typename T>
class MyQueue{
	private:
		class Node{
			public:
			Node * next;
			T value;
		};

		Node * head;
		Node * tail;
		
		std::size_t size;

	public:
		MyQueue(){
			size = 0;
			head = nullptr;
			tail = nullptr;
		}

		~MyQueue(){
		}

		void enqueue(T item){
			Node * toInsert;
			toInsert = new Node();
			toInsert->value = item;
			toInsert->next = nullptr;
			if(size == 0){
				head = toInsert;
			}
			else{
				tail->next = toInsert;
			}
			tail = toInsert;
			size++;
		}	

		T dequeue(){ 
			if(size == 0){
				// place for exception
			}
			T value = head->value;
			Node * toDelete = head;
			head = head->next;
			delete toDelete;
			size--;
			return value;
		}	

		bool empty(){
			return size == 0;
		}

		std::size_t getSize(){
			return size;
		}

		T seeHead(){
			if(size == 0){
				// place for exception
			}
			return head->value;
		}

		T seeTail(){
			if(size == 0){
				// place for exception
			}
			return tail->value;
		}
};

#endif
