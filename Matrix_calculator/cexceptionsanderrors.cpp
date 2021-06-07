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
    case 101: cerr << "Macierze maja rozne wymiary!" << endl; break;
    case 107: cerr << "" << endl; break;
    //case 107: cerr << "" << endl; break;
    //case 107: cerr << "" << endl; break;
    //case 107: cerr << "" << endl; break;
    //case 107: cerr << "" << endl; break;
    default: break;
    }
}


/********** PUBLIC: END **********/

/* cexceptionsanderrors.cpp */
/********** END_OF_FILE **********/
