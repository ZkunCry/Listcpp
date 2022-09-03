
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
class Node;
template<class T>
class List
{

private:
	
	struct Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(),Node *pNext = nullptr,Node * pPrev = nullptr )
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	size_t size;
	Node* head;
	Node* tail;
public:
	List();
	List(const List& other);
	~List();
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	void insert(size_t index, T value);
	void erase(size_t position);
	void pop_back();
	bool isEmpty();
	void reSize(size_t n);
	size_t Size();
	T& operator[](const size_t index);
	List& operator=(const List& other);
	T& front();
	T& back();
private:
	Node* GetNode(size_t index);
};

int main()
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	List<int> lst2;
	lst2.push_back(10);
	lst2.push_back(20);
	lst = lst2;
	return 0;
}

template<class T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<class T>
List<T>::List(const List& other):size(0),head(nullptr),tail(nullptr)
{
	head = tail = NULL;
	Node* temp = other.head;
	while (temp)
	{
		push_back(temp->data);
		temp = temp->pNext;
	}
	size = other.size;
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::push_back(T data)
{
	
	Node* tmp = new Node(data);
	tmp->pNext = NULL;
	tmp->pPrev = tail;
	if (tail)
		tail->pNext = tmp;
	tail = tmp;
	if (head == NULL)
		head = tmp;
	size++;
}

template<class T>
void List<T>::push_front(T data)
{
	Node* tmp = new Node(data);
	tmp->pNext = head;
	tmp->pPrev = NULL;
	if (head)
		head->pPrev = tmp;
	head = tmp;
	if (tail == NULL)
		tail = tmp;
	size++;
}

template<class T>
void List<T>::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<class T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<class T>
void List<T>::insert(size_t index, T value)
{

	if (index == 0)
		push_front(value);
	else if (index == size)
		push_back(value);
	else
	{
		Node* temp = GetNode(index);
		Node* res = new Node(value);
		Node* prev = temp->pPrev;
		prev->pNext = res;
		res->pNext = temp;
		res->pPrev = prev;
		temp->pPrev = res;
		size++;
	}
}

template<class T>
void List<T>::erase(size_t position)
{
	if (size == 1 && position <= 1)
		clear();
	else if (position == 0)
		pop_front();
	else
	{
		Node* temp = GetNode(position);
		Node* prev = temp->pPrev;
		Node* pnext = temp->pNext;
		prev->pNext = temp->pNext;
		pnext->pPrev = prev;
		delete temp;
		size--;
	}
}

template<class T>
void List<T>::pop_back()
{
	Node* temp = tail;
	tail = tail->pPrev;
	delete temp;
	size--;
}

template<class T>
bool List<T>::isEmpty()
{
	return size == 0;
}

template<class T>
void List<T>::reSize(size_t n)
{
	if (n > size)
	{
		for (int i = n - size; i != 0; i--)
			push_back(0);
	}
	else if (n < size)
	{
		for (int i= size-n; i != 0; i--)
			pop_back();
	}
}

template<class T>
size_t List<T>::Size()
{
	return size;
}

template<class T>
typename List<T>::Node * List<T>::GetNode(size_t index)
{
	Node * tmp = NULL;
	size_t i;
	if (index < this->size / 2)
	{
		i = 0;
		tmp = this->head;
		while (tmp && i < index)
		{
			tmp = tmp->pNext;
			i++;
		}
	}
	else
	{
		i = this->size - 1;
		tmp = this->tail;
		while (tmp && i > index)
		{
			tmp = tmp->pPrev;
			i--;
		}
	}
	return tmp;
}


template<class T>
T& List<T>::operator[](const size_t index)
{
	Node * tmp = GetNode(index);
	return tmp->data;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (size != 0 && head != nullptr)
	{
		clear();
	}
	Node* temp = other.head;
	while (temp)
	{
		push_back(temp->data);
		temp = temp->pNext;
	}
	this->size = other.size;
	return *this;
}

template<class T>
T& List<T>::front()
{
	return this->head->data;
}

template<class T>
T& List<T>::back()
{
	return tail->data;
}
