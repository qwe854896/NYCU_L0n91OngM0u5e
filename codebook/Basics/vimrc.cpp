"This file should be placed at ~/.vimrc"
se nu ai hls et ru ic is sc cul cindent smartindent autoindent
se re=1 ts=4 sts=4 sw=4 ls=2 mouse=a bg=dark
syntax on
hi cursorline cterm=none ctermbg=89
inoremap {<ENTER> {<ENTER>}<ESC>O
inoremap kj <Esc>
autocmd filetype cpp nnoremap<F5> :w <ENTER> :!g++ % -o %:r && ./%:r <ENTER>
autocmd filetype cpp nnoremap<F6> :!./%:r <ENTER>
