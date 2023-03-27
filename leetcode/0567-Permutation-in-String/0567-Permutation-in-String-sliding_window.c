/*
Sliding Window

Time Complexity: O(n) n is the length of s2.
*/

bool checkInclusion(char* s1, char* s2) {
    // Initialize variables
    size_t len_s1 = strlen(s1), len_s2 = strlen(s2);
    if (len_s2 < len_s1) return false;
    //Initiate freq_s1 to record s1 letter frequency
    size_t freq_s1[26] = {0};
    for (size_t i = 0; i < len_s1; ++i) {
        ++freq_s1[s1[i] - 'a'];
    }
    //Initiate freq_s2 to record s2 letter frequency in sliding window
    size_t freq_s2[26] = {0};
    for (size_t i = 0; i < len_s1 - 1; ++i) { // the most right entry `len_s1 - 1` will not be added,
        ++freq_s2[s2[i] - 'a'];               // because the sliding window will start from `len_s1 - 1`
    }
    // Use sliding window to search for permutations of s1 in s2
    for (size_t i = len_s1 - 1; i < len_s2; ++i) {
        ++freq_s2[s2[i] - 'a']; // Add one entry from right
        if (memcmp(freq_s1, freq_s2, sizeof(freq_s1)) == 0) { //Check if the two frequency are identical.
            return true; // Remove one entry from left
        }
        --freq_s2[s2[i - len_s1 + 1] - 'a'];
    }
    return false;
}
