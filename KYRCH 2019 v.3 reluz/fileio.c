#include"fileio.h"

int fscan_poligon(FILE *f,List *p1)
{
    int i=0;
    basetype point1;
    fscanf(f,"%i",&i);
    fscanf(f,"%lf %lf %lf ",&point1.x,&point1.y,&point1.z);
    List_init(p1,point1);
    --i;
    while(i>0)
    {
        fscanf(f,"%lf %lf %lf ",&point1.x,&point1.y,&point1.z);
        Listput(p1,point1);
        Listmove(p1);
        --i;
    }
return 0;
}

int fprint_poligon(FILE *f,List *p1)
{
    basetype point1;
    Listptrbegin(p1);
    int i=0, n=Listcount(p1);
    fprintf(f,"%i \n",n);
    while(n>i)
    {
        Listread(p1,&point1);
        Listmove(p1);
        fprintf(f,"x=%.3lf y=%.3lf z=%.3lf\n",point1.x,point1.y,point1.z);
        ++i;
    }
return 0;
}
