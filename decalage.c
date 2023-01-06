#include "head.h"

void decalage(int matrix[49][3][3])
{

    int choix;
    int stocks[7][3][3];
    printf("\n choisissez le cote a decaller\n");
    scanf("%d",&choix);

    if(choix == 1) {
        int z = -6;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                }
            }
        }
        z = -6;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    matrix[z + 7][j][k] = stocks[i][j][k];
                }
            }
        }
    }

    if(choix == 2) {
        int z = -3;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                }
            }
        }
        z = -6;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    matrix[z + 7][j][k] = stocks[i][j][k];
                }
            }
        }
    }

    if(choix == 3) {
        int z = -1;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                }
            }
        }
        z = -6;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    matrix[z + 7][j][k] = stocks[i][j][k];
                }
            }
        }
    }

    printf("\n         %c           %c           %c\n  ",0x19,0x19,0x19);
    int d = 0;
    for (int a = 0; a <7 ; a++) {
        for (int l = 0; l < 3; l++) {
            for (int i = d; i < d+7; i++) {
                for (int c = 0; c < 3; c++) {
                    if(matrix[i][l][c] == 0)
                    {
                        printf("%c", 0xDB);
                    }
                    else
                        printf("%c",' ');
                    if (i == 6+d && c == 2) {
                        if(l == 0 &&(a == 1 || a == 3 || a == 5))
                            printf("\n%c ",0x1A);
                            //if(l == 1 &&(a == 1 || a == 3 || a == 5))
                            //printf("%c\n ",0x1B);
                        else
                            printf("\n  ");
                        if(l==2){
                            printf("\n  ");
                        }
                    }
                }
                if (i != 6+d) {
                    printf("   ");
                }
            }
        }
        d=d+7;
    }
    printf("       %c           %c           %c  ",0x18,0x18,0x18);

}