// forth.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "classes.h"
#include "mylist.h"

enum TYPE { LINE, CIRCLE, RECTANGLE, TRIANGLE };
class FigureLink;				// 超前声明 

class Figure
{
	friend class FigureLink;	// FigureLink是连接不同图形绘制类对象的链表类
protected:
	TYPE type;				// 图形类别：直线 = LINE, 圆 = CIRCLE, 矩形 = RECTANGLE, 三角形 = TRIANGLE
	//int cx, cy;				// 圆心坐标
	//int radius;             // 半径
	//int x1, x2, y1, y2;     // 四角坐标

	Figure* next;			// 指向链表中下一个图形绘制对象	
public:
	Figure( TYPE tp )//int x, int y, 
	{
		//cx = x;
		//cy = y;
		type = tp;
	}
	virtual ~Figure() {}
	//virtual void Draw() = 0;	// 图形绘制操作的接口规则
	//virtual void Insert() = 0;	// 图形绘制类对象插入链表操作的接口规则
	void show();				// 在图形方式下按指定格式显示图形的各项属性（中
	// 心位置坐标属性除外）。
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
	int d;//wheel_size：	车轮的尺寸,
	int x;//   xstart：Car或Truck对象图形的左下角水平坐标,
	int y;//	ystart：Car或Truck对象图形的左下角垂直坐标
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
	//参数的含义（参见图1）：
	//	wheel_size：	车轮的尺寸，作为构造Car或Truck对象图形的参考尺寸。
	//	xstart：	Car或Truck对象图形的左下角水平坐标。
	//	ystart：	Car或Truck对象图形的左下角垂直坐标
};

//struct node
//{
//	Figure *figure;
//	struct node *pnext;
//};   //结点的定义
//struct node* _at_front;
//struct node* _at_end;     //定义该变量是为了链表的连结
//int          _size;





int _tmain(int argc, _TCHAR* argv[])
{
	initgraph(640, 480);   // 这里和 TC 略有区别
	float x = 20, y = 400, d = 20;//参考点

	Car mCar(d, x, y);
	mCar.draw();

	//Circle c1(x + 1.75*d, y - d / 2, d);
	//circle(x+1.75*d, y-d/2, d/2); // 画圆，圆心(200, 200)，半径 100
	//Rectanglee r1(x, y - 2 * d, x + 8 * d, y - d);
	//rectangle(x, y-2*d, x+8*d, y-d);
	//Circle c2(x + 6.25*d, y - d / 2, d);
	//circle(x+6.25*d, y-d/2, d / 2);
	
	//POINT pts1[] = { { x + 1.25*d, y - 2 * d }, { x + 2.25*d, y - 2 * d }, { x + 2.25*d, y - 3 * d } };
	//Triangle t1(pts1);// polygon(pts1, 3);
	//POINT pts2[] = { { x + 5.75*d, y - 2 * d }, { x + 6.75*d, y - 2 * d }, { x + 5.75*d, y - 3 * d } };
	//Triangle t2(pts2);// polygon(pts2, 3);
	//line(x + 2.25 * d, y - 3 * d, x + 5.75 * d, y - 3 * d);

	float x1 = 200, y1 = 400;//参考点, d = 20
	rectangle(x1, y1 - 5 * d, x1 + 9 * d, y1 - d);
	rectangle(x1 + 9 * d + 2, y1 - 4 * d, x1 + 11 * d + 2, y1 - d);
	circle(x1 + d, y - d / 2, d / 2);
	circle(x1 + 2.25*d, y - d / 2, d / 2);
	circle(x1 + 6.25*d, y - d / 2, d / 2);
	circle(x1 + 7.5*d, y - d / 2, d / 2);	
	circle(x1 + 10*d + 2, y - d / 2, d / 2);
	getchar();               // 按任意键继续
	closegraph();          // 关闭图形界面
	
	return 0;
}