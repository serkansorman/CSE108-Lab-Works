#include <stdio.h>

double minumum()
{
	double num = 0;
	double min;
	printf("Enter a number: ");
	scanf("%lf",&num);

	if(num <= 0)
		return 0;
	
	min = num;
	while(num > 0){	
		
		if(num < min )
			min = num;
	
		printf("Enter a number: ");
		scanf("%lf",&num);
	}

	return min;
}


double maximum()
{
	double num = 0;
	double max;
	printf("Enter a number: ");
	scanf("%lf",&num);
	
	if(num <= 0)
		return 0;
	
	max = num;
	while(num > 0){		
		if(num > max )
			max = num;
		printf("Enter a number: ");
		scanf("%lf",&num);
	}

	return max;
}

void main()
{
	double max = maximum();
	printf("%lf",max);
}
