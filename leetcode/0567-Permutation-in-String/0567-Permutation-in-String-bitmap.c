/*
Use Bitmap and traverse every possible substring.

Beats only 7.41% in time complexity.

1. Build a letter list to record the frequency of each letter in s1.
2. Build a letter bitmap to record the letters that exist in s1.
3. Traverse s2 and reduce the corresponding entry in the letter list for each letter encountered.
4. Record the starting index (matchIdx) when a match is found.
5. If an entry in the letter list goes to 0, set the corresponding bit in the bitmap to 0.
6. If the bitmap is 0, return true because s1 is a permutation of a substring of s2.
7. If the current letter in s2 is not in s1, reset both the bitmap and letter list.
8. If the letter list entry for the current letter in s2 is 0, reset both the bitmap and letter list, and re-match starting from matchIdx.

Time Complexity: O(n+k) n is the length of s2, k in the length of s1. But the time complexity may be much higher, because the code reset `i` in for loop of s2, it depends the input.
*/

#define SET_BIT(x,i) (x=(x|(1UL<<i)))
#define CLEAR_BIT(x,i) (x=(x&(~(1UL<<i))))

bool checkInclusion(char * s1, char * s2){
    int* letterList = (int*)calloc(26,sizeof(int));
    unsigned int bitmap = 0;
    for(int i = 0;s1[i]!='\0';i++){
        int ascii = s1[i] - 'a';
        letterList[ascii] += 1;
        SET_BIT(bitmap,ascii);
    }

    unsigned int tempbitmap = bitmap;
    int* tempList = (int*)calloc(26,sizeof(int));
    memcpy(tempList,letterList,sizeof(int) * 26);
    int matchIdx = -1;
    bool matching = false;

    for(int i = 0;s2[i]!='\0';i++){
        int ascii = s2[i] - 'a';
        if (matching==false){ // if not in matching state, set to matching state and record the start index.
            matchIdx = i;
            matching = true;
        }

        if (tempbitmap == 0) return true;
        
        else if(letterList[ascii] == 0){ // there is not any chance if there is no such letter in letterList.
            tempbitmap = bitmap;         // reset the bitmap and the list, then continue to check
            memcpy(tempList,letterList,sizeof(int) * 26);
            matchIdx = i;
            matching = true;
            continue;
        }

        else if(tempList[ascii] == 0){ // s2[i] is mismatch for the current check, a new check needs to be started from s2[i].
            tempbitmap = bitmap;       // reset the bitmap and the list
            memcpy(tempList,letterList,sizeof(int) * 26);
            i = matchIdx;
            matching = false;
            continue;
        }
        
        tempList[ascii] -= 1;
        
        if (tempList[ascii] == 0){
            CLEAR_BIT(tempbitmap,ascii);
        }
    }
    
    if (tempbitmap==0) return true;
    return false;
}
