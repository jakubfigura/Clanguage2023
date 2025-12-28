#include <stdio.h>
#include <string.h>
#define MAX 33

void reverseString(char number[]) {
    int length = strlen(number);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }
}

int conversion_dec_bin(unsigned dec, char *bin){
    unsigned remainder;
    int index = 0;
    if(dec == 0){
        strcpy(bin, "0");
        return 1;
    }else {
        while (dec > 0) {
            remainder = dec % 2;
            bin[index] = (char) (remainder + '0');
            index++;
            dec = dec / 2;
        }
        bin[index] = '\0';
        reverseString(bin);
        return index;
    }
}

int bit_conversion_dec_bin(unsigned dec, char *bin){
    int index = 0;
    if (dec == 0) {
        strcpy(bin, "0");
        return 1;
    }

    while (dec > 0) {
        char bit = (dec & 1) + '0';
        bin[index] = bit;
        index++;

        dec = dec >> 1;
    }
    bin[index] = '\0';
    reverseString(bin);
    return index;
}

int main(int argc, char *argv[]){
    unsigned decimal;
    int digits;
    char bin[MAX];
    if (argc < 2)
    {
        printf("Podaj pozostałe argumenty funkcji main! Po wyrażeniu '%s' wpisz metodę konwersji"
               " 'modulo lub 'bitowa'.\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "modulo") == 0)
    {
        scanf("%d", &decimal);
        digits = conversion_dec_bin(decimal, bin);
        printf("%s\n", bin);
    }

    if (strcmp(argv[1], "bitowa") == 0)
    {
        scanf("%d", &decimal);
        digits = bit_conversion_dec_bin(decimal, bin);
        printf("%s\n", bin);
    }
return 0;
}
