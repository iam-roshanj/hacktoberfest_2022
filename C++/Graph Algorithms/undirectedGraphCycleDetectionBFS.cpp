#include <iostream>
#include <vector>
#include <queue>

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

// Function to perform BFS and detect whether the component of the graph has a cycle or not
bool hasCycleBFS(vector <vector <node> > &graph , vector <bool> &visited , int i) {

    queue <pair <int , int> > q;
    q.push(make_pair(i , -1));
    visited[i] = true;

    while(!q.empty()) {
        int src = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(int adj = 0; adj < graph[src].size(); adj++) {
            int dest = graph[src][adj].dest;
            if(visited[dest] == false) {
                q.push(make_pair(dest , src));
                visited[dest] = true;
            } else {
                if(dest != parent) return true;
            }
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

    bool hasCycle = false;

    vector <bool> visited(vertices , false);
    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) {
            if(hasCycleBFS(graph , visited , i)) {
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

// 11
// 9
// 0 1 0
// 1 3 0
// 2 4 0
// 4 9 0
// 4 5 0
// 5 6 0
// 7 8 0
// 8 9 0
// 7 10 0
// 6 7 0