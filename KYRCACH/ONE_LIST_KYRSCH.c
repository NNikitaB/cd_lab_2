#include"ONE_LIST_KYRSCH.h"

int ListError=LISTOK;//=0
void List_init(List * l)
{
    Elptr pntr=(Elptr )malloc(sizeof(struct element));
    if(pntr!=NULL)  // память выделена
    {
      l->start=pntr;
      l->ptr=pntr->Link=pntr;// делаум фиктивный указатель (сам на себя)
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
    }
    free(l->start);l->ptr=NULL;l->start=NULL;
}


void Listput(List * l, basetype E)
{
 Elptr pntr=(Elptr)malloc(sizeof(struct element));//выделяем память
if(pntr!=NULL)
 {
pntr->Date=E;
pntr->Link=l->ptr->Link;//Формируем указатель
l->ptr->Link=pntr;//модифицируем указатель

 }
 else ListError=LISTNOTMEM;

}

void Listout(List * l, basetype * E )
{
Elptr pntr=NULL;
if(!Listemply(l)) //список не пуст
 {
if(!Listend(l) )// список не на послнднем элементе
{
pntr=l->ptr->Link;
*E=pntr->Date;
l->ptr->Link=pntr->Link;
free(pntr);

}
else ListError=LISTEND;
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
    return l->start==l->start->Link;  //список пуст
}

int Listend(List * l)
{
  return l->ptr->Link==l->start;  //мы на последнем элементе
}

int Listbegin(List * l)
{
  return l->ptr==l->start;  //мы на first элементе
}

void Listptrend(List * l)
{
while(!Listend(l))   // пока мы не на последнем элементе
    Listmove(l);    //двигаемся на 1 шаг ро списку
}

void Listptrbegin(List * l)
{
   l->ptr=l->start;  //в начасо списка
}


void Listread(List * l, basetype * E )
{
if(!Listemply(l)) //список не пуст
 {
if(!Listbegin(l))// список не на послнднем элементе
{
*E=l->ptr->Date;
}
else ListError=LISTEND;
 }
 else ListError=LISTEMPLY;
}

int Listcount(List *l)
{
    Elptr pntr=l->ptr;
    int i=0;
    Listptrbegin(l);
    while(!Listend(l))++i,Listmove(l);
    l->ptr=pntr;
    return i;
}
void Listmoveto(List *l,unsigned n)
{
if(!Listemply(l))
{
int i=Listcount(l);
if(n<i)
   {
      i=0;
      Listptrbegin(l);
      while(!Listend(l))++i,Listmove(l);
   }
else
   {
      i=0;n/=i;
      Listptrbegin(l);
      while(!Listend(l))++i,Listmove(l);
   }
}
}
void Listcopy(List * l1, List * l2)
{
    if(l1!=NULL && l2!=NULL && !Listemply(l1) && !Listemply(l2))
    {
         basetype e;
         if(Listbegin(l1))Listmove(l1);
         while(!Listbegin(l1)){Listread(l1,&e);Listmove(l1);Listput(l2,e);}
    }

}
