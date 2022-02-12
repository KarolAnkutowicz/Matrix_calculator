/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cexceptionsanderrors.cpp
 */

#include "cexceptionsanderrors.hpp"
#include <iostream>

/********** PUBLIC: BEGINNING **********/

/*
 * void mDisplayMessage(typeSize pNumber)
 */
void cExceptionsAndErrors::mDisplayMessage(typeSize pNumber)
{
    using std::cerr; // wykorzystanie strumienia wyjsciowego bledow ze standardowej przestrzeni nazw
    switch (pNumber) // wybranie odpowiedniej reakcji w zaleznosci od kodu bledu/wyjatku
    {
    case 101: cerr << "Macierze maja rozne wymiary!\n"; break;
    case 102: cerr << "Niepoprawne wymiary macierzy!\n"; break;
    case 103: cerr << "Macierz nie jest kwadratowa!\n"; break;
    case 104: cerr << "Wyznacznik jest rowny zero!\n"; break;
    case 105: cerr << "Co najmniej jeden z argumentow nie jest wektorem!\n"; break;
    case 106: cerr << "Argument nie jest wektorem!\n"; break;
    case 107: cerr << "Proba dzielenia przez zero!\n"; break;
    case 108: cerr << "Blednie wprowadzony argument!\n"; break;
    case 109: cerr << "Bledny operator!\n"; break;
        //case 107: cerr << "" << endl; break;
        //case 107: cerr << "" << endl; break;
        //case 107: cerr << "" << endl; break;
    default: break;
    }
}


/********** PUBLIC: END **********/

/* cexceptionsanderrors.cpp */
/********** END_OF_FILE **********/
