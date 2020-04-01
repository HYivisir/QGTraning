#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef Node* Link;

void Replace(Link L){
    Link odd,even,former,later,H;
    even = L;
    odd = even->next;
    // 第一次置换
    later = odd->next;
    odd->next = even;
    even->next = later;
    H = odd;
    former = even;
    even = even->next;
    odd = even->next;
    // 
    while(odd && even){
        later = odd->next;
        odd->next = even;
        even->next = later;
        former->next = odd;
        former = even;
        // if(even->next && odd->next){
        even = even->next;
        odd = even->next;
        // }
    }
    // 打印
    
    printf("\n换序完成\n奇偶位置变换后：\n");
    while (H != NULL)
    {
        printf("%d->",H->data);
        H = H -> next;
    };
    printf("\n按任意键继续\n");
    getch();
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

Link createList(){
    Link head,p1,temp;
    int i=0,length;
    printf("请输入链表长度:");
    scanf("%d",&length);
    head  = (Link)malloc(sizeof(Node));
    printf("请输入第%d个节点的数据(int):",i);
    scanf("%d",&head->data);
    p1 = head;
    for(i=1;i<length;i++){
        temp = (Link)malloc(sizeof(Node));
        printf("请输入第%d个节点的数据(int):",i);
        scanf("%d",&temp->data);
        temp->next = NULL;
        p1->next = temp;
        p1 = temp;
    };
    return head;
}