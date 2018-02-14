#include <iostream>
#include "Light.h"
#include <conio.h>
#include <Windows.h>

TrLight::TrLight() {
    curr = flashyel;
}

void TrLight::curColor() {
    switch (curr) {
        case green:
            printf("Зеленый.\n");
            break;;
        case yellow:
            printf("Желтый.\n");
            break;;
        case red:
            printf("Красный.\n");
            break;;
        case flashyel:
            printf("Мигающий желтый.\n");
            break;;
    }
}

void TrLight::automat() {
    int t;
    bool b;
    if (curr != flashyel) {
        printf("Включен режим автоматической работы. Для перехода к ручному управлению введите любой символ.\n");
        while (!kbhit()) {
            if (curr == green || curr == red) {
                curr == green ? b = true : b = false;
                t = 30;
                while (!kbhit() && t > 0) {
                    printf("%d\n", t);
                    t--;
                    Sleep(1000);
                }
                if (t == 0) {
                    curr = yellow;
                    printf("Цвет переключен на Желтый.\n");
                }
            } else {
                t = 5;
                while (!kbhit() && t > 0) {
                    printf("%d\n", t);
                    t--;
                    Sleep(1000);
                }
                if (t == 0) {
                    b == true ? curr = red : curr = green;
                    printf("Цвет переключен на ");
                    curColor();
                }
            }
        }
        while (getchar() != '\n');
    } else
        printf("Автоматический режим недоступен!\nСветофор работает в режиме Мигающий желтый!\n");
}

void TrLight::changeColor(char key) {
    int t;
    if (key != 'r') {
        if (curr != flashyel) {
            if ((curr == green && key == 's') || (curr == red && key == 'w'))
                printf("Ошибка! Невозможно переключить цвет!\n");
            else {
                if (curr == green || curr == red)
                    curr = yellow;
                else if (curr == yellow)
                    key == 'w' ? curr = red : curr = green;
                printf("Цвет успешно переключен на ");
                curColor();
            }
        } else
            printf("Невозможно переключить цвет!\nСветофор работает в режиме Мигающий желтый!\n");
    } else if (curr == flashyel) {
        curr = yellow;
        printf("Режим светофора успешно переключен на работу в штатном режиме.\n");
    } else {
        curr = flashyel;
        printf("Режим работы светофора успешно переключен на Мигающий желтый.\n");
    }

}

void TrLight::work() {
    char k;
    do {
        printf("Введите:\n\t'w' - переключатель вверх;\n\t's' - переключатель вниз;"
                       "\n\t'r' - переключатель режима работы со стандартного на 'мигающий желтый';\n\t"
                       "'a' - режим автоматической работы;\n\t'e' - выход.\nТекущий цвет: ");
        curColor();
        k = getchar();
        fflush(stdin);
        k = tolower(k);
        if (k == 'w' || k == 's' || k == 'r') {
            changeColor(k);
        } else if (k == 'a')
            automat();
        else if (k != 'e') {
            printf("ОШИБКА! Введен неверный символ. Пожалуйста, повторите ввод.\n");
        }
    } while (k != 'e');
}
