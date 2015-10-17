// class03.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class Worker
{
public:
	char *name;
	int age;
	char sex;
	int pay_per_hour;
	float salary = 0;
public:
	Worker(char *i_name, int i_age, char i_sex)
	{
		name = i_name;
		age = i_age;
		sex = i_sex;
	}

	friend ostream& operator<<(ostream& out, Worker& worker);
	void Name()
	{
		cout << name;
	}
	virtual void Compute_pay(double hours)
	{

	}
	~Worker()
	{

	}
};

ostream& operator<<(ostream& out, Worker& worker)
{
	cout << worker.name << " " << worker.age << " " << worker.sex << " " << worker.pay_per_hour << "US$/hour" << endl;
	return out;
}

class HourlyWorker :public Worker //��ʱ����
{
public:
	HourlyWorker(char *i_name, int i_age, char i_sex, int i_pay_per_hour) : Worker(i_name, i_age, i_sex)
	{
		name = i_name;
		age = i_age;
		sex = i_sex;
		pay_per_hour = i_pay_per_hour;
	}
	void Compute_pay(double hours)
	{
		if (hours <= 40)
			salary = pay_per_hour * hours;
		if (hours > 40)
			salary = pay_per_hour * 40 + 1.5 * pay_per_hour * (hours-40);
	}
};
class SalariedWorker :public Worker //��н����
{
public:
	SalariedWorker(char *i_name, int i_age, char i_sex, int i_pay_per_hour) : Worker(i_name, i_age, i_sex)
	{
		name = i_name;
		age = i_age;
		sex = i_sex;
		pay_per_hour = i_pay_per_hour;
	}
	void Compute_pay(double hours)
	{
		if (hours >= 35)
			salary = pay_per_hour * 40;
		if (hours < 35)
			salary = pay_per_hour * hours + 0.5 * pay_per_hour * (35 - hours);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	//char *name = new char;
	int age;
	char sex;
	int kind;
	int pay_per_hour;
	Worker *workers[5];

	cout << "��5�����˽���ע��" << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << "����¼���" << i << "λ���˵����ϣ�" << endl;

		char *name = new char;
		cout << "����:"; cin >> name; 
		cout << "����:"; cin >> age; 
		cout << "�Ա�F/M��:"; cin >> sex; 
		cout << "���1����ʱ 2����н��:"; cin >> kind; 
		cout << "н��ȼ�:"; cin >> pay_per_hour; 
		if (kind == 1)
		{
			//HourlyWorker  mHourlyWorker(name, age, sex, pay_per_hour);//; = ; *mHourlyWorker =
			//workers[i - 1] = &mHourlyWorker;
			HourlyWorker* p = new HourlyWorker(name, age, sex, pay_per_hour);
			workers[i - 1] = p;
		}
		if (kind == 2)
		{
			//SalariedWorker mSalariedWorker(name, age, sex, pay_per_hour);
			//workers[i - 1] = &mSalariedWorker;
			SalariedWorker* p = new SalariedWorker(name, age, sex, pay_per_hour);
			workers[i - 1] = p;
		}
	}

	while (1)
	{
		cout << "��ѡ����Ҫ�鿴�Ĺ��˱�ţ�����0�˳�" << endl;
		int i = 0,hour; 
		cout << "1��"; (*workers[0]).Name(); cout << endl;
		cout << "2��"; (*workers[1]).Name(); cout << endl;
		cout << "3��"; (*workers[2]).Name(); cout << endl;
		cout << "4��"; (*workers[3]).Name(); cout << endl;
		cout << "5��"; (*workers[4]).Name(); cout << endl;
		cin >> i;
		if (i == 0) break;
		if (i > 5 || i < 1) { cout << "�����������������룺�����Ϊ1-5��"; continue; }

		switch ( i ){
		case 1:cout << *workers[i - 1]; break;
		case 2:cout << *workers[i - 1]; break;
		case 3:cout << *workers[i - 1]; break;
		case 4:cout << *workers[i - 1]; break;
		case 5:cout << *workers[i - 1]; break;
		}

		cout << "�������������˱��ܹ���ʱ��:" << endl; cin >> hour;
		(*workers[i - 1]).Compute_pay(hour);
		cout << "�������˱���нˮӦΪ: " << (*workers[i - 1]).salary << endl;
	}

	for (int i = 0; i < 5; i++)
		delete workers[i];

	return 0;
}

