/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: ccalculatorhandling.h
 */

#ifndef CCALCULATORHANDLING_H
#define CCALCULATORHANDLING_H

#include "cexceptionsanderrors.h"
#include "cmatrix.h"
#include "constantsandtypes.h"
#include <iostream>

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
     * short i - zmienna calkowita uzywana do wczytania
     * wykladnikow w potegowaniach liczb rzeczywistych.
     */
    short i;

    /*
     * unsigned short j - zmienna calkowita bez znaku uzywana
     * do wczytania wykladnikow w potegowaniu macierzy.
     */
    unsigned short j;

    /*
     * cMatrix M1, M2, M3 - obiekty klasy cMatrix uzywane
     * do wczytywania macierzy.
     */
    cMatrix M1, M2, M3;


    /*
     * cExceptionsAndErrors Error - obiekt klasy
     * cExceptionsAndErrors obslugujacy komunikaty wyjatkow
     * i bledow w obsludze kalkulatora.
     */
    cExceptionsAndErrors Error;



    /*
     * void mMainHandling() - glowna metoda obslugi programu
     * stanowiaca "rozgaleznik" miedzy operacjami gdzie
     * pierwszym argumentem jest liczba albo macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMainHandling();



    /*
     * void mChooseNumber() - glowna metoda obslugi programu
     * dla operacji w których pierwszym argumentem jest
     * liczba rzeczywista
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumber();

    /*
     * void mChooseNumberSum() - metoda obslugujaca dodawanie
     * i odejmowanie liczb rzeczywistych.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumberSum();

    /*
     * void mChooseNumberMultiplication() - metoda obslugujaca
     * mnozenie liczby przez liczbe rzeczywista albo
     * przez macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumberMultiplication();

    /*
     * void mChooseNumberOthers() - metoda obslugujaca dzielenie
     * liczb rzeczywistych i potegowanie liczby rzeczywistej
     * do potegi calkowitej.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseNumberOthers();




    /*
     * void mChooseMatrix() - metoda obslugujaca operacje gdzie
     * pierwszym (i czasem jedynym) argumentem jest macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrix();

    /*
     * void mChooseMatrixSum() - metoda obslugujaca dodawanie
     * i odejmowanie macierzy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixSum();

    /*
     * void mChooseMatrixMultiplication() - metoda obslugujaca
     * mnozenie macierzy przez liczbe rzeczywista albo
     * przez macierz.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixMultiplication();

    /*
     * void mChooseMatrixExponentiation() - metoda obslugujaca
     * potegowanie macierzy - w tym do potegi (-1) czyli
     * odwracanie macierzy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixExponentiation();

    /*
     * void mChooseMatrixProducts() - metoda obslugujaca
     * iloczyny: skalarny i wektorowy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mChooseMatrixProducts();

    /*
     * void mChooseMatrixOthers() - metoda obslugujaca pozostale
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
