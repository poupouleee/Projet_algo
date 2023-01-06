#include "head.h"

int menu()
{
    int rep_menu;
    color(couleur_blanche, 0);
    //Menu avec les différentes options
    printf("* 1. Nouvelle partie\n");
    printf("* 2. Sauvegarde\n");
    printf("* 3. Charger une partie\n");
    printf("* 4. Afficher les regles / credits\n");
    printf("* 5. Quitter le jeu\n");
    printf("Que voulez-vous faire ? (Repondez par 1, 2, 3, 4 ou 5) :\n");
    scanf("%i", &rep_menu);

    //Blindage des valeurs de l'utilisateur
    if(rep_menu != 1 && rep_menu != 2 && rep_menu != 3 && rep_menu != 4 && rep_menu != 5)
    {
        do {
            fflush(stdin);
            printf("Veuillez reesayer S.V.P (Repondez par 1, 2, 3, 4 ou 5) :\n");
            scanf(" %i", &rep_menu);
        } while (rep_menu != 1 && rep_menu != 2 && rep_menu != 3 && rep_menu != 4 && rep_menu != 5);
    }

    //Les choix
    if (rep_menu == 5) //Quitter le jeu
    {
        printf("Vous avez quitt%c le jeu du labyrinthe.", 130);
        return 0;
    }
    else
        return rep_menu;
}

void conditions(int choix,int *nmbre_joueurs)
{
    int sauvegarde = 0;
    char Oui_ou_Non[4];
    char r_ou_c;
    int partie_debut = 0;


    color(couleur_blanche, 0);

    if(choix == 1)
    {
        if(sauvegarde == 1) //-> Blindage pour savoir si, oui ou non, l'utilisateur avait déjà une partie en cours
        {
            printf("Etes-vous sur de vouloir eraser l'ancienne sauvegarde (y ou n) ?\n");
            scanf("%3s", Oui_ou_Non);

            if(Oui_ou_Non[0] == 'y')
            {
                printf("D%cmarrage d'une nouvelle partie...\n", 130);
                partie_debut = 1; //Ca va servir pour blinder la sauvegarde (ligne 70)
                system("cls"); //effacement de la console
               // nouvelle_partie(nmbre_joueurs); //Sous-programme Nouvelle partie (Alternative #1)

            }
            else
            {
                choix = menu();
                conditions(choix,nmbre_joueurs);
            }
        }
        printf("Demarrage d'une nouvelle partie...\n");
        partie_debut = 1; //Ca va servir pour blinder la sauvegarde (ligne 70)
        nouvelle_partie( nmbre_joueurs); //Sous-programme Nouvelle partie (Alternative #2)
    }

    if(choix == 2)
    {
        if(partie_debut == 0)
        {
            printf("Vous n'avez encore aucune partie en cours.\n"
                   "Retour au menu");
            Sleep(500); //attente de 1000 ms
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(500);
            system("cls"); //clear screen
            Sleep(500);
            choix = menu();
            conditions(choix,nmbre_joueurs);
        }

        else
        {
            printf("Sauvegarde de la partie en cours...");
            Sleep(100);
            system("cls"); //clear écran
            Sleep(100);
            //Sous programme Sauvegarde
        }
    }

    if(choix == 3)
    {
        if(sauvegarde == 0)
        {
            printf("Vous n'avez pas d'anciennes parties a votre actif\n");
            printf("Retour au menu");
            Sleep(500); //attente de 500 ms
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(500);
            system("cls"); //clear ecran
            Sleep(500);
            choix = menu();
            conditions(choix,nmbre_joueurs);
        }
        else
        {
            printf("Chargement de l'ancienne partie...");
            Sleep(500);
            system("cls"); //clear écran
            Sleep(500);
            //Sous-programme chargement
        }

    }

    if(choix == 4)
    {
        regles_et_credits();
    }
}

void color(int couleur_texte,int fond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+couleur_texte);
}

void nouvelle_partie(int *nmbre_joueurs) {

    int i;
    int num_pion[4];


    char nom_personnage[nombre_joueurs_max][le_prenom_devient_long];

    Sleep(500);
    system("cls"); //Clear screen
    Sleep(500);
    printf("Bonjour, et bienvenue dans notre labyrinthe\n"); //L'entrée en matière peut être retravaillé
    printf("Ce jeu se joue de 2 a 4 joueurs,");
    printf(" combien etes vous ?\n");
    scanf("%i", nmbre_joueurs);

    if (*nmbre_joueurs < nombre_joueurs_min || *nmbre_joueurs > nombre_joueurs_max) //Blindage nombre de joueurs, boucle infinie si input != nombre
    {
        do {
            fflush(stdin);
            printf("Veuillez reesayer S.V.P (minimum : 2 joueurs et maximum : 4 joueurs) :\n");
            scanf("%i", nmbre_joueurs);
        } while (*nmbre_joueurs < nombre_joueurs_min || *nmbre_joueurs > nombre_joueurs_max);
    }

    printf("Les pions disponibles sont les suivants :\n");

    color(9, 0); //pion bleu
    printf("1. Le chevalier\n");

    color(5, 0); //pion pourpre
    printf("2. Le mage\n");

    color(2, 0); //pion vert
    printf("3. L'elfe\n");

    color(14, 0); //pion jaune-fluo
    printf("4. Le nain\n");

    for (i = 0; i < *nmbre_joueurs; i++)
    {
        color(couleur_blanche, 0);
        printf("Joueur %i : Quel pion choisissez-vous (Repondez par le numero) ?\n", i+1);
        scanf("%i", &num_pion[i]); //Stockage dans un tableau, peut poser des problemes apres

        if (num_pion[i] != 1 && num_pion[i] != 2 && num_pion[i] != 3 && num_pion[i] != 4) //Blindage choisissage de pion
        {
            do {
                fflush(stdin);
                printf("Ce personnage n'existe pas, veuillez choisir entre les personnages 1, 2, 3 et 4 S.V.P...\n");
                scanf("%i", &num_pion[i]);
            } while (num_pion[i] != 1 && num_pion[i] != 2 && num_pion[i] != 3 && num_pion[i] != 4);
        }

        if (num_pion[i] == num_pion[i-1] || num_pion[i] == num_pion[i-2] || num_pion[i] == num_pion[i-3])
        {
            do
            {
                fflush(stdin);
                printf("Ce pion est deja pris malheureusement, veuillez en prendre un autre...\n");
                printf("Joueur %i : Quel pion choisissez-vous (Repondez par un numero pas encore pris par votre camarade) ?\n", i+1);
                scanf("%i", &num_pion[i]);
            } while (num_pion[i] == num_pion[i-1] || num_pion[i] == num_pion[i-2] ||num_pion[i] == num_pion[i-3]);
        }
        printf("Comment se nommera votre personnage ?\n"); //Definition du nom du personnage
        scanf("%s", &nom_personnage[i][le_prenom_devient_long]);
    }
    resume_pions(*nmbre_joueurs, num_pion, nom_personnage); //Sous-programme faisant apparaitre un resume des personnages
    color(couleur_blanche, 0);
    printf("Nous pouvons donc commencer a explorer ce labyrinthe remplie de mysteres, de creatures mais surtout de tresors...");
}

void regles_et_credits()
{
    system("cls");
    printf("Voila, ce sera ici.");
}

void resume_pions(int joueurs, int numero[4], char nom[nombre_joueurs_max][le_prenom_devient_long])
{
    int i;

    printf("Tres bien, vous avez choisi vos pions avec succes\n");                                                      //resume des pions
    printf("Donc, pour resumer, nous avons :\n");

    for (i = 0; i < joueurs; i++)
    {

        if (numero[i] == 1)
        {
            color(9, 0);
            printf("Joueur %i : %s le chevalier\n", i+1, nom[i+1]);
        }
        else if (numero[i] == 2)
        {
            color(5, 0);
            printf("Joueur %i : %s le mage\n", i+1, nom[i+1]);
        }
        else if (numero[i] == 3)
        {
            color(2, 0);
            printf("Joueur %i : %s l'elfe\n", i+1, nom[i+1]);
        }
        else
        {
            color(14, 0);
            printf("Joueur %i : %s le nain\n", i+1, nom[i+1]);
        }
    }
}