#include <stdio.h>

double MaxSumOfIncSeq()
{
	double num = 0,maxcount = 0,sum = 0,next = 0,arr[255],target;
	int count = 1,countarr[255],i = 0,j;
	scanf("%lf",&num);

	if(num<0)
		return -1;

	sum = num;
	
	while(1){
		scanf("%lf",&next);
		if(next>num)
		{
			sum += next;
			count++;
		}
		if(next < num)
		{
			arr[i] = sum;
			countarr[i] = count;
			
			count = 0;
			sum = 0;
			i++;
		}

		if(next< 0)
			break;
	}

	maxcount = countarr[0];
	target = arr[0];
	for(j=1;j<i;j++)
	{
		if(countarr[j]>maxcount)
		{
			maxcount = countarr[j];
			target = arr[j];
			
		}
	}

	return target;
}
void main()
{
	printf("%lf",MaxSumOfIncSeq());
}


	
