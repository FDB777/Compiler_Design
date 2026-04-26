#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char line[50][50],lhs[50],rhs[50],op1[20],op2[20],op;
    int const1,const2,result,n,i,j;
    printf("enter number:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",line[i]);
    }
    for(i=0;i<n;i++){
        strcpy(lhs,strtok(line[i],"="));
        strcpy(rhs,strtok(NULL,"="));
        if(sscanf(rhs,"%[^+-*/]%c%s",op1,&op,op2)==3){
            const1=1;const2=1;
            for(j=0;op1[j]!='\0';j++){
                if(!isdigit(op1[j])){
                    const1=0;
                    break;
                }
            }
            for(j=0;op2[j]!='\0';j++){
                if(!isdigit(op2[j])){
                    const2=0;
                    break;
                }
            }
            if(const1 && const2){
                int v1=atoi(op1);
                int v2=atoi(op2);
                switch(op){
                    case '+':result=v1+v2;break;
                    case '-':result=v1-v2;break;
                    case '*':result=v1*v2;break;
                    case '/':result=v1/v2;break;}
                printf("%s=%d\n",lhs,result);
            }
            else
                printf("%s=%s%c%s\n",lhs,op1,op,op2);
        }
        else
            printf("%s=%s\n",lhs,rhs);
    }
}