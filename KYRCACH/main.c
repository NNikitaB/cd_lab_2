#include"ONE_LIST_KYRSCH.h"
#include <math.h>
#define N_NAME 100
#define EPSILON 0.001
#define TRUE
#define FALSE 0
int err_polig=0;
typedef enum position {PARALLEL=0,PERESEC=1,SPASEEUQUEL=2,PERPENDICULAR=3}pos;
int fprint_poligon(const char *s,List *p1,List * p2);
int print_poligon(List *p1,List * p2);
int fscan_poligon(const char *s,List *p1,List * p2);
int scan_poligon(List *p1,List * p2);
int numEuquel(double a,double b);
int planesPos(List *p1,List * p2);
void read_point(List * p,basetype * e);
void begin_poligon(List *p);
basetype comp_vect(basetype a,basetype b);
int vectEuquel(basetype a,basetype b);

void square_poligon(List *p1,List * p2);
List * comp_poligon_intersection(List *p1,List * p2,int *flag);
double comp_poligon_square(List *p,int flag);


double comp_poligon_square(List *p,int flag)
{
    double tmp=0.0;
    basetype t1_p,t2_p;
    begin_poligon(p);
    if(flag==1)
    {
        while(!Listend(p) && !Listbegin(p))
        {
            read_point(p,&t1_p);
            read_point(p,&t2_p);
            tmp+=(t1_p.x+t2_p.x)*(t1_p.y-t2_p.y);
        }
        if(Listbegin(p)){begin_poligon(p);t1_p=t2_p;read_point(p,&t2_p); tmp+=(t1_p.x+t2_p.x)*(t1_p.y-t2_p.y);}
        else{read_point(p,&t1_p);begin_poligon(p);read_point(p,&t2_p);tmp+=(t1_p.x+t2_p.x)*(t1_p.y-t2_p.y);}
    }
    if(flag==2)
    {
        while(!Listend(p) && !Listbegin(p))
        {
            read_point(p,&t1_p);
            read_point(p,&t2_p);
            tmp+=(t1_p.x+t2_p.x)*(t1_p.z-t2_p.z);
        }
        if(Listbegin(p)){begin_poligon(p);t1_p=t2_p;read_point(p,&t2_p); tmp+=(t1_p.x+t2_p.x)*(t1_p.z-t2_p.z);}
        else{read_point(p,&t1_p);begin_poligon(p);read_point(p,&t2_p);tmp+=(t1_p.x+t2_p.x)*(t1_p.z-t2_p.z);}
    }
    if(flag==3)
    {
        while(!Listend(p) && !Listbegin(p))
        {
            read_point(p,&t1_p);
            read_point(p,&t2_p);
            tmp+=(t1_p.y+t2_p.y)*(t1_p.z-t2_p.z);
        }
        if(Listbegin(p)){begin_poligon(p);t1_p=t2_p;read_point(p,&t2_p); tmp+=(t1_p.y+t2_p.y)*(t1_p.z-t2_p.z);}
        else{read_point(p,&t1_p);begin_poligon(p);read_point(p,&t2_p);tmp+=(t1_p.y+t2_p.y)*(t1_p.z-t2_p.z);}
    }

    return 0;
}

List * comp_poligon_intersection(List *p1,List * p2,int* flag)
{
    return NULL;
}





void square_poligon(List *p1,List * p2)
{
    unsigned char  c= planesPos(p1,p2);
    int flag=0;
    double tmp=0.0;
    List *p=NULL;

   if(c==SPASEEUQUEL) p=comp_poligon_intersection(p1,p2, &flag);
   else if(c!=PERESEC || c!=PARALLEL) err_polig=-1;

   if(p!=NULL && Listcount(p)!=1)tmp=comp_poligon_square(p,flag);// 1==-OZ   2==-OY  3==-OX
   printf("square poligon p= %lf",tmp);

}


basetype comp_vect(basetype a,basetype b)
{
    basetype tmp;
    tmp.x=b.x-a.x;
    tmp.y=b.y-a.y;
    tmp.z=b.z-a.z;
    return tmp;
}

void read_point(List * p,basetype * e){ Listread(p,e);Listmove(p);}

int numEuquel(double a,double b){return fabs(a-b)<EPSILON;}

void begin_poligon(List *p) {Listptrbegin(p);Listmove(p);}

int vectEuquel(basetype a,basetype b)
{
    return ( numEuquel(a.x,b.x) && numEuquel(a.y,b.y) && numEuquel(a.z,b.z));
}

int planesPos(List *p1,List * p2)
{
    basetype t1_p1,t2_p1,t1_p2,t2_p2,vect1,vect2;
    unsigned char x,y,z;
    begin_poligon(p1);
    begin_poligon(p2);
    read_point(p1,&t1_p1);
    read_point(p1,&t2_p1);
    read_point(p2,&t1_p2);
    read_point(p2,&t2_p2);
    vect1=comp_vect(t1_p1,t2_p1);
    vect2=comp_vect(t1_p2,t2_p2);
    x=numEuquel(vect1.x,vect2.x);
    y=numEuquel(vect1.y,vect2.y);
    z=numEuquel(vect1.z,vect2.z);
    if( x && y && z ) return SPASEEUQUEL;
    else if ( (x&&y) || (y&&z) || (z&&x) ) return PARALLEL;
    else return PERESEC;
}

int scan_poligon(List *p1,List * p2)
{
    int i=0;
    basetype point1,point2;
    Listptrbegin(p1);
    printf("write size poligon 1\n");
    scanf("%i",&i);
    printf("write poligon 1\n");
    while(i>0)
    {
        scanf("%lf %lf %lf",&point1.x,&point1.y,&point1.z);
        Listput(p1,point1);
        Listmove(p1);
        --i;
    }
    Listptrbegin(p2);
    i=0;
    printf("write size poligon 2\n");
    scanf("%i",&i);
    printf("write poligon 2\n");
    while(i>0)
    {

        scanf("%lf %lf %lf",&point2.x,&point2.y,&point2.z);
        Listput(p2,point2);
        Listmove(p2);
        --i;
    }
return 0;
}

int fscan_poligon(const char *s,List *p1,List * p2)
{
    int i;
    FILE *f=fopen(s,"r+");
    basetype point1,point2;
    Listptrbegin(p1);
    fscanf(f,"%i",&i);
    while(i>0)
    {
        fscanf(f,"%lf %lf %lf",&point1.x,&point1.y,&point1.z);
        Listput(p1,point1);
        Listmove(p1);
        --i;
    }
    Listptrbegin(p2);
    i=0;
    fscanf(f,"%i",&i);
    while(i>0)
    {

        fscanf(f,"%lf %lf %lf",&point2.x,&point2.y,&point2.z);
        Listput(p2,point2);
        Listmove(p2);
        --i;
    }
fclose(f);
return 0;
}



int print_poligon(List *p1,List * p2)
{
    basetype point1,point2;
    Listptrbegin(p1);
    if(Listbegin(p1))Listmove(p1);
    int i=Listcount(p1);
    printf("%i \n",i);
    while(!Listbegin(p1))
    {
        Listread(p1,&point1);
        Listmove(p1);
        printf("%lf \n%lf \n%lf \n",point1.x,point1.y,point1.z);
    }
    Listptrbegin(p2);
    if(Listbegin(p2))Listmove(p2);
    i=Listcount(p2);
    printf("%i \n",i);
    while(!Listbegin(p2))
    {
        Listread(p2,&point2);
        Listmove(p2);
        printf("%lf \n%lf \n%lf \n",point2.x,point2.y,point2.z);
    }

return 0;
}
int fprint_poligon(const char *s,List *p1,List * p2)
{
    FILE *f=fopen(s,"w+");
    basetype point1,point2;
    Listptrbegin(p1);
    if(Listbegin(p1))Listmove(p1);
    int i=Listcount(p1);
    fprintf(f,"%i \n",i);
    while(!Listbegin(p1))
    {
        Listread(p1,&point1);
        Listmove(p1);
        fprintf(f,"%lf \n%lf \n%lf \n",point1.x,point1.y,point1.z);
    }
    Listptrbegin(p2);
    if(Listbegin(p2))Listmove(p2);
    i=Listcount(p2);
    fprintf(f,"%i \n",i);
    while(!Listbegin(p2))
    {
        Listread(p2,&point2);
        Listmove(p2);
        fprintf(f,"%lf \n%lf \n%lf \n",point2.x,point2.y,point2.z);
    }

fclose(f);
return 0;
}

int main()
{
   char name[N_NAME];
   List p1={NULL,NULL},p2={NULL,NULL};
   List_init(&p1);
   List_init(&p2);
   int flag=0;
   printf("write poligon in file=1 or terminal=0  \n");
   scanf("%i",&flag);
   if(flag)
    {
        fgets(name,N_NAME,stdin);
        fscan_poligon(name,&p1,&p2);
    }
   else
   {
        scan_poligon(&p1,&p2);
   }


   if(flag)
    {
        fprint_poligon(name,&p1,&p2);
    }
   else
   {
        print_poligon(&p1,&p2);
   }

    printf("Hello world! %i \n",ListError);
    return 0;
}


//////List li={NULL,NULL};
//////
//////basetype e;e.x=0.1;e.y=0.1;e.z=0.1;
//////
//////    List_init(&li);
//////    Listput(&li,e);
////// e.x=0.0;e.y=0.0;e.z=0.0;
//////    Listput(&li,e);
//////    Listptrbegin(&li);e.x=0.01;e.y=0.01;e.z=0.01;
//////    Listout(&li,&e);
//////    printf("Hello world! %lf\n",e.x);
//////    Listmove(&li);
//////   // Listout(&li,&e);
//////   Listptrend(&li);
////// //  Listout(&li,&e);
//////    Listptrbegin(&li);
//////     Listout(&li,&e);
//////   //  Listout(&li,&e);
//////  // e.x=0.01;e.y=0.01;e.z=0.01;
//////    printf("Hello world! %lf\n",e.x);
//////    printf("Hello world! %i \n",ListError);
////// printf("Hello world! %i \n",ListError);
//////    return 0;
