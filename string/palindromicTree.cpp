/**
回文自動機包含以下元素:

    狀態St，所有節點的集合，一開始兩個節點，0表示偶數長度串的根和1表示奇數長度串的根
    last 新增加一個字符後所形成的最長回文串的節點編號
    s 當前的字符串(一開始設s[0]=-1(可以是任意一個在串S中不會出現的字符))
    n 表示添加的字符個數


每個節點代表一個不同的回文子字串，我們在每個節點會儲存一些數值:

    len 表示所代表的回文子字串長度
    next[c] 表示所代表的回文子字串在頭尾各增加一個字符c後的回文字串其節點編號
    sufflink 表示所代表的回文子字串不包括本身的最長後綴回文子串的節點編號
    cnt(非必要) 表示所代表的回文子字串在整體字串出現的次數(在建構完成後呼叫count()才能計算)
    //num(非必要) 表示所代表的回文子字串其後綴為回文字串的個數 <== not included
**/
struct palindromic_tree{
	struct node{
		int next[26],sufflink,len; /*這些是必要的元素*/
		int cnt, num;          /*這些是額外維護的元素*/
		node(int l=0):sufflink(0),len(l),cnt(0),num(0){
			for(int i=0;i<26;++i)next[i]=0;
		}
	};
	std::vector<node> St;
	std::vector<char> s;
	int last,n;
	palindromic_tree():St(2),last(1),n(0){
		St[0].sufflink=1;
		St[1].len=-1;
		s.push_back(-1);
	}
	inline void clear(){
		St.clear();
		s.clear();
		last=1;
		n=0;
		St.push_back(0);
		St.push_back(-1);
		St[0].sufflink=1;
		s.push_back(-1);
	}
	inline int get_sufflink(int x){
		while(s[n-St[x].len-1]!=s[n])x=St[x].sufflink;
		return x;
	}
	inline void add(int c){
		s.push_back(c-='a');
		++n;
		int cur=get_sufflink(last);
		if(!St[cur].next[c]){
			int now=St.size();
			St.push_back(St[cur].len+2);
			St[now].sufflink=St[get_sufflink(St[cur].sufflink)].next[c];
			/*不用擔心會找到空節點，由證明的過程可知*/
			St[cur].next[c]=now;
			St[now].num=St[St[now].sufflink].num+1;
		}
		last=St[cur].next[c];
		++St[last].cnt;
	}
	inline void count(){/*cnt必須要在構造完後呼叫count()去計算*/
		std::vector<node>::reverse_iterator i=St.rbegin();
		for(;i!=St.rend();++i){
			St[i->sufflink].cnt+=i->cnt;
		}
	}
	inline int size(){/*傳回其不同的回文子串個數*/
		return St.size()-2;
	}
}ptree;

