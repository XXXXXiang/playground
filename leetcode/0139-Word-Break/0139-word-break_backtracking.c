/*
Trying to apply backtracking, but time complexity is about O(n^2).
Once wordDictSize is too large, it will take very long time and fail due to Time Limit Exceeded.
*/


bool strcp(char* s, int head, char* worddict){
    int len = strlen(worddict);
    int lens = strlen(s);
    char* temp = (char*)malloc(sizeof(char) * (len + 1));
    temp[len] = '\0';
    if (head + len > lens) {
        return false;
    }
    memcpy(temp, s + head, len);
    if (strcmp(temp,worddict) == 0) {
        free(temp);
        return true;
    }
    free(temp);
    return false;
}

void search(char* s, int index, int len, char** wordDict, int wordDictSize, bool* rslt){
    if(*rslt == true) return;
    if(index == len){
        *rslt = true;
        return;
    }
    for(int i = 0;i<wordDictSize;i++){
        if (!strcp(s,index,wordDict[i])){//string in wordDict is not identical to s[index]
            continue;
        }
        else if (strlen(wordDict[i]) + index > len){
            break;
        }
        search(s,index+strlen(wordDict[i]),len,wordDict,wordDictSize,rslt);
    }
}

int cmp(const void* a, const void* b){
    return strlen(*((char**)a)) - strlen(*((char**)b));
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    bool rslt = false;
    bool* prslt = &rslt;
    qsort(wordDict,wordDictSize,sizeof(char*),cmp); //Sort wordDict by string length, so once the string in wordDict too long to pick, just break.
    search(s,0,strlen(s),wordDict,wordDictSize,prslt);
    return rslt;
}
