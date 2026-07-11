class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0;
        int m=g.size(),n=s.size();
        while(l<n && r<m){
            if(g[r]<=s[l])
                r++;
            l++;
        }
        return r;
    }
};