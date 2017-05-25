#include "Table.h"
#include <iostream>


BSTNode::BSTNode(TableNode* d) 
{
	data = d;
	left = NULL;
	right = NULL;
}

BSTNode::BSTNode() 
{
	data = NULL;
	left = NULL;
	right = NULL;
}

BSTNode::BSTNode(BSTNode& obj) 
{
	data = obj.GetData();
	left = obj.GetLeft();
	right = obj.GetRight();
}

BSTNode* BSTNode::GetLeft() const 
{
	return left;
}

BSTNode* BSTNode::GetRight() const 
{
	return right;
}


void BSTNode::SetData(TableNode* d) 
{
	data = d;
}


void BSTNode::SetLeft(BSTNode* l) 
{
	left = l;
}

void BSTNode::SetRight(BSTNode* r) 
{
	right = r;
}

string BSTNode::GetName() const 
{
	return data->GetKey();
}

TableNode* BSTNode::GetData() 
{
	return data;
}

BST::BST() {
	root = new BSTNode;
}

BST::BST(TableNode* data) {
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

void BST::Insert(TableNode* node)
{
	if (root->GetData() == NULL)
	{
		root->SetData(node);
		return;
	}

	BSTNode* tmp = new BSTNode(node);
	Insert(root, tmp);
}

void BST::Delete(string key)
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

BSTNode* BST::Search(BSTNode* r, string key) {
	if (r == NULL || r->GetData() == NULL) return NULL;

	if (key == r->GetName()) {
		return r;
	}
	if (key < r->GetName()) {
		return Search(r->GetLeft(), key);
	}
	return Search(r->GetRight(), key);
}

BSTNode* BST::FindMax(BSTNode* r) {
	if (r->GetRight() == NULL) {
		return r;
	}
	return FindMax(r->GetRight());
}

BSTNode* BST::FindMin(BSTNode* r) {
	if (r->GetLeft() == NULL) {
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

void BST::Insert(BSTNode* r, BSTNode* new_node) {
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

TableNode* BST::Search(string key) {
	BSTNode* res = Search(root, key);
	if (res == NULL)
	{
		return NULL;
	}
	return res->GetData();
}

BSTNode* BST::Merge(BSTNode* l, BSTNode* r) {
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

void BST::Delete(BSTNode* r, string key) {

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

