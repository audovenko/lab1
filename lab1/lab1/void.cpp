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


	printf("�������� ����� �������� �������:\n1. ������ �������\n2. ������ ��������� ������\n");
	scanf_s("%d", &b);// ������ �������� �������

	printf("\n������� ����� ��������� �������\n");
	scanf_s("%d", &N);//���� ����� ��������� �������

	mas1 = (int*)malloc(N * sizeof(int));

	switch (b)
	{
	case 1: //�������� ������� �������
		printf("\n������� �������� �������\n");
		for (int i = 0; i < N; i++)
			scanf_s("%d", &mas1[i]);
		break;
	case 2: // �������� ���������� �������
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
		printf("\n����� ��������� �������:\n");
		for (int i = 0; i < N; i++)
			printf("%d ", mas1[i]);
		printf("\n\n");

		printf("�������� ������ ����������\n1. ���������� �������\n2. ���������� ���������\n3. ���������� ���������\n4. ���������� ��������� � �������������\n5. ���������� ���������\n6. ���������� ��������\n7. ������� ����������\n0. �����\n\n������� ����� ��������\n");
		scanf_s("%d", &a);//����� ��������
		if (a == 0)
			return 0;


		switch (a)
		{

		case 1:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			choice(mas, N);
			break;
		case 2:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			inserts(mas, N);
			break;
		case 3:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			bubble(mas, N);
			break;
		case 4:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			bubblemode(mas, N);
			break;
		case 5:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			count(mas, N);
			break;
		case 6:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			merger(mas, N);
			break;
		case 7:
			copy(mas, mas1, N);
			printf("\n\n����� ���������������� ������� � �������������� ������������ ����������:\n");
			fast(mas, N);
			break;
		}
		printf("\n");
	}
}