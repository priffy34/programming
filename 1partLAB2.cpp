#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void clean() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
	setlocale(LC_ALL, "Russian");
	printf("-----------------------------------------------------------------------\n");
	printf("этот код определяет номера строк массива которые имеют нулевые элементы\n");
	printf("-----------------------------------------------------------------------\n");
	float mass[10][10];
	int str, col;
	printf("напишите кол-во строк и столбцов через пробел(не больше 10)\n>>>> ");
	while(1){
		int input = scanf("%d %d", &str, &col);
		if (input != 2) {
			printf("ОШИБКА! Введены не числа! Попробуйте снова.\n>>>> ");
			clean();
			continue;
		}
		if (str>10 || col>10) {
			printf("ОШИБКА!попробуй целое число не больше 10!\n>>>> ");
			clean();
			continue;
		}
		break;
	}
	for (int i = 0; i < str; i++) {
		printf("строка %d: ", i + 1);
		for (int j = 0; j < col; j++)
			scanf("%f", &mass[i][j]);
	}
	printf("-----------------------------------------------------------------------\nРезультат:\n");
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < col; j++)
			if (mass[i][j] == 0) {
				printf("строка %d имеет нулевой элемент\n", i + 1);
				break;
			}
	}
	printf("-----------------------------------------------------------------------\n");
}
