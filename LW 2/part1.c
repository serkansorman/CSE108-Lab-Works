#include <stdio.h>

double mean()
{
	int count = 0;
	double num = 0;
	double sum = 0;

	printf("Enter a number: ");
	scanf("%lf",&num);

	if(num <= 0)
		return 0;
	
	while(num > 0){	
		sum += num;
		++count;
		printf("Enter a number: ");
		scanf("%lf",&num);
	}

	return  sum / count;
}

void main()
{
	double average = mean();
	printf("%lf",average);
}
