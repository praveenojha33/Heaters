/**
	Intuition:
	In this solution I use binary search to find the answer. Currently for any given radius (say r) if we can
	heat all the houses than we can also heat all the houses with radius greater than equal to r. So I check for
	a radius and if I can cover all the houses with that radius than all the radius greater than r can't be my answer
	as we need to find the minimum and currently we have r as one of the possible answer. We will keep shrinking the
	sample space of our solution and will report the answer once lw and hi is same (lw means lowest possible answer
	ans hi is highest possible answer) .
	
	Time Complexity:
	We are binary searching for answer in range 0 to 10^9 every time we remove half on the range from our answer,
	so it will take log(10^9) steps for us to cut down the range to 1. Also for each check I can be traversing the
	both the arrays once. Also initial sorting has a time complexity of O(nlogn + mlogm) and Binary Search also
	has time complexity of O((n+m)log(10^9)) so overall time complexity is O((n+m)log(10^9)).
**/
class Solution {
public:
    vector<int> a,h;
    int n,m;
    bool check(long long r){
        int cur=0;
        for(int i=0;i<n;i++){
            long long p=max(h[i]-r,0LL),nxt=min(h[i]+r,(long long)1e9);
            if(cur<m && a[cur]<p)
                return false;
            while(cur<m && a[cur]<=nxt)
                cur++;
        }
        return (cur==m ? true : false);
    }
    int findRadius(vector<int>& aa, vector<int>& hh) {
        a=aa;
        h=hh;
        m=a.size();
        n=h.size();
        sort(a.begin(),a.end());
        sort(h.begin(),h.end());
        long long lw=0,hi=1e9;
        while(lw<hi){
            long long mid=(lw+hi)/2;
            if(check(mid))
                hi=mid;
            else
                lw=mid+1;
        }
        
        return lw;
    }
};