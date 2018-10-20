#ifndef ONE_LIST_H
#define ONE_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LISTOK 0
#define LISTKEMPLY 1
#define LISTNOTMEM 2
#define LISTEND 3
int ListError=LISTOK;
typedef  struct point {double x,y,z;} point_3d ;
typedef point_3d basetype;
typedef struct element * Elptr;
struct element{basetype Date; Elptr Link; };
typedef struct LList { Elptr start,ptr; }List;


void List_init(List * l );
void List_done(List * l );
void Listput(List * l, basetype E);
void Listout(List * l, basetype * E );
void Listmove(List * l );
int Listemply(List * l);
int Listend(List * l);
void Listptrend(List * l);
void Listptrbegin(List * l);
void error_print_List(int a);



#endif // ONE_LIST_H_H_INCLUDED
