#include "head.h"

int menu()
{
    int rep_menu;

    //Menu avec les différentes options
    printf("* 1. Nouvelle partie\n");
    printf("* 2. Sauvegarde\n");
    printf("* 3. Charger une partie\n");
    printf("* 4. Afficher les regles / credits\n");
    printf("* 5. Quitter\n");
    printf("Que voulez-vous faire ? (Repondez par 1, 2, 3, 4 ou 5) :\n");
    scanf("%i", &rep_menu);

    //Petit blindage des valeurs de l'utilisateur
    if(rep_menu != 1 && rep_menu != 2 && rep_menu != 3 && rep_menu != 4 && rep_menu != 5)
    {
        do {
            printf("Veuillez reesayer S.V.P (Repondez par 1, 2, 3, 4 ou 5) :\n");
            scanf("%i", &rep_menu);
        } while (rep_menu != 1 && rep_menu != 2 && rep_menu != 3 && rep_menu != 4 && rep_menu != 5);
    }

    //Les choix
    if (rep_menu == 5) //Quitter
    {
        printf("Vous avez quitte le jeu.");
        return 0;
    }
    else
        return rep_menu;
}

void conditions(int choix)
{
    int sauvegarde = 0;
    char Oui_ou_Non[4];
    char r_ou_c;
    int partie_debut = 0;

    if(choix == 1)
    {
        if(sauvegarde == 1) //-> Blindage pour savoir si, oui ou non, l'utilisateur avait déjà une partie en cours
        {
            printf("Etes-vous sur de vouloir ecraser l'ancienne sauvegarde (y ou n) ?\n");
            scanf("%3s", Oui_ou_Non);

            if(Oui_ou_Non[0] == 'y')
            {
                printf("Demarrage d'une nouvelle partie...\n");
                partie_debut = 1; //Ca va servir pour blinder la sauvegarde (ligne 68)
                //Sous-programme Nouvelle partie (Alternative #1)
            }
            else
            {
                choix = menu();
                conditions(choix);
            }
        }
        printf("Demarrage d'une nouvelle partie...\n");
        partie_debut = 1; //Ca va servir pour blinder la sauvegarde (ligne 68)
        //Sous-programme Nouvelle partie (Alternative #2)
        if(sauvegarde == 0 )
        {
            zebi();
        }
    }

    if(choix == 2)
    {
        if(partie_debut == 0)
        {
            printf("Vous n'avez encore aucune partie en cours.\n"
                   "Retour au menu...\n");
            choix = menu();
            conditions(choix);
        }

        else
        {
            printf("Sauvegarde de la partie en cours...");
            //Sous programme Sauvegarde
        }
    }

    if(choix == 3)
    {
        if(sauvegarde == 0)
        {
            printf("Vous n'avez pas d'anciennes parties a votre actif");
            choix = menu();
            conditions(choix);
        }
        else
        {
            printf("Chargement de l'ancienne partie...");
            //Sous-programme chargement
        }

    }

    if(choix == 4)
    {
        printf("Voulez-vous les regles ou les credits (r ou c) ?\n");
        scanf("%c", &r_ou_c);
        if (r_ou_c == 'r')
        {
            //Sous-programme regles
        }
        if (r_ou_c == 'c')
        {
            //Sous-programme credits
        }
        else
        {
            do {
                printf("Veuillez reesayer S.V.P (Repondez par r pour regles ou c pour credits) :\n");
                scanf("%c", &r_ou_c);
            } while (r_ou_c != 'c' && r_ou_c != 'r');
        }
    }
}

void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
