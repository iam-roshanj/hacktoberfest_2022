#include <iostream>
#include <vector>

using namespace std;

// Graph's node class definition
class node {

    public:
        int src;
        int dest;
        int wt;

        node(int src , int dest , int wt) {
            this->src = src;
            this->dest = dest;
            this->wt = wt;
        }
};

// Function to find if a cycle exists for a given component in the graph using DFS
bool hasCycleDFS(vector <vector <node> > &graph , vector <bool> &visited , int i , int parent) {

    visited[i] = true;
    for(int adj = 0; adj < graph[i].size(); adj++) {
        int dest = graph[i][adj].dest;
        if(visited[dest] == true) {
            if(dest != parent) return true;
        } else {
            if(hasCycleDFS(graph , visited , dest , i)) return true;
        }
    }
    return false;
}

int main() {

    int vertices , edges;
    cin >> vertices >> edges;

    vector <vector <node> > graph(vertices);
    for(int i = 0; i < edges; i++) {
        int src , dest , wt;
        cin >> src >> dest >> wt;

        graph[src].push_back(node(src , dest , wt));
        graph[dest].push_back(node(dest , src , wt));
    }

    vector <bool> visited(vertices , false);
    bool hasCycle = false;

    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) {
            if(hasCycleDFS(graph , visited , i , -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if(hasCycle) {
        cout << "There is a Cycle" << endl;
    } else {
        cout << "There is No Cycle" << endl;
    }

    return 0;
}

// 8
// 7
// 0 2 0
// 2 3 0
// 1 4 0
// 4 5 0
// 7 6 0
// 6 5 0
// 4 7 0