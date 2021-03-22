/*顺序表实现栈*/

#include<stdlib.h>
#define MAXSIZE 100

typedef struct{
}DataType;                          /*定义数据类型*/

typedef struct{
	DataType data[MAXSIZE];
    int top;
}SeqStack,*PSeqStack;               /*定义栈*/

PSeqStack Init_SeqStack(void)
{/*功能：创建一个空栈，返回栈的地址
入口参数：无
返回标志：返回栈的地址，NULL表示创建失败*/
    PSeqStack PS;
    PS = (PSeqStack)malloc(sizeof(SeqStack));
    if(PS) PS->top = -1;                /*如果创建成功，把栈顶设为-1*/
    return PS;
}

int Empty_SeqStack(PSeqStack S)
{/*功能：判断是否为空栈
入口参数：栈的地址
返回标志：返回一个整数，1为空，0为非空*/
    if(S->top < 0) return 1;
    return 0;
}

int Push_SeqStack(PSeqStack S,DataType x)
{/*功能：入栈，在栈顶插入一个新元素x，x为栈顶元素
入口参数：栈的地址，新元素x
返回标志：返回1表示成功，返回0表示栈不存在，返回-1表示栈溢出
*/
    if(!S) return 0;
    if(S->top+1 >= MAXSIZE) return -1;
    S->top++;
    S->data[S->top] = x;
    return 1;
}

int Pop_SeqStack(PSeqStack S,DataType* x)
{/*功能：让栈顶元素出栈（删除栈顶元素），记录在x中
入口参数：栈的地址，用于储存出栈的数据x
返回标志：返回1表示成功，0表示失败*/
    if(!S) return 0;
    if(Empty_SeqStack(S)) return 0;
    *x = S->data[S->top];
    S->top --;
    return 1;
}

int GetTop_SeqStack(PSeqStack S, DataType* x)
{/*功能：取出栈顶元素（不删除），记录在x中
入口参数：栈的地址，用于储存栈顶的数据x
返回标志：1表示成功，0表示失败*/
    if(!S) return 0;
    if(Empty_SeqStack(S)) return 0;
    *x = S->data[S->top];
    return 1;
}

void Destory_SeqStack(PSeqStack S)
{/*功能：销毁顺序栈
入口参数：顺序栈的地址
返回标志：无*/
    if(S)
        free(S);
    S = NULL;
    return;
}

int Clear_SeqStack(PSeqStack S)
{/*功能：清空顺序栈
入口参数：栈的地址
返回标志：1表示成功，0表示失败*/
    if(!S) return 0;
    S->top = -1;
    return 1;
}