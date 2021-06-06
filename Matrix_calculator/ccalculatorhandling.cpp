/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: ccalculatorhandling.cpp
 */

#include "ccalculatorhandling.h"
#include "cexceptionsanderrors.h"
#include "cmatrix.h"
#include "constantsandtypes.h"
#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

/********** PUBLIC: BEGINNING **********/

/*
 * cCalculatorHandling()
 */
cCalculatorHandling::cCalculatorHandling()
{
    mMainHandling(); // wywolanie glownej obslugi
}



/*
 * void mMainHandling()
 */
void cCalculatorHandling::mMainHandling()
{
    do
    {
        cin >> skipws >> c; // wczytanie znaku
        if (c == endOfProgram) // sprawdzenie czy konczymy dzialanie programu
            break;
        else if (isdigit(c)) // sprawdzenie czy wczytujemy liczbe
        {
            cin.unget(); // zwrocenie znaku do strumienia
            cin >> skipws >> d1; // wczytanie pierwszego argumentu (liczby rzeczywistej)
            mChooseNumber(); // wywolanie odrebnej metody
        }
        else if (c == '-') // sprawdzenie czy argument bedzie ujemny
        {
            cin >> skipws >> c; // wczytanie znaku
            if (isdigit(c)) // sprawdzenie czy wczytujemy liczbe
            {
                cin.unget(); // zwrocenie znaku do strumienia
                cin >> skipws >> d1; // wczytanie pierwszego argumentu (bez znaku)
                d1 = -d1; // przywrocenie wlasciwego znaku dla argumentu
                mChooseNumber(); // wywolanie odrebnej metody
            }
            /*else
            {
                // !!! Blednie wczytany argument
            }*/
        }
        else if (c == startOfMatrix) // sprawdzenie czy wczytujemy macierz
        {
            cin.unget(); // zwrocenie znaku do strumienia
            mChooseMatrix(); // wywolanie odrebnej metody
        }
        /*else
        {
            // !!! Blednie wczytany argument
        }*/
    } while (c != endOfProgram); // sprawdzenie warunku zakonczenia petli
}



/*
 * void mChooseNumber()
 */
void cCalculatorHandling::mChooseNumber()
{
    cin >> skipws >> oper; // wczytanie operatora
    switch (oper)
    {
    case '+':
    case '-': mChooseNumberSum(); break; // obsluga dodawania i odejmowania
    case '*': mChooseNumberMultiplication(); break; // obsluga mnozenia
    case '/':
    case operatorExponentiation: mChooseNumberOthers(); break; // obsluga dzielenia i potegowania
    default: /* !!! Bledny operator */ break;
    }
}

/*
 * void mChooseNumberSum()
 */
void cCalculatorHandling::mChooseNumberSum()
{
    if (oper == '+') // sprawdzenie czy bedziemy dodawac
    {
        cin >> skipws >> d2; // wczytanie drugiego argumentu
        d3 = d1 + d2; // obliczenie wyniku
        cout << d3 << endl; // wypisanie wyniku
    }
    else // bedziemy odejmowac
    {
        cin >> skipws >> d2; // wczytanie drugiego argumentu
        d3 = d1 - d2; // obliczenie wyniku
        cout << d3 << endl; // wypisanie wyniku
    }
}

/*
 * void mChooseNumberMultiplication()
 */
void cCalculatorHandling::mChooseNumberMultiplication()
{
    cin >> skipws >> c; // wczytanie znaku
    if (isdigit(c)) // sprawdzenie czy bedziemy wczytywac liczbe
    {
        cin.unget(); // zwrocenie znaku do strumienia
        cin >> skipws >> d2; // wczytanie drugiego argumentu
        d3 = d1 * d2; // obliczenie wyniku
        cout << d3 << endl; // wypisanie wyniku
    }
    else if (c == '-') // sprawdzenie czy argument bedzie ujemny
    {
        cin >> skipws >> d2; // wczytanie argumentu (bez znaku)
        d2 = -d2; // przywrocenie znaku argumentu
        d3 = d1 * d2; // obliczenie wyniku
        cout << d3 << endl; // wypisanie wyniku
    }
    else if (c == startOfMatrix) // sprawdzenie czy bedziemy wczytywac macierz
    {
        cin.unget(); // zwrocenie znaku do strumienia
        cin >> skipws >> M2; // wczytanie drugiego argumentu
        cMatrix M3(M2.getRows(), M2.getColumns());
        M3 = M2 * d1; // obliczenie wyniku
        cout << M3 << endl; // zwrocenie wyniku
    }
    else
    {
        // !!! Bledny argument
    }
}

/*
 * void mChooseNumberOthers()
 */
void cCalculatorHandling::mChooseNumberOthers()
{
    if (oper == '/') //sprawdzenie czy bedziemy dzielic
    {
        cin >> skipws >> d2; // wczytanie drugiego argumentu
        if (d2 != 0.0) // sprawdzenie czy nie probujemy dzielic przez '0'
        {
            d3 = d1 / d2; // obliczenie wyniku
            cout << d3 << endl; // wypisanie wyniku
        }
        else
        {
            // !!! Proba dzielenia przez '0'
        }
    }
    else //  bedziemy potegowac
    {
        cin >> i; // wczytanie wykladnika
        if (i > 0) // sprawdzamy czy wykladnik jest dodatni
        {
            d3 = d1;
            for (short j = i - 1; j > 0; j--) // wykonujemy odpowiednia liczbe mnozen
                d3 *= d1; // kolejne mnozenia
            cout << d3 << endl; // wypisanie wyniku
        }
        else if (i < 0) // tutaj wykladnik jest ujemny
        {
            d3 = 1 / d1;
            for (short j = i + 1; j < 0; j++) // wykonujemy odpowiednia liczbe dzielen
                d3 /= d1; // kolejne dzielenia
            cout << d3 << endl; // wypisanie wyniku
        }
        else // tutaj wykladnik jest '0'
        {
            d3 = 1;
            cout << d3 << endl; // wypisanie wyniku
        }
    }
}




/*
 * void mChooseMatrix()
 */
void cCalculatorHandling::mChooseMatrix()
{
    cin >> skipws >> M1 >> oper;
    switch(oper)
    {
    case '+':
    case '-': mChooseMatrixSum(); break; // obsluga dodawani i odejmowania
    case '*': mChooseMatrixMultiplication(); break; // obsluga mnozenia
    case operatorExponentiation: mChooseMatrixExponentiation(); break; // obsluga potegowania macierzy
    case operatorReversal: mChooseMatrixReversal(); break; // obsluga odwracania macierzy
    case operatorScalarProduct:
    case operatorCrossProduct: mChooseMatrixProducts(); break; // obsluga iloczynow: skalarnego i wektorowego
    case operatorLengthVector:
    case operatorDeterminant:
    case operatorTransposition: mChooseMatrixOthers(); break; // obsluga pozostalych operacji
    default: /* !!! Bledny operator */ break;
    }
}

/*
 * void mChooseMatrixSum()
 */
void cCalculatorHandling::mChooseMatrixSum()
{
    if (oper == '+') // sprawdzamy czy bedziemy dodawac macierze
    {
        cin >> skipws >> M2; // wczytanie drugiego argumentu
        if ((M1.getRows() == M2.getRows()) && (M1.getColumns() == M2.getColumns())) // sprawdzenie wymiarow macierzy
        {
            cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
            M3 = M1 + M2; // obliczenie wyniku
            cout << M3 << endl; // wypisanie wyniku
        }
        else // wymiary macierzy sie nie zgadzaja
        {
            // !!! Rozne wymiary macierzy
            cMatrix M3; // utworzenie fikcyjnego wyniku
            cout << M3 << endl; // wypisanie fikcyjnego wyniku
        }
    }
    else // tutaj bedziemy odejmowac macierze
    {
        cin >> skipws >> M2; // wczytanie drugiego argumentu
        if ((M1.getRows() == M2.getRows()) && (M1.getColumns() == M2.getColumns())) // sprawdzenie wymiarow macierzy
        {
            cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
            M3 = M1 - M2; // obliczenie wyniku
            cout << M3 << endl; // wypisanie wyniku
        }
        else // wymiary macierzy sie nie zgadzaja
        {
            // !!! Rozne wymiary macierzy
            cMatrix M3; // utworzenie fikcyjnego wyniku
            cout << M3 << endl; // wypisanie fikcyjnego wyniku
        }
    }
}

/*
 * void mChooseMatrixMultiplication()
 */
void cCalculatorHandling::mChooseMatrixMultiplication()
{
    cin >> skipws >> c; // wczytanie znaku
    if (isdigit(c)) // sprawdzenie czy argument bedzie liczba
    {
        cin.unget(); // zwrocenie znaku do strumienia
        cin >> d2; // wczytanie drugiego argumentu
        cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
        M3 = M1 * d2; // obliczenie wyniku
        cout << M3 << endl; // zwrocenie wyniku
    }
    else if (c == '-') // sprawdzenie czy argument bedzie ujemny
    {
        cin >> skipws >> c; // wczytanie znaku
        if (isdigit(c)) // sprawdzenie czy argument jest liczba
        {
            cin.unget(); // zwrocenie znaku do strumienia
            cin >> d2; // wczytanie drugiego argumentu
            d2 = -d2; // przywrocenie wlasciwego znaku argumentu
            cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
            M3 = M1 * d2; // obliczenie wyniku
            cout << M3 << endl; // wypisanie wyniku
        }
    }
    else if (c == startOfMatrix)
    {
        cin.unget(); // zwrocenie znaku do strumienia
        cin >> skipws >> M2; // wczytanie drugiego argumentu
        if (M1.getColumns() == M2.getRows()) // sprawdzenie warunku wymiarow macierzy
        {
            cMatrix M3(M1.getRows(), M2.getColumns()); // utworzenie obiektu wynikowego
            M3 = M1 * M2; // obliczenie wyniku
            cout << M3 << endl; // wypisanie wyniku
        }
        else
        {
            // !!! Niepoprawne wymiary macierzy
            cMatrix M3; // utworzenie fikcyjnego obiektu wynikowego
            cout << M3 << endl; // wypisanie fikcyjnego wyniku
        }
    }
    /*else
    {
        // !!! Bledny argument
    }*/
}

/*
 * void mChooseMatrixExponentiation()
 */
void cCalculatorHandling::mChooseMatrixExponentiation()
{
    if (M1.getIfMatrixSquare()) // sprawdzamy czy chcemy potegowac macierz kwardatowa
    {
        cin >> skipws >> j; // wczytanie wykladnika
        cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie macierzy wynikowej
        M3 = M1.mExponentiationMatrix(j); // wywolanie metody potegujacej macierze
        cout << M3 << endl; // wypisanie wyniku
    }
    else // nieudana proba potegowania macierzy niekwadratowej
    {
        // !!! Macierz nie jest kwadratowa
        cMatrix M3; // utworzenie fikcyjnego obiektu wynikowego
        cout << M3 << endl; // wypisanie fikcyjnego wyniku
    }
}

/*
 * void mChooseMatrixReversal()
 */
void cCalculatorHandling::mChooseMatrixReversal()
{
    if (M1.getIfMatrixSquare()) // sprawdzenie czy macierz jest kwadratowa
    {
        if (M1.getDeterminant() != 0) // sprawdzenie czy wyznacznik jest rozny od '0'
        {
            if (M1.getRows() == 1) // sprawdzamy czy wymiar macierzy jest rowny 1
            {
                cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
                M3 = M1.mInversalMatrix1x1(); // wywolanie metody wyznaczajacaj macierz odwrotna 1x1
                cout << M3 << endl; // wypisanie wyniku
            }
            /*else if (M1.getRows() == 2) // sprawdzamy czy wymiar macierzy jest rowny 2
            {
                cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
                M3 = M1.mInversalMatrix2x2(); // wywolanie metody wyznaczajacej macierz odwrotna 2x2
                cout << M3 << endl; // wypisanie wyniku
            }*/
            /*else if (M1.getRows() == 3) // sprawdzamy czy wymiar macierzy jest rowny 3
            {
                cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
                M3 = M1.mInversalMatrix3x3(); // wywolanie metody wyznaczajacej macierz odwrotna 3x3
                cout << M3 << endl; // wypisanie wyniku
            }*/
            /*else // wyznaczamy macierz dla wymiarow wiekszych niz 3
            {
                cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
                M3 = M1.mInversalMatrix(); // wywolanie metody wyznaczajacej macierz odwrotna o wymiarach wiekszych niz 3x3
                cout << M3 << endl; // wypisanie wyniku
            }*/
        }
        else // jednak wyznacznik jest '0'
        {
            // !!! Wyznacznik rozny od zera
            cMatrix M3; // utworzenie fikcyjnego obiektu wynikowego
            cout << M3 << endl; // wyswietlenie fikcynego wyniku
        }
    }
    else // jednak macierz nie jest kwadratowa
    {
        // !!! Macierz nie jest kwadratowa
        cMatrix M3; // utworzenie fikcyjnego wyniku
        cout << M3 << endl; // wyswietlenie fikcyjnego wyniku
    }
}


/*
 * void mChooseMatrixProducts()
 */
void cCalculatorHandling::mChooseMatrixProducts()
{
    if (oper == operatorScalarProduct) // wyznaczamy iloczyn skalarny
    {
        cin >> M2; // wczytanie drugiego argumentu
        if ((M1.getIfVector()) && (M2.getIfVector())) // sprawdzenie czy argumenty sa wektorami
        {
            if ((M1.getRows() == M2.getRows()) && (M1.getColumns() == M2.getColumns())) // sprawdzenie wymiarow
            {
                d3 = M1.mScalarProduct(M2); // wyznaczenie iloczynu skalarnego
                cout << d3 << endl; // wypisanie wyniku
            }
            else // argumenty sa wektorami ale maja rozne wymiary
            {
                // !!! Argumenty maja rozne wymiary
                d3 = 0.0; // nadanie wynikowi fikcyjnej wartosci
                cout << d3 << endl; // wyswietlenie fikcyjnego wyniku
            }
        }
        else // co najmniej jeden z argumentow nie jest wektorem
        {
            // !!! Bledne argumenty
            d3 = 0.0; // nadanie wynikowi fikcyjnej wartosci
            cout << d3 << endl; // wyswietlenie fikcyjnego wyniku
        }
    }
    else // wyznaczamy iloczyn wektorowy
    {
        cin >> M2; // wczytanie drugiego argumentu
        if ((M1.getIfVector()) && (M2.getIfVector())) // sprawdzenie czy argumenty sa wektorami
        {
            if ((M1.getRows() == M2.getRows()) && (M1.getColumns() == M2.getColumns())) // sprawdzenie wymiarow
            {
                cMatrix M3(M1.getRows(), M1.getColumns()); // utworzenie obiektu wynikowego
                M3 = M1.mCrossProduct(M2); // wyznaczenie iloczynu wektorowego
                cout << M3 << endl; // wypisanie wyniku
            }
            else // argumenty sa wektorami ale maja rozne wymiary
            {
                // !!! Argumenty maja rozne wymiary
                cMatrix M3; // utworzenie fikcyjnego obiektu wynikowego
                cout << M3 << endl; // wyswietlenie fikcyjnego wyniku
            }
        }
        else // co najmniej jeden z argumentow nie jest wektorem
        {
            // !!! Bledne argumenty
            cMatrix M3; // utworzenie fikcyjnego obiektu wynikowego
            cout << M3 << endl; // wyswietlenie fikcyjnego wyniku
        }
    }
}

/*
 * void mChooseMatrixOthers()
 */
void cCalculatorHandling::mChooseMatrixOthers()
{
    if (oper == operatorLengthVector) // sprawdzenie czy bedziemy wyznaczac dlugosc wektora
    {
        if (M1.getIfVector()) // sprawdzenie czy argument jest wektorem
        {
            d3 = M1.mLengthVector(); // wyznaczanie dlugosci wektora
            cout << d3 << endl; // wypisanie wyniku
        }
        else // argument jednak nie jest wektorem
        {
            // !!! Argument nie jest wektorem
            d3 = 0.0; // nadanie wynikowi fikcyjnej wartosci
            cout << d3 << endl; // wyswietlenie fikcyjnego wyniku
        }
    }
    else if (oper == operatorDeterminant) // sprawdzenie czy bedziemy obliczac wyznacznik macierzy
    {
        if (M1.getIfMatrixSquare()) // sprawdzenie czy macierz jest kwadratowa
        {
            if (M1.getRows() == 1) // sprawdzamy czy macierz ma wymiar 1
            {
                d3 = M1.getElement(0, 0); // wyznacznik bedzie rowny wartosci jedynego elementu
                cout << d3 << endl; // wypisanie wyniku
            }
            else if (M1.getRows() == 2) // sprawdzamy czy macierz ma wymair 2
            {
                M1.mCalculateDeterminant2x2(); // obliczenie wyznacznika
                d3 = M1.getDeterminant(); // przypisanie wyniku
                cout << d3 << endl; // wypisanie wyniku
            }
            else if (M1.getRows() == 3) // sprawdzamy czy macierz ma wymiar 3
            {
                M1.mCalculateDeterminant3x3(); // obliczenie wyznacznika
                d3 = M1.getDeterminant(); // przypisanie wyniku
                cout << d3 << endl; // wypisanie wyniku
            }
            else if (M1.getIfMatrixDiagonal() == true) // sprawdzamy czy macierz jest diagonalna
            {
                M1.mCalculateDeterminantDiagonal(); // obliczenie wyznacznika
                d3 = M1.getDeterminant(); // przypisanie wyniku
                cout << d3 << endl; // wypisanie wyniku
            }
            else // tutaj macierz ma wymiar wiekszy niz 3, ktore nie sa diagonalne
            {
                M1.mCalculateDeterminant(); // obliczenie wyznacznika
                d3 = M1.getDeterminant(); // przypisanie wyniku
                cout << d3 << endl; // wypisanie wyniku
            }
        }
        else // macierz jednak nie jest kwadratowa
        {
            // !!! Macierz nie jest kwadratowa
            d3 = 0.0; // przypisanie fikcyjnej wartosci
            cout << d3 << endl; // wypisanie fikcyjnej wartosci
        }
    }
    else // bedziemy wyznaczac macierz transponowana
    {
        cMatrix M3(M1.getColumns(), M1.getRows()); // utworzenie obiektu wynikowego
        M3 = M1.mTransposition(); // wyznaczanie macierzy transponowanej
        cout << M3 << endl; // wypisanie wyniku
    }
}


/********** PUBLIC: END **********/

/* ccalculatorhandling.cpp */
/********** END_OF_FILE **********/
