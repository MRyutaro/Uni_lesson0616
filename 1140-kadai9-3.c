#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cell
{
  int element;
  struct cell *next;
};

struct queue
{
  struct cell *front;
  struct cell *rear;
};

void enqueue(int x, struct queue *Q)
{
  struct cell *p;
  p = (struct cell *)malloc(sizeof(struct cell));
  if (p == NULL)
  {
    printf("enqueue : フル状態のためエンキューできません．\n");
    exit(1);
  }
  if (Q->rear != NULL)
  {
    (Q->rear)->next = p;
  }
  Q->rear = p;
  if (Q->front == NULL)
  {
    Q->front = p;
  }
  (Q->rear)->element = x;
  (Q->rear)->next = NULL;
  return;
}

void dequeue(struct queue *Q)
{
  struct cell *q;
  if (Q->front == NULL)
  {
    printf("空状態のためデキューできません．\n");
    exit(1);
  }
  else
  {
    q = Q->front;
    Q->front = (Q->front)->next;
    free(q);
  }
  if (Q->front == NULL)
  {
    Q->rear = NULL;
  }
  return;
}

void printQueue(struct queue *Q)
{
  struct cell *q;
  q = Q->front;
  printf("\t");
  printf("キューの中 [ ");
  while (q != NULL)
  {
    printf("%d", q->element);
    printf(" ");
    q = q->next;
  }
  printf("]\n");
  q = Q->front;
  printf("\t\tキューの中のアドレス [ ");
  while (q != NULL)
  {
    printf("%p", q);
    printf(" ");
    q = q->next;
  }
  printf("%p", q);
  printf(" ]\n");
  fflush(stdout);
}

int main(void)
{
  struct queue Q;
  struct cell *q;
  int x;

  Q.front = Q.rear = NULL;

  while (1)
  {
    printf("\n 整数を入力して下さい：\n");
    scanf("%d", &x);

    // is negative
    if (x < 0)
    {
      q = Q.front;
      while (q != NULL)
      {
        dequeue(&Q);
        printf("dequeue します: ");
        printQueue(&Q);
      }
    }
    // is positive
    // is even number
    else if (x % 2 == 0)
    {
      bool exit = false;
      // search
      q = Q.front;
      while (q != NULL)
      {
        if (x == q->element)
        {
          exit = true;
          break;
        }
        q = q->next;
      }
      if (exit == true)
      {
        fprintf(stderr, "enqueue：既に格納されています\n");
        continue;
      }
      else
      {
        enqueue(x, &Q);
        printf("enqueue(%d) : ", x);
        printQueue(&Q);
      }
    }
    // is odd number
    else
    {
      dequeue(&Q);
      printf("dequeue します: ");
      printQueue(&Q);
    }
  }

  return 0;
}