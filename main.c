
#include "head.h"


int main() {
    int matrix[49][3][3];
    int choix;
    int nbr_joueurs;
    int num_pion[3];
    choix = menu();
    conditions(choix,&nbr_joueurs);
    zebi(matrix,nbr_joueurs);
    decalage(matrix);
}