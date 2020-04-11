//
//  maze.h
//  algorithim
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef maze_h
#define maze_h

#define LEN 10 // 迷宫大小

#include "stack.h"
#include "common.h"

void maze(void);

/// 初始化迷宫
int init_maze(int maze[][LEN]);

/// 打印迷宫
void print_maze(int maze[][LEN]);

/// 寻找迷宫出口路径
/// @param start 迷宫入口坐标
/// @param end  迷宫出口坐标
bool find_way_out(int maze[][LEN],position *start,position *end);

/// 判断是否成功找多迷宫的入口
/// @param position 当前位置
bool is_successfully_pass(int maze[][LEN],position *position);

/// 标记正确的路径坐标
/// @param current_position 当前位置
void mark_right_path(int maze[][LEN],position *current_position);

// todo
void print_mark(int [][LEN],position*);

position* next_position(position*,int);

#endif /* maze_h */
