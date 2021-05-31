bool isSubSequence(string str1, string str2) {
    int i=0;
    
    for (int j=0; j<str2.length(); ++j) {
        if (str1[i] == str2[j])
        	i++;
        if (i==str1.length()) return true;
    }
    
    return false;
}
