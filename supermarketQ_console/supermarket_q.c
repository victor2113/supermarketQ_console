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

void print_q_element(struct queue *q , int n) {
    struct list *h;
    if (is_empty(q) == 1) {
        return;
    }
    h = q->frnt;
    for (int i = 0; i <= n; i++){
        h = h->ptr;
        if(i == n)
            printf("%c%d\n", h->client.name, h->client.ctime);
    }

}
int  curent_queue_size(struct queue *q) {
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
    srand(time(NULL));
    client1.name = 'a' + rand() % 26;
    client1.check = rand() % max_check;
    client1.ctime = rand() % max_customer_time + 1;
    //printf("client.name = %c , client.check = %d ,   client.ctime = %d \n", client1.name, client1.check, client1.ctime);
    return client1;
}

cashier create_new_cashier(int max_cashier_queue) {
    queue *queue1;
    queue1 = (queue *) malloc(sizeof(queue *));
    cashier cashier = {0, 0, 0, queue1};
    init_q(cashier.queue);
    return cashier;
}


int is_cashier_full(cashier cashier , int max_cashier_queue){
    if (curent_queue_size(cashier.queue) <  max_cashier_queue)
        return 0;
    else
        return 1;
}





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