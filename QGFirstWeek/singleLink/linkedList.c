// Encoding:UTF-8
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int element;
	struct Node *next;
};

typedef struct Node* List;
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
// 初始化链表
List createLinkedList(void){
	List L = (List)malloc(sizeof(struct Node));
	List p = (List)malloc(sizeof(struct Node));
	p = NULL;
	if(!isExist(L)) return;
	L->element = 0;
	L->next = p;
	printf("初始化成功！\n按任意键继续");
	getch();
	return L;
}

// 格式化链表
void deleteLinkedList(List L){
	// if(!isExist(L)) return;
	List p = L->next;
	List temp;
	while(p != NULL){
		temp =  p->next;
		free(p);
		p = temp;
	};
	L->next = NULL;
	printf("格式化成功！\n按任意键继续");
	getchar();
}
// 链表是否为空
void isEmpty(List L){
	if(!isExist(L)) return;
	if(L->next == NULL){
		printf("链表为空\n按任意键继续");
		getchar();
	}else{
		printf("链表不为空\n按任意键继续");
	}
}
// 查询节点
List find(int x,List L){
	if(!isExist(L)) return NULL;
	List p = L->next;
	int i=1;
	while(p != NULL && p->element != x ){
		p = p->next;
		i++;
	}
	if(p == NULL){
		printf("定位失败\n按任意键继续");
		getch();
		return NULL;
	}
	else{
		printf("定位成功\n该节点位置为： %d",i);
		getch();
		return p;
		
	}
}
//查询前面的节点
List findFormer(int x,List L){
	List p = L;
	while(p->next != NULL && p->next->element != x){
		p = p->next;
		if(p->next == NULL) break;
	};
	if(p->next == NULL){
		printf("定位失败\n按任意键继续");
		getch();
		return NULL;
	}
	else{
		return p;
	};
}


// 删除节点
void deleteNode(List L){
	if(!isExist(L)) return;
	int x;
	printf("请输入您想删除的数据:");
	scanf("%d",&x);
	List p = find(x,L);
	List former;
	if(p == NULL){
		printf("数据不存在\n按任意键继续\n");
		getchar();
		return ;
	};
	former = findFormer(x,L);
	former->next = p->next;
	free(p);
	printf("删除成功\n按任意键继续");
	getchar();
}
//打印链表
void printList(List L){
	if(!isExist(L)) return;
	List p = L;
	printf("列表排序为:\n");
	while(p != NULL){
		printf("%d -> ",p->element);
		p=p->next;
	};
	printf("NULL\n按任意键继续\n");
	getchar();
}
// 逆序链表
void reverse(List L){
	if(!isExist(L)) return;
	// if(isEmpty){ 
	// 	printf("链表为空\n按任意键继续");
	// 	getchar();
	// 	return;
	// }
	List currentPst,nextPst,formerPst;
	currentPst = L->next;
	formerPst = NULL;
	while(currentPst != NULL){
		nextPst = currentPst->next;
		currentPst->next = formerPst;
		formerPst = currentPst;
		currentPst = nextPst;
		
	}
	L->next = formerPst;
	printf("逆序成功\n按任意键继续");
	getchar();
}

// 插入节点
void insertNode(List L,int x){
	if(!isExist(L)) return;
	List p;
	p = L->next;
	List temp = (List)malloc(sizeof (struct Node));
	if(temp == NULL){
		printf("内存错误\n按任意键继续");
		getchar();	
		getchar();
	};
	temp->element = x;
	temp->next = p;
	L->next = temp;
	printf("插入数据成功\n");
	printList(L);
}




