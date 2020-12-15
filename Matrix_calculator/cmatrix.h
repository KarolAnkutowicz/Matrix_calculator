/********** BEGIN_OF_FILE **********/
/* cmatrix.h */

#ifndef CMATRIX_H
#define CMATRIX_H

#include "constantsandtypes.h"
#include <iostream>

using namespace std;

class cMatrix
{
    typeSize vRows, vColumns;
    double *tableElements;
    bool vIfVector;
    bool vIfMatrixZeros;
    bool vIfMatrixSquare;
    bool vIfMatrixIdentity;
    bool vIfMatrixDiagonal;
    bool vIfMatrixTriangularUpper;
    bool vIfMatrixTriangularLower;
    double vDeterminant;

    inline void setRows(typeSize parRows);
    inline void setColumns(typeSize parColumns);
    void mClearElements();

    inline void mTestVector();
    void mTestMatrixZeros();
    inline void mTestMatrixSquare();
    void mTestMatrixIdentity();
    void mTestMatrixDiagonal();
    void mTestMatrixTriangularUpper();
    void mTestMatrixTraingularLower();
    void mTests();
public:
    cMatrix();
    cMatrix(typeSize parRows, typeSize parColumns);
    cMatrix(typeSize parRows, typeSize parColumns, double *parTabElements);
    cMatrix(const cMatrix &M);
    ~cMatrix();

    inline typeSize getRows();
    inline typeSize getColumns();
    inline typeSize getElement(typeSize parRows, typeSize parColumns);
    inline bool getIfVector();
    inline bool getIfMatrixZeros();
    inline bool getIfMatrixSquare();
    inline bool getIfMatrixIdentity();
    inline bool getIfMatrixDiagonal();
    inline bool getIfMatrixTriangularUpper();
    inline bool getIfMatrixTriangularLower();

    inline void setElement(typeSize parRows, typeSize parColumns, double parValue);

    friend ostream &operator << (ostream &streamOut, cMatrix &M);
    friend istream &operator >> (istream & strIn, cMatrix &M);

    cMatrix &operator = (const cMatrix &M);

    cMatrix operator + (cMatrix M);
    cMatrix operator - (cMatrix M);
    cMatrix operator * (double parFactor);
    cMatrix operator * (cMatrix M);

    inline double mCalculateDeterminant1x1();
    double mCalculateDeterminant2x2();
    double mCalculateDeterminant3x3();
    double mCalculateDeterminantDiagonal();
    double mCalculateDeterminant();

    cMatrix mExponentiationMatrix(typeSize parPower);

    cMatrix mInversalMatrix1x1();
    cMatrix mInversalMatrix2x2();
    cMatrix mInversalMatrix3x3();
    cMatrix mInversalMatrix();

    double mScalarProduct(cMatrix M);
    cMatrix mCrossProduct(cMatrix M);
    double mLengthVector();
};

#endif // CMATRIX_H

/* cmatrix.h */
/********** END_OF_FILE **********/
