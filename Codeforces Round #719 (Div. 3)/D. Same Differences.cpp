#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin>>t;

    while(t--){

        ll n, ans = 0;

        cin>>n;

        map<ll,ll> m;

        for(ll i=1;i<=n;i++){

            ll input;
            cin>>input;

            m[i-input]++;
        }

        for(auto i:m){
            ll x = i.second-1;
            ans += (x*(x+1))/2;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
