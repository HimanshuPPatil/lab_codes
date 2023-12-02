#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int queue[7],head=-1,tail=-1;

bool isempty()
{
    if(head==-1 && tail==-1)
        return true;
    else
        return false;
}


int dequeue()
{
    if(isempty()){
        printf("Underflow");
        return -1;
    }
    if(head==tail){
        int num=queue[head];
        head=tail=-1;
        return num;
    }
    int num=queue[head];
    head=head+1;
    return num;
}

void enqueue(int data){
    if(isempty())
        head=0;
    tail++;
    queue[tail]=data;
}

int main()
{
    int visited[7]={0,0,0,0,0,0,0};
    int tree[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    int root;
    printf("Enter root for traversing");
    scanf("%d",&root);
    visited[root]=1;
    enqueue(root);
    //printf("%d ",root);

    while(!isempty()){
        int num=dequeue();
        printf("%d ",num);
        for(int j=0;j<7;j++){
            if(visited[j]==0 && tree[num][j]==1){
                enqueue(j);
                visited[j]=1;
                //printf("%d ",j);
            }
        }
    }
}

/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int queue[7];
int head=-1,tail=-1;
void enqueue(int data){
    if(head==-1 && tail==-1)
        head=0;
    if(tail==6){
        printf("overflow\n");
        return;
    }
    tail=tail+1;
    queue[tail]=data;
}

bool isEmpty(){
     if(head==-1 && tail==-1)
        return true;
     else
        return false;
}
int dequeue(){
    if(head==tail && head!= -1){
        return queue[head];
        head=tail=-1;
    }
    return queue[head++];
}
int main()
{
    int root;
    printf("Enter root for BFS traversal");
    scanf("%d",&root);
    int tree[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    int visited[7]={0,0,0,0,0,0,0};
    visited[root]=1;
    enqueue(root);
    while(!isEmpty()){
        int num=dequeue();
        printf("%d ",num);
        for(int j=0;j<7;j++){
            if(visited[j]==0 && tree[num][j]==1){
                enqueue(j);
                visited[j]=1;
            }
        }
    }
    return 0;
}*/
