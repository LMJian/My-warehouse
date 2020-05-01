#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#include<string>
const int kind = 36;//字母种类
int kg;
struct Treenode//树的结点结构
{
	long  count;//这个附加变量在本题中记录遍历到该结点形成的字符串出现的次数，在不同题中可记录不同的内容。
	//count现在改为记录这个存在的单词出现的次数
	bool exist;//是否存在这个单词
	string str;
	Treenode* next[kind];//指向儿子结点
	Treenode()//每个结点的初始化
	{
		exist = false;
		count = 0;
		for (int i = 0; i < kind; i++)
			next[i] = NULL;
	}
	Treenode(string str1, long count1)//每个结点的初始化
	{
		str = str1;
		exist = true;
		count = count1;
		for (int i = 0; i < kind; i++)
			next[i] = NULL;
	}
};

vector<Treenode> res;

void remove(int i, Treenode obj) {
	res[i].count = obj.count;
	res[i].exist = obj.exist;
	res[i].str = obj.str;
}

void insert_sort()//插入排序，从小到大
{
	int i, j, tmp;
	Treenode pos;

	for (i = 1; i < kg; i++)//第一个元素默认为有序
	{
		pos = res[i];
		j = i;
		tmp = res[i].count;
		while (j > 0 && res[j - 1].count > tmp) {
			remove(j, res[j - 1]);
			j--;
		}
		if (j != i) {
			remove(j, pos);
		}
	}
}

void sort()//插一次，找到位置
{
	int pos;
	pos = res[0].count;
	Treenode obj = res[0];
	for (int i = 1; i < res.size(); i++) {
		if (pos > res[i].count) {
			remove(i - 1, res[i]);
		}
		else {
			remove(i, obj);
			break;
		}
	}
}

void display(Treenode* root) {
	queue<Treenode*> alig;
	Treenode* location = root;
	alig.push(location);
	Treenode* obj;
	while (!alig.empty()) {
		obj = alig.front();
		alig.pop();
		for (int i = 0; i < 36; i++) {
			if (obj->next[i]) {
				alig.push(obj->next[i]);
			}
		}
		if (obj->exist) {
			cout << obj->str << endl;
		}
	}
}

void insert(Treenode*& root, char* word, int num)//向以root为根结点的树中插入串word
{
	Treenode* location = root;
	int i = 0, branch = 0;

	if (location == NULL) { location = new Treenode(); root = location; }

	while (word[i])
	{
		if (word[i] >= 'a') {
			branch = word[i] - 'a';
		}
		else if (word[i] >= '0') {
			branch = word[i] - 22;//存到后面
		}
		if (!location->next[branch]) location->next[branch] = new Treenode();//如果不存在，建新结点
		location = location->next[branch];
		i++;
	}
	location->exist = true;
	location->count = num;
	location->str = word;
}

int search(Treenode* root, char* word)//查找，与插入类似
{
	Treenode* location = root;
	int i = 0, branch = 0, ans;

	if (location == NULL) return 0;

	while (word[i])
	{
		if (word[i] >= 'a') {
			branch = word[i] - 'a';
		}
		else if (word[i] >= '0') {
			branch = word[i] - '0' + 26;
		}
		if (!location->next[branch]) return 0;//没有这个单词开头的单词
		//其他的就是有的情况，然后遍历树//找最大的k个数
		i++;
		location = location->next[branch];
		ans = location->count;
	}
	return ans;
}

Treenode* find(Treenode* root, string word) {
	Treenode* location = root;
	int i = 0, branch = 0, ans;

	if (location == NULL) return 0;

	while (word[i])
	{
		if (word[i] >= 'a') {
			branch = word[i] - 'a';
		}
		else if (word[i] >= '0') {
			branch = word[i] - '0' + 26;
		}
		if (!location->next[branch]) return NULL;//没有这个单词开头的单词
		i++;
		location = location->next[branch];
		//      ans = location->count;
	}
	//location的地方开始遍历
	//其他的就是有的情况，然后遍历树//找最大的k个数
 //   return ans;
	return location;
}

void traverse(Treenode* f) {//从find函数返回的返回值来进行遍历
	queue<Treenode*> alig;
	vector<Treenode*> test;
	Treenode* location = f;
	alig.push(location);
	while (!alig.empty()) {
		Treenode *obj;
		obj = alig.front();
		alig.pop();
		for (int i = 0; i < 36; i++) {
			if (obj->next[i]) {
				alig.push(obj->next[i]);
				test.push_back(obj->next[i]);
			}
		}
		if (obj->exist && obj == f) continue;
		if (obj->exist) {
			Treenode asd(obj->str, obj->count);
			//          cout << asd.str <<"  "<<asd.count<< endl;
			if (res.size() < kg) {
				res.push_back(asd);
				if (res.size() == kg) {
					insert_sort();
				}
			}
			else if (res[0].count < asd.count) {
				//替换最小的0处
				remove(0, asd);//把0处的用obj替换掉
				insert_sort();
			}
		}
	}
}

int main()
{
	char word[21];
	//   string ask;
	Treenode* root = NULL;
	long int num = 0;
	int n, m, k;
	cin >> n >> m >> k;
	kg = k;
	//字典树养成
	for (int i = 0; i < n; i++) {
		cin >> num;
		cin >> word;
		insert(root, word, num);
	}

	vector<string> str;
	for (int i = 0; i < m; i++) {
		string ask;
		cin >> ask;
		str.push_back(ask);
		cout << ask << endl;
	}

	for (int i = 0; i < m; i++) {
		//        cout << "yoriko" << endl;
		Treenode* node;
		string ask;
		ask = str[i];
		node = find(root, ask);
		if (node == NULL) {
			cout << "no suggestion" << endl;
		}
		else {
			traverse(node);
			for (int k = res.size() - 1; k >= 0; k--) {
				cout << res[k].str << endl;
			}
			res.clear();
		}
		cout << endl;
	}
	return 0;
}