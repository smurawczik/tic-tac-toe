#include <stdio.h>
#include <stdbool.h>

#include "constants.h"

bool winWithColumn(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]) {

	bool win = true;
	int playerVal = player;
	for (int i = 0; i < MATRIXHEIGHT; i++) {
		if (matrix[i][y] != playerVal) {
			win = false;
			break;
		}
	}

	return win;
}

bool winWithRow(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]) {

	bool win = true;
	int playerVal = player;
	for (int i = 0; i < MATRIXWIDTH; i++) {
		if (matrix[x][i] != playerVal) {
			win = false;
			break;
		}
	}

	return win;
}

bool winWithDiagLR(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]) {

	bool win = true;
	int playerVal = player;
	for (int i = 0; i < MATRIXHEIGHT; i++) {
		if (matrix[i][i] != playerVal) {
			win = false;
			break;
		}
	}

	return win;
}

bool winWithDiagRL(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]) {

	bool win = true;
	int playerVal = player;
	for (int i = 2; i >= 0; i--) {
		if (matrix[i][i] != playerVal) {
			win = false;
			break;
		}
	}

	return win;
}
