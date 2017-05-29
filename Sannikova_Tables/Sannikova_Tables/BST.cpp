#include "Table.h"
#include <iostream>


BSTNode::BSTNode(TableNode* d)  //конструктор для узла
{
	data = d;
	left = NULL;
	right = NULL;
}

BSTNode::BSTNode()  //конструктор для узла
{
	data = NULL;
	left = NULL;
	right = NULL;
}

BSTNode::BSTNode(BSTNode& obj)    //конструктор копирования
{
	data = obj.GetData();
	left = obj.GetLeft();
	right = obj.GetRight();
}

BSTNode* BSTNode::GetLeft() const   //достать левый элемент узла
{
	return left;
}

BSTNode* BSTNode::GetRight() const   //достать правый элемент узла
{
	return right;
}


void BSTNode::SetData(TableNode* d)   //заполнить данные узла
{
	data = d;
}


void BSTNode::SetLeft(BSTNode* l)   //установить левый потомок
{
	left = l;
}

void BSTNode::SetRight(BSTNode* r) //установить правый потомок
{
	right = r;
}

string BSTNode::GetName() const   //достать имя 
{
	return data->GetKey(); //нам нужно упорядочить по количеству, поэтому у нас здесь будет доставаться не имя, а count
}

TableNode* BSTNode::GetData()   //достать данные
{
	return data;
}

BST::BST()  //конструктор
{
	root = new BSTNode;
}

BST::BST(TableNode* data)  //
{
	root = new BSTNode;
	root->SetData(data);
}

//void BinarySearchTree::TLRwalk(BinarySearchTree_Element* r) {
//	if (r != NULL) {
//		cout << r->GetName() << " ";
//		TLRwalk(r->GetLeft());
//		TLRwalk(r->GetRight());
//	}
//}
//
//void BinarySearchTree::LTRwalk(BinarySearchTree_Element* r) {
//	if (r != NULL) {
//		TLRwalk(r->GetLeft());
//		TLRwalk(r->GetRight());
//		cout << r->GetName() << " ";
//	}
//}

void BST::Insert(TableNode* node) //вставка узла (обертка)
{
	if (root->GetData() == NULL)
	{
		root->SetData(node);
		return;
	}
	BSTNode* tmp = new BSTNode(node);
	Insert(root, tmp);
}

void BST::Delete(string key) //удаление узла(обертка)
{
	if (root->GetData() == NULL) {
		return;
	}

	if (root->GetName() == key)
	{
		if (root->GetRight() != NULL || root->GetLeft() != NULL) {
			root = Merge(root->GetLeft(), root->GetRight());
			return;
		}
		root->SetData(NULL);
		return;
	}
	Delete(root, key);
}

BSTNode* BST::Search(BSTNode* r, string key)  //поиск в дереве с корнем по узлу
{
	if (r == NULL || r->GetData() == NULL) return NULL;

	if (key == r->GetName()) 
	{
		return r;
	}
	if (key < r->GetName()) 
	{
		return Search(r->GetLeft(), key);
	}
	return Search(r->GetRight(), key);
}

BSTNode* BST::FindMax(BSTNode* r)  //поиск максимума в дереве
{
	if (r->GetRight() == NULL) 
	{
		return r;
	}
	return FindMax(r->GetRight());
}

BSTNode* BST::FindMin(BSTNode* r)  //поиск минимума в дереве
{
	if (r->GetLeft() == NULL) 
	{
		return r;
	}
	return FindMin(r->GetLeft());
}

//BinarySearchTree_Element* BinarySearchTree::FindNext(BinarySearchTree_Element* r) {
//	if (r->GetRight() != NULL) {
//		return FindMin(r->GetRight());
//	}
//	BinarySearchTree_Element* res = r->GetParent();
//	while (res != NULL && r == res->GetRight()) {
//		r = res;
//		res = res->GetParent();
//	}
//	return res;
//}
//
//BinarySearchTree_Element* BinarySearchTree::FindPrevious(BinarySearchTree_Element* r) {
//	if (r->GetLeft() != NULL) {
//		return FindMax(r->GetLeft());
//	}
//	BinarySearchTree_Element* res = r->GetParent();
//	while (res != NULL && r == res->GetLeft()) {
//		r = res;
//		res = res->GetParent();
//	}
//	return res;
//}

void BST::Insert(BSTNode* r, BSTNode* new_node)  //вставка в дерево с корнем узел
{
	if (new_node->GetName() > r->GetName()) {
		if (r->GetRight() != NULL) {
			Insert(r->GetRight(), new_node);
			return;
		}
		else {
			r->SetRight(new_node);
			return;//
		}
	}
	if (r->GetLeft() != NULL) {
		Insert(r->GetLeft(), new_node);
		return;//
	}
	else {
		r->SetLeft(new_node);
		return;//
	}
}

TableNode* BST::Search(string key)  //обертка для поиска
{
	BSTNode* res = Search(root, key);
	if (res == NULL)
	{
		return NULL;
	}
	return res->GetData();
}

BSTNode* BST::Merge(BSTNode* l, BSTNode* r) //слияние двух узлов
{
	if (r == NULL || r->GetData() == NULL)
	{
		return l;
	}
	if (l == NULL || l->GetData() == NULL) {
		return r;
	}
	FindMin(r)->SetLeft(l);
	return r;
}

void BST::Delete(BSTNode* r, string key)  //удаление узла в дереве с корнем
{

	if (key < r->GetName()) {
		if (r->GetLeft()->GetName() == key)
		{
			r->SetLeft(Merge(r->GetLeft()->GetLeft(), r->GetLeft()->GetRight()));
		}
		else {
			Delete(r->GetLeft(), key);
			return;
		}
	}
	if (key > r->GetName()) {
		if (r->GetRight()->GetName() == key) {
			r->SetRight(Merge(r->GetRight()->GetLeft(), r->GetRight()->GetRight()));
		}
		else {
			Delete(r->GetRight(), key);
			return;
		}
	}
}

