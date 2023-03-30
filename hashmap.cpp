#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int hashmap::hash(void* value)
{
	unsigned int key = *((unsigned int*) value);
	unsigned int temp = key;
	temp *= 9183579;
	temp >>= 3;
	temp &= 49021;
	temp ^= 1223;
	temp /= 333;
	temp *= 4039;
	key *= temp;
	key >>= 3;
	key &= temp;
	key ^= temp;
	return key % capacity;
}

hashmap::hashmap()
{
	table = (node**)malloc(sizeof(node*)*capacity);

	for(int i = 0; i < capacity; i++){
		table[i] = nullptr;
	}
}

hashmap::~hashmap()
{
	for(int i = 0; i < capacity; i++){
		node* curr = table[i];
		if(curr == nullptr){
			continue;
		}
		while(curr != nullptr){
			node* next = curr->next;
			free(curr);	
			curr = next;
		}
	}
	free(table);
}

void hashmap::Insert(void* key, void* value)
{
	unsigned int hash = this->hash(key);
	node* n = (node*)malloc(sizeof(node));
	n->key = key;
	n->value = value;
	n->next = nullptr;
	if(table[hash] == nullptr){
		table[hash] = n;
	}
	else{
		node* temp = table[hash];
		while(temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
		// printf("inserting ll\n");
	}
}

void* hashmap::Get(void* key)
{
	unsigned int hash = this->hash(key);
	node* temp = table[hash];

	while(temp != nullptr){
		if(temp->key == key){
			return temp->value;
		}
		temp = temp->next;
		// printf("getting ll\n");
	}
	return nullptr;
}

void hashmap::Delete(void* key)
{
	unsigned int hash = this->hash(key);
	node* temp = table[hash];

	if(temp->key == key){
		table[hash] = temp->next;
		free(temp);
		return;
	}

	while(temp->next != nullptr){
		if(temp->next->key == key){
			node* del = temp->next;
			temp->next = del->next;
			free(del);
			return;
		}
		temp = temp->next;
	}
}

void hashmap::Modify(void* key, void* value)
{
	unsigned int hash = this->hash(key);
	node* temp = table[hash];

	while(temp != nullptr)
	{
		if(temp->key == key){
			temp->value = value;
			return;
		}
		temp = temp->next;
	}
}