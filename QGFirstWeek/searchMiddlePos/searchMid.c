#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef Node* Link;


void searchMid(Link L){
    Link fast,slow,head;
    head = L;
    int i,pos=1;
    for(i=0;L!=NULL;i++){
        L = L->next;
    }
    if(i%2 == 0){
        printf("\n链表节点数为偶数，不存在中间位置\n按任意键继续");
        getch();
        return;
    }else if(i==1){
        printf("\n已找到中间位置：0\n该节点数据为：%d\n按任意键继续",head->data);
        getch();
    }else{
        slow = head->next;
        fast = head->next->next;

        while(fast->next){
            slow = slow->next;
            fast = fast->next->next;
            pos++;
        }
        printf("\n已找到中间位置：%d\n该节点数据为：%d\n按任意键继续",pos,slow->data);
        getch();
    }

}

Link createList(){
    Link head,p1,temp;
    int i=0,length;
    printf("请输入链表长度:");
    if(!(scanf("%d",&length))){
        printf("创建失败，请重新创建\n");
        getch();
        return NULL;
    }
    head  = (Link)malloc(sizeof(Node));
    printf("请输入第%d个节点的数据(int):",i);
    if(!(scanf("%d",&head->data))){
        printf("创建失败，请按规范数据类型输入\n");
        getch();
        return NULL;
    };
    head -> next = NULL;
    p1 = head;
    for(i=1;i<length;i++){
        temp = (Link)malloc(sizeof(Node));
        printf("请输入第%d个节点的数据(int):",i);
        if(!(scanf("%d",&temp->data))){
            printf("创建失败，请按规范数据类型输入\n");
            getch();
            return NULL;
        };
        temp->next = NULL;
        p1->next = temp;
        p1 = temp;
    };
    return head;
}

void printList(Link L){
    Link p1;
    p1 = L;
    printf("初始序列为：\n");
    while(p1 != NULL){
        printf("%d->",p1->data);
        p1 = p1->next;
    };
}

