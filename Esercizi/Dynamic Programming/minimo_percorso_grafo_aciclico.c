//deltak(s,v)=min{deltak-1(s,v)+w(u,v) con u,v € E e 0<=k<|V|
//O(VE)
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, const vector<vector<int>>& w, map<pair<int,int>, int>& dp){
	if(dp.find({i,j})!=dp.end()) //memoization
		return dp[{i,j}];

	if(i==j) //caso base
		return dp[{i,j}] = 0;

	int n = w.size();
	int min_val = INT_MAX;
	for(int k=0;k<n;k++) //ricorsione
		if(w[k][j]!=-1)
			min_val = min(min_val, solve(i,k,w,dp) + w[k][j]);
	if(min_val == INT_MAX) //nel caso i due nodi non siano collegati
		return dp[{i,j}] = -1;
	return dp[{i,j}] = min_val;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> w(n, vector<int>(n,-1)); //matrice nxn inizializzata a -1

	for(int i=0;i<n;i++){
		int links;
		cin >> links;
		while(links--){
			int to_who, cost;
			cin >> to_who >> cost;
			w[i][to_who] = cost;
		}
	}

	map<pair<int,int>, int> dp; //chiave: (inizio, fine), valore : costo_minimo

	cout << solve(0, n-1, w, dp) << endl; //cambiare i valori iniziali eventualmente

	//system("pause");
}
