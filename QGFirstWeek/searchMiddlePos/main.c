#include<stdio.h>
#include<stdlib.h>
#include"searchMid.c"

int main(){
    system("chcp 65001"); 
    printf("双指针定位中间位置：\n");  
    Link L;
    L = createList();
    printList(L);
    searchMid(L);
    return 0;
}