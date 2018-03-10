#include <stdio.h>

int findSize(char str[]){
	int i=0;
	while(str[i] != '\0')
		i++;
	return i;
}

char *interleave(char str1[],char str2[],char res[])
{
	int a = 0,b=0,i=0,size1=0,size2=0;
	size1 = findSize(str1);
	size2 = findSize(str2);

	if(size1 > size2){
		while(i<size1+size2){
			if(i % 2 == 0 || i >= 2 * size2){
				res[i] = str1[a];
				a++;
			}
			else{
				res[i] = str2[b];
				b++;
			}
			i++;
		}
	}else{
		while(i<size1+size2){
			if(i % 2 || i >= 2 * size1){
				res[i] = str2[b];
				b++;		
			}else{
				res[i] = str1[a];
				a++;
			}
			i++;
		}
	}

	res[i] ='\0';
	return res;
}

void main()
{
	char str1[] = "serkan",str2[]="123",res[255];
	printf("%s",interleave(str1,str2,res));
}
