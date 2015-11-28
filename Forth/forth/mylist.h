#include "stdafx.h"
#include <assert.h>
#include "classes.h"

class mylist
{
private:                      //��Ա������˵��
	struct node* _at_front;
	struct node* _at_end;     //����ñ�����Ϊ�����������
	int          _size;
public:
	struct node* get_front(){ return _at_front; }
	struct node* get_end(){ return _at_end; }
	int size(void){ return _size; }
	void insert_front(int);
	void insert_end(int);
	bool insert(struct node*, int);
	int  remove(int);
	void  remove_front(void);
	void  remove_end(void);
	struct node* find(int);
	void display(void);
	void reverse(void);
	bool equality(mylist&);
	mylist& concat(mylist&);
	//mylist() { _at_front(0), _at_end(0), _size(0) }; //���캯��
	~mylist();
};