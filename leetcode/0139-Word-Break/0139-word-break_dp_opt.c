/*
DP
- dp[i] = true, means the word can be broken before s[i+1].
- dp[0] is always true, if caller asked about s[i], dp[i+1] shoud be returned.

- transfer function
- dp[i] = dp[j] && s[j+1:i-1], for every i < j

- Optimization:
- If `i` in dp[i] is too small, so that it's not possible to find a string in `wordDict` to break this word `s`,
  then we don't need to concern such small `i`, because such dp[i+1] is definitely false.
  time complexity can be lowered to O(nk).
*/

bool isInwordDict(char* s, int head, int tail, char** wordDict, int wordDictSize){
    if(head>tail) return false;
    int len = tail-head+1;
    char* temp = (char*)malloc(sizeof(char) * (len+1));
    temp[len] = '\0';
    memcpy(temp,s+head,len*sizeof(char));
    for(int i = 0;i<wordDictSize;i++){
        if (strcmp(temp,wordDict[i]) == 0) return true;
    }
    return false;
}

/*
str   | l | e | e | t | c | o | d | e |
s     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
dp| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
*/

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len = strlen(s);
    bool* dp = (bool*)calloc((len+1),sizeof(bool)); // dp[i] = true, means the word can be broken before s[i+1]
    dp[0] = true;

    int maxLen = 0;  
    for (int i = 0; i < wordDictSize; i++) {
        maxLen = fmax(maxLen, strlen(wordDict[i]));
    }

    for(int i = 0;i<len;i++){
        for(int j = fmax(0, i - maxLen + 1);j<=i;j++){  // if length of s[i] is large, then it's not necessary to traverse small `i`.
            //from now on, only needs to check k times at max. k is the length of `wordDict`.
            if (dp[j]){ // if dp[j] is true, and s[j+1:i] is in wordDict, then dp[i+1] is also true;
                if (isInwordDict(s,j,i,wordDict,wordDictSize)){
                    dp[i+1] = true;
                    break;
                }
            } 
        }
    }
    return dp[len];
}
