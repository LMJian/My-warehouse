#include<iostream>
#include<assert.h>
#include<time.h>
using namespace std;

void *MyMemcpy(void *to, const void *from, size_t count) {
	assert(to);
	assert(from);
	char* left = (char*)to + count - 1;
	const char* right = (const char*)from + count - 1;
	while (count--) {
		*left = *right;
		--left;
		--right;
	}
	return to;
}
void *MyMemcpy1(void *to, const void *from, size_t count) {
	assert(to);
	assert(from);
	long long* left = (long long*)to;
	const long long* right = (const long long*)from;
	int size = count / 8;
	while (size--) {
		*left = *right;
		++left;
		++right;
	}
	size = count % 8;
	char* l = (char*)left;
	const char* r = (const char*)right;
	while (size--) {
		*l = *r;
		++l;
		++r;
	}
	return to;
}

int main() {
	char a[20] = "123456789987654321";
	char b[20] = { 0 };

	MyMemcpy1(b, a, 18);
	cout << b << endl;
	system("pause");
	return 0;
}