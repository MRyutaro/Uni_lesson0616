#include <stdio.h> 
#include <stdlib.h> 

struct cell{                                        /* 構造体 cell の定義 */
    int element;                                    /* cell のメンバ element(キューに格納されるデータ) */
    struct cell *next;                              /* 次のセルを指すポインタ変数 *init */
};

struct queue{                                       /* 構造体 queue の定義 */
    struct cell *front;                             /* キューの先頭のセルを指すポインタ変数*front */
    struct cell *rear;                              /* キューの末尾のセルを指すポインタ変数*rear */
};

void enqueue(int x, struct queue *Q){               /* エンキューする関数 enqueue の定義 */
    struct cell *p;                                 /* エンキューするセルを指すポインタ変数*p の宣言 */
    p=(struct cell *)malloc(sizeof(struct cell));   /* エンキューするセルを指すポインタ変数*p の獲得 */
    if(Q->rear != NULL){                            /* Q->rear が NULL(キューが空状態)でなければ， */
        (Q->rear)->next = p;                        /* Q->rear の次に p が指すセルを挿入 */
    }
    Q->rear = p;                                    /* キューの末尾を*p が指しているセルに更新 */
    if(Q->front == NULL){                           /* Q->front が NULL(キューが空状態)であれば， */
        Q->front = p;                               /* キューの先頭(Q->front)*p が指しているセルに更新*/
    }
    (Q->rear)->element = x;                         /* キューの末尾(Q->rear)のメンバ element に x を代入*/
    (Q->rear)->next = NULL;                         /* キューの末尾(Q->rear)のメンバ next に NULL */
    return;
}

void dequeue(struct queue *Q){                      /* デキューする関数 dequeue の定義 */
    struct cell *q;                                 /* キューの先頭(デキューされるセル)を指す*q の宣言 */
    if(Q->front == NULL) {                          /* Q->front が NULL(キューが空状態)であれば */
        printf("空状態のためデキューできません．\n");  /* 左記のメッセージを画面に表示して */
        exit(1);                                    /* プログラムを終了 */
    }
    else {                                          /* Q->front が NULL(キューが空状態)でなければ */
        q=Q->front;                                 /* ポインタ変数*q はキューの先頭を指す */
        Q->front = (Q->front)->next;                /* キューの先頭(Q->front)を置き換える */
        free(q);                                    /* デキューされたセルのメモリを解放 */
    } 
    if(Q->front == NULL){                           /* Q->front が NULL(キューが空状態)であれば */
        Q->rear = NULL;                             /* キューの初期化 */
    }
    return;
}

void printQueue(struct queue *Q){                   /* キューの中身を表示する関数 printQueue()の定義 */
    struct cell *q;
    q=Q->front;                                     /* ポインタ変数*q はキューの先頭を指す */
    printf("\t");
    printf("キューの中 [ ");
    while(q!=NULL){                                 /* q!=NULL の間{ }内を実行 */
        printf("%d", q->element);                   /* メンバ element の値を表示 */
        printf(" "); 
        q=q->next;                                  /* キューの中の次のデータに移動 */
    }
    printf("]\n"); 
    fflush(stdout);
}

int main(void){
    struct queue Q;                                 /* キュー先頭(Q.front)，末尾(Q.Rear)をメンバとする構造体 Q の宣言 */
    struct cell *q;                                 /* キューの中身となる構造体 cell へのポインタ*q の宣言 */
    int x;                                          /* エンキューされるデータ x の宣言 */

    Q.front=Q.rear=NULL;                            /* キューの初期化 */

    while(1){
        printf("\n 整数を入力して下さい：\n");
        scanf("%d",&x);
        if (x==0) break;
        enqueue(x,&Q);                              /* 関数 enque の呼び出し(引数はエンキューされる値 x と Q) */
        printf("enqueue(%d) : ",x);
        printQueue(&Q);
    }

    q=Q.front;                                      /* ポインタ変数*q の初期化(キューの先頭を指すようにする) */
    while(q!=NULL){                                 /* q!=NULL の間{ }を実行 */
        dequeue(&Q);                                /* 関数 deque の呼び出し(*q が指すセル=キューの先頭が除かれる) */
        printf("dequeue します: ");
        printQueue(&Q);
    }

    return 0;
}