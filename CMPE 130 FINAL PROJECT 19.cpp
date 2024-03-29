#include <iostream>
#include <limits.h>
#include <cmath>
#include<cstdlib>



using namespace std;


struct edge{
    int source;
    int destination;
    int weight;
};
struct graph{
    int n_v;
    int n_e;
    struct edge *e;
};



struct graph *construct(int vertices, int edges){
    struct graph *g=new graph;
    g->n_v=vertices;
    g->n_e=edges;
    g->e=new edge[edges];
    return g;
    
};

void printgraph(int destination[], int n, int source){
    cout<<"Destinations          Shortest distance from source "<<source<<endl;
    for (int a=0;a<n;a++){
        if (destination[a]==INT_MAX){
            cout<<a<<"                  "<<"   No outgoing edge towards to the vertex"<<endl;
        }
        else
            cout<<a<<"                           "<<destination[a]<<endl;
    }
    cout<<endl;
    
}
void shortest_path_from_source(graph *g){
    int v=g->n_v;
    int e=g->n_e;
    int destination[v];
    
    for (int source=0;source<v;source++)
    {
        
        for(int i=0; i<v;i++){
            destination[i]=INT_MAX;
            
        }
        
        destination[source]=0;
        
        for (int i=1;i<= v-1;i++){
            for (int k=0;k<e;k++){
                int a=g->e[k].source;
                int b=g->e[k].destination;
                int weight= g->e[k].weight;
                if (destination[a]!=INT_MAX && destination[a]+weight <destination[b]){
                    destination[b]=destination[a]+weight;
                }
            }
        }
        
        for (int j=0;j<e;j++){
            int a=g->e[j].source;
            int b=g->e[j].destination;
            int weight= g->e[j].weight;
            if (destination[a]!=INT_MAX && destination[a]+weight <destination[b]){
                cout<<"negative weight cycle"<<endl;
                return;
            }
        }
        printgraph(destination, v, source);
    }
}




int main() {
    int vertices=5;
    int edges=8;
    struct graph *network=construct(vertices, edges);
    network->e[0].source = 0;
    network->e[0].destination = 1;
    network->e[0].weight = -4;
    
    // add edge 0-2
    network->e[1].source = 0;
    network->e[1].destination = 2;
    network->e[1].weight = 11;
    
    // add edge 1-2
    network->e[2].source = 1;
    network->e[2].destination = 2;
    network->e[2].weight = 14;
    
    // add edge 1-3
    network->e[3].source = 1;
    network->e[3].destination = 3;
    network->e[3].weight = 9;
    
    // add edge 1-4
    network->e[4].source = 1;
    network->e[4].destination = 4;
    network->e[4].weight = 8;
    
    // add edge 3-2
    network->e[5].source = 3;
    network->e[5].destination = 2;
    network->e[5].weight = 12;
    
    // add edge 3-1
    network->e[6].source = 3;
    network->e[6].destination = 1;
    network->e[6].weight = 16;
    
    // add edge 4-3
    network->e[7].source = 4;
    network->e[7].destination = 3;
    network->e[7].weight = -7;
    
    
    
    shortest_path_from_source(network);
    
    
    
    
}
