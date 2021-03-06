# Vim

据说不会用 `Vim` 写代码的程序员不是好的程序猿。

#### 配置文件
在终端里打开配置文件：`vim ~/.vimrc`

输入以下内容：
```
:set tabstop=4
:set softtabstop=4
:set shiftwidth=4
:set autoindent
:set cindent
:set nu
:set hlsearch
:set backspace=2
:syntax on
:set smartindent
```
按 `ESC`，输入 `:wq` 保存并退出。

解释：
1. 设置制表符宽度
```
:set tabstop=4
:set softtabstop=4
```
2. 设置缩进的空格数
```
:set shiftwidth=4
```
3. 每行的缩进值与上一行相等
```
:set autoindent
```
4. 使用 `C/C++` 的自动缩进
```
:set cindent
```
5. 显示行号
```
:set nu
```
6. 搜索内容反白
```
:set hlsearch
```
7. 删除任意值
```
:set backspace=2
```
8. 语法高亮显示
```
:syntax on
```
9. 自动缩进
```
:set smartindent
```

#### 光标命令
`h` 向左

`j` 向下

`k` 向上

`l` 向右

`H` 屏幕首行

`nH` 屏幕第 n 行

`M` 屏幕中间行

`L` 屏幕底行

`nL` 屏幕倒数第 n 行

`w` 光标往后跳过一个单词

`b` 光标往前跳过一个单词

`gg` 光标定位到文件第一行

`G` 光标定位到文件最后一行

`nG` 光标移动到第 n 行

`ngg` 光标定位到第 n 行

#### 保存退出命令
`:w` 保存

`:q` 退出

`:wq` 保存并退出

`:q!` 不保存强制退出

`:qa` 退出所有文件

#### 编辑命令
`i` 光标前插入，开始编辑

`I` 在该行行首开始编辑

`a` 光标后插入，开始编辑

`A` 光标定位到当前行末，开始编辑

`o` 在当前行后插入新行，开始编辑

`O` 在当前行前插入新行，开始编辑

#### 删除命令

`x` 删除光标后一个字符

`X` 删除光标前一个字符

`(n)dd` 从当前行开始，删除 n 行，n 为空则删除当前行

`d$`或者`D` 删除从光标位置到该行尾的所有字符

#### 复制粘贴命令

`(n)yy` 从当前行开始，复制 n 行，n 为空则复制当前行

`y0` 复制从光标位置到该行行首的所有字符

`y$`或者`Y` 复制从光标位置到该行行末的所有字符

`p` 在当前行后粘贴

`P` 在当前行前粘贴

#### 撤销命令

`u` 撤销

`U` 自上次移动到当前行以来做过的所有操作，再按一次重复这些操作

#### 重复命令

`.` 重复上一次命令

#### 查找替换命令

查找

`/s` 向下查找字符串 s

`?s` 向上查找字符串 s

`n` 查看下一个

`N` 反向查看下一个

替换

`:s/temp/str/` 替换当前行第一个 `temp` 为 `str`

`:s/temp/str/g` 替换当前行所有 `temp` 为 `str`

`:n, $s/temp/str/` 替换第 `n` 行开始到最后一行中每一行的第一个 `temp` 为 `str`

`:n, $s/temp/str/g` 替换第 `n` 行开始到最后一行中每一行所有 `temp` 为 `str`，`n` 为数字，若 `n` 为 `.`，表示从当前行开始到最后一行

`:%s/temp/str/`（等同于 `:g/temp/s//str/`） 替换每一行的第一个 `temp` 为 `str`

`:%s/temp/str/g`（等同于 `:g/temp/s//str/g`） 替换每一行中所有 `temp` 为 `str`

#### 其它

`J` 合并当前行和下一行

`:sp + filename` 在当前文件上方打开一个窗口，显示文件 `filename`

`:vs + filename` 在当前文件左方打开一个窗口，显示文件 `filename`

两下 `Ctrl + w` 切换窗口

配置文件里添加`set expandtab`/`set noexpandtab`：将`tab`扩展/不扩展成空格
