char findNonRepeating(string str) {
    std::vector<int> ctr;
    for(int i: str) {
        if (i >= ctr.size()) ctr.resize(i+1, 0);
        ctr[i]++;
    }
    
    for (int i: str) {
        if (ctr[i] == 1) return char(i);
    }
    
    return '#';
}
