#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin>>s;

    int a[s.length()] = {0};

    for(int i=1;i<s.length();i++){
        if(s[i-1]==s[i]){
            a[i] = a[i-1]+1;
        }else{
            a[i] = a[i-1];
        }
    }

    int m;

    cin>>m;

    while(m--){

        int l,r;
        cin>>l>>r;

        cout<<a[r-1]-a[l-1]<<endl;

    }

    return 0;
}
