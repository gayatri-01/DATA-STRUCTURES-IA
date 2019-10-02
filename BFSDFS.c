#include <stdio.h>
#include <stdlib.h>

int stack[100],visited[100],visitedq[100];
int q[100];
int adj[100][100]; 
int top=-1;
int rear=-1,front=-1;
int n;

void push(int val){
  top++;
  stack[top]=val;
}

int pop(){
  int val=stack[top]; 
  top--;
  return val;
}

void pushq(int val)
{
if(front==-1&&rear==-1)
{front=rear=0;
  q[front]=val;  }
  else {
  rear++;
  q[rear]=val;}
}

int popq()
{int val;
 val=q[front];
 front++;
 return val;
}

void DFS(int s)
{static int c=0,i;
 printf("%c\t",s+65);
 c++;
 if(c==n)
  return;
 for( i=n-1;i>=0;i--)
  {if(adj[s][i]&&visited[i]==0){
    push(i);
    visited[i]=1;
    }
  }
  s=pop();  
  DFS(s);
}



void BFS(int s)
{static int c=0,i;
 printf("%c\t",s+65);
 c++;
 if(c==n)
  return;
 for( i=0;i<n;i++)
  {if(adj[s][i]&&visitedq[i]==0){
    pushq(i);
    visitedq[i]=1;
   }
  }
  s=popq(); 
  BFS(s);
}


 
int main(void) {
  printf("\nEnter no of nodes in graph: ");
  scanf("%d",&n);
  printf("\nEnter the adjacency matrix:\n");
  for(int i=0;i<n;i++)
  {  for(int j=0;j<n;j++)
    scanf("%d",&adj[i][j]);
  }
  int s;
  printf("\nEnter the start node: ");
  scanf("%d",&s);
  visited[s]=1;
  visitedq[s]=1;
  printf("\nChoose a traversal method:\n1.DFS\t2.BFS\n-1:EXIT");
  int opt;
  printf("\nEnter option: ");
  scanf("%d",&opt);
  while(opt!=-1){
    switch(opt){
      case 1:
      printf("\n________________DFS________________");
      printf("\n\n");
      DFS(s);
      break;
      case 2:
      printf("\n\n");
      printf("\n________________BFS________________");
      printf("\n\n");
      BFS(s);
      break;
    }printf("\nEnter option: ");
  scanf("%d",&opt);
  }
  return 0;
}
/*0 1 1 0 0 0 
 1 0 0 1 1 0
 1 0 0 0 1 0
 0 1 0 0 1 1
 0 1 1 1 0 1
 0 0 0 1 1 0*/