#ifndef POLIGON_H_INCLUDED
#define POLIGON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"LIST_K.h"
#include"fileio.h"

#include <math.h>
#define EPSILON 0.001
#define TRUE
#define FALSE 0

extern int err_polig;
enum {LEFT,  RIGHT,  BEYOND,  BEHIND, BETWEEN, ORIGIN, DESTINATION};
//    СЛЕВА, СПРАВА, ВПЕРЕДИ, ПОЗАДИ, МЕЖДУ,   НАЧАЛО, КОНЕЦ

//typedef enum position {PARALLEL=0,PERESEC=1,SPASEEUQUEL=2,PERPENDICULAR=3}pos;

enum { COLLINEAR=66, PARALLEL, SKEW, SKEW_CROSS, SKEW_NO_CROSS };

enum { INSIDE=32, OUTSIDE, BOUNDARY };         // положение точки
//     ВНУТРИ, ВНЕ,     НА ГРАНИЦЕ
enum { TOUCHING=39, CROSSING, INESSENTIAL };   // положение ребра
//     КАСАТЕЛbНОЕ, ПЕРЕСЕКАЮЩЕЕ, НЕСУЩЕСТВЕННОЕ

enum{UNKNOWN, P_IS_INSIDE, Q_IS_INSIDE};

basetype comp_vect(basetype a,basetype b);//вычисление вектора
basetype vect_norm(basetype a,basetype b);//скалярное произведение
int numEuquel(double a,double b);//числа равны
int vectEuquel(basetype a,basetype b);//векторы равны
double mixed_comp_vect(basetype a, basetype b,basetype c);//смешаное произведение
double min(double x, double y);
double max(double x, double y);
int point_in_vect(basetype p0, basetype p1,basetype p2);//точка лежит на векторе
int point_in_plane_vect(basetype p0, basetype p1,basetype p2);//проекция точки лежит на вектре
int classify(basetype p0, basetype p1,basetype p2);//где точка p2 относительно  отрезка (p0,p1)
int edgeType (basetype v, basetype w,basetype a);//тип ребра
int sign(double a);//знак + или нет
double dProduct(basetype a, basetype b);//скалярное троизведение
basetype point(basetype org,basetype dest,double t);//вычесление точки по параметру  t
int intersect(basetype a, basetype b,basetype c,basetype d, basetype *p);//возвращает положение ребер и если возможно, бточку пересечения
void print_p(basetype a);//вывод точки
void add_point_polig(List *p,basetype t);//добавить точку в полигон
int search_point_polig(List * p,basetype t);//точка в ролигоне
int aimsAt(basetype a, basetype b,basetype c,basetype d,int aclass,int crossType);
void advance (List *A, List *R, int inside);
int pointlnConvexPolygon (basetype s , List *p);

void square_poligon(List *p1,List * p2);
List * comp_poligon_intersection(List *p1,List * p2);
double comp_poligon_square(List *p,int flag);


#endif // POLIGON_H_INCLUDED
