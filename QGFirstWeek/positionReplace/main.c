// 实现链表的奇偶位置更换
#include<stdio.h>
#include<stdlib.h>
#include"posReplace.c"


int main(){
    system("chcp 65001");
    printf("奇偶位置进行调换：\n");
    Link L;
    L = createList();
    if(L){
        printList(L);
        Replace(L);
        getch();
    }else{
        printf("按任意键退出\n");
        getch();
    }
    return 0;
}
