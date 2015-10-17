// class02.cpp : �������̨Ӧ�ó������ڵ㡣
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
	CGoods(long id, char namee[], double pricee, int countt) //���캯��
	{
		no = id;
		p_name = namee;
		price = pricee;
		count = countt;
	}

	CGoods(const CGoods& C) //�������캯��
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

	~CGoods() //��������
	{
		cout << p_name << " have been deleted" << endl;
	}

	void Printt() //��Ա����
	{
		cout << no << " " << p_name << " " << price << endl;
	}
	
	int getCount() //��ȡ��Ա�ĳ�Ա����
	{
		return count;
	}
	
	friend char* getName(CGoods &C); //��Ԫ��������

	bool operator < (double a) //���������
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
		cout << "�ܸ�ɶ:";
	}
	void usedForx()
	{
		cout << "�ܸ�ɶ:";
	}
	
};

char* getName(CGoods &C) //��Ԫ����
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
		printf("������\n");
	}

	void usedForx()
	{
		printf("������\n");
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
//		printf("������");
//	}
//};

void usedForrrr(CGoods &CGoods) //�Զ�̬����������
{
	cout << "�����ǣ�";
	CGoods.usedForx();
	printf("---------------------------------------------");
	CGoods.usedFor();
}

int _tmain(int argc, _TCHAR* argv[])
{
	CGoods CGood1(123, "xxx", 123.123, 10);// ���캯��
	CGood1.Printt();// ��Ա���� ��ӡ

	int m_count;
	m_count = CGood1.getCount();// ��Ԫ���� ��ȡ����
	cout << getName(CGood1) << " " << m_count << endl;

	if (CGood1 >= 100)// ���������
		cout << "Price is bigger then 100" << endl;

	CClothes CClothes1(456, "yyy", 456.123, 10, "zzz");// ��������
	CClothes1.Printt(); // ����̳и���ĳ�Ա����
	usedForrrr(CClothes1);// �Գ�Ա��������̬�������

	getchar();
	return 0;
}

