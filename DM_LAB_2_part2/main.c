#include "sv_otn.h"
#include "oper_otn.h"

array reflexive_closure(array a,int n);
array symmetric_closure(array a,int n);
array transitive_closure(array a,int n);
array transitive_closure_degree_combining_algorithm(array a,int n);
array transitive_closure_advanced_d_c_a(array a,int n);
array transitive_closure_walshall_algorithm(array a,int n);
array transitive_closure_advanced_walshall_algorithm(array a,int n);
void clone_arr_a_in_b(array a,array b,int n);
void single_matr(array a,int n);
array exponent_A(array ,unsigned ,int );
void clone_arr_a_in_b(array a,array b, int n)
{
    for(int i=0;i<n-1;++i)
      for(int j=0;j<n-1;++j)
        b[i][j]=a[i][j];
}
void single_matr(array a,int n)
{
    for(int i=0;i<n-1;++i)
      for(int j=0;j<n-1;++j)
        a[i][j]=FALSE;
    for(int i=0;i<n-1;++i)  a[i][i]=TRUE;
}
array reflexive_closure(array a,int n)
{
    array  c=create_matr(n);
    clone_arr_a_in_b(a,c,n);
    for(int i=0;i<n-1;++i)  if(!c[i][i])c[i][i]=TRUE;  // or 2 var   single_matr(c,n);array d=A_or_B(a,c,n,n);return d;
    return c;
}

array symmetric_closure(array a,int n)
{
    array  c,tmp=obr_A(a,n);
    c=A_or_B(a,tmp,n,n);
    del_matr(tmp,n);
    return c;
}

array transitive_closure(array a,int n)
{
    array c_tr=NULL,c3;
    clone_arr_a_in_b(a,c_tr,n);
    array c2=exponent_A(c_tr,n,2);
    while(!Ainc_eqB(c2,c_tr,n,n))
    {
        c3=c_tr;
        c_tr=A_or_B(c_tr,c2,n,n);
        del_matr(c3,n);
        del_matr(c2,n);
        c2=exponent_A(c_tr,n,2);
    }

    return  c_tr;
}

array transitive_closure_degree_combining_algorithm(array a,int n)
{
    array c_tr=a,tmp,c;
    for(int i=2;i<=n;++i)
    {
        tmp=exponent_A(a,n,i);
        c=c_tr;
        c_tr=A_or_B(c_tr,tmp,n,n);
        del_matr(c,n);
        del_matr(tmp,n);
    }

    return  c_tr;
}


array transitive_closure_advanced_d_c_a(array a,int n)
{
     array c_tr=create_matr(n),tmp;
     single_matr(c_tr,n);
     tmp=A_or_B(c_tr,a,n,n);
     del_matr(c_tr,n);
     c_tr=exponent_A(tmp,n,n-2);
     del_matr(tmp,n);
     tmp=A_comp_B(a,c_tr,n,n);
     del_matr(c_tr,n);
     return tmp;
}
array transitive_closure_walshall_algorithm(array a,int n)
{
    array  c=create_matr(n);
    clone_arr_a_in_b(a,c,n);
    for(int z=0;z<n-1;++z)
     for(int i=0;i<n-1;++i)
      for(int j=0;j<n-1;++j)
        c[i][j]|=c[i][z] && c[z][j];
 return c;
}

array transitive_closure_advanced_walshall_algorithm(array a,int n)
{
    array  c=create_matr(n);
    clone_arr_a_in_b(a,c,n);
    for(int z=0;z<n-1;++z)
     for(int i=0;i<n-1;++i)
      for(int j=0;j<n-1;++j)
        if(c[i][z]) c[i][j]= c[z][j];
 return c;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
