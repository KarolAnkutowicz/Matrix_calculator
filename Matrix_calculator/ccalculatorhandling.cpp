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
        cin >> skipws >> c;
        if (c == endOfProgram)
            break;
        else if (isdigit(c))
        {
            cin.unget();
            mChooseNumber();
        }
        else if (c == '-')
        {
            cin >> skipws >> c;
            if (isdigit(c))
            {
                cin.unget();
                mChooseNumber();
            }
            /*else
            {
                // !!! Blednie wczytany argument
            }*/
        }
        else if (c == startOfMatrix)
        {
            cin.unget();
            mChooseMatrix();
        }
        /*else
        {
            // !!! Blednie wczytany argument
        }*/
    } while (c != endOfProgram);
}



/*
 * void mChooseNumber()
 */
void cCalculatorHandling::mChooseNumber()
{
    cin >> skipws >> d1 >> oper;
    switch (oper)
    {
    case '+':
    case '-': mChooseNumberSum(); break;
    case '*': mChooseNumberMultiplication(); break;
    case '/':
    case operatorExponentiation: mChooseNumberOthers(); break;
    default: /* !!! Bledny operator */ break;
    }
}

/*
 * void mChooseNumberSum()
 */
void cCalculatorHandling::mChooseNumberSum()
{
    if (oper == '+')
    {
        cin >> skipws >> d2;
        d3 = d1 + d2;
        cout << d3 << endl;
    }
    else
    {
        cin >> skipws >> d2;
        d3 = d1 - d2;
        cout << d3 << endl;
    }
}

/*
 * void mChooseNumberMultiplication()
 */
void cCalculatorHandling::mChooseNumberMultiplication()
{

}

/*
 * void mChooseNumberOthers()
 */
void cCalculatorHandling::mChooseNumberOthers()
{

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
