#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data);
        ~Node();
        void print_list();
        void print_list_reverse();
        void insert_at_beginning(int data);
        void insert_at_end(int data);
        void insert_after_node(Node *prev_node, int data);
        void delete_at_beginning();
        void delete_at_end();
        void delete_after_node(Node *prev_node);
        void delete_by_value(int value);
        void delete_by_position(int position);
        void delete_list();
};

#endif
