
#ifndef vmatris_h
#define vmatris_h


int control1(int x);
int defineZero(int row, int column, int arr[row][column]);
int defineArr(int row, int column, int arr[row][column]);
float deineArrFloat(int row, float arr[row][row]);
void printArr(int row, int column, int arr[row][column]);
void printArrFloat(int row, float arr[row][row]);
void sumArr(int row, int column, int arr1[row][column], int arr2[row][column]);
void multiArr(int row, int column, int row2, int column2, int arr[row][column], int arr2[row2][column2]);
int detOne(int row, int arr[row][row]);
int detTwo(int row, int arr[row][row]);
int detThree(int row, int arr[row][row]);
int detFour(int row, int arr[row][row]);
float identityMatrix(int row, float arr[row][row]);
void inverse(int row, float arr[row][row], float iArr[row][row]);


#endif
