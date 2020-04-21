#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"qgsort.c"

int main(){
    system("chcp 65001");
    int size,pos;
    int option;
    printf("===========初始化数组===========\n");
    printf("请输入数组的大小：");
    while(!scanf("%d",&size)){
        printf("输入错误，请重新输入：");
        getchar();
    };
    printf("请输入最高位数(1-5)：");
    scanf("%d",&pos);
    while(pos<1 || pos>5){
        printf("输入错误，请重新输入：");
        scanf("%d",&pos);
    };
    int a[size];
    srand((unsigned)time(NULL));
    switch(pos){
        case 1:{
            for(int i=0;i<size;i++){
                a[i] = rand()%10;
            }
            break;
        }
        case 2:{
            for(int i=0;i<size;i++){
                a[i] = rand()%100;
            }
            break;
        }
        case 3:{
            for(int i=0;i<size;i++){
                a[i] = rand()%1000;
            }
            break;
        }
        case 4:{
            for(int i=0;i<size;i++){
                a[i] = rand()%10000;
            }
            break;
        }
        case 5:{
            for(int i=0;i<size;i++){
                a[i] = rand();
            }
            break;
        }
    };
    printf("数据生成成功！\n");
    FILE *f;
    f = fopen("data.txt","w");
    for(int i=0;i<size;i++){
        fprintf(f,"%2d ",a[i]);
    }
    printf("数据已保存至data.txt\n");
    fclose(f);
    system("pause");
    system("cls");
    printf("==========请选择您的操作==========\n");
    printf("1.插入排序\n2.归并排序\n3.快速排序\n4.计数排序\n5.基数排序\n请选择：");
    scanf("%d",&option);
    while(option<1 || option>5){
        printf("输入错误，请重新输入:");
        scanf("%d",&option);
    };
    switch(option){
        case 1:{
            insertSort(a,size);
            printf("\n.\n.\n.\n插入排序完成!!!\n.\n.\n.\n数据存储在sortedData.txt中\n");
            FILE *s;
            s = fopen("sortedData.txt","w");
            for(int i=0;i<size;i++){
                fprintf(s,"%2d ",a[i]);
            };
            fclose(s);
            system("pause");
            break;
        }
        case 2:{
            int *temp = (int*)calloc(size,sizeof(int));
            MergeSort(a,0,size-1,temp);
            printf("\n.\n.\n.\n归并排序完成!!!\n.\n.\n.\n数据存储在sortedData.txt中\n");
            FILE *s;
            s = fopen("sortedData.txt","w");
            for(int i=0;i<size;i++){
                fprintf(s,"%2d ",a[i]);
            };
            fclose(s);
            system("pause");
            break;
        }
        case 3:{
            QuickSort_Recursion(a,0,size-1);
            printf("\n.\n.\n.\n快速排序完成!!!\n.\n.\n.\n数据存储在sortedData.txt中\n");
            FILE *s;
            s = fopen("sortedData.txt","w");
            for(int i=0;i<size;i++){
                fprintf(s,"%2d ",a[i]);
            };
            fclose(s);
            system("pause");
            break;
        }
        case 4:{
            CountSort(a,size);
            printf("\n.\n.\n.\n计数排序完成!!!\n.\n.\n.\n数据存储在sortedData.txt中\n");
            FILE *s;
            s = fopen("sortedData.txt","w");
            for(int i=0;i<size;i++){
                fprintf(s,"%2d ",a[i]);
            };
            fclose(s);
            system("pause");
            break;
        }
        case 5:{
            RadixCountSort(a,size);
            printf("\n.\n.\n.\n基数排序完成!!!\n.\n.\n.\n数据存储在sortedData.txt中\n");
            FILE *s;
            s = fopen("sortedData.txt","w");
            for(int i=0;i<size;i++){
                fprintf(s,"%2d ",a[i]);
            };
            fclose(s);
            system("pause");
            break;
        }
        
    }
    printf("按任意键退出\n");
    getch();
    return 0;
}