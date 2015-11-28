// forth.cpp : 定义控制台应用程序的入口点。
//
//#pragma comment(lib, "easyxw.lib")
#include "stdafx.h"
#include "classes.h"
#include "mylist.h"

enum TYPE { LINE, CIRCLE, RECTANGLE, TRIANGLE, UNKNOWN };

class Figure
{
protected:

public:
	Figure()
	{ }
	~Figure()
	{ }
	virtual void draw()
	{ }
	virtual void hide()
	{ }
	virtual void change()
	{ }
	virtual void forechange()
	{ }
	virtual void reset()
	{ }
};

class Circle :public Figure
{
private:
	float x, y, d, orgi_x;
public:
	Circle(float m_x, float m_y, float m_d) :Figure()
	{
		x = m_x; y = m_y; d = m_d; orgi_x = m_x;
	}
	void draw() { setcolor(WHITE); circle(x, y, d / 2); }
	void hide() {
		setcolor(BLACK); circle(x, y, d / 2);
	}
	void change(){ x = x + 1; }
	//void forechange(){ x = x - 1; }
	//void reset() { x = orgi_x; }
};

class Rectanglee :public Figure
{
private:
	int left, top, right, bottom, orgi_left, orgi_right;
public:
	Rectanglee(float mleft, float mtop, float mright, float mbottom) :Figure()
	{
		left = mleft; top = mtop; right = mright; bottom = mbottom; orgi_left = mleft; orgi_right = mright;
	}
	void draw() { setcolor(WHITE); rectangle(left, top, right, bottom); }
	void hide() { clearrectangle(left, top, right, bottom); }
	void change(){ left = left + 1; right = right + 1; }
	//void forechange(){ left = left - 1; right = right - 1; }
	//void reset() { left = orgi_left; right = orgi_right; }
};

class Triangle :public Figure
{
private:
	int pts[6], orgi[3];
public:
	Triangle(int mpts[]) : Figure()
	{
		pts[0] = mpts[0]; pts[1] = mpts[1]; pts[2] = mpts[2]; pts[3] = mpts[3]; pts[4] = mpts[4]; pts[5] = mpts[5];
		orgi[0] = pts[0]; orgi[1] = pts[2]; orgi[2] = pts[4];
	}
	void draw() { setcolor(WHITE); polygon((POINT*)pts, 3); }
	void hide() { setcolor(BLACK); polygon((POINT*)pts, 3); }
	void change(){ pts[0] = pts[0] + 1; pts[2] = pts[2] + 1; pts[4] = pts[4] + 1; }
	//void forechange(){ pts[0] = pts[0] - 1; pts[2] = pts[2] - 1; pts[4] = pts[4] - 1; }
	//void reset() { pts[0] = orgi[0]; pts[2] = orgi[1]; pts[4] = orgi[2]; }
};

struct FigureLink
{
	Figure *fig;
	FigureLink *next;
};

class Vehicle
{
protected:
	FigureLink *first;
public:
	Vehicle()
	{ }
	void draw()
	{
		FigureLink *u;
		u = first->next;
		while (u != NULL)
		{
			u->fig->draw();
			u = u->next;
		}
	}
	void hide()
	{
		FigureLink *u;
		u = first->next;
		while (u != NULL)
		{
			u->fig->hide();
			u = u->next;
		}
	}
	void change()
	{
		FigureLink *u;
		u = first->next;
		while (u != NULL)
		{
			u->fig->change();
			u = u->next;
		}
	}
	/*void forechange()
	{
	FigureLink *u;
	u = first->next;
	while (u != NULL)
	{
	u->fig->change();
	u = u->next;
	}
	}*/
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
		FigureLink *f1, *f2, *f3, *f4, *f5, *f6;
		first = new FigureLink;
		Figure *f;

		f1 = new FigureLink;
		f2 = new FigureLink;
		f3 = new FigureLink;
		f4 = new FigureLink;
		f5 = new FigureLink;
		f6 = new FigureLink;
		f = new Circle(x + 1.75*d, y - d / 2, d);
		f1->fig = f;
		f = new Rectanglee(x, y - 2 * d, x + 8 * d, y - d);
		f2->fig = f;
		f = new Circle(x + 6.25*d, y - d / 2, d);
		f3->fig = f;
		int pts1[6] = { x + 1.25*d, y - 2 * d, x + 2.25*d, y - 2 * d, x + 2.25*d, y - 3 * d };
		f = new Triangle(pts1);// polygon(pts1, 3);
		f4->fig = f;
		int pts2[6] = { x + 5.75*d, y - 2 * d, x + 6.75*d, y - 2 * d, x + 5.75*d, y - 3 * d };
		f = new Triangle(pts2);// polygon(pts2, 3);
		f5->fig = f;
		f = new Rectanglee(x + 2.25 * d, y - 3 * d, x + 5.75 * d, y - 2 * d); //line(x + 2.25 * d, y - 3 * d, x + 5.75 * d, y - 3 * d);
		f6->fig = f;

		first->next = f1;
		f1->next = f2;
		f2->next = f3;
		f3->next = f4;
		f4->next = f5;
		f5->next = f6;
		f6->next = NULL;
	}
	void reset()
	{
		FigureLink *f1, *f2, *f3, *f4, *f5, *f6;
		first = new FigureLink;
		Figure *f;

		f1 = new FigureLink;
		f2 = new FigureLink;
		f3 = new FigureLink;
		f4 = new FigureLink;
		f5 = new FigureLink;
		f6 = new FigureLink;
		f = new Circle(x + 1.75*d, y - d / 2, d);
		f1->fig = f;
		f = new Rectanglee(x, y - 2 * d, x + 8 * d, y - d);
		f2->fig = f;
		f = new Circle(x + 6.25*d, y - d / 2, d);
		f3->fig = f;
		int pts1[6] = { x + 1.25*d, y - 2 * d, x + 2.25*d, y - 2 * d, x + 2.25*d, y - 3 * d };
		f = new Triangle(pts1);// polygon(pts1, 3);
		f4->fig = f;
		int pts2[6] = { x + 5.75*d, y - 2 * d, x + 6.75*d, y - 2 * d, x + 5.75*d, y - 3 * d };
		f = new Triangle(pts2);// polygon(pts2, 3);
		f5->fig = f;
		f = new Rectanglee(x + 2.25 * d, y - 3 * d, x + 5.75 * d, y - 2 * d); //line(x + 2.25 * d, y - 3 * d, x + 5.75 * d, y - 3 * d);
		f6->fig = f;

		first->next = f1;
		f1->next = f2;
		f2->next = f3;
		f3->next = f4;
		f4->next = f5;
		f5->next = f6;
		f6->next = NULL;
	}
};

class Truck :public Vehicle
{
protected:
	int d;//wheel_size：	车轮的尺寸,
	int x1;//   xstart：Car或Truck对象图形的左下角水平坐标,
	int y1;//	ystart：Car或Truck对象图形的左下角垂直坐标	
public:
	Truck(int wheel_size, int xstart, int ystart)
	{
		d = wheel_size; x1 = xstart; y1 = ystart;
		FigureLink *f1, *f2, *f3, *f4, *f5, *f6, *f7;
		first = new FigureLink;
		Figure *f;

		f1 = new FigureLink;
		f2 = new FigureLink;
		f3 = new FigureLink;
		f4 = new FigureLink;
		f5 = new FigureLink;
		f6 = new FigureLink;
		f7 = new FigureLink;
		f = new Rectanglee(x1, y1 - 5 * d, x1 + 9 * d, y1 - d);
		f1->fig = f;
		f = new Rectanglee(x1 + 9 * d + 2, y1 - 4 * d, x1 + 11 * d + 2, y1 - d);
		f2->fig = f;
		f = new Circle(x1 + d, y1 - d / 2, d);
		f3->fig = f;
		f = new Circle(x1 + 2.25*d, y1 - d / 2, d);
		f4->fig = f;
		f = new Circle(x1 + 6.25*d, y1 - d / 2, d);
		f5->fig = f;
		f = new Circle(x1 + 7.5*d, y1 - d / 2, d);
		f6->fig = f;
		f = new Circle(x1 + 10 * d + 2, y1 - d / 2, d);
		f7->fig = f;

		first->next = f1;
		f1->next = f2;
		f2->next = f3;
		f3->next = f4;
		f4->next = f5;
		f5->next = f6;
		f6->next = f7;
		f7->next = NULL;
	}
	void reset()
	{
		FigureLink *f1, *f2, *f3, *f4, *f5, *f6, *f7;
		first = new FigureLink;
		Figure *f;

		f1 = new FigureLink;
		f2 = new FigureLink;
		f3 = new FigureLink;
		f4 = new FigureLink;
		f5 = new FigureLink;
		f6 = new FigureLink;
		f7 = new FigureLink;
		f = new Rectanglee(x1, y1 - 5 * d, x1 + 9 * d, y1 - d);
		f1->fig = f;
		f = new Rectanglee(x1 + 9 * d + 2, y1 - 4 * d, x1 + 11 * d + 2, y1 - d);
		f2->fig = f;
		f = new Circle(x1 + d, y1 - d / 2, d);
		f3->fig = f;
		f = new Circle(x1 + 2.25*d, y1 - d / 2, d);
		f4->fig = f;
		f = new Circle(x1 + 6.25*d, y1 - d / 2, d);
		f5->fig = f;
		f = new Circle(x1 + 7.5*d, y1 - d / 2, d);
		f6->fig = f;
		f = new Circle(x1 + 10 * d + 2, y1 - d / 2, d);
		f7->fig = f;

		first->next = f1;
		f1->next = f2;
		f2->next = f3;
		f3->next = f4;
		f4->next = f5;
		f5->next = f6;
		f6->next = f7;
		f7->next = NULL;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	initgraph(640, 480);   // 这里和 TC 略有区别
	RECT r1 = { 0, 0, 250, 15 };
	drawtext(_T("1.CAR 2.TRUCK 0.EXIT"), &r1, DT_LEFT);
	RECT r2 = {20, 20, 250, 35};
	drawtext(_T("Press <S> key to start moving"), &r2, DT_LEFT);
    RECT r3 = {20, 35, 250, 50};
	drawtext(_T("Press <P> key to pause "), &r3, DT_LEFT);
	RECT r4 = {20, 50, 250, 65};
	drawtext(_T("Press <E> key to end moving "), &r4, DT_LEFT);
	RECT r5 = {20, 65, 250,80};
	drawtext(_T("Press <+> key to speed up"), &r5, DT_LEFT);
	RECT r6 = {20, 80,250, 95};
	drawtext(_T("Press <-> key to speed down"), &r6, DT_LEFT);
	

	float x = 0, y = 400, d = 20;//参考点
	Car mCar(d, x, y);
	Truck mTruck(d, x, y);
	int i = 0;
	int speed = 100, kbhitt = 0;
	while (1)
	{
		if (kbhitt != 49) kbhitt = _getch();
		while (kbhitt == 49)
		{
			mTruck.hide();
			mCar.draw();
			kbhitt = _getch();
			if (kbhitt == 48) break;
			if (kbhitt == 50) mCar.hide(); //2
			if (kbhitt == 115) //S
			{
				mCar.hide();
				while (1)
				{
					mCar.hide();//mCar.change();
					mCar.change();//mCar.draw();mCar.hide();
					mCar.draw();
					i++;
					if (i > 640 - x) {
						mCar.hide();
						mCar.reset();
						i = 0;
					}
					if (_kbhit())
					{
						kbhitt = _getch();
						if (kbhitt == 43) speed /= 2;//+
						if (kbhitt == 45) speed *= 2;//-
						if (speed < 2) speed = 2;
						//if (kbhitt == 115) goto startt;//S
						if (kbhitt == 112) //Pause
						{
							while (1)
							if (_getch() == 112) break; //P->continue
						}

						if (kbhitt == 101 || kbhitt == 48) { mCar.hide(); mCar.reset(); break; }//E
					}
					Sleep(speed);
				}
			}
		}
		while (kbhitt == 50)
		{
			mCar.hide();
			mTruck.draw();
			kbhitt = _getch();
			if (kbhitt == 48) break;
			if (kbhitt == 49) mTruck.hide(); //1
			if (kbhitt == 115) //S
			{
				while (1)
				{
					mTruck.hide();//mCar.change();
					mTruck.change();//mCar.draw();mCar.hide();
					mTruck.draw();
					i++;
					if (i > 640 - x) {
						mTruck.hide();
						mTruck.reset();
						i = 0;
					}
					if (_kbhit())
					{
						kbhitt = _getch();
						if (kbhitt == 43) speed /= 2;//+
						if (kbhitt == 45) speed *= 2;//-
						if (speed < 2) speed = 2;
						if (kbhitt == 112) //Pause
						{
							while (1)
							if (_getch() == 112) break;//P->continue
						}
						if (kbhitt == 101 || kbhitt == 48) { mTruck.hide(); mTruck.reset(); break; };//E
					}
					Sleep(speed);
				}
			}
		}
		if (kbhitt == 48) break;
	}
	closegraph();            // 关闭图形界面

	return 0;
}