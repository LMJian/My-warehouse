#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

/*void reverse(char *p) {
	char *left = p;
	char *right = p;
	while (*right != '\0')
		++right;
	--right;
	while (left < right){
		char tmp = *left;
		*left = *right;
		*right = tmp;
		++left;
		--right;
	}
}*/
#include<assert.h>

/*class String {
public:
	String(const char* str = "") 
	:str_(nullptr)
	{
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}
	~String() {
		if (str_) {
			delete[] str_;
			str_ = nullptr;
		}
	}
	String(const String& str)
	:str_(nullptr)
	{
		String tmp(str.c_str());
		swap(str_, tmp.str_);
	}
	String& operator=(const String& str) 
	{
		String tmp(str.c_str());
		swap(str_, tmp.str_);
		return *this;
	}
private:
	const char* c_str() const{
		return str_;
	}
	char * str_;
}; 
void test() {
	String str("1234");
	String s1(str);
	String s2 = s1;
}*/
#include<string>

std::string add(const std::string &a, const std::string &b) {
	string ret = "";   //较大字符串
	string str = "";   //较小字符串
	if (a.size() > b.size()) {
		ret = a;
		str = b;
	}
	else {
		ret = b;
		str = a;
	}
	auto pRet = ret.rbegin();
	auto pStr = str.rbegin();
	int flag = 0;
	while (pStr != str.rend()) {
		*pRet = *pRet + *pStr - '0' + flag;
		flag = 0;
		if (*pRet > '9') {
			flag = 1;
			*pRet -= 10;
		}
		++pRet;
		++pStr;
	}
	while (flag&&pRet != ret.rend()) {
		*pRet += flag;
		flag = 0;
		if (*pRet > '9') {
			flag = 1;
			*pRet -= 10;
		}
		++pRet;
	}
	if (flag)
		ret = "1" + ret;
	return ret;
}

int main() {
	
	string ret = add("9999", "0001");
	cout << ret << endl;

	//test();
	//char arr[] = "abcdefg";
    //reverse(arr);
	//cout << arr << endl;
	

	system("pause");
	return 0;
}