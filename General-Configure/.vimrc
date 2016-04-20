autocmd FileType cpp call IoStream()
fu! IoStream()
    if line("$") == 1
        call append(0, "#include <bits/stdc++.h>")
        call append(1, "")
        call append(2, "using namespace std;")
        call append(3, "")
	call append(4, "#define mp make_pair")
	call append(5, "#define pb push_back")
	call append(6, "#define LL long long")
	call append(7, "#define pii pair<int,int>")
	call append(8, "#define PII pair<long long, long long>")
	call append(9, "#define fi first")
	call append(10, "#define se second")
    call append(11, "#define all(x) (x).begin(),(x).end()")
    call append(12, "#define SZ(x) ((int)(x).size())")
	call append(13, "const int inf = 0x7fffffff;")
	call append(14, "const LL  INF = 0x7fffffffffffffff;")
    	call append(15, "const int mod = 1e9+7;")
	call append(16, "typedef vector<int> vec;") 
	call append(17, "typedef vector<vec> mat;")
	call append(18, "#define maxn")
	call append(19, "int main() {")
	call append(20, "#ifdef DEBUG")
	call append(21, "	freopen(\"out\", \"w\", stdout);")
	call append(22, "#endif")
        call append(23, "	return 0;")
        call append(24, "}")
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

set nocompatible
set number
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

"nmap <bslash>p :set paste!<CR>
nmap <bslash>x mzHmx:silent! :%s/[ \t][ \t]*$//g<CR>`xzt`z
nmap ls :!ls<CR>
"nmap <bslash>t :Tlist<CR>
imap jj <Esc>:w<CR>

autocmd FileType c nmap <F9> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %<<CR>
autocmd FileType c nmap <F11> <ESC>\x:w<CR>:!./%<<CR>
autocmd FileType c nmap <F12> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %< && ./%<<CR>
autocmd FileType c imap <F9> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %<<CR>
autocmd FileType c imap <F11> <ESC>\x:w<CR>:!./%<<CR>
autocmd FileType c imap <F12> <ESC>\x:w<CR>:!gcc -O2 -Wall -std=c99 % -o %< && ./%<<CR>

autocmd FileType cpp nmap ff <ESC>\x:w<CR>:!g++ -Wall  -std=c++11 % -o %<<CR>
autocmd FileType cpp nmap <F9> <ESC>\x:w<CR>:!./%<
autocmd FileType cpp nmap <F12> <ESC>\x:w<CR>:!g++ -O2 -Wall -std=c++11 % -o %< && ./%<<CR>
autocmd FileType cpp imap ff <ESC>\x:w<CR>:!g++ -Wall  -std=c++11 % -o %<<CR>
autocmd FileType cpp imap <F19> <ESC>\x:w<CR>:!./%<
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
