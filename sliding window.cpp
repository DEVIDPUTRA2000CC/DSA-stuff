Q1->
  You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1.

#include <bits/stdc++.h>
using namespace std;
int main(){  
string s="aabacbebebe";
int k;
cin>>k;
int start=0;
int maxlen=INT_MIN;
unordered_map<char, int> mpp;
 for(int end=0; end<s.length(); end++){
     char checkchar=s[end];
     mpp[checkchar]++;
     while(mpp.size()>k){
        mpp[s[start]]--;
if (mpp[s[start]] == 0) {
    mpp.erase(s[start]);
}
start++;
}
if(mpp.size()==k){
    maxlen=max(maxlen, end-start+1);
}else{
    return -1;
}

 }
 cout<<maxlen;

    }
// Try to viualize->:
| Step | `end` | `s[end]` | `mpp` (char → freq)    | `start` | `mpp.size()` | Action                          | `maxlen`   |
| ---- | ----- | -------- | ---------------------- | ------- | ------------ | ------------------------------- | ---------- |
| 0    | 0     | `'a'`    | `{a:1}`                | 0       | 1            | size < k → move on              | -∞         |
| 1    | 1     | `'a'`    | `{a:2}`                | 0       | 1            | size < k → move on              | -∞         |
| 2    | 2     | `'b'`    | `{a:2, b:1}`           | 0       | 2            | size < k → move on              | -∞         |
| 3    | 3     | `'a'`    | `{a:3, b:1}`           | 0       | 2            | size < k → move on              | -∞         |
| 4    | 4     | `'c'`    | `{a:3, b:1, c:1}`      | 0       | ✅ 3          | ✅ Update maxlen = 5 (0 to 4)    | 5          |
| 5    | 5     | `'b'`    | `{a:3, b:2, c:1}`      | 0       | 3            | ✅ Update maxlen = 6 (0 to 5)    | 6          |
| 6    | 6     | `'e'`    | `{a:3, b:2, c:1, e:1}` | 0       | ❌ 4          | ❗ Shrink until size == 3        |            |
|      |       |          | `{a:2, b:2, c:1, e:1}` | 1       | 4            | —                               |            |
|      |       |          | `{a:1, b:2, c:1, e:1}` | 2       | 4            | —                               |            |
|      |       |          | `{a:1, b:1, c:1, e:1}` | 3       | 4            | —                               |            |
|      |       |          | `{a:0, b:1, c:1, e:1}` | 4       | 4            | erase `'a'` → `{b:1, c:1, e:1}` | ✅ size = 3 |
|      |       |          | `{b:1, c:1, e:1}`      | 4       | 3            | ✅ Update maxlen = 6 (4 to 6)    | 6          |
| 7    | 7     | `'b'`    | `{b:2, c:1, e:1}`      | 4       | 3            | ✅ Update maxlen = 7 (4 to 7)    | **7**      |
| 8    | 8     | `'e'`    | `{b:2, c:1, e:2}`      | 4       | 3            | ✅ Update maxlen = 8 (4 to 8)    | **8**      |
| 9    | 9     | `'b'`    | `{b:3, c:1, e:2}`      | 4       | 3            | ✅ Update maxlen = 9 (4 to 9)    | **9**      |
| 10   | 10    | `'e'`    | `{b:3, c:1, e:3}`      | 4       | 3            | ✅ Update maxlen = 10 (4 to 10)  | **10**     |

LEET CODE Q-> 209, 3





  
