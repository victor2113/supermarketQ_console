//
// Created by 1 on 12.11.2022.
//

#ifndef SUPERMARKETQ_CONSOLE_SUPERMARKET_Q_H
#define SUPERMARKETQ_CONSOLE_SUPERMARKET_Q_H

#endif //SUPERMARKETQ_CONSOLE_SUPERMARKET_Q_H


typedef struct Market_client {
    char name;
    int ct;//customer time
    int sum;//customer check
} client;

typedef struct  queue_element{
    client client;
    struct MyQueue *next;
} q_element;


typedef struct MyQueue {
    q_element *data;  // указатель на данные
    int low;        // указатель на нижнюю границу
    int high;       // указатель на верхнюю границу
    int count;      // количество элементов в очереди
    int max;
} queue;
