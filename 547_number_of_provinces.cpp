class Solution {
public:
    /*
    when do we get to know that this province isnt connected to another one??
    We consider the maximum number of cities as the number of provinces -- 
    ans = N
    1 ---> 2    kya ye connected he pehle se? No
    = ans - 1
    2 ---> 3  kya ye connected he pehle se? No
    = ans - 1
    ex: 1 --> 3  kya ye connected he pehle se? Yes
    To ans - 1 nahi hoga
    Track konsa city konse city se connected he...
    Ek set kon konsa cities were connected aur 
    kya ham pahucnch koi city X se koi dusri city Y
    Matrix 
    1 ---> 2
    
    Final: Create sets of connected vertices, return the size in the end 

        */
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        vector<unordered_set<int>> vec;

        for(int i = 0; i < sz; i++) {
            vec.push_back({i});
        }

        for(int i = 0; i < sz; i++){
            for(int j = i+1; j < sz; j++){
                if(isConnected[i][j]){
                    int ind1 = -1, ind2 = -1;
                    for(int k = 0; k < vec.size(); k++) {
                        if(vec[k].contains(i)) ind1 = k;
                        if(vec[k].contains(j)) ind2 = k;
                    }

                    if(ind1 != ind2) {
                        vec[ind1].insert(vec[ind2].begin(), vec[ind2].end());
                        vec.erase(vec.begin() + ind2);
                    }
                    // 1 --> 2
                    // {1, 2}
                    // 2 --> 3
                    // set 2 he?? Ya fir 3 he??
                    // agr koi ek bhi he to fir usi wale group me dalenge 3 ke bhi
                    // {1, 2, 3}
                    // Agar naya group form nahi hua, ans -1 nahi karna 
                    // agar 4 --> 5, na to 4, na 5 he....
                    // {1,2,3} {4, 5}
                }
            }
        }
        return (int)(vec.size());
    }
};