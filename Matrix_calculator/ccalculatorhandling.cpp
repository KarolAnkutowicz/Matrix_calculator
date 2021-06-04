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
    case '-': mChooseMatrixSum(); break;
    case '*': mChooseMatrixMultiplication(); break;
    case operatorExponentiation:
    case operatorReversal: mChooseMatrixExponentiation(); break;
    case operatorScalarProduct:
    case operatorCrossProduct: mChooseMatrixProducts(); break;
    case operatorLengthVector:
    case operatorDeterminant:
    case operatorTransposition: mChooseMatrixOthers(); break;
    default: /* !!! Bledny operator */ break;
    }
}

/*
 * void mChooseMatrixSum()
 */
void cCalculatorHandling::mChooseMatrixSum()
{

}

/*
 * void mChooseMatrixMultiplication()
 */
void cCalculatorHandling::mChooseMatrixMultiplication()
{

}

/*
 * void mChooseMatrixExponentiation()
 */
void cCalculatorHandling::mChooseMatrixExponentiation()
{

}

/*
 * void mChooseMatrixProducts()
 */
void cCalculatorHandling::mChooseMatrixProducts()
{

}

/*
 * void mChooseMatrixOthers()
 */
void cCalculatorHandling::mChooseMatrixOthers()
{

}


/********** PUBLIC: END **********/

/* ccalculatorhandling.cpp */
/********** END_OF_FILE **********/
