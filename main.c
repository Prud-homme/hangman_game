#define TAILLE_MAX 25
#define NB_COUP 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "motcache.h"

int main()
{
    char motDepart[TAILLE_MAX] = "" , motCache[TAILLE_MAX] = "", lettre="";
    int etatPL = 0, nombreCoup = NB_COUP, etatFin = 1;

    initMotSecret(motDepart);
    initMotCache(motDepart, motCache);



    while (nombreCoup > 0)
    {
        printf("Mot secret : %s\nNombre de coup restants : %d\n", motCache, nombreCoup);
        printf("\nEntrer une lettre : ");
        lettre = lireCaractere();

        etatPL = presenceLettre(motDepart, motCache, lettre);
        //etatPL : 0 si la lettre est trouvée ; 1 si la lettre n'est pas présente
        nombreCoup = coupRestant(nombreCoup, etatPL);



        etatFin = finPendu(motCache);
        if (etatFin == 0)//Gagne
        {
            printf("Vous avez trouve le mot secret : %s.\n", motCache);
            return 0;
        }
    }
    if (nombreCoup == 0)//Perdu
    {
        printf("\n--- Vous avez perdu. ---\n",motCache);
    }
    return 0;
}

/* With printf verification
int main()
{
    char motDepart[TAILLE_MAX] = "" , motCache[TAILLE_MAX] = "", lettre="";
    int etatPL = 0, nombreCoup = NB_COUP, etatFin = 1;

    initMotSecret(motDepart);
    initMotCache(motDepart, motCache);

    printf("--- Vérification ---\nMot a trouver : %s\nLettre trouvee : %s\nNombre de coup restants : %d\n--- Fin vérification ---\n",
           motDepart, motCache, nombreCoup);

    while (nombreCoup > 0)
    {
        printf("\nEntrer une lettre : ");
        lettre = lireCaractere();

        etatPL = presenceLettre(motDepart, motCache, lettre);
        //etatPL : 0 si la lettre est trouvée ; 1 si la lettre n'est pas présente
        nombreCoup = coupRestant(nombreCoup, etatPL);

        printf("\n--- Vérification ---\nLettre entree: %c\nLettre trouvee : %s\nNombre de coup restants : %d\n--- Fin vérification ---\n",
               lettre, motCache, nombreCoup);

        etatFin = finPendu(motCache);
        printf("\netatFin : %d\n", etatFin);
        if (etatFin == 0)//Gagne
        {
            printf("\n--- Vérification ---\nLettre trouvee: %s\n--- Fin vérification ---\n",motCache);
            return 0;
        }
    }
    if (nombreCoup == 0)//Perdu
    {
        printf("\n--- Vérification ---\nLettre trouvee: %s\n--- Fin vérification ---\n",motCache);
    }
    return 0;
}
*/
