autocmd FileType cpp call IoStream()
fu! IoStream()
    if line("$") == 1
    call append(0, "#include <bits/stdc++.h>")
    call append(1, "using namespace std;")
    call append(2, "#ifdef DEBUG")
    call append(3, "    #define debug(...) printf(__VA_ARGS__)")
    call append(4, "#else")
    call append(5, "    #define debug(...) (void)0")
    call append(6, "#endif")
	call append(7, "#define LL long long")
    call append(8, "#define SZ(x) ((int)(x).size())")
	call append(9, "//const int inf = 0x7fffffff; //beware overflow")
	call append(10, "//const LL INF = 0x7fffffffffffffff; //beware overflow")
    call append(11, "#define IOS ios_base::sync_with_stdio(0); cin.tie(0)") 
    call append(12, "template<typename A, typename B>")
    call append(13, "ostream& operator <<(ostream &s, const pair<A,B> &p) {")
    call append(14, "     return s<<\"(\"<<p.first<<\",\"<<p.second<<\")\";")
    call append(15, "}")
    call append(16, "template<typename T>")
    call append(17, "ostream& operator <<(ostream &s, const vector<T> &c) {")
    call append(18, "    s << \"[ \";")
    call append(19, "    for (auto it : c) s << it << \" \";")
    call append(20, "    s << \"]\";")
    call append(21, "    return s;")
    call append(22, "}")
    call append(23, "template<typename T>")
    call append(24, "ostream& operator << (ostream &o, const set<T> &st) {")
    call append(25, "    o << \"{\";")
    call append(26, "    for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? \"\" : \", \") << *it;")
    call append(27, "    return o << \"}\";")
    call append(28, "}")
    call append(29, "template<typename T1, typename T2>")
    call append(30, "ostream& operator << (ostream &o, const map<T1, T2> &mp) {")
    call append(31, "    o << \"{\";")
    call append(32, "    for (auto it=mp.begin(); it!=mp.end(); it++) {")
    call append(33, "        o << (it==mp.begin()?\"\":\", \") << it->first << \":\" << it->second;")
    call append(34, "    }")
    call append(35, "    o << \"}\";")
    call append(36, "    return o;")
    call append(37, "}")
    call append(38,"inline LL getint(){")
    call append(39, "   LL _x=0,_tmp=1; char _tc=getchar();")    
    call append(40, "   while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();")
    call append(41, "   if( _tc == '-' ) _tc=getchar() , _tmp = -1;")
    call append(42, "   while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();")
    call append(43, "   return _x*_tmp;")
    call append(44, "}") 
	call append(45, "#define maxn")
	call append(46, "int main() {")
    call append(47, "}")
    endif
endfu
  

imap jj <Esc>

sy on
se sw=4 ts=4 sts=4 et nu sc hls cc=69
filet plugin indent on
nm <F5> :!"./%<"<CR>
nm <F6> :!"./%<" < input.txt<CR>
au FileType cpp no <F9> :!g++ % -o
 \ %< -std=c++14 -O3 -Wall -Wextra
 \ -Wshadow -Wno-unused-result<CR>
no <expr> <silent> <Home> col('.') ==
 \ match(getline('.'),'\S') + 1
 \ ? '0' : '^'
im <silent> <Home> <C-O><Home>
