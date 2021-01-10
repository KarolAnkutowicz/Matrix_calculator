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
     * char c -
     * char operatorSymbol -
     */
    char c, operatorSymbol;

    /*
     * void mMainChoice() -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mMainChoice();

    /*
     * void mChoiceNumber() -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceNumber();
    /*
     * void mChoiceNumberAddSub(double parValue) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceNumberAddSub(double parValue);
    /*
     * void mChoiceNumberMultiplications(double parValue) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceNumberMultiplications(double parValue);
    /*
     * void mChoiceNumberDivision(double parValue) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceNumberDivision(double parValue);

    /*
     * void mChoiceMatrix() -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceMatrix();
    /*
     * void mChoiceMatrixAddSub(cMatrix M) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceMatrixAddSub(cMatrix M);
    /*
     * void mChoiceMatrixMultiplications(cMatrix M) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceMatrixMultiplications(cMatrix M);
    /*
     * void mChoiceMatrixDeterminant(cMatrix M) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceMatrixDeterminant(cMatrix M);
    /*
     * void mChoiceMatrixReversal(cMatrix M) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceMatrixReversal(cMatrix M);
    /*
     * void mChoiceMatrixProductsAnsOthers(cMatrix M) -
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mChoiceMatrixProductsAnsOthers(cMatrix M);

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
