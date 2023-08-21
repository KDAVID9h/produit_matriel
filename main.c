#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main() {
    setlocale(LC_ALL, "");

    int LIGNES_A, COLONNES_A, LIGNES_B, COLONNES_B;

    do {
        printf("Donnez les dimensions de la matrice A (Lignes Colonnes) : ");
        if (scanf("%d %d", &LIGNES_A, &COLONNES_A) != 2) {
            printf("Erreur de saisie.\n");
            while (getchar() != '\n'); // Vider le tampon d'entr�e
            continue;
        }

        printf("Donnez les dimensions de la matrice B (Lignes Colonnes) : ");
        if (scanf("%d %d", &LIGNES_B, &COLONNES_B) != 2) {
            printf("Erreur de saisie.\n");
            while (getchar() != '\n'); // Vider le tampon d'entr�e
            continue;
        }

        if (COLONNES_A != LIGNES_B) {
            printf("Multiplication impossible : le nombre de colonnes de la matrice A doit �tre �gal au nombre de lignes de la matrice B.\n");
            continue;
        }

        int A[LIGNES_A][COLONNES_A];
        int B[LIGNES_B][COLONNES_B];
        int C[LIGNES_A][COLONNES_B];
        int i, j, k;

        // Lecture de la matrice A
        printf("Saisie de la matrice A :\n");
        for (i = 0; i < LIGNES_A; i++) {
            for (j = 0; j < COLONNES_A; j++) {
                printf("A[%d][%d] = ", i, j);
                if (scanf("%d", &A[i][j]) != 1) {
                    printf("Erreur de saisie.\n");
                    while (getchar() != '\n'); // Vider le tampon d'entr�e
                    j--;
                }
            }
        }

        // Lecture de la matrice B
        printf("Saisie de la matrice B :\n");
        for (i = 0; i < LIGNES_B; i++) {
            for (j = 0; j < COLONNES_B; j++) {
                printf("B[%d][%d] = ", i, j);
                if (scanf("%d", &B[i][j]) != 1) {
                    printf("Erreur de saisie.\n");
                    while (getchar() != '\n'); // Vider le tampon d'entr�e
                    j--;
                }
            }
        }

        // Calcul du produit des matrices
        for (i = 0; i < LIGNES_A; i++) {
            for (j = 0; j < COLONNES_B; j++) {
                C[i][j] = 0;
                for (k = 0; k < COLONNES_A; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // Affichage de la matrice r�sultat
        printf("Matrice r�sultat :\n");
        for (i = 0; i < LIGNES_A; i++) {
            for (j = 0; j < COLONNES_B; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }

        char choix;
        printf("Voulez-vous refaire le calcul ? (O/N) : ");
        do {
            choix = getchar();
        } while (choix != 'O' && choix != 'o' && choix != 'N' && choix != 'n');

        if (choix != 'O' && choix != 'o') {
            break;
        }
    } while (true);

    return 0;
}
