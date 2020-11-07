vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int> heap;
    heap.insert(A);
    heap.insert(B);
    heap.insert(C);
    vector<int> result;
    
    while(result.size()<D){
        int next = *heap.begin();
        heap.erase(heap.begin());
        result.push_back(next);
        heap.insert(next*A);
        heap.insert(next*B);
        heap.insert(next*C);
    }
    return result;
}

