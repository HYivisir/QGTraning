#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"
// 初始化二叉树
Status InitBiTree(BiTree *T){
    *T = (BiTree)malloc(sizeof(BiTNode));
    if(*T == NULL){
        printf("构造失败！\n");
        return ERROR;
    }else{
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->data = NULL;
        printf("初始化成功\n");
        return SUCCESS;
    }
}

// 摧毁二叉树
Status DestroyBiTree(BiTree *T){
    if((*T) != NULL){
        DestroyBiTree(&((*T)->lchild));
        DestroyBiTree(&((*T)->rchild));
        free(*T);
        return SUCCESS;
    }else{
        return ERROR;
    }
    
}

// 构建二叉树
Status CreateBiTree(BiTree *T, char* definition){
    definition = (char*)malloc(sizeof(char));
    (*definition) = getchar();
    if((*definition) == '#'){
        *T = NULL;
        return ERROR;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = *definition;
        CreateBiTree(&((*T)->lchild),definition);
        CreateBiTree(&((*T)->rchild),definition);
        return SUCCESS;
    }
}

// 先序遍历
Status PreOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    if(*T){
        visit((*T)->data);
        PreOrderTraverse(&((*T)->lchild),visit);
        PreOrderTraverse(&((*T)->rchild),visit);
    }else{
        return SUCCESS;
    }

}

// 中序遍历
Status InOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    if(*T){
        InOrderTraverse(&((*T)->lchild),visit);
        visit((*T)->data);
        InOrderTraverse(&((*T)->rchild),visit);
    }else{
        return SUCCESS;
    }

}

// 后序遍历
Status PostOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    if(*T){
        PostOrderTraverse(&((*T)->lchild),visit);
        PostOrderTraverse(&((*T)->rchild),visit);
        visit((*T)->data);
    }else{
        return SUCCESS;
    }

}




// 链式队列实现层序遍历
//链式队列结构
typedef struct node
{
    BiTNode* data;                  //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
} LQueue;

// 初始化队列
LQueue* InitLQueue(LQueue* Q){
    Q->front = (Node*)malloc(sizeof(Node));
    Q->front->next = NULL;
    Q->rear = Q->front;
    return Q;
}  
// 入队
void EnLQueue(LQueue *Q, BiTNode* node){
    Node* QNode = (Node*)malloc(sizeof(Node));
    QNode->data= node;
    QNode->next = NULL;
    Q->rear->next = QNode;
    Q->rear = QNode;
}
// 出队
BiTree DeLQueue(LQueue *Q){
    Node* LTemp = (Node*)malloc(sizeof(Node));
    LTemp = Q->front->next;
    if(LTemp->next == NULL){
        Q->rear = Q->front;
    }else{
        Q->front->next = LTemp->next;
    } 
    BiTree BNode = LTemp->data;
    free(LTemp);
    return BNode;
}


// 层序遍历
Status LevelOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    LQueue* queue = (LQueue*)malloc(sizeof(LQueue));
    queue = InitLQueue(queue);
    EnLQueue(queue,T);
    while (queue->rear != queue->front)
    {
        BiTree node = DeLQueue(queue);
        visit(node->data);
        if(node->lchild) EnLQueue(queue,node->lchild);
        if(node->rchild) EnLQueue(queue,node->rchild);
    }
    
}


// 前缀表达式
// 构造前缀表达式
void buildPrTree(BiTree *T){
    char s;
    scanf("%c",&s);
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = s;
    // 若为数字，不构造子
    if(s>='0'&&s<='9'){
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }else{
        buildPrTree(&((*T)->lchild));
        buildPrTree(&((*T)->rchild));
    }
}

// 求值
int Value(BiTree *T){
	char s=(*T)->data;
	
	if(s>='0'&&s<='9'){		//若为数字则直接返回 
		int num=(int)s-48;
		return num;
	}
	else{
		int l_result=Value(&((*T)->lchild));
		int r_result=Value(&((*T)->rchild));
		if(s=='+') return l_result+r_result;
		else if(s=='-') return l_result-r_result;
		else if(s=='*') return l_result*r_result;
		else if(s=='/') return l_result/r_result;
	}

}


// 打印
Status print(TElemType e){
    printf("\t%c",e);
    return SUCCESS;
}

// 是否存在
int isExist(int flag){
    if(flag){
        return 1;
    }else{
        return 0;
    }
}


void menu(){
    printf("----------------------------------------\n\
-----------*欢迎进入二叉树ADT*-----------\n\
----------------------------------------\n\
--------------*请选择以下功能*--------------\n\
----------------------------------------\n\
||     1      ||-------->||初始化树    ||\n\
||     2      ||-------->||构造树      ||\n\
||     3      ||-------->||销毁树      ||\n\
||     4      ||-------->||先序遍历    ||\n\
||     5      ||-------->||中序遍历    ||\n\
||     6      ||-------->||后序遍历    ||\n\
||     7      ||-------->||层序遍历    ||\n\
||     8      ||-------->||输入前缀求值||\n\
||     9      ||-------->||退出系统    ||\n\
----------------------------------------\n\
请选择功能(以第一个字符为标准):\
");
}

