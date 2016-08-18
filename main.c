// System files
#include <stdio.h>
#include <stdbool.h>

// my files
#include "constants.h"
#include "main.h"
#include "win_funcs.h"

void startPlaying () {
	printf("empieza a jugar: \n");
}

void printTTTWithMatrix(int matrix[MATRIXWIDTH][MATRIXWIDTH]) {
	printf(
			ANSI_COLOR_RED "%d" ANSI_COLOR_GREEN "|" ANSI_COLOR_RED "%d" ANSI_COLOR_GREEN "|" ANSI_COLOR_RED "%d" ANSI_COLOR_RESET,
			matrix[0][0], matrix[1][0], matrix[2][0]);
	printf(ANSI_COLOR_GREEN "\n-----\n" ANSI_COLOR_RESET);
	printf(
			ANSI_COLOR_RED "%d" ANSI_COLOR_GREEN "|" ANSI_COLOR_RED "%d" ANSI_COLOR_GREEN "|" ANSI_COLOR_RED "%d" ANSI_COLOR_RESET,
			matrix[0][1], matrix[1][1], matrix[2][1]);
	printf(ANSI_COLOR_GREEN "\n-----\n" ANSI_COLOR_RESET);
	printf(
			ANSI_COLOR_RED "%d" ANSI_COLOR_GREEN "|" ANSI_COLOR_RED "%d" ANSI_COLOR_GREEN "|" ANSI_COLOR_RED "%d" ANSI_COLOR_RESET "\n\n",
			matrix[0][2], matrix[1][2], matrix[2][2]);
}

void changePlayer(int *player) {
	if (*player == 2) {
		*player = 1;
	} else {
		*player = 2;
	}
}

bool checkMatrix(int matrix[MATRIXWIDTH][MATRIXWIDTH]) {
	bool isFull = true;
	for (int i = 0; i < MATRIXWIDTH; i++) {
		for (int j = 0; j < MATRIXHEIGHT; j++) {
			if (matrix[i][j] == 0) {
				isFull = false;
				break;
			}
		}
	}
	return isFull;
}

bool checkForWin(int *player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]) {
	int playerVal = *player;

	bool winCol = winWithColumn(playerVal, x, y, matrix);
	if (winCol) {
		return winCol;
	}

	bool winRow = winWithRow(playerVal, x, y, matrix);
	if (winRow) {
		return winRow;
	}

	bool winDiagLR = winWithDiagLR(playerVal, x, y, matrix);
	if (winDiagLR) {
		return winDiagLR;
	}

	bool winDiagRL = winWithDiagRL(playerVal, x, y, matrix);
	if (winDiagRL) {
		return winDiagRL;
	}

	return false;
}

position getPosition(int *player) {
	int x = 0, y = 0;
	position p;
	do {
		printf("dime jugador %d la posicion X, Y: \n", *player);
		printf("X: ");
		scanf("%d", &x);
		printf("Y: ");
		scanf("%d", &y);
	} while ((x < 0 && x > 2) && (y < 0 && y > 2));
	p.x = x;
	p.y = y;
	return p;
}

void askForPosition(int matrix[MATRIXWIDTH][MATRIXHEIGHT], int *player) {
	position pos = getPosition(player);

	if (matrix[pos.x][pos.y] == 1) {
		printf("espacio elegido por el jugador 1\n\n");
		askForPosition(matrix, player);
	} else if (matrix[pos.x][pos.y] == 2) {
		printf("espacio elegido por el jugador 2\n\n");
		askForPosition(matrix, player);
	}
	matrix[pos.x][pos.y] = (*player == 1 ? 1 : 2);
	if (!checkMatrix(matrix) && checkForWin(player, pos.x, pos.y, matrix)) {
		printTTTWithMatrix(matrix);
		printf("gano el player %d ", *player);
	} else if (checkMatrix(matrix)) {
		printTTTWithMatrix(matrix);
		printf("Hubo un empate");
	} else {
		printTTTWithMatrix(matrix);
		changePlayer(player);
		askForPosition(matrix, player);
	}
}

int main() {

	int tictactoeMatrix[MATRIXWIDTH][MATRIXHEIGHT] = { { 0 }, { 0 } };
	int _player = 1;
	int *player = &_player;

	startPlaying();
	printTTTWithMatrix(tictactoeMatrix);
	askForPosition(tictactoeMatrix, player);

	return 0;
}
