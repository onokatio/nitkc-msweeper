#include <stdio.h>
#include <stdlib.h>

#define sizeX 10
#define sizeY 10
#define mineNum 10

int main(void){

	int ms[sizeX][sizeY];

	init(ms);

	setRandom(ms);

	dump(ms);

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
			ms[randX][randY] = 1;
			i++;
		}
	}
}

void dump(int ms[sizeX][sizeY]){
	int i,j;
	for(i=0;i<sizeX;i++){
		for(j=0;j<sizeY;j++){
			printf("%d ",ms[i][j]);
		}
		printf("\n");
	}
}
