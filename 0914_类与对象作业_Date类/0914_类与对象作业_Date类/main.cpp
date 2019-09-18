#include<iostream>
using namespace std;

class Date 
{
public:    
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (Isture(year, month, day))//如果是合法日期
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "输入有误，已设置为默认值" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	bool Isture(int year, int month, int day)
	{
		if (year < 0 || month <= 0 || month>12)
			return false;
		if (day <= 0 || day > GetDayOfMonth(year, month))
			return false;
		return true;
	}
	int GetDayOfMonth(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			days[2]++;
		return days[month];
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	int monthDays()const
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
			days[2] += 1;
		return days[_month];
	}
	Date operator+(int days)const
	{
		Date da(*this);
		for (int i = 0; i < days; i++)
			da++;
		return da;
	}
	Date operator-(int days)
	{
		Date da(*this);
		for (int i = 0; i < days; i++)
			da--;
		return da;
	}
	int operator-(const Date& d)
	{
		int count = 0;
		Date da(*this);
		if (da<d)
		{
			while (da < d)
			{
				count--;
				da++;
			}
			return count;
		}
		else if (da > d)
		{
			while (da > d)
			{
				count++;
				da--;
			}
			return count;
		}
		else
			return 0;
	}
	Date& operator++()
	{
		_day++;
		if (_day > monthDays())
		{
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
			_day = _day - monthDays();
			
		}
		return *this;
	}
	Date operator++(int)
	{
		Date da(*this);
		_day++;
		if (_day > monthDays())
		{
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
			_day = _day - monthDays();
		}
		return da;
	}
	Date& operator--()
	{
		_day--;
		if (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += monthDays();
		}
		return *this;
	}
	Date operator--(int)
	{
		Date da(*this);
		_day--;
		if (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += monthDays();
		}
		return da;
	}
	bool operator>(const Date& d)const
	{
		if (_year > d._year || (_year == d._year&&_month > d._month) || \
			(_year == d._year&&_month == d._month&&_day > d._day))
			return true;
		return false;
	}
	bool operator>=(const Date& d)const
	{
		if (_year > d._year || (_year == d._year&&_month > d._month) || \
			(_year == d._year&&_month == d._month&&_day >= d._day))
			return true;
		return false;
	}
	bool operator<(const Date& d)const
	{
		if (_year < d._year || (_year == d._year&&_month < d._month) || \
			(_year == d._year&&_month == d._month&&_day < d._day))
			return true;
		return false;
	}
	bool operator<=(const Date& d)const
	{
		if (_year < d._year || (_year == d._year&&_month < d._month) || \
			(_year == d._year&&_month == d._month&&_day <= d._day))
			return true;
		return false;
	}
	bool operator==(const Date& d)const
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return true;
		return false;
	}
	bool operator!=(const Date& d)const
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return false;
		return true;
	}
private:    
	int _year;    
	int _month;    
	int _day;
};
int main()
{
	Date d1(2015, 12, 31);
	Date d2(2015, 1, 1);

	Date d3 = d1 -365;
	//cout << (d1 - d2) << endl;
	//d1++;2
	//d2--;
	//Date d3 = --d1;
	//Date d4 = --d2;
	/*cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	Date da1 = d1--;
	Date da2 = --d1;
	Date da3 = d1++;
	Date da4 = ++d1;
	cout << (d1 - d2) << endl;*/
	d1++;
	d2--;


	system("pause");
	return 0;
}