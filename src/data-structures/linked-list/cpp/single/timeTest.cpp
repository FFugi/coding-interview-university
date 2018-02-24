#include <cstdio>
#include <cstddef>
#include "SingleList.hpp"
#include <ctime>


int main(){
	clock_t time0;
	SingleList<int> list;
	for(std::size_t i = 0; i < 100000; i++){
		list.pushFront(i);	
	}
	time0 = clock();
	list.reverse();
	time0 = clock() - time0;
	printf("reverse time = %f seconds\n", (float)time0/CLOCKS_PER_SEC);

	return 0;
}
