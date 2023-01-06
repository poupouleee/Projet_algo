#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "head.h"




int remplir_les_cases(int i,  int l, int c ,int* random_p,int random_s,int* compte_T,int* compte_I,int* compte_L){

    // 4 CASES DU HAUTS
    if (i<7 && i%2 == 0){
        if(l==0){
            return 0;
        }
        if((c==0 || c==2) && l==2){
            return 0;
        }
        if(i==0 && l ==1 && c==0){
            return 0;
        }
        if(i==6 && l==1 && c==2){
            return 0;
        }
        else{
            return 1;
        }
    }
    // 4 CASES DU BAS
    if(i>41 && i%2 == 0){
        if(l==2){
            return 0;
        }
        if((c==0 || c==2) && l==0){
            return 0;
        }
        if(i==42 && l==1 && c==0){
            return 0;
        }
        if(i==48 && l==1 && c==2){
            return 0;
        }
        else{
            return 1;
        }
    }
    //3 CASES IDENTIQUES MILIEU GAUCHE
    if(i==14 || i==16 || i==28){
        if(c==0){
            return 0;
        }
        if(c==2 && (l==0 || l==2)){
            return 0;
        }
        else{
            return 1;
        }
    }
    //3 CASES IDENTIQUES MILIEU DROITE
    if(i==20 || i==34 || i==32){
        if(c==2){
            return 0;
        }
        if(c==0 && (l==0 || l==2)){
            return 0;
        }
        else{
            return 1;
        }

    }
    //CASE UNIQUE MILIEU DROITE
    if(i==18){
        if(l==0){
            return 0;
        }
        if(l==2 && (c==0 || c==2)){
            return 0;
        }
        else{
            return 1;
        }
    }
    //CASE UNIQUE MILIEU GAUCHE
    if(i==30){
        if(l==2){
            return 0;
        }
        if(l==0 && (c==0 || c==2)){
            return 0;
        }
        else{
            return 1;
        }
    }

    else{
        if(*random_p == 0 )
        {
            if(*compte_T >0)// sert a checker si il reste des pieces ( ne marche pas)
            {
                *compte_T=*compte_T-1;

                if(random_s%4 == 0){
                    if ((l == 0  && (c == 0 || c == 2)) || l == 2){  // pieces en T dans tt les sens
                        return 0;
                    }
                    else{
                        return 1;
                    }

                }
                if(random_s%4 == 1 ){
                    if ((c == 2 && (l == 0 || l == 2)) || c == 0){
                        return 0;
                    }
                    else{
                        return 1;
                    }


                }
                if(random_s%4 == 2){
                    if ((c == 0 && (l == 0 || l == 2)) || c == 2){
                        return 0;
                    }
                    else{
                        return 1;
                    }

                }
                if(random_s%4 == 3){
                    if ((l == 2 && (c == 0 || c == 2)) || l == 0){
                        return 0;
                    }
                    else{
                        return 1;
                    }
                }
            }
            else {
                *random_p=1 + rand()%2;
            }
        }
        if(*random_p == 1 )
        {
            if(*compte_I>0)
            {
                *compte_I=*compte_I-1;
                // pieces en I
                if(random_s%2 == 0){
                    if (l== 0 || l == 2)
                        return 0;
                    else
                        return 1;
                }
                if(random_s%2 == 1){
                    if (c == 0 || c == 2)
                        return 0;
                    else
                        return 1;
                }
            }
            else {
                do{ *random_p=rand()%3; }
                while(*random_p==1);

                if( *random_p==0 && c==0 && l==0){
                    return 0;
                }
            }

        }
        if(*random_p == 2 )
        {
            if(*compte_L>0)
            {
                *compte_L=*compte_L-1;
                if(random_s%4 == 0){
                    if (c == 0 || (c == 2 && l == 2)  ||  l ==0){  // piece ne L
                        return 0;
                    }
                    else
                        return 1;
                }
                if(random_s%4 == 1){
                    if (c == 2 || (c == 0 && l == 2)  ||  l ==0){
                        return 0;
                    }
                    else
                        return 1;
                }
                if(random_s%4 == 2){
                    if (c == 2 || (c == 0 && l == 0)  ||  l ==2){
                        return 0;
                    }
                    else
                        return 1;
                }
                if(random_s%4 == 3){
                    if (c == 0 || (c == 2 && l == 0)  ||  l ==2){
                        return 0;
                    }
                    else
                        return 1;
                }
            }
            else{
                *random_p=rand()%2;
                if(l==0 && c==0) {
                    return 0;
                }
            }

        }

    }
}

void afficher_la_derniere_piece(int *compte_T,int *compte_I,int *compte_L) {
    int matrixe[3][3];
    printf("Votre piece restante est :\n");


    if (*compte_T > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {

                if ((l == 0 && (c == 0 || c == 2)) || l == 2) {  // pieces en T dans tt les sens
                    matrixe[l][c] = 0;
                } else {
                    matrixe[l][c] = 1;
                }
            }
        }
    }
    if (*compte_I > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (l == 0 || l == 2) {
                    matrixe[l][c] = 0;
                } else {
                    matrixe[l][c] = 1;
                }

            }
        }
    }
    if (*compte_L > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (c == 0 || (c == 2 && l == 2) || l == 0) {  // piece ne L
                    matrixe[l][c] = 0;
                } else {
                    matrixe[l][c] = 1;
                }
            }

        }
    }
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            if(matrixe[l][c] == 0)
            {
                printf("%c", 0xDB);
            }
            else
                printf("%c",' ');
        }
printf("\n");

    }
}


void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void zebi(int matrix[49][3][3],int nbr_joueurs) {
    int random_p;
    int random_s;
    int compte_T=6*9;
    int compte_L=16*9;
    int compte_I=12*9;

    int positionnement_joueur;
    int joueur1;
    int joueur2;
    int joueur3;



    int d=0;
    srand(time(NULL));
    //REMPLIR LE PLATEAU DE DEPART
    for (int i = 0; i < 49; i++) {

        random_p = rand()%3;
        random_s = rand()%4;
        for (int l = 0; l < 3 ; l++) {
            for (int c = 0; c < 3; c++) {
                matrix[i][l][c] = remplir_les_cases(i,l,c,&random_p,random_s,&compte_T,&compte_I,&compte_L); //call remplir les cases
            }
        }
    }

    if(nbr_joueurs==2){
        matrix[0][1][1]=2;
        matrix[48][1][1]=2;
    }
    if(nbr_joueurs==3){
        matrix[0][1][1]=3;
        matrix[48][1][1]=3;
        matrix[6][1][1]=3;
    }
    if(nbr_joueurs==4){
        matrix[0][1][1]=4;
        matrix[48][1][1]=4;
        matrix[6][1][1]=4;
        matrix[42][1][1]=4;
    }


// AFFICHER LE PLATEAU DE DEPART
    printf("\n         %c           %c           %c\n  ",0x19,0x19,0x19);
    for (int a = 0; a <7 ; a++) {
        for (int l = 0; l < 3; l++) {
            for (int i = d; i < d+7; i++) {
                for (int c = 0; c < 3; c++) {


                    if (matrix[i][l][c] == 2) {
                        if(i==0){
                        Color(9, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);}
                        else{
                            Color(5, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);
                        }
                    }


                    if (matrix[i][l][c] == 3) {
                        if(i==0){
                            Color(9, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);}
                        else if(i==48){
                            Color(5, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);
                        }
                        else{
                            Color(2, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);
                        }
                    }
                    if (matrix[i][l][c] == 4) {
                        if(i==0){
                            Color(9, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);}
                        else if(i==48){
                            Color(5, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);
                        }
                        else if(i==6){
                            Color(2, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);
                        }
                        else{
                            Color(14, 0);
                            printf("%c", 0xDB);
                            color(couleur_blanche, 0);
                        }
                    }




                    if (matrix[i][l][c] == 0) {
                        printf("%c", 0xDB);
                    } else if(matrix[i][l][c] == 1){
                        printf("%c", ' ');}
                    if (i == 6 + d && c == 2) {
                        if (l == 0 && (a == 1 || a == 3 || a == 5))
                            printf("\n%c ", 0x1A);
                            //if(l == 1 &&(a == 1 || a == 3 || a == 5))
                            //printf("%c\n ",0x1B);
                        else
                            printf("\n  ");
                        if (l == 2) {
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
    afficher_la_derniere_piece(&compte_T,&compte_I,&compte_L);
    //printf("       %c           %c           %c  ",0x18,0x18,0x18);

}



