//
//  stack.h
//  c
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include "common.h"


#define STACK_INIT_SIZE 100 // 栈初始化大小
#define STACKINCREMENT 10 // 栈扩容增量

#define GO_UP 1
#define GO_DOWN 2
#define GO_LEFT 3
#define GO_RIGHT 4


typedef struct
{
    int x;
    int y;
} position;

typedef struct
{
    int current_step; // 当前步骤
    position *seat;
    int direction;
} stack_elememt;

typedef struct
{
    stack_elememt *base; // 栈顶
    stack_elememt *top; // 栈底
    int stack_size; // 栈容量
} path_stack; // 用于保存路径坐标的栈

void init_element(stack_elememt *elemmet,
                  int current_step,
                  position *position,int direction);

/// 初始化栈
/// @param stack 即将分配内存的栈
int init_stack(path_stack *stack);

///  获取栈顶元素，但是不弹出
/// @param stack 栈
stack_elememt* peek(path_stack *stack);

/// 入栈
/// @param stack 栈
/// @param element 需要入栈的元素
void push(path_stack *stack,stack_elememt *element);

///  弹出栈顶元素
/// @param stack  栈
stack_elememt* pop(path_stack *stack);

///  判断栈是否为空
/// @param stack 栈
bool is_empty(path_stack *stack);

/// 销毁栈，释放栈内存
/// @param stack 栈
void distroy_stack(path_stack *stack);

/// 清空栈
/// @param stack 栈
void clear_stack(path_stack *stack);

#endif /* stack_h */
