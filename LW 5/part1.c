#include <stdio.h>

double calculateResult(int trueAns,int falseAns,int totalAns)
{
	double net;
	net = trueAns - falseAns / 4.0;
	return (net / totalAns);
}

double testResults(int questionNumbersArr[],int qNArrSize,char answersArr[],int ansArrSize,char keysArr[],int keysArrSize)
{
	int i,trueAns = 0,falseAns = 0;
	double result;

	for(i=0;i<ansArrSize;i++){
		if(keysArr[questionNumbersArr[i] - 1] == answersArr[i])
			trueAns ++;
		else
			falseAns ++;
	}
	result = calculateResult(trueAns,falseAns,keysArrSize);
	return result;
}

void main(){
	
	int questionNumbersArr[] = {1,2,4,5,7,9},qNArrSize = 6,ansArrSize = 6 , keysArrSize = 10;
	char answersArr[] = {'A','C','D','B','E','B'};
	char keysArr[] = {'A','C','E','D','B','A','A','D','B','E'};

	printf("%lf",testResults(questionNumbersArr,qNArrSize,answersArr,ansArrSize,keysArr,keysArrSize));

}
