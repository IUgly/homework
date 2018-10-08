#include <cstdlib>
#include "status.h"

//
// Created by kuang junlin on 18/10/6.
//
typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


//创建一个空的双向循环链表
status CreateList_Dul(DuLinkList &L){
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if (L) {
        L->next = L;
        L->prior = L;
        return true;
    }
    return false;
}

//取得双向链表中第i个数据元素的位置指针
//在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在,返回NULL
status GetElemP_Dul(DuLinkList L, int i, DuLNode &ptr){

    DuLNode *p = L;//p指向头结点
    int j = 0;
    while (p && j<i){
        p = p->next;j++;
    }
    if (!p||j>i||i<0)return false;
    ptr.prior=p->prior;
    ptr.next=p->next;
}

//将单链表置逆
//https://blog.csdn.net/u010625000/article/details/38046221
status ReverseList_L(LinkList &L){
    LNode *pre, *cur, *next;
    pre = L;
    cur=next=NULL;
    while (pre){
        next = cur->next;//逆置结点前，先保存下一节点
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return true;
}
