#include<stdio.h>
#include<stdlib.h>
const int maxSizeStack = 2;
const int maxSizeQueue = 1000;
const int INCREMENT = 10;
const double PER = 20.5;
typedef struct bus{
	char status;
	int number,inTime,outTime;
}bus,*busP;
typedef bus element;
typedef struct stack{
	element *base;
	element *top;
	int stackSize;

}stack;
typedef struct queue{
    element *outBuses;
	int front;
    int rear;
}queue;
void initStack(stack *s){
	s->base = (element*)malloc(sizeof(element)*maxSizeStack);
    s->top = s->base;
    s->stackSize = 0;
	return;
}

int push(stack *s,element ele,int flag){
	if(s->stackSize>= maxSizeStack) return 0;
	if(flag ==1){
		printf("���ƺ�Ϊ%d�ĳ���ͣ�ڳ����%d��λ����\n",ele.number,s->stackSize+1);
	}
	*s->top++ = ele;
    s->stackSize++;
	return 1;
}
element* pop(stack *s,int flag,int outTime){
	if(s->top == s->base) return NULL;
	if(flag == 1){
		printf("���ƺ���Ϊ %d �ĳ����ڳ���ͣ���� %d��Сʱ����Ҫ֧�� %.2lfԪ����\n",(s->top-1)->number,outTime-(s->top-1)->inTime,(outTime-(s->top-1)->inTime)*PER);
	}
    element *temp = s->top-1;
	s->top--;
    s->stackSize--;
	return temp;
}
void initQueue(queue *q){
    q->outBuses = (element*)malloc(sizeof(element)*maxSizeQueue);
    q->front = q->rear = 0;
}
void enQueue(queue *q,element ele){
    if((q->rear+1)%maxSizeQueue == q->front) return;
	printf("ͣ����λ�ò��������ƺ���Ϊ%d�ĳ���ͣ�ڱ����%d��λ��\n",ele.number,q->rear+1);
    *(q->outBuses+q->rear) = ele;
    q->rear = (q->rear+1)%maxSizeQueue;
	return;
}
element* deQueue(queue *q){
	if(q->front == q->rear) return NULL;
    element *temp = q->outBuses+q->front;
    q->front = (q->front+1)%maxSizeQueue;
    return temp;
}
int main(){
	char status;
	int number;
	int time;
	stack *buses = (stack*)malloc(sizeof(stack));
	stack *tempStack = (stack*)malloc(sizeof(stack));
	queue *outBuses = (queue*)malloc(sizeof(queue));
	initStack(buses);
	initStack(tempStack);
	initQueue(outBuses);
	printf("�����복��������Ϣ,�磨A,1,2��,E��ʾ�������\n");
	while(true){
		scanf("%c%d%d",&status,&number,&time);
		if(status == 'E') {
			printf("�������\n");
			break;
		}
		if(status == 'A'){
			element *pnew = (element*)malloc(sizeof(element));
			pnew->status = status;
			pnew->number = number;
			pnew->inTime = time;
			if(buses->stackSize < maxSizeStack ){
				pnew->inTime = time;
				push(buses,*pnew,1);
			} else {
				enQueue(outBuses,*pnew);
			}
		} else if(status == 'D'){
			while((buses->top-1)->number != number){
				push(tempStack,*(pop(buses,2,-1)),2);
			}
			pop(buses,1,time);
			element *temp;
			while((temp = pop(tempStack,3,-1))!=NULL){
				push(buses,*temp,1);
			}
			if(buses->stackSize < maxSizeStack && ((temp = deQueue(outBuses))!=NULL)){
				temp->inTime = time;
				push(buses,*temp,1);
			}
		}
	}
	system("pause");
	return 0;
}