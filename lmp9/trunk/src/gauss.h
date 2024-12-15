#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
Matrix * smaller(Matrix *big, int i, int j);

double detm(Matrix *mat);

int eliminate(Matrix *mat, Matrix *b);

#endif
