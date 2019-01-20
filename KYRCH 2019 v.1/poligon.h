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
//    �����, ������, �������, ������, �����,   ������, �����

//typedef enum position {PARALLEL=0,PERESEC=1,SPASEEUQUEL=2,PERPENDICULAR=3}pos;

enum { COLLINEAR=66, PARALLEL, SKEW, SKEW_CROSS, SKEW_NO_CROSS };

enum { INSIDE=32, OUTSIDE, BOUNDARY };         // ��������� �����
//     ������, ���,     �� �������
enum { TOUCHING=39, CROSSING, INESSENTIAL };   // ��������� �����
//     �������b���, ������������, ��������������

enum{UNKNOWN, P_IS_INSIDE, Q_IS_INSIDE};

basetype comp_vect(basetype a,basetype b);//���������� �������
basetype vect_norm(basetype a,basetype b);//��������� ������������
int numEuquel(double a,double b);//����� �����
int vectEuquel(basetype a,basetype b);//������� �����
double mixed_comp_vect(basetype a, basetype b,basetype c);//�������� ������������
double min(double x, double y);
double max(double x, double y);
int point_in_vect(basetype p0, basetype p1,basetype p2);//����� ����� �� �������
int point_in_plane_vect(basetype p0, basetype p1,basetype p2);//�������� ����� ����� �� ������
int classify(basetype p0, basetype p1,basetype p2);//��� ����� p2 ������������  ������� (p0,p1)
int edgeType (basetype v, basetype w,basetype a);//��� �����
int sign(double a);//���� + ��� ���
double dProduct(basetype a, basetype b);//��������� ������������
basetype point(basetype org,basetype dest,double t);//���������� ����� �� ���������  t
int intersect(basetype a, basetype b,basetype c,basetype d, basetype *p);//���������� ��������� ����� � ���� ��������, ������ �����������
void print_p(basetype a);//����� �����
void add_point_polig(List *p,basetype t);//�������� ����� � �������
int search_point_polig(List * p,basetype t);//����� � ��������
int aimsAt(basetype a, basetype b,basetype c,basetype d,int aclass,int crossType);
void advance (List *A, List *R, int inside);
int pointlnConvexPolygon (basetype s , List *p);

void square_poligon(List *p1,List * p2);
List * comp_poligon_intersection(List *p1,List * p2);
double comp_poligon_square(List *p,int flag);


#endif // POLIGON_H_INCLUDED
