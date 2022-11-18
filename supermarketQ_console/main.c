#include <stdio.h>
#include <stdlib.h>
#include "supermarket_q.h"


int max_customer_time, max_customer_check;


/*
 Супермаркет "Реми". Система моделирования очередей.
   1   2   3   4   5   6
  12   4   0   0   0   0
   +   +   -   -   -   -
  a1  s2  ||  ||  ||  ||
  s3  a1  ||  ||  ||  ||
  d1  q1  ||  ||  ||  ||
  f2  ||  ||  ||  ||  ||
  l3  ||  ||  ||  ||  ||
Время: 8
Следующие посетители: f2 w3 k1
Человек в очередях: 8
Касс работает: 2 из 6
Всего обслужено: 16
Сумма покупок: 20332
Допустимая очередь на кассу: 5

 */



int main() {

    FILE *fin;

    fin = fopen("settings.txt", "r");

    fscanf(fin, "%d %d", &max_customer_time, &max_customer_check);

    client client1;
    client1 = generate_client(max_customer_time, max_customer_check);

    client client3 = generate_client(max_customer_time, max_customer_check);;

    queue *queue1;
    queue1 = (queue *) malloc(sizeof(queue *));
    init_q(queue1);
    //print_q(queue1);
    insert(queue1, client1);
    insert(queue1, client3);
    insert(queue1, client1);
    insert(queue1, client1);
    print_q(queue1);
    client client2 = remove_fr_q(queue1);
    printf("\nclient.name = %c , client.check = %d ,   client.ctime = %d \n", client2.name, client2.check,
           client2.ctime);
    print_q(queue1);


    return 0;
}
