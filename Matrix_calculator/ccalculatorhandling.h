/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: ccalculatorhandling.h
 */

#ifndef CCALCULATORHANDLING_H
#define CCALCULATORHANDLING_H

#include "cmatrix.h"

using namespace std;

class cCalculatorHandling
{
/********** PUBLIC: BEGINNING **********/
public:
    /*
     * cCalculatorHandling() - konstruktor wywolywany
     * bez argumentow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu klasy cCalculatorHandling.
     */
    cCalculatorHandling();



    /*
     * c, oper - zmienne znakowe uzywane do wczytania
     * kolejnych argumentow.
     */
    char c, oper;

    /*
     * d1, d2, d3 - zmienne zmiennoprzecinkowe uzywane
     * do wczytania liczb rzeczywistych.
     */
    double d1, d2, d3;

    /*
     * i - zmienna calkowita uzywana do wczytania
     * wykladnikow w potegowaniach liczb rzeczywistych
     * lub macierzy.
     */
    int i;

    /*
     * M1, M2, M3 - obiekty klasy cMatrix uzywane do
     * wczytywania macierzy.
     */
    cMatrix M1, M2, M3;



    /*
     * mMainHandling() - glowna metoda obslugi programu
     * stanowiaca "rozgaleznik" miedzy operacjami gdzie
     * pierwszym argumentem jest liczba albo macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMainHandling();



    /*
     * mChooseNumber() - glowna metoda obslugi programu
     * dla operacji w których pierwszym argumentem jest
     * liczba rzeczywista
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumber();

    /*
     * mChooseNumberSum() - metoda obslugujaca dodawanie
     * i odejmowanie liczb rzeczywistych.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumberSum();

    /*
     * mChooseNumberMultiplication() - metoda obslugujaca
     * mnozenie liczby przez liczbe rzeczywista albo
     * przez macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumberMultiplication();

    /*
     * mChooseNumberOthers() - metoda obslugujaca dzielenie
     * liczb rzeczywistych i potegowanie liczby rzeczywistej
     * do potegi calkowitej.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumberOthers();




    /*
     * mChooseMatrix() - metoda obslugujaca operacje gdzie
     * pierwszym (i czasem jedynym) argumentem jest macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrix();

    /*
     * mChooseMatrixSum() - metoda obslugujaca dodawanie
     * i odejmowanie macierzy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixSum();

    /*
     * mChooseMatrixMultiplication() - metoda obslugujaca
     * mnozenie macierzy przez liczbe rzeczywista albo
     * przez macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixMultiplication();

    /*
     * mChooseMatrixExponentiation() - metoda obslugujaca
     * potegowanie macierzy - w tym do potegi (-1) czyli
     * odwracanie macierzy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixExponentiation();

    /*
     * mChooseMatrixProducts() - metoda obslugujaca
     * iloczyny: skalarny i wektorowy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixProducts();

    /*
     * mChooseMatrixOthers() - metoda obslugujaca pozostale
     * operacje na macierzach: dlugosc wektora, wyznacznik
     * macierzy, transponowanie macierzy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixOthers();

/********** PUBLIC: END **********/
};

#endif // CCALCULATORHANDLING_H

/* ccalculatorhandling.h */
/********** END_OF_FILE **********/
