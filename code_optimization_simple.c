#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char line[50],lhs[50],rhs[50],op1[20],op2[20],op;
    int i;
    printf("enter expression:");
    scanf("%s",line);
    strcpy(lhs,strtok(line,"="));
    strcpy(rhs,strtok(NULL,"="));
    if(sscanf(rhs,"%[^+-*/]%c%s",op1,&op,op2)==3){
        printf("MOV R1,%s\n",op1);
        printf("MOV R2,%s\n",op2);
        switch(op){
            case '+':printf("ADD R1,R2\n");break;
            case '-':printf("SUB R1,R2\n");break;
            case '*':printf("MUL R1,R2\n");break;
            case '/':printf("DIV R1,R2\n");break;
        }
        printf("MOV %s,R1\n",lhs);
    }
    else{
        printf("MOV %s,%s\n",lhs,rhs);
    }
}
