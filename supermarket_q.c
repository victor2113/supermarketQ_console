#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "supermarket_q.h"

#define EMPTY_QUEUE "Queue is empty!\n"
#define BOB '$'


client incorrect_client = {'!', -1, -1};

struct list *init(client client)
{
    struct list *lst;

    lst = (struct list *) malloc(sizeof(struct list));
    lst->client = client;
    lst->ptr = NULL;
    return (lst);
}

struct list *add_elem(node *lst, client new_client) {
    struct list *temp, *p;
    temp = (struct list *) malloc(sizeof(node));
    p = lst->ptr;
    lst->ptr = temp;
    temp->client = new_client;
    temp->ptr = p;
    return (temp);
}

void init_q(queue *q) {
    q->frnt = 0;
    q->rear = 0;
    q->size = 0;
}

int is_empty(queue *q) {
    if (q->frnt == 0)
        return 1;
    else
        return 0;
}


void insert(queue *q, client client) {
    q->size++;
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
    q->size--;
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
        printf("%c%d\n", h->client.name, h->client.ctime);
}

void print_q_element_for_interface(struct queue *q, int element_number) { //-1 - print front , 0 - 1-element ,  ...pt

    if (element_number <= 0)
        return;
    if (is_empty(q)) {
        printf("|| ");
        return;
    }


    struct list *p2 = q->frnt;

    for (int i = 0; i < element_number - 1; ++i) {
        if (p2->ptr == NULL) {
            printf("|| ");
            return;
        }

        if (p2->client.name == BOB) {
            printf("|| ");
            return;
        }
        p2 = p2->ptr;
    }
    printf("%c%d ", p2->client.name, p2->client.ctime);
    p2 = q->frnt;


}

client generate_client(int max_customer_time, int max_check) {
    client client1 = {' ', 0, 0};
    client1.name = 'a' + GetRandomNumber(26);
    client1.check = GetRandomNumber(max_check);
    client1.ctime = GetRandomNumber(max_customer_time);
    if (client1.ctime == 0)
        client1.ctime++;
    return client1;
}

cashier create_new_cashier(int max_cashier_queue) {
    queue *queue1 = (queue *) malloc(max_cashier_queue * sizeof(queue *));
    init_q(queue1);
    cashier cashier = {0, 0, 0, queue1};
    return cashier;
}


int is_cashier_full(cashier cashier, int max_cashier_queue) {
    if (cashier.queue->size < max_cashier_queue)
        return 0;
    else
        return 1;
}

int GetRandomNumber(int max) {
    int min = 0;
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);

    return num;
}







