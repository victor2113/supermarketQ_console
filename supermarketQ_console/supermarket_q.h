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


typedef struct MyQueue {
    client *data;  // указатель на данные
    int low;        // указатель на нижнюю границу
    int high;       // указатель на верхнюю границу
    int count;      // количество элементов в очереди
    int max;
} queue;

queue *init (int size);

void queue_add (queue *q, client qe);

client generate_client(int max_customer_time, int max_check);