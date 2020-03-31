#include<stdio.h>
#include<stdlib.h>
#include"linkedList.c"

int main(){
	system("chcp 65001");
	char option = '1';
	char trash[20];
	List L,p;
	int x,pos;
	while(option != '9'){
		printf("----------------------------------------\n\
-----------*欢迎进入队列管理系统*-----------\n\
----------------------------------------\n\
--------------*请选择以下功能*--------------\n\
----------------------------------------\n\
||     1      ||-------->||初始化列表  ||\n\
||     2      ||-------->||格式化列表  ||\n\
||     3      ||-------->||插入节点    ||\n\
||     4      ||-------->||删除节点    ||\n\
||     5      ||-------->||查询节点    ||\n\
||     6      ||-------->||遍历列表    ||\n\
||     7      ||-------->||打印列表    ||\n\
||     8      ||-------->||列表状态    ||\n\
||     9      ||-------->||退出系统    ||\n\
----------------------------------------\n\
请选择功能(以第一个字符为标准):\
");
		scanf("%c",&option);
		gets(trash);
		switch(option){
			case '1': {
				L = createList();
				p = L->next;
				getchar();
				system("cls");
				break;
			}
			case '2': {
				if(isEmpty(L)) {
					printf("该链表已为空\n按任意键继续");
					getchar();
					getchar()
					break;
					}
				deleteLinkedList(L);
				system("cls");
				break;
			}
			case '3': {
                printf("请输入您想插入元素的位置:");
                scanf("%d",&pos);
                printf("请输入元素的值(仅限数字):");
                scanf("%d",&x);
				L = insertEle(L,pos,x);
				getchar();
				system("cls");
				break;
			}
				
			case '4': {
				printf("请输入您想删除的位置");
				scanf("%d",&pos);
				L = deleteEle(L,pos);
				getchar();
				system("cls");
				break;
			}
			case '5': {
				printf("请输入您想查询的数据");
				scanf("%d",&x);
				EleSearch(L,x);
				system("cls");
				break;
			}
			case '6': {
				traverseList(L);
				system("cls");
				break;
			}
			case '7': {
				printList(L);
				getchar();
				system("cls");
				break;
			}
			case '8': {
				if(isEmpty(L)){
					printf("该链表为空！\n");
				}else{
					printf("该链表不为空！\n");
				}
				system("cls");
				break;
			}
			case '9': 
				printf("\n感谢您的使用\n\n");
				break;
			default: 
				system("cls");
				printf("\n\n\n输入错误，请重新输入\n\n\n");
				break;
				
		};

	}
	
	return 0;
	
}