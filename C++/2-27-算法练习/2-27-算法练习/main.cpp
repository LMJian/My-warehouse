#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

void Sort(int* left, int* right) {
	if (left >= right)
		return;
	int* i = left;
	int* j = right;
	bool flag = false;
	while (i < j) {
		if (*i > *j) {
			int tmp = *i;
			*i = *j;
			*j = tmp;
			flag = !flag;
		}
		flag ? ++i : --j;
	}
	Sort(left, i - 1);
	Sort(i + 1, right);
}

int BinSearch(const vector<int>& arr,const int num) {
	int left = 0;
	int right = arr.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num < arr[mid])
			right = mid - 1;
		else if (num > arr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

void MergeSort(int *arr, int *tmp, int left, int right) {
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(arr, tmp, left, mid);
	MergeSort(arr, tmp, mid + 1, right);
	int startA = left;
	int startB = mid + 1;
	int index = left;
	for (; startA <= mid && startB <= right; ++index) {
		if (arr[startA] < arr[startB]) {
			tmp[index] = arr[startA];
			++startA;
		}
		else {
			tmp[index] = arr[startB];
			++startB;
		}
	}
	for (; startA <= mid; ++index, ++startA)
		tmp[index] = arr[startA];
	for (; startB <= right; ++index, ++startB)
		tmp[index] = arr[startB];
	for (int i = left; i <= right; ++i)
		arr[i] = tmp[i];
}

void treeQSort(int* arr, int left, int right) {
	if (left >= right)
		return;
	int midL = left;
	int midR = right + 1;
	int i = left + 1;
	int tmp = arr[left];
	while (i < midR) {
		if (arr[i] < tmp) {
			int t = arr[i];
			arr[i] = arr[midL + 1];
			arr[midL + 1] = t;
			++midL;
			++i;
		}
		else if (arr[i] > tmp) {
			int t = arr[i];
			arr[i] = arr[midR - 1];
			arr[midR - 1] = t;
			--midR;
		}
		else
			++i;
	}
	int t = arr[left];
	arr[left] = arr[midL];
	arr[midL] = t;
	treeQSort(arr, left, midL - 1);
	treeQSort(arr, midR, right);
}

int main() {
	int arr[] = { 5,8,7,4 ,5,6,3,2,5 };
	int *tmp = new int[9];
	treeQSort(arr,0, 8);
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	/*srand(time(NULL));

	for (int i = 0; i < 10; ++i)
		cout << rand() % 10 << endl;

	//cout << x << endl;*/
	/*int arr[] = { 1,3,6,2,9,8,5,7,4 };
	Sort(arr, arr + 8);
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;*/
	system("pause");
	return 0;
}