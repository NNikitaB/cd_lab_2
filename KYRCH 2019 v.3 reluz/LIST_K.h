#ifndef LIST_K_H_INCLUDED
#define LIST_K_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LISTOK 0
#define LISTEMPLY 1
#define LISTNOTMEM 2
#define LISTEND 3

extern int ListError;
typedef  struct point {double x,y,z;} point_3d ;
typedef point_3d basetype;
typedef struct element * Elptr;
struct element{basetype Date; Elptr Link; };
typedef struct LList { Elptr start,ptr;unsigned size; }List;

void List_init(List * l ,basetype E);
void List_done(List * l );
void Listput(List * l, basetype E);
void Listrewrite(List * l, basetype E);
void Listmove(List * l );
int Listemply(List * l);
void Listptrbegin(List * l);

int Listbegin(List * l);
void Listread(List * l, basetype * E );
unsigned Listcount(List *l);

#endif // LIST_K_H_INCLUDED
