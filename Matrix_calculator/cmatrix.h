/********** BEGIN_OF_FILE **********/
/* cmatrix.h */

#ifndef CMATRIX_H
#define CMATRIX_H

#include "constantsandtypes.h"

using namespace std;

class cMatrix
{
/********** PRIVATE: BEGINNING **********/

    /*
     * vRows, vColumns - pola przechowujace wymiary macierzy
     */
    typeSize vRows, vColumns;

    /*
     * *tableElements - tablica elementow macierzy
     */
    double *tableElements;

    /*
     * vIfVector - pole przechowujaca informacje czy macierz
     * jest wektorem
     */
    bool vIfVector;

    /*
     * vIfMatrixZeros - pole przechowujace informacje czy macierz
     * jest macierza zerowa
     */
    bool vIfMatrixZeros;

    /*
     * vIfMatrixSquare - pole przechowujace informacje czy macierz
     * jest kwadratowa
     */
    bool vIfMatrixSquare;

    /*
     * vIfMatrixIdentity - pole przechowujace informacje czy macierz
     * jest jednostkowa
     */
    bool vIfMatrixIdentity;

    /*
     * vIfMatrixDiagonal - pole przechowujace informacje czy macierz
     * jest diagonalna
     */
    bool vIfMatrixDiagonal;

    /*
     * vIfMatrixTriangularUpper - pole przechowujace informacje czy
     * macierz jest macierza trojkatna gorna
     */
    bool vIfMatrixTriangularUpper;

    /*
     * vIfMatrixTriangularLower - pole przechowujace informacje czy
     * macierz jest macierza trojkatna dolna
     */
    bool vIfMatrixTriangularLower;

/********** PRIVATE: END **********/

/********** PUBLIC: BEGINNING **********/
public:
    /*
     * cMatrix() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak.
     * POST:
     * - utworzenie obiektu.
     */
    cMatrix();

/********** PUBLIC: END **********/
};

#endif // CMATRIX_H

/* cmatrix.h */
/********** END_OF_FILE **********/
