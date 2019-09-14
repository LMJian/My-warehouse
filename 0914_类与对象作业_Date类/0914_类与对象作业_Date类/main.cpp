#include<iostream>
using namespace std;

class Date 
{
public:    
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
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
		da._day += days;
		if (da._day > monthDays())
		{
			da._month++;
			da._day -= monthDays();
			if (da._month > 12)
			{
				da._month = 1;
				da._year++;
			}
		}
		return da;
	}
	Date operator-(int days)
	{
		Date da(*this);
		da._day -= days;
		if (da._day <= 0)
		{
			da._month--;
			da._day += da.monthDays();
			if (da._month == 0)
			{
				da._month = 12;
				da._year--;
			}
		}
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
			_day = _day - monthDays();
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
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
			_day = _day - monthDays();
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}
		return da;
	}
	Date& operator--()
	{
		_day--;
		if (_day <= 0)
		{
			_month--;
			_day += monthDays();
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
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
			_day += monthDays();
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
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

	Date d1(2019, 12, 31);
	Date d2(2016, 1, 1);
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