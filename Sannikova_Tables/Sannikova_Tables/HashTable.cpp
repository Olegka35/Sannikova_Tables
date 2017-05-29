#include "Table.h"
HashTable::HashTable()
{
	max_size = 10;
	data = new list<TableNode>*[max_size];
	for (int i = 0; i < max_size; i++)
	{
		data[i] = new list < TableNode >;
	}
}

void HashTable::Insert(string key, int p)
{
	int hash = hashfunc(key);
	data[hash]->push_back(TableNode(key, p));
}

void HashTable::Delete(string key)
{
	int hash = hashfunc(key);
	data[hash]->remove(TableNode(key, NULL));
}

int HashTable::GetNode(string key)
{
	int hash = hashfunc(key);
	list<TableNode>::const_iterator iterator;
	for (iterator = data[hash]->begin(); iterator != data[hash]->end(); ++iterator) {
		if (key == iterator->GetKey())
		{
			return iterator->GetCount();
		}
	}
	return NULL;
}

int HashTable::hashfunc(string s)
{
	int hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		hash += s[i]; //10^i
	}
	return hash%max_size;
}