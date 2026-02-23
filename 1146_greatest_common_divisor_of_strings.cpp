/* repeating pattern dhundhna hoga dono strings me,,,how??
 Pehli cheez to ye he ki repeat hone chaiye strings dono ke dono. Ab isko kaise identify kar
 sakte he?? Ek hi cheez dimaag me aa rahi he, wo he Binary operators. Hmm ek achha tarika mila he, 
 somehow pattern identify kia, aur ab loop kar raha hu dono strings me ek saath last se shuru karke,
 Agar me 0 index pe pahunch gaya to divisor return kar sakte he? Par minimum length ka rahega wo kaise identify karunga??
SO I've a great idea rn, that's take in sizes of these 2 strings, perform GCD on these 2 nos and after you get the mod of the current 2 nos check if that length can act as a divisor (the issue? I'd have to check if this length string divides both??) 
 */

class Solution {
public:
    /*I'll always send in the s1 as the smaller string, s2 as the larger one, smaller is size of the smaller string*/
    string checkDiv(string& s1, string& s2, int& num, int& smaller, int& greater){
        string subs = s1.substr(0, num);
        for(int i = 0; i < smaller; ++i) {
            if(s1[i] != subs[i % num]) return "";
        }
        for(int i = 0; i < greater; ++i) {
            if(s2[i] != subs[i % num]) return "";
        }
        return subs;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int size1 = str1.size(), size2 = str2.size(), greater, smaller;
        if(size1 > size2) {
            greater = size1;
            smaller = size2;
            int len = gcd(greater, smaller);
            return checkDiv(str2, str1, len, smaller, greater);
        }
        greater = size2;
        smaller = size1;
        int len = gcd(greater, smaller);
        return checkDiv(str1, str2, len, smaller, greater);
    }
};