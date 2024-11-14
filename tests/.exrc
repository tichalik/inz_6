if &cp | set nocp | endif
map  :s/^/std::cout << __FILE__ << "::" << __LINE__ << std::endl;\r
map  :%s/std::cout << __FILE__ << "::" << __LINE__ << std::endl;\n/
map  :s/^/\/\/
let s:cpo_save=&cpo
set cpo&vim
map <NL> :s/^\/\//
vnoremap  "hy:%s/h//gc<Left><Left><Left>
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
xnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
vnoremap <C-R> "hy:%s/h//gc<Left><Left><Left>
map <F3> :Termdebug L
map <F2> :packadd termdebug  
map <C-G> :%s/std::cout << __FILE__ << "::" << __LINE__ << std::endl;\n/
map <C-F> :s/^/std::cout << __FILE__ << "::" << __LINE__ << std::endl;\r
map <C-J> :s/^\/\//
map <C-H> :s/^/\/\/
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set printoptions=paper:a4
set ruler
set shiftwidth=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set wildmenu
" vim: set ft=vim :
