#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"
#include<windows.h>

// 初始化队列
void InitAQueue(AQueue *Q){
    Q->front = Q->rear = 0;
    Q->length = 0;
    printf("初始化成功！\n");
    system("pause");
}


// 队列是否存在
int isExist(int flag){
    if(flag){
        return TRUE;
    }else{
        printf("队列不存在，请先初始化！\n");
        system("pause");
        return FALSE;
    }
}

// 检查队列是否为空
Status IsEmptyAQueue(AQueue *Q){
    if(Q->length == 0){
        printf("队列为空！\n");
        return TRUE;
    }else{
        return FALSE;
    }
}


// 销毁队列
void DestoryAQueue(AQueue *Q){
    int i;
    for(i=0;i<MAXQUEUE;i++){
        Q->data[i] = NULL;
    };
    printf("摧毁列表成功！\n");
    system("pause");
}


// 检查队列是否已满
Status IsFullAQueue(AQueue *Q){
    if(Q->length == MAXQUEUE){
        printf("队列已满！\n");
        system("pause");
        return TRUE;
    }else{
        return FALSE;
    }
}

// 获取头指针
Status GetHeadAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        printf("队列为空！请先入队！\n");
        system("pause");
        return FALSE;
    }else{
        APrint(Q->data[Q->front]);
    }
}

// 入队！
Status EnAQueue(AQueue *Q, int data){
    if(IsFullAQueue(Q)){
        return FALSE;
    }else{
        if(Q->length == 0){
            Q->data[Q->front] = data;
        }else{
            Q->rear = (Q->rear+1) % MAXQUEUE;
            Q->data[Q->rear] = data;
        }
        Q->length++;
        printf("入队成功！\n");
        system("pause");
        return TRUE;
    }
}

// 出队！
Status DeAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        return FALSE;
    }else{
        Q->front = (Q->front + 1) % MAXQUEUE;
        Q->length--;
        printf("出队成功！\n");
        system("pause");
        return TRUE;
    }
}

// 清空队列
void ClearAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        return;
    }else{
        while(Q->front = Q->rear){
            Q->data[Q->front] = NULL;
            Q->front = (Q->front + 1) % MAXQUEUE;
        }
        Q->front = Q->rear = 0;
        Q->length = 0;
        printf("清空成功！\n");
        system("pause");
    }
}

// 遍历
Status TraverseAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        return FALSE;
    }else{
        int front = Q->front;
        int rear = Q->rear;
        while(Q->front != Q->rear){
            APrint(Q->data[Q->front]);
            Q->front = (Q->front + 1) % MAXQUEUE;
        };
        APrint(Q->data[Q->front]);
        Q->front = front;
        Q->rear = rear;
    }
}

// 打印
void APrint(int q){
    printf("%d ",q);
}