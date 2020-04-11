//
//  double_link_list.c
//  data_structure
//
//  Created by 程威 on 2020/4/11.
//  Copyright © 2020 程威. All rights reserved.
//

#include "double_link_list.h"


int len = 0;

void CreatDoLL(DoLinkList &phead,int num)//传递的为头节点的位置
{
    DoLinkList pnew,ptail;
    phead = (DoLinkList)malloc(sizeof(DoLNode));
    pnew = ptail = NULL;
    int i;
    if( NULlinklist == phead )
    {
        printf("分配节点失败\n");
    }
    phead->data = 0;
    phead->prior = phead;
    phead->next = phead;
    ptail = phead;//初始化节点
    for(i = 1;i <= num;i++)
    {
    pnew = (DoLinkList)malloc(sizeof(DoLNode)); //申请一个新节点
    printf("请输入第%d个值：",i);
    scanf("%d",&pnew->data);
    pnew->prior = ptail;//首先让新节点的prior指向当前的尾节点。
    pnew->next = phead;//再让新节点的next指向头节点，因此形成循环
    ptail->next = pnew;//让当前尾节点的next指向新节点
    phead->prior = pnew;//头节点的prior指向新节点，完成循环
    ptail = pnew;//再让当前节点成为新的尾节点。
    }
    len = num;
}
void Output_DLL(DoLinkList &space)
{   DoLinkList temp;//存储头节点的位置
    temp = space;
    while(space->next != temp)
    {
        space = space->next;
        printf("%d\n",space->data);
    }
   space = temp;
}
DoLinkList ElemGet(DoLinkList &pnode,int location)
{
    int i = 1;
    DoLinkList pnext;
    pnext = pnode;
    if(location > len||location < 0)
    {
        printf("错误\n");
        return ERROR;
    }
    else
    {
    if(location == 0)
    {
        return pnode;
    }
    else
    {
    while(pnext->next !=pnext)
    {
        pnext = pnext->next;
        if(i == location )
        {
            return pnext;
            break;
        }
        else
            i++;
    }
    }
    }
    return NULL;
}
int InsertAfter_DLL(DoLinkList &phead,int location,int elem)//结点之后插入
{
    DoLinkList temp;
    DoLinkList pnode;
    if(!(temp = ElemGet(phead,location)))
    {
        return ERROR; //确定插入的位置
    }
    if(!(pnode = (DoLinkList)malloc(sizeof(DoLNode))))
    {
        return ERROR;  //申请一个新的节点并且判断是否申请成功
    }
    pnode->data = elem;
    pnode->prior = temp;
    pnode->next = temp->next;
    temp->next = pnode;
    temp = pnode->next;
    temp->prior = pnode;
    len++;
    return OK;
}
DoLinkList InsertBefore_DLL(DoLinkList &phead,int location,int elem)//结点之前插入
{
    DoLinkList temp;
    DoLinkList pnode;
    if(!(temp = ElemGet(phead,location)))
    {
        return ERROR; //确定插入的位置
    }
    if(!(pnode = (DoLinkList)malloc(sizeof(DoLNode))))
    {
        return ERROR;  //申请一个新的节点并且判断是否申请成功
    }
    if(location != 0)
    {
    pnode->data = elem;
    pnode->next = temp;
    pnode->prior = temp->prior;
    temp->prior->next = pnode;
    temp->prior = pnode;
    len++;
    return phead;
    }
    else
    {
        phead->data = elem;
        temp = temp->prior;
        phead->prior = pnode;
        pnode->next = phead;
        pnode->prior = temp;
        pnode->data = 0;
        len++;
        return pnode;

    }
}

void Delete_DLL(DoLinkList &phead,int location)
{
   DoLinkList pnode,temp;
   pnode = ElemGet(phead,location);
   temp = pnode->prior;
   temp->next = pnode->next;
   temp = pnode->next;
   temp->prior = pnode->prior;
   free(pnode);
   pnode = NULL;
   len--;
}
void Destroy(DoLinkList &phead)
{
    DoLinkList temp;
    temp = phead;
    while(temp->next != phead)
    {
        DoLinkList temp_1;
        temp_1 = temp->next;
        free(temp);;
        temp = NULL;
        temp = temp_1;
    }
    free(phead);
    phead = NULL;
}
void ClearLinkList(DoLinkList &phead)
{
    DoLinkList temp;
    temp = phead;
    while(temp->next != phead)//示范除了头节点以外的所有结点
    {
        DoLinkList temp_1;
        temp_1 = temp->next;
        free(temp);;
        temp = NULL;
        temp = temp_1;
    }
    phead->next = phead->prior = phead;//初始化头节点
}
void AppendList(DoLinkList &phead)
{
    DoLinkList pnew,ptemp,ptemp_1;
    int num;
    printf("请输入新链表元素个数：");
    scanf("%d",&num);
    CreatDoLL(pnew,num);
    ptemp = pnew->prior;//指向新链表的尾节点
    ptemp_1 = phead->next->prior;//指向原链表的头节点
    pnew->next->prior = phead->prior;
    phead->prior->next = pnew->next;
    phead->prior = ptemp;
    ptemp->next = ptemp_1;
    free(pnew);
    pnew = NULL;
    len += num;

}
int StatueList(DoLinkList &phead)
{
    if(phead->next == phead||phead->prior == phead)
    {
        printf("该表为空表\n");
        return 0;
    }
    else
    {
        printf("该表非空\n");
        return 0;
    }

}
int menue()
{
    int i;
    printf("===================================\n");
    printf("1.创建链表    || 2.顺序输出链表    \n");
    printf("3.查找元素    || 4.结点后插入元素  \n");
    printf("5.修改元素    || 6.结点前插入元素  \n");
    printf("7.删除结点    || 8.销毁链表        \n");
    printf("9.重置链表    || 10.链表状态        \n");
    printf("11.扩展链表   || 12.退出           \n");
    printf("===================================\n");
    printf("请选择功能：");
    scanf("%d",&i);
    return i;
}
int DoLinkList_main()
{
    DoLinkList DL,pnode;
    int num;
    int location,data;
    int menu;//功能选项
    int elem;
    while(1)
    {
    menu = menue();
    if(menu == 1)
    {
    printf("请输入链表大小：");
    scanf("%d",&num);;
    CreatDoLL(DL,num);
    system("read -p 'press enter to continue...' var");
    system("clear");
    continue;
    }
    if(menu == 2)
    {
        Output_DLL(DL);
        system("read -p 'press enter to continue...' var");
        system("clear");
        continue;
    }
    if(menu == 3)
    {
    printf("请输入查找元素的位置：");
    scanf("%d",&location);
    pnode = ElemGet(DL,location);
    data = pnode->data;
    printf("第%d个元素为：%d\n",location,data);
    system("read -p 'press enter to continue...' var");
    system("clear");
    continue;
    }
   if(menu == 4)
    {
        printf("请输入插入元素位置：");
        scanf("%d",&location);
        printf("请输入插入元素的值：");
        scanf("%d",&elem);
        InsertAfter_DLL(DL,location,elem);
        system("read -p 'press enter to continue...' var");
        system("clear");
    }
   if(menu == 5)
   {
       int location,elem;
       DoLinkList ptemp;
       printf("输入修改结点的位置：");
       scanf("%d",&location);
       ptemp = ElemGet(DL,location);
       if(ptemp != ERROR)
       {
       printf("输入修改的值：");
       scanf("%d",&elem);
       ptemp->data = elem;
       }
       else
       {
           free(ptemp);
           ptemp = NULL;
       }
    }
   if(menu == 6)
    {
        printf("请输入插入元素位置：");
        scanf("%d",&location);
        printf("请输入插入元素的值：");
        scanf("%d",&elem);
        Dlinklist =InsertBefore_DLL(DL,location,elem);
        system("read -p 'press enter to continue...' var");
        system("clear");
    }
    if(menu == 7)
    {
        printf("请输入删除元素的位置：");
        scanf("%d",&location);
        Delete_DLL(DL,location);
        system("read -p 'press enter to continue...' var");
        system("clear");

    }
    if(menu == 8)
    {
        Destroy(DL);
        system("read -p 'press enter to continue...' var");
        system("clear");
    }
    if(menu == 9)
    {
        ClearLinkList(DL);
    }
    if(menu == 10)
    {
        StatueList(DL);
    }
    if(menu == 11)
    {
        AppendList(DL);
        
    }
    if(menu == 12)
    {
        break;
    }
    }
    return 0;
}

//多项式相关函数
int Polynomial_main()
{
    PN pa;
    int m;
    printf("输入多项式项数：");
    scanf("%d",&m);
    CreatPolyn(pa,m);
    PrintPolyn(pa,m);
    return 1;
    
}

int CreatPolyn(PN &P,int m)
{
    P = (PN)malloc(sizeof(Polynomial));
    PN pnew,ptemp;
    int i;
    if(!P)
    {
        printf("分配内存失败");
        return ERROR;
    }
    P->conef = P->expn = 0;
    P->next = NULL;
    ptemp = P;
    for(i = 0; i < m; i++)
    {
        pnew = (PN)malloc(sizeof(Polynomial));
        if(!pnew)
        {
            printf("分配结点失败");
            return ERROR;
        }
        printf("输入第%d项系数：",i+1);
        scanf("%f",&pnew->conef);
        printf("输入第%d项指数：",i+1);
        scanf("%d",&pnew->expn);
        ptemp->next = pnew;
        pnew->next = NULL;
        ptemp = pnew;
    }
    return OK;

}

void PrintPolyn(PN &p,int m)
{
    PN ptemp;
    ptemp = p;
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
        if(!ptemp->expn)
        {
            printf("%.1f",ptemp->conef);
        }
        else
        printf("+%.1fx^%d",ptemp->conef,ptemp->expn);

    }
    printf("\n");

}
/*void AddPolyn(PN &pa,PN &pb)//不想弄多项式的部分了  不弄了
{
    PN ptemp_a,ptemp_b;
    int tag;//用于
    ptemp_a = pa;
    ptemp_b = pb;
    while(ptemp_a->next != NULL)
    {
        ptemp_a = ptemp_a->next;
        while(ptemp_b->next != NULL)
        {
            ptemp_b = ptemp_b->next;
            if(ptemp_a->expn == ptemp_b->expn)
                break;
            else
            continue;
        }
        if(ptemp_b->next == NULL)
        {
            ptemp_b =
            
        }
        ptemp_a->conef = ptemp_a->conef +ptemp_b->conef;
    }
}*/
