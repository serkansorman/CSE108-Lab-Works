#include <stdio.h>
#define ALPHABET 26

void printHist(int hist[ALPHABET])
{
	int i;
	for(i=0;i<ALPHABET	;i++)
		printf("%c     =>%d\n",'A'+i,hist[i]);
	printf("Others => %d \n",hist[i]);
}

char *lower(char str[]){
	int i=0;
	while(str[i] != '\0'){
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return str;
}

void hist(char str[],int hist[27]){
	int i=0,j;
	while(i<27){
		hist[i] = 0;
		i++;
	}

	lower(str);
	for(i=0;str[i] != '\0';i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			for(j=0;j<26;j++)
				if(str[i] == 'a'+j)
					hist[j]++;
		}else
			hist[26]++;
	}
}


void main()
{
	char str[] ="The quick brown fox jumps over the lazy dog.";
	int histogram[ALPHABET];

	hist(str,histogram);
	printHist(histogram);
}
