#include <stdio.h>
#include <stdlib.h>
#include "supermarket_q.h"
#include <windows.h>


int max_customer_time, max_customer_check, max_cashiers, max_cashier_queue, max_next_customers;
client Bob = {'$', -1, 1020};


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


    int curent_profit = 0,
            curent_next_customers = 0,
            time_counter = 0,
            working_cashiers = 0,
            people_in_queues = 0,
            served_clients = 0;


    cashier *market = (cashier *) malloc(max_cashiers+1 * sizeof(cashier *));
    client *next_customers = (client *) malloc((max_next_customers) * sizeof(client*));
    next_customers[0] = generate_client(max_customer_time, max_customer_check);


    for (int i = 1; i <= max_cashiers; ++i) {
        market[i] = create_new_cashier(max_cashier_queue);
        init_q(market[i].queue);
    }


    for (int qua = 0; qua < 4; ++qua) {
        time_counter++;
        Sleep(1000);
        //system("cls");


        curent_next_customers = GetRandomNumber(max_next_customers);


        printf("\nSupermarket queue console simulator\n");


        for (int i = 1; i <= max_cashiers; ++i) {
            printf("%d  ", i);//номера касс
        }
        printf("\n");


        for (int i = 1; i <= max_cashiers; ++i) {
            printf("%d  ", market[i].client_counter);//кол - во обслуженных
        }
        printf("\n");


        for (int i = 1; i <= max_cashiers; ++i) {
            if (market[i].is_open == 0)
                printf("-  ");
            else
                printf("+  ");
        }
        printf("\n");


        for (int i = 1; i <= max_cashier_queue; ++i) {
            for (int j = 1; j <= max_cashiers; ++j) {
                print_q_element_for_interface(market[j].queue, i);
            }
            printf("\n");
        }


        printf("Time:%d  ", time_counter);//время


        //NEXT CUSTOMERS START
        printf("\nNext customers = ");
        if (curent_next_customers == 0) {
            curent_next_customers++;
        }
        if (curent_next_customers == 0) {
            printf("no next customers\n");
        } else {
            for (int i = 0; i < max_next_customers; ++i) {
                if (i < curent_next_customers) {
                    Sleep(1000);
                    next_customers[i] = generate_client(max_customer_time, max_customer_check);
                } else
                    next_customers[i] = Bob;
            }

            for (int i = 0; next_customers[i].name != Bob.name && i < max_next_customers; ++i) {
                printf(" %c%d ", next_customers[i].name, next_customers[i].ctime);
            }
            printf("\n");
        }
        //NEXT CUSTOMERS END



        printf("People in queues:%d  \n", people_in_queues);
        printf("Working cashiers: %d out of %d\n", working_cashiers, max_cashiers);
        printf("Served clients: %d\n", served_clients);
        printf("Sum of all purchases: %d\n", curent_profit);
        printf("Max cashier queue: %d\n", max_cashier_queue);
        printf("\n\n");




    }

    return 0;
}
