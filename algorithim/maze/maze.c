//
//  maze.c
//  algorithim
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#include "maze.h"

void maze() {
    int maze[LEN][LEN];
    init_maze(maze);
    print_maze(maze);
    position *start;
    position *end;
    start = (position *)malloc(sizeof(position));
    end = (position *)malloc(sizeof(position));
    start->x = 1;
    start->y = 1;
    end->x = 8;
    end->y = 8;
    find_way_out(maze,start,end);
    print_maze(maze);
    system("read -p ‘press enter to continue ’ var");
    system("clear");
}

int init_maze(int maze[][LEN])
{
   int i,j;
   srand((unsigned)time(NULL));//随机数发生器
   for(i = 0;i < LEN;i++)
       for(j = 0;j < LEN;j++)
       {
         if(i == 0 || i == LEN - 1)
             maze[i][j] = 0;//初始化墙壁
         else if(j == 0 || j == LEN -1)
             maze[i][j] = 0;//初始化墙壁
             else maze[i][j] = rand()%2;//初始化迷宫
               
       }
   maze[1][1] = 1;//入口点
   maze[LEN-2][LEN-2] = 1;//出口点
   return 1;
}

void print_maze(int maze[][LEN])
{
   int i,j;
   for(i = 0;i < LEN;i++)
   {
       for(j = 0;j < LEN;j++)
       {
           if(maze[i][j] == 0)
               printf("■");
           else if(maze[i][j] == 1)
               printf("□");
               else if(maze[i][j] == 3)
                   printf("★");
               

       }
       printf("\n");
    }

}

bool is_successfully_pass(int maze[][LEN],position *postion)
{
    if(maze[postion->x][postion->y] == 1)
        return true;//可以通过
    else
        return false;//不能通过


}
void mark_right_path(int maze[][LEN],position *current_position)
{
    maze[current_position->x][current_position->y] = 3;

}

position* next_position(position *current_position,int direction)
{
    position *next;
    int x;
    int y;
    x = current_position->x;
    y = current_position->y;
    next = (position *)malloc(sizeof(position));
    switch(direction)
    {
        case GO_UP:
        {
            next->x = x;
            next->y = y+1;
            break;
        }
        case GO_DOWN:
        {
            next->x = x+1;
            next->y = y;
            break;
        }
        case GO_LEFT:
        {
            next->x = x;
            next->y = y-1;
            break;
        }
        case GO_RIGHT:
        {//北
            next->x = x-1;
            next->y = y;
            break;
        }
    }
    return next;
}
void print_mark(int maze[][LEN],position *p)
{
    maze[p->x][p->y]  = -1;
}

bool find_way_out(int maze[][LEN],position *start,position *end)
{
    path_stack *stack = (path_stack *)malloc(sizeof(path_stack));
    init_stack(stack);
    position *current_position;//当前位置
    int current_step;//当前步骤
    current_position = start;
    current_step = 1;
    int mark = 0;
    do
    {
        if(is_successfully_pass(maze,current_position))
        {
            print_mark(maze, current_position);
            stack_elememt *e;
            init_element(e,current_step,current_position,GO_UP);
            push(stack,e);
            if(current_position == end)
            {
                printf("达到终点\n");
                return true;
            }
            current_position = next_position(current_position,GO_UP);
            current_step++;
            
        }
        else
        {//当前位置可以通过
            if(!is_empty(stack))
            {
                stack_elememt *e;
                e = pop(stack);
                while( e->direction == GO_RIGHT && !is_empty(stack))
                {
                    print_mark(maze,e->seat);
                    pop(stack);
                    mark = 0;
                }
                if(e->direction < GO_RIGHT)
                {
                    (e->direction)++;
                    push(stack,e);
                    current_position = next_position(e->seat,e->direction);
                    
                }

                
            }
        }

        
    }
    while(!is_empty(stack));
    
    return mark > 0;
    
}

