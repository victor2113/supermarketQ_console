//
// Created by 1 on 12.11.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "supermarket_q.h"

#define EMPTY_QUEUE "Queue is empty!\n"


client incorrect_client = {'!', -1, -1};

struct list *init(client client) // значение первого узла
{
    struct list *lst;
    // выделение памяти под корень списка
    lst = (struct list *) malloc(sizeof(struct list));
    lst->client = client;
    lst->ptr = NULL; // это последний узел списка
    return (lst);
}

struct list *add_elem(node *lst, client new_client) {
    struct list *temp, *p;
    temp = (struct list *) malloc(sizeof(node));
    p = lst->ptr; // сохранение указателя на следующий узел
    lst->ptr = temp; // предыдущий узел указывает на создаваемый
    temp->client = new_client; // сохранение поля данных добавляемого узла
    temp->ptr = p; // созданный узел указывает на следующий элемент
    return (temp);
}

void init_q(queue *q) {
    q->frnt = 0;
    q->rear = 0;
}

int is_empty(queue *q) {
    if (q->frnt == 0)
        return 1;
    else
        return 0;
}


void insert(queue *q, client client) { //добавление элемента в конец очереди
    if ((q->rear == 0) && (q->frnt == 0)) {
        q->rear = init(client);
        q->frnt = q->rear;
    } else
        q->rear = add_elem(q->rear, client);
}

client remove_fr_q(queue *q) {
    struct list *temp;
    client client1;
    if (is_empty(q) == 1) {
        printf(EMPTY_QUEUE);
        return incorrect_client;
    }
    client1 = q->frnt->client;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return client1;
}

client test(struct queue *q) {
    client client;
    client = q->frnt->client;
    return client;
}

void print_q(struct queue *q) {
    struct list *h;
    if (is_empty(q) == 1) {
        printf(EMPTY_QUEUE);
        return;
    }
    for (h = q->frnt; h != NULL; h = h->ptr)
        printf("%c ", h->client.name);
}


client generate_client(int max_customer_time, int max_check) {
    client client1 = {' ', 0, 0};
    srand(time(NULL));
    client1.name = 'a' + rand() % 26;
    client1.check = rand() % max_check;
    client1.ctime = rand() % max_customer_time;
    printf("client.name = %c , client.check = %d ,   client.ctime = %d \n", client1.name, client1.check, client1.ctime);
    return client1;
}
