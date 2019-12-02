set nocompatible              " be iMproved, required
filetype off                  " required


" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

Bundle 'altercation/vim-colors-solarized'
Plugin 'vim-scripts/OmniCppComplete'
Plugin 'Valloric/YouCompleteMe'

"mine
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'
Plugin 'Chiel92/vim-autoformat'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

syntax enable
colorscheme monokai

map <C-n> :NERDTree<CR>

"astyle
"let g:formatdef_allman = '"astyle --style=allman --pad-oper"'
"let g:formatters_cpp = ['allman']
"let g:formatters_c = ['allman']

"auto-format
""F5自动格式化代码并保存
"au BufWrite * :Autoformat
noremap <F5> :Autoformat<CR>:w<CR>
let g:autoformat_verbosemode=1

set autoindent  "自动缩进
set cindent  "C自动缩进
set shiftwidth=4 "自动缩进空白字符个数
set softtabstop=4 "tab键的一个制表符，如果softtabstop=5,tabstop=4,则tab是1个制表符加1个空格的混合
set tabstop=4 "tab键的空格数
set nu  "默认设置行号

let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'

"test
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 一般设定
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 设定默认解码
set fenc=utf-8
set fencs=utf-8,usc-bom,euc-jp,gb18030,gbk,gb2312,cp936

" 不要使用vi的键盘模式，而是vim自己的
set nocompatible

" history文件中需要记录的行数
set history=100

" 在处理未保存或只读文件的时候，弹出确认
set confirm

" 与windows共享剪贴板
set clipboard+=unnamed

" 侦测文件类型
filetype on

" 载入文件类型插件
filetype plugin on

" 为特定文件类型载入相关缩进文件
filetype indent on

" 保存全局变量
set viminfo+=!

" 带有如下符号的单词不要被换行分割
set iskeyword+=_,$,@,%,#,-

" 语法高亮
syntax on

" 高亮字符，让其不受100列限制
:highlight OverLength ctermbg=red ctermfg=white guibg=red guifg=white
:match OverLength '\%101v.*'

" 状态行颜色
highlight StatusLine guifg=SlateBlue guibg=Yellow
highlight StatusLineNC guifg=Gray guibg=White

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 文件设置
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 不要备份文件（根据自己需要取舍）
set nobackup

" 不要生成swap文件，当buffer被丢弃的时候隐藏它
setlocal noswapfile
set bufhidden=hide

" 字符间插入的像素行数目
set linespace=0

" 增强模式中的命令行自动完成操作
set wildmenu

" 在状态行上显示光标所在位置的行号和列号
set ruler
set rulerformat=%20(%2*%<%f%=\ %m%r\ %3l\ %c\ %p%%%)

" 命令行（在状态行下）的高度，默认为1，这里是2
set cmdheight=2

" 使回格键（backspace）正常处理indent, eol, start等
set backspace=2

" 允许backspace和光标键跨越行边界
set whichwrap+=<,>,h,l

" 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）
set mouse=a
set selection=exclusive
set selectmode=mouse,key

" 启动的时候不显示那个援助索马里儿童的提示
set shortmess=atI

" 通过使用: commands命令，告诉我们文件的哪一行被改变过
set report=0

" 不让vim发出讨厌的滴滴声
set noerrorbells

" 在被分割的窗口间显示空白，便于阅读
set fillchars=vert:\ ,stl:\ ,stlnc:\

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 搜索和匹配
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 高亮显示匹配的括号
set showmatch

" 匹配括号高亮的时间（单位是十分之一秒）
set matchtime=5

" 在搜索的时候忽略大小写
set ignorecase

" 不要高亮被搜索的句子（phrases）
set nohlsearch

" 在搜索时，输入的词句的逐字符高亮（类似firefox的搜索）
set incsearch

" 输入:set list命令是应该显示些啥？
set listchars=tab:\|\ ,trail:.,extends:>,precedes:<,eol:$

" 光标移动到buffer的顶部和底部时保持3行距离
set scrolloff=3

" 不要闪烁
set novisualbell

" 我的状态行显示的内容（包括文件类型和解码）
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}

" 总是显示状态行
set laststatus=2

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 文本格式和排版
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 自动格式化
set formatoptions=tcrqn

" 继承前一行的缩进方式，特别适用于多行注释
set autoindent

" 为C程序提供自动缩进
set smartindent

" 使用C样式的缩进
" set cindent

" 制表符为4
set tabstop=4

" 统一缩进为4
" set softtabstop=4
set shiftwidth=4

" 不要用空格代替制表符
set expandtab
" 如果改成set noexpandtab就是不用四个空格代替一个table

" 不要换行
set nowrap

" 在行和段开始处使用制表符
set smarttab

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" CTags的设定
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 按照名称排序
let Tlist_Sort_Type = "name"

" 在右侧显示窗口
let Tlist_Use_Right_Window = 1

" 压缩方式
let Tlist_Compart_Format = 1

" 如果只有一个buffer，kill窗口也kill掉buffer
let Tlist_Exist_OnlyWindow = 1

" 不要关闭其他文件的tags
let Tlist_File_Fold_Auto_Close = 0

" 不要显示折叠树
let Tlist_Enable_Fold_Column = 0

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Autocommands
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 只在下列文件类型被侦测到的时候显示行号，普通文本文件不显示

if has("autocmd")
    autocmd FileType xml,html,c,cs,java,perl,shell,bash,cpp,python,vim,php,ruby set number
    autocmd FileType xml,html vmap <C-o> <ESC>'<i<!--<ESC>o<ESC>'>o-->
    autocmd FileType java,c,cpp,cs vmap <C-o> <ESC>'<o/*<ESC>'>o*/
    autocmd FileType html,text,php,vim,c,java,xml,bash,shell,perl,python setlocal textwidth=100
    autocmd Filetype html,xml,xsl source $VIMRUNTIME/plugin/closetag.vim
    autocmd BufReadPost *
                \ if line("'\"") > 0 && line("'\"") <= line("$") |
                \   exe "normal g`\"" |
                \ endif
endif " has("autocmd")

" F5编译和运行C程序，F6编译和运行C++程序
" 请注意，下述代码在windows下使用会报错
" 需要去掉./这两个字符

" C的编译和运行

func! CompileRunGcc()
    exec "w"
    silent exec "!gcc % -o %<"
    exec "! ./%<"
endfunc

" C++的编译和运行

func! CompileRunGpp()
    exec "w"
    silent exec "!g++ % -o %<"
    exec "! ./%<"
endfunc

func! CompileCode()
    if &filetype == "c"
        exec "call CompileRunGcc()"
    elseif &filetype == "cpp"
        exec "call CompileRunGpp()"
    endif
endfunc
map<F6> :call CompileCode()<CR>

"map <F4> :call TitleDet2() <cr>
function AddTitle2()
    call append(0,"/************************************************************")
    call append(1," * Author        : huamin.wang")
    call append(2," * Email         : wanghm@greenet.net.cn")
    call append(3," * Last modified : ".strftime("%Y-%m-%d %H:%M"))
    call append(4," * Filename      : ".expand("%:t"))
    call append(5," * Description   :" )
    call append(6," * *********************************************************/")
    echohl WarningMsg |echo "Successful in adding the copyright." | echohl None
endf

function UpdateTitle2()
    normal m'
    execute '/# *Last modified:/s@:.*$@\=strftime(":\t%Y-%m-%d %H:%M")@'
    normal ''
    normal mk
    execute '/# *Filename:/s@:.*$@\=":\t\t".expand("%:t")@'
    execute "noh"
    normal 'k
    echohl WarningMsg | echo "Successful in updating the copy right." | echohl None
endfunction

function TitleDet2()
    let n=1
    while n < 7
        let line = getline(n)
        if line =~ '^\#\s*\S*Last\smodified:\S*.*$'
            call UpdateTitle2()
            return
        endif
        let n = n+1
    endwhile
    call AddTitle2()
endfunction

"autocmd BufNewFile *.c,*.py,*.cpp,*.sh,*.java exec ":call SetTitle()"
func SetTitle()

    if &filetype == 'sh'
        call setline(1,"\#!/bin/bash")
        call append(line("."), "# Author: xiaxiaosheng")
        call append(line(".")+1, "# Created Time: ".strftime("%c"))
        call append(line(".")+2, "")
    elseif &filetype == 'cpp'
        call setline(1,"// File Name: ".expand("%"))
        call append(line("."), "// Author: xiaxiaosheng")
        call append(line(".")+1, "// Created Time: ".strftime("%c"))
        call append(line(".")+2, "")
        call append(line(".")+3, "#include<vector>")
        call append(line(".")+4, "#include<list>")
        call append(line(".")+5, "#include<map>")
        call append(line(".")+6, "#include<set>")
        call append(line(".")+7, "#include<deque>")
        call append(line(".")+8, "#include<stack>")
        call append(line(".")+9, "#include<bitset>")
        call append(line(".")+10, "#include<algorithm>")
        call append(line(".")+11, "#include<functional>")
        call append(line(".")+12, "#include<numeric>")
        call append(line(".")+13, "#include<utility>")
        call append(line(".")+14, "#include<sstream>")
        call append(line(".")+15, "#include<iostream>")
        call append(line(".")+16, "#include<iomanip>")
        call append(line(".")+17, "#include<cstdio>")
        call append(line(".")+18, "#include<cmath>")
        call append(line(".")+19, "#include<cstdlib>")
        call append(line(".")+20, "#include<cstring>")
        call append(line(".")+21, "#include<ctime>")
        call append(line(".")+22, "")
        call append(line(".")+23, "using namespace std;")
        call append(line(".")+24, "")
        call append(line(".")+25, "int main(){")
        call append(line(".")+26,"")
        call append(line(".")+27, "return 0;")
        call append(line(".")+28, "}")

    elseif &filetype == 'python'
        call setline(1,"\#!/usr/bin/env python")
        call append(line("."), "# Author: xiaxiaosheng")
        call append(line(".")+1, "# Created Time: ".strftime("%c"))
        call append(line(".")+2, "")
    elseif &filetype == 'c'
        call setline(1,"// File Name: ".expand("%"))
        call append(line("."), "// Author: xiaxiaosheng")
        call append(line(".")+1, "// Created Time: ".strftime("%c"))
        call append(line(".")+2, "")
        call append(line(".")+3,"#include<stdio.h>")
        call append(line(".")+4,"#include<string.h>")
        call append(line(".")+5,"#include<stdlib.h>")
        call append(line(".")+6,"#include<time.h>")
        call append(line(".")+7,"#include<math.h>")
        call append(line(".")+8,"")
        call append(line(".")+9,"int main(){")
        call append(line(".")+10,"")
        call append(line(".")+11,"return 0 ;")
        call append(line(".")+12,"}")
    else
        call setline(1,"/*")
        call append(line("."), "* Author: rechen")
        call append(line(".")+1, "* Created Time: ".strftime("%c"))
        call append(line(".")+2, "*/")
        call append(line(".")+3, "")
    endif

    autocmd BufNewFile * normal G
endfunc




" 能够漂亮地显示.NFO文件
set encoding=utf-8
function! SetFileEncodings(encodings)
    let b:myfileencodingsbak=&fileencodings
    let &fileencodings=a:encodings
endfunction
function! RestoreFileEncodings()
    let &fileencodings=b:myfileencodingsbak
    unlet b:myfileencodingsbak
endfunction

au BufReadPre *.nfo call SetFileEncodings('cp437')|set ambiwidth=single
au BufReadPost *.nfo call RestoreFileEncodings()

" 高亮显示普通txt文件（需要txt.vim脚本）
au BufRead,BufNewFile * setfiletype txt

" 用空格键来开关折叠
set foldenable
set foldmethod=manual
nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR>

" minibufexpl插件的一般设置
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplModSelTarget = 1
