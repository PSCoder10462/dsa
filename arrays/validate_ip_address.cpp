bool isValidIPv4(string ipAddress) {
    std::vector<std::string> v(4);
    int dotCount = 0;
    
    if (ipAddress[ipAddress.length()-1] > '9' || ipAddress[ipAddress.length()-1] < '0')
        return false;
    
    for (int i=0; i<ipAddress.length(); ++i) {
        char c = ipAddress[i];
        if (c == '.') { 
            dotCount++;
        	if (dotCount > 3) 
                return false;
        }
        else if (c >= '0' && c <= '9') v[dotCount].push_back(c);
        else return false;
    }
    
    if (dotCount != 3) return false;
    
    for (std::string s: v) {
        int temp = std::stoi(s);
        if (temp < 0 || temp > 255) return false;
    }
    
    return true;
    
}
