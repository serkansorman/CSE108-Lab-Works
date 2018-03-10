#include <stdio.h>
int getMinAndMax(int *min,int *max)
{
	int number;
	
	printf("Enter a positive integer: ");
	scanf("%d",&number);
	
	if(number <= 0)
		return -1;

	*min= number;
	*max= number;

	while(number > 0)
	{
		if (number < *min)
			*min = number;
			
			printf("%d ",*min);
	
		if (number > *max)
			*max = number;
			
			printf("%d ",*max);
		
		printf("Enter a positive integer: ");
		scanf("%d",&number);
	}
	return 0;
}


