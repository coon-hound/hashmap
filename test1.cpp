#include "hashmap.h"
#include <map>
#include <stdio.h>

int main()
{
	hashmap map;
	const int ntests = 100000;
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

	int b = 3;

	void* ret = map.Get((void*)&b);
	assert(ret == NULL);
}
