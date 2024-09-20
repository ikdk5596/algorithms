#include "node.hpp"

Node::Node(int data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

Node::~Node() {
    delete this->next;
    delete this->prev;
}

void Node::print_list() {
    Node *current = this;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Node::print_list_reverse() {
    Node *current = this;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
    Node *current = this;

}

void Node::insert_at_beginning(int data) {
    Node *new_node = new Node(data);
    new_node->next = this;
    this->prev = new_node;
}

void Node::insert_at_end(int data) {
    Node *new_node = new Node(data);
    Node *current = this;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void Node::insert_after_node(Node *prev_node, int data) {
    Node *new_node = new Node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void Node::delete_at_beginning() {
    Node *current = this;
    current = current->next;
    delete current->prev;
    current->prev = NULL;
}

void Node::delete_at_end() {
    Node *current = this;
    while (current->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
}

void Node::delete_after_node(Node *prev_node) {
    Node *current = this;
    while (current->next != prev_node) {
        current = current->next;
    }
    delete current->next;
    current->next = prev_node;
    prev_node->prev = current;
}

void Node::delete_by_value(int value) {
    Node *current = this;
    while (current->next != NULL) {
        if (current->next->data == value) {
            delete_after_node(current);
            break;
        }
        current = current->next;
    }
}

void Node::delete_by_position(int position) {
    Node *current = this;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    delete_after_node(current);
}

void Node::delete_list() {
    Node *current = this;
    while (current->next != NULL) {
        delete_after_node(current);
    }
    delete current;
}