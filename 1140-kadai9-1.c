#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 5
typedef int QUEUE_TYPE;

QUEUE_TYPE gQueue[QUEUE_SIZE + 1];
int gQFront = 0;
int gQRear = 0;
void error(char *s)
{
  fflush(stdout);
  fprintf(stderr, "\n%s\n", s);
  exit(1);
}

void initQueue(void)
{
  gQFront = 0;
  gQRear = 0;
}

int queueNext(int n)
{
  return (n + 1) % (QUEUE_SIZE + 1);
}

int chkEmpty(void)
{
  return gQFront == gQRear;
}

int chkFull(void)
{
  return queueNext(gQRear) == gQFront;
}

void enqueue(QUEUE_TYPE x)
{
  if (chkFull())
    error("enqueue : フル状態のためエンキューできません。\n");

  gQueue[gQRear] = x;
  gQRear = queueNext(gQRear);
}

int dequeue(void)
{
  QUEUE_TYPE x;

  if (chkEmpty())
    error("dequeue : 空状態のためデキューできません。\n");

  x = gQueue[gQFront];
  gQFront = queueNext(gQFront);
  return x;
}

void printQueue(void)
{
  int i;
  printf("\t");
  printf("キューの中 [ ");
  for (i = gQFront; i != gQRear; i = queueNext(i))
  {
    printf("%d", gQueue[i]);
    if (i != gQRear)
      printf(" ");
  }
  printf("]\n");
  printf("先頭 = %d,\t 末尾 = %d \n", gQFront, gQRear);
  fflush(stdout);
}

int main(void)
{
  QUEUE_TYPE x;

  initQueue();

  while (1)
  {
    printf("整数を入力して下さい:\n");
    scanf("%d", &x);

    if (x < 0)
    {
      while (!chkEmpty())
      {
        printf("dequeue() %d : ", dequeue());
        printQueue();
      }
      return 0;
    }

    else if (x % 2 == 0)
    {
      bool exit = false;
      for (int i = gQFront; i != gQRear; i = queueNext(i))
      {
        if (x == gQueue[i])
        {
          exit = true;
        }
      }
      if (exit == true)
      {
        fprintf(stderr, "enqueue：既に格納されています\n");
        continue;
      }
      else
      {
        enqueue(x);
        printf("enqueue(%d) : ", x);
        printQueue();
      }
    }

    else
    {
      printf("dequeue() %d : ", dequeue());
      printQueue();
    }
  }
  return 0;
}