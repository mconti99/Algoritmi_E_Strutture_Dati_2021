#include <bits/stdc++.h>
using namespace std;

int solve(const vector<vector<int>>& m, vector<vector<int>>& dp, const int i, const int j){
	if(dp[i][j]!=-1)
		return dp[i][j];

	vector<int> sols;
	sols.push_back(0);
	for(int l = -1; l<=1; l++)
		for(int k = -1; k<=1; k++){
			if(!(i+l<0 || j+k<0 || i+l>=m.size() || j+k>= m[0].size())){
				if(m[i][j] > m[i+l][j+k] && abs(l)!=abs(k))
					sols.push_back(solve(m,dp,i+l,j+k));
			}
		}

	return dp[i][j] = 1 + *max_element(sols.begin(), sols.end());
}




int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		int row, col;
		cin >> s >> row >> col;
		vector<vector<int>> m(row, vector<int>(col, 0));
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin >> m[i][j];
		vector<vector<int>> dp(row, vector<int>(col, -1));
		int max_val = 0;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				max_val = max(max_val,solve(m,dp,i,j));
		cout << s << ": " << max_val << endl;
	}

	system("pause");
}