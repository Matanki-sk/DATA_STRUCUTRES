#include<stdio.h>
#include<limits.h>
#define V 6
int minKey(int dist[],int sptset[]){
    int min= INT_MAX,min_index;
    for(int i =0;i<V;i++){
        if(sptset[i]==0 && dist[i]<min){
            min = dist[i];
            min_index= i;
        }
    }
    return min_index;
}
void print(int dist[]){
    printf("Vertex \t Distance\n");
    for(int i = 0;i < V;i++){
        printf("%d \t %d\n",i,dist[i]);
    }
}
void dijikstra(int graph[V][V],int src){
    int sptset[V];
    int dist[V];

    for(int i = 0;i<V;i++){
        sptset[i]=0;
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i = 0;i<V;i++){
        int u = minKey(dist,sptset);
        sptset[u]=1;
        for(int v=0;v<V;v++){
            if(!sptset[v] && graph[u][v] && dist[u]+graph[u][v]<=dist[v]){
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    print(dist);
}
int main(){
    int graph[V][V],source;
    printf("Enter the value ");
    for(int i =0;i<V;i++){
        for(int j = 0;j< V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter the value for source");
    scanf("%d",&source);
    dijikstra(graph,source);
}