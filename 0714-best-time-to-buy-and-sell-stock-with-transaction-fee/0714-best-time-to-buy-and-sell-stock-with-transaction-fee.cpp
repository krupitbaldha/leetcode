class Solution {
public:
    int find(vector<int> &prices, int i,bool buy,vector<vector<int>> &v,int fee)
    {
      
        if(i>=prices.size()) return 0;
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy)  {
            
           return v[i][buy]=max(-prices[i]-fee+find(prices,i+1,!buy,v,fee),find(prices,i+1,buy,v,fee)); 
        }
        else    {
           return v[i][buy]=max( prices[i]+find(prices,i+1,!buy,v,fee),find(prices,i+1,buy,v,fee)); 
        }
    }
    int maxProfit(vector<int>& prices,int fee) {
        
        int n=prices.size(); 
        vector<vector<int>> v(n,vector<int> (2,-1));
        //passing here buy=1 because we will first buy then sell
        //we can do atmost k=1 transaction
        return find(prices,0,1,v,fee);
    }
};