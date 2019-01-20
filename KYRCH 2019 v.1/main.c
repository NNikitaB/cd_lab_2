#include <stdio.h>
#include <stdlib.h>
#include"LIST_K.h"
#include"fileio.h"
#include"poligon.h"
#include <math.h>
#define N_NAME 100


int print_poligon(List *p1)
{
    basetype point1,point2;
    Listptrbegin(p1);
    int i=0, n=Listcount(p1);
    printf("%i \n",n);
    while(n>i)
    {
        Listread(p1,&point1);
        Listmove(p1);
        printf("x=%.3lf y=%.3lf z=%.3lf \n",point1.x,point1.y,point1.z);
        ++i;
    }

return 0;
}
int main()
{
   char name[N_NAME]="plg.text";
   List p1={NULL,NULL,0},p2={NULL,NULL,0};
   int flag=1;
   printf("write poligon input and output in files=1 or terminals=0  \n");
  // scanf("%i",&flag);
   FILE *f=stdin,*d=stdout;
   if(flag)
    {
        //fgets(name,N_NAME,stdin);
        //name="D:\\cods\\KYRCH 2019\\plg.text";
        f=fopen(name,"r+");
    }
   fscan_poligon(f,&p1,&p2);
List *R=comp_poligon_intersection(&p1,&p2);
print_poligon( R);
//print_p(p1.ptr->Date);
//search_point_polig(&p1,p2.ptr->Date);
//print_p(p1.ptr->Date);
printf("----------\n");
flag=0;

   if(flag)
    {
        fgets(name,N_NAME,stdin);
        d=fopen(name,"w+");
    }
fprint_poligon(d,&p1,&p2);



    printf("Hello world! %i \n",ListError);

    printf("Hello world!\n%i",5/2);
    return 0;
}
