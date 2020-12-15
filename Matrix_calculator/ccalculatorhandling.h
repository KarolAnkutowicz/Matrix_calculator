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
    cCalculatorHandling();

    char c, operatorSymbol;

    void mMainChoice();

    void mChoiceNumber();
    void mChoiceNumberAddSub(double parValue);
    void mChoiceNumberMultiplications(double parValue);
    void mChoiceNumberDivision(double parValue);

    void mChoiceMatrix();
    void mChoiceMatrixAddSub(cMatrix M);
    void mChoiceMatrixMultiplications(cMatrix M);
    void mChoiceMatrixDeterminant(cMatrix M);
    void mChoiceMatrixReversal(cMatrix M);
    void mChoiceMatrixProductsAnsOthers(cMatrix M);

    void mPrintHelp();
    void mPrintErrorStatement(typeSize parError);
};

#endif // CCALCULATORHANDLING_H

/* ccalculatorhandling.h */
/********** END_OF_FILE **********/
