#include "node.h"

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_list_reverse(Node *tail) {
    Node *current = tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void insert_after_node(Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
    new_node->prev = prev_node;
}

void delete_node(Node **head, Node *del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }
    if (*head == del_node) {
        *head = del_node->next;
    }
    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }
    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }
    free(del_node);
}

void delete_at_beginning(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delete_at_end(Node **head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_after_node(Node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        return;
    }
    Node *temp = prev_node->next;
    prev_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prev_node;
    }
    free(temp);
}

void delete_by_value(Node **head, int value) {
    if (*head == NULL) {
        return;
    }
    Node *current = *head;
    while (current != NULL) {
        if (current->data == value) {
            delete_node(head, current);
            return;
        }
        current = current->next;
    }
}

void delete_by_position(Node **head, int position) {
    if (*head == NULL || position < 0) {
        return;
    }
    if (position == 0) {
        delete_at_beginning(head);
        return;
    }
    Node *current = *head;
    int count = 0;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL) {
        return;
    }
    delete_after_node(current);
}

void delete_list(Node **head) {
    Node *current = *head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}