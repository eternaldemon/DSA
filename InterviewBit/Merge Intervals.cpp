/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    int i;
    for(i=0;i<intervals.size();i++){
        if(newInterval.start<=intervals[i].start){
            intervals.insert(intervals.begin()+i,newInterval);
            break;
        }
    }
    
    if(i==intervals.size())
    intervals.push_back(newInterval);
    
    for(int i=0;i<intervals.size();i++){
        if(intervals[i].end>=intervals[i+1].start){
            intervals[i+1].start = intervals[i].start;
            intervals[i+1].end = max(intervals[i].end,intervals[i+1].end);
        }
        else if(intervals[i+1].start>intervals[i].end){
            result.push_back(intervals[i]);
        }
        else if(i==intervals.size()-1){
            result.push_back(intervals[i]);
        }
    }
    return result;
}

