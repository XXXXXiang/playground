<h2><a href="https://leetcode.com/problems/word-break/description/">139. Word Break (Medium)</a></h2><div>

  <p>Given a string <code>s</code> and a dictionary of strings wordDict, return true if <code>s</code> can be segmented into a space-separated sequence of one or more dictionary words.</p>

  <p>Note that the same word in the dictionary may be reused multiple times in the segmentation.</p>
  <p>&nbsp;</p>
  
  <p><strong class="example">Example 1:</strong></p>
  <pre>
  <strong>Input:</strong> s = "leetcode", wordDict = ["leet","code"]
  <strong>Output:</strong> true
  <strong>Explanation:</strong> Return true because "leetcode" can be segmented as "leet code".</pre>
  
  
  <p><strong class="example">Example 2:</strong></p>
  <pre>
  <strong>Input:</strong> s = "applepenapple", wordDict = ["apple","pen"]
  <strong>Output:</strong> true
  <strong>Explanation:</strong> Return true because "applepenapple" can be segmented as "apple pen apple".
  Note that you are allowed to reuse a dictionary word.</pre>

  <p><strong class="example">Example 3:</strong></p>
  <pre>
  <strong>Input:</strong> s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
  <strong>Output:</strong> false</pre>
  
  <p><strong>Constraints:</strong></p>
  <ul>
    <li><code>1 <= s.length <= 300</code></li>
    <li><code>1 <= wordDict.length <= 1000</code></li>
    <li><code>1 <= wordDict[i].length <= 20</code></li>
    <li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
    <li>All the strings of wordDict are <strong>unique</strong>.</li>
  </ul>
