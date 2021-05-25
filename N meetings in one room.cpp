class Solution
{
    public:
    
    static bool comp(pair<int,int> p1 , pair<int,int> p2){
	if(p1.second<p2.second){
		return true;
	}
	else if(p1.second==p2.second){
		if(p1.first < p2.first){
			return true;
		}
	}
	return false;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int> p[n];
        for(int i=0;i<n;i++){
            p[i].first = start[i];
            p[i].second = end[i];
        }
        sort(p,p+n,comp);
        int cnt =1;
        int time = p[0].second;
        for(int i=1;i<n;i++){
            if(p[i].first > time){
                cnt++;
                time = p[i].second;
            }
        }
        return cnt;
        
    }
};
