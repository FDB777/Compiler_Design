#include <stdio.h>
#include <string.h>
char stack[50]="$";
char lhs[50][50],rhs[50][50],input[50];
int top=0,n;
int reduce(char action[]){
    int i,pos,len;
    for(i=0;i<n;i++){
        len=strlen(rhs[i]);
        if(top>=len){
            pos=top-len+1;
            if(strncmp(&stack[pos],rhs[i],len)==0){
                stack[pos]=lhs[i][0];
                stack[pos+1]='\0';
                top=pos;
                sprintf(action,"reduce %s->%s",lhs[i],rhs[i]);
                return 1;
            }
        }
    }
    return 0;
}
void main(){
    int i,ip=0;
    char action[50];
    printf("enter number of productions:");
    scanf("%d",&n);
    printf("enter productions:");
    for(i=0;i<n;i++){
        scanf("%s",lhs[i]);
        strtok(lhs[i],"->");
        strcpy(rhs[i],strtok(NULL,"->"));
    }
    printf("enter input string:");
    scanf("%s",input);
    printf("\nSTACK\tINPUT\tACTION\n");
    while(1){
        if(input[ip]!='\0'){
            stack[++top]=input[ip++];
            stack[top+1]='\0';
            strcpy(action,"SHIFT");
            printf("%s\t%s\t%s\n",stack,&input[ip],action);
        }
        while(reduce(action)){
            printf("%s\t%s\t%s\n",stack,&input[ip],action);
        }
        if(top==1 && stack[0]=='$' && stack[1]==lhs[0][0] && strcmp(&input[ip],"$")==0){
            printf("%s\t%s\tACCEPTED\n",stack,&input[ip]);
            break;
        }
        if(input[ip]=='\0'){
            printf("%s\t%s\tREJECTED\n",stack,&input[ip]);
            break;
        }
    }
}