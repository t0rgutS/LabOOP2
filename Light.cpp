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

void TrLight::flash() {
    if (curr == flashyel) {
        curr = yellow;
        printf("Режим светофора успешно переключен на работу в штатном режиме.\n");
    } else {
        curr = flashyel;
        printf("Режим светофора успешно переключен на: Мигающий желтый.\n");
    }
}

void TrLight::changeColor(char key) {
    int t;
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
            if (curr == green || curr == red) {
                printf("Через 30 секунд светофор переключит цвет автоматически."
                               "Чтобы перейти к ручному управлению раньше - введите любой символ.\n");
                t = 30;
                while (!kbhit() && t > 0) {
                    printf("%d\n", t);
                    t--;
                    Sleep(1000);
                }
                if (t == 0)
                    curr = yellow;
                else
                    while (getchar() != '\n');
            }
        }
    } else
        printf("Невозможно переключить цвет!\nСветофор работает в режиме Мигающий желтый!\n");
}

void TrLight::work() {
    char k;
    do {
        printf("Введите:\n\t'w' - переключатель вверх;\n\t's' - переключатель вниз;"
                       "\n\t'r' - переключатель режима работы;\n\t'e' - выход.\nТекущий цвет: ");
        curColor();
        k = getchar();
        fflush(stdin);
        k = tolower(k);
        if (k == 'w' || k == 's') {
            changeColor(k);
        } else if (k == 'r')
            flash();
        else if (k != 'e') {
            printf("ОШИБКА! Введен неверный символ. Пожалуйста, повторите ввод.\n");
        }
    } while (k != 'e');
}
