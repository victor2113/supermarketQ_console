#include <stdio.h>
#include <stdlib.h>
#include "supermarket_q.h"
#include <unistd.h>


int max_customer_time, max_customer_check, max_cashiers, max_cashier_queue, max_next_customers;


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
    cashier cashier1 = create_new_cashier(max_cashier_queue);
    for (int i = 0; i < max_cashier_queue; ++i) {
        client client1 = generate_client(max_customer_time, max_customer_check);
        insert(cashier1.queue , client1);
        sleep(1);
    }
    print_q(cashier1.queue);
    printf("\n\neto\n");
    print_q_element(cashier1.queue , 2);
    printf("\n\n\n");
    client client2 = remove_fr_q(cashier1.queue);
    print_q(cashier1.queue);
    printf("\n\neto\n");
    print_q_element(cashier1.queue , 2);

//    int curent_profit = 0;
//    cashier *market = (cashier *) malloc(max_cashiers * sizeof(cashier *));
//    client *next_customers = (client *) malloc(max_next_customers * sizeof(client *));
//
//    for (int i = 0; i < max_cashiers; ++i) {
//        market[i] = create_new_cashier(max_cashier_queue);
//    }
//    printf("Supermarket queue console sinulator\n");
//    system("cls");
//
//    for (int qua = 0; qua < 10; ++qua) {
//        system("clear");
//        printf("Supermarket queue console sinulator\n");
//        for (int i = 0; i < max_cashiers; ++i) {
//            printf("%d  ", i + 1);//номера касс
//        }
//        for (int i = 0; i < max_cashiers; ++i) {
//            for (int j = 0; j < max_cashier_queue; ++j) {
//
//            }
//        }
//
//    }

    return 0;
}