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

    /*
     * double vDeterminant - pole przechowujace wartosc wyznacznika
     * (jesli istnieje)
     */
    double vDeterminant;



    /*
     * void setRows(typeSize parRows) - metoda umozliwiajaca zmiane
     * liczby wierszy w tablicy elementow macierzy.
     * PRE:
     * - podanie nowej liczby wierszy (argument: parRows).
     * POST:
     * - brak.
     */
    inline void setRows(typeSize parRows)
    {
        vRows = parRows;
    }

    /*
     * void setColumns(typeSize parColumns) - metoda umozliwiajaca
     * zmiane liczby kolumn w tablicy elementow macierzy.
     * PRE:
     * - podanie nowej liczby kolumn (argument: parColumns).
     * POST:
     * - brak.
     */
    inline void setColumns(typeSize parColumns)
    {
        vColumns = parColumns;
    }



    /*
     * void mClearElements() - metoda "zerujaca" wszystkie elementy
     * macierzy.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearElements();

    /*
     * void mCopyTableElements(double parTableElements[]) -
     * metopa kopiujaca zawartosc tablicy zadanej jako parametr do tablicy
     * elementow macierzy.
     * PRE:
     * - podanie tablicy elementow (atrgument: parTableElements[).
     * POST:
     * - brak.
     */
    void mCopyTableElements(double parTableElements[]);



    /*
     * void mTestVector() - metoda sprawdzajaca czy macierz jest
     * wektorem.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    inline void mTestVector()
    {
        ((vRows == 1) || (vColumns == 1)) ? vIfVector = true : vIfVector = false;
    }

    /*
     * void mTestMatrixZeros() - metoda sprawdzajaca czy macierz jest
     * macierza zerowa.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mTestMatrixZeros();

    /*
     * void mTestMatrixSquare() - metoda sprawdzajaca czy macierz jest
     * macierza kwadratowa.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    inline void mTestMatrixSquare()
    {
        (vRows == vColumns) ? vIfMatrixSquare = true : vIfMatrixSquare = false;
    }

    /*
     * void mTestMatrixIdentity() - metoda sprawdzajaca czy macierz
     * jest macierza jednostkowa.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mTestMatrixIdentity();

    /*
     * void mTestMatrixDiagonal() - metoda sprawdzajaca czy macierz
     * jest macierza diagonalna.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mTestMatrixDiagonal();

    /*
     * void mTestMatrixTriangularUpper() - metoda sprawdzajaca czy
     * macierz jest macierza trojkatna gorna.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mTestMatrixTriangularUpper();

    /*
     * void mTestMatrixTraingularLower() - metoda sprawdzajaca czy
     * macierz jest macierza trojkatna dolna.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mTestMatrixTraingularLower();

    /*
     * void mTests() - metoda wywolujaca kolejne metody sprawdzajace
     * cechy macierzy.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mTests();

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

    /*
     * cMatrix(typeSize parColumns) - konstruktor wywo³ywany z jednym
     * parametrem - jednym wymniarem macierzy. Efektem jest utworzenie
     * macierzy o jednym wierszu (wektor poziomy).
     * PRE:
     * - podanie liczby kolumn (argument: parColumns).
     * POST:
     * -utworzenie obiektu.
     */
    cMatrix(typeSize parColumns);

    /*
     * cMatrix(typeSize parColumns, double *parTabElements) -
     * konstruktor wywolywany z dwoma parametrami: liczba kolumn
     * (zatem jest to wektor) oraz tablica liczb.
     * PRE:
     * - podanie liczby kolumn (argument: parColumns);
     * - podanie wartosci kolejnych elementow (argument: *parTabElements).
     * POST:
     * - utworzenie obiektu.
     */
    cMatrix(typeSize parColumns, double *parTabElements);

    /*
     * cMatrix(typeSize parRows, typeSize parColumns) - konstruktor
     * wywolywany z dwoma parametrami - wymiarami macierzy.
     * PRE:
     * - podanie liczby wierszy (argument: parRows);
     * - podanie liczby kolumn (argument: parColumns).
     * POST:
     * - utworzenie obiektu.
     */
    cMatrix(typeSize parRows, typeSize parColumns);

    /*
     * cMatrix(typeSize parRows, typeSize parColumns, double *parTabElements) -
     * konstruktor wywolywany z trzema parametrami - wymiarami
     * macierzy oraz tablica elementow.
     * PRE:
     * - podanie liczby wierszy (argument: parRows);
     * - podanie liczby kolumn (argument: parColumns);
     * - podanie wartosci kolejnych elementow (argument: *parTabElements).
     * POST:
     * - utworzenie obiektu.
     */
    cMatrix(typeSize parRows, typeSize parColumns, double *parTabElements);

    /*
     * cMatrix(const cMatrix &M) - konstruktor kopiujacy.
     * PRE:
     * - brak.
     * POST:
     * - utworzenie obiektu.
     */

    cMatrix(const cMatrix &M);
    /*
     * ~cMatrix() - destruktor klasy cMatrix.
     * PRE:
     * - brak.
     * POST:
     * - zwalnianie pamieci przydzielanej dynamicznie.
     */
    ~cMatrix();






/********** PUBLIC: END **********/
};

#endif // CMATRIX_H

/* cmatrix.h */
/********** END_OF_FILE **********/
