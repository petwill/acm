//kmp algorithm, O(T + P)
// p[0...i] 的「次長的相同前後綴」是 p[0...failure[i]]。
// 值為 -1 時，代表「次長的相同前後綴」不存在。

/*
    使用 DP 來計算 failure function。
    分割問題的方式：把 p[0...i] 的最後一個字元拿掉，
    然後利用已求得的「次長的相同前後綴」來求答案。
*/
#include <bits/stdc++.h>
using namespace std;

int failure[100];   // P進行大幅移動後，所要對準的位置。

void KMP(string& t, string& p)
{
    // 預先算 P 的 failure function，O(P)。
    for (int i = 1, j = failure[0] = -1; i < p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i]) j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }

    // 進行字串比對，O(T)。
    for (int i = 0, j = -1; i < t.size(); ++i)
    {
        // 先試 p[0...j] 的「最長的相同前後綴」，
        // 再試「次長的相同前後綴」、「次次長的相同前後綴」……
        while (j >= 0 && p[j+1] != t[i]) j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1) cout << "位置" << i - p.size() + 1 << "開始出現P" << endl;
    }
}
int main() {
    string p, t;
    cin>>p>>t;
    KMP(t, p);
}
//kmp algorithm, O(T + P)
// p[0...i] 的「次長的相同前後綴」是 p[0...failure[i]]。
// 值為 -1 時，代表「次長的相同前後綴」不存在。

/*
    使用 DP 來計算 failure function。
    分割問題的方式：把 p[0...i] 的最後一個字元拿掉，
    然後利用已求得的「次長的相同前後綴」來求答案。
*/
#include <bits/stdc++.h>
using namespace std;

int failure[100];   // P進行大幅移動後，所要對準的位置。

void KMP(string& t, string& p)
{
    // 預先算 P 的 failure function，O(P)。
    for (int i = 1, j = failure[0] = -1; i < p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i]) j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }

    // 進行字串比對，O(T)。
    for (int i = 0, j = -1; i < t.size(); ++i)
    {
        // 先試 p[0...j] 的「最長的相同前後綴」，
        // 再試「次長的相同前後綴」、「次次長的相同前後綴」……
        while (j >= 0 && p[j+1] != t[i]) j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1) cout << "位置" << i - p.size() + 1 << "開始出現P" << endl;
    }
}
int main() {
    string p, t;
    cin>>p>>t;
    KMP(t, p);
}
//kmp algorithm, O(T + P)
// p[0...i] 的「次長的相同前後綴」是 p[0...failure[i]]。
// 值為 -1 時，代表「次長的相同前後綴」不存在。

/*
    使用 DP 來計算 failure function。
    分割問題的方式：把 p[0...i] 的最後一個字元拿掉，
    然後利用已求得的「次長的相同前後綴」來求答案。
*/
#include <bits/stdc++.h>
using namespace std;

int failure[100];   // P進行大幅移動後，所要對準的位置。

void KMP(string& t, string& p)
{
    // 預先算 P 的 failure function，O(P)。
    for (int i = 1, j = failure[0] = -1; i < p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i]) j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }

    // 進行字串比對，O(T)。
    for (int i = 0, j = -1; i < t.size(); ++i)
    {
        // 先試 p[0...j] 的「最長的相同前後綴」，
        // 再試「次長的相同前後綴」、「次次長的相同前後綴」……
        while (j >= 0 && p[j+1] != t[i]) j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1) cout << "位置" << i - p.size() + 1 << "開始出現P" << endl;
    }
}
int main() {
    string p, t;
    cin>>p>>t;
    KMP(t, p);
}
//kmp algorithm, O(T + P)
// p[0...i] 的「次長的相同前後綴」是 p[0...failure[i]]。
// 值為 -1 時，代表「次長的相同前後綴」不存在。

/*
    使用 DP 來計算 failure function。
    分割問題的方式：把 p[0...i] 的最後一個字元拿掉，
    然後利用已求得的「次長的相同前後綴」來求答案。
*/
#include <bits/stdc++.h>
using namespace std;

int failure[100];   // P進行大幅移動後，所要對準的位置。

void KMP(string& t, string& p)
{
    // 預先算 P 的 failure function，O(P)。
    for (int i = 1, j = failure[0] = -1; i < p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i]) j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }

    // 進行字串比對，O(T)。
    for (int i = 0, j = -1; i < t.size(); ++i)
    {
        // 先試 p[0...j] 的「最長的相同前後綴」，
        // 再試「次長的相同前後綴」、「次次長的相同前後綴」……
        while (j >= 0 && p[j+1] != t[i]) j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1) cout << "位置" << i - p.size() + 1 << "開始出現P" << endl;
    }
}
int main() {
    string p, t;
    cin>>p>>t;
    KMP(t, p);
}
