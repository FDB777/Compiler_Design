#include <stdio.h>
#include <ctype.h>
void main(){
    char infix[100],postfix[100],stack[100],tacstack[100][10],op1[10],op2[10];
    int i,j=0,top=-1,ttop=-1,temp=1;
    printf("enter expression:");
    scanf("%s",infix);
    for(i=0;infix[i];i++){
        char ch=infix[i];
        if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch=='(')
            stack[++top]=ch;
        else if(ch==')'){
            while(stack[top]!='(')
                postfix[j++]=stack[top--];
            top--;
        }
        else{
            int p;
            if(ch=='+'|| ch=='-')p=1;
            else p=2;
            while(top!=-1 && ((stack[top]=='*'|| stack[top]=='/')||((stack[top]=='+'|| stack[top]=='-')&& p==1))){
                postfix[j++]=stack[top--];
            }
            stack[++top]=ch;
        }
    }
    while(top!=-1)
        postfix[j++]=stack[top--];
    postfix[j]='\0';
    printf("\nThree address code:\n");
    for(i=0;postfix[i];i++){
        char ch=postfix[i];
        if(isalnum(ch)){
            tacstack[++ttop][0]=ch;
            tacstack[ttop][1]='\0';}
        else{
            sprintf(op2,"%s",tacstack[ttop--]);
            sprintf(op1,"%s",tacstack[ttop--]);
            if(ch=='='){
                printf("%s=%s\n",op1,op2);
                sprintf(tacstack[++ttop],"%s",op1);
            }
            else{
                printf("t%d=%s%c%s\n",temp,op1,ch,op2);
                sprintf(tacstack[++ttop],"t%d",temp);
                temp++;
            }
        }
    }
}