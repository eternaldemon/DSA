#LEETCODE 1054. Distant Barcodes
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=1)
            return barcodes;
        unordered_map<int,int> m;
        vector<int> result(barcodes.size(),0);
        for(auto i:barcodes){
            m[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it=m.begin();it!=m.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        int index=0;
        int key,value;
        while(!pq.empty()){
            key = pq.top().second;
            value = pq.top().first;
            pq.pop();
            while(value!=0){
                if(index>=result.size())
                    index=1;
                result[index] = key;
                value--;
                index = index+2;
            }
        }
        return result;
    }
};
