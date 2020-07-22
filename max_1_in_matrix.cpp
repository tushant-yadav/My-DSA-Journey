    #include<iostream>
    #include<stack>
    #include<climits>
    using namespace std;

    int max_area(int arr[],int n){
        stack<int> s;
        int area=INT_MIN,max_area_so_far=INT_MIN;
        int i=0;
        while(i<n){
            if(s.empty() || arr[s.top()]<=arr[i]) 
                {s.push(i);
                }
            else{
                while(!s.empty() && arr[s.top()]>arr[i]){
                    int a=s.top();
                    s.pop();
                    //int l=s.top();
                    area=arr[a]*(s.empty()?i:i-s.top()-1);
                }	
            }
            s.push(i);
            //cout<<area<<":"<<max_area_so_far<<":"<<i<<endl;
            max_area_so_far=area>max_area_so_far?area:max_area_so_far;
            i++;

        }
        while(!s.empty()){
            int a=s.top();
            s.pop();
            area=arr[a]*(s.empty()?i:i-s.top()-1);
            max_area_so_far=area>max_area_so_far?area:max_area_so_far;
            //cout<<area<<":"<<max_area_so_far<<":"<<i<<endl;
        }
        return max_area_so_far;
    }


    int main(){
        int m,n;
        cin>>m>>n;
        int arr[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>0){
                arr[i][j]=arr[i-1][j]+arr[i][j];
                }
            }
        }
        
        /*for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }     */
        int maximu=0,max_all_over=INT_MIN;
        for(int i=0;i<m;i++){
            maximu=max_area(arr[i],n);
            //cout<<maximu<<":"<<i<<endl;
            max_all_over=max_all_over<maximu?maximu:max_all_over;
        }
        cout<<max_all_over<<endl;
    }