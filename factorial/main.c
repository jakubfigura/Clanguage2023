#include <stdio.h>
#include <string.h>
int factorial(int n){
    int factor = 1;
    int i;
    if(n == 0){
        printf("Factorial == 1");
    }
    else {
        for (i = 1; i <= n; i++) {
            factor = factor * i;
        }
    }
    return factor;
}

int recfactorial(int n){
    if(n <= 1)
        return 1;
    else
        return n * recfactorial(n-1);
}

int main(int narg, char *Arg[]) {
    int n;
    if (narg != 2) {
        printf("Podaj drugi argument funkcji main! Po wyrażeniu '%s' wpisz 'rekurencja' lub 'iteracja'\n", Arg[0]);
        return 1;
    }
    printf("Wprowadź liczbę dla której chcesz wyliczyć silnie:\n");
    scanf("%d", &n);

    if (strcmp(Arg[1], "rekurencja") == 0) {
        int result = recfactorial(n);
        printf("Silnia obliczona rekurencyjnie z %d wynosi: %d\n", n, result);
    } else if (strcmp(Arg[1], "iteracja") == 0) {
        int result = factorial(n);
        printf("Silnia obliczona iteracyjnie z %d wynosi: %d\n", n, result);
    } else {
        printf("Program nie zna takiej metody obliczania silni: %s\n", Arg[1]);
        return 1;
    }

    return 0;
}
/* aby skorzystać z opcji time należy skompliować pogram gcc -o factorial factorial.c, następnie zastosować komendę
 * time./factorial*/