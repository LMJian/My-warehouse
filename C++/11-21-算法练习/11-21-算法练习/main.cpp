#include<iostream>
#include<vector>
using namespace std;

/*class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		vector<int> key;
		for (int i = 0; i < length; ++i) {
			int num = numbers[i];
			key.resize(num + 1);
			++key[num];
			if (key[num] > 1)
			{
				*duplication = num;
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution sa;
	int arr[] = { 2,4,3,1,4 };
	int num = -1;
	cout << sa.duplicate(arr, 5, &num) << endl;
	cout << num << endl;
	system("pause");
	return 0;
}*/

/*struct st_task { 
	uint16_t id; 
	uint32_t value; 
	uint64_t timestamp; 
};
void fool() { 
	st_task task = {}; 
	uint64_t a = 0x00010001; 
	memcpy(&task, &a, sizeof(uint64_t)); 
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp); 
}*/

class myClass {
public:
	~myClass() { delete this; //this = NULL; 
	}
};
void test() {
	myClass sa;

}
void func(const int v1, const int v2) { 
	std::cout << v1 << ' '; 
	std::cout << v2 << ' '; 
}
int main(int argc, char* argv[]) { 
	int i = 0; 
	func(++i, i++);
	system("pause");
	return 0; 
}
/*int main() {
	//fool();
	test();
	system("pause");
	return 0;
}*/