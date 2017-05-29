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
	int Find(string key) 
	{ return 0;};
public:
	HashTable();
	void Insert(string key, int p);
	void Delete(string key);
	int GetNode(string key);
};

class BSTNode
{
private:
	TableNode* data;  //указатель на данные 
	BSTNode* left;    //указатель на левый узел
	BSTNode* right;   //указатель на правый узел
public:
	BSTNode(TableNode* d);  //конструктор 
	BSTNode();
	BSTNode(BSTNode &obj); //конструктор копирования

	BSTNode* GetLeft() const;  //достать левый потомок
	BSTNode* GetRight() const;  //достать правый потомок

	void SetData(TableNode* d); //установить данные в узел
	void SetLeft(BSTNode* l);  //установить данные в правый узел
	void SetRight(BSTNode* r);  //установить правый узел

	string  GetName() const;   //достать имя НЕ ИМЯ А КОЛИЧЕСТВО 
	TableNode* GetData();     //достать данные
};

class BST
{
private:
	BSTNode* root;   //корень

	BSTNode* Search(BSTNode* r, string key);   //поиск в дереве с корнем по ключу

	BSTNode* FindMax(BSTNode* r);   //найти максимум
	BSTNode* FindMin(BSTNode* r);   //найти минимум

	/*BinarySearchTree_Element* FindNext(BinarySearchTree_Element* r);
	BinarySearchTree_Element* FindPrevious(BinarySearchTree_Element* r);*/

	void Insert(BSTNode* r, BSTNode* new_node);  //вставка в дерево с коренем элемент

	void Delete(BSTNode* r, string key);   //удалить из дерева с корнем элемент

	BSTNode* Merge(BSTNode* l, BSTNode* r);   //слияние двух узлов
public:
	BST();    //конструктор
	BST(TableNode* data);  //конструктор
	/*void TLRwalk(BinarySearchTree_Element* r);
	void LTRwalk(BinarySearchTree_Element* r);*/

	void Insert(TableNode* node);  //вставка узла
	void Delete(string key);       //удаление узла
	TableNode* Search(string key);   //поиск узла по ключу

};

class AVLNode 
{
private:
	TableNode* data;
	AVLNode* left;
	AVLNode* right; //дерево сбалансировано, если у каждой вершины дисбаланс в отрезке(-1,1)
	int height;
	int disbalance; //+1 если правое поддерево больше, -1 если левое поддерево больше, 0 если одинаково
public:
	AVLNode(TableNode* d);
	AVLNode();
	AVLNode(AVLNode &obj);

	AVLNode* GetLeft() const;
	AVLNode* GetRight() const;

	void SetData(TableNode* d);
	void SetLeft(AVLNode* l);
	void SetRight(AVLNode* r);
	void SetHeight(int height);
	int GetHeight();
	string GetName() const;
	TableNode* GetData() ;
};

class AVL
{
private:

	AVLNode* root;
	int BFactor(AVLNode* node);
	void FixHeight(AVLNode* r);
	AVLNode* RotateRight(AVLNode* r);
	AVLNode* RotateLeft(AVLNode* r);
	AVLNode* Balance(AVLNode* r);
	AVLNode* Insert(AVLNode*r, AVLNode* new_node); //возможна бага
	AVLNode* Search(AVLNode* r, string key);   //поиск в дереве с корнем по ключу
	AVLNode* FindMin(AVLNode* t);
	AVLNode* RemoveMin(AVLNode* p);
	AVLNode* Delete(AVLNode* r, string key);

//	AVLNode* Search(AVLNode* r, string key);
	//AVLNode* FindMax(AVLNode* r);

public:
	AVL();
	AVL(TableNode* data);
	void Insert(TableNode* node);
	void Delete(string key);
	TableNode* Search(string key);
};