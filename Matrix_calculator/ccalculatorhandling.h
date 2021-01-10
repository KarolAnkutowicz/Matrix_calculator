/********** BEGIN_OF_FILE **********/
/* ccalculatorhandling.h */

#ifndef CCALCULATORHANDLING_H
#define CCALCULATORHANDLING_H

#include "cmatrix.h"
#include "constantsandtypes.h"

using namespace std;

class cCalculatorHandling
{
public:
    /*
     * cCalculatorHandling() -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    cCalculatorHandling();

    /*
     * char vOperatorSymbol -
     */
    char vOptions, vOperatorSymbol;

    /*
     * void mMainChoice() -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mMainChoice();


    /*
     * void mChoiceOneArgument()
     */
    void mChoiceOneArgument();

    /*
     * void mChoiceTwoArgumentMatrixMatrix()
     */
    void mChoiceTwoArgumentMatrixMatrix();

    /*
     * void mChoiceTwoArgumentMatrixNumber()
     */
    void mChoiceTwoArgumentMatrixNumber();




    /*
     * void mPrintHelp() -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mPrintHelp();
    /*
     * void mPrintErrorStatement(typeSize parError) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mPrintErrorStatement(typeSize parError);
};

#endif // CCALCULATORHANDLING_H

/* ccalculatorhandling.h */
/********** END_OF_FILE **********/
