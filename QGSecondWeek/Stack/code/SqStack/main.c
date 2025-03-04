#include<stdio.h>
#include<stdlib.h>
#include"SqStack.c"
#include"SqStack.h"

int main(){
    system("chcp 65001");
    char option = '1';
    char trash[20];
    SqStack stack;
    ElemType data;
    ElemType size;
    int flag = 0;
    while(option != '9'){
		printf("-----------------------------------------\n\
-----------*欢迎进入顺序栈管理系统*------\n\
-----------------------------------------\n\
--------------*请选择以下功能*-----------\n\
-----------------------------------------\n\
||     1      ||-------->||初始化栈    ||\n\
||     2      ||-------->||清空栈      ||\n\
||     3      ||-------->||入栈        ||\n\
||     4      ||-------->||出栈        ||\n\
||     5      ||-------->||栈顶元素    ||\n\
||     6      ||-------->||栈长度      ||\n\
||     7      ||-------->||销毁栈      ||\n\
||     8      ||-------->||顺栈状态    ||\n\
||     9      ||-------->||退出系统    ||\n\
-----------------------------------------\n\
请选择功能(以第一个字符为标准):\
");
		scanf("%c",&option);
		gets(trash);
		switch(option){
            case '1':{
            while(flag == 0){
                printf("请输入栈的长度：\n");
                flag = scanf("%d",&size);
                gets(trash);
                if(flag){
                    initStack(&stack,size);
                    system("cls");
                }else{
                    printf("输入错误，请重新输入\n");
            }
    }
                
            }
            case '2':{
                if(isExist(flag)){
                    clearStack(&stack);
                    break;
                }else{
                    break;
                }
                
            }
            case '3':{
                if(isExist(flag)){
                    printf("请输入栈值(int)：");
                    if(scanf("%d",&data)){
                        pushStack(&stack,data);
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
                    popStack(&stack);
                    break;
                }else{
                    break;
                }
                
            }
            case '5':{
                if(isExist(flag)){
                    getTopStack(&stack,&data);
                    break;
                }else{
                    break;
                }
                
            }
            case '6':{
                if(isExist(flag)){                
                    stackLength(&stack);
                    break;
                }else{
                    break;
                }
            }
            case '7':{
                if(isExist(flag)){
                    destroyStack(&stack);
                    flag = 0;
                    break;
                }else{
                    break;
                }
                
            }
            case '8':{
                if(isExist(flag)){
                    isEmptyStack(&stack);
                    break;
                }else{
                    break;
                }
                
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

        };
        system("cls");
    };
}
