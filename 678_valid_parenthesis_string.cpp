class Solution {
public:
    /*Simple stack based approach ke lie jaa raha, what about the *?? keep pushng that as well?
    Jab ) aaye to pop & compare? 
    */
    bool checkValidString(string s) {
        int mini =0, maxi =0;
        for(int el: s){
            if(el == '(') mini++, maxi++;
            else if(el == ')') mini--, maxi--;
            else mini--, maxi++;
            if(maxi < 0) return false;
            mini = max(mini, 0);
        }
        if(mini ==0) return true;
        return false;
    }
};