#include<stdio.h>
#include<stdlib.h>
#include"searchMid.c"

int main(){
    system("chcp 65001"); 
    printf("双指针定位中间位置：\n");  
    Link L;
    L = createList();
    if(L){
        printList(L);
        searchMid(L);
    }else{
        printf("按任意键退出\n");
        getch();
    }
    return 0;
}