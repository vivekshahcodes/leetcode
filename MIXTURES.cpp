#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr<< "\n";
#else
#define debug(x)
#endif

template<class T> void _print(T a) { cerr << a; }
template<class T, class V> void _print(pair<T,V> p){ _print('{'); _print(p.first); _print(','); _print(p.second); _print('}'); }
template<class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(vector<vector<T>> v) { cerr << "\n"; for (auto i : v) { cerr << "[ "; _print(i); cerr << "]\n"; } }
template<class T> void _print(set<T> s) { cerr << "[ "; for (T i : s) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map<T, V> m) { cerr << "\n"; for (auto i : m) { _print(i.first); cerr << " "; _print(i.second); cerr << "\n"; } }


typedef long long ll;

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	fastio();

	int n;

	while(cin>>n){

		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}

		vector<vector<int>> dp(n,vector<int> (n,0));

		for(int i=0;i<n-1;i++){
			dp[i][i+1] = v[i]*v[i+1];
		}

		for(int i=2;i<n;i++){

			int r = 0, c = i;

			while(c<n){

				dp[r][c] = INT_MAX;

				for(int k=r;k<c;k++){

					int totA,totB;
					totA = totB = 0;

					for(int i=r;i<=k;i++){
						totA += v[i];
					}

					for(int i=k+1;i<=c;i++){
						totB += v[i];
					}

					dp[r][c] = min(dp[r][c],dp[r][k]+dp[k+1][c]+((totA%100)*(totB%100)));

					debug(dp);
				}
				r++;
				c++;
			}
		}

		cout<<dp[0][n-1]<<endl;

	}

	return 0;
}
