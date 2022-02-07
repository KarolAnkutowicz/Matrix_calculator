/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cexceptionsanderrors.hpp
 */

#ifndef CEXCEPTIONSANDERRORS_HPP
#define CEXCEPTIONSANDERRORS_HPP

#include "constantsandtypes.hpp"
#include <iostream>

using namespace std;

class cExceptionsAndErrors
{
    /********** PUBLIC: BEGINNING **********/
public:
    /*
     * cExceptionsAndErrors() - konstruktor wywolywany bez
     * parametrow.
     * PRE:
     * - brak
     * POST:
     * - utworzenie obiektu klasy cExceptionsAndErrors.
     */
    cExceptionsAndErrors();

    /*
     * void mDisplayMessage(typeSize pNumber) - metoda wyswietlajaca
     * komunikat bledu lub wyjatku.
     * PRE:
     * - numer bledu lub wyjatku.
     * POST:
     * - brak.
     */
    void mDisplayMessage(typeSize pNumber);

    /********** PUBLIC: END **********/
};

#endif // CEXCEPTIONSANDERRORS_HPP

/* cexceptionsanderrors.hpp */
/********** END_OF_FILE **********/
