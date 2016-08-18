/*
 * win_funcs.h
 *
 *  Created on: 18 ago. 2016
 *      Author: sebastianmurawczik
 */

#ifndef WIN_FUNCS_H_
#define WIN_FUNCS_H_
#endif /* WIN_FUNCS_H_ */

bool winWithColumn(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]);

bool winWithRow(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]);

bool winWithDiagLR(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]);

bool winWithDiagRL(int player, int x, int y,
		int matrix[MATRIXWIDTH][MATRIXHEIGHT]);
