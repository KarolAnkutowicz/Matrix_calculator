/********** BEGIN_OF_FILE **********/
/* cmatrix.cpp */

#include "cmatrix.h"

using namespace std;

/********** PRIVATE: BEGINNING **********/

/*
 * void mClearElements()
 */
void cMatrix::mClearElements()
{
    for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
            tableElements[i * vColumns + j] = 0; // wyzerowanie elementu tablicy
}
/*
 * void mCopyTableElements(double parTableElements[])
 */
void cMatrix::mCopyTableElements(double parTableElements[])
{
    for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
            tableElements[i * vColumns + j] = parTableElements[i * vColumns + j]; // skopiowanie wartosci elementu tablicy
}



/*
 * void mTestMatrixZeros()
 */
void cMatrix::mTestMatrixZeros()
{
    vIfMatrixZeros = true; // pierwotne przypisanie wlasciwosci macierzy zerowej
    for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
    {
        for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
        {
            if (tableElements[i * vColumns + i] != 0) // sprawdzenie czy element jest zerem
            {
                vIfMatrixZeros = false; // jesli nie jest zerem to automatycznie macierz nie jest zerowa
                break;
            }
        }
    }
}

/*
 * void mTestMatrixIdentity()
 */
void cMatrix::mTestMatrixIdentity()
{
    if (vIfMatrixSquare != true) // jesli macierz nie jest kwadratowa to nie moze byc jednostkowa
        vIfMatrixIdentity = false;
    else if (vIfMatrixZeros == true) // jesli macierz jest macierza zerowa to nie moze byc jednostkowa
        vIfMatrixIdentity = false;
    else
    {
        vIfMatrixIdentity = true; // pierwotne przypisanie wlasciwosci macierzy jednostkowej
        for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
        {
            for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
            {
                if ((i == j) && (tableElements[i * vColumns + j] != 1)) // sprawdzenie elementow na glownej przekatnej
                {
                    vIfMatrixIdentity = false; // zmiana wlasciwosci obiektu
                    break;
                }
                if ((i != j) && (tableElements[i * vColumns + j] != 0)) // sprawdzenie elementowa poza glowna przekatna
                {
                    vIfMatrixIdentity = false; // zmiana wlasciwosci obiektu
                    break;
                }
            }
        }
    }
}

/*
 * void mTestMatrixDiagonal()
 */
void cMatrix::mTestMatrixDiagonal()
{
    if (vIfMatrixSquare != true) // jesli macierz nie jest kwadratowa to nie moze byc diagonalna
        vIfMatrixDiagonal = false;
    else if (vIfMatrixZeros == true) // jesli macierz jest macierza zerowa to nie moze byc diagonalna
        vIfMatrixDiagonal = false;
    else if (vIfMatrixIdentity == true) // jesli macierz jest jednostkowa to jest automatycznie diagonalna
        vIfMatrixDiagonal = true;
    else
    {
        vIfMatrixDiagonal = true; // pierwotne przypisanie wlasciwosci macierzy jednostkowej
        for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
        {
            for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
            {
                if ((i == j) && (tableElements[i * vColumns + j] == 0)) // sprawdzenie elementow na glownej przekatnej
                {
                    vIfMatrixDiagonal = false; // zmiana wlasciwosci obiektu
                    break;
                }
                if ((i != j) && (tableElements[i * vColumns + j] != 0)) // sprawdzenie elementowa poza glowna przekatna
                {
                    vIfMatrixDiagonal = false; // zmiana wlasciwosci obiektu
                    break;
                }
            }
        }
    }
}

/*
 * void mTestMatrixTriangularUpper()
 */
void cMatrix::mTestMatrixTriangularUpper()
{
    if (vIfMatrixSquare != true) // jesli macierz nie jest kwadratowa to nie moze byc trojkatna gorna
        vIfMatrixTriangularUpper = false;
    else if (vIfMatrixZeros == true) // jesli macierz jest macierza zerowa to nie moze byc trojkatna gorna
        vIfMatrixTriangularUpper = false;
    else if (vIfMatrixIdentity == true) // jesli macierz jest jednostkowa to nie moze byc trojkatna gorna
        vIfMatrixTriangularUpper = false;
    else if (vIfMatrixDiagonal == true) // jesli macierz jest diagonalna to nie moze byc trojkatna gorna
        vIfMatrixTriangularUpper = false;
    else
    {
        vIfMatrixTriangularUpper = true; // pierwotne przypisanie wlasciwosci do obiektu
        for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
        {
            for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
            {
                if ((i > j) && (tableElements[i * vColumns + j] != 0)) // sprawdzenie elementow ponizej glownej przekatnej
                {
                    vIfMatrixTriangularUpper = false; // zmiana wlasciwosci obiektu
                    break;
                }
                if ((i <= j) && (tableElements[i * vColumns + j] == 0)) // sprawdzenie elementow na glownej przekatnej i powyzej niej
                {
                    vIfMatrixTriangularUpper = false; // zmiana wlasciwosci obiektu
                    break;
                }
            }
        }
    }
}

/*
 * void mTestMatrixTraingularLower()
 */
void cMatrix::mTestMatrixTraingularLower()
{
    if (vIfMatrixSquare != true) // jesli macierz nie jest kwadratowa to nie moze byc trojkatna dolna
        vIfMatrixTriangularLower = false;
    else if (vIfMatrixZeros == true) // jesli macierz jest macierza zerowa to nie moze byc trojkatna dolna
        vIfMatrixTriangularLower = false;
    else if (vIfMatrixIdentity == true) // jesli macierz jest jednostkowa to nie moze byc trojkatna dolna
        vIfMatrixTriangularLower = false;
    else if (vIfMatrixDiagonal == true) // jesli macierz jest diagonalna to nie moze byc trojkatna dolna
        vIfMatrixTriangularLower = false;
    else if (vIfMatrixTriangularUpper == true) // jesli macierz jest trojkatna gorna to nie moze byc trojkatna dolna
        vIfMatrixTriangularLower = false;
    else
    {
        vIfMatrixTriangularLower = true; // pierwotne przypisanie wlasciwosci do obiektu
        for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
        {
            for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
            {
                if ((i < j) && (tableElements[i * vColumns + j] != 0)) // sprawdzenie elementow powyzej glownej przekatnej
                {
                    vIfMatrixTriangularLower = false; // zmiana wlasciwosci obiektu
                    break;
                }
                if ((i >= j) && (tableElements[i * vColumns + j] == 0)) // sprawdzenie elementow na glownej przekatnej i ponizej niej
                {
                    vIfMatrixTriangularLower = false; // zmiana wlasciwosci obiektu
                    break;
                }
            }
        }
    }
}

/*
 * void mTests()
 */
void cMatrix::mTests()
{
    mTestVector(); // wywolanie metody sprawdzajacej czy macierz jest wektorem
    mTestMatrixZeros(); // wywolanie metody sprawdzajacej czy macierz jest zerowa
    mTestMatrixSquare(); // wywolanie metody sprawdzajacej czy macierz jest kwadratowa
    mTestMatrixIdentity(); // wywolanie metody sprawdzajacej czy macierz jest jednostkowa
    mTestMatrixDiagonal(); // wywolanie metody sprawdzajacej czy macierz jest diagonalna
    mTestMatrixTriangularUpper(); // wywolanie metody sprawdzajacej czy macierz jest trojkatna gorna
    mTestMatrixTraingularLower(); // wywolanie metody sprawdzajacej czy macierz jest trojkatna dolna
}


/********** PRIVATE: END **********/

/********** PUBLIC: BEGINNING **********/

/*
 * cMatrix()
 */
cMatrix::cMatrix()
{
    vRows = vColumns = 1; // ustanowienie rozmiaru macierzy
    mClearElements(); // "wyzerowanie" elementow
    mTests(); // sprawdzenie wlasciwosci macierzy
    vDeterminant = 0; // ustanowienie wyznacznika
}

/*
 * cMatrix(typeSize parColumns)
 */
cMatrix::cMatrix(typeSize parColumns)
{
    vRows = 1; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    mClearElements(); // "wyzerowanie" elementow
    mTests(); // sprawdzenie wlasciwosci macierzy
    vDeterminant = 0; // ustanowienie wyznacznika (jedynie dla porzadku)
}

/*
 * cMatrix(typeSize parColumns, double *parTabElements)
 */
cMatrix::cMatrix(typeSize parColumns, double parTabElements[])
{
    vRows = 1; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    mCopyTableElements(parTabElements); // skopiowanie zawartosci tablicy
    mTests(); // sprawdzenie wlasciwosci macierzy
    if (vIfMatrixSquare)
        vDeterminant = getElement(0, 0); // ustanowienie wlasciwego wyznacznika
    else
        vDeterminant = 0; // ustanowienie wyznacznika (jedynie dla porzadku)
}

/*
 * cMatrix(typeSize parRows, typeSize parColumns)
 */
cMatrix::cMatrix(typeSize parRows, typeSize parColumns)
{
    vRows = parRows; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    mClearElements(); // "wyzerowanie" elementow
    mTests(); // sprawdzenie wlasciwosci macierzy
    vDeterminant = 0; // ustanowienie wartosci wyznacznika (dla porzadku)
}

/*
 * cMatrix(typeSize parRows, typeSize parColumns, double *parTabElements)
 */
cMatrix::cMatrix(typeSize parRows, typeSize parColumns, double parTabElements[])
{
    vRows = parRows; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    mCopyTableElements(parTabElements); // skopiowanie zawartosci tablicy
    mTests(); // sprawdzenie wlasciwosci macierzy
    /*if (vIfMatrixSquare)
        vDeterminant = ...
    else*/
        vDeterminant = 0; // ustanowienie wartosci wyznacznika (jedynie dla porzadku)
}

/*
 * cMatrix(const cMatrix &M)
 */
/*cMatrix::cMatrix(const cMatrix &M)
{
}*/

/*
 * ~cMatrix()
 */
cMatrix::~cMatrix()
{
    delete []tableElements; // zwolnienie zasobow przydzielanych dynamicznie
}

/********** PUBLIC: END **********/

/* cmatrix.cpp */
/********** END_OF_FILE **********/
