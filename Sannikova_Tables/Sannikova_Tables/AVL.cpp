#include "Table.h"

AVLNode::AVLNode(TableNode* d) //конструктор для узла
{
	data = d;
	height = 1;
	left = NULL;
	right = NULL;
}

AVLNode::AVLNode() //конструктор
{
	data = NULL;
	height = 0;
	left = NULL;
	right = NULL;
}

AVLNode::AVLNode(AVLNode& obj) //конструктор копирования
{
	data = obj.GetData();
	height = obj.GetHeight();
	left = obj.GetLeft();
	right = obj.GetRight();
}

AVLNode* AVLNode::GetLeft() const //достать левый потомок
{
	return left;
}

AVLNode* AVLNode::GetRight() const //достать правый потомок
{
	return right;
}

int AVLNode::GetHeight() //достать высоу узла
{
	return height;
}

void AVLNode::SetHeight(int h) //установить высоту для узла
{
	height = h;
}

void AVLNode::SetData(TableNode* d) //установить данные для узла
{
	data = d;
}


void AVLNode::SetLeft(AVLNode* l) //установить данные для левого узла
{
	left = l;
}

void AVLNode::SetRight(AVLNode* r) //установить данные для правого узла
{
	right = r;
}

string AVLNode::GetName() const //дость имя для узла
{
	return data->GetKey();
}

TableNode* AVLNode::GetData() //достать данные из узла
{
	return data;
}


AVL::AVL()  //конструтор для дерева
{
	root = new AVLNode;
}

AVL::AVL(TableNode* data)  //конструтор копирования
{
	root = new AVLNode;
	root->SetData(data);
}

int AVL::BFactor(AVLNode* node) //вычисляет высоту, работает в для 0 вершин тоэе
{
	return (node->GetLeft()->GetHeight()) - (node->GetRight()->GetHeight());
}

void AVL::FixHeight(AVLNode* node) //расчитывает баланс
{
	int height_left = (node->GetLeft()->GetHeight()); //высота леого
	int height_right = (node->GetRight()->GetHeight()); //высота правого
	node->SetHeight((height_left > height_right ? height_left : height_right)+1); //установка высоты для узла, +1
}

AVLNode* AVL::RotateRight(AVLNode* p) //правый поворот
{
	AVLNode* left = p->GetLeft(); //лефт стал левым потомком р
	p->SetLeft(left->GetRight()); //левым потомком р стал правый потомок лефта
	left->SetRight(p); //правым потомком лефта стал р
	FixHeight(p); //расчет высоты для p
	FixHeight(left); //расчет высоты для лефта
	return left; //возвращает новый корень полученного дерева

}

AVLNode* AVL::RotateLeft(AVLNode* p) //правй поворот
{
	AVLNode* right = p->GetRight(); //райт стал правым потомком р
	p->SetRight(right->GetLeft()); //правым потомком р станет левый потомок райт
	right->SetLeft(p); //левым потомком райт станет р
	FixHeight(p); //корректируем высоты
	FixHeight(right); //корректируем высоты
	return right; //возвращаем новй корень полученнного дерева
}

AVLNode* AVL::Balance(AVLNode* node) //балансировка
{
	FixHeight(node); //расчет высоты для p
	if (BFactor(node) == 2) //если перевес справва на 2
	{
		if (BFactor(node->GetRight()) < 0) //если перевес правого потомка меньше 0
			node->SetRight(RotateRight(node->GetRight()));  //то для правого потомка надо выполнить правый поворот
		return RotateLeft(node); //делаем левый вопрот для корня
	}
	if (BFactor(node) == -2) //если перевес слева на 2
	{
		if (BFactor(node->GetLeft()) > 0) //если перевес левого потомка больше 0
			node->SetLeft(RotateLeft(node->GetLeft())); //то для левого потомка надо выполнить левый поворот
		return RotateRight(node); //делает правый поворот для корня
	}
	return node; // балансировка уже не нужна
}

AVLNode* AVL::Insert(AVLNode*root, AVLNode* new_node)
{
	//if (!root) 
	//	new AVLNode (new_node); //если дерево пустое то создаем дерево из 1 вершины
	//if (k<p->key)  //если ключ вставляемой вершины меньше ключа р
	//	p->left = insert(p->left, k); //то рекурсивно вставляем для левого поддерева наш узел
	//else
	//	p->right = insert(p->right, k); //в противном случает рекурсивно вставляем в правое поддерево
	//return balance(p); //выполняем балансировку корня

								//а если равны????
	if (new_node->GetName() < root->GetName()) //если ключ вставляемой вершины меньше ключа корня
	{
		root->SetLeft(Insert(root->GetLeft(), new_node)); //то делаем вставку для левого поддерева корня
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
	//		Balance(root); //его ли балансировать?
	//		return;
	//	}
	//	else 
	//	{
	//		root->SetRight(new_node);
	//		Balance(root); //isert должен возвращаеть узел, чтобы его балансировать
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
	return (root->GetLeft()) ? (FindMin(root->GetLeft())) : root; //существует левое поддерево, да- делаем поиск миниума в нем, нет возвращаем корень
}

AVLNode* AVL::RemoveMin(AVLNode* root) //удалить минимум из дерева
{
	if (root->GetLeft() == NULL) //если слева у узла ничего нет, то позвращаем правое поддерево, удаляется корень
		return root->GetRight();
	root->SetLeft(RemoveMin(root->GetLeft())); //для левого поддерева узла вызываем рекурсию
	//p->left = removemin(p->left);
	return Balance(root); //возвращаем сбалансированное дерево
}

AVLNode* AVL::Delete(AVLNode* root, string key)
{
	//if (!p) return 0; //если дерево пустое
	//if (k < p->key) //если ключ меньше ключа
	//	p->left = remove(p->left, k); //то для левого поддерева вызываем изъятие ключа
	//else
	//	if (k > p->key) //если ключ больше ключа р
	//		p->right = remove(p->right, k); //то вызываем изъятие для правого поддерева
	//	else //  k == p->key 
	//	{
	//		AVLNode* q = p->left; //это праавое поддерева корня
	//		AVLNode* r = p->right; //это левое поддерево корня
	//		delete p; //удаляем корень
	//		if (!r)
	//			return q; //если правое поддерево пустое то возвращаем левое поддерево
	//		AVLNode* min = findmin(r); //ищем минимум в правом поддереве
	//		min->right = removemin(r); //правым потомком минимума станомится правое поддерево без минимума
	//		min->left = q; //левым потомком минимума становится правое поддерево 
	//		return balance(min); //делаем балансировку для минимума( это корень нашего поддерева)
	//	}
	//return balance(p); //балансируем дерево р на всякий
	
	if (key < root->GetName())  //если ключ меньше ключа корня
	{
		root->SetLeft(Delete(root->GetLeft(), key)); //то вызoв удаления для правого поддерева
	}
	else
		if (key > root->GetName()) //если ключ больше ключа корня
		{
			root->SetLeft(Delete(root->GetRight(), key)); //то вызывает удаление для правого поддерева
		}
		else //если мы ншли корень, где совпадают ключ и данные
		{
			AVLNode*q = root->GetLeft();  //это левый сын узла
			AVLNode*r = root->GetRight(); //это правый сын узла
			delete root; //удаляем сам узел
			if (!r) //если правого поддерева нет
				return q; //то возвращаем указатель на левое поддерево
			AVLNode* min = FindMin(r); //если правое поддерево не пустое, то ищем минимальное занчение в правом поддереве
			min->SetRight(RemoveMin(r)); //правым потомком минимума становится правое поддерево без минимума
			min->SetLeft(q); //левым потомком минимума становится левый потомок удаляемого элемента
			return Balance(min); //балансируем высоты для минимума
		}
	return Balance(root); //выходим из рекурсии с балансировкой
}

AVLNode* AVL::Search(AVLNode* r, string key)  //поиск в дереве с корнем по узлу
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

void AVL::Insert(TableNode* node) //обертка
{
	if (root->GetData() == NULL) //если дерево пустое
	{
		root->SetData(node); //делаем дерево из одного элемента
		return;
	}
	AVLNode* tmp = new AVLNode(node); //делаем новый узел с нудными данными
	Insert(root, tmp); //вставляем его в это дерево
}

void AVL::Delete(string key) //обертка, переделать
{
	if (root->GetData() == NULL)  //если дерево пустое
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

	Delete(root, key);  //возвратит нам сбалансированное дерево с корнем?
}

TableNode* AVL::Search(string key)  //обертка для поиска
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

