#ifndef POLIGON_H_INCLUDED
#define POLIGON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"LIST_K.h"
#include"fileio.h"

#include <math.h>
#define EPSILON 0.001
#define TRUE 1
#define FALSE 0

#define M 4 //расмер массива для ур-ия плоскости
extern int err_polig;
enum {OX=100,OY,OZ,OXYZ};
enum {LEFT,  RIGHT,  BEYOND,  BEHIND, BETWEEN, ORIGIN, DESTINATION};
//    СЛЕВА, СПРАВА, ВПЕРЕДИ, ПОЗАДИ, МЕЖДУ,   НАЧАЛО, КОНЕЦ
enum { COLLINEAR=66, PARALLEL, SKEW, SKEW_CROSS, SKEW_NO_CROSS };
enum{UNKNOWN=20, P_IS_INSIDE, Q_IS_INSIDE};

basetype comp_vect(basetype a,basetype b);//вычисление вектора
double vect_norm(basetype a,basetype b);//скалярное произведение
int numEuquel(double a,double b);//числа равны
int vectEuquel(basetype a,basetype b);//векторы равны
double min(double x, double y);
double max(double x, double y);
int point_in_plane_vect(basetype p0, basetype p1,basetype p2);//проекция точки лежит на вектре

int classify(basetype p0, basetype p1,basetype p2);//где точка p2 относительно  отрезка (p0,p1)

double dProduct(basetype a, basetype b);//скалярное троизведение
basetype point(basetype org,basetype dest,double t);//вычесление точки по параметру  t

void print_p(basetype a);//вывод точки+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void add_point_polig(List *p,basetype t);//добавить точку в полигон

int aimsAt(basetype a, basetype b,basetype c,basetype d,int aclass,int crossType);//возврат   TRUE если ребро ab нацелено на cd
void advance (List *A, List *R, int inside,basetype *edge_org,  basetype *edge_dest);

int pointlnConvexPolygon (basetype s , List *p);// возврат   TRUE если точка s внутри полигона
double length_v (basetype a);//длинна вектора
int crossingPoint(basetype ea, basetype eb,basetype fc,basetype fd,basetype *p);
//возвращает положение ребер относительно друг друга и если возможно,точку пересечения
double * comp_PL(basetype ea, basetype eb,basetype fc,int * flag);
//возвращает указатель на массив [4] в кот находится уравнение плоскости
// в первенную flag возвр значение оси паралельной оси координат
int points_in_PL(double *a,List * p);//т. прин плоскости а
void rotate_3d(basetype * a,int flag);//меняет координаты местами
void rewrite_poligon(List * p,int flag);//меняет координаты местами во всем полигоне

double square_poligon(List *p1,List * p2);//поиск пересечения полигонов
List  comp_poligon_intersection(List *p1,List * p2);//вычисление полигона пересечения
double comp_poligon_square(List *p);//вычисление площади полигона

#endif // POLIGON_H_INCLUDED
