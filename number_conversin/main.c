#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 20
struct RZYM{
    int arab;
    char *rzym;
};
struct RZYM rz[]={{1,"I"}, {4, "IV"}, {5, "V"},
       {9, "IX"}, {10,"X"}, {40, "XL"},
       {50, "L"}, {90, "XC"}, {100, "C"},
       {400, "CD"}, {500, "D"}, {900, "CM"},
       {1000, "M"}};

void conversion_from_arabic_to_roman(int number) {
    int i = 12; //największy indeks w strukturze//
    int div;

    while (number > 0) {
        div = number / rz[i].arab;
        number = number % rz[i].arab;

        while (div > 0) {
            printf("%s", rz[i].rzym);
            div = div - 1;
        }

        i--;
    }
}

int conversion_from_roman_to_arabic(char *roman_number){
    int i=0;
    int j;
    int result = 0;
    while(i < strlen(roman_number)){
        for(j = 12; j >= 0; j--){
            if(strlen(rz[j].rzym) == 1){
                if(roman_number[i] == rz[j].rzym[0]){
                    result += rz[j].arab;
                    break;
                }
            }
            if(strlen(rz[j].rzym) == 2){
                if(roman_number[i] == rz[j].rzym[0] && roman_number[i + 1] == rz[j].rzym[1]){
                    result += rz[j].arab;
                    i++;
                    break;
                }

            }
        }
        i++;
    }
    return result;
}

int main() {
    char snumber[MAX];
    int result;
    int i;
    int j;
    int roman = 0;
    int arabic = 0;
    int temp = 0;
    scanf("%s", snumber);
    int length = strlen(snumber)-1;
    for(i = 0; snumber[i]!='\0'; i++){
        if(isalpha(snumber[i])!=0){
            roman++;
        }
    }
    if(roman == i){
        result = conversion_from_roman_to_arabic(snumber);
        printf("%d\n", result);
    }
    for(i = 0; snumber[i]!='\0'; i++){
        if(isdigit(snumber[i])!=0){
            arabic++;
        }
    }
    if(arabic == i && roman==0){
        for(j=0; snumber[j]!='\0'; j++){
            temp = temp + ((snumber[j] - '0') * pow(10, length));
            length = length - 1;
        }
        if (temp < 1 || temp > 3999) {
            printf("Please enter a snumber between 1 and 3999.\n");
            return 1;
        }
        else {
            conversion_from_arabic_to_roman(temp);
            printf("\n");
        }
    }
    if(arabic != i && roman != i){
        printf("The input has invalid syntax.\nPlease provide roman or arabic number\n");
    }
    if(result == 0){
        printf("The input has invalid syntax.\nPlease provide roman or arabic number\n");
    }
    return 0;
}