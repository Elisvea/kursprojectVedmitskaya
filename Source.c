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
int file(int** array); //Чтение из файла и заполнение массива
int uch(int** array); //Функция, которая позволяет вывести на экран исходную таблицу c очками участников
int kom(int** array, int* arraySUM, int* res); //Функция, которая заполняет массив с очками команд
int rkom(int* res); //Функция, которая позволяет вывести на экран таблицу с очками команд
int sumsort(int number[15], int* res); //Функция, которая позволяет вывести на экран таблицу с очками команд по возрастанию или убыванию
int vch(int number[15], int* res); //Функция, которая позволяет максимальное количество очков по командам, минимальное количество очков по командам, среднее значение очков, общее значение очков
int qwer(int number[15], int* res); //Функция, которая позволяет найти лучшую или худшую команды, команды, набравшие более или менее определённого количества очков
int change(int** array); //Функция, которая позволяет изменить значения очков в ячейке


int main() {
	setlocale(LC_ALL, "rus");
	int a = 1; //Переменная, используемая для ввода значений в switch

	int* arraySUM = (int**)malloc(arrh0 * sizeof(int*)); //Выделение памяти под одномерные массивы
	int* res = (int**)malloc(arrh * sizeof(int*));;

	int** array = array_memory(); //Выделение памяти под двумерный массив

	int number[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };//Массив с номерами команд


	file(array);
	kom(array, arraySUM, res);
	while (1) {
		printf("Выберите нужный вариант:\n1) Таблица результатов соревнований по участникам\n2) Правила присваивания очков\n3) Результирующая таблица по командам\n4) Таблица результатов соревнований по командам в порядке возрастания или убывания\n5) Вывод общего, среднего, минимального и максимального количества очков\n6) Поиск лучшей команды, худшей команды, набравших более или менее введенного количества очков\n7) Изменение очков участников в таблице\n8) Выход\n Вы выбрали пункт: ");
		scanf_s("%d", &a);

		switch (a) {
		case 1:
			uch(array); //Функция, которая позволяет вывести на экран исходную таблицу c очками участников
			break;
		case 2:
			puts("\n");
			printf("Места пересчитываются в очки по правилу: Схема простая : 1 - е место – 15 очков, 2 - е – 12, 3 - е – 10, 4 - е – 8, 5 - е – 6, 6 - е – 5, 7 - е – 4, 8 - е – 3, 9 - е – 2 и 10 - е – 1.");
			puts("\n"); //Правила присваивания очков
			break;
		case 3:
			rkom(res); //Функция, которая позволяет вывести на экран таблицу с очками команд
			break;
		case 4:
			sumsort(number, res); //Функция, которая позволяет вывести на экран таблицу с очками команд по возрастанию или убыванию
			break;
		case 5:
			vch(number, res); //Функция, которая позволяет вывести максимальное количество очков по командам, минимальное количество очков по командам, среднее значение очков, общее значение очков
			break;
		case 6:
			qwer(number, res); //Функция, которая позволяет найти лучшую или худшую команды, команды, набравшие более или менее определённого количества очков
			break;
		case 7:
			change(array); //Функция, которая позволяет изменить значения очков в ячейке
			uch(array); //Функция, которая позволяет вывести на экран исходную таблицу c очками участников
			break;
		case 8:
			exit(EXIT_SUCCESS); //Завершение работы программы
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
		printf("\t\tЭтап %d", i);
	}
	for (int i = 1; i <= arrh1; i++) {
		printf("\n\n");
		for (int j = 0; j < arrsh; j++) {
			if (j == 0) {
				if (array[i - 1][j] == 0) {
					printf("Участник %d", i);
				}
				else {
					printf("Участник %d \t %d", i, array[i - 1][j]);
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
		printf("Команда %d %d\n", i + 1, res[i]);
	}
	puts("\n");
}

int sumsort(int number[15], int* res) {
	printf("Выполнить сортировку команд:\n1)По возрастанию\n2)По убыванию\n");
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
		printf(" Команда %2d %5d\n", number[i], res[i]);
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
	printf("Максимальное количество очков по командам : Команда %d Очков %d\n", number[ind], max);

	int min = 10000;
	int ind1 = 0;
	for (int i = 0; i < arrh; i++) {
		if (res[i] < min) {
			min = res[i];
			ind1 = i;
		}
	}
	printf("Минимальное количество очков по командам : Команда %d Очков %d\n", number[ind1], min);

	int sum1 = 0;
	float sr = 0.0;
	for (int i = 0; i < arrh; i++) {
		sum1 = sum1 + res[i];
	}
	sr = (float)sum1 / 15;
	printf("Среднее значение очков : %.2f\n", sr);
	printf("Общее значение очков : % d\n", sum1);

	puts("\n");
	return 0;
}

int qwer(int number[15], int* res) {
	int sum = 0;
	int x = 0;
	puts("Выберите пункт:");
	puts("1)Лучшая команда");
	puts("2)Худшая команда");
	puts("3)Команда, набравшая более определённого количества очков");
	puts("4)Команда, набравшая менее определённого количества очков");
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
		printf("Лучшая команда : %d\n", number[ind]);
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
		printf("Худшая команда : %d\n", number[ind1]);
		puts("\n");
	}
	else if (x == 3) {
		puts("Введите количество очков: ");
		int x1 = 0;
		scanf("%d", &x1);
		for (int i = 0; i < arrh; i++) {
			if (res[i] > x1) {
				printf("Команда %d %d\n", i + 1, res[i]);
			}
		}
	}
	else if (x == 4) {
		puts("Введите количество очков: ");
		int x1 = 0;
		scanf("%d", &x1);
		for (int i = 0; i < arrh; i++) {
			if (res[i] < x1) {
				printf("Команда %d %d\n", i + 1, res[i]);
			}
		}
	}
}

int change(int** array) {

	int x = 0, y = 0;
	int m;

	system("cls");
	printf("Участник по горизонтали:");
	scanf("%i", &x);
	printf("Этап по вертикали:");
	scanf("%i", &y);
	system("cls");

	if (array[x][y] == 0) {
		printf("В этом этапе участник не учавствует");
		printf("Выберите другой этап по вертикали:");
		scanf("%i", &y);
	}

	printf("Новое значение ячейки Участника %i\n", x);

	printf("Очки участника %i:", x);
	scanf("%i", &m);



	y--;
	x--;

	array[x][y] = m;

}