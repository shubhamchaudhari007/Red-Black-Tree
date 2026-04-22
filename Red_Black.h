#ifndef RED_BLACK_H
#define RED_BLACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COLOR(x)  ((x) == NULL ? BLACK : (x)->color)

typedef enum st{
    FAILURE,SUCCESS
}Status;

typedef enum colours{
    RED,BLACK
}color;

typedef struct Tree_node{
    int data;
    color color;
    struct Tree_node *left;
    struct Tree_node *right;
    struct Tree_node *parent;
}T_node;

Status insert(T_node **root,int val);
Status Display(T_node *root);
Status rbDelete(T_node **root, int key);
T_node* bstDelete(T_node *root, int del, T_node **x, T_node **parent, color *detectc);
void rbDeleteFixup(T_node **root, T_node *x, T_node *parent);
Status find_maximum(T_node *root);
Status find_minimum(T_node *root);
Status Search(T_node *root, int val);
void rightrotate(T_node **root, T_node *node);
void leftrotate(T_node **root, T_node *node);
Status delete_maximum(T_node **root);
Status delete_minimum(T_node **root);

#endif