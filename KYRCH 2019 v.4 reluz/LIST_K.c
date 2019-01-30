#include"LIST_K.h"
int ListError=LISTOK;//=0
void List_init(List * l,basetype E)
{
    Elptr pntr=(Elptr )malloc(sizeof(struct element));
    if(pntr!=NULL)  // память выделена
    {
      l->start=pntr;
      l->ptr=pntr->Link=pntr;// делаум фиктивный указатель (сам на себя)
      l->size=1;
      l->ptr->Date=E;
    }
    else
      ListError=LISTNOTMEM;
}

void List_done(List *l)
{
    Listptrbegin(l);
    Elptr pntr=l->ptr;
    while(!Listemply(l))
    {
        l->ptr=pntr->Link;
        free(pntr);
        pntr=l->ptr;
        --l->size;
    }
    l->ptr=NULL;l->start=NULL;
}

void Listput(List * l, basetype E)
{
 Elptr pntr=(Elptr)malloc(sizeof(struct element));//выделяем память
if(pntr!=NULL)
 {
pntr->Date=E;
pntr->Link=l->ptr->Link;//Формируем указатель
l->ptr->Link=pntr;//модифицируем указатель
++l->size;
 }
 else ListError=LISTNOTMEM;
}

void Listrewrite(List * l, basetype E)
{
    if(!Listemply(l)) //список не пуст
    {
        l->ptr->Date=E;
    }
    else ListError=LISTEMPLY;
}

void Listmove(List * l )
{
   Elptr pntr=l->ptr;
   l->ptr=pntr->Link;//двигаемся на 1 шаг ро списку
}

int Listemply(List * l)
{
    return l->size<=0;  //список пуст
}

int Listbegin(List * l)
{
  return l->ptr==l->start;  //мы на first элементе
}

void Listptrbegin(List * l)
{
   l->ptr=l->start;  //в начасо списка
}

void Listread(List * l, basetype * E )
{
if(!Listemply(l)) //список не пуст
   *E=l->ptr->Date;
else ListError=LISTEMPLY;
}

unsigned Listcount(List *l)
{
    return l->size;
}
