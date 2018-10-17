//
// Created by kuang junlin on 18/10/15.
//
#include "stdio.h"
#include "stdlib.h"
#define Status bool
#define MAXQSIZE 100
#define QElemType int

typedef struct {
    QElemType data[];
    int front;
    int rear;
    int count;
}SqQueue;

//初始化
Status initQueue(SqQueue &Q){
    Q.data = (QElemType)malloc(MAXQSIZE * sizeof(QElemType));
    if(!Q.data){
        return false;
    }
    Q.front = Q.rear = 0;
    Q.count = 0;
    return true;
}

// 判断是否为满,计数器方法
Status isFull(SqQueue &Q){
    if (Q.count == MAXQSIZE){
        return true;
    }
    return false
}

// 入队
// * 队空和队满时头尾指针均相等。无法通过front=rear来判断队列“空”还是“满”。
Status EnQueue(SqQueue &Q, QElemType e){
    if (isFull(Q)) return false;
    Q.data[Q.rear] = e;
    //当队列不为空，front指向队列的第一个元素，rear指向队列最后一个元素的下一个位置；
    Q.rear = (Q.rear+1) %MAXQSIZE ;
    Q.count++;
}

// 出队
Status DeQueue(SqQueue &Q, QElemType e){
    if (Q.count == 0) return false; //队列为空
    e = Q.front;
    Q.front = (Q.front+1) % MAXQSIZE;
    Q.count--;
    return true;
}

// 求队列元素个数
int NumQueue(SqQueue &Q){
    return Q.count;
}

// 判断是否为空
Status isEmpty(SqQueue &Q){
    if (Q.count == 0)return true;
    return false;
}





