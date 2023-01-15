
#include <stdio.h>
#include <math.h>
#include "vmatris.h"



int control1(int x){

    while(1){
        if(x<1 || x>4){
            printf("\nGecersiz sayi\n");
            printf("Satir veya sutun sayisi 1den kucuk, 4ten buyuk olamaz!\n");
            printf("Satir sayisini girin: ");
            scanf("%d", &x);
        }
        else break;
    }

    return x;
}


int defineZero(int row, int column, int arr[row][column]){

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            arr[i][j]=0;
        }
    }
    
    return arr[row][column];
}


int defineArr(int row, int column, int arr[row][column]){

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("\nLutfen su elemani giriniz [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    
    return arr[row][column];
}


float deineArrFloat(int row, float arr[row][row]){

    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("\nLutfen su elemani giriniz [%d][%d]: ", i+1, j+1);
            scanf("%f", &arr[i][j]);
        }
    }

    return arr[row][row];
}


void printArr(int row, int column, int arr[row][column]){

    for(int i=0; i<row; i++){
        printf("\n|");
        for(int j=0; j<column; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("|\n");
    }
}


void printArrFloat(int row, float arr[row][row]){

    for(int i=0; i<row; i++){
        printf("\n|");
        for(int j=0; j<row; j++){
            printf("%5.2f ", arr[i][j]);
        }
        printf("|\n");
    }
}


void sumArr(int row, int column, int arr1[row][column], int arr2[row][column]){

    int sonuc[row][column];
    defineZero(row, column, sonuc);

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){

            sonuc[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("\n\nSonuc:\n");
    printArr(row, column, sonuc);
}


void multiArr(int row, int column, int row2, int column2, int arr[row][column], int arr2[row2][column2]){

    int sonuc[row][column2];
    defineZero(row, column2, sonuc);

    for(int i=0; i<row; i++){
        for(int j=0; j<column2; j++){
            for(int k=0; k<row2; k++){
                sonuc[i][j] += arr[i][k] * arr2[k][j];
            }
        }
    }

    printf("\n\nSonuc:\n");
    printArr(row, column2, sonuc);
}


int detOne(int row, int arr[row][row]){

    int det=0;
    det=arr[0][0];

    return det;
}


int detTwo(int row, int arr[row][row]){

    int det=0;
    det=((arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]));

    return det;
}


int detThree(int row, int arr[row][row]){

    int det=0;
    det=(arr[0][0]*arr[1][1]*arr[2][2])+(arr[0][1]*arr[1][2]*arr[2][0])+(arr[0][2]*arr[1][0]*arr[2][1])-(arr[0][2]*arr[1][1]*arr[2][0])-(arr[0][1]*arr[1][0]*arr[2][2])-(arr[0][0]*arr[1][2]*arr[2][1]);

    return det;
}


int detFour(int row, int arr[row][row]){

    int a, b;
    int det=0;
    int arr2[row][row];

    for(int i=0; i<row; i++){
        a=0;
        b=0;

        for(int j=1; j<row; j++){
            for(int k=0; k<row; k++){

                if(k==i){
                    continue;
                }

                arr2[a][b]=arr[j][k];
                b++;
                if(b==a-1){
                    a++;
                    b=0;
                }
            }
        }
        det += arr[0][i]*pow(-1, i)*detThree(3, arr2);
    }

    return det;
}


float identityMatrix(int row, float arr[row][row]){
    
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            if(i==j){
                arr[i][j]=1;
            }
            else{
            arr[i][j]=0;
            }
        }
    }
    return arr[row][row];
}


void inverse(int row, float arr[row][row], float iArr[row][row]){
    
    float a,b;
    for(int i=0; i<row; i++){
        a=arr[i][i];
            for(int j=0; j<row; j++){
                arr[i][j]=(arr[i][j])/a;
                iArr[i][j]=(iArr[i][j])/a;
            }
            for(int k=0; k<row; k++){
                if(k!=i){
                    b=arr[k][i];
                    for(int j=0; j<row; j++){
                        arr[k][j]=arr[k][j]-(arr[i][j]*b);
                        iArr[k][j]=arr[k][j]-(iArr[i][j]*b);
                    }
                }
            }
        }
    printf("\nGirilen matrisin tersi:\n");
    printArrFloat(row, iArr);
    
}
