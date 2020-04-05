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
    initLStack(&stack);
    while(option != '9'){
		printf("----------------------------------------\n\
-----------*欢迎进入链栈管理系统*-----------\n\
----------------------------------------\n\
--------------*请选择以下功能*--------------\n\
----------------------------------------\n\
||     1      ||-------->||链栈状态    ||\n\
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
                isEmpty(&stack);
                break;
            }
            case '2':{
                clearLStack(&stack);
                break;
            }
            case '3':{
                printf("请输入栈值：");
                if(scanf("%d",&data)){
                    pushLStack(&stack,data);
                    break;
                }else{
                    printf("输入错误，请重新输入\n按任意键继续");
                    getch();
                    break;
                }
            }
            case '4':{
                popLStack(&stack,&top);
                break;
            }
            case '5':{
                getTopLStack(&stack,&top);
                break;
            }
            case '6':{
                LStackLength(&stack);
                break;
            }
            case '7':{
                destroyLStack(&stack);
                break;
            }
            case '9':{
                printf("感谢您的使用！\n按任意键退出");
                getch();


            }
            default:{
                printf("输入错误，请重新输入\n");
                getch();
                break;
            }

        }
        system("cls");
    }
}