#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include"LIST_K.h"
#include"fileio.h"
#include <math.h>
#define N_NAME 100
#define F_NAME 100



int print_poligon(List *p)
{
    char *s=NULL;
    Listptrbegin(p);
    long unsigned i=0, n=Listcount(p);
    printf("%lu \n",n);
    while(n>i)
    {
        Listread(p,&s);
        Listmove(p);
        printf("%s \n",s);
        ++i;
    }
return 0;
}
int main()
{
    setlocale(0,"Russian");
    printf("%i   %i",'ß','À');
   char name[N_NAME]="pldf-win.txt";
    char fname[F_NAME]="55.txt";
    char addname[F_NAME]="add.txt";
   List p={NULL,NULL,0};
   int flag=1;
   printf("write poligon input and output in files=1 or terminals=0  \n");
  // scanf("%i",&flag);
   FILE *f=stdin,*d=stdout,*add;
   if(flag)
    {
        //fgets(name,N_NAME,stdin);
        //name="D:\\cods\\KYRCH 2019\\plg.text";
        f=fopen(name,"r+");
    }
   fscan_poligon(f,&p);

//print_poligon(&p);
add=fopen(addname,"r+");
f_add_poligon(add,&p);
printf("----------\n");
flag=1;

   if(flag)
    {
       // fgets(name,N_NAME,stdin);
        d=fopen(fname,"w+");
    }
fprint_poligon(d,&p);
fprint_poligon(stdout,&p);



    printf("Hello world! %i \n",ListError);




    return 0;
}
