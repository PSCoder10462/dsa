class Solution {
public:
     bool detectCapitalUse(string word) {
        int count = 0;
        for (int i = 0; i < word.length(); i++){
            if (isupper(word[i])){
                count++;
            }
        }
        
        if (count == word.length()){
            return true;
        }else if (count == 0){
            return true;
        }else if (count == 1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};
