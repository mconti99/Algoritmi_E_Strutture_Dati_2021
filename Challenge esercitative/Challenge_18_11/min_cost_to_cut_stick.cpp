//c[i,j]=(min(c[i,k]+c[k,j])) + cost(i,j) dove i<k<j e cost(i, j)=j-i per j>i+1

#include <bits/stdc++.h>
using namespace std;


int min_cost(vector<int> tagli, map<pair<int,int>,int>& dp, int start, int end){
    
    
    if(dp.find({start,end}) != dp.end())
        return dp[{start,end}];
    
    bool cut = false;
    int min = INT_MAX;
    for(auto taglio : tagli){
        
        if(taglio>start && taglio<end){
            cut = true;
            int cost1 = min_cost(tagli, dp, start, taglio);
            int cost2 = min_cost(tagli,dp, taglio,end);
            int costo = cost1+cost2;
            
            if(costo<min)
                min = costo;
        }
        
    }
    
    if(cut){
        
        dp[{start,end}] = end-start+min;
        return dp[{start,end}];}
    else
    {
        dp[{start,end}] = 0;
        return dp[{start,end}];}
    
}


int main() {
	// your code goes here
	
	int l;
	while(cin>>l){
	    
	    if(l == 0)
	        break;
	        
	    int n;
	    cin>>n;
	    
	    vector<int> tagli;
	    int val;
	    
	    for(int i=0;i<n;i++)
	        {
	            cin>>val;
	            tagli.push_back(val);
	        
	        }
	    
	    map<pair<int,int>,int> dp;
	    cout<<min_cost(tagli,dp,0,l)<<endl;
	}
	
	return 0;
}
