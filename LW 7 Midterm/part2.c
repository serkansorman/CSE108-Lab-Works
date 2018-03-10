#include <stdio.h>

int findLenght(char str[]){
	int i;
	for(i=0;str[i] != '\0';i++);
	return i;
}

char *reverse(char str[],char rev[]){
	int i=0,len;
	len = findLenght(str) - 1;
	while(len >= 0){
		rev[i] = str[len];
		len--;
		i++;
	}
	
	rev[i] = '\0';
	return rev;
}

char *tostr(int num,char str[]){
	int n,i=0,j=0,len;
	char temp[255];

	while(num){
		n = num % 10;
		num = (num - n) / 10;
		temp[i] = n + 48;
		i++;
	}

	reverse(temp,str);
	str[i] = '\0';
	return str;	
}


char *combine(char str1[],char str2[],char str3[],char res[])
{
	int i=0,a=0,b=1,c=2;
	char *s1 = str1,*s2 = str2,*s3 = str3;
	
	while(*s1|| *s2 || *s3){
		if(*s1 && *s2 && *s3){
			res[a] = *s1++;
			res[b] = *s2++;
			res[c] = *s3++;
			a+=3;
			b+=3;
			c+=3;
		}
		else if(!*s1 && *s2 && *s3){
			while(*s2 && *s3){
				res[a] = *s2++;
				res[b] = *s3++;
				a+=2;
				b+=2;
			}
			while(*s2)
				res[a++] = *s2++;
			while(*s3)
				res[a++] = *s2++;	
		}
		else if(*s1 && !*s2 && *s3){
			while(*s1 && *s3){
				res[a] = *s1++;
				res[b] = *s3++;
				a+=2;
				b+=2;
			}		
			while(*s1)
				res[a++] = *s1++;
			while(*s3)
				res[a++] = *s3++;
		}
		else if(*s1 && *s2 && !*s3){
			while(*s1 && *s2){
				res[a] = *s1++;
				res[b] = *s3++;

				a+=2;
				b+=2;
			}
			while(*s1)
				res[a++] = *s1++;
			while(*s2)
				res[a++] = *s2++;		
		}
	}
	res[a] = '\0';
	return res;
}

char *convert(char str[],int num,char res[]){
	char rev[255],numtoStr[255];
	combine(str,tostr(num,numtoStr),reverse(str,rev),res);
	return res;
}

void main(){
	char str[] ="herhalde",str2[255] = "turta",str3[255] = "donmus",res[255];
	int dec = 65109;

	printf("%s",convert(str,dec,res));
	
}
