//
// Created by SuperAdmin on 21.12.2022.
//

#ifndef UNTITLED_SUPERMARKET_Q_H
#define UNTITLED_SUPERMARKET_Q_H

#endif //UNTITLED_SUPERMARKET_Q_H

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
    int size;
    struct list *frnt, *rear;
} queue;

typedef struct cashier {
    int is_open;
    int client_counter;
    int sum_of_purchases;
    queue *queue;
} cashier;

int GetRandomNumber(int max);

struct list *init(client client);

struct list *add_elem(node *lst, client new_client);

void init_q(struct queue *q);

int is_empty(struct queue *q);

void print_q(struct queue *q);

int curent_queue_size(struct queue *q);

void insert(struct queue *q, client client);

client remove_fr_q(queue *q);

client test(struct queue *q);
client *generate_next_customers(int max_next_customers, int max_customer_time, int max_check);
void queue_add(queue *q, client qe);

void print_q_element_for_interface(struct queue *q , int element_number);

cashier create_new_cashier(int max_cashier_queue);

int is_cashier_full(cashier cashier, int max_cashier_queue);

client generate_client(int max_customer_time, int max_check);

void printInterface(int max_cashiers, int max_cashier_queue);

void print_next_customers(client *next_clients);