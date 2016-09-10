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
	call append(7, "#define mp make_pair")
	call append(8, "#define pb push_back")
	call append(9, "#define LL long long")
	call append(10, "#define pii pair<int,int>")
	call append(11, "#define PII pair<long long, long long>")
	call append(12, "#define fi first")
	call append(13, "#define se second")
    call append(14, "#define all(x) (x).begin(),(x).end()")
    call append(15, "#define SZ(x) ((int)(x).size())")
	call append(16, "const int inf = 0x7fffffff; //beware overflow")
	call append(17, "const LL  INF = 0x7fffffffffffffff; //beware overflow")
   	call append(18, "#define mem(x, y) memset(x, (y), sizeof(x) ); ")
    call append(19, "#define IOS ios_base::sync_with_stdio(0); cin.tie(0)")
    call append(20, "template<typename A, typename B>")
    call append(21, "ostream& operator <<(ostream &s, const pair<A,B> &p) {")
    call append(22, "   return s<<\"(\"<<p.first<<\",\"<<p.second<<\")\";")
    call append(23, "}")
    call append(24, "template<typename T>")
    call append(25, "ostream& operator <<(ostream &s, const vector<T> &c) {")
    call append(26, "   s << \"[ \";")
    call append(27, "   for (auto it : c) s << it << \" \";")
    call append(28, "   s << \"]\";")
    call append(29, "   return s;")
    call append(30, "}")
    call append(31, "template<typename T>")
    call append(32, "ostream& operator << (ostream &o, const set<T> &st) {")
    call append(33, "   o << \"{\";")
    call append(34, "   for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? \"\" : \", \") << *it;")
    call append(35, "   return o << \"}\";")
    call append(36, "}")
    call append(37, "template<typename T1, typename T2>")
    call append(38, "ostream& operator << (ostream &o, const map<T1, T2> &mp) {")
    call append(39, "    o << \"{\";")
    call append(40, "    for (auto it=mp.begin(); it!=mp.end(); it++) {")
    call append(41, "        o << (it==mp.begin()?\"\":\", \") << it->fi << \":\" << it->se;")
    call append(42, "    }")
    call append(43, "    o << \"}\";")
    call append(44, "    return o;")
    call append(45, "}")
	call append(46, "#define maxn")
	call append(47, "int main() {")
    call append(49, "    return 0;")
    call append(50, "}")
    endif
endfu
" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif
set encoding=utf-8
set fileencoding=utf-8
set termencoding=utf-8

set number
set nocompatible
set hlsearch
set ruler
set cursorline
set background=dark
set showmode
set showmatch

set expandtab
set backspace=2
set shiftwidth=4
set tabstop=4
set softtabstop=4

set autoindent
set smartindent

autocmd FileType python set tw=80 cc=+1
autocmd FileType make set noexpandtab

set pastetoggle=<F2>

nmap <C-S-c> 0i//<Esc>
imap <C-S-c> jj<C-S-c>
nmap <C-S-x> 0xx
imap <C-S-x> jj<C-S-x> 

nmap <bslash>p :set paste!<CR>
nmap <bslash>x mzHmx:silent! :%s/[ \t][ \t]*$//g<CR>`xzt`z
nmap <bslash>t :Tlist<CR>
imap jj <Esc>

autocmd FileType c nmap <F9> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %<<CR>
autocmd FileType c nmap <F11> <ESC>\x:w<CR>:!./%<<CR>
autocmd FileType c nmap <F12> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %< && ./%<<CR>
autocmd FileType c imap <F9> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %<<CR>
autocmd FileType c imap <F11> <ESC>\x:w<CR>:!./%<<CR>
autocmd FileType c imap <F12> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %< && ./%<<CR>

autocmd FileType cpp nmap ff <ESC>\x:w<CR>:!./%<  
autocmd FileType cpp nmap <F9> <ESC>\x:w<CR>:!g++ -D DEBUG -g -std=c++11 % -o %<<CR>
autocmd FileType cpp nmap <F12> <ESC>\x:w<CR>:!g++ -O2 -Wall -std=c++11 % -o %< && ./%<<CR>
autocmd FileType cpp imap ff <ESC>\x:w<CR>:!./%<  
autocmd FileType cpp imap <F9> <ESC>\x:w<CR>:!g++ -D DEBUG -g -std=c++11 % -o %<<CR>  
autocmd FileType cpp imap <F12> <ESC>\x:w<CR>:!g++ -O2 -Wall -std=c++11 % -o %< && ./%<<CR>

autocmd FileType python nmap <F11> <ESC>\x:w<CR>:!./%<CR>
autocmd FileType python nmap <F12> <ESC>\x:w<CR>:!./%<CR>
autocmd FileType python imap <F11> <ESC>\x:w<CR>:!./%<CR>
autocmd FileType python imap <F12> <ESC>\x:w<CR>:!./%<CR>

autocmd FileType tex nmap <F11> <ESC>\x:w<CR>:!gnome-open %<.pdf<CR><CR>
autocmd FileType tex nmap <F12> <ESC>\x:w<CR>:!xelatex %<CR>
autocmd FileType tex imap <F11> <ESC>\x:w<CR>:!gnome-open %<.pdf<CR><CR>
autocmd FileType tex imap <F12> <ESC>\x:w<CR>:!xelatex %<CR>

set fdm=indent
set foldlevel=0
set foldnestmax=1
set foldminlines=7

syntax on
execute pathogen#infect()

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

au FocusLost * :set norelativenumber
au FocusGained * :set relativenumber

function! NumberToggle()
  if(&relativenumber == 1)
    set norelativenumber 
  else
    set relativenumber
  endif
endfunc

nnoremap <C-n> :call NumberToggle()<cr>

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
let g:syntastic_cpp_compiler = 'g++'
let g:syntastic_cpp_compiler_options = ' -std=c++11 '

