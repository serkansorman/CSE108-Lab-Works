#include <stdio.h>

int findExp(int num,int exp)
{
	int i,val = 1;

	for(i=0;i<exp;i++)
		val = val * num;

	return val;
}

int getMaxExp()
{
	int i,j,exp,num,val = 1;
	int max;

	scanf("%d",&num);
	if(num <= 0)
		return -1;
	scanf("%d",&exp);
	if(exp <= 0)
		return -2;
	val = findExp(num,exp);
	max = val;


	while(1){
		if(val > max)
			max = val;
		val=1;
		scanf("%d",&num);
		if(num<0)
			break;
		scanf("%d",&exp);
		val = findExp(num,exp);
	}

	return max;
}

void main()
{
	printf("%d",getMaxExp());
}
