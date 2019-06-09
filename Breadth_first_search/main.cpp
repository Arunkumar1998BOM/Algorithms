#include <iostream>
#include<list>
#include<vector>
using namespace std;
//now create a graph class

class graph{
    //This is the number of verticies
    int V;
    //This is the adjacency list
    list <int> *adj;
public:
    graph(int V);
    //This function is to add the edge to the particular nodes
    void add_edge(int v, int w);
    //this function is to print the BFS from the given node
    void print(int s);

    //This is the constructor

};

graph::graph(int V) {
    this->V=V;
    adj=new list<int>[V];
}

void graph::add_edge(int v, int w) {
    //Add w to v's list
    adj[v].push_back(w);
}

void graph::print(int s) {
    bool *visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    //create a queue for BFS
    list <int>queue;

    visited[s]=true;
    queue.push_back(s);

    list<int>::iterator i;
    while(!queue.empty())
    {   //Dequeue a vertex from queue and print it
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        //Now we shall traverse
        for(i=adj[s].begin();i!=adj[s].end();++i){
            if(!visited[*i]){
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}
int main() {
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    cout<<"Following is the breadth first traversal "<<" Starting from vertex 2 ";
    g.print(2);

    return 0;
}