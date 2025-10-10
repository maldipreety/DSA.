#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue {
    int front, rear;
     int data[SIZE];
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item){
    if (q-> rear == SIZE -1){
        printf("\n queue overflow - queue  is full!\n");
    }
    else {
        q->rear++;
        q->data[q->rear]=item;
        if (q->front == -1)
            q->front = 0;
        printf("\n inserted %d into the queue.\n",item);
    }
}
void dequeue(QUEUE *q){
    if (q->front == -1){
        printf("\n queue underflow - queue is empty!\n");
    }
    else {
        printf("\n deleted element is %d\n",q->data [q->front]);
        if (q->front == q->rear){
              q->front = -1;
              q->rear = -1;
        }
        else {
            q->front++;
        }

    }

}
void display(QUEUE q){
    int i;
    if (q.front == -1){
        printf ("\n queue is empty.\n");
    }
    else {
        printf("\n queue contents are:\n");
        for (i = q.front; i<=q.rear; i++)
            printf ("%d\t",q.data[i]);
        printf("\n");
    }
}

    int main(){
    int item,ch ;
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    while(1){
        printf("\n -------- queue operations---------");
        printf("\n1 enqueue. \n2 dequeue. \n3 display. \n4 exit.");
        printf("\n ------------------");
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch (ch){
    case1:
        printf("\n enter element to insert:");
        scanf("%d", &item);
        enqueue(&q, item);
        break;
    case 2:
           dequeue(&q);
           break;
    case 3:
          display (q);
          break;
    case 4:
          printf("|n exiting program...\n");
          exit(0);
          default: printf("\n invalid choice! please try again.\n");
        }
    }
      return 0;
}
