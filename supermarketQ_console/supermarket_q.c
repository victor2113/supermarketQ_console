//
// Created by 1 on 12.11.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "supermarket_q.h"



client default_client = {' ', 0 , 0};


queue *init (int size)
{
    queue * q = calloc (1, sizeof (queue));
    q -> data = calloc (size, sizeof (client));
    q->low = q->high = size - 1;
    q->max = size;

    return q;
}

void queue_add (queue *q, client qe)
{

    if (q->count == q->max) {
        fprintf (stderr, "not enough queue size\n");
        return;
    }

    q->data[q->low--] = qe;
    q->count++;

    if (q->low < 0) {
        q->low = q->max - 1;
    }

}

client queue_get (queue *q)
{
    client a = q->data[q->high--];
    q->count--;

    if (q->high < 0) {
        q->high = q->max - 1;
    }

    return a;
}





client generate_client(int max_customer_time,int max_check){
    client client1  = {' ', 0 , 0};
    srand( time(NULL) );
    client1.name = 'a' + rand() % 26;
    client1.check = rand() % max_check;
    client1.ctime = rand() % max_customer_time;
    printf("client.name = %c , client.check = %d ,   client.ctime = %d \n" , client1.name , client1.check , client1.ctime);
    return client1;
}
