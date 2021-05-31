/*
CH-230-A
a8 p2.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de

*/
/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
static void copy_to_item(Node *pn, Item *pi);
static void copy_to_node(Item item, Node *pn);
void print(Queue *pq);
void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
	
	if (queue_is_full(pq))
	{
		return -1;
	}
	Node *newel = (Node *)malloc(sizeof(Node));

	if (newel == NULL)
	{
		return -1;
	}
	copy_to_node(item, newel);
	newel->next = NULL;
	if (queue_is_empty(pq))
	{
		pq->front = newel;
		pq->rear = pq->front;
	}
	else
	{
		pq->rear->next = newel;
		pq->rear = pq->rear->next;
	}

	pq->items++;

	return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	if(queue_is_empty(pq)){
        // Queue is Underflow
        return -1;
    }

    Node *temp = pq->front;
    copy_to_item(pq->front, pitem);
    pq->front = pq->front->next;

    
    free(temp);
    pq->items--;

    if(pq->items == 0){
        pq->front = pq->rear = NULL;
    }

    return 0;

}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}
static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}
static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}
void print(Queue *pq){
    Node *temp;
    temp=pq->front;
    while (temp!=NULL)
    {
        printf("%d ",temp->item);
        temp=temp->next;
    }
    printf("\n");
    }