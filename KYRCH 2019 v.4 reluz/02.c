//#include <stdio.h>
//#include <stdlib.h>
//#include"LIST_K.h"
//#include"fileio.h"
//#include"poligon.h"
//#include <math.h>
//#define N_NAME 100
//int main()
//{
//   char name[N_NAME];
//   List p1={NULL,NULL,0},p2={NULL,NULL,0};
//   int flag=1;
//   printf("write poligon input and output in files=1 or terminals=0  \n");
//   scanf("%i",&flag);
//   FILE *f=stdin,*d=stdout;
//   if(flag)
//    {
//        fgets(name,N_NAME,stdin);
//
//        f=fopen(name,"r+");
//    }
//   fscan_poligon(f,&p1);
//   fscan_poligon(f,&p2);
//   if(flag)
//    {
//        fgets(name,N_NAME,stdin);
//        d=fopen(name,"w+");
//    }
//fprintf(d,"\n S=%f\n",square_poligon(&p1,&p2));
//fprint_poligon(d,&p1);
//fprint_poligon(d,&p2);
//List_done(&p1);
//List_done(&p2);
//printf("ERR %i \n",ListError);
//return 0;
//}
