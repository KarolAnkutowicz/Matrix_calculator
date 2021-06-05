/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cmatrix.cpp
 */

#include "cexceptionsanderrors.h"
#include "cmatrix.h"
#include "constantsandtypes.h"
#include <cmath>
#include <iostream>

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
    tableElements = new double[vRows * vColumns];
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
    tableElements = new double[vRows * vColumns];
    mClearElements(); // "wyzerowanie" elementow
    mTests(); // sprawdzenie wlasciwosci macierzy
    vDeterminant = 0; // ustanowienie wyznacznika (jedynie dla porzadku)
}

/*
 * cMatrix(typeSize parColumns, double *parTabElements)
 */
/*cMatrix::cMatrix(typeSize parColumns, double parTabElements[])
{
    vRows = 1; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    tableElements = new double[vRows * vColumns];
    mCopyTableElements(parTabElements); // skopiowanie zawartosci tablicy
    mTests(); // sprawdzenie wlasciwosci macierzy
    if (vIfMatrixSquare)
        vDeterminant = getElement(0, 0); // ustanowienie wlasciwego wyznacznika
    else
        vDeterminant = 0; // ustanowienie wyznacznika (jedynie dla porzadku)
}*/

/*
 * cMatrix(typeSize parRows, typeSize parColumns)
 */
cMatrix::cMatrix(typeSize parRows, typeSize parColumns)
{
    vRows = parRows; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    tableElements = new double[vRows * vColumns];
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
    tableElements = new double[vRows * vColumns];
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



/*
 * ostream &operator << (ostream &streamOut, cMatrix &M)
 */
ostream &operator << (ostream &streamOut, cMatrix &M)
{
    streamOut << startOfMatrix; // wypisanie znaku pocz¹tku macierzy
    for (typeSize i = 0; i < M.getRows(); i++) // przejœcie przez wszystkie wiersze
    {
        streamOut << startOfRow; // wypisanie znaku pocz¹tku wiersza
        for (typeSize j = 0; j < M.getColumns(); j++) // przejœcie przez wszystkie kolumny
        {
            streamOut << M.tableElements[i * M.getColumns() + j]; // wypisanie wartoœci elementu
            if (j < (M.getColumns() - 1)) // warunek wypisania separatora pomiêdzy elementami danego wiersza
                streamOut << separatorElement; // wypisanie separatora
        }
        streamOut << endOfRow; // wypisanie znaku koñca wiersza
        if (i < (M.getRows() - 1)) // warunek przejœcia do nowej linii
            streamOut << endl; // przejœcie do nowej linii
    }
    streamOut << endOfMatrix << endl; // wypisanie znaku koñca macierzy
    return streamOut; // zwrócenie strumienia
}

/*
 *  istream &operator >> (istream & streamIn, cMatrix &M)
 */
istream &operator >> (istream & streamIn, cMatrix &M)
{
    char c; // deklaracja znaku
    typeSize rows = 0, separator = 0, columns; // deklaracje i definicje zmiennych potrzebnych do wyznaczenia wymiarów macierzy
    double *tabElem, *tabElemAux; // deklaracja wskaŸników do tablic: g³ównej i pomocniczej
    tabElem = new double[1]; // stworzenie nowej tablicy g³ównej
    streamIn >> c; // wczytanie znaku
    if (c == startOfMatrix) // sprawdzenie warunku wczytania znaku pocz¹tku macierzy
    {
        do
        {
            streamIn >> c; // wczytanie znaku
            if (c == startOfRow) // sprawdzenie warunku wczytania znaku pocz¹tku wiersza
            {
                rows++; // zwiêkszenie siê liczby wierszy
                do
                {
                    tabElemAux = new double[rows + separator]; // stworzenie nowej, powiêkszonej tablicy pomocniczej
                    for (typeSize i = 0; i < ((rows + separator) - 1); i++) // przejœcie przez wszystkie elementy tablicy g³ównej
                        tabElemAux[i] = tabElem[i]; // przypisanie elementów do tablicy pomocniczej
                    delete []tabElem; // destrukcja tablicy g³ównej
                    tabElem = new double[rows + separator]; // stworzenie nowej, powiêkszonej tablicy g³ównej
                    for (typeSize i = 0; i < ((rows + separator) - 1); i++) // przejœcie przez wszystkie elementy tablicy pomocniczej
                        tabElem[i] = tabElemAux[i]; // przypisanie elementów do tablicy g³ównej
                    delete []tabElemAux; // destrukcja tablicy pomocniczej
                    streamIn >> tabElem[rows + separator - 1]; // wczytanie nowego elementu do g³ównej tablicy
                    streamIn >> c; // wczytanie znaku
                    if (c == separatorElement) // sprawdzenie warunku wczytania separatora
                        separator++; // zwiêkszenie siê liczby separatorów
                } while (c != endOfRow); // sprawdzenie warunku wczytanie znaku koñca wiersza
            }
        } while (c != endOfMatrix); // sprawdzenie warunku wczytania znaku koñca macierzy
    }
    columns = (rows + separator) / rows; // wyznaczenie liczby kolumn macierzy
    M.setRows(rows); // ustawienie liczby wierszy
    M.setColumns(columns); // ustawienie liczby kolumn
    M.tableElements = new double[rows * columns]; // stworzenie nowej tablicy elementów
    for (typeSize i = 0; i < (rows * columns); i++) // przejœcie przez wszystkie elementy
        M.tableElements[i] = tabElem[i]; // przypisanie wartoœci do tablicy obiektu
    M.mTests(); // okreœlenie parametrów macierzy
    return streamIn; // zwrócenie strumienia
}

/*
 * void operator = (cMatrix M)
 */
void cMatrix::operator = (cMatrix M)
{
    setRows(M.getRows()); // ustawienie liczby wierszy
    setColumns(M.getColumns()); // ustawienie liczby kolumn
    tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
    for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich elemantach
            tableElements[i * getColumns() + j] = M.getElement(i, j); // kopiowanie elementu
    mTests(); // sprawdzenie wlasciwosci macierzy
}



/*
 * cMatrix operator + (cMatrix M)
 */
cMatrix cMatrix::operator + (cMatrix M)
{
    if ((getRows() == M.getRows()) && (getColumns() == M.getColumns())) // s[rawdzenie czy macierz maja te same wymiary
    {
        cMatrix Result(getRows(), getColumns()); // utworzenie macierzy wynikowej
        for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
            for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
                Result.setElement(i, j, getElement(i, j) + M.getElement(i, j)); // obliczanie kolejnych elementow
        Result.mTests(); // sprawdzenie wlasciwosci macierzy
        return Result; // zwrocenie wyniku
    }
    else // macierze maja rozne wymiary
    {
        // !!! Rozne wymiary macierzy
        cMatrix Result; // utworzenie fikcyjnej macierzy wynikowej
        return Result; // zwrocenie fikcyjnej macierzy wynikowej
    }
}

/*
 * cMatrix operator - (cMatrix M)
 */
cMatrix cMatrix::operator - (cMatrix M)
{
    if ((getRows() == M.getRows()) && (getColumns() == M.getColumns())) // s[rawdzenie czy macierz maja te same wymiary
    {
        cMatrix Result(getRows(), getColumns()); // utworzenie amcierzy wynikowej
        for (typeSize i = 0; i < vRows; i++) // przejscie po wszystkich wierszach
            for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich kolumnach
                Result.setElement(i, j, getElement(i, j) - M.getElement(i, j)); // obliczanie kolejnych elementow
        Result.mTests(); // sprawdzenie wlasciwosci macierzy
        return Result; // zwrocenie wyniku
    }
    else // macierza maja rozne wymiary
    {
        // !!! Rozne wymiary macierzy
        cMatrix Result; // utworzenie fikcyjnej macierzy wynikowej
        return Result; // zwrocenie fikcyjnej macierzy wynikowej
    }
}

/*
 * cMatrix operator * (double parFactor)
 */
cMatrix cMatrix::operator * (double parFactor)
{
    cMatrix Result(getRows(), getColumns()); // utworzenie macierzy wynikowej
    for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich kolumnach
            Result.setElement(i, j, getElement(i, j) * parFactor); // obliczanie kolejnych elementow
    Result.mTests(); // sprawdzenie wlasciwosci macierzy
    return Result; // zwrocenie wyniku
}

/*
 * cMatrix operator * (cMatrix M)
 */
cMatrix cMatrix::operator * (cMatrix M)
{
    if (getColumns() == M.getRows()) // sprawdzenie czy macierze maja odpowiednie wymiary
    {
        cMatrix Result(getRows(), M.getColumns()); // utworzenie obiektu wynikowego
        Result.tableElements = new double[getRows() * M.getColumns()]; // utworzenie nowej tablicy elementow
        for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
        {
            double sum; // utworzenie obiektu wynikowego
            for (typeSize j = 0; j < M.getColumns(); j++) // przejscie po wszystkich kolumnach
            {
                sum = 0.0; // nadanie sumy poczatkowej
                for (typeSize k = 0; k < getColumns(); k++) // przejscie przez wszystkie iloczyny
                    sum += (getElement(i, k) * M.getElement(k, j)); // sumowanie kolejnych iloczynow
                Result.setElement(i, j, sum); // ustawienie wartosci elementu macierzy wynikowej
            }
        }
        return Result; // zwrocenie wyniku
    }
    else // macierze jednak nie pasuja wymiarami
    {
        // !!! Macierze maja niepasujace wymiary
        cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
        return Result; // zwrocenie fikcyjnego wyniku
    }
}



/*
 * void mCalculateDeterminant2x2()
 */
void cMatrix::mCalculateDeterminant2x2()
{
    if ((getRows() == 2) && (getColumns() == 2)) // sprawdzenie wymiarow macierzy
        vDeterminant = getElement(0, 0) * getElement(1, 1) - getElement(1, 0) * getElement(0, 1); // obliczenie wyniku
    else // dzialanie dla niepoprawnych wymiarow macierzy
    {
        // !!! Macierz ma nieprawidlowe wymiary
        vDeterminant = 0.0; // ustanowienie fikcyjnego wyniku
    }
}

/*
 * void mCalculateDeterminant3x3()
 */
void cMatrix::mCalculateDeterminant3x3()
{
    if ((getRows() == 3) && (getColumns() == 3)) // sprawdzenie wymiarow macierzy
    {
        vDeterminant = getElement(0, 0) * getElement(1, 1) * getElement(2, 2)
                     + getElement(0 ,1) * getElement(1, 2) * getElement(2, 0)
                     + getElement(0, 2) * getElement(1, 0) * getElement(2, 1)
                     - getElement(0, 2) * getElement(1, 1) * getElement(2, 0)
                     - getElement(0, 1) * getElement(1, 0) * getElement(2, 2)
                     - getElement(0, 0) * getElement(1, 2) * getElement(2, 1); // obliczenie wyniku
    }
    else // dzialanie dla niepoprawnych wymiarow macierzy
    {
        // !!! Macierz ma nieprawidlowe wymiary
        vDeterminant = 0.0; // ustanowienie fikcyjnego wyniku
    }
}

/*
 * void mCalculateDeterminantDiagonal()
 */
void cMatrix::mCalculateDeterminantDiagonal()
{
    vDeterminant = 1.0;
    for (typeSize i = 0; i < getRows(); i++)
        vDeterminant *= getElement(i, i);
}

/*
 * void mCalculateDeterminant()
 */
/*void cMatrix::mCalculateDeterminant()
{
}*/



/*
 * cMatrix mExponentiationMatrix(typeSize parPower)
 */
/*cMatrix cMatrix::mExponentiationMatrix(typeSize parPower)
{
}*/

/*
 * cMatrix mInversalMatrix1x1()
 */
cMatrix cMatrix::mInversalMatrix1x1()
{
    if ((getRows() == 1) && (getColumns() == 1)) // sprawdzenie czy macierz ma wymiary 1 na 1
    {
        if (getDeterminant() != 0) //  sprawdzenie czy wyznacznik jest rozny od '0'
        {
            cMatrix Result(getRows(), getColumns()); // utworzenie obiektu wynikowego
            Result.tableElements = new double[1]; // utworzenie nowej tablicy elementow
            Result.setElement(0, 0, 1 / getElement(0, 0)); // ustanowienie wartosci jedynego elementu tablicy
            return Result; // zwrocenie wyniku
        }
        else // jednak wyznacznik jest '0'
        {
            // !!! Wyznacznik jest rowny zero
            cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
            return Result; // zwrocenie fikcyjnego wyniku
        }
    }
    else // macierz ma jednak niepoprawne wymiary
    {
        // !!! Macierz ma niepoprawne wymiary
        cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
        return Result; // zwrocenie fikcyjnego wyniku
    }
}

/*
 * cMatrix mInversalMatrix2x2()
 */
cMatrix cMatrix::mInversalMatrix2x2()
{
    if ((getRows() == 2) && (getColumns() == 2)) // sprawdzenie czy macierz ma wymiary 2 na 2
    {
        if (getDeterminant() != 0) //  sprawdzenie czy wyznacznik jest rozny od '0'
        {
            cMatrix Result(getRows(), getColumns()); // utworzenie obiektu wynikowego
            Result.tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
            Result.setElement(0, 0, getElement(1, 1)/getDeterminant()); // ustanowienie wartosci kolejnych elementow
            Result.setElement(0, 1, getElement(1, 0)/getDeterminant());
            Result.setElement(1, 0, getElement(0, 1)/getDeterminant());
            Result.setElement(1, 1, getElement(0, 0)/getDeterminant());
            return Result; // zwrocenie wyniku
        }
        else // jednak wyznacznik jest '0'
        {
            // !!! Wyznacznik jest rowny zero
            cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
            return Result; // zwrocenie fikcyjnego wyniku
        }
    }
    else // macierz ma jednak niepoprawne wymiary
    {
        // !!! Macierz ma niepoprawne wymiary
        cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
        return Result; // zwrocenie fikcyjnego wyniku
    }
}

/*
 * cMatrix mInversalMatrix3x3()
 */
/*cMatrix cMatrix::mInversalMatrix3x3()
{
}*/

/*
 * cMatrix mInversalMatrix()
 */
/*cMatrix cMatrix::mInversalMatrix()
{
}*/



/*
 * double mScalarProduct(cMatrix M)
 */
double cMatrix::mScalarProduct(cMatrix M)
{
    if ((getIfVector() == true) && (M.getIfVector() == true)) // sprawdzenie czy argumantami sa wektory
    {
        if ((getRows() == M.getRows()) && (getColumns() == M.getColumns())) // sprawdzenie czy wektory maja identyczne wymiary
        {
            double sum = 0.0; // ustanowienie sumy poczatkowej
            for (typeSize i = 0; i < getColumns(); i++) // przejscie przez wszystkie elementy obu wektorow
                sum += (getElement(1, i) * M.getElement(1, i)); // dodawanie kolejnych iloczynow do wyniku
            return sum; // zwrocenie wyniku
        }
        else // jednak wektory maja rozne wymiary
        {
            // !!! Wektory maja rozne wymiary
            double sum = 0.0; // ustanowienie fikcyjnej sumy poczatkowej
            return sum; // zwrocenie fikcyjnego wyniku
        }
    }
    else // co najmniej jeden z argumentow nie jest wektorem
    {
        // !!! Co najmniej jeden z argumentow nie jest wektorem
        double sum = 0.0; // ustanowienie fikcyjnej sumy poczatkowej
        return sum; // zwrocenie fikcyjnego wyniku
    }
}

/*
 * cMatrix mCrossProduct(cMatrix M)
 */
cMatrix cMatrix::mCrossProduct(cMatrix M)
{
    if ((getIfVector() == true) && (M.getIfVector() == true)) // sprawdzenie czy argumantami sa wektory
    {
        cMatrix Result(1, getColumns());
        if (getColumns() > 2)
        {
            Result.tableElements = new double[getColumns()];
            for (typeSize i = 0; i < getColumns(); i++)
            {
                typeSize a = i + 1;
                if (a >= getColumns())
                    a -= getColumns();
                typeSize b = i + 2;
                if (b >= getColumns())
                    b -= getColumns();
                typeSize c = i + getColumns() - 1;
                if (c >= getColumns())
                    c -= getColumns();
                typeSize d = i + getColumns() - 2;
                if (d >= getColumns())
                    d -= getColumns();
                Result.setElement(1, i, (getElement(1, a) * M.getElement(1, b) - getElement(1, c) * M.getElement(1, d)));
            }
        }
        return Result;
    }
    else // co najmniej jeden z argumentow nie jest wektorem
    {
        // !!! Co najmniej jeden z argumentow nie jest wektorem
        cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
        return Result; // zwrocenie fikcyjnego wyniku
    }
}

/*
 * double mLengthVector()
 */
double cMatrix::mLengthVector()
{
    if (vIfVector)
    {
        double vSum = 0.0; // ustanowienie sumy poczatkowej
        if (getColumns() == 1) // obliczenia dla wektora pionowego
        {
            for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich elementach
                vSum += (getElement(i, 0) * getElement(i, 0)); // dodanie kwadratow kolejnych elementow
        }
        else // obliczenia dla wektora poziomego
        {
            for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich elementach
                vSum += (getElement(0, j) * getElement(0, j)); // dodanie kwadratow kolejnych elementow
        }
        vSum = sqrt(vSum); // obliczenie pierwiastka z sumy kwadratow
        return vSum; // zwrocenie wyniku
    }
    else
    {
        // !!! Macierz nie jest wektorem
        return 0.0; // zwrocenie fikcyjnego wyniku
    }
}

/*
 * cMatrix mTransposition()
 */
cMatrix cMatrix::mTransposition()
{
    cMatrix M(getColumns(), getRows()); // utworzenie nowej macierzy
    M.tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
    for (typeSize i = 0; i < M.getRows(); i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < M.getColumns(); j++) // przejscie po wszystkich kolumnach
            M.setElement(i, j, getElement(j, i)); // przypisanie elementow
    M.mTests(); // ustalanie wlasnosci macierzy
    return M; // zwrocenie macierzy
}





/********** PUBLIC: END **********/

/* cmatrix.cpp */
/********** END_OF_FILE **********/
