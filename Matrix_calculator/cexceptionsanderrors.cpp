/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cexceptionsanderrors.cpp
 */

#include "cexceptionsanderrors.h"
#include <iostream>

using namespace std;

/********** PUBLIC: BEGINNING **********/

/*
 * cExceptionsAndErrors()
 */
cExceptionsAndErrors::cExceptionsAndErrors()
{
}

/*
 * void mDisplayMessage(typeSize pNumber)
 */
void cExceptionsAndErrors::mDisplayMessage(typeSize pNumber)
{
    switch (pNumber) // wybranie odpowiedniej reakcji w zaleznosci od kodu bledu/wyjatku
    {
        case 101: cerr << "Macierze maja rozne wymiary!" << endl; break;
        case 102: cerr << "Niepoprawne wymiary macierzy!" << endl; break;
        case 103: cerr << "Macierz nie jest kwadratowa!" << endl; break;
        case 104: cerr << "Wyznacznik jest rowny zero!" << endl; break;
        case 105: cerr << "Co najmniej jeden z argumentow nie jest wektorem!" << endl; break;
        case 106: cerr << "Argument nie jest wektorem!" << endl; break;
        case 107: cerr << "Proba dzielenia przez zero!" << endl; break;
        case 108: cerr << "Blednie wprowadzony argument!" << endl; break;
        case 109: cerr << "Bledny operator!" << endl; break;
        //case 107: cerr << "" << endl; break;
        //case 107: cerr << "" << endl; break;
        //case 107: cerr << "" << endl; break;
    default: break;
    }
}


/********** PUBLIC: END **********/

/* cexceptionsanderrors.cpp */
/********** END_OF_FILE **********/
