#include <bits/stdc++.h>
using namespace std;
/*int sum(vector<vector<int>> arr(n, vector<int>(n))){ 
    int n= arr.size();
    int sumtotal=0;
    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
        sumtotal+=arr[i];
       }
    }
    return sumtotal;

}
*/

int main() {
    int  m = 3;
    int n=4;
    vector<vector<int>> arr(m, vector<int>(n)); 

    // Input row wise
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    //Input cloumn wise

    /*for(int j=0; j<n; j++){
    for(int i=0; i<m; i++){
    cin>> arr[i][j];
    }
    }
    */
   
    // Output
   for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;

    }
    cout<<endl;
   
    int target;
    cin>>target;
    bool c=false;

   
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==target){
                c=true;
            }
        }
    }
    if(c==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    return 0;
}
