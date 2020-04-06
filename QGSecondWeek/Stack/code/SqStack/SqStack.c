#include<stdio.h>
#include<stdlib.h>
#include "SqStack.h"

// 初始化顺序栈
Status initStack(SqStack *s,int sizes){
    s->elem = (ElemType*)malloc(sizeof(ElemType));
    s->top = -1;
    s->size = sizes;
    printf("初始化成功！\n");
    getchar();
    return SUCCESS;
}

// 是否为空
Status isEmptyStack(SqStack *s){
    if(s == NULL){
        printf("栈不存在，请先初始化！");
        getch();
        return ERROR;
    }else if(s->top == -1){
        printf("该顺序栈为空！\n按任意键继续");
        getch();
        return ERROR;
    }else{
        printf("该顺序栈不为空！\n按任意键继续");
        getch();
        return SUCCESS;
    }
}

// 得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
    if(s == NULL){
        printf("栈不存在，请先初始化！");
        getch();
        return ERROR;
    }else if(s->top == -1){
        printf("该链表为空！\n");
        getch();
        return ERROR;
    }else{
        *e = s->elem[s->top];
        printf("栈顶元素为：%d",*e);
        getch();
        return SUCCESS;
    }
}

// 清空栈
Status clearStack(SqStack*s){
    if(s->top == -1){
        printf("该链表已为空！\n");
        getch();
        return ERROR;
    }else{
        s->top = -1;
        printf("清空成功\n按任意键继续");
        getch();
        return SUCCESS;
    }
}

// 销毁栈
Status destroyStack(SqStack *s){
    if(s->elem == NULL){
        printf("请先初始化栈\n");
        return ERROR;
    }else{
        free(s->elem);
        s->top = -1;
        s->elem = NULL;
        printf("销毁成功\n按任意键继续");
        getch();
        return SUCCESS;
    }
    
}

// 检测栈长度
Status stackLength(SqStack *s){
    if(s->top == -1){
        printf("该链表为空！\n");
        getch();
        return ERROR;
    }else{
        printf("该栈长度为：%d",s->top+1);
        getch();
        return SUCCESS;
        }
}

// 入栈
Status pushStack(SqStack *s,ElemType data){
    printf("%d",s->elem);
    if(s->top == s->size-1){
        printf("该栈已满，无法入栈\n");
        getch();
        return ERROR;
    }else if(s->elem == NULL){
        printf("该栈不存在，请先初始化栈\n");
        getch();
        return ERROR;
    }else{    
        s->top++;
        s->elem[s->top] = data;
        printf("入栈成功！\n");
        getch();
        return SUCCESS;
    }
}
// 出栈
Status popStack(SqStack *s){
    if(s->top == -1){
        printf("该栈为空\n");
        getch();
        return ERROR;
    }else if(s->elem == NULL)
    {
        printf("该栈不存在，请先初始化栈\n");
        getch();
        return ERROR;
    }else{
        s->top--;
        printf("出栈成功\n");
        getch();
        return SUCCESS;
    }
}