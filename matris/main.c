#include <stdio.h>
#include <math.h>
#include "vmatris.h"




int main(){

    char exit = 'Y';
    int gate;
    int arr1[4][4], arr2[4][4];
    float arrF[4][4], ideArr[4][4];
    int row, column, row2, column2;

    while(exit== 'y' || exit=='Y'){

        printf("------------------------------\n");
        printf("|                            |\n");
        printf("| 1 -> Toplama               |\n");
        printf("| 2 -> Determinant Hesaplama |\n");
        printf("| 3 -> Tersini Alma          |\n");
        printf("| 4 -> Noktasal Carpim       |\n");
        printf("|                            |\n");
        printf("------------------------------\n");
        printf("\n\n");
        printf("Matris islemleri yapma uygulamasina hosgeldiniz!\n");
        printf("Lutfen yapmak istediginiz islemi secin: ");
        scanf("%d", &gate);
        while(1){
            if (gate<1 || gate>4){
                printf("Gecersiz secim!\nLutfen tekrar deneyin: ");
                scanf("%d", &gate);
            }
        else break;
        }



        switch(gate){






        case 1://Toplama işlemi
        printf("\nToplama islemi!\n\n");
        printf("Lutfen satir sayisini girin: ");
        scanf("%d", &row);
        row=control1(row);
        printf("Lutfen sutun sayisini girin: ");
        scanf("%d", &column);
        column=control1(column);

        
        printf("\n1. matris icin:\n");
        defineArr(row,column,arr1);
        printArr(row,column,arr1);

        printf("\n\n2. matris icin:\n");
        defineArr(row,column,arr2);
        printArr(row,column,arr2);

        sumArr(row, column,arr1,arr2);

        printf("\n\nMenuye donmek ister misiniz (Y/N): ");
        getchar();
        scanf("%s", &exit);
        break;






        case 2://Determinant işlemi
        printf("\nDeterminant Hesaplama!\n\n");
        printf("Determinant sadece kare matrislerde bulunabilir\n");
        printf("Lutfen satir ve sutun sayisini girin: ");
        scanf("%d", &row);
        row=control1(row);
        defineArr(row, row, arr1);
        printf("Girilen matris:\n");
        printArr(row, row, arr1);
        printf("\n\nMatrisin determinanti: ");

        if(row==1){
            printf("%d", detOne(row, arr1));
        }
        if(row==2){
            printf("%d", detTwo(row, arr1));
        }
        if(row==3){
            printf("%d", detThree(row, arr1));
        }
        if(row==4){
            printf("%d", detFour(row, arr1));
        }


        printf("\n\nMenuye donmek ister misiniz (Y/N): ");
        getchar();
        scanf("%s", &exit);
        break;
        
        

        case 3://Tersini alma işlemi
        printf("\nTersini Alma!\n\n");
        printf("Kare matrislerin determinanti alinabilir\n");
        printf("Lutfen satir ve sutun sayisini girin: ");
        scanf("%d", &row);
        row=control1(row);
        deineArrFloat(row,arrF);
        printf("Girilen matris:\n");
        printArrFloat(row,arrF);
        printf("\n");
        identityMatrix(row,ideArr);
        inverse(row, arrF, ideArr);
        


        printf("\n\nMenuye donmek ister misiniz (Y/N): ");
        getchar();
        scanf("%s", &exit);
        break;


        




        case 4://Noktasal çarpım işlemi
        printf("\nNoktasal Carpim!\n\n");
        printf("1. Matrisin sutun sayisi ile 2. matrisin satir sayisi esit olmali\n\n");
        printf("Lutfen 1. matris icin satir sayisini girin: ");
        scanf("%d", &row);
        printf("Lutfen 1. matris icin sutun sayisini girin: ");
        scanf("%d", &column);

        printf("Lutfen 2. matris icin satir sayisini girin: ");
        scanf("%d", &row2);
        printf("Lutfen 2. matris icin sutun sayisini girin: ");
        scanf("%d", &column2);

        while(1){
            if( column!=row2 || row<1 || row>4 || column<1 || column>4 || row2<1 || row2>4 || column2<1 || column2>4){
                printf("1. Matrisin sutun sayisi ile 2. matrisin satir sayisi esit olmali\n");
                printf("\nSatir ve sutun sayilari 1den kucuk 4ten buyuk olamaz!\n\n");
                printf("Lutfen 1. matris icin satir sayisini girin: ");
                scanf("%d", &row);
                printf("Lutfen 1. matris icin sutun sayisini girin: ");
                scanf("%d", &column);

                printf("Lutfen 2. matris icin satir sayisini girin: ");
                scanf("%d", &row2);
                printf("Lutfen 2. matris icin sutun sayisini girin: ");
                scanf("%d", &column2);
            }
            else break;
        }

        printf("\n1. matris icin:\n");
        defineArr(row,column,arr1);
        printArr(row,column,arr1);

        printf("\n\n2. matris icin:\n");
        defineArr(row2,column2,arr2);
        printArr(row2,column2,arr2);

        multiArr(row,column,row2,column2,arr1,arr2);

        printf("\n\nMenuye donmek ister misiniz (Y/N): ");
        getchar();
        scanf("%s", &exit);
        break;

        default:
        break;
        }
        
    }

    return 0;
}
