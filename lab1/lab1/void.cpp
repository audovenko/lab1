#include "Header.h"
#include <stdio.h>
#include <iostream>
#include <random>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, N;
	int* mas1;


	printf("Выберите спсоб создания массива:\n1. Ввести вручную\n2. Созать рандомный массив\n");
	scanf_s("%d", &b);// Способ создания массива

	printf("\nВведите число элементов массива\n");
	scanf_s("%d", &N);//Ввод числа элементов массива

	mas1 = (int*)malloc(N * sizeof(int));

	switch (b)
	{
	case 1: //Создание массива вручную
		printf("\nВведите элементы массива\n");
		for (int i = 0; i < N; i++)
			scanf_s("%d", &mas1[i]);
		break;
	case 2: // Создание рандомного массива
		random_device rd;
		default_random_engine eng(rd());
		uniform_int_distribution<int> dist(0, 9);
		for (int i = 0; i < N; i++)
			mas1[i] = dist(eng);
		break;
	}

	int* mas = (int*)malloc(N * sizeof(int));
	//for (int i = 0; i < d; i++)
	//	mas[i] = mas1[i];


	printf("\n\n");
	while (true)
	{
		printf("\nВывод заданного массива:\n");
		for (int i = 0; i < N; i++)
			printf("%d ", mas1[i]);
		printf("\n\n");

		printf("Выберите способ сортировки\n1. Сортировка выбором\n2. Сортировка вставками\n3. Сортировка пузырьком\n4. Сортировка пузырьком с модификациями\n5. Сортировка подсчётом\n6. Сортировка слиянием\n7. Быстрая сортировка\n0. Выход\n\nВведите номер операции\n");
		scanf_s("%d", &a);//Выбор операции
		if (a == 0)
			return 0;


		switch (a)
		{

		case 1:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			choice(mas, N);
			break;
		case 2:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			inserts(mas, N);
			break;
		case 3:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			bubble(mas, N);
			break;
		case 4:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			bubblemode(mas, N);
			break;
		case 5:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			count(mas, N);
			break;
		case 6:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			merger(mas, N);
			break;
		case 7:
			copy(mas, mas1, N);
			printf("\n\nВывод отсортированного массива с промежуточными результатами сортировки:\n");
			fast(mas, N);
			break;
		}
		printf("\n");
	}
}