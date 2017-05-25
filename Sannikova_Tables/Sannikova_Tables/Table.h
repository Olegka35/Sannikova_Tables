#pragma once
#include <stdio.h>
#include <iostream> 
#include <string>
#include <list>
using namespace std;

class TableNode
{
private:
	string word;
	int count;
public:
	TableNode();
	TableNode(TableNode &r);
	TableNode(string name_, int elem);

	string GetKey() const;
	int GetCount() const;
	TableNode& operator=(const TableNode &r);
	bool operator==(const TableNode &r);

};

class Table
{
protected:
	virtual int Find(string word) = 0;
public:
	virtual void Insert(string word, int p) = 0;
	virtual void Delete(string word) = 0;
	virtual int GetNode(string key) = 0;
};


class HashTable : public Table
{
private:
	list<TableNode> **data; //	СПИСОК СПИСКОВ (массив, в котором указатели на списки, но массив большой)
	int max_size;   // максимальная длина списка указтелей

	int hashfunc(string s);
	int Find(string key) { return 0; };
public:
	HashTable();

	void Insert(string key, int p);
	void Delete(string key);
	int GetNode(string key);
};

class BSTNode
{
private:
	TableNode* data;
	BSTNode* left;
	BSTNode* right;
public:
	BSTNode(TableNode* d);
	BSTNode();
	BSTNode(BSTNode &obj);

	BSTNode* GetLeft() const;
	BSTNode* GetRight() const;

	void SetData(TableNode* d);
	void SetLeft(BSTNode* l);
	void SetRight(BSTNode* r);

	string GetName() const;
	TableNode* GetData();
};

class BST
{
private:
	BSTNode* root;

	BSTNode* Search(BSTNode* r, string key);

	BSTNode* FindMax(BSTNode* r);
	BSTNode* FindMin(BSTNode* r);

	/*BinarySearchTree_Element* FindNext(BinarySearchTree_Element* r);
	BinarySearchTree_Element* FindPrevious(BinarySearchTree_Element* r);*/

	void Insert(BSTNode* r, BSTNode* new_node);

	void Delete(BSTNode* r, string key);

	//BSTNode* Merge(BSTNode* l, BSTNode* r);
public:
	BST();
	BST(TableNode* data);
	/*void TLRwalk(BinarySearchTree_Element* r);
	void LTRwalk(BinarySearchTree_Element* r);*/

	void Insert(TableNode* node);
	void Delete(string key);
	TableNode* Search(string key);

};

class AVL
{
private:
	BSTNode* root;
	BSTNode* Search(BSTNode* r, string* key);
	BSTNode* FindMax(BSTNode* r);
	BSTNode* FindMin(BSTNode* t);
	void Insert(BSTNode*r, BSTNode* new_node);
	void Delete(BSTNode* r, string key);
	BSTNode* Merge(BSTNode* l, BSTNode *r);
public:
	AVL();
	AVL(TableNode* data);
	void Insert(TableNode* node);
	void Delete(string key);
	TableNode* Search(string key);
};