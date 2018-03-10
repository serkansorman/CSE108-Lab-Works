#include <stdio.h>

void swap(int *n1,int *n2)
{
	int temp;

	temp  = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int sum(int n)
{
	int i,sumNum = 0;

	for(i=1;i<=n;i++)
		sumNum += i;
	
	return sumNum;
}


int getMaxThreeTotal(int *first,int *second,int *third)
{
	int n1,n2,target;
	*first = 0;
	*second = 0;
	*third = 0;

	scanf("%d",&n1);
	if(n1<=0)
        return -1;
	scanf("%d",&n2);
	if(n2<=0)
        return -2;
    if(n2<n1)
        return -3;

	target = sum(n2) - sum(n1) + n1;
	while(1){
		if(target > *third)
			*third = target;
		if(*third > *second)
			swap(third,second);
		if(*second > *first)
			swap(first,second);

		scanf("%d",&n1);
		if(n1 < 0)
			return 0;

		scanf("%d",&n2);
		if(n2<=0)
            return -2;
        if(n2<n1)
            return -3;

		target = sum(n2) - sum(n1) + n1;
	}
}



void main()
{	
	int first,second,third;

	getMaxThreeTotal(&first,&second,&third);
	printf("%d %d %d",first,second,third);

}
