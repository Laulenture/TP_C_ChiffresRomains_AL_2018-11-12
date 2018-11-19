#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    i : int             :nVar
    f : float           :flVar
    d : double          :dblVar
    c : char            :cVar
    l : long int        :lnVar
    ll: long long int   :llnVar
    L : double long     :ldblVar
    h : short int       :srVar
    ui: unsigned int    :unVar
    uf: unsigned float  :unfVar
    s : *STRING*
*/

#define TAILLE 13
#define MAX 0
#define MIN 4000

void EntierVersRomain()
{
    int nNombre = 0, nQuotient = 0, nCpt = 0;
    char cResultat [TAILLE] = "";
    int len = 0;

    do{
        printf("Entrez un chiffre en entier entre %i et %i non inclus\n", MIN, MAX);
        scanf("%i",&nNombre);
        if ((nNombre > MIN) && (nNombre < MAX)){
            printf("Vous n'avez pas entre un nombre entre 0 et 4000 non inclus\n");
        }
    } while ((nNombre > MIN) && (nNombre < MAX));

    //TEST POUR LES MILLEIRS
    if (nNombre > 1000){
        nQuotient = nNombre / 1000;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                len = strlen(cResultat);
                cResultat[len] = 'M';

            }
        }
        nNombre -= (nQuotient * 1000);
    }

    ///TESTS POUR LES CENTAINES

    //TEST POUR LES 900
    if (nNombre >= 900){
        nQuotient = nNombre / 900;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'C';
            cResultat[len+1] = 'M';
        }
        nNombre -= (900);
    }

    //TEST POUR LES 500
    if (nNombre >= 500){
        nQuotient = nNombre / 500;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'D';
        }
        nNombre -= (500);
    }

    //TEST POUR LES 400
    if (nNombre >= 400){
        nQuotient = nNombre / 400;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'C';
            cResultat[len+1] = 'D';
        }
        nNombre -= (400);
    }

    //TEST POUR LES 100
    if (nNombre >= 100){
        nQuotient = nNombre / 100;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                len = strlen(cResultat);
                cResultat[len] = 'C';
            }
        }
        nNombre -= (nQuotient * 100);
    }

    ///TESTS POUR LES DIZAINES

    //TEST POUR LES 90
    if (nNombre >= 90){
        nQuotient = nNombre / 90;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'X';
            cResultat[len+1] = 'C';
        }
        nNombre -= (90);
    }

    //TEST POUR LES 50
    if (nNombre >= 50){
        nQuotient = nNombre / 50;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'L';
        }
        nNombre -= (50);
    }

    //TEST POUR LES 40
    if (nNombre >= 40){
        nQuotient = nNombre / 40;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'X';
            cResultat[len+1] = 'L';
        }
        nNombre -= (40);
    }

    //TEST POUR LES 10
    if (nNombre >= 10){
        nQuotient = nNombre / 10;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                len = strlen(cResultat);
                cResultat[len] = 'X';
            }
        }
        nNombre -= (nQuotient * 10);
    }

    ///TESTS POUR LES UNITES

    //TEST POUR 9
    if (nNombre >= 9){
        nQuotient = nNombre / 9;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = '1';
            cResultat[len+1] = 'X';
        }
        nNombre -= (9);
    }

    //TEST POUR 5
    if (nNombre >= 5){
        nQuotient = nNombre / 5;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'V';
        }
        nNombre -= (5);
    }

    //TEST POUR 4
    if (nNombre >= 4){
        nQuotient = nNombre / 4;
        if (nQuotient > 0){
            len = strlen(cResultat);
            cResultat[len] = 'I';
            cResultat[len+1] = 'V';
        }
        nNombre -= (4);
    }

    //TEST POUR LES 1
    if (nNombre >= 1){
        nQuotient = nNombre / 1;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                len = strlen(cResultat);
                cResultat[len] = 'I';
            }
        }
        nNombre -= (nQuotient * 1);
    }

    printf("%s\n",cResultat);
}

void RomainVersEntier()
{



}

int main()
{
    int nChoix;

    do{
        printf("Voulez vous convertir un nombre en chiffres romains, des chiffres romains en nombres ou quiter ?\n");
        printf("1 : nombre en chiffres romains\n");
        printf("2 : chiffres romains en nombres\n");
        printf("0 : QUITTER\n");
        scanf("%i",&nChoix);
        if (nChoix == 1){
            EntierVersRomain();
        }
        else{
            RomainVersEntier();
        }
    } while (nChoix != 0);

    system("pause");

    return 0;
}
