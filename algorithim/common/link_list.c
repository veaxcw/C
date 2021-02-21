//
// Created by 程威 on 2021/2/21.
//

#include "link_list.h"

/**
 * push node to list
 *
 * @node node
 * @list list
 * **/
void do_push(NodePtr node, LinkListPtr list) {
    if (NULL == list) {
        printf("empty list\n");
    }
    if (NULL == node ) {
        printf("empty node do nothing\n");
    }
    if (list->size == 0) {
        list->size++;
        list->head = node;
        list->tail = list->head;
        return;
    }
    node->pre = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

void do_add(int data, LinkListPtr list) {
    NodePtr nodePtr = (NodePtr)
            malloc(sizeof(struct Node));
    nodePtr->data = data;
    do_push(nodePtr, list);
}

void do_print(LinkListPtr list) {
    if (NULL == list || list->size == 0) {
        printf("empty list\n");
    }
    NodePtr node = list->head;
    int size = 0;
    while (NULL != node) {
        printf("node data:%d, index:%d\n", node->data, size++);
        node = node->next;
    }
}


LinkListPtr newLinkList() {
    LinkListPtr list = (LinkListPtr)
            malloc(sizeof(struct LinkList));
    list->size = 0;
    list->head = list->tail = NULL;
    list->add = (func_add) do_add;
    list->print = (func_print) do_print;
    list->push = (func_push)do_push;
    return list;
}

LinkListPtr merger_sorted_list(LinkListPtr one, LinkListPtr other) {
    if (NULL == one || one->size == 0) {
        return other;
    }
    if (NULL == other || other->size == 0) {
        return one;
    }
    LinkListPtr result = newLinkList();
    NodePtr one_node =  one->head;
    NodePtr other_node = other->head;
    while (NULL != one_node && NULL != other_node) {
        if (one_node->data < other_node->data) {
            result->push(one_node, result);
            one_node = one_node->next;
        } else {
            result->push(other_node, result);
            other_node = other_node->next;
        }
    }
    result->push(NULL == one_node ? other_node : one_node, result);
    return result;
}