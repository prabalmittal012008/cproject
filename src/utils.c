#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
int read_int(){ int x; if(scanf("%d",&x)!=1){ int c; while((c=getchar())!='\n'&&c!=EOF); return 0;} return x; }
float read_float(){ float f; if(scanf("%f",&f)!=1){ int c; while((c=getchar())!='\n'&&c!=EOF); return 0.0;} return f; }
void read_string(char *buf,int n){
    int c; while((c=getchar())!='\n'&&c!=EOF);
    fgets(buf,n,stdin);
    size_t len=strlen(buf);
    if(len&&buf[len-1]=='\n') buf[len-1]='\0';
}
