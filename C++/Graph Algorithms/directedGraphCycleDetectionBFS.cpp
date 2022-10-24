#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph's node class definition
class node {
    public:
        int src , dest , wt;

        node(int src , int dest , int wt) {
            this->src = src;
            this->dest = dest;
            this->wt = wt;
        }
};

// Function to find the toposort of the given graph using Kahn's Algorithm (BFS)
void topoSortBFS(vector <vector <node> > &graph , vector <int> &indegree , vector <int> &topoSort) {

    queue <int> q;
    for(int i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int src = q.front();
        q.pop();

        topoSort.push_back(src);

        for(int i = 0; i < graph[src].size(); i++) {
            int dest = graph[src][i].dest; 
            if(indegree[dest] == 1) {
                q.push(dest);
            } else {
                indegree[dest]--;
            }
        }
    }

}

// Function to detect whether a cycle exists in a directed graph with the help of topo sort
bool detectCycleBFS(vector <int> &topoSort , int vertices) {
    return topoSort.size() != vertices;
}

int main() {

    int vertices , edges;
    cin >> vertices >> edges;

    vector <vector <node> > graph(vertices);
    for(int i = 0; i < edges; i++) {
        int src , dest , wt;
        cin >> src >> dest >> wt;

        graph[src].push_back(node(src , dest , wt));
    }

    vector <int> indegree(vertices , 0);
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            indegree[graph[i][j].dest]++;
        }
    }

    vector <int> topoSort;

    topoSortBFS(graph , indegree , topoSort);

    cout << topoSort.size() << endl;

    bool hasCycle = detectCycleBFS(topoSort , vertices);
    if(hasCycle) {
        cout << "The graph has a Cycle" << endl;
    } else {
        cout << "The graph doesn't have a Cycle" << endl;
    }

    return 0;
}