#include<stdlib.h>
struct DataType {};/*定义一种数据类型*/
int operator != (const DataType& A,const DataType& B) {}/*定义对DataType的运算*/

typedef struct node {
	/*定义单链表的节点*/
	DataType data;
	struct node* next;
}LinkNode,*LinkList;

LinkList Head = NULL;					/*定义头指针*/

LinkList Creat_LinkList(void)
{/*函数功能：创建一个只有一个节点的空表
 入口参数：无
 返回标志：若创建成功，返回链表的地址；若失败，返回NULL
 注：使用时，用 Head=Creat_LinkList() */
	LinkList Head;
	Head = (LinkList)malloc(sizeof(LinkNode));
	if (Head) Head->next = NULL;				/*如果创建成功，将下一个节点设为零*/
	return Head;
}

LinkList Creat_NLinkList(int N)
{/*函数功能：创建一个有N个节点的空表(从前往后创建)
 入口参数：要创建表的节点数N
 返回标志：返回链表的头节点的位置，若创建失败则返回0*/
	LinkList Head;
	Head = (LinkList)malloc(sizeof(LinkNode));
	LinkList p = Head;
	N--;										/*第一个节点*/
	while (N--)
	{
		p->next = (LinkList)malloc(sizeof(LinkNode));
		p = p->next;
	}
	p->next = NULL;
	return (Head);
}

void Destory_LinkList(LinkList* Head)
{/*功能：销毁单链表
 入口参数：单链表的头指针
 返回值：无*/
	LinkList p;
	LinkList q;
	p = *Head;
	while (q = p)			/*一个个释放内存*/
	{
		p = p->next;
		free(q);
	}
	*Head = NULL;			/*头指针指向NULL*/
}

int Length_LinkList(LinkList Head)
{/*功能：求单链表的表长
 入口参数：头指针
 返回标志：返回一个整数，即表长*/
	int length = 0;
	LinkList p = Head;
	while (p->next)
	{
		length++;
		p = p->next;
	}
	return length;
}

LinkList Locate_LinkList_Position(LinkList Head, int i)
{/*功能：按序号查找，返回第i个节点的地址
 入口参数：头指针，节点位置i
 返回标志：第i个节点的地址,若输入不合法或者找不到，返回NULL*/

	if (Head->next == NULL)
		return NULL;			/*没有一个节点，返回NULL*/

	if (i <= 0 || i > Length_LinkList(Head))
		return NULL;			/*输入不合法或者超出长度范围，返回NULL*/

	LinkList p = Head;
	while (i--)
	{
		p = p->next;
	}
	return p;
}

LinkList Locate_LinkList_Value(LinkList Head, DataType x)
{/*功能：按数据查找，返回第一个与x相等的data出现的节点
 入口参数：头节点，数据x
 返回标志：返回第一个与x相等的数据出现的地址，若没有则返回NULL*/
	LinkList p;
	p = Head->next;
	while (p!= NULL && (x != p->data))			/*需要保证数据x的"!="有定义*/
	{
		p = p->next;
	}
	return p;
}

int Insert_LinkList(LinkList Head, int i, DataType x)
{/*功能：在单链表的第i个位置后插入一个带有数据x的节点
入口参数：头节点，节点位置i，数据x
返回标志：返回0表示不成功，返回1表示成功*/
	LinkList p = NULL;
	p = Locate_LinkList_Position(Head,i);		/*找到第i个节点的地址*/
	if(!p) return 0;					/*如果p的位置不合法，返回0*/
	
	LinkList q;
	q = (LinkList) malloc(sizeof(LinkNode));

	if(!q) return 0;					/*如果申请内存失败，返回0*/

	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;							/*插入成功*/
}

int Delete_LinkList(LinkList Head,int i)
{/*功能：删除第i个节点
入口参数：头节点，节点位置i
返回标志：返回0表示不成功，返回1表示成功*/

	if(Head == NULL||Head->next == NULL) return 0;		/*如果头节点为空或者指向空，返回0*/
	if(i<=0||i>Length_LinkList) return 0;		/*如果i不合法，返回0*/

	if(i == 1)						/*如果i=1，删除第一个节点*/
	{
		LinkList p;
		p = Head->next;
		Head = p->next;
		free(p);
		return 1;
	}

	LinkList p;
	p = Locate_LinkList_Position(Head,i-1);			/*找到第i-1个位置的地址*/

	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return 1;							/*删除成功*/
}
