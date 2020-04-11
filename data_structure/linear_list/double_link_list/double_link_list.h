//
//  double_link_list.h
//  data_structure
//
//  Created by 程威 on 2020/4/11.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef double_link_list_h
#define double_link_list_h

#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef struct DoLNode
{
    int data;
    struct DoLNode *prior;
    struct DoLNode *next;
}DoLNode, *DoLinkList;   //DoLNode 现在是一个类型名了,循环双链表结点

typedef struct Polynomial
{
    float conef; //系数
    int   expn;//指数
   struct Polynomial *next;
}Polynomial,*PN;

//循环双链表ADT
void AppendList(DoLinkList &phead);
void CreatDoLL(DoLinkList &,int);
void Output_DLL(DoLinkList &);
void Delete_DLL(DoLinkList&,int);
void Destroy(DoLinkList&);
void ClearLinkList(DoLinkList&);
int  InsertAfter_DLL(DoLinkList &,int,int );//结点之后插入
int  StatueList(DoLinkList &);
int  menue();
int  DoLinkList_main();
DoLinkList ElemGet(DoLinkList &,int);
DoLinkList InsertBefore_DLL(DoLinkList &,int,int);//结点之前插入


//多项式实现ADT
int  PN_main();
int  CreatPolyn(PN &,int);
void PrintPolyn(PN &,int);
void AddPolyn(PN &,PN &);
void SubstractPolyn(PN &,Polynomial &);
void MultiplyPolyn(PN &,Polynomial &);
int  Polynomial_main();


#endif /* double_link_list_h */
