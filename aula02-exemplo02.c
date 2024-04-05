#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ERRO 1

int main(){

    system("cls");
    int matriz [3][3] = {
        {1, 4, 3},
        {2, 1, 2},
        {0, 5, 6},
    };

    int Det = 0;

    Det = Det + matriz[0][0] * matriz[1][1] * matriz[2][2];
    Det = Det + matriz[0][1] * matriz[1][2] * matriz[2][0];
    Det = Det + matriz[0][2] * matriz[1][0] * matriz[2][1];
    Det = Det - matriz[2][0] * matriz[1][1] * matriz[0][2];
    Det = Det - matriz[2][1] * matriz[1][2] * matriz[0][0];
    Det = Det - matriz[2][2] * matriz[1][0] * matriz[0][1];

    printf("%d\n", Det);

    return 0;
}

