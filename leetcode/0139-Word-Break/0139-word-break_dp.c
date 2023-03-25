/*
DP
- dp[i] = true, means the word can be broken before s[i+1].
- dp[0] is always true, if caller asked about s[i], dp[i+1] shoud be returned.

- transfer function
- dp[i] = dp[j] && s[j+1:i-1], for every i < j

- time complexity: O(n^2k), n is the length of string s, k is the length of wordDict.
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
    for(int i = 0;i<len;i++){
        for(int j = 0;j<=i;j++){
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
