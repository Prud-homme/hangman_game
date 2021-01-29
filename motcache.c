#define TAILLE_MAX 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initMotSecret(char motDepart[])
{
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    FILE* fichier = NULL;
    int caractereActuel = 0, nbMots = 0, motNumero = 0, nbSaut = 0;
    char chaine[TAILLE_MAX] = "";
    fichier = fopen("motsecret.txt", "r");

    if (fichier == NULL)
    {
        return 1;
    }

    do
    {
        caractereActuel = fgetc(fichier); // On lit le caractère
        if (caractereActuel == '\n')
        {
            nbMots++;
        }
    } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

    motNumero = rand() % nbMots;
    rewind(fichier);

    while (nbSaut < motNumero)
    {
        caractereActuel = fgetc(fichier); // On lit le caractère
        if (caractereActuel == '\n')
        {
            nbSaut++;
        }
    }
    fgets(motDepart, TAILLE_MAX, fichier) ;
    motDepart[strlen(motDepart)-1] = '\0';
    fclose(fichier);

    return 0;
}

int initMotCache(char motDepart[], char motCache[])
{
    int tailleMotDepart = strlen(motDepart), i = 0;
    for (i = 0 ; i < tailleMotDepart ; i++)
    {
        motCache[i] = '*';
    }
    motCache[tailleMotDepart] = '\0';
    return 0;
}

int presenceLettre(char motDepart[], char motCache[], char lettre)
{
    int tailleMot = strlen(motDepart), tailleSuiteChaine = 0, placeLettre = 0;
    char *suiteChaine = NULL;
    suiteChaine = strchr(motDepart, lettre);
    if (suiteChaine == NULL)
    {
        return 1;
    }
    while (suiteChaine != NULL)// Si la lettre est présente on récupère la suite du mot commencant à la lettre trouvée
    {
        tailleSuiteChaine = strlen(suiteChaine);
        placeLettre = tailleMot - tailleSuiteChaine;
        motCache[placeLettre] = lettre;
        suiteChaine = &(suiteChaine[1]);
        suiteChaine = strchr(suiteChaine, lettre);
    }
    return 0;
}

int coupRestant(int nombreCoupRestant, int etatCoupActuel)
// etatCoupActuel valeur renvoyer par presenceLettre : 0 si une lettre est présente ; 1 si la lettre n'est pas présente
{
    nombreCoupRestant -= etatCoupActuel;
    return nombreCoupRestant;
}

int finPendu(char motCache[])
{
    char *suiteChaine = NULL;
    suiteChaine = strchr(motCache, '*');
    if (suiteChaine != NULL)
    {
        return 1;
    }
    return 0;
}
