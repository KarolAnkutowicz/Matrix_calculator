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
    switch (pNumber)
    {
    case 101: cerr << "Blednie wczytany argument!" << endl; break;
    case 102: cerr << "Bledny operator!" << endl; break;
    case 103: cerr << "" << endl; break;
    case 104: cerr << "" << endl; break;
    case 105: cerr << "" << endl; break;
    case 106: cerr << "" << endl; break;
    case 107: cerr << "" << endl; break;
    default: break;
    }
}


/********** PUBLIC: END **********/

/* cexceptionsanderrors.cpp */
/********** END_OF_FILE **********/
