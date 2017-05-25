#pragma once
#pragma once
#include <stdlib.h>
template <class Type>
class Node
{
private:
	Type var;
	Node<Type> *next;
public:
	void SetVar(Type x)
	{
		var = x;
	}
	void SetNext(Node<Type> *n)
	{
		next = n;
	}
	Type GetVar()
	{
		return var;
	}
	Node<Type> *GetNext()
	{
		return next;
	}
	Node()
	{
		SetVar(Type());
		SetNext(NULL);
	}
	Node(Type tmp)
	{
		SetVar(tmp);
		SetNext(NULL);
	}
	Node(Type tmp, Node<Type> *n)
	{
		SetVar(tmp);
		SetNext(n);
	}
};

template <class Type>
class List
{
private:
	Node<Type>*fhead;
	Node<Type>*tail;
	Node<Type>* head;
	int length;
public:
	List()
	{
		fhead = new Node<Type>();
		head = fhead;
		tail = fhead;
		length = 0;
	}

	~List()
	{
		DeleteAll();
		fhead = NULL;
		//cout << "destr list" << endl;
	}

	Node<Type>* GetHead()
	{
		return head;
	}
	int GetLength()
	{
		return length;
	}
	void SetLenght(int l)
	{
		if (i > 0) length = l;
		//else
		//	throw 'NegL';
	}
	Node<Type> FindAtPos(int pos)
	{
		if (pos<0 || pos>length) trow 'ErrP';
		Node<Type>*current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->GetNext();
		}
		return current;
	}
	void AddToHead(Type x)
	{
		Node<Type>* tmp;
		if (length == 0)
		{
			tmp = new Node<Type>(x, NULL);
			tail = tmp;
		}
		else
		{
			tmp = new Node<Type>(x, head);
		}
		fhead->SetNext(tmp);
		head = tmp;
		length++;
	}
	void AddToTail(Type x)
	{
		Node<Type>* tmp = new Node<Type>(x, NULL);
		if (tail != NULL)
		{
			tail->SetNext(tmp);
		}
		tail = tmp;
		if (head == fhead)
		{
			head = tmp;
		}
		length++;
	}
	void AddElem(Type x, int pos)
	{
		if (pos == 0)
		{
			AddToHead(x);
			return;
		}
		Node<Type>*current = FindAtPos(pos - 1);
		Node<Type>*tmp = new Node<Type>(x, current->GetNext());
		current->SetNext(tmp);
		length++;
	}
	void AddElemInOrder(Type x)
	{
		Node<Type>*current = head;
		Node<Type>*previous = fhead;
		Node<Type>* tmp = new Node<Type>(x);
		if (current == fhead)
		{
			AddToHead(x);
			return;
		}
		//if (x == current->GetVar())    //костыль
		//{
		//	current->SetVar(current->GetVar()+x);
		//	return;
		//}
		if (x > current->GetVar()) //добавила =
		{
			AddToHead(x);
			return;
		}
		if (x < tail->GetVar())
		{
			AddToTail(x);
			return;
		}

		while (x < current->GetVar())
		{
			previous = current;
			current = current->GetNext();
		}

		if (x == current->GetVar())    //костыль
		{
			current->SetVar(current->GetVar() + x);
			return;
		}
		previous->SetNext(tmp);
		tmp->SetNext(current);
		length++;
	}
	void DeleteFirst()
	{
		if (length == 0) return;
		Node<Type>*tmp = head;
		head = tmp->GetNext();
		fhead->SetNext(head);
		delete tmp;
		if (length == 1)
		{
			head = tail = NULL;
		}
		length--;
	}
	void DeleteAll()
	{
		while (length != 0)
		{
			DeleteFirst();
		}
	}
	void DeleteElement(Node<monom>* node)
	{
		Node<Type>*previous = fhead;
		Node<Type>*current = head;
		if (node == head)
		{
			DeleteFirst();
			return;
		}
		while (current != NULL)
		{
			if (current == node)
			{
				previous->SetNext(current->GetNext());
				delete current;
				length--;
				return;
			}
			previous = current;
			current = current->GetNext();
		}

	}
};