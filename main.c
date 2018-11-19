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
    int nLen = 0;

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
                nLen = strlen(cResultat);
                cResultat[nLen] = 'M';

            }
        }
        nNombre -= (nQuotient * 1000);
    }

    ///TESTS POUR LES CENTAINES

    //TEST POUR LES 900
    if (nNombre >= 900){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'C';
        cResultat[nLen+1] = 'M';
        nNombre -= (900);
    }

    //TEST POUR LES 500
    if (nNombre >= 500){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'D';
        nNombre -= (500);
    }

    //TEST POUR LES 400
    if (nNombre >= 400){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'C';
        cResultat[nLen+1] = 'D';
        nNombre -= (400);
    }

    //TEST POUR LES 100
    if (nNombre >= 100){
        nQuotient = nNombre / 100;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                nLen = strlen(cResultat);
                cResultat[nLen] = 'C';
            }
        }
        nNombre -= (nQuotient * 100);
    }

    ///TESTS POUR LES DIZAINES

    //TEST POUR LES 90
    if (nNombre >= 90){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'X';
        cResultat[nLen+1] = 'C';
        nNombre -= (90);
    }

    //TEST POUR LES 50
    if (nNombre >= 50){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'L';
        nNombre -= (50);
    }

    //TEST POUR LES 40
    if (nNombre >= 40){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'X';
        cResultat[nLen+1] = 'L';
        nNombre -= (40);
    }

    //TEST POUR LES 10
    if (nNombre >= 10){
        nQuotient = nNombre / 10;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                nLen = strlen(cResultat);
                cResultat[nLen] = 'X';
            }
        }
        nNombre -= (nQuotient * 10);
    }

    ///TESTS POUR LES UNITES

    //TEST POUR 9
    if (nNombre >= 9){
        nLen = strlen(cResultat);
        cResultat[nLen] = '1';
        cResultat[nLen+1] = 'X';
        nNombre -= (9);
    }

    //TEST POUR 5
    if (nNombre >= 5){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'V';
        nNombre -= (5);
    }

    //TEST POUR 4
    if (nNombre >= 4){
        nLen = strlen(cResultat);
        cResultat[nLen] = 'I';
        cResultat[nLen+1] = 'V';
        nNombre -= (4);
    }

    //TEST POUR LES 1
    if (nNombre >= 1){
        nQuotient = nNombre / 1;
        if (nQuotient > 0){
            for (nCpt = 1; nCpt <= nQuotient; nCpt++){
                nLen = strlen(cResultat);
                cResultat[nLen] = 'I';
            }
        }
        nNombre -= (nQuotient * 1);
    }

    printf("Le resultat est : %s\n",cResultat);
}

void RomainVersEntier()
{
    int nCpt = 0;
    int nLen = 0;
    int nResultat = 0;
    char cNombre[TAILLE] = "";

    printf("Entrez un chiffre en chiffres romains\n");
    scanf("%s",&cNombre);

    nLen = strlen(cNombre);
    for (nCpt = 0; nCpt <= nLen; nCpt++){
        //test pour les I
        if (cNombre[nLen - nCpt] == 'I'){
            if (nCpt < 0){
                nResultat += 1;
            }
            else{
                if ((cNombre[nLen - nCpt + 1] == 'V') || (cNombre[nLen - nCpt + 1] == 'X')){
                    nResultat -= 1;
                }
                else{
                    nResultat += 1;
                }
            }
        }

        //test pour les V
        if (cNombre[nLen - nCpt] == 'V'){
            nResultat += 5;
        }

        //test pour les X
        if (cNombre[nLen - nCpt] == 'X'){
            if (nCpt < 0){
                nResultat += 10;
            }
            else{
                if ((cNombre[nLen - nCpt + 1] == 'C') ||(cNombre[nLen - nCpt + 1] == 'L')){
                    nResultat += 10;
                }
                else{
                    nResultat -= 10;
                }
            }
        }

        //tets pour les L
        if (cNombre[nLen - nCpt] == 'L'){
            nResultat += 50;
        }

        //test pour les C
        if (cNombre[nLen - nCpt] == 'C'){
            if (nCpt < 0){
                nResultat += 100;
            }
            else{
                if ((cNombre[nLen - nCpt + 1] == 'D') ||(cNombre[nLen - nCpt + 1] == 'M')){
                    nResultat += 100;
                }
                else{
                    nResultat -= 100;
                }
            }
        }

        //tets pour les D
        if (cNombre[nLen - nCpt] == 'D'){
            nResultat += 500;
        }

        //tets pour les M
        if (cNombre[nLen - nCpt] == 'M'){
            nResultat += 1000;
        }


        printf("Le resultat est : %i\n",nResultat);


    }
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
        else if(nChoix == 2){
            RomainVersEntier();
        }
    } while (nChoix != 0);

    system("pause");

    return 0;
}
