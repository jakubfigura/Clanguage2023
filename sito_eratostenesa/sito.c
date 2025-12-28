#include <stdio.h>
#define MAX 1000
int main(){
    int numbers[MAX];
    int n;
    int d = 2;
    int i = 1;
    printf("Enter the number\n");
    scanf("%d", &n);
    if(n > 1000){
        printf("ERROR!\n");
    }
    else {
        if (n == 1) {
            printf("The number is not prime\n");
        }
        else {
            for (i = 2; i <= n; ++i) {
                numbers[i] = i;
            }
            while (d <= n) {
                    for (i = d; (i * d) <= n; ++i) {
                        numbers[i * d] = 0;
                    }
                    do{
                        d = d + 1;
                    }while(numbers[d]==0);
                }

            }
            printf("The following numbers are primes:\n");
            for (i = 2; i <= n; ++i) {
                if (numbers[i] != 0)
                    printf("%d ", numbers[i]);

            }
            printf("\n");
        }
    }