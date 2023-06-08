#include <bits/stdc++.h>
using namespace std;
#define V 6   //defining the number of vertices V as 6.

// function that checks if an edge (u, v) creates a valid MST edge. 
bool createsMST(int u, int v, vector<bool>& inMST){
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}
//function that finds and prints the MST.
void printMinSpanningTree(int cost[][V]){
    vector<bool> inMST(V, false);
    inMST[0] = true;
    int edgeNo = 0, MSTcost = 0;

    while (edgeNo < V - 1) {
        int minCost = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] < minCost) {
                    if (createsMST(i, j, inMST)) {
                        minCost = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            cout<<"edge "<<edgeNo++<<" : "<<a<<" - "<<b<<"  : cost = "<<minCost<<endl;
            MSTcost += minCost;
            inMST[b] = inMST[a] = true;
        }
    }
    cout<<"Cost of Minimum spanning tree = "<<MSTcost;
}

int main() {
    //representing the graph's adjacency matrix with the corresponding edge costs.
    int cost[V][V] = {
            { INT_MAX, 3, INT_MAX, INT_MAX, INT_MAX ,1},
            { 3, INT_MAX, 2, 1, 10,INT_MAX },
            { INT_MAX, 2, INT_MAX,3, INT_MAX, 5 },
            { INT_MAX, 1,3, INT_MAX, 5,INT_MAX },
            { INT_MAX, 10,INT_MAX, 5, INT_MAX,4},
            { 1, INT_MAX, 5,INT_MAX, 4,INT_MAX },
    };

    cout<<"The Minimum Spanning Tree for the given graph is:\n";
    //calls the printMinSpanningTree function to find and print the MST of the given graph.
    printMinSpanningTree(cost);

    return 0;
}