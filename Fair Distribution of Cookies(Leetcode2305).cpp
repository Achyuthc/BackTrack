

/*You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.*/

class Solution {
public:
    int ans=INT_MAX;
    void backtrack(int indx,vector<int> &v,vector<int> &cookies,int &k)
    {
        if(indx==cookies.size())
        {
            int tmp=INT_MIN;
            for(int i=0;i<k;i++)
                tmp=max(tmp,v[i]);
            ans=min(ans,tmp);
            return;
        }
        for(int i=0;i<k;i++)
        {
            v[i]+=cookies[indx];
            backtrack(indx+1,v,cookies,k);
            v[i]-=cookies[indx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        backtrack(0,v,cookies,k);
        return ans;
    }
};
