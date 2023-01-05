#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

#include <stdlib.h>
#define _USE_MATH_DEFINES

#include <math.h>
#include <locale.h>

#define arrh0 30
#define arrh 15
#define arrh1 30
#define arrsh 6

int** array_memory();
int file(int** array); //������ �� ����� � ���������� �������
int uch(int** array); //�������, ������� ��������� ������� �� ����� �������� ������� c ������ ����������
int kom(int** array, int* arraySUM, int* res); //�������, ������� ��������� ������ � ������ ������
int rkom(int* res); //�������, ������� ��������� ������� �� ����� ������� � ������ ������
int sumsort(int number[15], int* res); //�������, ������� ��������� ������� �� ����� ������� � ������ ������ �� ����������� ��� ��������
int vch(int number[15], int* res); //�������, ������� ��������� ������������ ���������� ����� �� ��������, ����������� ���������� ����� �� ��������, ������� �������� �����, ����� �������� �����
int qwer(int number[15], int* res); //�������, ������� ��������� ����� ������ ��� ������ �������, �������, ��������� ����� ��� ����� ������������ ���������� �����
int change(int** array); //�������, ������� ��������� �������� �������� ����� � ������


int main() {
	setlocale(LC_ALL, "rus");
	int a = 1; //����������, ������������ ��� ����� �������� � switch

	int* arraySUM = (int**)malloc(arrh0 * sizeof(int*)); //��������� ������ ��� ���������� �������
	int* res = (int**)malloc(arrh * sizeof(int*));;

	int** array = array_memory(); //��������� ������ ��� ��������� ������

	int number[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };//������ � �������� ������


	file(array);
	kom(array, arraySUM, res);
	while (1) {
		printf("�������� ������ �������:\n1) ������� ����������� ������������ �� ����������\n2) ������� ������������ �����\n3) �������������� ������� �� ��������\n4) ������� ����������� ������������ �� �������� � ������� ����������� ��� ��������\n5) ����� ������, ��������, ������������ � ������������� ���������� �����\n6) ����� ������ �������, ������ �������, ��������� ����� ��� ����� ���������� ���������� �����\n7) ��������� ����� ���������� � �������\n8) �����\n �� ������� �����: ");
		scanf_s("%d", &a);

		switch (a) {
		case 1:
			uch(array); //�������, ������� ��������� ������� �� ����� �������� ������� c ������ ����������
			break;
		case 2:
			puts("\n");
			printf("����� ��������������� � ���� �� �������: ����� ������� : 1 - � ����� � 15 �����, 2 - � � 12, 3 - � � 10, 4 - � � 8, 5 - � � 6, 6 - � � 5, 7 - � � 4, 8 - � � 3, 9 - � � 2 � 10 - � � 1.");
			puts("\n"); //������� ������������ �����
			break;
		case 3:
			rkom(res); //�������, ������� ��������� ������� �� ����� ������� � ������ ������
			break;
		case 4:
			sumsort(number, res); //�������, ������� ��������� ������� �� ����� ������� � ������ ������ �� ����������� ��� ��������
			break;
		case 5:
			vch(number, res); //�������, ������� ��������� ������� ������������ ���������� ����� �� ��������, ����������� ���������� ����� �� ��������, ������� �������� �����, ����� �������� �����
			break;
		case 6:
			qwer(number, res); //�������, ������� ��������� ����� ������ ��� ������ �������, �������, ��������� ����� ��� ����� ������������ ���������� �����
			break;
		case 7:
			change(array); //�������, ������� ��������� �������� �������� ����� � ������
			uch(array); //�������, ������� ��������� ������� �� ����� �������� ������� c ������ ����������
			break;
		case 8:
			exit(EXIT_SUCCESS); //���������� ������ ���������
			break;
		}
	}
}

int** array_memory()
{
	int** array = (int**)malloc(arrh1 * sizeof(int*));
	for (int i = 0; i < 30; i++) {
		array[i] = (int*)malloc(30 * sizeof(int));
	}
	return array;
}

int file(int** array) {
	FILE* pog;
	pog = fopen("gonki.txt", "r");
	if (pog == NULL) {
		printf("ERROR");
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 6; j++) {
			fscanf(pog, "%d", &array[i][j]);
		}
	}
	return array;
}

int uch(int** array) {
	for (int i = 1; i < 7; i++) {
		printf("\t\t���� %d", i);
	}
	for (int i = 1; i <= arrh1; i++) {
		printf("\n\n");
		for (int j = 0; j < arrsh; j++) {
			if (j == 0) {
				if (array[i - 1][j] == 0) {
					printf("�������� %d", i);
				}
				else {
					printf("�������� %d \t %d", i, array[i - 1][j]);
				}
			}
			else {
				if (array[i - 1][j] == 0) {
					printf("\t");
				}
				else {
					printf("%27d", array[i - 1][j]);
				}
			}
		}
	}
	printf("\n\n");

}

int kom(int** array, int* arraySUM, int* res) {
	int sum = 0;
	for (int i = 0; i < arrh1; i++) {
		for (int j = 0; j < arrsh; j++) {
			sum += array[i][j];
		}
		if (i % 2 != 0) {

			arraySUM[i - 1] = sum;
			sum = 0;

		}
	}

	for (int i = 0, j = 0; i < 16; i++) {
		res[i] = arraySUM[j];
		j = j + 2;
	}
	return array;
}

int rkom(int* res) {
	int sum = 0;
	puts("\n");
	for (int i = 0; i < arrh; i++) {
		printf("������� %d %d\n", i + 1, res[i]);
	}
	puts("\n");
}

int sumsort(int number[15], int* res) {
	printf("��������� ���������� ������:\n1)�� �����������\n2)�� ��������\n");
	int w = 0;

	scanf("%d", &w);

	for (int i = 0; i < arrh - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < arrh; j++)
		{
			if (((w == 1) && (res[j] < res[max])) || ((w == 2) && ((res[j] > res[max]))))

				max = j;
		}
		int vrem = res[i];
		res[i] = res[max];
		res[max] = vrem;
		int vremnum = number[i];
		number[i] = number[max];
		number[max] = vremnum;
	}
	for (int i = 0; i < arrh; i++) {
		printf(" ������� %2d %5d\n", number[i], res[i]);
	}
}


int vch(int number[15], int* res) {
	int sum = 0;
	int max = -10000;
	int ind = 0;
	for (int i = 0; i < arrh;
		i++) {
		if (res[i] > max) {
			max = res[i];
			ind = i;
		}
	}
	puts("\n");
	printf("������������ ���������� ����� �� �������� : ������� %d ����� %d\n", number[ind], max);

	int min = 10000;
	int ind1 = 0;
	for (int i = 0; i < arrh; i++) {
		if (res[i] < min) {
			min = res[i];
			ind1 = i;
		}
	}
	printf("����������� ���������� ����� �� �������� : ������� %d ����� %d\n", number[ind1], min);

	int sum1 = 0;
	float sr = 0.0;
	for (int i = 0; i < arrh; i++) {
		sum1 = sum1 + res[i];
	}
	sr = (float)sum1 / 15;
	printf("������� �������� ����� : %.2f\n", sr);
	printf("����� �������� ����� : % d\n", sum1);

	puts("\n");
	return 0;
}

int qwer(int number[15], int* res) {
	int sum = 0;
	int x = 0;
	puts("�������� �����:");
	puts("1)������ �������");
	puts("2)������ �������");
	puts("3)�������, ��������� ����� ������������ ���������� �����");
	puts("4)�������, ��������� ����� ������������ ���������� �����");
	scanf("%d", &x);
	if (x == 1) {
		int max = -10000;
		int ind = 0;
		for (int i = 0; i < arrh; i++) {
			if (res[i] > max) {
				max = res[i];
				ind = i;
			}
		}
		puts("\n");
		printf("������ ������� : %d\n", number[ind]);
	}
	else if (x == 2) {
		int min = 10000;
		int ind1 = 0;
		for (int i = 0; i < arrh; i++) {
			if (res[i] < min) {
				min = res[i];
				ind1 = i;
			}
		}
		printf("������ ������� : %d\n", number[ind1]);
		puts("\n");
	}
	else if (x == 3) {
		puts("������� ���������� �����: ");
		int x1 = 0;
		scanf("%d", &x1);
		for (int i = 0; i < arrh; i++) {
			if (res[i] > x1) {
				printf("������� %d %d\n", i + 1, res[i]);
			}
		}
	}
	else if (x == 4) {
		puts("������� ���������� �����: ");
		int x1 = 0;
		scanf("%d", &x1);
		for (int i = 0; i < arrh; i++) {
			if (res[i] < x1) {
				printf("������� %d %d\n", i + 1, res[i]);
			}
		}
	}
}

int change(int** array) {

	int x = 0, y = 0;
	int m;

	system("cls");
	printf("�������� �� �����������:");
	scanf("%i", &x);
	printf("���� �� ���������:");
	scanf("%i", &y);
	system("cls");

	if (array[x][y] == 0) {
		printf("� ���� ����� �������� �� ����������");
		printf("�������� ������ ���� �� ���������:");
		scanf("%i", &y);
	}

	printf("����� �������� ������ ��������� %i\n", x);

	printf("���� ��������� %i:", x);
	scanf("%i", &m);



	y--;
	x--;

	array[x][y] = m;

}