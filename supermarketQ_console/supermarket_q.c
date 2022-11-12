//
// Created by 1 on 12.11.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "supermarket_q.h"

queue *init (int size)
{
    queue * q = calloc (1, sizeof (queue));
    q -> data = calloc (size, sizeof (q_element));
    q->low = q->high = size - 1;
    q->max = size;

    return q;
}
