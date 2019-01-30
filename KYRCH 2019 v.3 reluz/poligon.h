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

#define M 4 //������ ������� ��� ��-�� ���������
extern int err_polig;
enum {OX=100,OY,OZ,OXYZ};
enum {LEFT,  RIGHT,  BEYOND,  BEHIND, BETWEEN, ORIGIN, DESTINATION};
//    �����, ������, �������, ������, �����,   ������, �����
enum { COLLINEAR=66, PARALLEL, SKEW, SKEW_CROSS, SKEW_NO_CROSS };
enum{UNKNOWN=20, P_IS_INSIDE, Q_IS_INSIDE};

basetype comp_vect(basetype a,basetype b);//���������� �������
double vect_norm(basetype a,basetype b);//��������� ������������
int numEuquel(double a,double b);//����� �����
int vectEuquel(basetype a,basetype b);//������� �����
double min(double x, double y);
double max(double x, double y);
int point_in_plane_vect(basetype p0, basetype p1,basetype p2);//�������� ����� ����� �� ������

int classify(basetype p0, basetype p1,basetype p2);//��� ����� p2 ������������  ������� (p0,p1)

double dProduct(basetype a, basetype b);//��������� ������������
basetype point(basetype org,basetype dest,double t);//���������� ����� �� ���������  t

void print_p(basetype a);//����� �����+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void add_point_polig(List *p,basetype t);//�������� ����� � �������

int aimsAt(basetype a, basetype b,basetype c,basetype d,int aclass,int crossType);//�������   TRUE ���� ����� ab �������� �� cd
void advance (List *A, List *R, int inside,basetype *edge_org,  basetype *edge_dest);

int pointlnConvexPolygon (basetype s , List *p);// �������   TRUE ���� ����� s ������ ��������
double length_v (basetype a);//������ �������
int crossingPoint(basetype ea, basetype eb,basetype fc,basetype fd,basetype *p);
//���������� ��������� ����� ������������ ���� ����� � ���� ��������,����� �����������
double * comp_PL(basetype ea, basetype eb,basetype fc,int * flag);
//���������� ��������� �� ������ [4] � ��� ��������� ��������� ���������
// � ��������� flag ����� �������� ��� ����������� ��� ���������
int points_in_PL(double *a,List * p);//�. ���� ��������� �
void rotate_3d(basetype * a,int flag);//������ ���������� �������
void rewrite_poligon(List * p,int flag);//������ ���������� ������� �� ���� ��������

double square_poligon(List *p1,List * p2);//����� ����������� ���������
List  comp_poligon_intersection(List *p1,List * p2);//���������� �������� �����������
double comp_poligon_square(List *p);//���������� ������� ��������

#endif // POLIGON_H_INCLUDED
