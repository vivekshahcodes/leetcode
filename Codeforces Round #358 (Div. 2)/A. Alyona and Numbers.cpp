#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b;

    cin>>a>>b;

    ll x = min(a,b);
    ll y = max(a,b);

    map<ll,ll> m;

    for(ll i=1;i<=y;i++){
        m[i%5]++;
    }

    ll ans = 0;

    for(ll i=1;i<=x;i++){
        ans += m[5-(i%5)];
        if(i%5==0){
            ans += m[0];
        }
    }

    cout<<ans;

    return 0;
}
