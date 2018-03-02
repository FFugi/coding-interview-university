#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include <string>
#include <cstddef>
#include <iostream>

template <typename T>
class Dictionary{
	private:
		enum RecordStatus{
			st_free,
			st_occupied,
			st_deleted
		};

		struct Record {
			Record() : status(st_free){}
			T value;
			std::string key;
			std::size_t hash;
			RecordStatus status;
		};

		struct Record * dictionary;

		std::size_t size;		
		std::size_t occupied;
		std::size_t deleted;

		friend std::ostream& operator<<(std::ostream& out, const Dictionary& dict){
			out << "\nPrinting dictionary: \n\tkey:\tvalue:\n";
			for(std::size_t i = 0; i < dict.size; i++){
				out << i << ".\t" ;
				if(dict.dictionary[i].status == st_deleted){
					out << "deleted";
				}
				else if(dict.dictionary[i].status == st_occupied){
					out << dict.dictionary[i].key
						<< "\t" << dict.dictionary[i].value
						<< "\t" << dict.dictionary[i].hash;
				}
				out << "\n";
			}
			out << "Deleted: " << dict.deleted << " occupied: " << dict.occupied << "\n";
			return out;
		}	

		std::size_t Hash(std::string key){
			std::size_t hash = 7;
			for(std::size_t i = 0; i < key.size(); i++){
				hash += hash*31 + key[i];
			}
			return hash % size;	
		}
		
		std::size_t Hash(std::string key, std::size_t size){
			std::size_t hash = 7;
			for(std::size_t i = 0; i < key.size(); i++){
				hash += hash*31 + key[i];
			}
			return hash % size;	
		}

		void resize(std::size_t newSize){
			struct Record * newDictionary;
			newDictionary = new Record [newSize];
			for(std::size_t i = 0; i < size; i++){
				if(dictionary[i].status == st_occupied){
					std::size_t index = Hash(dictionary[i].key, newSize);
					std::size_t hash = index;
					while(newDictionary[index].status == st_occupied){
						index++;
						if(index >= newSize){
							index = 0;
						}
					}
					newDictionary[index] = dictionary[i];
					newDictionary[index].hash = hash;
				}
			}
			size = newSize;
			delete [] dictionary;
			dictionary = newDictionary;
		}

	public:
		Dictionary():size(13), occupied(0), deleted(0){
			dictionary = new Record [size];
		}	

		~Dictionary(){
			delete [] dictionary;
		}

		void add(std::string key, T value){
			occupied++;
			std::size_t index = Hash(key);
			std::size_t firstIndex = index;
			while(dictionary[index].status == st_occupied){
				index++;
				if(index >= size){
					index = 0;
				}
			}				
			if(dictionary[index].status == st_deleted){
				deleted--;
			}
			dictionary[index].hash = firstIndex;	
			dictionary[index].value = value;
			dictionary[index].key = key;
			dictionary[index].status = st_occupied;
			
			if(occupied == size){
				resize(size * 2);
			}
		}	

		T get(std::string key){
			std::size_t index = Hash(key);				
			while(dictionary[index].key != key && dictionary[index].status != st_free){
				index++;
				if(index >= size){
					index = 0;
				}
			}
			return dictionary[index].value;
		}
	
		void remove(std::string key){
			std::size_t index = Hash(key);
			std::size_t jumps = 0;
			while((dictionary[index].key != key && dictionary[index].status == st_occupied)
					|| (dictionary[index].status == st_deleted)
					|| jumps == size){
				index++;
				jumps++;
			}	
			if(jumps == size){
				// todo: exception will be here
				return;
			}
			else{
				dictionary[index].status = st_deleted;
				deleted++;
			}
			if(deleted >= size/4){
				resize(size/2);
			}
		}

		bool exists(std::string key){
			std::size_t index = Hash(key);
			std::size_t jumps = 0;
			while((dictionary[index].key != key && dictionary[index].status == st_occupied)
					|| (dictionary[index].status == st_deleted)
					|| jumps == size){
				index++;
				jumps++;
			}	
			if(dictionary[index].key == key &&  
					(dictionary[index].status != st_deleted
					 || dictionary[index].status == st_occupied)){
				return true;
			}
			return false;			
		}

};

#endif
