#include"fileio.h"


//char *fget_word(FILE * f)
//{
//    char * s=(char *)calloc(70,sizeof(char));
//    fscanf(f,"%[À-ß][à-ÿ]70s",s);
//    for(int i=0;i<70;i++)if(s[i]=='\n' || s[i]=='\0'){s[i]='\0';realloc(s,i+1);return s;}
//    realloc(s,70);
//    s[70]='\0';
//    return s;
//}

int is_bikv(int a)
{
    if ( ('à'<=a && a<='ÿ') || ('À'<=a && a<= 'ß') ) return 1;
      else if(a=='\n' || a=='\0')return 0;
return -1;
}

char * fget_is_bikv_word_a_ya(FILE * f)
{
    int i=0,c,j=0;
    do
    {
         c=fgetc(f);
         j=is_bikv(c);
    }while( c!=EOF && j!=1 );

if(c==EOF){return NULL;puts("END\n");}
char * s=(char *)calloc(70,sizeof(char));
if(s==NULL){return NULL;puts("ERRORS\n");}
s[i++]=c;
    do
       {
           c=fgetc(f);
           j=is_bikv(c);
           if(j==1)s[i++]=c;
           else if(j==0 || c==EOF){realloc(s,i+1);s[i]='\0';return s;}
       }while(i<69);
    s[i]='\0';return s;

}



char *fget_word(FILE * f)
{
    char * s=(char *)calloc(70,sizeof(char));
    fscanf(f,"%70s",s);
    for(int i=0;i<70;i++)if(s[i]=='\n' || s[i]=='\0'){s[i]='\0';realloc(s,i+1);return s;}
    realloc(s,70);
    s[70]='\0';
    return s;
}

int fscan_poligon(FILE *f,List *p)
{

    char *s=fget_word(f),*ok;
    List_init(p,&s);

    while(!feof(f))
    {
        s=fget_word(f);

        //for(unsigned long r=0;r<100000000;++r);
        Listput(p,&s);
        Listmove(p);
   // Listread(p,&ok);
  // printf("%s \n",ok);

    }

return 0;
}

int fprint_poligon(FILE *f,List *p)
{


    char *ok=NULL;
    Listptrbegin(p);
    long unsigned  n=Listcount(p);
    fprintf(f,"%lu \n",n);
    do
    {
        Listread(p,&ok);
        Listmove(p);
        if(ok!=NULL){fprintf(f,"%s \n",ok); ok=NULL;//       printf("%.70s \n",s);
        }

    }while(!Listbegin(p));

return 0;
}

int sign(int c)
{
    if(c>0)return 1;
    else if(c==0)return 0;
          else return -1;
}

int search_word(List*p,char *s)
{
    char * st,c=0;
    Elptr pn=p->start,pl;
    pl=pn;
    Listptrbegin(p);
    Listread(p,&st);
    Listmove(p);
    pl=p->ptr;
    Listread(p,&st);
    Listmove(p);
    while(!Listbegin(p))
{
    c=sign(strcmp(s,st));
        switch(c){
    case 1:pn=pl;Listread(p,&st);pl=p->ptr;Listmove(p);break;
    case 0:return 1;
    case -1:p->ptr=pn;return 0;
    default:puts("ERROR1");return -100;
    }
}
    p->ptr=pn;return 0;
}


int f_add_poligon(FILE *f,List *p)
{
    char tmp=0;
    char *s;
    if(Listemply(p))fscan_poligon(f,p);
    else
    while(!feof(f))
    {
        s=fget_is_bikv_word_a_ya(f);
        if(s!=NULL)
        {
        tmp=search_word(p,s);
        if(tmp==0){ Listput(p,&s);Listmove(p);}
        else if(tmp==1)++p->ptr->coun;
              else puts("ERR");
        }
    }
fclose(f);
return 0;
}
