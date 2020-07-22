#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int count;
    int sum;
    int height;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* build_tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}

//POST ORDER LEFT-RIGHT-ROOT
void print_post(node* root){
    if(root==NULL){
        return;
    }
    print_post(root->left);
    print_post(root->right);
    cout<<root->data<<" ";
    return;
}

//INORDER LEFT-ROOT-RIGHT
void print_in(node* root){
    if(root==NULL){
        return;
    }
    print_post(root->left);
    cout<<root->data<<" ";
    print_post(root->right);
    return;
}


// preorder ROOT-LEFT-RIGHT
void print(node* root){
    if(root==NULL){
        //cout<<"END";
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

//prints height of tree
int height_tree_count(node* &root){
    if(root==NULL)   return 0;
    root->height=max(height_tree_count(root->left),height_tree_count(root->right))+1;
    return root->height;
}

//for print_sameheight
void height_tree(node* root,int h){
    if(root==NULL) return;
    if(h==1){
        cout<<root->data<<" ";
        return ;
    }
    
    height_tree(root->left,h-1);
    height_tree(root->right,h-1);
}
void print_sameheight(node* root){
    int level=height_tree_count(root);
    for(int i=1;i<=level;i++){
        height_tree(root,i);
        cout<<endl;
    }
}

//to count no. of nodes and sum of childerens
node* function(node* root){
    if(root->left==NULL && root->right==NULL){
        root->count=1;
        root->sum=root->data;
        return root;
    }
    node* c;
    node* d;
    if(root->left==NULL){
        c=function(root->right);
        root->sum=c->sum+root->data;
        root->count=c->count+1;
        return root;
    }
    if(root->right==NULL){
        d=function(root->left);
        root->sum=d->sum+root->data;
        root->count=d->count+1;
        return root;
    }
    root->sum=c->sum+d->sum+root->data;
    root->count=c->count+d->count+1;
    return root;
}



int diameter(node* root){
    if(root==NULL) return 0;
    int current_dia=height_tree_count(root->left)+height_tree_count(root->right)+1;
    int left_dia=diameter(root->left);
    int right_dia=diameter(root->right);
    return max(max(left_dia,right_dia),current_dia);
}

void print_right_view(queue<node*> r){
    while(!r.empty()){
        node* a=r.front();
        cout<<a->data<<":";
        r.pop();
    }
    return ;
}

void bfs(node* root){
    queue<node*> q;
    queue<node*> r;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f=q.front();
        if(f==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            if(f->left!=NULL) q.push(f->left);
            if(f->right!=NULL) q.push(f->right);
            q.pop();
            if(q.front()==NULL) {r.push(f);}
        }
    }
    print_right_view(r);
    return;
}




int main() {
    node* root=NULL;
    root=build_tree();
    print(root);
    cout<<endl;
    //print_post(root);
    cout<<endl;
    //print_in(root);
    cout<<endl;
    //print_sameheight(root);
    //cout<<height_tree_count(root);
    //cout<<endl<<"sum and count"<<endl;
    //node* d=function(root);
    //cout<<d->count<<":"<<d->sum<<endl;
    //cout<<"diameter:"<<diameter(root);
    bfs(root);
    return 0;
}
