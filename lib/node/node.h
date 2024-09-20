#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    Node *next;
    Node *prev;
} Node;

void print_list(Node *head);
void print_list_reverse(Node *tail);
void insert_at_beginning(Node **head, int data);
void insert_at_end(Node **head, int data);
void insert_after_node(Node *prev_node, int data);
void delete_at_beginning(Node **head);
void delete_at_end(Node **head);
void delete_after_node(Node *prev_node);
void delete_by_value(Node **head, int value);
void delete_by_position(Node **head, int position);
void delete_list(Node **head);

#endif