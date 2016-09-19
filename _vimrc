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
