#include "Table.h"

AVLNode::AVLNode(TableNode* d) //����������� ��� ����
{
	data = d;
	height = 1;
	left = NULL;
	right = NULL;
}

AVLNode::AVLNode() //�����������
{
	data = NULL;
	height = 0;
	left = NULL;
	right = NULL;
}

AVLNode::AVLNode(AVLNode& obj) //����������� �����������
{
	data = obj.GetData();
	height = obj.GetHeight();
	left = obj.GetLeft();
	right = obj.GetRight();
}

AVLNode* AVLNode::GetLeft() const //������� ����� �������
{
	return left;
}

AVLNode* AVLNode::GetRight() const //������� ������ �������
{
	return right;
}

int AVLNode::GetHeight() //������� ����� ����
{
	return height;
}

void AVLNode::SetHeight(int h) //���������� ������ ��� ����
{
	height = h;
}

void AVLNode::SetData(TableNode* d) //���������� ������ ��� ����
{
	data = d;
}


void AVLNode::SetLeft(AVLNode* l) //���������� ������ ��� ������ ����
{
	left = l;
}

void AVLNode::SetRight(AVLNode* r) //���������� ������ ��� ������� ����
{
	right = r;
}

string AVLNode::GetName() const //����� ��� ��� ����
{
	return data->GetKey();
}

TableNode* AVLNode::GetData() //������� ������ �� ����
{
	return data;
}


AVL::AVL()  //���������� ��� ������
{
	root = new AVLNode;
}

AVL::AVL(TableNode* data)  //���������� �����������
{
	root = new AVLNode;
	root->SetData(data);
}

int AVL::BFactor(AVLNode* node) //��������� ������, �������� � ��� 0 ������ ����
{
	return (node->GetLeft()->GetHeight()) - (node->GetRight()->GetHeight());
}

void AVL::FixHeight(AVLNode* node) //����������� ������
{
	int height_left = (node->GetLeft()->GetHeight()); //������ �����
	int height_right = (node->GetRight()->GetHeight()); //������ �������
	node->SetHeight((height_left > height_right ? height_left : height_right)+1); //��������� ������ ��� ����, +1
}

AVLNode* AVL::RotateRight(AVLNode* p) //������ �������
{
	AVLNode* left = p->GetLeft(); //���� ���� ����� �������� �
	p->SetLeft(left->GetRight()); //����� �������� � ���� ������ ������� �����
	left->SetRight(p); //������ �������� ����� ���� �
	FixHeight(p); //������ ������ ��� p
	FixHeight(left); //������ ������ ��� �����
	return left; //���������� ����� ������ ����������� ������

}

AVLNode* AVL::RotateLeft(AVLNode* p) //����� �������
{
	AVLNode* right = p->GetRight(); //���� ���� ������ �������� �
	p->SetRight(right->GetLeft()); //������ �������� � ������ ����� ������� ����
	right->SetLeft(p); //����� �������� ���� ������ �
	FixHeight(p); //������������ ������
	FixHeight(right); //������������ ������
	return right; //���������� ���� ������ ������������ ������
}

AVLNode* AVL::Balance(AVLNode* node) //������������
{
	FixHeight(node); //������ ������ ��� p
	if (BFactor(node) == 2) //���� ������� ������� �� 2
	{
		if (BFactor(node->GetRight()) < 0) //���� ������� ������� ������� ������ 0
			node->SetRight(RotateRight(node->GetRight()));  //�� ��� ������� ������� ���� ��������� ������ �������
		return RotateLeft(node); //������ ����� ������ ��� �����
	}
	if (BFactor(node) == -2) //���� ������� ����� �� 2
	{
		if (BFactor(node->GetLeft()) > 0) //���� ������� ������ ������� ������ 0
			node->SetLeft(RotateLeft(node->GetLeft())); //�� ��� ������ ������� ���� ��������� ����� �������
		return RotateRight(node); //������ ������ ������� ��� �����
	}
	return node; // ������������ ��� �� �����
}

AVLNode* AVL::Insert(AVLNode*root, AVLNode* new_node)
{
	//if (!root) 
	//	new AVLNode (new_node); //���� ������ ������ �� ������� ������ �� 1 �������
	//if (k<p->key)  //���� ���� ����������� ������� ������ ����� �
	//	p->left = insert(p->left, k); //�� ���������� ��������� ��� ������ ��������� ��� ����
	//else
	//	p->right = insert(p->right, k); //� ��������� ������� ���������� ��������� � ������ ���������
	//return balance(p); //��������� ������������ �����

								//� ���� �����????
	if (new_node->GetName() < root->GetName()) //���� ���� ����������� ������� ������ ����� �����
	{
		root->SetLeft(Insert(root->GetLeft(), new_node)); //�� ������ ������� ��� ������ ��������� �����
	}
	else
	{
		root->SetRight(Insert(root->GetRight(),new_node));
	}
	return Balance(root);

	//if (!root)
	//AVLNode(new_node);

	//if (new_node->GetName() > root->GetName()) 
	//{
	//	if (root->GetRight() != NULL) 
	//	{
	//		Insert(root->GetRight(), new_node);
	//		Balance(root); //��� �� �������������?
	//		return;
	//	}
	//	else 
	//	{
	//		root->SetRight(new_node);
	//		Balance(root); //isert ������ ����������� ����, ����� ��� �������������
	//		return;//
	//	}
	//}
	//if (root->GetLeft() != NULL) 
	//{
	//	Insert(root->GetLeft(), new_node);
	//	Balance(root);
	//	return;//
	//}
	//else 
	//{
	//	root->SetLeft(new_node);
	//	Balance(root);
	//	return;//
	//}
}

AVLNode* AVL::FindMin(AVLNode* root)
{
	//if (r->GetLeft() == NULL)
	//{
	//	return r;
	//}
	//return FindMin(r->GetLeft());
	return (root->GetLeft()) ? (FindMin(root->GetLeft())) : root; //���������� ����� ���������, ��- ������ ����� ������� � ���, ��� ���������� ������
}

AVLNode* AVL::RemoveMin(AVLNode* root) //������� ������� �� ������
{
	if (root->GetLeft() == NULL) //���� ����� � ���� ������ ���, �� ���������� ������ ���������, ��������� ������
		return root->GetRight();
	root->SetLeft(RemoveMin(root->GetLeft())); //��� ������ ��������� ���� �������� ��������
	//p->left = removemin(p->left);
	return Balance(root); //���������� ���������������� ������
}

AVLNode* AVL::Delete(AVLNode* root, string key)
{
	//if (!p) return 0; //���� ������ ������
	//if (k < p->key) //���� ���� ������ �����
	//	p->left = remove(p->left, k); //�� ��� ������ ��������� �������� ������� �����
	//else
	//	if (k > p->key) //���� ���� ������ ����� �
	//		p->right = remove(p->right, k); //�� �������� ������� ��� ������� ���������
	//	else //  k == p->key 
	//	{
	//		AVLNode* q = p->left; //��� ������� ��������� �����
	//		AVLNode* r = p->right; //��� ����� ��������� �����
	//		delete p; //������� ������
	//		if (!r)
	//			return q; //���� ������ ��������� ������ �� ���������� ����� ���������
	//		AVLNode* min = findmin(r); //���� ������� � ������ ���������
	//		min->right = removemin(r); //������ �������� �������� ���������� ������ ��������� ��� ��������
	//		min->left = q; //����� �������� �������� ���������� ������ ��������� 
	//		return balance(min); //������ ������������ ��� ��������( ��� ������ ������ ���������)
	//	}
	//return balance(p); //����������� ������ � �� ������
	
	if (key < root->GetName())  //���� ���� ������ ����� �����
	{
		root->SetLeft(Delete(root->GetLeft(), key)); //�� ���o� �������� ��� ������� ���������
	}
	else
		if (key > root->GetName()) //���� ���� ������ ����� �����
		{
			root->SetLeft(Delete(root->GetRight(), key)); //�� �������� �������� ��� ������� ���������
		}
		else //���� �� ���� ������, ��� ��������� ���� � ������
		{
			AVLNode*q = root->GetLeft();  //��� ����� ��� ����
			AVLNode*r = root->GetRight(); //��� ������ ��� ����
			delete root; //������� ��� ����
			if (!r) //���� ������� ��������� ���
				return q; //�� ���������� ��������� �� ����� ���������
			AVLNode* min = FindMin(r); //���� ������ ��������� �� ������, �� ���� ����������� �������� � ������ ���������
			min->SetRight(RemoveMin(r)); //������ �������� �������� ���������� ������ ��������� ��� ��������
			min->SetLeft(q); //����� �������� �������� ���������� ����� ������� ���������� ��������
			return Balance(min); //����������� ������ ��� ��������
		}
	return Balance(root); //������� �� �������� � �������������
}

AVLNode* AVL::Search(AVLNode* r, string key)  //����� � ������ � ������ �� ����
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

void AVL::Insert(TableNode* node) //�������
{
	if (root->GetData() == NULL) //���� ������ ������
	{
		root->SetData(node); //������ ������ �� ������ ��������
		return;
	}
	AVLNode* tmp = new AVLNode(node); //������ ����� ���� � ������� �������
	Insert(root, tmp); //��������� ��� � ��� ������
}

void AVL::Delete(string key) //�������, ����������
{
	if (root->GetData() == NULL)  //���� ������ ������
	{
		return;
	}
	//if (root->GetName() == key)
	//{
	//	if (root->GetRight() != NULL || root->GetLeft() != NULL) {
	//		root = Merge(root->GetLeft(), root->GetRight());
	//		return;
	//	}
	//	root->SetData(NULL);
	//	return;
	//}

	Delete(root, key);  //��������� ��� ���������������� ������ � ������?
}

TableNode* AVL::Search(string key)  //������� ��� ������
{
	AVLNode* res = Search(root, key);
	if (res == NULL)
	{
		return NULL;
	}
	return res->GetData();
}


















//AVLNode* AVL::Search(AVLNode* r, string key) {
//	if (r == NULL || r->GetData() == NULL) return NULL;
//
//	if (key == r->GetName()) {
//		return r;
//	}
//	if (key < r->GetName()) {
//		return Search(r->GetLeft(), key);
//	}
//	return Search(r->GetRight(), key);
//}
//
//TableNode* AVL::Search(string key) {
//	AVLNode* res = Search(root, key);
//	if (res == NULL)
//	{
//		return NULL;
//	}
//	return res->GetData();
//}
//
//AVLNode* AVL::FindMax(AVLNode* r) {
//	if (r->GetRight() == NULL) {
//		return r;
//	}
//	return FindMax(r->GetRight());
//}
//
//AVLNode* AVL::FindMin(AVLNode* r) {
//	if (r->GetLeft() == NULL) {
//		return r;
//	}
//	return FindMin(r->GetLeft());
//}\
//
//int AVL::GetHeight()
//{
//	return height;
//}
//
//
//int AVL::bfactor(AVLNode* r)
//{
//	return height()
//}
//
//
//void AVL::Insert(AVLNode* r, AVLNode* new_node) 
//{
//	if (new_node->GetName() > r->GetName()) 
//	{
//		if (r->GetRight() != NULL) {
//			Insert(r->GetRight(), new_node);
//			return;
//		}
//		else {
//			r->SetRight(new_node);
//			return;//
//		}
//	}
//	if (r->GetLeft() != NULL) {
//		Insert(r->GetLeft(), new_node);
//		return;//
//	}
//	else {
//		r->SetLeft(new_node);
//		return;//
//	}
//
//}

