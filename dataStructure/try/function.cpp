//
// Created by kuang junlin on 18/10/9.
//
#define ElemType int
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if(L)L->next=NULL;
}
LinkList LinkListCreate(){
    LNode L;
    InitList(L);
    LNode *r;
    r = L;
    ElemType x;
    while (scanf("%d",&x)){
        LNode *p;
        p = (LNode)malloc(sizeof(LNode));
        p->data= x;
        r->next= p;
        r=p;
    }
    r->next=NULL;
    return L;
}