#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
struct stk
{
char stack[MAX];
int top;
}ptr;
void int__stkk(struct stk *s)
{
s->top=-1;
}
void push(struct stk *s, char sym)
{
s->top++;
s->stack[s->top]=sym;
}
int pop(struct stk *s)
{
return(s->stack[s->top--]);
}
int stacktop(struct stk *s)
{
return(s->stack[s->top]);
}
void convert(char infix[MAX])
{
char postfix [MAX];
char sym,stackt;
int i,j=0;
for(i=0;infix[i]!=0;i++)
{
sym=infix[i];
if(isalpha(sym))
postfix[j++]=sym;
else
{
switch(sym)
{
case '(': push(&ptr,sym);
	  break;
case '$': while((stackt=ptr.stack[ptr.top])=='$')
	  postfix[j++]=pop(&ptr);
	  push(&ptr,sym);
	  break;
case '*':
case '/': while((stackt=ptr.stack[ptr.top])=='$'|| stackt=='*'||stackt=='/')
	  postfix[j++]=pop(&ptr);
	  push(&ptr,sym);
	  break;
case '+':
case '-': while((stackt=ptr.stack[ptr.top])=='$'|| stackt=='*'||stackt=='/'|| stackt=='+'|| stackt=='-')
	  postfix[j++]=pop(&ptr);
	  push(&ptr,sym);
	  break;
case ')': while((stackt=ptr.stack[ptr.top])!='(')
	  postfix[j++]=pop(&ptr);
	  pop(&ptr);
	  break;
default: printf("Invalid");
	  exit(0);
}
}
}
while(ptr.top>-1)
postfix[j++]=pop(&ptr);
postfix[j++]='\0';
printf("postfix is %s \n",postfix);
}
void main()
{
char infix[MAX];
printf("Enter the infix expression:");
scanf("%s",infix);
convert(infix);
}
