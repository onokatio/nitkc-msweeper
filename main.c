#include <stdio.h>
#include <stdlib.h>

#define sizeX 10
#define sizeY 10
#define mineNum 10

#define xRight x+1
#define xLeft x-1
#define yTop y-1
#define yBottom y+1

int main(void){

	int ms[sizeX][sizeY];
	int isOpen[sizeX][sizeY];

	init(ms);
	init(isOpen);

	setRandom(ms);

	//dump(ms);

	setNumber(ms);

	dump(ms);

	start(ms,isOpen);

	return 0;

}
void init(int ms[sizeX][sizeY]){
	int i,j;
	srand((unsigned)time(NULL));

	for(i=0;i<sizeX;i++){
		for(j=0;j<sizeY;j++){
			ms[i][j] = 0;
		}
	}
}

void setRandom(int ms[sizeX][sizeY]){
	int randX,randY;
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
	int i,j;
	for(j=0;j<sizeY;j++){
		for(i=0;i<sizeX;i++){
			printf("%d ",ms[i][j]);
		}
		printf("\n");
	}
}

void setNumber(int ms[sizeX][sizeY]){
	int i,j;
	for(i=0;i<sizeX;i++){
		for(j=0;j<sizeY;j++){
			if(ms[i][j] != -1) ms[i][j] = getHereNum(i,j,ms);
		}
	}
}

int getHereNum(int x,int y, int ms[sizeX][sizeY]){
	int count = 0;

	if(x != 0)         if(ms[xLeft][y]   == -1) count++;
	if(x != sizeX - 1) if(ms[xRight][y]  == -1) count++;
	if(y != 0)         if(ms[x][yTop]    == -1) count++;
	if(y != sizeY - 1) if(ms[x][yBottom] == -1) count++;

	if(x != 0         && y != 0)         if(ms[xLeft][yTop]     == -1) count++;
	if(x != sizeY - 1 && y != 0)         if(ms[xRight][yTop]    == -1) count++;
	if(x != 0         && y != sizeY - 1) if(ms[xLeft][yTop]     == -1) count++;
	if(x != sizeY - 1 && y != sizeY - 1) if(ms[xRight][yBottom] == -1) count++;

	return count;
}

void prompt(int *x,int *y){
	printf("input (x y) ");
	scanf("%d %d",x,y);
}

void show(int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	int i,j;
	for(j=0;j<sizeY;j++){
		for(i=0;i<sizeX;i++){
			if(isOpen[i][j] == 1){
				if(ms[i][j] == -1){
					printf("%d",ms[i][j]);
				}else{
					printf("M");
				}
			}else{
				printf("*");
			}
			printf(" ");
		}
		printf("\n");
	}
}

int calcFail(int inputX, inputY, int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	if(isOpen[inputX][inputY] ==1) return 2;

	if(ms[inputX][inputY] == -1){
		return 1;
	}

	return 0;
}

int calcOpen(int inputX, inputY, int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	if(x != 0)         if(ms[xLeft][y]   == -1) count++;
	if(x != sizeX - 1) if(ms[xRight][y]  == -1) count++;
	if(y != 0)         if(ms[x][yTop]    == -1) count++;
	if(y != sizeY - 1) if(ms[x][yBottom] == -1) count++;

	if(x != 0         && y != 0)         if(ms[xLeft][yTop]     == -1) count++;
	if(x != sizeY - 1 && y != 0)         if(ms[xRight][yTop]    == -1) count++;
	if(x != 0         && y != sizeY - 1) if(ms[xLeft][yTop]     == -1) count++;
	if(x != sizeY - 1 && y != sizeY - 1) if(ms[xRight][yBottom] == -1) count++;
}

void start(int ms[sizeX][sizeY],int isOpen[sizeX][sizeY]){
	int inputX,inputY;
	int loop = 1;
	int failReturn;

	while(loop){
		show(ms,isOpen);

		prompt(&inputX,&inputY);
		//printf("ms[%d][%d] = %d",inputX,inputY, ms[inputX][inputY]);

		failReturn = calcFail(inputX, inputY, ms, isOpen);

		if(failReturn == 1){
			loop = 0;
		}else if(calcReturn == 2){
			printf("The position is already opened.");
		}else{
			isOpen[inputX][inputY] = 0;
			calcOpen(inputX, inputY, ms,isOpen);
		}
	}
}
