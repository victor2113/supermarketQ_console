#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "supermarket_q.h"

#define EMPTY_QUEUE "Queue is empty!\n"


client incorrect_client = {'!', -1, -1};

struct list *init(client client) // значение первого узла
{
    struct list *lst;
    // выделение памяти под корень списка
    lst = (struct list *) malloc(sizeof(struct list));
    lst->client = client;
    lst->ptr = NULL; // это последний узел списка
    return (lst);
}

struct list *add_elem(node *lst, client new_client) {
    struct list *temp, *p;
    temp = (struct list *) malloc(sizeof(node));
    p = lst->ptr; // сохранение указателя на следующий узел
    lst->ptr = temp; // предыдущий узел указывает на создаваемый
    temp->client = new_client; // сохранение поля данных добавляемого узла
    temp->ptr = p; // созданный узел указывает на следующий элемент
    return (temp);
}

void init_q(queue *q) {
    q->frnt = 0;
    q->rear = 0;
}

int is_empty(queue *q) {
    if (q->frnt == 0)
        return 1;
    else
        return 0;
}


void insert(queue *q, client client) { //добавление элемента в конец очереди
    if ((q->rear == 0) && (q->frnt == 0)) {
        q->rear = init(client);
        q->frnt = q->rear;
    } else
        q->rear = add_elem(q->rear, client);
}

client remove_fr_q(queue *q) {
    struct list *temp;
    client client1;
    if (is_empty(q) == 1) {
        printf(EMPTY_QUEUE);
        return incorrect_client;
    }
    client1 = q->frnt->client;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return client1;
}

client test(struct queue *q) {
    client client;
    client = q->frnt->client;
    return client;
}

void print_q(struct queue *q) {
    struct list *h;
    if (is_empty(q) == 1) {
        printf(EMPTY_QUEUE);
        return;
    }
    for (h = q->frnt; h != NULL; h = h->ptr)
        printf("%c%d\n", h->client.name, h->client.ctime);
}

void print_q_element_for_interface(struct queue *q , int k) { //-1 - print front , 0 - 1-element ,  ...pt
    if(k<=0)
        return;

    struct list *p1 = q->frnt;
    struct list *p2 = q->frnt;

    for (int i = 0; i < k-1; ++i) {
        if(p2->ptr==NULL){
            printf("|| ");
            return;
        }
          p2 = p2->ptr;
    }
    if(p2->ptr==NULL){
        printf("|| ");
        return;
    }
    while(p2->ptr != NULL){
        p1 = p1->ptr;
        p2 = p2->ptr;
    }
    printf("%c%d" , p1 ->client.name , p1->client.ctime);






}
int curent_queue_size(struct queue *q) {
    int counter = 0;
    struct list *h;
    if (is_empty(q) == 1) {
        return 0 ;
    }
    for (h = q->frnt; h != NULL; h = h->ptr)
        counter++;
    return counter;
}


client generate_client(int max_customer_time, int max_check) {
    client client1 = {' ', 0, 0};
    client1.name = 'a' + GetRandomNumber(26) + 1;
    client1.check = GetRandomNumber(max_check);
    client1.ctime = GetRandomNumber(max_customer_time);
    if(client1.ctime == 0)
        client1.ctime++;
    return client1;
}

cashier create_new_cashier(int max_cashier_queue) {
    queue *queue1 = (queue *) malloc(max_cashier_queue * sizeof(queue *));
    //init_q(queue1);
    cashier cashier = {0, 0, 0, queue1};
    return cashier;
}


int is_cashier_full(cashier cashier , int max_cashier_queue){
    if (curent_queue_size(cashier.queue) <  max_cashier_queue)
        return 0;
    else
        return 1;
}

int GetRandomNumber(int max)
{
    int min = 0;
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);

    return num;
}



//client *generate_next_customers(int max_next_customers ,int max_customer_time, int max_check){
//    srand(time(NULL));
//    int next_custmrs = 5;
//    //next_custmrs = rand()% max_next_customers;
//    client *next_customers = (client *) malloc(max_next_customers * sizeof(client *));
//    for (int i = 0; i < max_next_customers; ++i) {
//        if(i < next_custmrs)
//            next_customers[i] = generate_client( max_customer_time,  max_check);
//        else
//            next_customers[i] = incorrect_client;
//    }
//    return next_customers;
//}



//void printInterface(int max_cashiers, int max_cashier_queue) {
//    printf("Supermarket queue console sinulator\n");
//    for (int i = 0; i < max_cashiers; ++i){
//        printf("%d  ", i+1);//номера касс
//        market[i] = create_new_cashier(max_cashier_queue);
//    }
//    printf("\n");
//    for (int i = 0; i < max_cashiers; ++i)
//        for (int j = 0; j < max_cashier_queue; ++j) {
//
//        }
//}