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
    while(option != '7'){
        menu();
        scanf("%c",&option);
        gets(trash);
        switch(option){
            case '1':{
                if(isExist(flag)){
                    printf("树已初始化！\n");                    
                }else{
                    InitBiTree(T);
                    flag = 1;
                }
                break;
            };
            case '2':{
                if(isExist(flag)){
                    printf("请输入字符串：\n");
                    CreateBiTree(T,definition);
                    getchar();
                }else
                {
                    printf("树未初始化，请前往初始化！\n");
                }
                break;
            }
            case '3':{
                if(isExist){
                    DestroyBiTree(T);
                    flag = 0;
                }else{
                    printf("树未初始化,没得销毁\n");
                }
                break;
            }
            case '4':{
                if(isExist){
                    PreOrderTraverse(T,print);
                }else{
                    printf("树未初始化!\n");
                }
                printf("\n");
                break;
            }
            case '5':{
                if(isExist){
                    InOrderTraverse(T,print);
                }else{
                    printf("树未初始化!\n");
                }
                printf("\n");
                break;
            }
            case '6':{
                if(isExist){
                    PostOrderTraverse(T,print);
                }else{
                    printf("树未初始化!\n");
                }
                printf("\n");
                break;
            }
            case '7':{
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