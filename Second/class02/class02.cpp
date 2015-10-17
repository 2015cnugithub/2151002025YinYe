// class02.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class CGoods
{
protected:
	long no;
	char *p_name;
	double price;
	int count;
public:
	CGoods(long id, char namee[], double pricee, int countt) //构造函数
	{
		no = id;
		p_name = namee;
		price = pricee;
		count = countt;
	}

	CGoods(const CGoods& C) //拷贝构造函数
	{
		long no;
		char *p_name;
		double price;
		int count;
		no = C.no;
		p_name = C.p_name;
		price = C.price;
		count = C.count;
	}

	~CGoods() //析构函数
	{
		cout << p_name << " have been deleted" << endl;
	}

	void Printt() //成员函数
	{
		cout << no << " " << p_name << " " << price << endl;
	}
	
	int getCount() //获取成员的成员函数
	{
		return count;
	}
	
	friend char* getName(CGoods &C); //友元函数声明

	bool operator < (double a) //运算符重载
	{
		if (price < a)
			return true;
		else
			return false;
	}
	bool operator >= (double a)
	{
		if (price >= a)
			return true;
		else
			return false;
	}

	virtual void usedFor()
	{
		cout << "能干啥:";
	}
	void usedForx()
	{
		cout << "能干啥:";
	}
	
};

char* getName(CGoods &C) //友元函数
{
	char *name;
	name = C.p_name;
	return name;
}

class CClothes : public CGoods
{
	char *p_brand;
public:
	CClothes(long id, char *namee, double pricee, int count, char *brand) : CGoods(id, namee, pricee, count)
	{
		no = id;
		p_name = namee;
		price = pricee;
		p_brand = brand;
	}
	~CClothes()
	{
		cout << "Clothes has disappear" << endl;
	}

	void usedFor()
	{
		printf("用来穿\n");
	}

	void usedForx()
	{
		printf("用来穿\n");
	}
};
//
//class CFood : public CGoods
//{
//	char *p_brand;
//public:
//	CFood(long id, char *namee, double pricee, char brand) : CGoods(id, namee, pricee)
//	{
//		no = id;
//		//p_name = &namee;
//		price = pricee;
//		p_brand = &brand;
//	}
//	~CFood();
//
//	void usedFor()
//	{
//		printf("用来吃");
//	}
//};

void usedForrrr(CGoods &CGoods) //对动态联编做测试
{
	cout << "功能是：";
	CGoods.usedForx();
	printf("---------------------------------------------");
	CGoods.usedFor();
}

int _tmain(int argc, _TCHAR* argv[])
{
	CGoods CGood1(123, "xxx", 123.123, 10);// 构造函数
	CGood1.Printt();// 成员函数 打印

	int m_count;
	m_count = CGood1.getCount();// 友元函数 获取数量
	cout << getName(CGood1) << " " << m_count << endl;

	if (CGood1 >= 100)// 运算符重载
		cout << "Price is bigger then 100" << endl;

	CClothes CClothes1(456, "yyy", 456.123, 10, "zzz");// 构造子类
	CClothes1.Printt(); // 子类继承父类的成员函数
	usedForrrr(CClothes1);// 对成员函数做动态联编测试

	getchar();
	return 0;
}

