#include <stdio.h>


void printByte(int byte[])
{
	int i;
	for(i=0;i<8;i++)
		printf("%d",byte[i]);
}

int power(int x,int y)
{
	int i,carpim = 1;
	for(i=0;i<y;i++)
		carpim = carpim * x;
	return carpim;
}


int bin2dec(int bin[]){
	int i = 0,j = 7,dec = 0;
	while(i<8){
		dec = dec + (bin[i] * power(2,j));
		i++;
		j--;
	}
	return dec;
}

int dec2bin(int dec,int bin[]){
	int i = 7;
	while(i>=0){	
		bin[i] = dec % 2;
		dec = dec / 2;	
		i--;
	}
}



void main()
{
	int a[8] = {1,0,1,0,1,0,1,0},b[8],dec = 249;

	printf("Binary: ");
	printByte(a);
	printf("  => Decimal: %d",bin2dec(a));
	printf("\n");
	printf("Decimal: %d => Binary: ",dec);
	dec2bin(dec,b);
	printByte(b);	
}
