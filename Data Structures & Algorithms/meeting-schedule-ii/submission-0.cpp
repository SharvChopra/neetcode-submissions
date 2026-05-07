/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start;
        vector<int>end;

        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i=0;
        int j=0;
        int groups = 0;
        int res = 0;
        while(i<intervals.size()){
            if(start[i]<=end[j]){
                groups+=1;
                i+=1;
            }
            else{
                groups-=1;
                j+=1;
            }
            res = max(res,groups);
        }
        return res;
    }
};
