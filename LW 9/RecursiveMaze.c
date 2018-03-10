#include <stdio.h>


typedef enum _tiles {BORDER, WALL, EMPTY, USED, START} TILES;
int testMaze(char * fileName, int startTile[2]);
void readMaze(TILES maze[100][100], char * fileName, int *w, int *h);
void printMaze(TILES maze[100][100], int a, int b);

int isStuck(TILES maze[100][100], int currentTile[]);
int isExit(TILES maze[100][100], int currentTile[]);
int exitFromMaze(TILES maze[100][100], int currentTile[2]);
void clearBoard(TILES maze[100][100]);



/**************************** part 1 *****************************/
void printMaze(TILES maze[100][100], int a, int b){
	int i = 0, j = 0;
	
	printf("  ");
	for (j = 0; j < b; ++j){
		printf("%d ", j%10);
	}
	printf("\n");

	for (i = 0; i < a; ++i){
		printf("%d ", i%10);
		for (j = 0; j < b; ++j){
			switch(maze[i][j]){
				case EMPTY:
					printf("  ");
					break;
				case WALL:
					printf("W ");
					break;
				case USED:
					printf(". ");
					break;
				case BORDER:
					printf("B ");
					break;
				case START:
					printf("* ");
					break;
			}
		}
		printf("\n");
	}
	printf("\n");
}


int isStuck(TILES maze[100][100], int currentTile[]){

	if(maze[currentTile[0] + 1][currentTile[1]] != EMPTY &&
	   maze[currentTile[0]][currentTile[1] + 1] != EMPTY &&
	   maze[currentTile[0] - 1][currentTile[1]] != EMPTY &&
	   maze[currentTile[0]][currentTile[1] - 1] != EMPTY )
	{
		return 1;
	}
	else
		return 0;
}



int isExit(TILES maze[100][100], int currentTile[]){

	if(maze[currentTile[0] + 1][currentTile[1]] == BORDER ||
	   maze[currentTile[0]][currentTile[1] + 1] == BORDER ||
	   maze[currentTile[0] - 1][currentTile[1]] == BORDER ||
	   maze[currentTile[0]][currentTile[1] - 1] == BORDER )
	{
		return 1;
	}
	else
		return 0;

}



int exitFromMaze(TILES maze[100][100], int currentTile[2]){

	int count = 0,tempTile[2];

	if(maze[currentTile[0]][currentTile[1]] != EMPTY)	
		// if start position is invalid return -1
		return -1;										
	
	maze[currentTile[0]][currentTile[1]] = USED;
	
	/* Termination condition for recursion */
	if(isStuck(maze,currentTile) && ! isExit(maze,currentTile))			
		return 0;
	else{
		/*Controls the environment of the current tile*/
		if(maze[currentTile[0] + 1][currentTile[1]] == EMPTY){
			tempTile[0] = currentTile[0] + 1;
			tempTile[1] = currentTile[1];
			count += exitFromMaze(maze,tempTile);
		}
		if(maze[currentTile[0] - 1][currentTile[1]] == EMPTY){
			tempTile[0] = currentTile[0] - 1;
			tempTile[1] = currentTile[1];
			count += exitFromMaze(maze,tempTile);
		}
		if(maze[currentTile[0]][currentTile[1] + 1] == EMPTY){
			tempTile[0] = currentTile[0];
			tempTile[1] = currentTile[1] + 1;
			count += exitFromMaze(maze,tempTile);
		}
		if(maze[currentTile[0]][currentTile[1] - 1] == EMPTY){
			tempTile[0] = currentTile[0];
			tempTile[1] = currentTile[1] - 1;
			count += exitFromMaze(maze,tempTile);
		}
		/*Controls the current tile whether exit or not  and increment the counter */
		if(isExit(maze,currentTile))
			count += 1;
		return count;
	}


}

void clearBoard(TILES maze[100][100]){
	int i = 0, j = 0;
	
	for (i = 0; i < 100; ++i)
		for (j = 0; j < 100; ++j)
			maze[i][j] = BORDER;
}


void readMaze(TILES maze[100][100], char * fileName, int *w, int *h){
	int i = 0, j = 0, tile = 0;
	FILE *fp = fopen (fileName, "r");

	clearBoard(maze);

	fscanf(fp, "%d", w);
	fscanf(fp, "%d", h);


	for (i = 0; i < *w; ++i){
		for (j = 0; j < *h; ++j){
			fscanf(fp, "%d", &tile);
			switch(tile){
				case 0:
					maze[i][j] = EMPTY;
					break;
				case 1:
					maze[i][j] = WALL;
					break;
				case 2:
					maze[i][j] = USED;
					break;
				case 3:
					maze[i][j] = BORDER;
					break;
			}
		}
	}
	fclose(fp);
}


int testMaze(char * fileName, int startTile[2]){
	int totalExits = 0;
	int w = 0, h = 0;

	TILES maze[100][100];
	
	printf("Board name: %s\n", fileName);

	readMaze(maze, fileName, &w, &h);


	totalExits = exitFromMaze(maze, startTile);
	maze[startTile[0]][startTile[1]] = START;
	printMaze(maze, w, h);

	printf("Total Exits: %d\n", totalExits);
	printf("-------------------------------------\n");
	return totalExits;
}


int main(){
	int startTile1[2] = {5,2};
	int startTile2[2] = {2,3};
	int startTile3[2] = {2,3};
	int startTile4[2] = {2,3};
    testMaze("maze1.txt", startTile1);
	testMaze("maze2.txt", startTile2);
	testMaze("maze3.txt", startTile3);
	testMaze("maze4.txt", startTile4);
	
	return 0;
}





