#include<stdio.h>    
#include<stdlib.h> 
const int MAX = 1000; 
const int maxSizeQueue = 1000;
typedef struct node {
    struct node*lc;
    struct node*rc;
    int data;
} node;
typedef struct queue{
    node *nodeQueue;
	int front;
    int rear;
}queue;
void initQueue(queue *q){
    q->nodeQueue = (node*)malloc(sizeof(node)*maxSizeQueue);
    q->front = q->rear = 0;
}
void enQueue(queue *q,node ele){
    if((q->rear+1)%maxSizeQueue == q->front) return;
    *(q->nodeQueue+q->rear) = ele;
    q->rear = (q->rear+1)%maxSizeQueue;
	return;
}
node* deQueue(queue *q){
	if(q->front == q->rear) return NULL;
    node *temp = q->nodeQueue+q->front;
    q->front = (q->front+1)%maxSizeQueue;
    return temp;
}
node* createTree(int sum){
    int a,b,tag;
    node*root = (node*)malloc(sizeof(node));
    node*p;
    node*ss[MAX];
    root->lc=root->rc=NULL;
    root->data = 0;
    ss[0] = root;
    for(int n=1; n<MAX; n++){
        node*pnew=(node*)malloc(sizeof(node));
        pnew->data = n;
        pnew->lc=pnew->rc=NULL;
        ss[n] = pnew;
    }
    for(int i=0; i<sum; i++){
        scanf("%d%d%d",&a,&b,&tag);
        node*pnew2 = (node*)malloc(sizeof(node));
        pnew2->data = b;
        pnew2->lc=pnew2->rc=NULL;
        ss[a]->data = a;
        ss[b]->data = b;
        if(tag==1){
            ss[a]->lc = ss[b];
        } else if(tag==2){
            ss[a]->rc = ss[b];
        }
    }
    return root;
}
int getLeaf(node*root){
    int result = 0;
    node*p=root;
    queue *nodeQueue = (queue*)malloc(sizeof(queue));
    initQueue(nodeQueue);
    enQueue(nodeQueue,*root);
    while((p=deQueue(nodeQueue))!=NULL){
        if(p->lc!=NULL){
            enQueue(nodeQueue,*(p->lc));
        }
        if(p->rc!=NULL){
            enQueue(nodeQueue,*(p->rc));
        }
        if(p->lc==NULL&p->rc==NULL){
            result++;
        }
    }
    return result;
}
int main(){
    int sum;
    node*tree = (node*)malloc(sizeof(node));
    while(true){
        scanf("%d",&sum);
        if(sum==0) break;
        tree = createTree(sum);
        printf("%d\n",getLeaf(tree));
    }
    system("pause");
    return 0;
}