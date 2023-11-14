#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 5000

#include <stdbool.h>

int x_timeline[MAX] = {0};

int main(int argc, char *argv[]) {


    //------------------[Check for correct usage]------------------//
    if (argc != 2) {
        printf("Usage: ./day2 <input file>\n");
        exit(1);
    }

    //------------------[Open input file]------------------//
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char ligne[50];

    char **tokens = (char **)malloc(sizeof(char *) * 10);
        if (tokens == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    int nb_cycles = 1;
    x_timeline[0] = 1;
    int x = 1;

    //------------------[Read input file]------------------//
    while (fgets(ligne, 50, fptr)) {

        ligne[strcspn(ligne, "\n")] = '\0';

        char *token = strtok(ligne, " ");
        int t = 0;

        while (token != NULL) {
            // Allouer de l'espace pour chaque token et le copier
            tokens[t] = (char *)malloc(strlen(token) + 1);

            // Vérifier si l'allocation a réussi
            if (tokens[t] == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire.\n");
                exit(EXIT_FAILURE);
            }

            // Copier le token dans le tableau
            strcpy(tokens[t], token);

            // Afficher le token
            printf("Token: %s\n", tokens[t]);

            // Incrémenter le compteur de tokens
            t++;

            token = strtok(NULL, " ");
        }

        if (strcmp(tokens[0], "noop") == 0) {
            x_timeline[nb_cycles] = x;
        } else {
            x += atoi(tokens[1]);
        }

        nb_cycles++;

    }


}