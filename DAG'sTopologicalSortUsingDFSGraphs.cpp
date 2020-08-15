#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class graph{
    map<T,list<T>>l;
    public:
    void addedge(int x,int y){
        l[x].push_back(y);
    }
    void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering){
        //recursive function that will traverse the graph

        visited[src]=true;
        //go to all nbrs one by one
        for(T nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited,ordering);
            }
        }
    ordering.push_front(src);    
    return;
    }


    void dfs(){
        map<T,bool> visited ;
        list<T> ordering;
        //mark all the nodes as not visited in the beginning
        for(auto p:l){
            T node =p.first;
            visited[node]=false;}
        
    //call the helper function

    //interate over all vertices and call dfs for non visited
    int cnt=0;
    for(auto p:l){
        T node=p.first;
        if(!visited[node]){
            dfs_helper(node,visited,ordering);
            cnt++;
            cout<<endl;
        }
    }
    for(auto a:ordering){
        cout<<a<<" ";
    }
    }

};


int main() {
    graph<int> g;
    g.addedge(1,3);
    g.addedge(1,2);
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(1,0);
    g.addedge(0,4);
    g.dfs();
    return 0;
}
