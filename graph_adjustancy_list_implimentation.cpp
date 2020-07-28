#include<iostream>
#include<list>
using namespace std;

class graph{
	int v;
	//array of lists
	list<int> *l;
	public:
	graph(int v){
		this->v=v;
		l=new list<int>[v];
	}
	void addedge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void print_adj_list(){
		//iterate over all the vertices
		for(int i=0;i<v;i++){
			cout<<"Vertex"<<i<<"->";
			for(int nbr:l[i]){
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}

};




int main(){
	graph g(4);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(2,3);
	g.print_adj_list();
	return 0;
}