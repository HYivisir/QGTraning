#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"qgsort.c"

int main(){
    system("chcp 65001");
    char option;
    char trash[20];
    while(option != '5'){
        int flag=1;
        bignum();
        scanf("%c",&option);
        gets(trash);
        switch(option){
            case '1':{
                printf("==========测试结果==========\n");
                double before,diff;
                int i;
                int size = 10000;
                int* a = (int*)calloc(size,sizeof(int));
                int* temp = (int*)malloc(sizeof(int)*size);
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                insertSort(a,size);
                diff = clock() - before;
                printf("插入排序:%.0fms\n",diff);
                

                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                MergeSort(a,0,size-1,temp);
                diff = clock() - before;
                printf("归并排序:%.0fms\n",diff);


                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                QuickSort_Recursion(a,0,size-1);
                diff = clock() - before;
                printf("快速排序(递归版):%.0fms\n",diff);
                flag--;


                
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                CountSort(a,size);
                diff = clock() - before;
                printf("计数排序:%.0fms\n",diff);
                

                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                RadixCountSort(a,size);
                diff = clock() - before;
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
                int size = 50000;
                int* a = (int*)calloc(size,sizeof(int));
                int* temp = (int*)malloc(sizeof(int)*size);
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                insertSort(a,size);
                diff = clock() - before;
                printf("插入排序:%.0fms\n",diff);
                
                
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                MergeSort(a,0,size-1,temp);
                diff = clock() - before;
                printf("归并排序:%.0fms\n",diff);

                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                QuickSort_Recursion(a,0,size-1);
                diff = clock() - before;
                printf("快速排序(递归版):%.0fms\n",diff);


                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                CountSort(a,size);
                diff = clock() - before;
                printf("计数排序:%.0fms\n",diff);
                

                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                RadixCountSort(a,size);
                diff = clock() - before;
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
                int size = 200000;
                int* a = (int*)calloc(size,sizeof(int));
                int* temp = (int*)malloc(sizeof(int)*size);
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                insertSort(a,size);
                diff = clock() - before;
                printf("插入排序:%.0fms\n",diff);
                
                
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                MergeSort(a,0,size-1,temp);
                diff = clock() - before;
                printf("归并排序:%.0fms\n",diff);

                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                QuickSort_Recursion(a,0,size-1);
                diff = clock() - before;
                printf("快速排序(递归版):%.0fms\n",diff);


                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                CountSort(a,size);
                diff = clock() - before;
                printf("计数排序:%.0fms\n",diff);
                

                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                before = clock();
                RadixCountSort(a,size);
                diff = clock() - before;
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
                int size = 100;
                int* a = (int*)calloc(size,sizeof(int));
                int* temp = (int*)malloc(sizeof(int)*size);
                before = clock();
                for(count=0;count<100000;count++){

                    for(i=0;i<size;i++){
                        a[i] = rand()%1000; 
                    } 
                    insertSort(a,size);
                }
                diff = clock() - before;
                printf("插入排序:%.0fms\n",diff);


                before = clock();
                for(count=0;count<100000;count++){
                    for(i=0;i<size;i++){
                        a[i] = rand()%1000; 
                    }
                    MergeSort(a,0,size-1,temp);
                }
                
                diff = clock() - before;
                printf("归并排序:%.0fms\n",diff);
                
                before = clock();
                for(count=0;count<100000;count++){
                    for(i=0;i<size;i++){
                        a[i] = rand()%1000; 
                    }
                    QuickSort_Recursion(a,0,size-1);
                }
                diff = clock() - before;
                printf("快速排序(递归版):%.0fms\n",diff);

                before = clock();
                for(count=0;count<100000;count++){
                    for(i=0;i<size;i++){
                        a[i] = rand()%1000; 
                    }
                    CountSort(a,size);
                }
                diff = clock() - before;
                printf("计数排序:%.0fms\n",diff);
                
                before = clock();
                for(count=0;count<100000;count++){
                    for(i=0;i<size;i++){
                        a[i] = rand()%1000; 
                    }
                    RadixCountSort(a,size);
                }
                diff = clock() - before;
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