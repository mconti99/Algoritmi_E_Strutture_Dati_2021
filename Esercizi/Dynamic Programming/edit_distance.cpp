//dp[i,j]=min(cost(replace(x[i]->y[j]))+dp[i+1,j+1], cost(insert(y[j]))+dp[i,j+1], cost(delete(x[i]))+dp[i+1,j])
//O(|x|*|y|)
// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems
	int dp[m + 1][n + 1];

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If the last character is different, consider
			// all possibilities and find the minimum
			else
				dp[i][j]
					= 1 //caso base
					+ min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Remove
							dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}

// Driver code
int main()
{
	string str1 = "sunday";
	string str2 = "saturday";

	cout << editDistDP(str1, str2, str1.length(),
					str2.length());

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int minDis(string s1, string s2, int n, int m, vector<vector<int>> &dp){
		
// If any string is empty,
// return the remaining characters of other string
			
if(n==0) return m;
		
if(m==0) return n;
		
			
// To check if the recursive tree
// for given n & m has already been executed
		
if(dp[n][m]!=-1) return dp[n][m];
			
			
// If characters are equal, execute
// recursive function for n-1, m-1
		
if(s1[n-1]==s2[m-1]){		
	if(dp[n-1][m-1]==-1){			
	return dp[n][m] = minDis(s1, s2, n-1, m-1, dp);		
	}		
	else
	return dp[n][m] = dp[n-1][m-1];
}
	
		
// If characters are nt equal, we need to
			
// find the minimum cost out of all 3 operations.
		
else{		
	int m1, m2, m3;	 // temp variables
	
	if(dp[n-1][m]!=-1){	
	m1 = dp[n-1][m];	
	}		
	else{
	m1 = minDis(s1, s2, n-1, m, dp);	
	}			
			
	if(dp[n][m-1]!=-1){				
	m2 = dp[n][m-1];			
	}			
	else{	
	m2 = minDis(s1, s2, n, m-1, dp);	
	}								
	
	if(dp[n-1][m-1]!=-1){	
	m3 = dp[n-1][m-1];	
	}
	else{
	m3 = minDis(s1, s2, n-1, m-1, dp);	
	}	
	return dp[n][m] = 1+min(m1, min(m2, m3));		
}
	
}


// Driver program
int main() {
	
string str1 = "voldemort";
string str2 = "dumbledore";
		
int n= str1.length(), m = str2.length();	
vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
				
cout<<minDis(str1, str2, n, m, dp);
return 0;

}

*/

