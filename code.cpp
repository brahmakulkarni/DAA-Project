#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> colour;
vector<int> num_vertices_with_colour;
vector<int> pi;
vector<vector<int>> vertices_with_colour;

// typedef struct node {
//     int weight, parent;
// } node;

// void dfs(vector <vector<int>> &graph, int *visited, int pos)
// {
//   if (visited[pos]) return;
//   visited[pos] = 1;
//   for (int i = 0; i < graph[pos].size(); i++) {
//         dfs(graph, visited, graph[pos][i]);
//   }
// }

// void addEdge(vector <vector<int>> &graph, int u, int v){
//   graph[u].push_back(v);
//   graph[v].push_back(u);
// }

void addEdge(vector<tuple<int, int, int>> &graph, int u, int v, int w) {
    graph.push_back(tuple<int, int, int>(w,u,v));
    // graph.push_back(tuple<int, int, int>(w,v,u));
}

void initialize() {
    for (int i = 0; i < n; i++) {
        colour.push_back(i);
        vector<int> vertices;
        vertices.push_back(i);
        vertices_with_colour.push_back(vertices);
        pi.push_back(i);
        num_vertices_with_colour.push_back(1);
    }
}

vector<tuple<int, int, int>> kruskal(vector<tuple<int, int, int>> &graph) {
    sort(graph.begin(), graph.end());
    reverse(graph.begin(), graph.end());
    vector<tuple<int, int, int>> S;
    initialize();
    for (int i = 0; i < graph.size(); i++) {
        int u = get<1>(graph[i]);
        int v = get<2>(graph[i]);
        int colour1 = colour[u];
        int colour2 = colour[v];
        if (colour1!= colour2) {
            if (num_vertices_with_colour[colour1] < num_vertices_with_colour[colour2]) {
                pi[u] = v;
                num_vertices_with_colour[colour2] += num_vertices_with_colour[colour1];
                num_vertices_with_colour[colour1] = 0;
                for (int j = 0; j < vertices_with_colour[colour1].size(); j++) {
                    int vertex = vertices_with_colour[colour1][j];
                    colour[vertex] = colour2;
                    vertices_with_colour[colour2].push_back(vertex);
                }
                vertices_with_colour[colour1].clear();
            }
            else {
                pi[v] = u;
                num_vertices_with_colour[colour1] += num_vertices_with_colour[colour2];
                num_vertices_with_colour[colour2] = 0;
                for(int j=0;j<vertices_with_colour[colour2].size(); j++){
                    int vertex = vertices_with_colour[colour2][j];
                    colour[vertex] = colour1;
                    vertices_with_colour[colour1].push_back(vertex);
                }
                vertices_with_colour[colour2].clear();
            }
        }
        else{
            S.push_back(graph[i]);
        }
    }
    return S;
}

int main(){
    vector<tuple<int, int, int>> graph;
    int num_vertices, num_edges;
    cin >> num_vertices;
    cin >> num_edges;
    n = num_vertices;
    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        addEdge(graph, u, v, w);
    }
    vector<tuple<int,int,int>> cycle_edges = kruskal(graph);
    for (int i = 0; i < cycle_edges.size(); i++) {
        int u = get<1>(cycle_edges[i]);
        int v = get<2>(cycle_edges[i]);
        cout << u+1 << "---" << v+1 << endl;
    }
    return 0;
}
