#include<stdio.h>    
#include<stdlib.h> 
#include<string.h>
#include<math.h>
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
    int length;
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
    char left[5];
    char right[5];
    node*root = (node*)malloc(sizeof(node));
    node*s[MAX];
    int n,t;
    root->data = 1;
    root->lc=root->rc=NULL;
    s[1]=root;
    n = 1;
    t = 1;
    while(n<=sum){
        scanf("%s%s",left,right);
        if(strcmp(left,"#")){
            int m = 0;
            int data = 0;
            int q = 0;
            while(left[m]!='\0'){
                m++;
            }
            for(int j=m; j>0; j--){
                data += ((int)(left[j-1]-'0'))*pow(10,q);
                q++;
            }
            node*pnew = (node*)malloc(sizeof(node));
            pnew->data = data;
            pnew->lc=pnew->rc=NULL;
            s[data] = pnew;
            s[n]->lc = pnew;
        }
        if(strcmp(right,"#")){
            int m = 0;
            int data = 0;
            int q = 0;
            while(right[m]!='\0'){
                m++;
            }
            for(int j=m; j>0; j--){
                data += ((int)(right[j-1]-'0'))*pow(10,q);
                q++;
            }
            node*pnew = (node*)malloc(sizeof(node));
            pnew->data = data;
            pnew->lc=pnew->rc=NULL;
            s[data] = pnew;
            s[n]->rc = pnew;
        }
        n++;
    }
    return root;
}
void getOrder(node*root,int sum){
    node*p=root;
    int n = 1;
    queue *nodeQueue = (queue*)malloc(sizeof(queue));
    initQueue(nodeQueue);
    enQueue(nodeQueue,*root);
    while((p=deQueue(nodeQueue))!=NULL){
        if (n<sum) {
            printf("%d ",p->data);
        } else {
            printf("%d",p->data);
        }
        n++;
        if(p->lc!=NULL){
            enQueue(nodeQueue,*(p->lc));
        }
        if(p->rc!=NULL){
            enQueue(nodeQueue,*(p->rc));
        }
    }

}
int main(){
    int sum;
    node*tree = (node*)malloc(sizeof(node));
    while(true){
        scanf("%d",&sum);
        if(sum==0) break;
        tree = createTree(sum);
        getOrder(tree,sum);
    }
    return 0;
}