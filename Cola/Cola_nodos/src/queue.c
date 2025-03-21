#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d){
    if (q == NULL) {
        return;
    }
    Node* new_n = new_node(d);
    if (new_n == NULL) {
        return;
    }
    if (q->tail == NULL) {
        q->head = q->tail = new_n;
    } else {
        q->tail->next = new_n;
        q->tail = new_n;
    }
}

Data queue_dequeue(Queue* q){
    if (queue_is_empty(q)) {
        return -1;
    }
    Node* temp = q->head;
    Data d = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return d;
}
bool queue_is_empty(Queue* q){
    return (q == NULL || q->head == NULL);
}

Data queue_front(Queue* q){
    if (queue_is_empty(q)) {
        return -1; // Valor de error si la cola está vacía
    }
    return q->head->data;
}

void queue_empty(Queue* q){
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q){
    if (q != NULL) {
        queue_empty(q);
        free(q);
    }
}