#include<stdio.h>
#include<stdlib.h>

typedef struct DblNode{
    int data;
    struct DblNode *pre;
    struct DblNode *next;
}Node,*List;
typedef Node* DList;


// 初始化链表 L为头,n为指向终端的指针
DList createList(){
    Node *L,*p,*n;
    L = (DList)malloc(sizeof(Node));
    L->next = NULL;
    n = L;
    n->next = NULL;
    int x;
    if(scanf("%d",&x)==1){
        p = (DList)malloc(sizeof(Node));
        p->data = x;
        p->next = n->next;
        n->next = p;
        n = p;
    }else{
        printf("输入错误，请重新初始化");
        return NULL;
    };
    n->next = NULL;
    return L;
}
// 链表状态
int isEmpty(DList L){
    DList p = L->next;
    if(p->next == NULL) return 1;
    else return 0;
}

// 元素查找
void EleSearch(DList L,int x){
    DList p;
    p = L->next;
    int i;
    while(p!=NULL && p->data != x){
        p=p->next;
        i++;
    }
    if(p == NULL){
        printf("查询错误");
        getchar();
    }
    else{
        printf("定位成功！位置是：%d",i);
        getchar();
    };
}

// 插入元素 t为目标元素
DList insertEle(DList L,int pos,int x){
    DList p,t;
    p = L->next;
    int i;
    for(i=0;i<pos-1;i++){
        p = p->next;
    };
    t = (List)malloc(sizeof(Node));
    t->data = x;
    t->next = p->next;
    p->next->pre = t;
    t->pre = p;
    p->next = t;
    return L;
}

// 删除链表中的第i个节点
DList deleteEle(DList L ,int i){
    int pos = 1;
    DList p;
    p = L->next;
    if(p == NULL){
        printf("位置错误！");
    }else if(p->next == NULL){
        p->next->pre = NULL;
        free(p);
    }else{
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    };
    return L;
}
// 打印列表
void printList(DList L){
    if(isEmpty(L)){
        printf("链表为空！\n");
    }
    else{
        DList p = (List)malloc(sizeof(Node));
        p = L->next;
        while(p != NULL){
            printf("%d->",p->data);
            p = p->next;
        }
    };
    printf("\n");
}
// 遍历列表

void traverseList(DList L)
{
    DList p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n按任意键继续");
    getchar();
}
// 格式化链表
void deleteLinkedList(DList L){
	// if(!isExist(L)) return;
	L->next = NULL;
    L->pre = NULL;
	printf("格式化成功！\n按任意键继续");
	getchar();
}
 
