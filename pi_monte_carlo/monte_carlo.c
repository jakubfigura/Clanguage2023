#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RMAX 65535
long double random_number_generator(int r){
    return ((75 * (r + 1)) % 65537) - 1;
}
int main(){
    int random;
    long double x; /* współrzędna x */
    long double y; /* współrzędna y */
    long double pi;
    int n = 0; /* liczba prób */
    int k = 0;  /* liczba trafien*/
    int m; /* liczba iteracji*/
    int i;
    int j;
    scanf("%d", &m);
    scanf("%d", &random);
        for (i = 0; i < m; i++) {
            random = random_number_generator(random_number_generator(random));
            x = (long double) random / (RMAX + 1);
            random = random_number_generator(random_number_generator(random));
            y = (long double) random / (RMAX + 1);
            if ((pow(x, 2) + pow(y, 2)) < 1) {
                k++;
            }
            n++;
        }
        pi = ((long double) k / (long double) n) * 4;
        printf("%LG\n", pi);
    return 0;
}