//
//  sort.c
//  algorithim
//
//  Created by 程威 on 2020/4/6.
//  Copyright © 2020 程威. All rights reserved.
//

#include "sort.h"

float Time[8] = {0,0,0,0,0,0,0,0};

void sort()
{
    List *list;
    int left,right;
    int flag = 0;
    int first = 0;
    int last = MAXSIZE-1;
    list = (List *)malloc(sizeof(List));
    do
    {
    switch(menue())
        {
            case 1:
                {
                    init_list(list);
                    printf("排序前：");
                    print_list(list);
                    insert_sort(list);
                    printf("排序后：");
                    print_list(list);
                    system("read -p 'press any key to continue ...' var");
                    system("clear");
                    continue;
                }
            case 2:
                {
                    init_list(list);
                    printf("排序前：");
                    print_list(list);
                    shell_sort(list);
                    printf("排序后：");
                    print_list(list);
                    system("read -p 'press any key to continue ...' var");
                    system("clear");
                    break;

                }
            case 3:{
                    init_list(list);
                    printf("排序前：");
                    print_list(list);
                    bubble_sort(list);
                    printf("排序后：");
                    print_list(list);
                    system("read -p 'press any key to continue ...' var");
                    system("clear");
                    break;

                        
                   }
            case 4:{
                    left = 0;
                    right = MAXSIZE-1;
                    init_list(list);
                    printf("排序前：");
                    print_list(list);
                    quick_sort(list,left,right);
                    printf("排序后：");
                    print_list(list);
                    system("read -p 'press any key to continue ...' var");
                    system("clear");
                    break;
                   }
            case 5:{
                    init_list(list);
                    printf("排序前：");
                    print_list(list);
                   select_sort(list);
                    printf("排序后：");
                    print_list(list);
                    system("read -p 'press any key to continue ...' var");
                    system("clear");
                    break;
                   }
            case 7:{
                    init_list(list);
                    printf("排序前：");
                    print_list(list);
                    merge_sort(list,first,last);
                    printf("排序后：");
                    print_list(list);
                    system("read -p 'press any key to continue ...' var");
                    system("clear");
                    break;
                   }
            case 9:
                {
                    print_time();
                    break;
                }
            case 10:
                {
                    flag = 1;
                    break;
                    
                }
        }
    }
    while(flag == 0 );

}


int menue()
{
    int i;
    printf("===================================\n");
    printf("1.插入排序    || 2.希尔排序        \n");
    printf("3.冒泡排序    || 4.快速排序        \n");
    printf("5.选择排序    || 6.堆排序          \n");
    printf("7.归并排序    || 8.基数排序        \n");
    printf("9.时间统计    || 10.退出               \n");
    printf("===================================\n");
    printf("请选择功能：");
    scanf("%d",&i);
    return i;
}

int init_list(List *list)
{
    srand((unsigned)time(NULL));
    int i;
    list->length = 0;
    for(i = 0;i < MAXSIZE;i++ )
    {
        list->r[i] = rand()%(20000-1+1)+1;//产生1到20000的随机数
        list->length++;
    }
    return 0;
}

void print_list(List *list)
{
    int i;
    for(i = 0;i < MAXSIZE;i++)
        {
        printf("%d ",list->r[i]);
        }
        printf("\n");
}


void insert_sort(List *list)
{//插入排序
    int i;
    int j;
    float start,end;
    start = clock();
    for(i = 1;i < list->length;i++)
    {
        j = i;
        while(j > 0)
        {
            if(list->r[j] < list->r[j-1])
            {
                swap(&(list->r[j]),&(list->r[j-1]));
            }
            --j;
        }
    }
    end = clock();
    Time[0] = (double)(end-start)/CLOCKS_PER_SEC;
}

void shell_sort(List *list)
{
    int dt = MAXSIZE/2;//增量
    int i;
    int j;
    int k;
    float start,end;//记录时间用
    start = clock();
    while(dt != 1)
    {//增量为1时停止
        for(k = 0;k < dt;k++)
        {//将数据分成dt 组序列
            for(i = 1;i < MAXSIZE/dt;i++)
             {//对该序列进行插入排序
                j = i*dt;//为该序列的第i+1个数
                while(j > 0)
                {
                    if(list->r[j+k] < list->r[j-dt+k])
                    {
                        swap(&(list->r[j+k]),&(list->r[j-dt+k]));
                    }
                    j -= dt;
                }
            }
        }
        dt = (int)(dt/2+0.5);
    }
    end = clock();
    Time[1] = (double)(end-start)/CLOCKS_PER_SEC;
}

void bubble_sort(List *list)
{//冒泡排序
    int i,j;
    j = list->length;
    float start,end;
    start = clock();
    while(j > 1)
    {
        for(i = 0;i < j;i++)
        {
            if(list->r[i+1] < list->r[i])
            {
                swap(&(list->r[i+1]),&(list->r[i]));
            }
        }
        j--;
    }
    end = clock();
    Time[2] = (double)(end-start)/CLOCKS_PER_SEC;
}

void quick_sort(List *list,int left,int right)
{//快速排序的递归实现
    int privot = 0;
    float start,end;
    start = clock();
    if(left < right)
    {
        privot = do_quick_sort(list,left,right);
        quick_sort(list,left,privot-1);
        quick_sort(list,privot+1,right);
    }
    end = clock();
    Time[3] = (double)(end-start)/CLOCKS_PER_SEC;
}


int do_quick_sort(List *list,int left,int right)
{//快速排序的核心算法
    int key = list->r[right];
    while (left < right)
    {
        while(left < right && list->r[left] <= key )
            left++;
        list->r[right] = list->r[left];//如果左边的值比key 大，则如此
        while(left < right && list->r[right] >=key )
            right--;
        list->r[left] = list->r[right];//如果右边的值比他小，则如此
    }
    list->r[right] = key;
    return left;
}


void select_sort(List *list)
{
    int i;
    int key = 0;//起始关键字
    float start,end;
    start = clock();
    while(key < MAXSIZE)
    {
        i = key+1;
        while(i < MAXSIZE)
        {
            if(list->r[i] <= list->r[key])
                swap(&(list->r[i]),&(list->r[key]));
            i++;
        }
        ++key;
    }
    end = clock();
    Time[4] = (double)(end-start)/CLOCKS_PER_SEC;
}

void do_merge(List *list,int first,int mid,int last)
{//归并两个数组到c
    int i = first;
    int j = mid+1;
    int m = mid;
    int n = last;
    int k = 0;
    int *temp;
    temp = (int *)malloc(sizeof(int)*(last - first+1));
    if(!temp)
        printf("temp初始化失败\n");
    while(i <= m && j <=n )
    {
        if(list->r[i] < list->r[j])
            temp[k++] = list->r[i++];
        else
            temp[k++] = list->r[j++];
    }
    while(i <= m)
    {
        temp[k++] = list->r[i++];
    }
    while(j <= n)
    {
        temp[k++] = list->r[j++];
    }
    for(i = first,k = 0;i <= last;i++,k++)
        list->r[i] = temp[k];
    free(temp);
}

void merge_sort(List *list,int first,int last)
{
    float start,end;
    start = clock();
    if(first < last)
    {
        int mid = (first + last)/2;
        merge_sort(list,first,mid);
        merge_sort(list,mid+1,last);
        do_merge(list,first,mid,last);
    }
    end = clock();
    Time[6] = (double)(end-start)/CLOCKS_PER_SEC;

}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
   *a = *b;
    *b = temp;
}

void print_time()
{
    printf("插入排序用时：%f毫秒\n",Time[0]*1000);
    printf("希尔排序用时：%f毫秒\n",Time[1]*1000);
    printf("冒泡排序用时：%f毫秒\n",Time[2]*1000);
    printf("快速排序用时：%f毫秒\n",Time[3]*1000);
    printf("选择排序用时：%f毫秒\n",Time[4]*1000);
    printf(" 堆 排序用时：%f毫秒\n",Time[5]*1000);
    printf("归并排序用时：%f毫秒\n",Time[6]*1000);
    printf("基数排序用时：%f毫秒\n",Time[7]*1000);
}

