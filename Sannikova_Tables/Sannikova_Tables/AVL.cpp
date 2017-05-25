#include "Table.h"

AVLNode::AVLNode(TableNode* d)
{
	data = d;
	left = NULL;
	right = NULL;
}

AVLNode::AVLNode()
{
	data = NULL;
	left = NULL;
	right = NULL;
}

AVLNode::AVLNode(AVLNode& obj)
{
	data = obj.GetData();
	left = obj.GetLeft();
	right = obj.GetRight();
}

AVLNode* AVLNode::GetLeft() const
{
	return left;
}

AVLNode* AVLNode::GetRight() const
{
	return right;
}


void AVLNode::SetData(TableNode* d)
{
	data = d;
}


void AVLNode::SetLeft(AVLNode* l)
{
	left = l;
}

void AVLNode::SetRight(AVLNode* r)
{
	right = r;
}

string AVLNode::GetName() const
{
	return data->GetKey();
}

TableNode* AVLNode::GetData()
{
	return data;
}

AVL::AVL() 
{
	root = new AVLNode;
}

AVL::AVL(TableNode* data) {
	root = new AVLNode;
	root->SetData(data);
}

AVLNode* AVL::Search(AVLNode* r, string key) {
	if (r == NULL || r->GetData() == NULL) return NULL;

	if (key == r->GetName()) {
		return r;
	}
	if (key < r->GetName()) {
		return Search(r->GetLeft(), key);
	}
	return Search(r->GetRight(), key);
}

TableNode* AVL::Search(string key) {
	AVLNode* res = Search(root, key);
	if (res == NULL)
	{
		return NULL;
	}
	return res->GetData();
}

AVLNode* AVL::FindMax(AVLNode* r) {
	if (r->GetRight() == NULL) {
		return r;
	}
	return FindMax(r->GetRight());
}

AVLNode* AVL::FindMin(AVLNode* r) {
	if (r->GetLeft() == NULL) {
		return r;
	}
	return FindMin(r->GetLeft());
}











void AVL::Insert(AVLNode* r, AVLNode* new_node) 
{
	if (new_node->GetName() > r->GetName()) 
	{
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