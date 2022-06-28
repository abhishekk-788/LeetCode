class Solution {
public:
     bool f(int s,int k,int cs,int ss,int n,vector<int> &a,vector<bool> &vis)
     {
        if(k==0) return true;
        if(cs>ss) return false;
        if(cs==ss){
            return f(0,k-1,0,ss,n,a,vis);
        }
        for(int i=s;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                if(f(i+1,k,cs+a[i],ss,n,a,vis)) return true;
                vis[i]=0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=0;
        int n=nums.size();
        int mx=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            mx=max(mx,nums[i]);
        }
        if(s%k!=0 || n<k || mx>s/k) return false;
        vector<bool> vis(n,0);
        return f(0,k,0,s/k,n,nums,vis);
    }
};

/*

 0 1 2 3 4 5 6 7 8  9
[2,2,3,4,4,6,7,8,10,10]
4


*/