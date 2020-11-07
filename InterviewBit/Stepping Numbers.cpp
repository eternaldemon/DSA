void dfs(int A, int B, int num, vector<int>&r){
    
    if(num>B)
        return;
    if(num==0 && num>=A && num<=B){
        r.push_back(0);
        return;
    }
    else if(num==0)
        return;
    if(num>=A && num<=B)
        r.push_back(num);
    int lastdigit = num % 10;
    int nextdigit1 = num*10 + lastdigit + 1;
    int nextdigit2 = num*10 + lastdigit - 1;
    
    if(lastdigit == 0)
        dfs(A,B,nextdigit1,r);
    else if(lastdigit == 9)
        dfs(A,B,nextdigit2,r);
    else{
        dfs(A,B,nextdigit1,r);
        dfs(A,B,nextdigit2,r);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> r;
    for(int i=0;i<=9;i++){
        dfs(A,B,i,r);
    }
    sort(r.begin(),r.end());
    /*
    for(int i=0;i<r.size();i++)
    cout<<r[i]<<endl;
    */
    return r;
}

