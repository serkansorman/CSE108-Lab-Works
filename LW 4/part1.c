#include <stdio.h>

typedef enum {MAX,MIN,SUM} operation;


int MaxArr(int *arr,int size){
	int i,max = 0;
	max = arr[0];
	for(i=1;i<size;i++)
		if(arr[i] > max)
			max = arr[i]
	return max;
}


int MinArr(int *arr,int size){
	int i,min = 0;
	min = arr[0];
	for(i=1;i<size;i++)
		if(arr[i] < min)
			min = arr[i];
	return min;
}


int SumArr(int *arr,int size){
	int i,sum = 0;
	for(i=0;i<size;i++)
		sum += arr[i];
	return sum;
}




int arrOp(int *arr,int size,operation op){

int Result = 0;

	switch(op)
	{
		case MAX:
		Result = MaxArr(arr,size);
		break;
		case MIN:
		Result = MinArr(arr,size);
		break;
		case SUM:
		Result = SumArr(arr,size);
		break;
		default:
		Result = -9876;
	}
	return Result;
}



void main(){

	int array[] = {1,2,3,4,5,6,7,-99,200},size = 9;

	int max = arrOp(array,size,MAX);
	int min = arrOp(array,size,MIN);
	int sum = arrOp(array,size,SUM);

	printf("max = %d min = %d sum = %d",max,min,sum);
	
}
