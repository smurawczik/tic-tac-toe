#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
} position;

void printTTTWithMatrix(int matrix[3][3]);

void changePlayer(int *player);

bool checkMatrix(int matrix[3][3]);

bool checkForWin(int *player, int x, int y, int matrix[3][3]);

position getPosition(int *player);

void askForPosition(int matrix[3][3], int *player);
