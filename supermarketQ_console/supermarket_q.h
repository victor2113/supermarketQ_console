//
// Created by 1 on 12.11.2022.
//

#ifndef SUPERMARKETQ_CONSOLE_SUPERMARKET_Q_H
#define SUPERMARKETQ_CONSOLE_SUPERMARKET_Q_H

#endif //SUPERMARKETQ_CONSOLE_SUPERMARKET_Q_H


typedef struct Market_client {
    char name;
    int ctime;//customer time
    int check;//customer check
} client;

typedef struct list {
    client client;
    struct list *ptr;
} node;

typedef struct queue {
    struct list *frnt, *rear;
} queue;

typedef struct cashier {
    int is_open;
    int client_counter;
    int sum_of_purchases;
    queue queue;
} cashier;


struct list *init(client client);

struct list *add_elem(node *lst, client new_client);

void init_q(struct queue *q);

int is_empty(struct queue *q);

void print_q(struct queue *q);

void insert(struct queue *q, client client);

client remove_fr_q(queue *q);

client test(struct queue *q);

void queue_add(queue *q, client qe);

client generate_client(int max_customer_time, int max_check);