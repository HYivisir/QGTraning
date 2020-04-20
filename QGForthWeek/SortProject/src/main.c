#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"qgsort.c"

int main(){
    system("chcp 65001");
    char option;
    char trash[20];
    int size;
    while(option != 6){
        menu();
        scanf("%c",&option);
        gets(trash);
        switch(option){
            case '1':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int a[size],i;                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                insertSort(a,size);
                printf("插入排序完成:\n");
                PrintArr(a,size);
                system("pause");
                break;
            }
            case '2':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int a[size],i;
                int* temp = (int*)malloc(sizeof(int)*size);                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                MergeSort(a,0,size-1,temp);
                printf("归并排序完成:\n");
                PrintArr(a,size);
                system("pause");
                break;
            }
            case '3':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                };
                int a[size],i;                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                QuickSort_Recursion(a,0,size-1);
                printf("快速排序(递归版)完成:\n");
                PrintArr(a,size);
                system("pause");
                break;
            }
            case '4':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int a[size],i;                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                CountSort(a,size);
                printf("计数排序完成:\n");
                PrintArr(a,size);
                system("pause");
                break;
            }
            case '5':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int a[size],i;                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%1000; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                RadixCountSort(a,size);
                printf("基数排序完成:\n");
                PrintArr(a,size);
                system("pause");
                break;
            }
            case '6':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int a[size],i;                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%3; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                ColorSort(a,size);
                printf("颜色排序完成:\n");
                PrintArr(a,size);
                system("pause");
                break;
            }
            case '7':{
                printf("请输入数组的长度:");
                while(!scanf("%d",&size)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int key;
                printf("您需要查询第几小的数字呢:");
                while(!scanf("%d",&key)){
                        printf("输入错误，请重新输入:");
                        getchar();
                }
                int a[size],i;                
                srand((unsigned)(time(NULL)));
                for(i=0;i<size;i++){
                    a[i] = rand()%100; 
                }
                printf("已随机生成数组:\n");
                PrintArr(a,size);
                int target = researchKey(a,size,key-1);
                printf("第%d小的值为：%d\n",key,target);
                system("pause");
                break;
            }
            case '8':{
                printf("感谢您的使用！\n");
                system("pause");
                exit(1);
                break;
            }
            default:{
                printf("输入错误，请重新输入！\n");
                break;
            }      
        }
        getchar();
        system("cls");
    }
    return 0;
}