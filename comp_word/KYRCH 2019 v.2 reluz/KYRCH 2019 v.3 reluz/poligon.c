#include"poligon.h"
int err_polig=0;

basetype comp_vect(basetype a,basetype b)
{
    basetype tmp;
    tmp.x=b.x-a.x;
    tmp.y=b.y-a.y;
    return tmp;
}

double vect_norm(basetype a,basetype b)
{
  return (a. x * b.y - b.x * a.y);
}

int numEuquel(double a,double b){return fabs(a-b)<EPSILON;}

int vectEuquel(basetype a,basetype b)
{
    return ( numEuquel(a.x,b.x) && numEuquel(a.y,b.y) );
}


double max(double x, double y)
{
    return (x < y)? y:x;
}

double min(double x, double y)
{
    return (x < y)? x:y;
}

int point_in_plane_vect(basetype p0, basetype p1,basetype p2)//проекция точки лежит на вектре
{
    return( (((min(p0.x,p1.x)<=p2.x) && (p2.x<=max(p0.x,p1.x))) &&((min(p0.y,p1.y)<=p2.y) && (p2.y<=max(p0.y,p1.y)))) );
}

int sign(double a){return a>=0.0 ? 1:-1;} //1 если знак +

double dProduct(basetype a, basetype b)//скалярное троизведение
{
  return (a.x*b.x + a.y*b.y );
}

void print_p(basetype a)
{
    printf("x=%lf ,y=%lf \n",a.x,a.y);
}


double length_v(basetype a)
{
  return sqrt(a.x*a.x + a.y*a.y);
}

int classify(basetype p0, basetype p1,basetype p2)//где точка p2 относительно  отрезка p0p1
{
  //basetype p2 = *this;
  basetype a = comp_vect(p0,p1); //p1 - p0;
  basetype b = comp_vect(p0,p2);//p2 - p0;
  //находим вектор нормали с
   double sa=(a. x * b.y - b.x * a.y);

    //printf("%f\n",sa);
  if (sa > EPSILON)//>0 правая тройка
    return LEFT;
  if (sa < -EPSILON)//<0 левая  тройка
    return RIGHT;
  if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0))
    return BEHIND;
  if (length_v(a) < length_v(b))
    return BEYOND;
  if (vectEuquel(p0 , p2))
    return ORIGIN;
  if (vectEuquel(p1 , p2))
    return DESTINATION;

  //if(point_in_vect(p0,p1,p2))
    return BETWEEN;
  // return -1;
}

int edgeType (basetype v, basetype w,basetype a)
{
  switch (classify(v,w,a)) {
    case LEFT:
      return ((v.y<a.y)&&(a.y<=w.y)) ? CROSSING : INESSENTIAL;
    case RIGHT:
      return ((w.y<a.y)&&(a.y<=v.y)) ? CROSSING : /*(point_in_vect(w,v,a)) ? CROSSING :*/ INESSENTIAL;
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
   basetype tmp=comp_vect(org,dest);
  tmp.x=tmp.x*t+org.x;
  tmp.y=tmp.y*t+org.y;

  return tmp;
 //(org + t * (dest - org));
}

void add_point_polig(List * p,basetype t)//добавить точку в полигон
{
     if(p->start!=NULL){Listput(p,t);Listmove(p);}
     else List_init(p,t);
}

int aimsAt(basetype a, basetype b,basetype c,basetype d,int aclass,int crossType)
{
    basetype v1=comp_vect(a,b);
    basetype v2=comp_vect(c,d);
    if(crossType!=COLLINEAR)
    {
       //if(mixed_comp_vect(c,d,a)>0)//a нацелено на вектор cd
       if((v1.x* v2.y)>=(v2.x*v1.y))return (aclass != RIGHT);
       else return (aclass != LEFT);
    }else return (aclass != BEYOND);
}

void advance (List *A, List *R, int inside,  basetype *edge_org,  basetype *edge_dest)
{
    basetype r_point,a_point;

  Listmove(A);
  Listread(R,&r_point);
  Listread(A,&a_point);
  *edge_org=*edge_dest;
  *edge_dest=a_point;
  if(inside && vectEuquel(a_point,r_point)==0 )
    {add_point_polig(R,a_point);}
}

int pointlnConvexPolygon(basetype s , List *p)
{
 basetype edge_org,edge_dest;

if(p->size<3)return FALSE;
print_p(s);
Listread(p,&edge_org);
  for (int i = 0; i < p->size; i++)
  {
    Listmove(p);
    print_p(edge_org);
    Listread(p,&edge_dest);
    print_p(edge_dest);
    if (classify(edge_org,edge_dest,s) == LEFT) return FALSE;
    edge_org=edge_dest;
  }

return TRUE;
}

int crossingPoint(basetype a, basetype b,basetype c,basetype d,basetype *p)
{
double	A1, B1, C1, A2, B2, C2;
	//вычислим коэффициенты прямых Ax+By+C=0
	A1 = b.y - a.y;
	B1 = a.x - b.x;
	C1 = a.x * (a.y - b.y) +a.y * (b.x - a.x);

	A2 = d.y - c.y;
	B2 = c.x - d.x;
	C2 = c.x * (c.y - d.y) +c.y * (d.x -c.x);

	//проверим, параллельны ли они?
	if (numEuquel((A1*B2 - A2*B1),0))
		return COLLINEAR;

	//кооординаты точки пересечения
	p->x = (B1*C2 - B2*C1)/(A1*B2 - A2*B1);
	p->y = (C1*A2 - C2*A1)/(A1*B2 - A2*B1);

	//проверим, находится ли точка пересечения прямых на отрезках
	if (
//      p->x >= min(a.x,b.x) &&
//		p->x <= max(a.x,b.x) &&
//		p->x >= min(c.x,d.x) &&
//		p->x <= max(c.x,d.x) &&
//		p->y >= min(a.y,b.y) &&
//		p->y <= max(a.y,b.y) &&
//		p->y >= min(c.y,d.y) &&
//		p->y <= max(c.y,d.y)  &&
     point_in_plane_vect(a,b,*p) &&
     point_in_plane_vect(c,d,*p)
     )
		return SKEW_CROSS;
	else
		return SKEW_NO_CROSS;

}

List  comp_poligon_intersection(List *P,List * Q)
{
   List T={NULL,NULL,0};
   List *R=&T;
   basetype iPnt,startPnt,r_point;
   basetype p_edge_org,q_edge_org,p_edge_dest,q_edge_dest;
   int inflag=UNKNOWN;
   int phase=1;
   int maxInts=2*(Listcount(Q)+Listcount(P));
   Listread(P,&p_edge_org);
   Listread(Q,&q_edge_org);
   Listmove(P);
   Listmove(Q);
   Listread(P,&p_edge_dest);
   Listread(Q,&q_edge_dest);
   for (int i = 1; (i<=maxInts) /*|| (phase==2)*/; i++)
   {

       print_p(p_edge_org);print_p(p_edge_dest);print_p(q_edge_org);print_p(q_edge_dest);
       int p_class = classify(q_edge_org,q_edge_dest,p_edge_dest);
       int q_class = classify(p_edge_org,p_edge_dest,q_edge_dest);
       int crossType = crossingPoint(p_edge_org,p_edge_dest,q_edge_org,q_edge_dest,&iPnt);
       printf("------%i----\n",crossType );
       if(crossType==SKEW_CROSS)
       { printf("-----1111111111111111111111111111111111111---\n" );print_p(iPnt);
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
                else return T;
                }else return T;
           }
         if (p_class==RIGHT) inflag = P_IS_INSIDE;
         else if (q_class==RIGHT) inflag = Q_IS_INSIDE;
         else inflag = UNKNOWN;
       }
       else if ( (crossType-COLLINEAR) || (p_class != BEHIND) && (q_class != BEHIND) )inflag = UNKNOWN;

       int pAIMSq = aimsAt(p_edge_org,p_edge_dest,q_edge_org,q_edge_dest, p_class, crossType);
       int qAIMSp = aimsAt(q_edge_org,q_edge_dest, p_edge_org,p_edge_dest, q_class, crossType);
       if (pAIMSq && qAIMSp)
        {
           if ( (inflag == Q_IS_INSIDE) || ( (inflag == UNKNOWN)  && (p_class == LEFT)))
        advance(P, R, FALSE,&p_edge_org,&p_edge_dest);
           else
        advance (Q, R, FALSE,&q_edge_org,&q_edge_dest);
        }else if(pAIMSq)advance(P, R, inflag == P_IS_INSIDE,&p_edge_org,&p_edge_dest);
              else if(qAIMSp)advance(Q, R, inflag == Q_IS_INSIDE,&q_edge_org,&q_edge_dest);
                    else  if((inflag == Q_IS_INSIDE) || ((inflag == UNKNOWN) && (p_class == LEFT)))// ||
                            advance ( P , R , FALSE ,&p_edge_org,&p_edge_dest);
                          else advance (Q, R, FALSE,&q_edge_org,&q_edge_dest);

                          printf("----------000\n");
   }

  if(T.size==0)
 {
     if (pointlnConvexPolygon( p_edge_org, Q) )return  *P;
  else if (pointlnConvexPolygon(q_edge_org, P) )return *Q;
 }
  return T;
}

double comp_poligon_square(List *p)
{
    double tmp=0.0;
    basetype t1_p,t2_p;
    Listptrbegin(p);
    do
        {
            Listread(p,&t1_p);
            Listmove(p);
            Listread(p,&t2_p);
            Listmove(p);

            tmp+=(t1_p.x+t2_p.x)*(t1_p.y-t2_p.y);

        }while( !Listbegin(p));

    return tmp/2;
}

double square_poligon(List *p1,List * p2)
{
   // unsigned char  c= planesPos(p1,p2);
    int flag=OXYZ;
    double tmp=0.0,cos_fi=1.0,* arr=NULL;
    List p={NULL,NULL,0};
   if(p1->size>2 && p2->size>2)
{
    basetype pt1,pt2,pt3;
    Listread(p1,&pt1);
    Listmove(p1);
    Listread(p1,&pt2);
    Listread(p2,&pt3);
   arr=comp_PL(pt1,pt2,pt3,&flag);
   if(flag==OX || flag==OY)rewrite_poligon(p1,flag),rewrite_poligon(p2,flag);
   //if(c==SPASEEUQUEL)
        p=comp_poligon_intersection(p1,p2);
   //else if(c!=PERESEC || c!=PARALLEL) err_polig=-1;
   if(p.size>1)tmp=comp_poligon_square(&p);// 1==-OZ   2==-OY  3==-OX
   if(flag==OXYZ)
   {
       double t1,t2;
       basetype tm,tn;
       tn.x=1.0;tn.y=2.0;tn.z=0.0;
       tm.x=arr[0];tm.y=arr[1];tm.z=arr[2];
      cos_fi=tm.x*tn.x+tm.y*tn.y+tm.z*tn.z;
      t1=tm.x*tm.x+tm.y*tm.y+tm.z*tm.z;
      t1=sqrt(t1);
      t2=tn.x*tn.x+tn.y*tn.y+tn.z*tn.z;
      t2=sqrt(t2);
      cos_fi=cos_fi/(t1*t2);
      tmp=tmp/cos_fi;
   }
   free(arr);
}
   printf("square poligon p= %lf",tmp);
   return tmp;
}
double * comp_PL(basetype a, basetype b,basetype c,int * flag)
{
    *flag=OXYZ;
    double * arr=(double*)calloc(4,sizeof(double));
    arr[0]=(b.y-a.y)*(c.z-a.z)-(c.y-a.y)*(b.z-a.z);
    arr[3]=-a.x*arr[0];
    arr[1]=-( (b.x-a.x)*(c.z-a.z)-(c.x-a.x)*(b.z-a.z) );
    arr[3]+=-a.y*arr[1];
    arr[2]=(b.x-a.x)*(c.y-a.y)-(c.y-a.x)*(b.z-a.y);
    arr[3]+=-a.z*arr[2];
    if(numEuquel(arr[0],0.0) && numEuquel(arr[1],0.0))*flag=OZ;//плоскость || XOY
    if(numEuquel(arr[1],0.0) && numEuquel(arr[2],0.0))*flag=OX;//плоскость || ZOY
    if(numEuquel(arr[2],0.0) && numEuquel(arr[0],0.0))*flag=OY;//плоскость || XOY

    return arr;
}
void rotate_3d(basetype *a,int flag)
{
    basetype tmp=*a;
    switch(flag)
    {
        case OX:a->x=tmp.y;a->y=tmp.z;a->z=tmp.x;break;
        case OY:a->y=tmp.z;a->z=tmp.y;break;
        default :;
    }
}
void rewrite_poligon(List * p,int flag)
{
    Listptrbegin(p);
    basetype tmp;
        do
        {
            Listread(p,&tmp);
            rotate_3d(&tmp,flag);
            Listrewrite(p,tmp);
            Listmove(p);

        }while( !Listbegin(p));
}
