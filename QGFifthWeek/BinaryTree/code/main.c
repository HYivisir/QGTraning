#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.c"
int main(){
    system("chcp 65001");
    char option;
    char trash[20];
    int flag;
    char* definition;
    BiTree T;
    while(option != '9'){
        menu();
        scanf("%c",&option);
        gets(trash);
        switch(option){
            case '1':{
                if(isExist(flag)){
                    printf("树已初始化！\n");                    
                }else{
                    InitBiTree(&T);
                    flag = 1;
                }
                break;
            };
            case '2':{
                if(isExist(flag)){
                    printf("请输入字符串(以'#'表示无子节点)：\n");
                    CreateBiTree(&T,definition);
                    getchar();
                }else
                {
                    printf("树未初始化，请前往初始化！\n");
                }
                break;
            }
            case '3':{
                if(isExist(flag)){
                    DestroyBiTree(&T);
                    flag = 0;
                    printf("摧毁二叉树成功！\n");
                }else{
                    printf("树未初始化,没得销毁\n");
                }
                break;
            }
            case '4':{
                if(isExist(flag)){
                    PreOrderTraverse(&T,print);
                }else{
                    printf("树未初始化!\n");
                }
                printf("\n");
                break;
            }
            case '5':{
                if(isExist(flag)){
                    InOrderTraverse(&T,print);
                }else{
                    printf("树未初始化!\n");
                }
                printf("\n");
                break;
            }
            case '6':{
                if(isExist(flag)){
                    PostOrderTraverse(&T,print);
                }else{
                    printf("树未初始化!\n");
                }
                printf("\n");
                break;
            }
            case '7':{
                if(isExist(flag)){
                    LevelOrderTraverse(T,print);
                }else{
                    printf("树未初始化！\n");
                }
                break;
            }
            case '8':{
                if(isExist(flag)){
                    printf("请输入前缀表达式:\n");
                    buildPrTree(&T);
                    printf("前缀表达式的值为：%d\n",Value(&T));
                }else{
                    printf("树未初始化！\n");
                }
                break;
            }
            case '9':{
                printf("感谢您的使用！\n");
                system("pause");
                exit(1);
                break;
            }
            default:{
                printf("输入错误！请重新输入\n");
                break;
            }
        }
        system("pause");
        system("cls");
    }
}