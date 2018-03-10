#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ILSAYISI 81
#define ILCESAYISI 970
#define MAXSTRLEN 64
#define LINELEN 255

typedef enum order_s {
	ASC, DESC
} order;

typedef enum sortby_s {
	ISIM, IL, NUFUS
} sortby;

typedef struct ilce_s {
	char isim[MAXSTRLEN];
	char il[MAXSTRLEN];
	int nufus;
} ilce;

typedef struct iller_s {
	char isim[ILSAYISI][MAXSTRLEN];
} iller;

typedef struct nufus_s
{
	ilce ilceler[ILCESAYISI];
	int count;
} nufus;


void printNufus(nufus nuf) {
	int i;
	printf("%-30s%-30s%8s\n","ILCE","IL","NUFUS");
	for (i = 0; i < 68; ++i)
		printf("-");
	printf("\n");
	for (i = 0; i < nuf.count; ++i)
		printf("%-30s%-30s%8d\n",nuf.ilceler[i].isim,nuf.ilceler[i].il,nuf.ilceler[i].nufus);
}


void printIller(iller sehirler) {
	int i;
	for (i = 0; i < ILSAYISI; ++i) {
		printf("`%s`\n", sehirler.isim[i]);
	}
}

/* =================== IMPLEMENT THE FUNCTIONS BELOW =================== */

/* Parse the line string to construct an ilce struct. Then place this ilce
   struct to nufus struct. This function will be called for each line in
   ilceler.txt.
*/

void addIlce(nufus *nuf, char* line) {

	sscanf(line,"%s %s %d",nuf->ilceler[nuf->count].isim,nuf->ilceler[nuf->count].il,&nuf->ilceler[nuf->count].nufus);
	++nuf->count;
}

/* sort nufus struct according to sortby and order parameters and print the
   sorted nufus struct using printNufus function.

   - order parameter defines how the sorting will be done. It can be either
	 ascending (artan A-Z) or descending (azalan Z-A).

   - sort parameter defines which information is used during the sorting
     process. nufus struct can be sorted by population, by district(ilce) name
     or by city name. If city name is used on sorting, you should also sort
     the districts of the same city by its name. If district name is used on
     sorting you should use the city name for sorting the districts with the
     same name.

     Example output (sorting is done by city name, ascending order):
     ILCE                          IL                               NUFUS
     --------------------------------------------------------------------
     .
     .
     .
     AKYAKA                        KARS                             11375
     ARPACAY                       KARS                             18737
     DIGOR                         KARS                             24932
     KAGIZMAN                      KARS                             46687
     KARS                          KARS                            111278
     SARIKAMIS                     KARS                             47231
     SELIM                         KARS                             24924
     SUSUZ                         KARS                             11302
     .
     .
     .
*/
void swap(char *str1,char *str2,int *n1,int *n2)
{
	int tempInt = 0;
	char temp[64];

	strcpy(temp,str1);
	strcpy(str1,str2);
	strcpy(str2,temp);

	tempInt = *n1;
	*n1 = *n2;
	*n2 = tempInt;
}

void printSorted(nufus nuf, sortby sort, order ord) {

	char temp[64];
	int i,j,tempInt = 0,a=1,b=2;
	
	for(i=0;i<ILCESAYISI;i++)
	{	
		for(j=i+1;j<ILCESAYISI;j++)
		{
			switch(sort)
			{	
				case IL:
				if(strcmp(nuf.ilceler[i].il,nuf.ilceler[j].il) > 0)
				{	
					swap(nuf.ilceler[i].il,nuf.ilceler[j].il,&nuf.ilceler[i].nufus,&nuf.ilceler[j].nufus);
					swap(nuf.ilceler[i].isim,nuf.ilceler[j].isim,&a,&b);
				}
				break;

				case ISIM:
				if(strcmp(nuf.ilceler[i].isim,nuf.ilceler[j].isim) > 0)
				{	
					swap(nuf.ilceler[i].il,nuf.ilceler[j].il,&nuf.ilceler[i].nufus,&nuf.ilceler[j].nufus);
					swap(nuf.ilceler[i].isim,nuf.ilceler[j].isim,&a,&b);
				}
				break;

				case NUFUS:
				if(nuf.ilceler[i].nufus > nuf.ilceler[j].nufus)
				{	
					swap(nuf.ilceler[i].il,nuf.ilceler[j].il,&nuf.ilceler[i].nufus,&nuf.ilceler[j].nufus);
					swap(nuf.ilceler[i].isim,nuf.ilceler[j].isim,&a,&b);
				}
				break;
			}
		}	
	}
	

	printNufus(nuf);
}

/* calculate the city population based on nufus struct */
int getIlNufus(nufus nuf, char* il) {

	int i,sum = 0;
	for(i=0;i<ILCESAYISI;i++)	
		if(strcmp( nuf.ilceler[i].il, il) == 0)
			sum += nuf.ilceler[i].nufus;
	return sum;
}

/* find the city which has the maximum population based on nufus struct */
/* return the address of the city name from iller struct */

char* mostCrowdedCity(nufus nuf, iller *sehirler) {

	int i,max = 0;
	char *maxCity;

	max = getIlNufus(nuf,sehirler->isim[0]);
	for(i=1;i<ILSAYISI;i++){	
		if( getIlNufus(nuf,sehirler->isim[i]) > max)	{
			max = getIlNufus(nuf,sehirler->isim[i]);
			maxCity = sehirler->isim[i];
		}
	}
	return maxCity;
}

int countIlce(nufus nuf,char *il,iller *sehirler){
	int i,j,IlceSayisi = 0;
	for(i=0;i<ILSAYISI;i++)
		for(j=0;j<nuf.count;j++)
			if(strcmp(il,nuf.ilceler[j].il) == 0)
				IlceSayisi++;
	return IlceSayisi;
}

/* find the city which has the maximum number of districts (ilce) */
/* return the address of the city name from iller struct */
char* mostFragmentedCity(nufus nuf, iller *sehirler) {

	int i,j,maxIlceSayisi;
	char *mostFragment;
	maxIlceSayisi = countIlce(nuf,sehirler->isim[0],sehirler);
	strcpy(mostFragment,sehirler->isim[0]);

	for(i=1;i<ILSAYISI;i++){	
		if(countIlce(nuf,sehirler->isim[i],sehirler) > maxIlceSayisi){
			maxIlceSayisi = countIlce(nuf,sehirler->isim[i],sehirler);
			strcpy(mostFragment,sehirler->isim[i]);
		}
	}
	return mostFragment;
}

/* construct iller struct based on the given nufus struct */
/* every il should occur one time in iller struct */
void constructIller(nufus nuf, iller *sehirler) {
	int i,j, ind = 0;
	for (i = 0; i < nuf.count; ++i) {
		for(j = 0; j < ILSAYISI; ++j) {
			if(strcmp(nuf.ilceler[i].il,sehirler->isim[j]) == 0) {
				break;
			}
		}
		if(j == ILSAYISI) /* not found */
			strcpy(sehirler->isim[ind++], nuf.ilceler[i].il);
	}
}


void test() {
	char line[LINELEN];
    FILE *file = fopen("ilceler.txt","r");
    nufus nuf;
    iller sehirler;
    nuf.count = 0;
    if(!file) {
    	fprintf(stderr, "Unable to open file.\n");
    	return;
    }
    while (1) {
        if(fgets(line, LINELEN,file)) {
        	addIlce(&nuf, line);
        } else
        	break;
    }

   constructIller(nuf,&sehirler);
   printIller(sehirler);
   printSorted(nuf,NUFUS,DESC);
   
   printf("%-29s: %d\n", "ÇANKIRI NUFUSU", getIlNufus(nuf,"CANKIRI"));
   printf("%-29s: %d\n", "MERSİN NUFUSU", getIlNufus(nuf,"MERSIN") );
   printf("%-28s: %s\n", "EN KALABALIK SEHIR", mostCrowdedCity(nuf,&sehirler));
   printf("%-28s: %s\n", "EN COK ILCEYE SAHIP SEHIR", mostFragmentedCity(nuf,&sehirler));
   
}

int main() {
	test();
	return 0;
}

