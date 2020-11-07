vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int,vector<pair<int,int>>> m;
    vector<int> result(4,INT_MAX);
    
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            int sum = A[i] + A[j];
            m[sum].push_back(make_pair(i,j));
        }
    }
    for(auto i:m){
        if(i.second.size()>=2){
            for(int j=0; j<i.second.size();j++){
                pair<int,int> p1 = i.second[0];
                pair<int,int> p2 = i.second[j];
                int a = p1.first;
                int b = p1.second;
                int c = p2.first;
                int d = p2.second;
                if(a<b && c<d && a<c && b!=d && b!=c){
                    vector<int> temp = {a,b,c,d};
                    
                    if(temp<result)
                    result = temp;
                }
            }
        }
    }
    return result;
}

