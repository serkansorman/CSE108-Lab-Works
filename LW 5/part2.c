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
	for(i=0;i<ansArrSize;i++){
		if(keysArr[questionNumbersArr[i] - 1] == answersArr[i])
			trueAns ++;
		else
			falseAns ++;
	}
	return calculateResult(trueAns,falseAns,keysArrSize);;
}



void convertLetter(char *letterArr,int letterNum,int i)
{
	switch(letterNum)
	{
		case 1:
		letterArr[i] = 'A';
		break;
		case 2:
		letterArr[i] = 'B';
		break;
		case 3:
		letterArr[i] = 'C';
		break;
		case 4:
		letterArr[i] = 'D';
		break;
		case 5:
		letterArr[i] = 'E';
		break;
	}
}




double testResult2d(char questionNumbersArr[][5],int qNArrSize,char keysArr[],int keysArrSize)
{
	int ansArrSize = 0,i,j,letterNum = 0,NumArr[qNArrSize],markCount = 0;
	char letterArr[qNArrSize];
	
	for(i=0;i<qNArrSize;i++)
	{
		for(j=0;j<5;j++)
		{
			letterNum ++;
			if(questionNumbersArr[i][j] == '*')
			{
				markCount ++;
				if(markCount == 1)
				{
					NumArr[ansArrSize] = i + 1;
					convertLetter(letterArr,letterNum,ansArrSize);
					ansArrSize++;
				}
				else if(markCount > 1)
					letterArr[ansArrSize - 1] = 'F';
				
			}
		}
		markCount = 0;
		letterNum = 0;	
	}

	return testResults(NumArr,ansArrSize,letterArr,ansArrSize,keysArr,keysArrSize);
}




void main(){


	char answersArr[][5] = {
	{'*','-','-','-','-'},
	{'-','-','*','-','-'},
	{'-','-','-','-','-'},
	{'-','-','-','*','-'},
	{'-','*','-','-','-'},
	{'-','-','-','-','-'},
	{'*','-','-','-','*'},
	{'-','-','-','-','-'},
	{'-','*','-','-','-'},
	{'-','-','-','-','-'},
	};
	
	int keysArrSize = 10;
	char keysArr[] = {'A','C','E','D','B','A','A','D','B','E'};
	printf("%lf",testResult2d(answersArr,10,keysArr,keysArrSize));
}
