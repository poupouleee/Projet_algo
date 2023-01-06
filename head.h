#ifndef TEST3_HEAD_H
#define TEST3_HEAD_H
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <stdbool.h>

#define le_prenom_devient_long 100
#define nombre_joueurs_max 4
#define nombre_joueurs_min 2
#define couleur_blanche 15




void nouvelle_partie(int *nmbre_joueurs);
void regles_et_credits();
void conditions(int choix,int *nmbre_joueurs);
int menu();
void color(int t,int f);
void resume_pions(int joueurs, int numero[3], char nom[nombre_joueurs_max][le_prenom_devient_long]);
void zebi(int matrix[49][3][3],int nbr_joueurs);
void decalage(int matrix[49][3][3]);
void Color(int couleurDuTexte,int couleurDeFond);
#endif //TEST3_HEAD_H