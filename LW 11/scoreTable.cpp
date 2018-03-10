#include <stdio.h>
#include <string.h>

typedef struct _score
{
    char name[20];
    int score;
}Score;


int readTable(char filename[],Score table[],int *tableSize){

	int i=0,status = 0;
	FILE *file;
	file = fopen("table.bin","rb");

	if(file != NULL){
		while(fread(&table[i],sizeof(Score),1,file) != 0){
			++i;
			(*tableSize)++;
		}
		status = 0;
	}else
		status = -1;

    fclose(file);
	return status ;
}


int writeTable(char filename[],Score table[],int tableSize)
{

	int i=0,status = 0;
	FILE *file;
	file = fopen(filename,"wb");

	if(file != NULL){
		for(i=0;i<tableSize;i+= 1)
			fwrite(&table[i],sizeof(Score),1,file);
		status = 0;
	}else
		status = -1;
		
	fclose(file);
	return status ;

}

void setRowValues(Score *row, char name[], int score){
    strcpy(row->name, name);
    row->score = score;
}


void setRow(Score *row1, Score row2){
    strcpy(row1->name, row2.name);
    row1->score = row2.score;
}

void swapRows(Score *row1, Score *row2){
    Score tmp;
    setRow(&tmp, *row1);
    setRow(row1, *row2);
    setRow(row2, tmp);
}

void sortPlayers(Score row,Score table[],int *tableSize){
	int i;
	for (i = *tableSize-1; i > 0; --i)
    	if(table[i-1].score<table[i].score)
    		swapRows(&(table[i-1]), &(table[i]));
}

void insertRow(Score row, Score table[], int *tableSize){
    int i = 0;
    if(*tableSize < 10){
        setRow(&(table[*tableSize]), row);
        (*tableSize)++;
        sortPlayers(row,table,tableSize);
    }
	else if(table[9].score<row.score){
        setRow(&(table[9]), row);
        sortPlayers(row,table,tableSize);
    }
    
}

void insertRowAndSave(char filename[], Score row){
    Score table[10];
    int tableSize = 0;
    readTable(filename, table, &tableSize);
    insertRow(row, table, &tableSize);
    writeTable(filename, table, tableSize);
}

void printTable(Score table[], int tableSize){
    int i = 0;
    for (i = 0; i < tableSize; ++i){
        printf("%s: %d\n",table[i].name, table[i].score);
    }
}

int main()
{
    Score table[10];
    Score row;
    int tableSize = 0;

    setRowValues(&row,"player1",60);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player2",70);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player3",65);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player4",45);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player5",35);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player6",85);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player7",20);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player8",95);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player9",90);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player10",15);
    insertRow(row,table,&tableSize);
    setRowValues(&row,"player11",100);
    insertRowAndSave("table.bin",row);
    printTable(table,tableSize);
    
    return 0;

}
