#include<stdio.h>
#include<stdlib.h>

typedef struct DblNode{
    int data;
    struct DblNode *pre;
    struct DblNode *next;
}Node,*List;
typedef Node* DList;

// 链表是否存在
int isExist(List L){
	if(L == NULL){
		printf("链表不存在\n请先初始化列表");
		getch();
		return 0;
	}else{
		return 1;
	};
}


// 初始化链表 L为头,n为指向终端的指针
DList createList(){
    Node *L,*p,*n;
    L = (DList)malloc(sizeof(Node));
    L->next = NULL;
    n = L;
    n->next = NULL;
    int x = 0;
    p = (DList)malloc(sizeof(Node));
    p->data = x;
    p->next = n->next;
    n->next = p;
    n = p;
    n->next = NULL;
    printf("初始化成功！\n按任意键继续");
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
    if(!isExist(L)) return;
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

// 插入元素
DList insertEle(DList L,int x){
    if(!isExist(L)) return;
    DList p,t;
    p = L->next;
    t = (List)malloc(sizeof(Node));
    t->data = x;
    t->next = p;
    L->next = t;
    p->pre = t;
    t->pre = L;
    L->next = t;
    printf("插入数据成功\n");
	printList(L);
    getchar();
    return L;
}

// 删除链表中的第i个节点
DList deleteEle(DList L ,int i){
    if(!isExist(L)) return;    
    int pos = 1;
    DList p;
    p = L->next;
    if(p == NULL){
        printf("位置错误！\n按任意键继续");
        getchar();
    }else if(p->next == NULL){
        p->next->pre = NULL;
        free(p);
        printf("删除成功\n按任意键继续");
	    getchar();
    }else{
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
        printf("删除成功\n按任意键继续");
	    getchar();
    };
    return L;
}
// 打印列表
void printList(DList L){
    if(!isExist(L)) return;    
    if(isEmpty(L)){
        printf("链表为空！\n");
    }
    else{
        printf("列表顺序为：\n");
        DList p = (List)malloc(sizeof(Node));
        p = L->next;
        while(p->next != NULL){
            printf("%d->",p->data);
            p = p->next;
        };
        printf("0");
    };
    printf("\n");
}
// 遍历列表

void traverseList(DList L)
{
    if(!isExist(L)) return;
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
 
