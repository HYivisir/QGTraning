#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

// 初始化队列
void InitLQueue(LQueue **Q){
    *Q = (LQueue*)malloc(sizeof(LQueue));
    (*Q)->front = NULL;
    (*Q)->rear = NULL;
    (*Q)->length = 0;
    printf("初始化成功！\n");
    system("pause");
}  

// 摧毁队列
void DestoryLQueue(LQueue *Q){
    while(Q->front != NULL){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    Q->front = Q->rear =NULL;
    free(Q);
    printf("队列销毁成功！\n");
    system("pause");
}

// 队列是否为空
Status IsEmptyLQueue(const LQueue *Q){
    if(Q->front){
        return TRUE;
    }else{
        return FALSE;
    }
}

// 查看队头元素
Status GetHeadLQueue(LQueue *Q){
    if(Q->front != NULL){
        printf("队头元素为：");
        LPrint(Q->front->data);
        return TRUE;
    }else{
        printf("该队列为空！请入队！\n");
        system("pause");
        return FALSE;
    }
    
}

// 查看队列长度
int LengthLQueue(LQueue *Q){
    printf("队列长度为：%d",Q->length);
    return TRUE;
}

// 入队
Status EnLQueue(LQueue *Q, void *data){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    if(Q->front == NULL){
        Q->front = p;
        Q->rear = p;
    }else{
        Q->rear->next = p;
        Q->rear = p;
    }
    Q->length++;
    printf("入队成功！\n");
    system("pause");
 
    return TRUE;
}
// Status EnLQueue(LQueue *Q, int data){
//     Node* p = (Node*)malloc(sizeof(Node));
//     // p->data = (void*)malloc(sizeof(*data));
//     p->data = data;
//     p->next = NULL;
//     if(Q->front == NULL){
//         Q->front = p;
//         Q->rear = p;
//     }else{
//         Q->rear->next = p;
//         Q->rear = p;
//     }
//     Q->length++; 
//     printf("入队成功！");
//     system("pause");
//     return TRUE;
// }

// 出队
Status DeLQueue(LQueue *Q){
    Node *p;
    p = Q->front;
    if(p){
        Q->front = p->next;
        free(p);
        Q->length--;
        printf("出队成功！\n");
        system("pause");
        return TRUE;
    }else{
        printf("队列为空！\n");
        system("pause");
        return FALSE;
    } 
}
// 清空队列
void ClearLQueue(LQueue *Q){
    if(Q->front != NULL){
        Node* temp = Q->front;
        while(temp != NULL){
            Q->front = temp->next;
            free(temp);
            temp = Q->front;
        }
    };
    Q->front = Q->rear = NULL;
    Q->length = 0;
    printf("清空成功！\n");
    system("pause");
}

// 遍历操作
Status TraverseLQueue(LQueue *Q){
    Node *temp = Q->front;
    if(temp){
        while(temp != NULL){
            LPrint(temp->data);
            temp = temp->next;
        };
        return TRUE;
    }else{
        printf("队列为空！\n");
        system("pause");
        return FALSE;
    }
}
    
    
// 队列是否存在
Status isExist(int flag){
    if(flag){
        return TRUE;
    }else{
        printf("队列不存在，请先初始化\n");
        system("pause");
        return FALSE;
    }
}

// 数据类型
void pushData(void*data){
    char type;
    char trash[20];
    printf("请输入数据类型：\n");
    printf("1.int\n2.char\n3.float\n");
    scanf("%d",&type);
    while(type < 1 || type >3){
        printf("请重新输入(1-3)！\n");
        system("pause");
        scanf("%d",&type);
    };
    switch (type){
        case 1:{
            data = (void*)malloc(sizeof(int));
            printf("请输入入队的数据：\n");
            scanf("%d",(int*)data);
            break;
        }
        case 2:{
            data = (void*)malloc(sizeof(char));
            printf("请输入入队的数据：\n");
            scanf("%c",(char*)data);
            break;
        }
        case 3:{
            data = (void*)malloc(sizeof(float));
            printf("请输入入队的数据：\n");
            scanf("%f",(float*)data);
            break;
        }
        default:
            break;
    };
}

// 打印
void LPrint(void *q){
    printf("%d ",(int *)q);
}