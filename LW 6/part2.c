
#include <stdio.h>

char* append(char str1[], char str2[]) {

    int i=0,j=0;

    while(str1[i] != '\0')
        i++;
    while(str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++; 
    }
}


int roman(int num, char romanstr[])
{
    int decimalRep[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char  romanRep[][3] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int i=0;
    
    romanstr[0] = '\0';
    while(num){
      	while(num / decimalRep[i]){    
             append(romanstr,romanRep[i]);
             num -= decimalRep[i];
        }
        i++;
    }
    return 1;
}

void main()
{
    char romanstr[255];
    int i,dec = 49;
    do{
        printf("Enter a number:");
        scanf("%d",&dec);
        if(roman(dec,romanstr))
        {
            printf("%d -> %s\n",dec,romanstr);
            for(i=0;romanstr[i] != '\0';i++)
                romanstr[i] = '\0';
        }
    }
    while(dec > 0);
}

