#include<stdio.h>
#include<stdlib.h>
#include"LQueue.c"

int main(){
    system("chcp 65001");
    LQueue* Queue;
    char option;
    char trash[20];
    int flag = 0;
    int data;
    while(option != '8'){
		printf("----------------------------------------\n\
-----------*欢迎进入链队管理系统*-----------\n\
----------------------------------------\n\
--------------*请选择以下功能*--------------\n\
----------------------------------------\n\
||     1      ||-------->||初始化队列  ||\n\
||     2      ||-------->||清空队列    ||\n\
||     3      ||-------->||入队        ||\n\
||     4      ||-------->||出队        ||\n\
||     5      ||-------->||队头元素    ||\n\
||     6      ||-------->||遍历队列    ||\n\
||     7      ||-------->||销毁队列    ||\n\
||     8      ||-------->||退出系统    ||\n\
----------------------------------------\n\
请选择功能(以第一个字符为标准):\
");
		scanf("%c",&option);
		gets(trash);
		switch(option){
            case '1':{
                InitLQueue(&Queue);
                flag = 1;
                break;
            }
            case '2':{
                if(isExist(flag)){
                    ClearLQueue(Queue);
                    break;
                }else{
                    break;
                }
            }
            case '3':{
                if(isExist(flag)){
                    // pushData(data);
                    printf("请输入入队数据：\n");
                    if(!scanf("%d",&data)){
                        printf("输入错误，请重新输入！");
                        system("pause");
                        getchar();
                        break;
                    }
                    EnLQueue(Queue,data);
                    break;
                }else{
                    break;
                }
            }
            case '4':{
                if(isExist(flag)){
                    DeLQueue(Queue);
                    break;
                }else{
                    break;
                }
            }
            case '5':{
                if(isExist(flag)){
                    GetHeadLQueue(Queue);
                    break;
                }else{
                    break;
                }
            }
            case '6':{
                if(isExist(flag)){
                    TraverseLQueue(Queue);
                    break;
                }else{
                    break;
                }
            }
            case '7':{
                if(isExist(flag)){
                    DestoryLQueue(Queue);
                    flag = 0;
                    break;
                }else{
                    break;
                }
            }
            case '8':{
                printf("感谢您的使用！\n");
                system("pause");
                break;
            }
            default:{
                printf("输入错误，请重新输入\n");
                system("pause");
                break;
            }

        }
        getchar();
        system("cls");
    }

    return 0;
}