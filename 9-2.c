#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5            /* 例題 9-1 と同じ */
typedef int QUEUE_TYPE;         /* 例題 9-1 と同じ */

QUEUE_TYPE gQueue[QUEUE_SIZE];  /* 例題 9-1 と同じ */
int gQNum;                      /* 例題 9-1 と同じ */

void error(char *s){                /* エラーメッセージを表示する関数 error()の定義 */
    fflush(stdout);                 /* キューがフル状態でエンキューした場合 および */
    fprintf(stderr, "\n%s\n", s);   /* キューが空状態でデキューした場合に */
    exit(1);                        /* 引数である文字列表示して終了 */
}

void initQueue(void){           /* キューを初期化する関数 initQueue の定義(例題 9-1 と同じ) */
    gQNum=0; 
} 

int chkEmpty(void){             /* キューが空状態かチェックする関数 chkEmpty()の定義 */
    return gQNum == 0;          /* キューが空状態である(gQNum==0 が真) → 1 を返す */
}                               /* キューが空状態でない(gQNum==0 が偽) → 0 を返す */

int chkFull(void){              /* キューがフル状態かチェックする関数 chkFull()の定義 */
    return gQNum == QUEUE_SIZE; /* キューがフル状態である(gQNum==QUEUE_SIZE が真) → 1 を返す */
}                               /* キューがフル状態である(gQNum==QUEUE_SIZE が偽) → 0 を返す */


void enqueue(QUEUE_TYPE x){     /* エンキューする関数 enqueue(x)の定義 */
    if(chkFull())               /* キューがフル状態かチェックする関数 chkFull の呼び出し */
        error("enqueue : フル状態のためエンキューできません．"); /* フル状態であればメッセージを引数として error 関数を呼び出し*/
    gQueue[gQNum++] = x;        /* 例題 9-1 と同じ */
} 

int dequeue(void){                  /* デキューする関数 dequeue()の定義 */
    QUEUE_TYPE x;                   /* 例題 9-1 と同じ */
    int i;
    if (chkEmpty())                 /* キューが空状態かチェックする関数 chkEmpty の呼び出し */
        error("dequeue : 空状態のためデキューできません．"); /* 空状態であればメッセージを引数として error 関数を呼び出し*/

    x = gQueue[0];                  /* 例題 9-1 と同じ */
    for (i=1;i<=gQNum-1;i++){       /* 例題 9-1 と同じ */
    gQueue[i-1]=gQueue[i];          /* 例題 9-1 と同じ */
    }                               /* 例題 9-1 と同じ */
    gQNum--;                        /* 例題 9-1 と同じ */
    return x;                       /* 例題 9-1 と同じ */
}

void printQueue(void){              /* キューの中身を表示する関数 printQueue()の定義（例題 9-1 と同じ） */
    int i; 
    printf("\t"); 
    printf("キューの中 [ "); 
    for (i=0;i<gQNum;i++){ 
        printf("%d", gQueue[i]); 
        if(i != gQNum) printf(" "); 
    } 
    printf("]\n"); 
    fflush(stdout); 
} 

int main(void){
    QUEUE_TYPE x;                   /* 例題 9-1 と同じ */

    initQueue();                    /* キューを初期化する関数 initstack()の呼び出し */

    while(!chkFull()){              /* キューが空状態でなければ{ }内を繰り返し */
        printf("整数を入力して下さい:\n"); /* 例題 9-1 と同じ */
        scanf("%d",&x);                 /* 例題 9-1 と同じ */
        if (x==0) break;                /* 0 が入力されたら while を抜ける */
        enqueue(x);                     /* 例題 9-1 と同じ */
        printf("enqueue(%d) : ",x);     /* 例題 9-1 と同じ */
        printQueue();                   /* 例題 9-1 と同じ */
    }

    while(!chkEmpty()){                 /* キューが空状態でなければ{ }内を繰り返し */
        printf("dequeue() %d : ",dequeue()); /* 例題 9-1 と同じ */
        printQueue();                   /* 例題 9-1 と同じ */
    } 

    return 0;
}