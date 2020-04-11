//
//  stack.c
//  algorithim
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#include "stack.h"

void init_element(stack_elememt *elemmet,
                  int current_step,
                  position *position,
                  int direction) {
    elemmet = (stack_elememt *)malloc(sizeof(stack_elememt));
    
    elemmet->current_step = current_step;
    elemmet->seat = position;
    elemmet->direction = direction;
}

int init_stack(path_stack *stack)
{
    stack->base = (stack_elememt *)malloc(STACK_INIT_SIZE * sizeof(stack_elememt));
    if(!stack->base)
    {
    printf("分配内存失败\n");
    exit(-1);
    }
    stack->top = stack->base;
    stack->stack_size = STACK_INIT_SIZE;
    return 0;
}

stack_elememt* peek(path_stack *stack)
{
    stack_elememt *e = NULL;
    if(stack->base == stack->top)
    {
    printf("空栈\n");
    return 0;
    }
    *e = *(stack->top - 1);
    return e;
}

void push(path_stack *stack,stack_elememt *element)
{
    if(stack->top - stack->base >= stack->stack_size)
    {   stack->base = (stack_elememt *)realloc(stack->base,(stack->stack_size + STACKINCREMENT)*sizeof(stack_elememt));
        if(!stack->base) exit(-1);
     stack->top = stack->base + stack->stack_size;
     stack->stack_size += STACKINCREMENT;
    }
    *stack->top++ = *element;//++要优先于*
}

stack_elememt* pop(path_stack *stack)
{
    if(stack->top == stack->base)
    {
        printf("空栈\n");
        return NULL;
    }
    return --stack->top;
    
}

bool is_empty(path_stack *stack)
{
    return stack->base == stack->top;
}

void distroy_stack(path_stack *stack)
{
    stack->top = NULL;
    stack->stack_size = 0;
    free(stack->base);
}

void clear_stack(path_stack *stack)
{
    stack->top = stack->base;
}
