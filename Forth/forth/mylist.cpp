#include "stdafx.h"
#include "mylist.h"
#include "iostream"
using namespace std;

//insertʵ�ִ���
//bool mylist::insert(struct node* pnode, int a)
//{
//	assert(pnode != 0);
//	struct node* temp = new struct node;
//	if (!temp)
//	{
//		temp->idata_item = a;
//		temp->pnext = pnode->pnext;
//		pnode->pnext = temp;
//		return true;
//	}	
//	else
//	{
//		cerr << "non memory allocate" << endl;
//		return false;
//	}
//}
//
////displayʵ�ִ���
//void mylist::display(void)
//{
//	if (_size == 0)
//		cout << "mylist is empty" << endl;
//	else
//	{
//		struct node *iter = _at_front;
//		for (int i = 1; i <= _size; i++)
//		{
//			cout << iter->idata_item << " ";
//			iter = iter->pnext;
//		}
//	}
//}
////reverseʵ�ִ���
//void mylist::reverse(void)
//{
//	struct node *temp;
//	temp = _at_front;
//	_at_front = _at_end;
//	_at_end = temp;
//}
////removeʵ�ִ���
//int  mylist::remove(int a)
//{
//	struct node *iter1 = _at_front;
//	struct node *iter2 = 0;
//	for (int i = 1; i <= _size; i++)
//	{
//		if (iter1->idata_item != a)
//		{
//			iter2 = iter1;
//			iter1 = iter1->pnext;
//		}
//		else
//			iter2 = iter1->pnext;
//		delete iter1;
//		_size--;
//		return 1;
//	}
//
//	return 0;
//}
//
////insert_endʵ�ִ���
//void mylist::insert_end(int a)
//{
//	struct node* temp = new struct node;
//	temp->idata_item = a;
//	if (!_at_end)
//	{
//		_at_front = _at_end = temp;
//		_size++;
//	}
//	else
//	{
//		_at_end->pnext = temp;
//		_at_end = temp;
//		_size++;
//	}
//}
////insert_frontʵ�ִ���
//void mylist::insert_front(int a)
//{
//	struct node* temp = new struct node;
//	temp->idata_item = a;
//	if (!_at_front)
//	{
//		_at_front = _at_end = temp;
//		_size++;
//	}
//	else
//	{
//		temp->pnext = _at_front;
//		_at_front = temp;
//		_size++;
//	}
//}