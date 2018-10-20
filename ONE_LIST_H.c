#include "ONE_LIST_H.h"
#define FICT 0.000012
void List_init(List * l)
{
    Elptr pntr=(Elptr )malloc(sizeof(struct element));
    if(pntr!=NULL)
    {
      l->start=pntr;
      pntr->Date.x=FICT;
      l->ptr=pntr->Link=pntr;
    }
    else ListError=LISTNOTMEM;
}

void List_done(List *l)
{
    void Listptrbegin(List * l);
    Elptr pntr=l->ptr;
    while(pntr->Date.x!=FICT)
    {
        l->ptr=pntr->Link;
        free(pntr);
        pntr=l->ptr;
    }
}
void Listput(List * l, basetype E)
{
 l->start=(Elptr)malloc(sizeof(struct element));
if(l->start!=NULL)
 {

 }
 else;
 
}

void Listout(List * l, basetype * E )
{

}


void Listmove(List * l )
{
	Elptr pntr=l->ptr;
   l->ptr=pntr->Link;
}

int Listemply(List * l)
{
    return l->start==l->ptr->Link;
}

int Listend(List * l)
{
  return l->ptr->Link==l->start;
}

void Listptrend(List * l)
{
Elptr pntr=NULL;
while(!Listend(l))
{ pntr=l->ptr; l->ptr=pntr->Link;}
}

void Listptrbegin(List * l)
{
  
}
main(void)
{
	return 0;
}