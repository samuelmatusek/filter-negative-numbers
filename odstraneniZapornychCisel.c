#include <stdio.h>
#include <stdlib.h>

int odfiltruj_zaporna(int **pole, int *delka){

    if (pole == NULL || *delka <= 0 || delka == NULL)
        return 0;

    int delkaTemp = 0;
    
    for (int i = 0; i < *delka; i++){
        if ((*pole)[i] < 0)
            delkaTemp++;
        else 
            (*pole)[i - delkaTemp] = (*pole)[i];
    }

    *delka = *delka - delkaTemp;
    if (*delka <= 0)
        return 0;

    int *temp = realloc(*pole, *delka * sizeof(**pole));
    if (temp == NULL)
        return 0;
    *pole = temp;
    temp = NULL;

    return 1;
}

int main(void){

    int delka, *pole;

    printf("Zadejte pocet prvku:\n");
    if (scanf("%d", &delka) != 1 || delka <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }

    pole = malloc(delka * sizeof(*pole));
    if (pole == NULL){
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Zadejte prvky pole:\n");
    for (int i = 0; i < delka; i++){
        if (scanf("%d", &pole[i]) != 1){
            printf("Nespravny vstup.\n");
            free(pole);
            return 1;
        }
    }

    if (odfiltruj_zaporna(&pole, &delka)){
        printf("Filtrovane pole:\n");
        for (int i = 0; i < delka; i++){
            if (i < delka - 1)
                printf("%d ", pole[i]);
            else
                printf("%d\n", pole[i]);
        }
        free(pole);
    }
    else {
        printf("Nespravny vstup.\n");
        free(pole);
        return 1;
    }

    return 0;
}