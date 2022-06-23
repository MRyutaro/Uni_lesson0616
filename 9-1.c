#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10                                /* キューのサイズ(ここでは 5) */
typedef int QUEUE_TYPE;                             /* キューに格納されるデータの型(ここでは int) */

QUEUE_TYPE gQueue[QUEUE_SIZE];                      /* データ格納用の配列 */
int gQNum;                                          /* キューに格納されているデータ数 */

void initQueue(void){                               /* キューの中身を初期化する関数 initQueue の定義 */
    gQNum=0;                                        /* 配列 gQueue[ ]内の他の要素が参照されないので */
}                                                   /* gQNum=0 で配列 gQueue[ ]の初期化が可能 */

void enqueue(QUEUE_TYPE x){                         /* エンキューする関数 enqueue(x)の定義 */
    gQueue[gQNum++] = x;                            /* 配列 gQueue[ ]の gQNum 番目の要素として x を代入 */
}                                                   /* x の型は QUEUE_TYPE として定義(ここでは int) */

int dequeue(void){                                  /* デキューする関数 dequeue()の定義 */
    QUEUE_TYPE x;                                   /* デキューされるデータ x の型 */
    int i;                                          /* デキューされた後の配列の入れ替えのためのカウンタ i */
    x = gQueue[0];                                  /* デキューされる値(配列 gQueue[0]の要素)を x に代入 */
    for (i=1;i<=gQNum-1;i++){                       /* デキューされた後の配列の要素入れ替えのためのループ */
        gQueue[i-1]=gQueue[i];                      /* 配列の要素入れ替え 配列 gQueue[ ]の i 番目の要素を */
    }                                               /* i-1 番目の要素として代入 */
    gQNum--;                                        /* デキューされたのでデータ数 gQNum を 1 減らす */
    return x;                                       /* main 関数にデキューされた値 x を戻す */
}

void printQueue(void){                              /* キューの中身を表示する関数 printQueue()の定義 */
    int i;                                          /* 配列 gQueue[ ]を巡回するためのカウンタ i */
    printf("\t");                                   /* タブ空白の設定 */
    printf("キューの中 [ ");                         /* "キューの中[ "を画面に表示 */
    for (i=0;i<gQNum;i++){                          /* i=0～その時点のキューの最後(gQnum-1)まで順に増やす */
        printf("%d", gQueue[i]);                    /* キューの i 番目の要素(gQueue[i])を表示 */
        if(i != gQNum) printf(" ");                 /* キューの最後のデータでなければ 1 文字空白を挿入 */
    }
    printf("]\n");                                  /* キューの最後のデータであれば "]"を画面に表示 */
    fflush(stdout);                                 /* stdout(標準出力)のバッファの中身を強制出力 */
}

int main(void){
    QUEUE_TYPE x;                                   /* キューに格納されるデータ x の型 */
    int i;                                          /* エンキュー，デキューを繰り返す回数のカウンタ i の定義 */

    initQueue();                                    /* キューを初期化する関数 initstack()の呼び出し */

    for (i=0;i<QUEUE_SIZE;i++){                     /* for 文で{ }内をキューのサイズ(QUEUE_SIZE)回繰り返し */
        printf("整数を入力して下さい:\n");           /* 画面表示と改行 */
        scanf("%d",&x);                             /* キーボードからデータ x の入力 */
        enqueue(x);                                 /* エンキューする関数 enqueue(x)の呼び出し */
        printf("enqueue(%d) : ",x);                 /* エンキューされた値の画面表示 */
        printQueue();                               /* キューの中身を表示する関数 printQueue()の呼び出し */
    }

    for (i=0;i<QUEUE_SIZE;i++){                     /* for 文で{ }内をキューのサイズ(QUEUE_SIZE)回繰り返し */
    printf("dequeue() %d : ",dequeue());            /* デキューする関数の呼び出しとデキューされた値の表示 */
    printQueue();                                   /* キューの中身を表示する関数 printQueue()の呼び出し */
    }
    return 0;
}