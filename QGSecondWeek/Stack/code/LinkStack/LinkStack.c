#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

// 初始化栈
Status initLStack(LinkStack *s){
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    s->top = NULL;
    s->count = 0;
    printf("链表初始化成功！\n按任意键继续");
    return SUCCESS;
}

//判断栈是否存在
Status isEmpty(LinkStack *s){
    if(s->top == NULL){
        printf("该链栈为空！\n按任意键继续");
        getch();
        return ERROR;
    }else{
        printf("该链栈不为空！\n按任意键继续");
        getch();
        return SUCCESS;
    }
} 

// 得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
    if(s->top == NULL){
        printf("该链表为空！\n");
        getch();
        return ERROR;
    }else{
        *e =  s->top->data;
        printf("栈顶元素为：%d",s->top->data);
        getch();
        return SUCCESS;
    } 
}

// 清空链栈
Status clearLStack(LinkStack *s){
    if(s->top == NULL){
        printf("该链表为空！\n");
        getch();
        return ERROR;
    }else{
        LinkStackPtr latter,former;
        former = s->top;
        while(former!=NULL){
            latter = former -> next;
            free(former);
            former = latter;
        }
        s->top = NULL;
        s->count = 0;
        printf("清空成功！\n按任意键继续");
        getch();
        return SUCCESS;

    }
    
}
// 销毁链栈
Status destroyLStack(LinkStack *s){
    clearLStack(s);
    free(s->top);
    printf("销毁链栈成功！\n");
    getch();
    return SUCCESS;
}

// 链栈长度
Status LStackLength(LinkStack *s){
    if(s->top == NULL){
        printf("该链表为空！\n");
        getch();
        return ERROR;
    }else{
        
        printf("链栈长度为：%d",s->count);
        getch();
        return SUCCESS;
    }
}
// 入栈
Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p -> data = data;
    p->next = s->top;
    s->top = p;
    s->count ++;
    printf("入栈成功！\n按任意键继续");
    getchar();
    return SUCCESS;
}
//出栈
Status popLStack(LinkStack *s,ElemType *data){
    if(s->top == NULL){
        printf("该链表为空！\n");
        getch();
        return ERROR;
    }else{        
        *data = s->top->data;
        LinkStackPtr p = s->top;
        s->top = p->next;
        s->count--;
        free(p);
        printf("出栈成功！");
        getch();
        return SUCCESS;
    }
}

