#include<stdio.h>
#include<stdlib.h>
#include "./LinkStack.c"
#include "LinkStack.h"

int main(){
    system("chcp 65001");
    char option = '1';
    char trash[20];
    LinkStack stack;
    ElemType data;
    ElemType top;
    int flag = 0;
    while(option != '8'){
		printf("----------------------------------------\n\
-----------*欢迎进入链栈管理系统*-----------\n\
----------------------------------------\n\
--------------*请选择以下功能*--------------\n\
----------------------------------------\n\
||     1      ||-------->||初始化栈    ||\n\
||     2      ||-------->||清空链栈    ||\n\
||     3      ||-------->||入栈        ||\n\
||     4      ||-------->||出栈        ||\n\
||     5      ||-------->||栈顶元素    ||\n\
||     6      ||-------->||链栈长度    ||\n\
||     7      ||-------->||销毁链表    ||\n\
||     8      ||-------->||退出系统    ||\n\
----------------------------------------\n\
请选择功能(以第一个字符为标准):\
");
		scanf("%c",&option);
		gets(trash);
		switch(option){
            case '1':{
                initLStack(&stack);
                flag = 1;
            }
            case '2':{
                if(isExist(flag)){    
                    clearLStack(&stack);
                    break;
                }else{
                    break;
                }
            }
            case '3':{
                if(isExist(flag)){
                    printf("请输入栈值：");
                    if(scanf("%d",&data)){
                        pushLStack(&stack,data);
                        break;
                    }else{
                        printf("输入错误，请重新输入\n按任意键继续");
                        getch();
                        break;
                    }
                }else{
                    break;
                }
                
            }
            case '4':{
                if(isExist(flag)){
                    popLStack(&stack,&top);
                    break;
                }else{
                    break;
                }
                
            }
            case '5':{
                if(isExist(flag)){
                    getTopLStack(&stack,&top);
                    break;    
                }else{
                    break;
                }
                
            }
            case '6':{
                if(isExist(flag)){
                    LStackLength(&stack);
                    break;
                }else{
                    break;
                }
                
            }
            case '7':{
                destroyLStack(&stack);
                flag = 0;
                break;
            }
            case '8':{
                printf("感谢您的使用！\n");
                system("pause");
            }
            default:{
                printf("输入错误，请重新输入\n");
                system("pause");
                break;
            }

        }
        system("cls");
    }
}