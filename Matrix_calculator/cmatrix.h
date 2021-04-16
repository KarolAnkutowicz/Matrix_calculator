/********** BEGIN_OF_FILE **********/
/* cmatrix.h */

#ifndef CMATRIX_H
#define CMATRIX_H

#include "constantsandtypes.h"
#include <iostream>

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
    //cMatrix(const cMatrix &M);

    /*
     * ~cMatrix() - destruktor klasy cMatrix.
     * PRE:
     * - brak.
     * POST:
     * - zwalnianie pamieci przydzielanej dynamicznie.
     */
    ~cMatrix();



    /*
     * typeSize getRows() - metoda zwracajaca liczbe wierszy macierzy.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vRows.
     */
    inline typeSize getRows()
    {
        return vRows;
    }
    /*
     * typeSize getColumns() - metoda zwracajaca liczbe kolumn macierzy
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vColumns.
     */
    inline typeSize getColumns()
    {
        return vColumns;
    }
    /*
     * typeSize getElement(typeSize parRows, typeSize parColumns) -
     * metoda pozwalajaca zmienic wartosc wskazanego elementu tablicy
     * elementow macierzy.
     * PRE:
     * - podanie numeru wiersza (argument: parRows);
     * - podanie numeru kolumny (argument: parColumns).
     * POST:
     * - zwrocenie wartosci z tablicy wedlug wskazanych wspolrzednych.
     */
    inline typeSize getElement(typeSize parRows, typeSize parColumns)
    {
        return tableElements[parRows * vColumns + parColumns];
    }
    /*
     * bool getIfVector() - metoda zwracajaca informacje czy macierz
     * jest wektorem.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfVector.
     */
    inline bool getIfVector()
    {
        return vIfVector;
    }
    /*
     * bool getIfMatrixZeros() - metoda zwracajaca informacje czy
     * macierz jest macierza zerowa.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfMatrixZeros.
     */
    inline bool getIfMatrixZeros()
    {
        return vIfMatrixZeros;
    }
    /*
     * bool getIfMatrixSquare() - metoda zwracajaca informacje czy
     * macierz jest macierza kwadratowa.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfMatrixSquare.
     */
    inline bool getIfMatrixSquare()
    {
        return vIfMatrixSquare;
    }
    /*
     * bool getIfMatrixIdentity() - metoda zwracajaca informacje czy
     * macierz jest macierza jednostkowa.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfMatrixIdentity.
     */
    inline bool getIfMatrixIdentity()
    {
        return vIfMatrixIdentity;
    }
    /*
     * bool getIfMatrixDiagonal() - metoda zwracajaca informacje czy
     * macierz jest macierza diagonalna.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfMatrixDiagonal.
     */
    inline bool getIfMatrixDiagonal()
    {
        return vIfMatrixDiagonal;
    }
    /*
     * bool getIfMatrixTriangularUpper() - metoda zwracajaca informacje
     * czy macierz jest macierza trojkatna gorna.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfMatrixTriangularUpper.
     */
    inline bool getIfMatrixTriangularUpper()
    {
        return vIfMatrixTriangularUpper;
    }
    /*
     * bool getIfMatrixTriangularLower() - metoda zwracajaca informacje
     * czy macierz jest macierza trojkatna dolna.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vIfMatrixTriangularLower.
     */
    inline bool getIfMatrixTriangularLower()
    {
        return vIfMatrixTriangularLower;
    }

    /*
     * void setElement(typeSize parRows, typeSize parColumns, double parValue) -
     * metoda pozwalajaca na ustanowienie nowej wartosci wskazanego
     * elementu tablicy elementow macierzy.
     * PRE:
     * - podanie numeru wiersza (argument: parRows);
     * - podanie numeru kolumny (argument: parColumns);
     * - podanie wartosci (argument: parValue).
     * POST:
     * - brak.
     */
    inline void setElement(typeSize parRows, typeSize parColumns, double parValue)
    {
        tableElements[parRows * vColumns + parColumns] = parValue;
    }



    /*
     * ostream &operator << (ostream &streamOut, cMatrix &M) -
     * przeladowanie operatora wyjscia.
     * PRE:
     * - podanie referancji do obiektu klasy ostream;
     * - podanie referencji do obiektu klasy cMatrix.
     * POST:
     * - zwrocenie strumiena wyjsciowego.
     */

    friend ostream &operator << (ostream &streamOut, cMatrix &M);
    /*
     * istream &operator >> (istream & streamIn, cMatrix &M) -
     * przeladowanie operatora wejjscia.
     * PRE:
     * - podanie referencji do obiektu klasy istream;
     * - podanie referencji do obiektu klasy cMatrix.
     * POST:
     * - zwrocenie strumienia wejsciowego.
     */
    friend istream &operator >> (istream & streamIn, cMatrix &M);

    /*
     * void operator = (const cMatrix &M) - przeladowanie
     * operatora przypisania.
     * PRE:
     * - podanie referencji do obiektu klasy cMatrix.
     * POST:
     * - brak.
     */
    void operator = (const cMatrix &M);



    /*
     * cMatrix operator + (cMatrix M) - przeladowanie operatora
     * dodawania.
     * PRE:
     * - podanie obiektu klasy cMatrix.
     * POST:
     * - wynik dodawania macierzy (typ: cMatrix).
     */
    cMatrix operator + (cMatrix M);

    /*
     * cMatrix operator - (cMatrix M) - przeladowanie operatora
     * odejmowania.
     * PRE:
     * - podanie obiektu klasy cMatrix.
     * POST:
     * - wynik odejmowania macierzy (typ: cMatrix).
     */
    cMatrix operator - (cMatrix M);

    /*
     * cMatrix operator * (double parFactor) - przeladowanie operatora
     * mnozenia (macierz i liczba rzeczywista).
     * PRE:
     * - podanie liczby rzeczywistej (argument: parFactor.
     * POST:
     * - zwrocenie wyniku mnozenia (typ: cMatrix).
     */
    cMatrix operator * (double parFactor);

    /*
     * cMatrix operator * (cMatrix M) - przeladowanie operatora
     * mnozenia (macierz i macierz).
     * PRE:
     * - podanie obiektu klasy cMatrix.
     * POST:
     * - zwrocenie wyniku mnozenia (typ: cMatrix).
     */
    cMatrix operator * (cMatrix M);



    /*
     * double mCalculateDeterminant2x2() - metoda obliczajaca
     * wyznacznik macierzy o wymiarze 2.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: double).
     */
    double mCalculateDeterminant2x2();

    /*
     * double mCalculateDeterminant3x3() - metoda obliczajaca
     * wyznacznik macierzy o wymiarze 3.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: double).
     */
    double mCalculateDeterminant3x3();

    /*
     * double mCalculateDeterminantDiagonal() - metoda obliczajaca
     * wyznacznik macierzy diagonalnej o dowolnym wymiarze wiekszym
     * od 3.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: double).
     */
    double mCalculateDeterminantDiagonal();

    /*
     * double mCalculateDeterminant() - metoda obliczajaca
     * wyznacznik macierzy o dowolnym wymiarze wiekszym od 3.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: double).
     */
    double mCalculateDeterminant();



    /*
     * cMatrix mExponentiationMatrix(typeSize parPower) -
     * metoda obliczajaca potege macierzy.
     * PRE:
     * - podanie potegi (argument: parPower).
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    cMatrix mExponentiationMatrix(typeSize parPower);

    /*
     * cMatrix mInversalMatrix1x1() - metoda wyznaczajaca macierz
     * odwrotna dla macierzy o wymiarze 1.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    cMatrix mInversalMatrix1x1();

    /*
     * cMatrix mInversalMatrix2x2() - metoda wyznaczajaca macierz
     * odwrotna dla macierzy o wymiarze 2.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    cMatrix mInversalMatrix2x2();

    /*
     * cMatrix mInversalMatrix3x3() - metoda wyznaczajaca macierz
     * odwrotna dla macierzy o wymiarze 3.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    cMatrix mInversalMatrix3x3();

    /*
     * cMatrix mInversalMatrix() - metoda wyznaczajaca macierz odwrotna
     * dla macierzy o wymiarze wiekszym niz 3.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    cMatrix mInversalMatrix();



    /*
     * double mScalarProduct(cMatrix M) - metoda wyznaczajaca iloczyn
     * skalarny dwoch wektorow.
     * PRE:
     * - podanie obiektu klasy cMatrix.
     * POST:
     * - zwrocenie wyniku (typ: double).
     */
    double mScalarProduct(cMatrix M);

    /*
     * cMatrix mCrossProduct(cMatrix M) - metoda wyznaczajaca iloczyn
     * wektorowy dwoch wektorow.
     * PRE:
     * - podanie obiektu klasy cMatrix.
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    cMatrix mCrossProduct(cMatrix M);

    /*
     * double mLengthVector() - metoda wyznaczajaca dlugosc wektora.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wyniku (typ: cMatrix).
     */
    double mLengthVector();


/********** PUBLIC: END **********/
};

#endif // CMATRIX_H

/* cmatrix.h */
/********** END_OF_FILE **********/
