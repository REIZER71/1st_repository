#include <iostream>
#include <string>
#include <set>
using namespace std;
bool m31, m30, february;
/*����� ��� ��������������� ����(31 ����� ������, 30 ���� � ������ � ������� (�� �����, � ����)),
����� �� ���� ������ - ����� ���� ������*/
bool specialYears; /*���� ��� ����� ����������� ����*/
string sh, ss, sm,smh,sd; /*���� ������� �������� ���� (���������� ����� �������)*/
string era, infa;

set <int> M31 = { 1,3,5,7,8,10,12 };
set <int> M30 = { 4,6,9,11 };
class Date
{
public:
	int year = 1960;
	int month, day, hour, minute, second;
	bool isOurEra;
	Date()
	{
		year = 1960;
		isOurEra = 1;
		month = 1;
		day = 1;
		hour = 0;
		minute = 0;
		second = 0;
	};
	Date(int y, int mnth, int d, int h, int m, int s)
	{
		if (year >= 0)
			isOurEra = 1;
		else
			isOurEra = 0;
		year = abs(y);
		month = mnth;
		day = d;
		hour = h;
		minute = m; 
		second = s;
		convert(*this);
		flagOut(*this);
		
	}
	static Date flagSet(Date d)
	{// �������� ��� �������� ������������, �� ����� �� � ���� �����������
		 if (M31.find(d.month) != M31.end())
			 m31 = 1;
		 else if (M30.find(d.month) != M30.end())
			 m30 = 1;
		 else
			 february = 1;
		 if ((d.year%4==0 && d.year%100!=0) or (d.year % 400 == 0)) {
			 specialYears = 1;
		 }
		 return (d);
		
	} 
	static void flagOut(Date d)
	{
			if (d.hour < 10)
				sh = "0";
			else sh = "";
			
			if (d.minute < 10)
				sm = "0";
			else sm = "";
		
			if (d.second < 10)
				ss = "0";		
			else ss = "";
			
			if (d.day < 10) 
				sd = "0";
			else sd = "";
			
			if (d.month < 10) 
				smh = "0";
			else smh = "";

	};
	friend ostream& operator<<(ostream& os, const Date& d) {
		flagOut(d);
		if ((d.day <= 0) || (d.month <= 0))
			infa = "���� ������������, �� �������� ��� ����������� � �����-����: ";
		else
			infa = "���� ���������: ";
		if (d.isOurEra == true)
			 era = "����� ���";
		else
			 era = "�� ����� ���";
		return os <<infa << endl << "����: "<<sd << d.day << '.'<< smh << d.month << '.' << d.year << endl
			<< "�����: " << sh << d.hour << ":" << sm << d.minute << ":" << ss << d.second << endl
			<< era << endl;
		
	}
	void convert(Date d) {
		while ((second >=60) && (minute >= 60) && (hour >= 24))
		{
			if (second >= 60)
			{
				second -= 60;
				minute++;
			}
			if (minute >= 60) 
			{
				minute -= 60;
				hour++;
			}
			if (hour >= 24)
			{
				hour -= 24;
				day++;
			}

		}
		flagOut(d);
		while ((m31 == 1 && day > 31)|| (m30 == 1 && day > 30) || (february == 1 && day > 28 && specialYears == 0) || (february == 1 && day > 29 && specialYears == 1)|| (month > 12))
		{
			if (m31 == 1 && day > 31)
			{
				month++;
				day -= 31;
				flagSet(d);
			}
			if (m30 == 1 && day > 30) 
			{
				month++;
				day -= 30;
				flagSet(d);
			}
			if (february == 1 && day > 28 && specialYears == 0)
			{
				month++;
				day -= 28;
				flagSet(d);
			}
			else if (february == 1 && day > 29 && specialYears == 1)
			{
				month++;
				day -= 29;
				flagSet(d);
			}
			if (month > 12) 
			{
				year++;
				month -= 12;
				flagSet(d);

			}
			
		}
		flagOut(d);
	}
	void add(Date d, int year1, int month1, int day1, int  hour1, int minute1, int second1)
	{
		Date adder(year1, month1, day1, hour1, minute1, second1);
		d/*��� ����� �� �, � ����� ����������*/ = d + adder;// ����� ������ �� ������������� �������, �������� �������� �� ��������������
		convert(d);// � ���
		flagOut(d);// � ���
	}
	void subtract(int year1, int month1, int day1, int  hour1, int minute1, int second1)
	{
		Date deleter(year1, month1, day1, hour1, minute1, second1);
		if (deleter > *this)
		{

		}

		else if (deleter < *this)
		{

		}
		else if (deleter == *this)
		{ // ������ ��������� 000, � ��������� ���� ����� ����������
			year = 1;
			isOurEra = 1;
			month = 1;
			day = 1;
			hour = 0;
			minute = 0;
			second = 0;
		}
	}
	//////////////////////////////////////////////////// �������� ///////////////////////////////////////////////////

	Date& operator= (const Date& d)
	{
		this->day = d.day;
		this->year =  d.year;
		this->hour =  d.hour;
		this->minute =  d.minute;
		this->second =  d.second;
		this->month = d.month;

		return *this;
	}
	// ����� ������������ ��� ���������
	Date operator+(const Date& d)
	{
		Date res;
		res.day = this->day + d.day;
		res.month = this->month + d.month;
		res.hour = this->hour + d.hour;
		res.minute = this->minute + d.minute;
		res.second = this->second + d.second;
		res.year = this->year + d.year;
		cout << res;
		return res;
	}
	// - 
	Date& operator+= (const Date& d)
	{
		this->day = this->day + d.day;
		this->year = this->year + d.year;
		this->hour = this->hour + d.hour;
		this->minute = this->minute + d.minute;
		this->second = this->second + d.second;

		return *this;


	}
	// - 
	Date operator-(const Date& other)
	{
		Date res;
		res.day = this->day - other.day;

		return res;
	}
	// - ������������ � ����� ������ (��� ���������)
	Date& operator-= (const Date& d)
	{
		this->day = this->day - d.day;
		this->year = this->year - d.year;
		this->hour = this->hour - d.hour;
		this->minute = this->minute - d.minute;
		this->second = this->second - d.second;

		return *this;
	}
	// - ������������ �� ������ ������ (��� ���������)
	friend bool operator> (const Date d, const Date other)
	{
		if ((d.year>=other.year)&& (d.month >= other.month) && (d.day >= other.day) && (d.hour >= other.hour) && (d.minute >= other.minute) && (d.second > other.second))
			return 1;
		else
			return 0;
	}
	// +
	friend bool operator< (const Date d, const Date other)
	{
		if ((d.year <= other.year) && (d.month <= other.month) && (d.day <= other.day) && (d.hour <= other.hour) && (d.minute <= other.minute) && (d.second < other.second))
			return 1;
		else
			return 0;
	}
	// +
	friend bool operator== (const Date& d, const Date& other)
	{
		if ((d.year == other.year) && (d.month == other.month) && (d.day == other.day) && (d.hour == other.hour) && (d.minute == other.minute) && (d.second == other.second))
			return 1;
		else
			return 0;
	}
	// +
	
	//////////////////////////////////////////////////// ����� ///////////////////////////////////////////////////
};

int main()
{
	setlocale(0, "");
	//Date date(1000,9,9,9,9,9);
	Date date(1000, 10, 10, 10, 10, 10);
	cout << date;
	//date.add(date, 13, 0, 32, 26, 63, 63);
	date.add(date,0, 0, 0, 0, 0, 1);
	cout << date;
}
/* � ������ Date ������ ���� ����������� ������ �� ��������� ����������:
add/subtract(year, month, day, hour, minute, second),
������� ������ ���������� ����� ������ ������ Date.

������ �����������, ��� ��� ����� ���� ����������.
���������� UML ���������.*/

