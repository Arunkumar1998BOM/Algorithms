//
// Created by ak47a on 09-06-2019.
//

#include<iostream>
#include<list>
using namespace std;

class graph{
    //this stores the number of vertices
    int V;
    //create a list that will hold the adjacency
    list<int> *adj;
public:
    //contructor
    graph(int V);
    //this function is to add edges
    void add_edge(int v, int w);
    //this function is called recursively to travel depths
    void DFS_util(int v, bool visited[]);
    //this function will initiate the DFS
    void DFS(int v);

};

graph::graph(int V) {
    this->V=V;
    adj=new list<int>[V];
}

void graph::add_edge(int v, int w) {
    adj[v].push_back(w);
}
void graph::DFS(int v) {
    bool *visited=new bool [V];
    for (int i=0;i<V;i++){
        visited[i]=false;
    }

    //Now initiate the recursive function
    DFS_util(v,visited);
}
void graph::DFS_util(int v, bool visited[]) {
    //the present node must be visited and written out
    visited[v]=true;
    cout<<v<<" ";
    //now we shall start the traverse

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            DFS_util(*i,visited);
        }
    }

}
int main(){
//cout<<"Please enter the number of nodes";
//int k;
//cin>>k;
graph g(4);
g.add_edge(0,1);
g.add_edge(0,2);
g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);

    cout<<"This is the beginning of the DFS (at 2 )";
    g.DFS(2);
    return 0;
}