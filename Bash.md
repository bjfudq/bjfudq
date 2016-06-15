# Bash
------

据说不会写 `Bash` 脚本的程序员不是好的程序猿。

#### 输出 Hello World
`echo Hello World`

#### 变量名命名
`str=abc`

#### 变量名使用
`\$str`

#### `for` 循环
```
for i in a b c
do
    echo \$i
done
```

#### 访问当前目录下所有文件
```
for i in *
do
    echo \$i
done
```

#### 访问文件 `a.txt` 里所有内容
```
t=1
while read line
do
    echo \$t \$line
    ((t++))
done < a.txt
```

#### 访问指定目录 `root/data` 下所有文件
```
for i in `ls root/data`
do
    if [ -d root/data/\$i] #判断是否是子文件夹
    then
        echo \$i is dir
    else
        echo \$i is file
    fi
done
```

#### 遍历 `10` 个数
```
for ((i=0;i<10;i++))
do
    echo \$i
done
```

#### 有关字符串操作
`s1=\${str%_*}` #从左往右，取字符串 `str` 中第一个 `'_'` 前的子串

`s2=\${str#*_}` #从右往左，取字符串 `str` 中第一个 `'_'` 后的子串

[Bash 字符串操作小结](http://www.cnblogs.com/frydsh/p/3261012.html)

#### 运行 `/root/demo` 里的 `run.sh`
```
/root/demo/run.sh #最前面不需要加 '.'
```

#### 整数比较大小：
* 相同  `-eq`
* 不同  `-ne`
* 大于  `-gt`
* 小于  `-lt`
* 大于等于  `-ge`
* 小于等于  `-le`

#### 字符串比较大小
* 相同  `=`
* 不同  `!=`
* 大于  `>`
* 小于  `<`
* 为空  `-z`
* 不为空  `-n`

#### 文件属性判断
当运算符满足以下要求时返回 `true`
* `-e file` 文件 file 已经存在
* `-f file` 文件 file 是普通文件
* `-s file` 文件 file 大小不为零
* `-d file` 文件 file 是一个目录
* `-r file` 文件 file 对当前用户可以读取
* `-w file` 文件 file 对当前用户可以写入
* `-x file` 文件 file 对当前用户可以执行
* `-g file` 文件 file 的 GID 标志被设置
* `-u file` 文件 file 的 UID 标志被设置
* `-O file` 文件 file 是属于当前用户的
* `-G file` 文件 file 的组 ID 和当前用户相同
* `file1 -nt file2` 文件 file1 比 file2 更新
* `file1 -ot file2` 文件 file1 比 file2 更老

#### 退出
`exit n`

`n` 是退出码：

* 0 表示成功（Zero - Success）
* 非 0 表示失败（Non-Zero  - Failure）
* 2 表示用法不当（Incorrect Usage）
* 127 表示命令没有找到（Command Not Found）
* 126 表示不是可执行的（Not an executable）
* \>=128 信号产生

#### 运算操作
一般使用 `let` 和 `expr` 这两个指令来实现。

#### 变量 i 加 1 的几种写法：
```
((i++))
let i=\$i+1
let "i = \$i + 1"
i=`expr \$i + 1`
if ((\$t%2 == 0)) #判断 t 能否被 2 整除
```

#### LeetCode 193. Valid Phone Numbers
用 bash 从文本文件 file.txt 里逐行读取电话号码。

符合下列两种格式的为有效电话号码：`(xxx) xxx-xxxx` 和 `xxx-xxx-xxxx`. (x 代表 0 - 9 之间的数字)

文本文件中的每一行都不包含前导或者后缀空格。

例如，如果 file.txt 包含下面的内容：
```
987-123-4567
123 456 7890
(123) 456-7890
```
程序应该输出下列有效的电话号码：
```
987-123-4567
(123) 456-7890
```

考查 Bash 的正则表达式匹配，参考代码如下：
```
cat file.txt | grep -Eo '^\([0-9]{3}\) [0-9]{3}-[0-9]{4}\$|^([0-9]{3}-){2}[0-9]{4}
$'
```
--------
