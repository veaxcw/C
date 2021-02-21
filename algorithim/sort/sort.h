//
//  sort.h
//  algorithim
//
//  Created by 程威 on 2020/4/6.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#define MAXSIZE 7

typedef struct{
    int r[MAXSIZE];
    int length;
    
}List;

enum FUNCTION {
    INSERT = 1, SHELL, BUBBLE, QUICK, SELECT, HEAP, MERGE, BASE, TIME_COUNT, EXIT
};

/// 排序
void sort(void);

/// 初始化list
/// @param list list
int  init_list(List *list);

/// 打印列表
/// @param list 打印的列表
void print_list(List *list);

/// 插入排序
/// @param list 排序的列表
void insert_sort(List *list);

/// 希尔排序
/// @param list 排序的列表
void shell_sort(List *list);

/// 冒泡排序
/// @param list 排序的列表
void bubble_sort(List *list);

/// 交换两个数字的位置
void swap(int *,int *);

/// 快速排序
/// @param list 排序的列表
/// @param left left descriptio左边的值
/// @param right 右边的值
void quick_sort(List *list,int left,int right);

/// 递归快速排序
/// @param list 排序的列表
/// @param left left descriptio左边的值
/// @param right 右边的值
int  do_quick_sort(List *list,int left,int right);

/// 选择排序排序
/// @param list 排序的列表
void select_sort(List *list);

/// 归并排序
/// @param list 排序的列表
/// @param first 第一个数
/// @param last  最后一个数字
void merge_sort(List *list,int first,int last);

/// 归并两个数组到c
/// @param list  排序的列表
/// @param first  首个
/// @param mid  中间那个
/// @param last  最后一个
void do_merge(List *list,int first,int mid, int last);

/// 打印时间
void print_time(void);

/// 排序菜单
int menue(void);

void do_sort(enum FUNCTION sort_type, List *list);

#endif /* sort_h */
