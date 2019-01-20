#include"poligon.h"
int err_polig=0;

basetype comp_vect(basetype a,basetype b)
{
    basetype tmp;
    tmp.x=b.x-a.x;
    tmp.y=b.y-a.y;
    tmp.z=b.z-a.z;
    return tmp;
}

basetype vect_norm(basetype a,basetype b)
{
      basetype n ;
    n.x=(a. y * b.z - b.y * a.z);
  n.y=( b.x * a.z-a. x * b.z );
  n.z=(a. x * b.y - b.x * a.y);
    return n;
}

int numEuquel(double a,double b){return fabs(a-b)<EPSILON;}

int vectEuquel(basetype a,basetype b)
{
    return ( numEuquel(a.x,b.x) && numEuquel(a.y,b.y) && numEuquel(a.z,b.z));
}

double mixed_comp_vect(basetype a, basetype b,basetype c)
{
 return  ( a.x*b.y*c.z + a.y*b.z*c.x + b.x*c.y*a.z - c.x*b.y*a.z - a.y*b.x*c.z - b.z*c.y*a.x );
}

double max(double x, double y)
{
    return (x < y)? y:x;
}

double min(double x, double y)
{
    return (x < y)? x:y;
}

int point_in_vect(basetype p0, basetype p1,basetype p2)
{
    return( ((min(p0.x,p1.x)<=p2.x) && (p2.x<=max(p0.x,p1.x)))
           &&((min(p0.y,p1.y)<=p2.y) && (p2.y<=max(p0.y,p1.y)))
           &&((min(p0.z,p1.z)<=p2.z) && (p2.z<=max(p0.z,p1.z))) );
}

int point_in_plane_vect(basetype p0, basetype p1,basetype p2)//проекция точки лежит на вектре
{
    return( (((min(p0.x,p1.x)<=p2.x) && (p2.x<=max(p0.x,p1.x))) &&((min(p0.y,p1.y)<=p2.y) && (p2.y<=max(p0.y,p1.y))))
           ||(((min(p0.x,p1.x)<=p2.x) && (p2.x<=max(p0.x,p1.x))) &&((min(p0.z,p1.z)<=p2.z) && (p2.z<=max(p0.z,p1.z))))
           ||(((min(p0.z,p1.z)<=p2.z) && (p2.z<=max(p0.z,p1.z))) &&((min(p0.y,p1.y)<=p2.y) && (p2.y<=max(p0.y,p1.y)))) );
}

int sign(double a){return a>=0.0 ? 1:-1;} //1 если знак +

double dProduct(basetype a, basetype b)//скалярное троизведение
{
  return (a.x*b.x + a.y*b.y + a.z*b.z);
}

void print_p(basetype a)
{
    printf("x=%lf ,y=%lf ,z=%lf \n",a.x,a.y,a.z);
}


int classify(basetype p0, basetype p1,basetype p2)//где точка p2 относительно  отрезка p0p1
{
  //basetype p2 = *this;
  basetype a = comp_vect(p0,p1); //p1 - p0;
  basetype b = comp_vect(p0,p2);//p2 - p0;
  //находим вектор нормали с
  basetype c;
  c.x=(a. y * b.z - b.y * a.z);
  c.y=-(a. x * b.z - b.x * a.z);
  c.z=(a. x * b.y - b.x * a.y);
    //находим смешаное произведение чтобы определить левая или правая тройка
    double sa =  mixed_comp_vect(a,b,c);
    //printf("%f\n",sa);
  if (sa > EPSILON)//>0 правая тройка
    return LEFT;
  if (sa < -EPSILON)//<0 левая  тройка
    return RIGHT;
  if (vectEuquel(p0 , p2))
    return ORIGIN;
  if (vectEuquel(p1 , p2))
    return DESTINATION;

  if(point_in_vect(p0,p1,p2))return BETWEEN;
   return -1;
}

int edgeType (basetype v, basetype w,basetype a)
{
  switch (classify(v,w,a)) {
    case LEFT:
      return (point_in_plane_vect(v,w,a)) ? CROSSING : INESSENTIAL;
    case RIGHT:
      return (point_in_plane_vect(v,w,a)) ? CROSSING : /*(point_in_vect(w,v,a)) ? CROSSING :*/ INESSENTIAL;
    case BETWEEN:
    case ORIGIN:
    case DESTINATION:
      return TOUCHING;
    default:
      return INESSENTIAL;

  }
}

basetype point(basetype org,basetype dest,double t)//
{
   basetype tmp;//comp_vect(org,dest);
  tmp.x=dest.x*t+org.x;
  tmp.y=dest.y*t+org.y;
  tmp.z=dest.z*t+org.z;

  return tmp;
 //(org + t * (dest - org));
}

int intersect(basetype a, basetype b,basetype c,basetype d, basetype *p)
{
    int zn=SKEW_CROSS;
  basetype n=comp_vect(c,d);
   basetype tmp= comp_vect(a,b);
  double denom = dProduct(n, tmp);
  if (numEuquel(denom,0.0))
  {
    int aclass = classify(c,d,a);
    if ((aclass==LEFT) || (aclass==RIGHT))
         zn=PARALLEL;
    else return COLLINEAR;
  }


  basetype p1=vect_norm(tmp,comp_vect(a,c));
  basetype p2=vect_norm(tmp,comp_vect(a,d));
  if(sign(p1.z)==(sign(p2.z)))return SKEW_NO_CROSS;
   if(numEuquel(p1.z,0.0)){*p=c;return zn;}
  if(numEuquel(p2.z,0.0)){*p=d;return zn;}

   p1=vect_norm(tmp,comp_vect(b,c));
   p2=vect_norm(tmp,comp_vect(b,d));
  if(sign(p1.z)==(sign(p2.z)))return SKEW_NO_CROSS;
   if(numEuquel(p1.z,0.0)){*p=c;return zn;}
  if(numEuquel(p2.z,0.0)){*p=d;return zn;}

  double num = fabs(p2.z-p1.z);
  num = fabs(p1.z)/num;
  *p=point(c,n,num);//*p=point(c,d,num);
  return zn;

}

void add_point_polig(List * p,basetype t)//добавить точку в полигон
{
     if(p->start!=NULL)Listput(p,t);
     else List_init(p,t);
}

int search_point_polig(List * p,basetype t)//ищет точку м возвр в начальную точку
{
    int i=0,c=FALSE,n=Listcount(p);
    basetype point;
    while(i<n && c==FALSE)
    {
        Listread(p,&point);
        c=vectEuquel(t,point);
        ++i;
    }
    while(i<n)Listread(p,&point),++i;
    return c;
}

int aimsAt(basetype a, basetype b,basetype c,basetype d,int aclass,int crossType)
{
    basetype v1=comp_vect(a,b);
    basetype v2=comp_vect(c,d);
    if(crossType!=COLLINEAR)
    {
       //if(mixed_comp_vect(c,d,a)>0)//a нацелено на вектор cd
       if(dProduct(v1,v2)>0.0)return (aclass != RIGHT);
       else return (aclass != LEFT);
    }else return (aclass != BEYOND);
}

void advance (List *A, List *R, int inside)
{
    basetype r_point,a_point;
  Listmove(A);
  Listread(R,&r_point);
  Listread(A,&a_point);
  if(inside && vectEuquel(a_point,r_point)==0 )
    add_point_polig(R,a_point);
}
int pointlnConvexPolygon (basetype s , List *p)
{
//    if (p->size == 1) return (s == p.point());
//    if (p->size == 2) {
//    int c = s .classify (p. edge ());
//    return ( c==TOUCHING );}
return FALSE;
}


List * comp_poligon_intersection(List *P,List * Q)
{
   List T={NULL,NULL,0};
   List *R=&T;
   basetype iPnt,startPnt,r_point;
   basetype p_edge_org,q_edge_org,p_edge_dest,q_edge_dest;
   int inflag=UNKNOWN;
   int phase=1;
   int maxInts=2*(Listcount(Q)+Listcount(P));
   Listread(P,&p_edge_dest);
   Listread(Q,&q_edge_dest);
   for (int i = 1; (i<=maxInts) || (phase==2); i++)
   {
       p_edge_org=p_edge_dest;print_p(p_edge_org);
       q_edge_org=q_edge_dest;print_p(p_edge_dest);
       Listread(P,&p_edge_org);print_p(q_edge_org);
       Listread(Q,&q_edge_org);print_p(q_edge_dest);
       int p_class = classify(q_edge_org,q_edge_dest,p_edge_dest);
       int q_class = classify(p_edge_org,p_edge_dest,q_edge_dest);
       int crossType = intersect(p_edge_org,p_edge_dest,q_edge_org,q_edge_dest,&iPnt);
       printf("------%i----\n",crossType );print_p(iPnt);
       if(crossType==SKEW_CROSS)
       {
           if(phase==1)
           { //printf("++++++++++++\n");
               phase=2;
               add_point_polig(R,iPnt);
               startPnt=iPnt;
           }
           else
           {
               Listread(R,&r_point);
               if(vectEuquel(iPnt,r_point)==0)
                {if(vectEuquel(iPnt,startPnt)==0)add_point_polig(R,iPnt);
                else return R;
                }
           }
         if (p_class==RIGHT) inflag = P_IS_INSIDE;
         else if (q_class==RIGHT) inflag = Q_IS_INSIDE;
         else inflag = UNKNOWN;
       }
       else if ( (crossType-COLLINEAR) && (p_class != BEHIND) && (q_class != BEHIND) )inflag = UNKNOWN;

       int pAIMSq = aimsAt(p_edge_org,p_edge_dest,q_edge_org,q_edge_dest, p_class, crossType);
       int qAIMSp = aimsAt(q_edge_org,q_edge_dest, p_edge_org,p_edge_dest, q_class, crossType);
       if (pAIMSq && qAIMSp)
        {
           if ( (inflag == Q_IS_INSIDE) || ( (inflag == UNKNOWN)  && (p_class == LEFT)))
        advance(P, R, FALSE);
      else
        advance (Q, R, FALSE);
        }else if(pAIMSq)advance(P, R, inflag == P_IS_INSIDE);
              else if(qAIMSp)advance(Q, R, inflag == Q_IS_INSIDE);
                    else  if((inflag == Q_IS_INSIDE) || ((inflag == UNKNOWN) && (p_class == LEFT)))
                            advance ( P , R , FALSE );
                          else advance (Q, R, FALSE);

                          printf("----------\n");
   }







return R;
}







