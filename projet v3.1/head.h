//
// Created by charv on 21/12/2022.
//

#ifndef TEST3_HEAD_H
#define TEST3_HEAD_H
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <stdbool.h>

int menu();
void color(int t,int f);
void Credits_Regles();
void conditions(int choix,int [49][3][3]);
int zebi(int matrix[49][3][3]);
int remplir_les_cases(int i,  int l, int c,int random_p,int random_s);
void piece();
void decalage(int matrix[49][3][3]);

#endif //TEST3_HEAD_H
