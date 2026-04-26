#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char line[50][50],lhs[50],rhs[50],op1[20],op2[20],op,var[50][50],val[50][50];
    int n,i,j,count=0;
    printf("enter number of expressions:");
    scanf("%d",&n);
    printf("enter expressions:");
    for(i=0;i<n;i++){
        scanf("%s",line[i]);
    }
    for(i=0;i<n;i++){
        strcpy(lhs,strtok(line[i],"="));
        strcpy(rhs,strtok(NULL,"="));
        if(sscanf(rhs,"%s",op1)==1 && sscanf(rhs,"%[^+-*/]%c%s",op1,&op,op2)!=3){
            for(j=0;j<count;j++){
                if(strcmp(op1,var[j])==0){
                    strcpy(op1,val[j]);
                    break;
                }
            }
            printf("%s=%s\n",lhs,op1);
            strcpy(var[count],lhs);
            strcpy(val[count],op1);
            count++;
        }
        else if(sscanf(rhs,"%[^+-*/]%c%s",op1,&op,op2)==3){
            for(j=0;j<count;j++){
                if(strcmp(op1,var[j])==0){
                    strcpy(op1,val[j]);
                    break;
                }
            }
            for(j=0;j<count;j++){
                if(strcmp(op2,var[j])==0){
                    strcpy(op2,val[j]);
                    break;
                }
            }
            printf("%s=%s%c%s\n",lhs,op1,op,op2);
        }
        else
            printf("%s=%s",lhs,rhs);
    }
}