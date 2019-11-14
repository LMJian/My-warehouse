#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct StudentInfo
{
	char ID[11];
	char* name;
	float score;
}SInfo;

SInfo StuTmp[12] = { 0 };
SInfo StuInfo[12] =
{
	{"0800301105", "JACK", 95},
	{"0800201505", "LUN", 85},
	{"0400820115", "MARY", 75.5},
	{"0400850122", "KATE", 78.9},
	{"0500201011", "LILI", 88},
	{"0800401105", "JACK", 96},
	{"0600830105", "JAN", 98.4},
	{"0952520012", "SAM", 75},
	{"9721000045", "OSCAR", 64},
	{"0700301105", "JACK", 97},
	{"0458003312", "ZOE", 68.9},
	{"0400830211", "BOBI", 87.6}
};

void insertSort(SInfo* arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int j = i;
		while (j > 0 && strcmp((arr + j)->ID, (arr + j - 1)->ID) < 0)
		{
			char *_name = (arr + j)->name;
			(arr + j)->name = (arr + j - 1)->name;
			(arr + j - 1)->name = _name;

			float _score = (arr + j)->score;
			(arr + j)->score = (arr + j - 1)->score;
			(arr + j - 1)->score = _score;

			char tmp[11];
			strcpy(tmp, (arr + j)->ID);
			strcpy((arr + j)->ID, (arr + j - 1)->ID);
			strcpy((arr + j - 1)->ID, tmp);
			--j;
		}
	}
}

void dealQSort(SInfo* arr, int left, int right)
{
	if (left >= right)
		return;
	int i = left, j = right;
	int flag = 1;
	while (i < j)
	{
		if (strcmp(arr[i].name, arr[j].name) > 0)
		{
			char *_name = (arr + j)->name;
			(arr + j)->name = (arr + i)->name;
			(arr + i)->name = _name;

			float _score = (arr + j)->score;
			(arr + j)->score = (arr + i)->score;
			(arr + i)->score = _score;

			char tmp[11];
			strcpy(tmp, (arr + j)->ID);
			strcpy((arr + j)->ID, (arr + i)->ID);
			strcpy((arr + i)->ID, tmp);

			flag = !flag;
		}
		flag ? i++ : j--;
	}
	dealQSort(arr, left, i - 1);
	dealQSort(arr, i + 1, right);
}

void dealMergeSort(SInfo *arr, SInfo *tmp, int start, int end)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	dealMergeSort(arr, tmp, start, mid);
	dealMergeSort(arr, tmp, mid + 1, end);

	int a = start;
	int b = mid + 1;
	int c = a;
	for (; a <= mid && b <= end; c++)
	{
		if (strcmp(arr[a].name, arr[b].name) < 0)
		{
			strcpy(tmp[c].ID, arr[a].ID);
			tmp[c].name = arr[a].name;
			tmp[c].score = arr[a].score;
			a++;
		}
		else
		{
			strcpy(tmp[c].ID, arr[b].ID);
			tmp[c].name = arr[b].name;
			tmp[c].score = arr[b].score;
			b++;
		}
	}
	for (; a <= mid; a++, c++)
	{
		strcpy(tmp[c].ID, arr[a].ID);
		tmp[c].name = arr[a].name;
		tmp[c].score = arr[a].score;
	}
	for (; b <= end; b++, c++)
	{
		strcpy(tmp[c].ID, arr[b].ID);
		tmp[c].name = arr[b].name;
		tmp[c].score = arr[b].score;
	}
	for (int i = start; i <= end; i++)
	{
		strcpy(arr[i].ID, tmp[i].ID);
		arr[i].name = tmp[i].name;
		arr[i].score = tmp[i].score;
	}
}


int main()
{
	//insertSort(StuInfo, 12);
	//dealQSort(StuInfo, 0, 11);
	dealMergeSort(StuInfo, StuTmp, 0, 11);

	system("pause");
	return 0;
}

