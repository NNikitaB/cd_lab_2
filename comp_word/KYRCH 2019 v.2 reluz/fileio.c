#include"fileio.h"

int fscan_poligon(FILE *f,List *p1,List * p2)
{
    int i=0;
    basetype point1,point2;
    fscanf(f,"%i",&i);
    fscanf(f,"%lf %lf ",&point1.x,&point1.y/*,&point1.z*/);
    List_init(p1,point1);
    --i;
    while(i>0)
    {
        fscanf(f,"%lf %lf ",&point1.x,&point1.y/*,&point1.z*/);
        Listput(p1,point1);
        Listmove(p1);
        --i;
    }

    i=0;
    fscanf(f,"%i",&i);
    fscanf(f,"%lf %lf ",&point2.x,&point2.y/*,&point2.z*/);
    List_init(p2,point2);
    --i;
    while(i>0)
    {
        fscanf(f,"%lf %lf ",&point2.x,&point2.y/*,&point2.z*/);
        Listput(p2,point2);
        Listmove(p2);
        --i;
    }
fclose(f);
return 0;
}

int fprint_poligon(FILE *f,List *p1,List * p2)
{
    basetype point1,point2;
    Listptrbegin(p1);
    int i=0, n=Listcount(p1);
    fprintf(f,"%i \n",n);
    while(n>i)
    {
        Listread(p1,&point1);
        Listmove(p1);
        fprintf(f,"x=%.3lf y=%.3lf \n",point1.x,point1.y/*,point1.z*/);
        ++i;
    }
    Listptrbegin(p2);
    i=0;
    n=Listcount(p2);
    fprintf(f,"%i \n",n);
    while(n>i++)
    {
        Listread(p2,&point2);
        Listmove(p2);
        fprintf(f,"x=%.3lf y=%.3lf  \n",point2.x,point2.y/*,point2.z*/);
    }

fclose(f);
return 0;
}
