
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG if (1)

#define n 100
int perm[n];

void print_perm(int i, int j) {
    printf("\nprint_perm (i = %d, j = %d):\n", i, j);
    for (int ii = 0; ii < n; ii++) {
        printf("%d. %d\n", ii, perm[ii]);
    }
}

int rand_seed(int xxx) {
    xxx++;
    srand(time(NULL) * (time(NULL)%13 + 1));
    return (rand() % (99999*xxx)) * (rand() % (33333*xxx));
}

int main() {

    double N = 7e6;
    DEBUG printf("\nN = %.*lf\nn = %d", 0, N, n);
    int powtorzenia = 30;
    double N1[powtorzenia], N2[powtorzenia];

    for (int xxx = 0; xxx < powtorzenia; xxx++) {

        for (int i = 0; i < n; i++) perm[i] = i;
        int k = n; /* liczba punktów stałych permutacji (dla ilu i perm[i] == i) */
        int pocz_perm;
        int counter = -1;

        unsigned int seed1 = rand_seed(xxx) * (xxx+1);
//        printf("\nseed1 = %u\n", seed1);
        srand(seed1);

        for (int i = 0; i < N; i++) {
            for (int _i = 0; _i<3; _i++) { /* dodalem taka petle, zauwazywszy, ze zwieksza ona dokladnosc zwracanych przyblizen */
                /* a) Losujemy całkowite j z przedziału 0, 1, . . . n−2 */
                int j = rand() % (n - 1);

                /* b) Zamieniamy elementy perm[j] oraz perm[j+1] */
                int tmp_perm = perm[j];
                perm[j] = perm[j + 1];
                perm[j + 1] = tmp_perm;

                /* c) Określamy nową liczbę punktów stałych wg przepisu: */
                k += (perm[j] == j) + (perm[j + 1] == j + 1) - (perm[j] == j + 1) - (perm[j + 1] == j);
            }
            if (counter == -1 && k == 0) {
                pocz_perm = i; /* numer iteracji, w ktorej nastapilo pierwsze k==0 */
                counter++;

            } else if (k == 0) {
                counter++;
            }
        }

        if (counter == -1) counter = 0;
        N1[xxx] = (N - pocz_perm) / counter;
        N2[xxx] = (N) / (counter + 1);
    }

    printf("\n\n final : \n");
    printf("\n         e = 2.718281828459\n");

    /* srednie arytmetyczne */
    double N1_srednia = 0, N2_srednia = 0;
    for (int i = 0; i < powtorzenia; i++) {
        N1_srednia += N1[i];
        N2_srednia += N2[i];
    }
    N1_srednia /= powtorzenia;
    N2_srednia /= powtorzenia;

    /* odchylenia standardowe */
    double N1_odchyl = 0, N2_odchyl = 0;
    for (int i = 0; i < powtorzenia; i++) {
        N1_odchyl += pow(N1[i]-N1_srednia, 2);
        N2_odchyl += pow(N2[i]-N2_srednia, 2);
    }
    N1_odchyl /= powtorzenia;
    N2_odchyl /= powtorzenia;
    N1_odchyl = sqrt(N1_odchyl);
    N2_odchyl = sqrt(N2_odchyl);

    /* wyniki */
//    printf("hmmm...    = %.*lf\n", 12, N1_srednia-N1_odchyl);
    printf("N1_srednia = %.*lf\n", 12, N1_srednia);
    printf("N1_odchyl  = %.*lf\n", 12, N1_odchyl);
//    printf("N2_srednia = %.*lf\n", 12, N2_srednia);
//    printf("N2_odchyl  = %.*lf\n", 12, N2_odchyl);
    printf("\n");
    return 0;
}