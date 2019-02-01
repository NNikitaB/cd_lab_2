#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include"LIST_K.h"
#include<string.h>
#include <unistd.h>
#include <io.h>
int fprint_poligon(FILE *f,List *p);
int fscan_poligon(FILE *f ,List *p);
int search_word(List*p,char *s);
int f_add_poligon(FILE *f,List *p);
char *fget_word_a_ya(FILE * f);
int is_bikv(int a);
char * fget_is_bikv_word_a_ya(FILE * f);
#endif // FILEIO_H_INCLUDED
