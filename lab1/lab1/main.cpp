#include "Header.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

void output(int* mas, int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", mas[i]);
	printf("\n");
}

void copy(int* mas, int* mas1, int N)
{
	for (int i = 0; i < N; i++)
		mas[i] = mas1[i];
}


void choice(int* mas, int N)
{
	int t;
	for (int i = 0; i < N; i++)
	{
		int min = i;
		for (int j = i; j < N; j++)
			if (mas[min] > mas[j])
				min = j;
		t = mas[min];
		mas[min] = mas[i];
		mas[i] = t;
		output(mas, N);
	}
}

void inserts(int* mas, int N)
{
	int t, j;

	for (int i = 1; i < N; i++)
	{
		t = mas[i];
		j = i - 1;
		while (mas[j] > t)
		{
			mas[j + 1] = mas[j];
			j = j - 1;
		}
		mas[j + 1] = t;
		output(mas, N);
	}
}

void bubble(int* mas, int N)
{
	int t;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				t = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = t;
			}
		}
		output(mas, N);
	}

}

void bubblemode(int* mas, int N)
{
	int t;
	bool Swap;

	for (int i = N - 1; i >= 0; i--)
	{
		Swap = 1;
		for (int j = 0; j < i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				t = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = t;
				Swap = 0;
				output(mas, N);
			}
		}
		if (Swap == 1)
			break;
	}
}

void count(int* mas, int N)
{
	int max = mas[0]; // поиск максимума
	for (int i = 0; i < N; i++)
	{
		if (mas[i] > max)
			max = mas[i];
	}
	printf("%d\n", max);
	int mas1[10];
	for (int i = 0; i < 10; i++) // зануление доп массива
		mas1[i] = 0;
	output(mas1, 10);
	for (int i = 0; i < N; i++) //проход по массиву
		mas1[mas[i]]++;
	output(mas1, 10);
	int k = 0;
	for (int i = 0; i <= max; i++)
	{
		if (mas1[i] == 0)
			continue;

		for (int j = 0; j < mas1[i]; j++)
		{
			mas[k] = i;
			k++;
		}
	}
	printf("\n");
	output(mas, N);
}




void mergersort(int* mas, int* G, int mid, int* r, int nR) {
	int i = 0, j = 0, k = 0;
	while (i < mid && j < nR) /*nR - элемент второй части */
	{ /*mid - элемент середны */
		if (G[i] < r[j])
			mas[k++] = G[i++];
		else
			mas[k++] = r[j++];
	}
	while (i < mid)
	{
		mas[k++] = G[i++];
	}
	while (j < nR)
	{
		mas[k++] = r[j++];
	}
}

void merger(int* mas, int N)
{
	if (N < 2)
		return;
	int mid = N / 2;
	int* left = (int*)malloc(mid * sizeof(int));
	int* right = (int*)malloc(sizeof(int) * (N - mid));
	for (int i = 0; i < mid; i++)
		left[i] = mas[i];
	for (int i = mid; i < N; i++)
		right[i - mid] = mas[i];
	merger(left, mid);
	merger(right, N - mid);
	mergersort(mas, left, mid, right, N - mid);
	output(mas, N);
}





void fast(int* mas, int N)
{

	int i = 0;// начало массива 
	int j = N - 1; // конец массива
	int mid = mas[N / 2];//Центральный элемент массива
	//Делим массив
	do
	{
		//проходим по элементам, ищем те, которые нужно переместить  в другую часть
		//В левой части массива пропускаем элементы, которые меньше центрального
		while (mas[i] < mid)
		{
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (mas[j] > mid)
		{
			j--;
		}
		//Меняем элементы местами
		if (i <= j) {
			int t = mas[i];
			mas[i] = mas[j];
			mas[j] = t;
			i++;
			j--;
		}

	}

	while (i <= j);
	{
		//Рекурсивные вызовы, если осталось, что сортировать
		if (j > 0)
			fast(mas, j + 1);   //"Левый кусок"
		if (i < N)
			fast(&mas[i], N - i);   //"Првый кусок"
		output(mas, N);
	}

}
