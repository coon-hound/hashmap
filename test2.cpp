#include "hashmap.h"
#include <map>
#include <stdio.h>

int main()
{
	hashmap map;
	const int ntests = 1000000;
	int a[ntests];
	for(int i = 0; i < ntests; i++){
		a[i] = i;
	} 

	for(int i = 0; i < ntests; i++){
		void* ret;
		map.Insert((void*)&a[i], (void*)&a[i]);

		ret = map.Get((void*)&a[i]);

		assert(*((int*)ret) == a[i]);
		printf("%d\n", *((int*)ret));
	}

	for(int i = ntests-1; i >= 0; i--){
		void* temp = (void*)&a[i];
		map.Delete(temp);
		assert(map.Get(temp) == nullptr);
		printf("success %d\n", i);
	}		
}
