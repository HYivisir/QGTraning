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
// 搜索节点
List find(int pos,List L){
	if(!isExist(L)) return NULL;
	List p = L->next;
	int i=0;
	for(i;i <= pos;i++){
		p = p->next;
		if(p == NULL){
			printf("\n未找到该节点\n按任意键继续");
			getch();
			return NULL;
		};
	}
	printf("定位成功！\n");
	getch();
	return p;
}

// 查询节点
void searchNode(int x,List L){
	if(!isExist(L)) return NULL;
	List p = L->next;
	int i=0;
	int flag = 0;
	while(p != NULL){
		if(p->element == x ){
			flag = 1;
			printf("定位成功\n节点位置为： %d\n",i);
		}
		p = p->next;
		i++;
	}
	if(flag == 0){
		printf("定位失败\n按任意键继续");
		getch();
		return;
	};	
	getch();
	}

//查询前面的节点
List findFormer(int pos,List L){
	List p = L;
	int i=0;
	for(i;i <= pos;i++){
		p = p->next;
		if(p == NULL){
			printf("\n未找到该节点\n按任意键继续");
			getch();
			return NULL;
		};
	}
	printf("定位成功！\n");
	getch();
	return p;
}


// 删除节点
void deleteNode(List L){
	if(!isExist(L)) return;
	int pos;
	printf("请输入您想删除的位置:");
	scanf("%d",&pos);
	List p = find(pos,L);
	List former;
	if(p == NULL){
		printf("\n数据不存在\n按任意键继续\n");
		getchar();
		return ;
	};
	former = findFormer(pos-1,L);
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




