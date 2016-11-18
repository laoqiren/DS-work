#include<stdio.h>    
#include<stdlib.h> 
#include<string.h>
const int MAX = 100; 
const int maxSizeQueue = 100;
typedef struct node {
    struct node*lc;
    struct node*rc;
    int data;
} node;
typedef struct queue{
    node* nodeQueue[maxSizeQueue];
	int front;
    int rear;
}queue;
void initQueue(queue *q){
    q->front = q->rear = 0;
}
void enQueue(queue *q,node *ele){
    if((q->rear+1)%maxSizeQueue == q->front) return;
    q->rear = (q->rear+1)%maxSizeQueue;
    q->nodeQueue[q->rear] = ele;
	return;
}
node* deQueue(queue *q){
	if(q->front == q->rear) return NULL;
    q->front = (q->front+1)%maxSizeQueue;
    return q->nodeQueue[q->front];
}
node* createTree(int sum){
    char left[5];
    char right[5];
    node*root = (node*)malloc(sizeof(node));
    node*p = root;
    queue *nodeQueue = (queue*)malloc(sizeof(queue));
    int t,n;
    root->lc=root->rc=NULL;
    root->data = 1;
    t = 1;
    n = 0;
    initQueue(nodeQueue);
    enQueue(nodeQueue,root);
    while(n<sum){
        n++;
        scanf("%s%s",left,right);
        p = deQueue(nodeQueue);
        if((!strcmp(left,"#"))&&(!strcmp(right,"#"))) continue;
        if(strcmp(left,"#")){
            t++;
            node*pnew = (node*)malloc(sizeof(node));
            pnew->lc=pnew->rc=NULL;
            pnew->data = t;
            p->lc = pnew;
            enQueue(nodeQueue,pnew);
        }
        if(strcmp(right,"#")){
            t++;
            node*pnew = (node*)malloc(sizeof(node));
            pnew->lc=pnew->rc=NULL;
            pnew->data = t;
            p->rc = pnew;
            enQueue(nodeQueue,pnew);
        }
    }
    return root;
}
int getHigh(node*root){
    int leftH=0,rightH=0;
    if(root->lc!=NULL){
        leftH = getHigh(root->lc);
    } else {
        leftH=0;
    }
    if(root->rc!=NULL){
        rightH = getHigh(root->rc);
    } else {
        rightH=0;
    }
    return (leftH>rightH)?leftH+1:rightH+1;
}
int main(){
    int sum;
    node*tree = (node*)malloc(sizeof(node));
    while(true){
        scanf("%d",&sum);
        if(sum==0) break;
        tree = createTree(sum);
        printf("%d",getHigh(tree));
    }
    system("pause");
    return 0;
}