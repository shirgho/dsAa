class Solution {
public:

    /* // 1. sort both arrays and compare, if same then anagram (30ms, O(n logn))
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t) 
            return true;
        else 
            return false;
    } 
    
    // 2. go through array and make map of char to recurrance. If both maps same, is anagram (15ms, O(n))
    bool isAnagram(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for(char c : s){
            // if c in map, add 1 to value
            // else put c in map, with 1 value
            smap[c]++;
        }
        
        for(char c : t){
            tmap[c]++;
        }
        
        if(smap == tmap) //Average O(n), worst O(n²)
            return true;
        else 
            return false;
    } 
    
    // 3. Use only one map and negate values from t string, to see if strings match (11ms O(n))
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) 
            return false;
        
        unordered_map<char, int> map;
        
        for(char c : s)
            map[c]++;
        
        for(char c : t)
            map[c]--;
        
        for(auto key : map)
            if(key.second)
                return false;

        return true;
    } */
    
    // 4. use array instead of map to make it faster (10 ms, O(n))
    bool isAnagram(string s, string t) {
        // hash map is basically a larger array using hashes instead of indexes
        if(s.length() != t.length()) 
            return false;
        
        vector<int> map(26,0);
        //int array[26];
        //map.reserve(50);
      
        for(char c : s)
            map[c - 'a']++;
        
        for(char c : t)
            map[c - 'a']--;
        
        
        /*for(int i = 0; i < s.size(); i++){
            array[s[i] - 'a'] += 1;
            map[s[i] - 'a'] += 1;
        }*/
            
        //ostream_iterator<int> output(cout, " ");
        //copy(map.begin(), map.end(), output);
        //cout << endl;
        //cout << "size: " << map.size() << endl;
        
        /*
        for(vector<int>::iterator i = map.begin(); i != map.end(); ++i){
            cout << "i: " << distance(map.begin(), i) << endl;
            if (map.at(distance(map.begin(), i)) != 0)
               return false;
        }*/
        
        for(int i = 0; i < map.size(); i++){
            if(map.at(i))
                return false;
        }
            
        
        return true;
        
    }
    
    
    
};