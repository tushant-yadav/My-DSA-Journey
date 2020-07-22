#include <iostream>
#include<vector>
using namespace std;

class heap{
    vector<int> h;
    bool minheap;
    bool compare(int idx1,int idx){
        if(minheap){
            return idx1>idx;
        }
    return idx1<idx;
    }
    void swap(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
        return;
    }
    void heapify(int parent,vector<int> &h,int size){
        int left= parent*2;
        int right = left+1;
        int last=size-1;
        int min_inx=parent;
        if(left<=last && compare(h[min_inx],h[left])){
            min_inx=left;
        }
        if(right<=last && compare(h[min_inx],h[right])){
            min_inx=right;
        }
        if(min_inx!=parent){
            swap(h[min_inx],h[parent]);
            heapify(min_inx,h,size);
        }
        
    }

    public:
    heap(int reserve_default=10,bool type=true){
        h.reserve(reserve_default);
        h.push_back(-1);
        minheap=type;
    }
    void print(){
        for(int i=1;i<h.size();i++){
            cout<<h[i]<<":"<<i<<"--";
        }
    }

    void insert(int data){
        h.push_back(data);
        cout<<data<<":"<<h.size()<<endl;
        int idx= h.size()-1;
        int parent= idx/2;
        while(idx>1 && compare(h[parent],h[idx])){
            swap(h[parent],h[idx]);
            idx=parent;
            parent=parent/2;
        }
    }

    void remove(){
        swap(h[1],h[h.size()-1]);
        h.pop_back();
        heapify(1,h,h.size());
    }
    //O(NLog(N)     ) time complexity
    void build_heap(vector<int> &v){
        for(int i=2;i<v.size();i++){
            int idx=i;
            int parent=idx/2;
            while(idx>1 && compare(v[parent],v[idx])){
                swap(v[parent],v[idx]);
                    idx=parent;
                    parent=parent/2;
                }
            }
        cout<<endl;    
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<":"<<i<<"--";
        }    
    }
    //---------O(N) optimized heap building
    void build_heap_opti(vector<int> &v1){
        int n=v1.size()-1;
        for(int i=n/2;i>=1;i--){
            heapify(i,v1,v1.size());}
        for(int i=1;i<v1.size();i++){
            cout<<v1[i]<<":"<<i<<"--";
        }    
    }
    void heapsort(vector<int> &arr){
        build_heap(arr);
        int n=arr.size();
        while(n>1){
            swap(arr[1],arr[n-1]);
            n--;
            heapify(1,arr,n);
        }
        for(int i=1;i<arr.size();i++){
            cout<<arr[i]<<"::"<<i<<"--";
        }    
    }        
    
};



int main() {
    heap a(10,true);
    a.insert(10);
    a.insert(20);
    a.insert(15);
    a.insert(14);
    a.insert(11);
    a.insert(90);
    a.print();
    a.remove();
    cout<<endl;
    a.print();
    vector<int> v={-1,10,20,5,6,1,8,9,4};
    cout<<"heap build**************************"<<endl;
    heap b(10,false);
    a.build_heap(v);
    cout<<endl<<"optimal heap**************************"<<endl;
    vector<int> v1={-1,10,20,5,6,1,8,9,4};
    a.build_heap_opti(v1);
    vector<int> v2={-1,10,20,5,6,1,8,9,4};
    cout<<endl<<"heapsort**************************"<<endl;
    a.heapsort(v2);

}
