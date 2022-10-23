#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph's Edge class definition
class Edge {
    public:
        int src;
        int dest;
        int wt;

        Edge(int src , int dest , int wt) {
            this->src = src;
            this->dest = dest;
            this->wt = wt;
        }
};

vector <int> bfs(vector <vector <Edge> > &graph , vector <bool> &visited , int source) {

    // To store the vertices visited in bfs
    vector <int> visitedVertices;

    queue <int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()) {

        // Getting the first adjacent element
        int vertex = q.front();
        q.pop();

        visitedVertices.push_back(vertex);

        // Push all the adjacent elements of edge.dest into the queue
        for(int i = 0; i < graph[vertex].size(); i++) {
            Edge adjacentEdge = graph[vertex][i];
            if(visited[adjacentEdge.dest] == false) {
                q.push(adjacentEdge.dest);
                visited[adjacentEdge.dest] = true;
            }
        }
    }

    return visitedVertices;
}

int main() {


    int vertices;
    cin >> vertices;

    int edges;
    cin >> edges;

    vector <vector <Edge> > graph(vertices);
    for(int i = 0; i < edges; i++) {
        int src , dest , wt;
        cin >> src >> dest >> wt;

        graph[src].push_back(Edge(src , dest , wt));
        graph[dest].push_back(Edge(dest , src , wt));
    }

    vector <bool> visited(vertices , false);

    // Calling just the bfs, only performs bfs for a single component of the graph
    // If they are multiple components in the graph, then this would not traverse all the vertices of the graph
    
    vector <vector <int> > totalComponents;

    for(int i = 0; i < vertices; i++) {
        if(visited[i] == false) {
            vector <int> singleComponent = bfs(graph , visited , i);
            totalComponents.push_back(singleComponent);
        }
    }

    if(totalComponents.size() == 0) {
        cout << "No vertices has been visited";
    }
    for(int i = 0; i < totalComponents.size(); i++) {
        for(int j = 0; j < totalComponents[i].size(); j++) {
            cout << totalComponents[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
