#include "ONE_LIST_H.h"

void List_init(List * l)
{
    Elptr pntr=(Elptr )malloc(sizeof(struct element));
    if(pntr!=NULL)
    {
      l->start=pntr;
      pntr->Date=NULL;
      l->ptr=pntr->Link=pntr;
    }
    else ListError=LISTNOTMEM;
}

void List_done(List *l)
{
    void Listptrbegin(List * l);
    Elptr pntr=l->ptr;
    while(pntr->Date!=NULL)
    {
        l->ptr=pntr->Link;
        free(pntr);
        pntr=l->ptr;
    }
}
void Listput(List * l, basetype E)
{
 l->start=(Elptr)malloc(sizeof(element));
 (l->start!=NULL)
 {

 }
 else
}

void Listout(List * l, basetype * E )
{

}


void Listmove(List * l )
{

}

int Listemply(List * l)
{
    return l->start==NULL;
}

int Listend(List * l)
{

}

void Listptrend(List * l)
{

}

void Listptrbegin(List * l)
{

}
