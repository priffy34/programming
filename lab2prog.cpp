#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void clean() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void program1() {
    printf("\n-----------------------------------------------------------------------\n");
    printf("этот код определяет номера строк массива которые имеют нулевые элементы\n");
    printf("-----------------------------------------------------------------------\n");
    float mass[10][10];
    int str, col;
    printf("напишите кол-во строк и столбцов через пробел(не больше 10)\n>>>> ");
    while (1) {
        int input = scanf("%d %d", &str, &col);
        if (input != 2) {
            printf("ОШИБКА! Введены не числа! Попробуйте снова.\n>>>> ");
            clean();
            continue;
        }
        if (str > 10 || col > 10 || str<=0 || col<=0) {
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
    printf("\n\n-----------------------------------------------------------------------\nРезультат:\n");
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++)
            if (mass[i][j] == 0) {
                printf("строка %d имеет нулевой элемент\n", i + 1);
                break;
            }
    }
    printf("-----------------------------------------------------------------------\n");
}

void program2() {
    printf("\n-----------------------------------------------------------------------\n");
    printf("этот код определяет максимальное количество введенных подряд пробелов\n");
    printf("-----------------------------------------------------------------------\n");
    char text[1000];
    int maxspace = 1, space = 1;
    printf("напишите текст(для конца ввода поставьте @ и нажмите ENTER)\n>>>>");
    for (int i = 0; i < 999; i++) {
        scanf("%c", &text[i]);
        if (text[i] == '@')
            break;
        if (text[i] == ' ' && text[i - 1] == ' ') {
            space++;
            if (space > maxspace)
                maxspace = space;
        }
        else space = 1;
    }
    printf("-----------------------------------------------------------------------\nРезультат:\n");
    if (strchr(text, ' ') != NULL)
        printf("максимальное число подряд стоящих пробелов: %d", maxspace);
    else
        printf("пробелов в этом тексте нет");
    printf("\n-----------------------------------------------------------------------\n");

}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (1) {
        printf("\n\n=========================================\n");
        printf("           МЕНЮ ВЫБОРА ПРОГРАММ\n");
        printf("=========================================\n");
        printf("1. Первая программа\n");
        printf("2. Вторая программа\n");
        printf("0. Выход\n");
        printf("=========================================\n");
        printf("Выберите программу: ");

        if (scanf("%d", &choice) != 1) {
            printf("ОШИБКА! Введите число!\n");
            clean();
            continue;
        }

        switch (choice) {
        case 1:
            program1();
            break;
        case 2:
            program2();
            break;
        case 0:
            printf("Выход из программы...\n");
            return 0;
        default:
            printf("ОШИБКА! Выберите 1, 2 или 0 для выхода!\n");
            break;
        }
        clean();
    }

    return 0;
}
