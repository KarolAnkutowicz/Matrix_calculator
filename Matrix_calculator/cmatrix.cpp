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
    tableElements = new double[vRows * vColumns]; // utworzenie nowej tablic elementow
    mClearElements(); // "wyzerowanie" elementow
    mTests(); // sprawdzenie wlasciwosci macierzy
    vDeterminant = 0.0; // ustanowienie wyznacznika
}

/*
 * cMatrix(typeSize parColumns)
 */
cMatrix::cMatrix(typeSize parColumns)
{
    vRows = 1; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    tableElements = new double[vRows * vColumns]; // utworzenie nowej tablicy elementow
    mClearElements(); // "wyzerowanie" elementow
    mTests(); // sprawdzenie wlasciwosci macierzy
    if (vRows == vColumns) // sprawdzenie czy macierz jest kwadratowa
        vDeterminant = getElement(0, 0); // jesli tak to jedyny element jedt rowniez wyznacznikiem
    else // jesli macierz nie jest kwadratowa
        vDeterminant = 0.0; // ustanowienie wyznacznika (jedynie dla porzadku)
}

/*
 * cMatrix(typeSize parRows, typeSize parColumns)
 */
cMatrix::cMatrix(typeSize parRows, typeSize parColumns)
{
    vRows = parRows; // ustanowienie liczby wierszy
    vColumns = parColumns; // ustanowienie liczby kolumn
    tableElements = new double[vRows * vColumns]; // utworzenie nowej tablicy elementow
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
    tableElements = new double[vRows * vColumns]; // utworzenie nowej tablicy elementow
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
cMatrix::cMatrix(const cMatrix &M)
{
    setRows(M.vRows); // ustawienie liczby wierszy
    setColumns(M.vColumns); // ustawienie liczby kolumn
    tableElements = new double[M.vRows * M.vColumns]; // utworzenie nowej tablicy elementow
    for (typeSize i = 0; i < M.vRows; i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich elemantach
            setElement(i, j, M.tableElements[i * vColumns + j]); // kopiowanie wartosci elementu
    mTests(); // sprawdzenie wlasciwosci macierzy
    vDeterminant = M.vDeterminant; // skopiowanie wartosci wyznacznika
}


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
cMatrix& cMatrix::operator = (const cMatrix &M)
{
    delete []tableElements;
    setRows(M.vRows); // ustawienie liczby wierszy
    setColumns(M.vColumns); // ustawienie liczby kolumn
    tableElements = new double[M.vRows * M.vColumns]; // utworzenie nowej tablicy elementow
    for (typeSize i = 0; i < M.vRows; i++) // przejscie po wszystkich wierszach
        for (typeSize j = 0; j < vColumns; j++) // przejscie po wszystkich elemantach
            //tableElements[i * getColumns() + j] = M.getElement(i, j); // kopiowanie elementu
            setElement(i, j, M.tableElements[i * vColumns + j]);
    mTests(); // sprawdzenie wlasciwosci macierzy
    return *this;
}



/*
 * cMatrix operator + (cMatrix M)
 */
cMatrix cMatrix::operator + (cMatrix M)
{
    if ((getRows() == M.getRows()) && (getColumns() == M.getColumns())) // sprawdzenie czy macierz maja te same wymiary
    {
        cMatrix Result(getRows(), getColumns()); // utworzenie macierzy wynikowej
        Result.tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
        for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
            for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich kolumnach
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
        Result.tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
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
    if (getIfMatrixSquare())
    {
        if ((getIfMatrixIdentity() == true) || (getIfMatrixDiagonal() == true) || (getIfMatrixTriangularUpper() == true) || (getIfMatrixTriangularLower() == true)) // sprawdzenie wlasciwosci macierzy
        {
            vDeterminant = 1.0; // nadanie wartosci poczatkowej
            for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich elementach glownej przekatnej
                vDeterminant *= getElement(i, i); // przemnozenie przez kolejne elementy
        }
        else // jednak wlasciwosci nie sa spelnione
        {
            // !!! Macierz nie spelnia okreslonych wlasciwosci
            vDeterminant = 0.0; // nadanie fikcyjnej wartosci wyznacznika
        }
    }
    else // macierz jednak nie jest kwadratowa
    {
        // !!! Macierz nie jest kwadratowa
        vDeterminant = 0.0; // nadanie fikcyjnej wartosci wyznacznika
    }
}

/*
 * void mCalculateDeterminant()
 */
void cMatrix::mCalculateDeterminant()
{
    if (getIfMatrixSquare()) // sprawdzamy czy macierz jestkwadratowa
    {
        if ((mFindZerosRow() == 0) && (mFindZerosColumn() == 0)) // sprawdzamy czy mamy zerowy wiersz lub kolumne
            vDeterminant = 0.0; // nadanie wartosci wyznacznika
        else
        {

        }
    }
    else // macierz jednak nie jest kwadratowa
    {
        // !!! Macierz nie jest kwadratowa
        vDeterminant = 0.0; // nadanie fikcyjnej wartosci wyznacznika
    }
}

/*
 * bool mFindZerosRow()
 */
bool cMatrix::mFindZerosRow()
{
    bool vZeros; // utworzenie obiektu wynikowego
    for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
    {
        vZeros = true; // domniemanie posiadania zerowego wiersza
        for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich kolumnach
        {
            if (getElement(i, j) != 0) // sprawdzamy czy element jest rozny od zera
            {
                vZeros = false; // natrafienie na niezerowy element
                continue; // przejscie do kolejnego cyklu petli
            }
            if (vZeros == true) // jesli nie udalo sie zmienic w calym wierszu wartosci obiektu to mamy wiersz zerowy
                break; // przerwanie petli
        }
    }
    return vZeros; // zwrocenie wyniku
}

/*
 * bool mFindZerosColumn()
 */
bool cMatrix::mFindZerosColumn()
{
    bool vZeros; // utworzenie obiektu wynikowego
    for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich kolumnach
    {
        vZeros = true; // domniemanie posiadania zerowej kolumny
        for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
        {
            if (getElement(i, j) != 0) // sprawdzamy czy element jest rozny od zera
            {
                vZeros = false; // natrafienie na niezerowy element
                continue; // przejscie do kolejnego cyklu petli
            }
            if (vZeros == true) // jesli nie udalo sie zmienic w calej kolumnie wartosci obiektu to mamy kolumne zerowa
                break; // przerwanie petli
        }
    }
    return vZeros; // zwrocenie wyniku
}



/*
 * cMatrix mExponentiationMatrix(typeSize parPower)
 */
cMatrix cMatrix::mExponentiationMatrix(typeSize parPower)
{
    if (getIfMatrixSquare()) // sprawdzenie czy macierz jest kwadratowa
    {
        cMatrix Result(getRows(), getColumns()); // utworzenie macierzy wynikowej
        Result.tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
        for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
            for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich kolumnach
                Result.setElement(i, j, getElement(i, j)); // nadanie wartosci dla kolejnych elementow
        if (parPower == 0) // sprawdzamy czy potega jest rowna '0'
        {
            for (typeSize i = 0; i < getRows(); i++) // przejscie po wszystkich wierszach
            {
                for (typeSize j = 0; j < getColumns(); j++) // przejscie po wszystkich kolumnach
                {
                    if (i == j) // sprawdzamy czy jestesmy na glownej przekatnej
                        Result.setElement(i, j, 1); // utanowienie wartosci elementu
                    else // jestesmy poza glowna przekatna
                        Result.setElement(i, j, 0); // ustanowienie wartosci elementu
                }
            }
        }
        else if (parPower > 1) // tutaj potega jest wieksza niz 1
        {
            cMatrix X = Result; // utworzenie nowej macierzy, rownej wynikowej
            for (typeSize k = 1; k < parPower; k++) // przejscie przez odpowiednia liczbe mnozen
                Result = Result * X; // kolejne mnozenie
        }
        return Result; // zwrocenie wyniku
    }
    else // macierz jednak nie jest kwadratowa
    {
        // !!! Macierz nie jest kwadratowa
        cMatrix Result; // ustanowienie fikcyjnego obiektu wynikowego
        return Result; // wyswietlenie fikcyjnego wyniku
    }
}

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
cMatrix cMatrix::mInversalMatrix3x3()
{
    if ((getRows() == 3) && (getColumns() == 3)) // sprawdzamy czy macierz ma odpowiednie wymiary
    {
        if (getDeterminant() != 0) // sprawdzamy czy wyznacznik jest rozny od zera
        {
            //
            cMatrix Result(getRows(), getColumns()); // utworzenie obiektu wynikowego
            return Result; // zwrocenie wyniku
        }
        else // jesli wyznacznik jest rowny '0'
        {
            // !!! Wyznacznik jest rowny zero
            cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
            return Result; // zwrocenie fikcyjnego wyniku
        }
    }
    else // macierz ma niepoprawne wymiary
    {
        // A moze to blad wywolania?
        cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
        return Result; // zwrocenie fikcyjnego wyniku
    }
}

/*
 * cMatrix mInversalMatrix()
 */
cMatrix cMatrix::mInversalMatrix()
{
    if (getIfMatrixSquare() == true) // sprawdzamy czy macierz jest kwadratowa
    {
        if (getRows() > 3) //sprawdzamy czy macierz ma wieksze wymiary niz 3x3
        {
            if (getDeterminant() != 0) // sprawdzamy czy wyznacznik jest rozny od zera
            {
                //
                cMatrix Result(getRows(), getColumns()); // utworzenie obiektu wynikowego
                return Result; // zwrocenie wyniku
            }
            else // wyznacznik jest jednak zerem
            {
                // !!! Wyznacznik jest rowny zero
                cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
                return Result; // zwrocenie fikcyjnego wyniku
            }
        }
        else // macierz nie ma wiekszych wymiarow niz 3x3
        {
            // moze wywolano nie te metode?
            cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
            return Result; // zwrocenie fikcyjnego wyniku
        }
    }
    else // jesli macierz nie jest kwadratowa
    {
        // !!! Macierz nie jest kwadratowa
        cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
        return Result; // zwrocenie fikcyjnego wyniku
    }
}



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
            if (getRows() == 1) // sytaucja kiedy mamy wektory poziome
            {
                for (typeSize i = 0; i < getColumns(); i++) // przejscie przez wszystkie elementy obu wektorow
                    sum += (getElement(0, i) * M.getElement(0, i)); // dodawanie kolejnych iloczynow do wyniku
            }
            else // sytuacja kiedy mamy wektory pionowe
            {
                for (typeSize j = 0; j < getRows(); j++) // przejscie przez wszystkie elementy obu wektorow
                    sum += (getElement(j, 0) * M.getElement(j, 0)); // dodawanie kolejnych iloczynow do wyniku
            }
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
        if ((getRows() == M.getRows()) && (getColumns() == M.getColumns())) // sprawdzenie czy wektory maja identyczne wymiary
        {
            cMatrix Result(getRows(), getColumns()); // utworzenie obiektu wynikowego
            Result.tableElements = new double[getRows() * getColumns()]; // utworzenie nowej tablicy elementow
            if ((getRows() == 1) && (getColumns() > 2)) // argumenty sa wektorami poziomymi majacymi wiecej niz po 2 elementy
            {
                for (typeSize i = 0; i < getColumns(); i++) // przejscie po wszystkich elementach
                {
                    typeSize a = i + 1; // ustalenie wspolrzednej "o 1 miejsce dalej"
                    if (a >= getColumns()) // sprawdzenie czy przekroczono zakres
                        a -= getColumns(); // naniesienie poprawki
                    typeSize b = i + 2; // ustalenie wspolrzednej "o 2 miejsca dalej"
                    if (b >= getColumns()) // sprawdzenie czy przekroczono zakres
                        b -= getColumns(); // naniesienie poprawki
                    typeSize c = i + getColumns() - 1; // ustalenie wspolrzednej "o 1 miejsce blizej"
                    if (c >= getColumns()) // sprawdzenie czy przekroczono zakres
                        c -= getColumns(); // naniesienie poprawki
                    typeSize d = i + getColumns() - 2; // ustalenie wspolrzednej "o 2 miejsca blizej"
                    if (d >= getColumns()) // sprawdzenie czy przekroczono zakres
                        d -= getColumns(); // naniesienie poprawki
                    Result.setElement(0, i, (getElement(0, a) * M.getElement(0, b) - getElement(0, c) * M.getElement(0, d))); // ustanowienie wartosci elementu
                }
            }
            else if ((getRows() == 1) && getColumns() == 2) // argumenty sa wektorami poziomymi majacymi po 2 elementy
            {
                Result.setElement(0, 0, getElement(0, 1) * M.getElement(0, 0)); // ustanowienie wartosci elementow wynikowych
                Result.setElement(0, 1, getElement(0, 0) * M.getElement(0, 1));
            }
            else if ((getRows() == 1) && (getColumns() == 1)) // argumenty sa wektorami poziomymi/pionowymi majacymi po 1 elemencie
            {
                Result.setElement(0, 0, getElement(0, 0) * M.getElement(0, 0)); // ustanowienie wartosci elementu wynikowego
            }
            else if ((getRows() > 2) && (getColumns() == 1)) // argumenty sa wektorami pionowymi majacymi wiecej niz po 2 elementy
            {
                for (typeSize j = 0; j < getRows(); j++) // przejscie po wszystkich elementach
                {
                    typeSize a = j + 1; // ustalenie wspolrzednej "o 1 miejsce dalej"
                    if (a >= getRows()) // sprawdzenie czy przekroczono zakres
                        a -= getRows(); // naniesienie poprawki
                    typeSize b = j + 2; // ustalenie wspolrzednej "o 2 miejsca dalej"
                    if (b >= getRows()) // sprawdzenie czy przekroczono zakres
                        b -= getRows(); // naniesienie poprawki
                    typeSize c = j + getRows() - 1; // ustalenie wspolrzednej "o 1 miejsce blizej"
                    if (c >= getRows()) // sprawdzenie czy przekroczono zakres
                        c -= getRows(); // naniesienie poprawki
                    typeSize d = j + getRows() - 2; // ustalenie wspolrzednej "o 2 miejsca blizej"
                    if (d >= getRows()) // sprawdzenie czy przekroczono zakres
                        d -= getRows(); // naniesienie poprawki
                    Result.setElement(j, 0, (getElement(a, 0) * M.getElement(b, 0) - getElement(c, 0) * M.getElement(d, 0))); // ustanowienie wartosci elementu
                }
            }
            else // argumenty sa wektorami pionowymi majacymi po 2 elementy
            {
                Result.setElement(0, 0, getElement(1, 0) * M.getElement(0, 0)); // ustanowienie wartosci elementow wynikowych
                Result.setElement(1, 0, getElement(0, 0) * M.getElement(1, 0));
            }
            return Result; // zwrocenie wyniku
        }
        else // wektory maja rozne wymiary
        {
            // !!! Wektory maja rozne wymiary
            cMatrix Result; // utworzenie fikcyjnego obiektu wynikowego
            return Result; // zwrocenie fikcyjnego wyniku
        }
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
