// class01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int year, month, day;
	int calday(int year, int month);
	void PrintTitle(int day);
	int PrintOthers(int year, int month, int day);
	
	while (1)
	{		
		cin >> year;
		if (year == 0) break;
		cin >> month;

		day = calday(year, month);
		PrintTitle(day);
		PrintOthers(year, month, day);
		cout << endl;
	}

	return 0;
}

int calday(int year, int month)
{
	int day, century;
	if (month < 3){
		month = month + 12;
		year = year - 1;
	}
	century = year / 100;
	day = (year - century * 100 + ((year - century * 100) / 4) + (century / 4) - 2 * century + (26 * (month + 1) / 10) + 1 - 1) % 7;
	if (day < 0) day = 7 + day;
	return day;
}

void PrintTitle(int day){
	cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thr " << "Fri " << "Sar " << endl;
	switch (day){
	case 0:break;
	case 1:cout << "    "; break;
	case 2:cout << "    " << "    "; break;
	case 3:cout << "    " << "    " << "    "; break;
	case 4:cout << "    " << "    " << "    " << "    "; break;
	case 5:cout << "    " << "    " << "    " << "    " << "    "; break;
	case 6:cout << "    " << "    " << "    " << "    " << "    " << "    "; break;
	}
}

int PrintOthers(int year, int month, int day){
	int i;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		for (i = 1; i < 32; i++)
		{
			printf("%3d ", i);
			if ((i + day) % 7 == 0) cout << endl;
		}
		return 0;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		for (i = 1; i < 31; i++)
		{
			printf("%3d ", i);
			if ((i + day) % 7 == 0) cout << endl;
		}
		return 0;
	}
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		for (i = 1; i < 30; i++)
		{
			printf("%3d ", i);
			if ((i + day) % 7 == 0) cout << endl;
		}
		return 0;
	}
	else{
		for (i = 1; i < 29; i++)
		{
			printf("%3d ", i);
			if ((i + day) % 7 == 0) cout << endl;
		}
		return 0;
	}
}