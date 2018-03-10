#include <stdio.h>

int readInt()
{	
	int i;

	printf("Enter a integer: ");
	scanf("%d",&i);

	return i;

}

double readDouble()
{		
	double d;

	printf("Enter a double: ");
	scanf("%lf",&d);

	return d;
}

char readChar()
{	
	char c;

	printf("Enter a char: ");
	scanf(" %c",&c);

	return c;
}

int main(void)
{
	int intValue = readInt();
	double doubleValue = readDouble();
	char charValue = readChar();

	printf("%d %lf %c",intValue,doubleValue,charValue);
}