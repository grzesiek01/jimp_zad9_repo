#include <stdio.h>
#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i;
	int j;
	if(x->c != 1 || b->c != 1 || mat->r != x->r || mat->r != b->r) {
		printf("Blad nieprawidlowych rozmiarow macierzy");
		return 2;
	}
	for(i=0; i < mat->r; i++) {
		if(mat->data[i][i] == 0) {
			printf("Blad dzielenia przez 0 (element diagonali = 0)");
			return 1;	
		}
	}
	for(i = mat->r - 1; i >= 0; i--) {
		double s = b->data[i][0];
		for(j = i+1; j < mat->c; j++) {
			s-=mat->data[i][j] * x->data[j][0];
		}
		x->data[i][0] = s / mat->data[i][i];
	}
	return 0;
}


