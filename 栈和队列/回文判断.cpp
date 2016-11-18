#include<stdio.h>
#include<stdlib.h>
const int maxSizeStack = 1000;
const int maxSizeQueue = 1000;
typedef struct stack{
	char *base;
	char *top;
	int stackSize;

}stack;
typedef struct queue{
    char *outBuses;
	int front;
    int rear;
}queue;
void initStack(stack *s){
	s->base = (char*)malloc(sizeof(char)*maxSizeStack);
    s->top = s->base;
    s->stackSize = 0;
	return;
}

int push(stack *s,char ele){
	
	*s->top++ = ele;
    if(s->stackSize>= maxSizeStack) return 0;
    s->stackSize++;
	return 1;
}
char* pop(stack *s){
	
    char *temp = s->top-1;
    if(s->top == s->base) return NULL;
	s->top--;
    s->stackSize--;
	return temp;
}
void initQueue(queue *q){
    q->outBuses = (char*)malloc(sizeof(char)*maxSizeQueue);
    q->front = q->rear = 0;
}
void enQueue(queue *q,char ele){
    *(q->outBuses+q->rear) = ele;
    q->rear = (q->rear+1)%maxSizeQueue;
	return;
}
char* deQueue(queue *q){
    char *temp = q->outBuses+q->front;
	if(q->front == q->rear) return NULL;
    
    q->front = (q->front+1)%maxSizeQueue;
    return temp;
}
int judge(stack*s,queue*q){
    int flag = 1;
    char *tempS = (char*)malloc(sizeof(char));
    char *tempQ = (char*)malloc(sizeof(char));
    while((tempS=pop(s))!=NULL&&(tempQ=deQueue(q))!=NULL){
        if(*tempS!=*tempQ){
            flag = 0;
            break;
        }
    }
    return flag;
}
int main(){
    int sum;
    int i;
    char ch;
    stack *s;
    queue *q;
    while(1){
        scanf("%d",&sum);
        getchar();
        if(sum==0){
            break;
        }
        for(i=0; i<sum; i++){
            s = (stack*)malloc(sizeof(stack));
            q = (queue*)malloc(sizeof(queue));
            initStack(s);
            initQueue(q);
            while(1){
                ch = getchar();
                if(ch == '\n'){
                    break;
                }
                push(s,ch);
                enQueue(q,ch);
            }
            if(judge(s,q)){
                printf("Case #%d: Yes",i+1);
                if(i+1!=sum){
                    printf("\n");
                }
            }else {
                printf("Case #%d: No\n",i+1);
            }
        }
    }
    system("pause");
    return 0;
}