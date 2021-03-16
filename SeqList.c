#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct DataType {
	/*定义一种数据类型*/
};
int operator == (const DataType& A,const DataType& B) {}/*定义对DataType的运算*/

DataType data[MAXSIZE];

typedef struct node {
	/*定义顺序表SeqList，由某种数据类型的数组data[]和int型的表长length组成*/
	DataType data[MAXSIZE];
	int length;
}SeqList, * PSeqList;							/*定义指向顺序表的指针类型PSeqList*/

PSeqList Init_List(void)
{/*创建一个空顺序表，入口参数无，返回一个指向顺序表的指针*/
	PSeqList PL;
	PL = (PSeqList)malloc(sizeof(SeqList));
	if (PL)										/*如果PL=0，说明空间分配失败*/
		PL->length = 0;
	return PL;
}

int Length_SeqList(SeqList L)
{/*求顺序表的长度，入口参数是所求的顺序表，返回表的长度*/
	return L.length;
}

int Insert_SeqList(PSeqList PL, int i, DataType x)
{/*功能：在顺序表的第i位前插入数据x；
 入口参数：顺序表指针，插入位置，插入元素；
 返回标志：1表示操作成功，0表示插入位置不合法，-1表示溢出，-2表示不存在
 */
	if (!PL)
	{
		printf("Error：表不存在");
		return -2;							/*表不存在，不能插入*/
	}

	if (PL->length >= MAXSIZE)
	{
		printf("Error：表溢出");
		return -1;							/*表满了，不能插入*/
	}

	if (i > PL->length + 1 || i <= 0)			/*检查位置的合法性*/
	{
		printf("Error：插入位置不合法");
		return 0;
	}

	int j;
	j = PL->length - 1;
	while (j >= i - 1)
	{
		PL->data[j + 1] = PL->data[j];		/*移动元素*/
		j--;
	}
	PL->data[i - 1] = x;					/*插入新元素*/
	PL->length++;							/*插入后表长增加*/
	return 1;								/*插入成功*/
}

int Delete_SeqList(PSeqList PL, int i)
{/*功能：删除顺序表的第i个元素
 入口参数：要操作的顺序表PL，元素的位置i
 返回标志：返回一个整型数，1表示操作成功，0表示删除位置不合法，-1表示表不存在
 */
	if (!PL)
	{
		printf("Error：表不存在");						/*表不存在，无法删除*/
		return -1;
	}
	if (i <= 0 || i > PL->length)
	{
		printf("Error：删除位置不合法");				/*删除位置不合法，无法删除*/
		return 0;
	}
	for (int j = i - 1; j < PL->length-1; j++)			/*顺序表整体向上移动*/
	{
		PL->data[j] = PL->data[j+1];
	}
	PL->length--;										/*删除成功，长度-1*/
	return 1;
}

int Destory_List(PSeqList PL)
{/*功能：销毁一个顺序表
 入口参数：要销毁的表PL
 返回标志：1表示操作成功，0表示表不存在
 */
	if (!PL)
	{
		printf("Error：表不存在");
		return 0;
	}
	else 
	{
		free(PL);
		return 1;
	}
}

int Locate_List(PSeqList PL,DataType x)
{/*功能：在循序表中寻找数据x，输出第一次出现的位置
 入口参数：循序表PL，数据x
 返回标志：返回一个整形数，为x首次出现的位置；若没有找到，则返回0
 */
	for (int i = 0; i < PL->length; i++)
	{
		if (PL->data[i] == x)							/*需要先定义DataType的相等运算*/
			return i + 1;								/*返回x的位置*/
	}
	return 0;											/*找不到这样的数据，返回0*/
}

int main()
{
}
