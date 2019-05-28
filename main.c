#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define sizeX 10
#define sizeY 10
#define mineNum 10

void init(int ms[sizeX][sizeY]);
void setRandom(int ms[sizeX][sizeY]);
void dump(int ms[sizeX][sizeY]);
void setNumber(int ms[sizeX][sizeY]);
int getHereNum(int inputX,int inputY, int ms[sizeX][sizeY]);
void start(int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]);

int main(void){

	int ms[sizeX][sizeY];
	int isOpen[sizeX][sizeY];

	init(ms);
	init(isOpen);

	setRandom(ms);

	//dump(ms);

	setNumber(ms);

	//dump(ms);
	
	printf("\n");

	start(ms,isOpen);

	return 0;

}
void init(int ms[sizeX][sizeY]){
	int i;
	int j;
	srand((unsigned)time(NULL));

	for(i=0;i<sizeX;i++){
		for(j=0;j<sizeY;j++){
			ms[i][j] = 0;
		}
	}
}

void setRandom(int ms[sizeX][sizeY]){
	int randX;
	int randY;
	int i;
	i = 0;
	while(i<mineNum){
		randX = rand()%sizeX;
		randY = rand()%sizeY;
		if( ms[randX][randY] == 0){
			ms[randX][randY] = -1;
			i++;
		}
	}
}

void dump(int ms[sizeX][sizeY]){
	int i;
	int j;
	for(j=0;j<sizeY;j++){
		for(i=0;i<sizeX;i++){
			printf("%d ",ms[i][j]);
		}
		printf("\n");
	}
}

void setNumber(int ms[sizeX][sizeY]){
	int i;
	int j;
	for(i=0;i<sizeX;i++){
		for(j=0;j<sizeY;j++){
			if(ms[i][j] != -1){ ms[i][j] = getHereNum(i,j,ms); };
		}
	}
}

int getHereNum(int inputX,int inputY, int ms[sizeX][sizeY]){
	int count = 0;

	if(inputX != 0)         if(ms[inputX-1][inputY]   == -1) count++;
	if(inputX != sizeX - 1) if(ms[inputX+1][inputY]  == -1) count++;
	if(inputY != 0)         if(ms[inputX][inputY-1]    == -1) count++;
	if(inputY != sizeY - 1) if(ms[inputX][inputY+1] == -1) count++;

	if(inputX != 0         && inputY != 0)         if(ms[inputX-1][inputY-1]     == -1) count++;
	if(inputX != sizeY - 1 && inputY != 0)         if(ms[inputX+1][inputY-1]    == -1) count++;
	if(inputX != 0         && inputY != sizeY - 1) if(ms[inputX-1][inputY-1]     == -1) count++;
	if(inputX != sizeY - 1 && inputY != sizeY - 1) if(ms[inputX+1][inputY+1] == -1) count++;

	return count;
}

void prompt(int *x,int *y){
	printf("input (x y) ");
	scanf("%d %d",x,y);
}

void show(int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	int i;
	int j;
	printf("    ");
	for(i=0;i<sizeX;i++){
		printf("%d ",i);
	}
	printf("\n");
	printf("   ┌");
	for(i=0;i<sizeX;i++){
		printf("──",i);
	}
	printf("┐\n");
	for(j=0;j<sizeY;j++){
		printf("%d  │",j);
		for(i=0;i<sizeX;i++){
			if(isOpen[i][j] == 1){
				if(ms[i][j] == -1){
					printf("M");
				}else if(ms[i][j] == 0){
					printf(" ");
				}else{
					printf("%d",ms[i][j]);
				}
			}else{
				printf("■");
			}
			printf(" ");
		}
		printf("│\n");
	}
	printf("   └");
	for(i=0;i<sizeX;i++){
		printf("──",i);
	}
	printf("┘\n");
}

int calcFail(int inputX, int inputY, int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	if(isOpen[inputX][inputY] == 1) return 2;

	if(ms[inputX][inputY] == -1){
		return 1;
	}

	return 0;
}

int calcAutoOpen(int inputX, int inputY, int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	int i;
	int j;

	for(j=0;j<sizeY;j++){
		for(i=0;i<sizeX;i++){
			if(ms[i][j] == 0){
			}
		}
	}
	int count = 0;
	if(inputX != 0)         if(ms[inputX-1][inputY]   == -1) count++;
	if(inputX != sizeX - 1) if(ms[inputX+1][inputY]  == -1) count++;
	if(inputY != 0)         if(ms[inputX][inputY-1]    == -1) count++;
	if(inputY != sizeY - 1) if(ms[inputX][inputY+1] == -1) count++;

	if(inputX != 0         && inputY != 0)         if(ms[inputX-1][inputY-1]     == -1) count++;
	if(inputX != sizeY - 1 && inputY != 0)         if(ms[inputX+1][inputY-1]    == -1) count++;
	if(inputX != 0         && inputY != sizeY - 1) if(ms[inputX-1][inputY-1]     == -1) count++;
	if(inputX != sizeY - 1 && inputY != sizeY - 1) if(ms[inputX+1][inputY+1] == -1) count++;
}

void start(int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	int inputX;
	int inputY;
	int loop = 1;
	int failReturn;

	while(loop){
		show(ms,isOpen);

		prompt(&inputX,&inputY);
		//printf("ms[%d][%d] = %d",inputX,inputY, ms[inputX][inputY]);

		failReturn = calcFail(inputX, inputY, ms, isOpen);

		if(failReturn == 1){
			isOpen[inputX][inputY] = 1;
			show(ms,isOpen);
			printf("\n == Game Over. == \n");
			loop = 0;
		}else if(failReturn == 2){
			printf("\n == The position is already opened. == \n");
		}else{
			isOpen[inputX][inputY] = 1;
			calcAutoOpen(inputX, inputY, ms,isOpen);
		}
	}
}
