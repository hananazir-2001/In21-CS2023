#include <iostream>
#include <limits.h>

#define V 6 // number of vertices in the graph

using namespace std;
// function to get the minimum time
int minTime_taken(int Time[], bool visited[]) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++) {
        if (!visited[v] && Time[v] <= min) {
            min = Time[v];
            min_index = v;
        }
    }
 
    return min_index;
}

void dijkstra(int graph[V][V], int start) {
    int Time[V]; // array to store shortest distance from start to i
    bool visited[V]; // array to keep track of visited vertices
 
    for (int i = 0; i < V; i++) {
        Time[i] = INT_MAX;
        visited[i] = false;
    }
 
    Time[start] = 0;
 
    for (int count = 0; count < V - 1; count++) {
    
        int u = minTime_taken(Time, visited);
        
        visited[u] = true;
 
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && Time[u] != INT_MAX && Time[u] + graph[u][v] < Time[v]) {
                Time[v] = Time[u] + graph[u][v];
            }
        }
    }
     double total_time =0;
    //cout << "Vertex \t Distance from Start\n";
     //for (int i = 0; i < 6; i++){
     //cout<<"from node "<<i<<endl;
    for (int i = 0; i < V; i++) {
        cout<< "Time taken to city "<< i <<" = ";
        cout <<Time[i] << endl;
        total_time+=Time[i];
    }
    cout<< "total_time =  "<< total_time<<endl;
    
    double average =  total_time/5;

    cout<< "average =  "<< average <<endl;
    }


int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    }; // adjacency matrix representation of the graph
    //cout<<"from city "<<0<<endl;
    //dijkstra(graph, 0); // find shortest path and its weight starting from vertex 0
    //cout<<"from city "<<1<<endl;
    //dijkstra(graph, 1);
   //cout<<"from city "<<2<<endl;
    //dijkstra(graph, 2);
    //cout<<"from city "<<3<<endl;
    //dijkstra(graph, 3);
    //cout<<"from city "<<4<<endl;
    //dijkstra(graph, 4);
    cout<<"from city "<<5<<endl;
    dijkstra(graph, 5);
    return 0;
}