#include<iostream>
#include<string>
using namespace std;

void test1()
{
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);
	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

}
void test2()
{
	string s("hello!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	/*cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;*/

	/*s.reserve(15);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	s.reserve(25);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	s.reserve(45);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;*/
	s.reserve(85);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(45);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(25);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(14);
	cout << s.size() << endl;
	cout << s.capacity() << endl; //newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity)，有效元素个数不变
								// newcapacity < oldcapacity(string类旧空间大小)：空间缩小，该函数直接返回 除非newcapacity < 15
								// 注意：只改变容量大小，不会改变有效元素个数，如果改变的空间大小小于了有效元素大小则不改变空间大小
	/*s.resize(20, 'c');
	cout << s << endl;
	s.resize(25);//默认用\0填充
	cout << s << endl;*/

}
void test3()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	// 如果越界---assert触发
	//cout << s[10] << endl;

	cout << s.at(2) << endl;
	s.at(2) = 'L';

	// 如果越界---抛出out_of_range异常
	//cout << s.at(10) << endl;
	const char *ss = s.c_str();
	cout << ss << endl;
}
void test4()
{
	string s1;
	s1.push_back('I');
	s1 += "Love ";
	s1.append("You ");
	s1.append(3, '!');
	cout << s1 << endl;
}
void test5()
{
	string s("12345");
	int ret = atoi(s.c_str());//字符串转整形
	cout << ret << endl;
}
void test6()
{
	string s = ("hello world!");
	size_t pos = s.find(' ');
	cout << string::npos << endl;
	if (pos != string::npos)
	{
		cout << ' ' << " is in s" << pos << endl;
	}
	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << " is in s" << pos << endl;
	}

	// 获取文件的后缀 - 20190923.cpp.cpp
	string ss("20190923.cpp.cpp");
	pos = ss.rfind('.') + 1;

	string filepox = ss.substr(pos);
	cout << filepox << endl;
}
void test7()
{
	string s("ADsdvsdvxz");
	auto it = s.begin();
	while (it != s.end())
		cout << *it++<<"   ";
}
void reversestring(string& s)
{
	 	char* begin = (char*)s.c_str();
	 	char* end = begin + s.size() - 1;
	 	while (begin < end)
	 	{
	 		swap(*begin, *end);
	 		begin++;
	 		end--;
	 	}

	reverse(s.begin(), s.end());//置逆字符串
}

int main()
{
	string s("abcdef");
	reversestring(s);
	////test7();
	//test2();
	//test1();


	system("pause");
	return 0;
}