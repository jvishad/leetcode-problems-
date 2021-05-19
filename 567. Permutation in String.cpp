class Solution {
public:

//    time complexity is O(n)
//    sliding window approach
    bool check(int arr1[26],int arr2[26]){
        for(int i=0;i<26;i++){
            if(arr1[i]!= arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size() || s2.size() == 0){
            return false;
        }

        int arr1[26];
        int arr2[26];
        for(int i=0;i<26;i++){
            arr1[i] = 0;
            arr2[i] = 0;
        }

        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        if(check(arr1,arr2) == true){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){
            arr2[s2[i]-'a']++;
            arr2[s2[i-s1.size()]-'a']--;
            if(check(arr1,arr2) == true){
                return true;
            }
        }
        if(check(arr1,arr2) == true){
            return true;
        }
        return false;
    }
};