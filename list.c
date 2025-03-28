#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * lista = (List *)malloc(sizeof(List));
    if (lista == NULL) {
        return NULL;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    return lista;
}

void * firstList(List * list) {
    if (list->head != NULL) {
        list->current = list->head;
        return list->current->data;
    }
    return NULL;
}

void * nextList(List * list) {
    if (list->current != NULL) {
        list->current = list->current->next;
        if (list->current != NULL) {
            return list->current->data;
        }
    }
    return NULL;
}

void * lastList(List * list) {
    if (list->tail != NULL) {
        list->current = list->tail;
        return list->current->data;
    }
    return NULL;
}

void * prevList(List * list) {
    if (list->current != NULL) {
        list->current = list->current->prev;
        if (list->current != NULL) {
            return list->current->data;
        }
    }
    return NULL;
}

void pushFront(List * list, void * data) {
    Node *nodoNuevo = createNode(data);
    if (list->head == NULL) {
        list->head = nodoNuevo;
        list->tail = nodoNuevo;
    } else {
        nodoNuevo->next = list->head;
        list->head->prev = nodoNuevo;
        list->head = nodoNuevo;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node * nodoNuevo = createNode(data);
    if (list->current == NULL) {
        list->tail = nodoNuevo;
        list->head = nodoNuevo;
    } else {
        if (list->current->next != NULL) {
            nodoNuevo->next = list->current->next;
            list->current->next->prev = nodoNuevo;
        } else {
            list->tail = nodoNuevo;
        }
        nodoNuevo->prev = list->current;
        list->current->next = nodoNuevo;
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}