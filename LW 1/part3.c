#include <stdio.h>

int readInt()
{	
	int i;
	scanf("%d",&i);
	return i;

}

double readDouble()
{		
	double d;
	scanf("%lf",&d);
	return d;
}


char readChar()
{	
	char c;
	scanf(" %c",&c);
	return c;
}



double calculateBMI(int height,double weight)
{
	double bmi;
	bmi = weight / ( (height * height) / 10000.0 );
	return bmi;
}




void printPersonalInfo(int id,char name,int height,double weight)
{

	double bmi;

	bmi = calculateBMI(height,weight);
	
	printf("ID: %d \n",id);
	printf("Name: %c \n",name);
	printf("Height: %d \n",height);
	printf("Weight: %lf \n",weight);
	printf("BMI: %lf \n",bmi);

}

void getAndPrintPersonalInfo()
{	
	int id;
    char name;
    int height;
    double weight;

	id = readInt();
	name = readChar();
	height = readInt();
	weight = readDouble();

	printPersonalInfo(id,name,height,weight);
}



int main(void)
{
	getAndPrintPersonalInfo();

}
