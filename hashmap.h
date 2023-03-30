#ifndef HASHMAP_H
#define HASHMAP_H

class hashmap{
public:
	hashmap();
	~hashmap();
	void Insert(void* key, void* value);
	void* Get(void* key);
	void Delete(void* key);
	void Modify(void* key, void* value);
private:
	struct node{
		void* key;
		void* value;
		node* next;
	};

	unsigned int hash(void* value);

	int capacity = 100000;
	node** table;
};

#endif