#include <stdio.h>

void lower(char str[]){
	int i;
	for(i=0;str[i] != '\0';i++)
		if('A'< str[i] && str[i] < 'Z')
			str[i] += 'a' - 'A';
}


int findlenght(char str[]){
	int i;
	for(i=0;str[i] != '\0';i++);
	return i;
}



int count(char haystack[],char needle[]){
	int occur = 0,len,i,j,k;
	len = findlenght(needle);
	lower(haystack);
	
	for(j=0;haystack[j] != '\0';j++){		
		if(needle[0] == haystack[j]){
			k = 1;
			while(needle[k] !='\0' && needle[k]==haystack[k+j])
				k++;
            if(k == len){
            	occur++;
             	j += len / 2;
            }
		}
	}
	return occur;
}


int ifind(char haystack[],char needle[]){
	
	int len,i,j,k;
	len = findlenght(needle);
	lower(haystack);
	
	for(j=0;haystack[j] != '\0';j++){		
		if(needle[0] == haystack[j]){
			k = 1;
			while(needle[k] !='\0' && needle[k]==haystack[k+j])
				k++;
            if(k == len)
            	return j;
		}
	}
}

void main()
{
	char haystack[] = "deHedeheDeHEDE",needle[255] ="hede";

	printf("Position:%d ",ifind(haystack,needle));
	printf("Count:%d\n",count(haystack,needle));

	
}
