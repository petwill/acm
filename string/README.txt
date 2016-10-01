字串比對的策略：

一、T與P的最長共同前綴（Longest Common Prefix）
　適用情況：T為定值，P為變動值。
　單一字串匹配：Gusfield's Algorithm(z algorithm)。（P為定值，T為變動值。）
　單一、多重字串匹配：Suffix Array + Binary Search、Suffix Trie、Suffix Tree。
　特色：LCP Array。

二、P本身的次長相同前綴後綴（Longest Proper Prefix-Suffix）（Border）
　適用情況：P為定值，T為變動值。
　單一字串匹配：Morris-Pratt Algorithm。
　多重字串匹配：Aho-Corasick Algorithm。
　特色：可以轉換成自動機。
