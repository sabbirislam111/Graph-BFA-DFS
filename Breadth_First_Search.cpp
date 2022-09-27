#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> edgewaightpair;

class Graph{
    int V;
    list <edgewaightpair> *adj;

public:
    Graph(int V){
        this->V = V;
        adj = new list<edgewaightpair> [V];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printNaighbour(int chk){
        cout<<chk<<" : ";
        for(auto i = adj[chk].begin(); i != adj[chk].end(); i++){
            cout<<"("<< (*i).first <<','<< (*i).second<<") ";

        }
         cout<<endl;
    }

    void BFS(int sourch){
        vector<bool> visited(V, false);
        queue<int> Q;
        visited[sourch] = true;
        Q.push(sourch);

        while(!Q.empty()){
            int u = Q.front();
            cout<<u<<" ";
            Q.pop();
            for(auto element: adj[u]){
                int v = element.first;
                if(visited[v] != true){
                    visited[v] = true;

                    Q.push(v);
                }

            }

        }

    }

    void DFS(int sourch){
        static vector<bool> visited(V, false);
        queue<int> Q;
        visited[sourch] = true;
        cout<<sourch<<" ";

        for(auto element: adj[sourch]){
            int v = element.first;
            if(visited[v] != true){
                DFS(v);
            }
        }
    }

};


int main(){

    int V, E;
    cin>>V>>E;
    Graph g(V);
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
    }

    for(int i = 0; i < V; i++){
        g.printNaighbour(i);
    }

    g.BFS(0);
    cout<<endl;
    g.DFS(0);




 return 0;
}
/*
7 10
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4
5 4 6
2 5 8


*/

