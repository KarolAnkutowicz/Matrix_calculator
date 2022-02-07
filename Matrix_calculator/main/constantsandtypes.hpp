/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: constantsandtypes.hpp
 */

#ifndef CONSTANTSANDTYPES_HPP
#define CONSTANTSANDTYPES_HPP

/*
 * unsigned short typeSize - zdefiniowanie synonimu typu dla rozmiaru
 */
typedef unsigned short typeSize;



/*
 * char separatorElement, char startOfMatrix, char endOfMatrix,
 * char startOfRow, char endOfRow - stale znakowe pozwalajace
 * na odpowiednie wypisywanie i wczytywanie macierzy:
 * znaki otwierajace i zamykajace macierz i otwierajaca i zamykajace
 * kolejne wiersze oraz separator kolejnych elementow w wierszach.
 */
const char separatorElement = '_';
const char startOfMatrix = '[';
const char endOfMatrix = ']';
const char startOfRow = '<';
const char endOfRow = '>';



/*
 * char operatorScalarProduct - zdefiniowanie operatora iloczynu skalarnego
 */
const char operatorScalarProduct = 'o';

/*
 * char operatorCrossProduct - zdefiniowanie operatora iloczynu wektorowego
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
 * char operatorReversal - zdefiniowanie operatora  wyznaczania macierzy odwrotnej
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
 * char endOfProgram - zdefiniowanie operatora zakonczenia programu
 */
const char endOfProgram = 'k';

#endif // CONSTANTSANDTYPES_HPP

/* constantsandtypes.hpp */
/********** END_OF_FILE **********/
