#include"LIST_K.h"

int ListError=LISTOK;//=0
void List_init(List * l,basetype * E)
{
    Elptr pntr=(Elptr )malloc(sizeof(struct element));
    if(pntr!=NULL)  // ������ ��������
    {
      l->start=pntr;
      l->ptr=pntr->Link=pntr;// ������ ��������� ��������� (��� �� ����)
      l->size=1;
      l->ptr->Date=*E;
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


void Listput(List * l, basetype * E)
{
 Elptr pntr=(Elptr)malloc(sizeof(struct element));//�������� ������
if(pntr!=NULL)
 {
pntr->Date=*E;
pntr->Link=l->ptr->Link;//��������� ���������
l->ptr->Link=pntr;//������������ ���������
++l->size;
 }
 else ListError=LISTNOTMEM;
}

void Listrewrite(List * l, basetype E)
{
    if(!Listemply(l)) //������ �� ����
    {
        l->ptr->Date=E;
    }
    else ListError=LISTEMPLY;
}

void Listout(List * l, basetype * E )
{
Elptr pntr=NULL;
if(!Listemply(l)) //������ �� ����
 {
if(!Listend(l) )// ������ �� �� ��������� ��������
{
pntr=l->ptr->Link;
*E=pntr->Date;
l->ptr->Link=pntr->Link;
free(pntr);
l->size--;
}
else {
        ListError=LISTEND;
     }
 }
 else ListError=LISTEMPLY;

}


void Listmove(List * l )
{
   Elptr pntr=l->ptr;
   l->ptr=pntr->Link;//��������� �� 1 ��� �� ������
}

int Listemply(List * l)
{
    return l->size<=0;  //������ ����
}

int Listend(List * l)
{
  return l->ptr->Link==l->start;  //�� �� ��������� ��������
}

int Listbegin(List * l)
{
  return l->ptr==l->start;  //�� �� first ��������
}

void Listptrend(List * l)
{
while(!Listend(l))   // ���� �� �� �� ��������� ��������
    Listmove(l);    //��������� �� 1 ��� �� ������
}


void Listptrbegin(List * l)
{
   l->ptr=l->start;  //� ������ ������
}


void Listread(List * l, basetype * E )
{
if(!Listemply(l)) //������ �� ����
 {*E=l->ptr->Date;}
  else ListError=LISTEMPLY;
}

unsigned long Listcount(List *l)
{
    return l->size;
}


void Listmoveto(List *l,unsigned n)
{
if(!Listemply(l))
{
int i=Listcount(l);
if(n>=i)n=n%i;
i=0;
Listptrbegin(l);
while(i<n)++i,Listmove(l);
}
}
