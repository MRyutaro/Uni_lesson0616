#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5    /* 例題 9-1 と同じ */
typedef int QUEUE_TYPE; /* 例題 9-1 と同じ */

QUEUE_TYPE gQueue[QUEUE_SIZE + 1]; /* リングバッファで空状態とフル状態を区別するため，QUEUE_SIZE+1 とする */
int gQFront = 0;                   /* キューの先頭の位置を記録する変数の定義と初期化 */
int gQRear = 0;                    /* キューの末尾の次の位置を記録する変数の定義と初期化 */
void error(char *s)
{ /* 関数 error()の定義(例題 9-2 と同じ) */
    fflush(stdout);
    fprintf(stderr, "\n%s\n", s);
    exit(1);
}

void initQueue(void)
{                /* キューを初期化する関数 initQueue の定義 */
    gQFront = 0; /* キューの先頭 gQFront = 0 および */
    gQRear = 0;  /* 末尾の次の位置 gQRear=0 でキューの初期化が可能 */
}

int queueNext(int n)
{                                      /* エンキュー，デキューされた際の配列の最初と最後を */
    return (n + 1) % (QUEUE_SIZE + 1); /* リング状に繋げるための関数 queueNext の定義 */
}

int chkEmpty(void)
{                             /* キューが空状態かチェックする関数 chkEmpty の定義 */
    return gQFront == gQRear; /* キューの先頭 gQFront と末尾の次 gQRear が等しいと空状態 */
} /* gQFront==gQRear が真であれば → 1 を返す */

int chkFull(void)
{                                        /* キューがフル状態かチェックする関数 chkFull()の定義 */
    return queueNext(gQRear) == gQFront; /* エンキューされた場合の gQRear の値(即ち「末尾の次の次」 */
} /*「gQRear の次」)が gQFront の値と一致していればフル状態 */

void enqueue(QUEUE_TYPE x)
{                                                                /* エンキューする関数 enqueue の定義 */
    if (chkFull())                                               /* 例題 9-2 と同じ */
        error("enqueue : フル状態のためエンキューできません．"); /* 例題 9-2 と同じ */

    gQueue[gQRear] = x;         /* フル状態でなければ gQueue[ ]の QRear 番目に x を代入し， */
    gQRear = queueNext(gQRear); /* キューの末尾の次の位置を記録する変数 gQRear を更新 */
}

int dequeue(void)
{                 /* デキューする関数 dequeue()の定義 */
    QUEUE_TYPE x; /* 例題 9-2 と同じ */

    if (chkEmpty())                                          /* 例題 9-2 と同じ */
        error("dequeue : 空状態のためデキューできません．"); /* 例題 9-2 と同じ */

    x = gQueue[gQFront];          /* デキューされる値(配列 gQueue[ ]の gQFront 番目)を x に代入 */
    gQFront = queueNext(gQFront); /* キューの先頭を記録する変数 gQFront を更新 */
    return x;                     /* main 関数にデキューされた値 x を戻す */
}

void printQueue(void)
{                            /* キューの中身を表示する関数 printQueue()の定義 */
    int i;                   /* 例題 9-1 と同じ */
    printf("\t");            /* 例題 9-1 と同じ */
    printf("キューの中 [ "); /* 例題 9-1 と同じ */
    for (i = gQFront; i != gQRear; i = queueNext(i))
    {                            /* キューの先頭は gQFront, gQRear でなければ繰り返し */
        printf("%d", gQueue[i]); /* gQFront から始めて，gQRear でなければ繰り返す */
        if (i != gQRear)
            printf(" ");                                  /* 配列中の次の要素は関数 queueNext を用いて求める */
    }                                                     /* 例題 9-1 と同じ */
    printf("]\n");                                        /* 例題 9-1 と同じ */
    printf("先頭 = %d,\t 末尾 = %d \n", gQFront, gQRear); /* gQFront と gQRear を表示 */
    fflush(stdout);                                       /* 例題 9-1 と同じ */
}

int main(void)
{ /* 関数 main (例題 9-2 と同じ) */
    QUEUE_TYPE x;

    initQueue();

    while (!chkFull())
    {
        printf("整数を入力して下さい:\n");
        scanf("%d", &x);
        if (x == 0)
            break;
        enqueue(x);
        printf("enqueue(%d) : ", x);
        printQueue();
    }

    while (!chkEmpty())
    {
        printf("dequeue() %d : ", dequeue());
        printQueue();
    }

    return 0;
}