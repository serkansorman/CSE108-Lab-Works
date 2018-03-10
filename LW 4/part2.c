#include <stdio.h>

void Lower(char *arr,int size){
	int i;
	for(i=0;i<size;i++)
		if(arr[i] >= 'A' && arr[i] <= 'Z')
			arr[i] += 'a' - 'A';		
}


void swap(char *n1,char *n2){
	char temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void alphabeticalSort(char *arr,int size){
	int i,j;
	Lower(arr,size);
	for(i=0;i<size;i++)
		for(j=i+1;j<size;j++)
			if(arr[j] < arr[i])	
				swap(&arr[i],&arr[j]);
}

void main(){

	int i;
	char arr[] = {'z','c','b','d','a','b','a','f','m','i'};
	alphabeticalSort(arr,10);
	for(i=0;i<10;i++)
		printf("%c",arr[i]);
}
