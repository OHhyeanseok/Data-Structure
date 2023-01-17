#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int max;
	int ptr;
	int *stk;
}IntStack;
int Initialize(IntStack *s, int max){
	s->ptr=0;
	if((s->stk = (int*)calloc(max,sizeof(int)))==NULL){
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 1;
}
int Push(IntStack *s,int x){
if(s->ptr >= s->max) return -1;
s->stk[s->ptr++]=x;
return 0;
}
int Pop(IntStack *s){
	if(s->ptr<=0) return -1;
	s->stk[--s->ptr];
}
int Peek(IntStack *s){
	if(s->ptr<=0) return -1;
	return s->stk[s->ptr-1];
}
int IsEmpty(const IntStack *s){return s->ptr<=0;}
void Terminate(IntStack *s){if(s->stk!=NULL)free(s->stk);
s->max=s->ptr=0;
}
 
int main(){
	int max=0;
	int count=1;
	IntStack A;
	int num;
	scanf("%d",&num);
	Initialize(&A,num);
	while(num-->0){
		int variable;
		scanf("%d",&variable);
		Push(&A,variable);
	}
	max=Peek(&A);
	Pop(&A);		
	while(1){	
	if(max>=Peek(&A)){
		Pop(&A);
	}
	else if(max < Peek(&A)){
		max=Peek(&A);
		Pop(&A);
		count++;
	}
	if(IsEmpty(&A)) break;
}
	printf("%d",count);
	
	return 0;
}

