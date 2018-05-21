#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define MOD 1000000007
using namespace std;
int* stockSpan(int *price,int size){
    stack<int> s;
    int *output = new int[size];
    s.push(0);
    output[0]=1;
    for(int i=1;i<size;i++){
        while(!s.empty() && price[s.top()]<price[i]){
            s.pop();
        }
        if(s.empty()) output[i] = i+1;
        else{
            output[i] = i-s.top();
        }
        s.push(i);
    }
    return output;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int64_t n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        int *output = stockSpan(arr,n);
        for(int i=0;i<n;i++){
            cout << output[i] << " ";
        }
    }
}