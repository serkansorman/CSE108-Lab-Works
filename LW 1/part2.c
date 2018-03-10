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



double calculateBMI(int height,double weight)
{
	double bmi;
	bmi = weight / ( (height * height) / 10000.0 );
	return bmi;
}


double getInfoAndCalculateBMI()
{	
	double bmi;
	double weight;
	int height;

	printf("Enter a height: ");
	height = readInt();

	printf("Enter a weight: ");
	weight = readDouble();

	bmi = calculateBMI(height,weight);

	return bmi;
}



int main(void)
{
	double bmi = getInfoAndCalculateBMI();
	printf("%lf",bmi);
}
