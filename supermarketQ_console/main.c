#include <stdio.h>
#include <stdlib.h>
#include "supermarket_q.h"
#include <unistd.h>


int max_customer_time, max_customer_check, max_cashiers, max_cashier_queue, max_next_customers;
client Bob = {'$' , -1 , 0};


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

    fscanf(fin,
           "%d %d %d %d %d",
           &max_customer_time,
           &max_customer_check,
           &max_cashiers,
           &max_cashier_queue,
           &max_next_customers); //settings


    int curent_profit = 0;

    cashier *market = (cashier *) malloc(max_cashiers * sizeof(cashier *));
    client *next_customers = (client *) malloc(max_next_customers * sizeof(client *));

    for (int i = 0; i < max_cashiers; ++i) {
        market[i] = create_new_cashier(max_cashier_queue);
    }

    for (int i = 0; i < max_next_customers; ++i) {
        int curent_next_customers = GetRandomNumber(max_next_customers);
        sleep(1);
        if(i < curent_next_customers)
            next_customers[i] = generate_client(max_customer_time, max_customer_check);
        else
            next_customers[i] = Bob;
    }
    for (int i = 0; next_customers[i].name != Bob.name; ++i) {
        printf("%c%d ", next_customers[i].name,  next_customers[i].ctime);
    }
    for (int qua = 0; qua < 10; ++qua) {

//        for (int i = 0; next_customers[i].name != Bob.name; ++i) {
//            printf("%c%d ", next_customers[i].name,  next_customers[i].ctime);
//        }

        printf("\nSupermarket queue console simulator\n");
        for (int i = 0; i < max_cashiers; ++i) {
            printf("%d  ", i + 1);//номера касс
        }
//        for (int i = -1; i < max_cashiers; ++i) {
//            for (int j = -1; j < max_cashier_queue; ++j) {
//                print_q_element_for_interface(market[i].queue,j);
//            }
//            printf("\n");
//        }

    }

    return 0;
}