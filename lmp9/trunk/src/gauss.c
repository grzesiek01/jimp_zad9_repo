#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void swaprow(Matrix *mat, int a, int b){
	double *tmp = malloc(sizeof(double)*mat->r);
	for(int i=0; i<mat->r; i++){
		tmp[i] = mat->data[a][i];
	}
	for(int j=0; j<mat->r; j++){
		mat->data[a][j] = mat->data[b][j];
	}
	for(int k=0; k<mat->r; k++ ){
		mat->data[b][k] = tmp[k];
	}
}

Matrix * smaller(Matrix *big, int i, int j){
	//printToScreen(big);
	Matrix * small = (Matrix*) malloc(sizeof(Matrix));
	small->r = big->r-1;
	small->c = big->c-1;
	//printf("%d, %d\n", small->r, small->c);
	double* tmp = malloc(sizeof(double) * small->r);
	double** dane = malloc(sizeof(tmp) * small->r);
	int m = 0;
	int n = 0;
	int c1 = 0;
	int c2 = 0;
	for(m=0; m<small->r+1; m++){
		if(m!=i){
			double* tmp1 = malloc(sizeof(double) * small->r);
			for(n=0; n<small->r+1; n++){
				if(n!=j){
					tmp1[c1] = big->data[m][n];
					//printf("%f, %f\n", tmp1[0], tmp1[1]);
					c1+=1;
				}	
			}
			//printf("%d\n", c2);
			dane[c2] = tmp1;
			//printf("%f, %f, %f, %f\n", dane[0][0],dane[0][1],dane[1][0],dane[1][1]);
			c2++;
			c1 = 0;
		}
	}
	small->data = dane;
	return small;
}

double detm(Matrix *mat){
	double sum = 0;
	if(mat->r == 2){
		return mat->data[0][0]*mat->data[1][1] - mat->data[0][1]*mat->data[1][0];
	}
	for (int i=0; i<mat->r; i++){
		if(i%2 == 0){
			sum+=mat->data[0][i]*detm(smaller(mat,0,i));
		}
		else{
			sum-=mat->data[0][i]*detm(smaller(mat,0,i));
		}
	}
	return sum;
}

int eliminate(Matrix *mat, Matrix *b){
	if(detm(mat) == 0){
		return 1;
	}
	double wsp = 0; 
	double flag = 0;
	for (int i=0; i<mat->r-1; i++){
		if(mat->data[i][i] == flag){
			for(int a=i+1;a<mat->r;a++){
				if(mat->data[a][i] != flag){
					swaprow(mat, a, i);
					swaprow(b, a ,i);
					break;
				}
			}
		}
		for(int j=i+1; j<mat->r; j++){
			wsp = mat->data[j][i]/mat->data[i][i];
			b->data[j][0] -= wsp*b->data[i][0];
			for(int k = 0; k<mat->r; k++){
				mat->data[j][k] -= wsp*mat->data[i][k]; 
			}	
		}
	 }
	return 0;
}

