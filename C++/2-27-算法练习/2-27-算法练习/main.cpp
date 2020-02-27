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

void qSort(int* arr, int l, int r) {
	if (l >= r) {
		return;
	}
	int v = arr[l];
	int lt = l;
	int i = l + 1;
	int gt = r + 1;
	while (i < gt) {
		if (arr[i] < v) {
			int tmp = arr[i];
			arr[i] = arr[lt + 1];
			arr[lt + 1] = tmp;
			//swap(arr, i, lt + 1);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			int tmp = arr[i];
			arr[i] = arr[gt - 1];
			arr[gt - 1] = tmp;
			//swap(arr, i, gt - 1);
			gt--;
		}
		else {
			i++;
		}
	}
	// 循环⾛走完只需要将l位置的元素与lt交换即为分区点
	int tmp = arr[l];
	arr[l] = arr[lt];
	arr[lt] = tmp;
	//swap(arr, l, lt);
	qSort(arr, l, lt - 1);
	qSort(arr, gt, r);
}

int main() {
	int arr[] = { 5,8,7,4 ,9,6,3,2,1 };
	int *tmp = new int[9];
	qSort(arr, 0, 8);
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