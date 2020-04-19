#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"qgsort.c"

int main(){
    system("chcp 65001");
    char option;
    char trash[20];
    while(option != '5'){
        bignum();
        scanf("%c",&option);
        gets(trash);
        switch(option){
            case '1':{
                printf("==========测试结果==========\n");
                double before,diff;
                int i;
                int* a = (int*)malloc(sizeof(int)*10000);
                for(i=0;i<10000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                insertSort(a,10000);
                diff = GetTickCount() - before;
                printf("插入排序:%.0fms\n",diff);
                
                
                for(i=0;i<10000;i++){
                    a[i] = rand()%1000; 
                }
                int size = sizeof(a)/sizeof(a[0]);
                int* temp = (int*)malloc(sizeof(int)*size);
                before = GetTickCount();
                MergeSort(a,0,size-1,temp);
                diff = GetTickCount() - before;
                printf("归并排序:%.0fms\n",diff);

                for(i=0;i<10000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                QuickSort_Recursion(a,0,size-1);
                diff = GetTickCount() - before;
                printf("快速排序(递归版):%.0fms\n",diff);


                for(i=0;i<10000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                CountSort(a,size);
                diff = GetTickCount() - before;
                printf("计数排序:%.0fms\n",diff);
                

                for(i=0;i<10000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                RadixCountSort(a,size);
                diff = GetTickCount() - before;
                printf("基数排序:%.0fms\n",diff);

                free((void*)temp);
                free((void*)a);
                system("pause");
                break;

            }
            case '2':{
                printf("==========测试结果==========\n");
                double before,diff;
                int i;
                int* a = (int*)malloc(sizeof(int)*50000);
                for(i=0;i<50000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                insertSort(a,50000);
                diff = GetTickCount() - before;
                printf("插入排序:%.0fms\n",diff);
                
                
                for(i=0;i<50000;i++){
                    a[i] = rand()%1000; 
                }
                int size = sizeof(a)/sizeof(a[0]);
                int* temp = (int*)malloc(sizeof(int)*size);
                before = GetTickCount();
                MergeSort(a,0,size-1,temp);
                diff = GetTickCount() - before;
                printf("归并排序:%.0fms\n",diff);

                for(i=0;i<50000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                QuickSort_Recursion(a,0,size-1);
                diff = GetTickCount() - before;
                printf("快速排序(递归版):%.0fms\n",diff);


                for(i=0;i<50000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                CountSort(a,size);
                diff = GetTickCount() - before;
                printf("计数排序:%.0fms\n",diff);
                

                for(i=0;i<50000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                RadixCountSort(a,size);
                diff = GetTickCount() - before;
                printf("基数排序:%.0fms\n",diff);

                free((void*)temp);
                free((void*)a);
                system("pause");
                break;

            }
            case '3':{
                printf("==========测试结果==========\n");
                double before,diff;
                int i;
                int* a = (int*)malloc(sizeof(int)*200000);
                for(i=0;i<200000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                insertSort(a,200000);
                diff = GetTickCount() - before;
                printf("插入排序:%.0fms\n",diff);
                
                
                for(i=0;i<200000;i++){
                    a[i] = rand()%1000; 
                }
                int size = sizeof(a)/sizeof(a[0]);
                int* temp = (int*)malloc(sizeof(int)*size);
                before = GetTickCount();
                MergeSort(a,0,size-1,temp);
                diff = GetTickCount() - before;
                printf("归并排序:%.0fms\n",diff);

                for(i=0;i<200000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                QuickSort_Recursion(a,0,size-1);
                diff = GetTickCount() - before;
                printf("快速排序(递归版):%.0fms\n",diff);


                for(i=0;i<200000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                CountSort(a,size);
                diff = GetTickCount() - before;
                printf("计数排序:%.0fms\n",diff);
                

                for(i=0;i<200000;i++){
                    a[i] = rand()%1000; 
                }
                before = GetTickCount();
                RadixCountSort(a,size);
                diff = GetTickCount() - before;
                printf("基数排序:%.0fms\n",diff);

                free((void*)temp);
                free((void*)a);
                system("pause");
                break;

            }
            case '4':{
                printf("==========测试结果==========\n");
                double before,diff;
                int i,count;
                int* a = (int*)malloc(sizeof(int)*100);
                before = GetTickCount();
                for(count=0;count<100000;count++){

                    for(i=0;i<100;i++){
                        a[i] = rand()%1000; 
                    } 
                    insertSort(a,100);
                }
                diff = GetTickCount() - before;
                printf("插入排序:%.0fms\n",diff);
                int size = sizeof(a)/sizeof(a[0]);


                before = GetTickCount();
                for(count=0;count<100000;count++){
                    for(i=0;i<100;i++){
                        a[i] = rand()%1000; 
                    }
                    int* temp = (int*)malloc(sizeof(int)*size);
                    MergeSort(a,0,size-1,temp);
                    free((void*)temp);
                }
                
                diff = GetTickCount() - before;
                printf("归并排序:%.0fms\n",diff);
                
                before = GetTickCount();
                for(count=0;count<100000;count++){
                    for(i=0;i<100;i++){
                        a[i] = rand()%1000; 
                    }
                    QuickSort_Recursion(a,0,size-1);
                }
                diff = GetTickCount() - before;
                printf("快速排序(递归版):%.0fms\n",diff);

                before = GetTickCount();
                for(count=0;count<100000;count++){
                    for(i=0;i<100;i++){
                        a[i] = rand()%1000; 
                    }
                    CountSort(a,size);
                }
                diff = GetTickCount() - before;
                printf("计数排序:%.0fms\n",diff);
                
                before = GetTickCount();
                for(count=0;count<100000;count++){
                    for(i=0;i<100;i++){
                        a[i] = rand()%1000; 
                    }
                    RadixCountSort(a,size);
                }
                diff = GetTickCount() - before;
                printf("基数排序:%.0fms\n",diff);

                free((void*)a);
                system("pause");
                break;
            }
            case '5':{
                printf("感谢您的使用！\n");
                system("pause");
                exit(1);
                break;
            }
            default:{
                printf("输入错误，请重新输入！\n");
                    system("pause");
                    break;
            }
        }
        system("cls");
    }
}