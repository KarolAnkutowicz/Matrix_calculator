/********** BEGIN_OF_FILE **********/
/* ccalculatorhandling.cpp */

#include "ccalculatorhandling.h"

using namespace std;

/*
 * cCalculatorHandling()
 */
cCalculatorHandling::cCalculatorHandling()
{
    mMainChoice();
}

/*
 * void mMainChoice()
 */
void cCalculatorHandling::mMainChoice()
{
    do
    {
        cout << "Jaki rodzaj operacji chcesz przeprowadzic?" << endl
             << "(1) - operacja jednoargumentowa" << endl
             << "(2) - operacja dwuargumentowa (macierz i macierz)" << endl
             << "(3) - operacja dwuargumentowa (macierz i liczba)" << endl
             << "(k) (K) - koniec dzialania programu" << endl << endl;
        cin >> vOptions;
        cout << endl;
        switch (vOptions)
        {
            case '1' : mChoiceOneArgument();
                       break;
            case '2' : mChoiceTwoArgumentMatrixMatrix();
                       break;
            case '3' : mChoiceTwoArgumentMatrixNumber();
                       break;
            case 'k' :
            case 'K' : cout << "Do zobaczenia!" << endl;
                       break;
            default : cout << "Nie ma takiej opcji! Sprobuj jeszcze raz." << endl;
                      break;
        }
        cout << endl;
    } while ((vOptions != endOfProgram1) && (vOptions != endOfProgram2));
}

/*
 * void mChoiceOneArgument()
 */
void cCalculatorHandling::mChoiceOneArgument()
{
    cout << "Wybierz operacje jednoargumentowa:" << endl
         << "(1) - dlugosc wektora" << endl
         << "(2) - obliczenie wyznacznika" << endl
         << "(3) - wyznaczenie macierzy odwrotnej" << endl
         << "(4) - transponowanie macierzy" << endl
         << "(a) - anuluj" << endl << endl;
    cin >> vOptions;
    cout << endl;
    switch(vOptions)
    {
    case '1' : cout << "1" << endl;
        break;
    case '2' : cout << "2" << endl;
        break;
    case '3' : cout << "3" << endl;
        break;
    case '4' : cout << "4" << endl;
        break;
    case 'a' : cout << "a" << endl;
        break;
    default : cout << "Nie ma takiej opcji! Sprobuj jeszcze raz." << endl;
        mChoiceOneArgument();
              break;
    }
}

/*
 * void mChoiceTwoArgumentMatrixMatrix()
 */
void cCalculatorHandling::mChoiceTwoArgumentMatrixMatrix()
{
    cout << "Wybierz operacje dwuargumentowa (macierz i macierz)" << endl
         << "(1) - dodawanie macierzy" << endl
         << "(2) - odejmowanie macierzy" << endl
         << "(3) - mnozenie macierzy" << endl
         << "(4) - iloczyn skalarny wektorow" << endl
         << "(5) - iloczyn wektorowy" << endl
         << "(a) - anuluj" << endl << endl;
    cin >> vOptions;
    cout << endl;
    switch(vOptions)
    {
    case '1' : cout << "1" << endl;
        break;
    case '2' : cout << "2" << endl;
        break;
    case '3' : cout << "3" << endl;
        break;
    case '4' : cout << "4" << endl;
        break;
    case '5' : cout << "5" << endl;
        break;
    case 'a' : cout << "a" << endl;
        break;
    default : cout << "Nie ma takiej opcji! Sprobuj jeszcze raz." << endl;
        mChoiceTwoArgumentMatrixMatrix();
              break;
       }
}

/*
 * void mChoiceTwoArgumentMatrixNumber()
 */
void cCalculatorHandling::mChoiceTwoArgumentMatrixNumber()
{
    cout << "Wybierz operacje dwuargumentowa (macierz i liczba)" << endl
         << "(1) - mnozenie macierzy przez liczbe" << endl
         << "(1) - potegowanie macierzy" << endl
         << "(a) - anuluj" << endl << endl;
    cin >> vOptions;
    cout << endl;
    switch(vOptions)
    {
    case '1' : cout << "1" << endl;
        break;
    case '2' : cout << "2" << endl;
        break;
    case 'a' : cout << "a" << endl;
        break;
    default : cout << "Nie ma takiej opcji! Sprobuj jeszcze raz." << endl;
        mChoiceTwoArgumentMatrixNumber();
              break;
    }
}




/*
 * void mPrintHelp() -
 */
/*void cCalculatorHandling::mPrintHelp()
{

}*/

/*
 * void mPrintErrorStatement(typeSize parError)
 */
/*void cCalculatorHandling::mPrintErrorStatement(typeSize parError)
{

}*/

/* ccalculatorhandling.cpp */
/********** END_OF_FILE **********/
