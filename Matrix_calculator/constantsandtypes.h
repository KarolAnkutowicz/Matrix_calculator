/********** BEGIN_OF_FILE **********/
/* constantsandtypes.h */

#ifndef CONSTANTSANDTYPES_H
#define CONSTANTSANDTYPES_H

using namespace std;

/*
 * unsigned short typeSize - zdefiniowanie synonimu typu dla rozmiaru
 */
typedef unsigned short typeSize;
/*
 * char operatorScalarProduct - zdefiniowanie operatora iloczynu skalarnego wektorow
 */
const char operatorScalarProduct = 'o';
/*
 * char operatorCrossProduct - zdefiniowanie operatora iloczynu wektorowego wektorow
 */
const char operatorCrossProduct = 'x';
/*
 * char operatorLengthVector - zdefiniowanie operatora dlugosci wektora
 */
const char operatorLengthVector = 'L';
/*
 * char operatorDeterminant - zdefiniowanie operatora obliczania wyznacznika macierzy
 */
const char operatorDeterminant = 'D';
/*
 * char operatorReversal - zdefiniowanie operatora wyznaczania macierzy odwrotnej
 */
const char operatorReversal = '@';
/*
 * char operatorExponentiation - zdefiniowanie operatora potegowania macierzy
 */
const char operatorExponentiation = '^';
/*
 * char operatorTransposition - zdefiniowanie operatora transponowania macierzy
 */
const char operatorTransposition = 'T';

/*
 * char printHelp - zdefiniowanie operatora wyswietlania pomocy
 */
const char printHelp = '?';
/*
 * char endOfProgram1, char endOfProgram2 - zdefiniowanie operatorow zakonczenia dzialania programu
 */
const char endOfProgram1 = 'k';
const char endOfProgram2 = 'K';

#endif // CONSTANTSANDTYPES_H

/* constantsandtypes.h */
/********** END_OF_FILE **********/
