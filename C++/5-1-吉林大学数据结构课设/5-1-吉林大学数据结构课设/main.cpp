#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#include<string>
const int kind = 36;//��ĸ����
int kg;
struct Treenode//���Ľ��ṹ
{
	long  count;//������ӱ����ڱ����м�¼�������ý���γɵ��ַ������ֵĴ������ڲ�ͬ���пɼ�¼��ͬ�����ݡ�
	//count���ڸ�Ϊ��¼������ڵĵ��ʳ��ֵĴ���
	bool exist;//�Ƿ�����������
	string str;
	Treenode* next[kind];//ָ����ӽ��
	Treenode()//ÿ�����ĳ�ʼ��
	{
		exist = false;
		count = 0;
		for (int i = 0; i < kind; i++)
			next[i] = NULL;
	}
	Treenode(string str1, long count1)//ÿ�����ĳ�ʼ��
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

void insert_sort()//�������򣬴�С����
{
	int i, j, tmp;
	Treenode pos;

	for (i = 1; i < kg; i++)//��һ��Ԫ��Ĭ��Ϊ����
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

void sort()//��һ�Σ��ҵ�λ��
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

void insert(Treenode*& root, char* word, int num)//����rootΪ���������в��봮word
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
			branch = word[i] - 22;//�浽����
		}
		if (!location->next[branch]) location->next[branch] = new Treenode();//��������ڣ����½��
		location = location->next[branch];
		i++;
	}
	location->exist = true;
	location->count = num;
	location->str = word;
}

int search(Treenode* root, char* word)//���ң����������
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
		if (!location->next[branch]) return 0;//û��������ʿ�ͷ�ĵ���
		//�����ľ����е������Ȼ�������//������k����
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
		if (!location->next[branch]) return NULL;//û��������ʿ�ͷ�ĵ���
		i++;
		location = location->next[branch];
		//      ans = location->count;
	}
	//location�ĵط���ʼ����
	//�����ľ����е������Ȼ�������//������k����
 //   return ans;
	return location;
}

void traverse(Treenode* f) {//��find�������صķ���ֵ�����б���
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
				//�滻��С��0��
				remove(0, asd);//��0������obj�滻��
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
	//�ֵ�������
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