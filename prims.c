#include <stdio.h>
#include<limits.h>
#define V 5
int minKey(int key[],int mstset[]){
    int min = INT_MAX,min_index;
    for(int i =0 ;i<V;i++){
        if(mstset[i]==0 && key[i]<min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
//0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0

void printprim(int graph[V][V],int parent[]){
    printf("Edge     Weight\n");
    for(int i =1;i<V;i++){
        printf("%d - %d  %d\n",parent[i],i,graph[i][parent[i]]);
       
    }

}
void prim(int graph[V][V]){
    int parent[V];
    int mstset[V];
    int key[V];
    for(int i =0;i<V;i++){
        key[i]=INT_MAX;
        mstset[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int j =0;j<V-1;j++){
        int u = minKey(key,mstset);
          mstset[u]=1;
        for(int i=0;i<V;i++){
        if(mstset[i]==0 && graph[u][i] && graph[u][i]<key[i]){
            parent[i]=u;
            key[i]=graph[u][i]; 
        }
    }}
    printprim(graph,parent);
}
int main(){
    int graph[V][V];
    printf("Enter the value ");
    for(int i =0;i<V;i++){
        for(int j = 0;j< V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    prim(graph);
    return 0 ;
}
// #include <stdio.h>
// #include <limits.h>

// #define V 5

// int minKey(int key[], int mstset[]) {
//     int min = INT_MAX, min_index;
//     for (int i = 0; i < V; i++) {
//         if (mstset[i] == 0 && key[i] < min) {
//             min = key[i];
//             min_index = i;
//         }
//     }
//     return min_index;
// }

// void printprim(int graph[V][V], int parent[]) {
//     printf("Edge   Weight\n");
//     for (int i = 1; i < V; i++) {
//         printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
//     }
// }

// void prim(int graph[V][V]) {
//     int parent[V];
//     int mstset[V];
//     int key[V];

//     for (int i = 0; i < V; i++) {
//         key[i] = INT_MAX;
//         mstset[i] = 0;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int count = 0; count < V - 1; count++) {
//         int u = minKey(key, mstset);
//         mstset[u] = 1;

//         for (int i = 0; i < V; i++) {
//             if (mstset[i] == 0 && graph[u][i] && graph[u][i] < key[i]) {
//                 parent[i] = u;
//                 key[i] = graph[u][i];
//             }
//         }
//     }

//     printprim(graph, parent);
// }

// int main() {
//     int graph[V][V];

//     printf("Enter the adjacency matrix for the graph (5x5):\n");
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     prim(graph);
//     return 0;
// }
