#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char line[50][50],lhs[50],rhs[50],used[50][50],result[50][50];
    int n,i,j,count=0,flag,rcount=0;
    printf("enter number of expressions:");
    scanf("%d",&n);
    printf("enter expressions:");
    for(i=0;i<n;i++){
        scanf("%s",line[i]);
    }
    printf("after optimization\n");
    for(i=n-1;i>=0;i--){
        strcpy(lhs,strtok(line[i],"="));
        strcpy(rhs,strtok(NULL,"="));
        flag=0;
        for(j=0;j<count;j++){
            if(strcmp(lhs,used[j])==0){
                flag=1;
                break;
            }
        }
        if(flag ||i==n-1){
            sprintf(result[rcount++],"%s=%s\n",lhs,rhs);
            for(j=0;rhs[j]!='\0';j++){
                if(isalpha(rhs[j])){
                    used[count][0]=rhs[j];
                    used[count][1]='\0';
                    count++;
            }}
        }
    }
    for(i=0;i<rcount;i++){
        printf("%s",result[i]);
    }
}