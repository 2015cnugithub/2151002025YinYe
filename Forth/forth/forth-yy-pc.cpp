// forth.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "classes.h"
#include "mylist.h"

enum TYPE { LINE, CIRCLE, RECTANGLE, TRIANGLE };
class FigureLink;				// ��ǰ���� 

class Figure
{
	friend class FigureLink;	// FigureLink�����Ӳ�ͬͼ�λ���������������
protected:
	TYPE type;				// ͼ�����ֱ�� = LINE, Բ = CIRCLE, ���� = RECTANGLE, ������ = TRIANGLE
	//int cx, cy;				// Բ������
	//int radius;             // �뾶
	//int x1, x2, y1, y2;     // �Ľ�����

	Figure* next;			// ָ����������һ��ͼ�λ��ƶ���	
public:
	Figure( TYPE tp )//int x, int y, 
	{
		//cx = x;
		//cy = y;
		type = tp;
	}
	virtual ~Figure() {}
	//virtual void Draw() = 0;	// ͼ�λ��Ʋ����Ľӿڹ���
	//virtual void Insert() = 0;	// ͼ�λ�������������������Ľӿڹ���
	void show();				// ��ͼ�η�ʽ�°�ָ����ʽ��ʾͼ�εĸ������ԣ���
	// ��λ���������Գ��⣩��
};

class Circle :public Figure
{
private:
	float x, y, d;
public:
	Circle(float m_x, float m_y, float m_d) :Figure(CIRCLE)
	{
		x = m_x; y = m_y; d = m_d;
		type = CIRCLE;
		//circle(x, y, d / 2);
	}
};

class Rectanglee :public Figure
{
private:
	int left, top, right, bottom;
public:
	Rectanglee(float mleft, float mtop, float mright, float mbottom) :Figure(RECTANGLE)
	{
		left = mleft; top = mtop; right = mright; bottom = mbottom;
		type = RECTANGLE;
		//rectangle(left, top, right, bottom);
	}
};

class Triangle :public Figure
{
private:
	POINT *pts;
public:
	Triangle(POINT *mpts) : Figure(TRIANGLE)
	{
		type = TRIANGLE;
		pts = mpts;
		//polygon(mpts, 3);
	}

};

class FigureLink
{
	friend class Vehicle;
protected:
	Figure* head;
public:
	FigureLink()
	{
		head = 0;
	}
	~FigureLink()
	{}
	bool empty()
	{
		return TRUE;
		return FALSE;
	}
	void Insert(Figure* figureNode)
	{
		figureNode->next = head->next;
		head->next = figureNode;
	}
	Figure* Search(Figure* head, TYPE xtype)
	{
		Figure* ptr;
		for (ptr = head; ptr; ptr = ptr->next)
		{
			if ((*ptr).type == xtype)
				return ptr;
		}
		return 0;
	}
};

class Vehicle
{
protected:
	FigureLink contents;
	Figure* temp;
public:
	Vehicle()
	{

	}
	void draw()
	{
		temp = contents.Search(contents.head, CIRCLE);
		circle((*temp).x, (*temp).y, (*temp).d);
	}
	void Hide();
	void move(int x, int y);


};

class Car :public Vehicle
{
protected:
	int d;//wheel_size��	���ֵĳߴ�,
	int x;//   xstart��Car��Truck����ͼ�ε����½�ˮƽ����,
	int y;//	ystart��Car��Truck����ͼ�ε����½Ǵ�ֱ����
public:
	Car(int wheel_size, int xstart, int ystart)
	{
		d = wheel_size; x = xstart; y = ystart;
		Circle c1(x + 1.75*d, y - d / 2, d);
		Rectanglee r1(x, y - 2 * d, x + 8 * d, y - d);
		Circle c2(x + 6.25*d, y - d / 2, d);
		contents.Insert(&c1);
		contents.Insert(&r1);
		contents.Insert(&c2);
	}
};

class Truck :public Vehicle
{
public:
	Truck(int wheel_size, int xstart, int ystart);
	//�����ĺ��壨�μ�ͼ1����
	//	wheel_size��	���ֵĳߴ磬��Ϊ����Car��Truck����ͼ�εĲο��ߴ硣
	//	xstart��	Car��Truck����ͼ�ε����½�ˮƽ���ꡣ
	//	ystart��	Car��Truck����ͼ�ε����½Ǵ�ֱ����
};

//struct node
//{
//	Figure *figure;
//	struct node *pnext;
//};   //���Ķ���
//struct node* _at_front;
//struct node* _at_end;     //����ñ�����Ϊ�����������
//int          _size;





int _tmain(int argc, _TCHAR* argv[])
{
	initgraph(640, 480);   // ����� TC ��������
	float x = 20, y = 400, d = 20;//�ο���

	Car mCar(d, x, y);
	mCar.draw();

	//Circle c1(x + 1.75*d, y - d / 2, d);
	//circle(x+1.75*d, y-d/2, d/2); // ��Բ��Բ��(200, 200)���뾶 100
	//Rectanglee r1(x, y - 2 * d, x + 8 * d, y - d);
	//rectangle(x, y-2*d, x+8*d, y-d);
	//Circle c2(x + 6.25*d, y - d / 2, d);
	//circle(x+6.25*d, y-d/2, d / 2);
	
	//POINT pts1[] = { { x + 1.25*d, y - 2 * d }, { x + 2.25*d, y - 2 * d }, { x + 2.25*d, y - 3 * d } };
	//Triangle t1(pts1);// polygon(pts1, 3);
	//POINT pts2[] = { { x + 5.75*d, y - 2 * d }, { x + 6.75*d, y - 2 * d }, { x + 5.75*d, y - 3 * d } };
	//Triangle t2(pts2);// polygon(pts2, 3);
	//line(x + 2.25 * d, y - 3 * d, x + 5.75 * d, y - 3 * d);

	float x1 = 200, y1 = 400;//�ο���, d = 20
	rectangle(x1, y1 - 5 * d, x1 + 9 * d, y1 - d);
	rectangle(x1 + 9 * d + 2, y1 - 4 * d, x1 + 11 * d + 2, y1 - d);
	circle(x1 + d, y - d / 2, d / 2);
	circle(x1 + 2.25*d, y - d / 2, d / 2);
	circle(x1 + 6.25*d, y - d / 2, d / 2);
	circle(x1 + 7.5*d, y - d / 2, d / 2);	
	circle(x1 + 10*d + 2, y - d / 2, d / 2);
	getchar();               // �����������
	closegraph();          // �ر�ͼ�ν���
	
	return 0;
}