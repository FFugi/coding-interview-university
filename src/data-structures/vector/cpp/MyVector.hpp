#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <cstddef>
#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

using namespace std;

template <typename E>
class MyVector{
	private:
		E *items;
		size_t currentCapacity;
		size_t occupied;

		void resize(size_t newCapacity){
			E *tmpObjects = new E [newCapacity];
			for(size_t i=0;i<min(currentCapacity,newCapacity);i++){
				tmpObjects[i]=items[i];
			}
			delete [] items;
			currentCapacity=newCapacity;
			items = tmpObjects;
		}

		void moveLeft(size_t positions, size_t from){
			for(size_t i=from;i<occupied-positions;i++){
				items[i]=items[i+positions];
			}	
		}

		void shrinkIfNeeded(){
			if(occupied<currentCapacity/4){
				resize(currentCapacity/2);
			}
		}
	public:
		MyVector(){
			currentCapacity = 16;
			occupied=0;
			items = new E [currentCapacity];	
		}

		~MyVector(){
			delete [] items;	
		}

		E &front(){
			if(occupied){
				return items[0];
			}
			else{
				// place for exception
				throw std::invalid_argument("This vector is empty!");
			}
		}

		E &back(){
			if(occupied){
				return items[occupied-1];
			}
			else{
				// place for exception
				throw std::invalid_argument("This vector is empty!");
			}
		}


		E at(size_t position){
			if(position>=occupied){
				// place for exception
				throw std::invalid_argument("This has no position like this!");
			}
			else{
				return items[position];
			}
		}

		E pop(){
			if(occupied){
				occupied--;
				shrinkIfNeeded();
				return items[occupied+1];
			}
		}

		void push(E object){
			if(occupied<currentCapacity){
				items[occupied]=object;	
				occupied++;
			}
			else {
				resize(currentCapacity*2);
				push(object);
			}
		}

		void prepend(E object){
			insert(0,object);
		}
		
		void clear(){
			occupied=0;
		}

		size_t size(){
			return occupied;
		}

		size_t capacity(){
			return currentCapacity;
		}

		bool empty(){
			return !occupied;
		}

		void reserve(size_t elements){
			if(elements>currentCapacity){
				resize(elements);
			}
		}

		void erase(size_t position){
			if(position<occupied){
				moveLeft(1,position);
				occupied--;
			}	
			shrinkIfNeeded();	
		}

		void erase(size_t from, size_t to){
			if(to>from && to<occupied){
				size_t number=to-from;
				moveLeft(number, from);
				occupied-=number;	
				shrinkIfNeeded();
			}
		}
		
		void insert(size_t position, E object){
			if(occupied==currentCapacity){
				resize(2*currentCapacity);
			}
			if(position<occupied){
				for(size_t i=occupied+1;i>position;i--){
					items[i]=items[i-1];
				}
				items[position]=object;
				occupied++;
			}
		}

		int find(E item){
			for(size_t i=0;i<currentCapacity;i++){
				if(items[i] == item){
					return i;
				}
			}
			return -1;
		}

		void remove(E item){
			size_t removed=0;
			size_t freePosition=0;
			for(size_t i=0;i<occupied;i++){
				if(items[i]==item){
					if(!removed){
						freePosition=i;
					}
					removed++;
					continue;
				}
				if(removed){
					items[freePosition]=items[i];	
					freePosition++;
				}
			}	
			occupied-=removed;
			shrinkIfNeeded();
		}
};

#endif


