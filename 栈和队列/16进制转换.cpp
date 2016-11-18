#include<stdio.h>
#include<stdlib.h>
const int maxSizeStack = 1000;
const int maxSizeQueue = 1000;
typedef struct stack{
	int *base;
	int *top;
	int stackSize;

}stack;
void initStack(stack *s){
	s->base = (int*)malloc(sizeof(int)*maxSizeStack);
    s->top = s->base;
    s->stackSize = 0;
	return;
}

int push(stack *s,int ele){
	
	*s->top++ = ele;
    if(s->stackSize>= maxSizeStack) return 0;
    s->stackSize++;
	return 1;
}
int* pop(stack *s){
	
    int *temp = s->top-1;
    if(s->top == s->base) return NULL;
	s->top--;
    s->stackSize--;
	return temp;
}
int main(){
    int sum;
    int num;
    int i;
    char ch;
    stack *s;
    int *tempInt;
    char result;
    while(1){
        scanf("%d",&sum);
        if(sum==0){
            break;
        }
        for(i=0; i<sum; i++){
            s = (stack*)malloc(sizeof(stack));
            initStack(s);
            scanf("%d",&num);
            while(num){
                push(s,num%16);
                num/=16;
            }
            while((tempInt=pop(s))!=NULL){
                if(*tempInt<10){
                    printf("%d",*tempInt);
                    continue;
                }
                switch(*tempInt){
                    case 10:
                        result = 'A';
                        break;
                    case 11:
                        result = 'B';
                        break;
                    case 12:
                        result = 'C';
                        break;
                    case 13:
                        result = 'D';
                        break;
                    case 14:
                        result = 'E';
                        break;
                    case 15:
                        result = 'F';
                        break;
                    default:
                        printf("");
                }
                printf("%c",result);
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}