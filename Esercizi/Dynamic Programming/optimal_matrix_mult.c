//dp[i,j]=min(dp[i,k]+dp[k+1,j]+cost(A_{i:k-1}*A_{k:j-1})) dove devo ciclare k da i a j-1 
//O(n^3)
#include <bits/stdc++.h>
using namespace std;

int cost(const vector<pair<int,int>>& mat,int i, int k, int j){
	return mat[i].first * mat[k].second * mat[j].second;
}

int solve(int inizio, int fine, const vector<pair<int,int>>& mat, map<pair<int,int>,int>& dp){
	if(dp.find({inizio,fine})!=dp.end())
		return dp[{inizio,fine}];
	if(inizio == fine)
		return dp[{inizio, fine}] = 0;
	if(inizio == fine-1)
		return dp[{inizio,fine}] = mat[inizio].first * mat[fine].first * mat[fine].second;

	int min_val = INT_MAX;

	for(int k = inizio; k<= fine-1;k++)
		min_val = min(min_val, solve(inizio,k, mat, dp) + solve(k+1, fine, mat, dp) + cost(mat, inizio, k, fine));
	
	return dp[{inizio,fine}] = min_val;
 }

int main(){
	vector<pair<int,int>> mat;//vettore di coppie, ovvero le dimensioni di ogni matrice
	int n;
	cin >> n;
	vector<int> sizes;//vettore di dimensioni
	for(int i=0;i<=n;i++){
		int temp;
		cin >> temp;
		sizes.push_back(temp);
	}

	for(int i=0;i<n;i++){//vado da mat[0] a mat[n-1]
		pair<int,int> temp;
		temp.first = sizes[i];
		temp.second = sizes[i+1];
		mat.push_back(temp);
	}

	map<pair<int,int>,int> dp;

	cout <<  solve(0, n-1, mat, dp) << endl;

	//system("pause");
}

/*
// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		dp[i][j] = min(
			dp[i][j], matrixChainMemoised(p, i, k)
					+ matrixChainMemoised(p, k + 1, j)
					+ p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
	int i = 1, j = n - 1;
	return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n);
}

*/
