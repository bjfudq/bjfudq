# C/C++ 学习笔记

记录一些 C/C++ 的学习笔记

---

### 指针相关

#### 指针的三种值

- 指针的值`p`（即指针指向值的地址）
- 指针的地址`&p`
- 指针指向的值`*p`

```c++
int a = 2;
int *p;
cout << p << endl;  //  指针的值
cout << &p << endl;  //  指针的地址
p = &a;
cout << p << endl;  //  指针的值
cout << &p << endl;
cout << *p << endl;  //  指针指向的值
cout << &a << endl;  //  a 的地址
```

64 位操作系统下，会依次输出：
```
0x7fff5db25b38
0x7fff5db25ac0
0x7fff5db25ac8
0x7fff5db25ac0
2
0x7fff5db25ac8
```

#### 为什么在 64 位操作系统下，地址是由 12 个十六进制字母组成的

64 位操作系统，CPU 只用了 48 位地址来寻址，每 4 位可以用一个十六进制的字母来表示，所以 64 位操作系统下，地址一共由 12 个十六进制字母组成。

另外，32 位操作系统下，CPU 用 32 位地址来寻找，所以地址由 8 个十六进制字母组成。


#### 指针 delete 问题

在指针 delete 之前，记得把指针指向 NULL，否则指针会成为野指针。

delete 一个空指针也是合法的操作。

#### C/C++语言里指针的使用
C：malloc 和 free
```c
int * p = (int *)malloc(sizeof(int));
free(p);
```
C++：new 和 delete
```c++
int * p = new int;
delete p;

int * p = new int[10];
delete [] p;
```

#### 数组指针和指针数组
- 数组指针：指向整型数组的指针，`int (*p)[];`
- 指针数组：数组里存储一系列指针地址，`int *p[];`

---

### 内存对齐问题

#### 如何求结构体的 sizeof

#### 数据类型的 sizeof

![](https://res.jisuanke.com/img/upload/20161122/b73ea5677fd359901f2ec1534d81910055a4c3dd.png)

请讲诉 heap 和 stack 的差别。

解析：在进行 C/C++ 编程时，需要程序员对内存的了解比较精准。经常需要操作的内存可分为以下几个类别：

（1）栈区（stack）：由编译器自动分配和释放，存放函数的参数值、局部变量的值等。其操作方式类似于数据结构中的栈。

（2）堆区（heap）：一般由程序员分配和释放，若程序员不释放，程序结束时可能由操作系统回收。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表

（3）全局区（静态区）（static）：全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和静态变量在相邻的另一块区域。程序结束后由系统释放。

（4）文字常量区：常量字符串就是放在这里的，程序结束后由系统释放。
 
（5）程序代码区：存放函数体的二进制代码。

 答案：

（1）stack的空间由操作系统自动分配/释放，heap上的空间手动分配/释放。
（2）stack空间有限，heap是很大的自由存储区。
（3）C中的malloc函数分配内存空间即在堆上，C++中对应的是new操作符。
（4）程序在编译期对变量和函数分配内存都在栈上进行，且程序运行过程中函数调用时参数的传递也在栈上进行。


### 面向对象

#### 面向对象重写（override）和重载（overload）的区别

#### 什么是虚函数？什么是纯虚函数？

#### const 的用处

#### 静态成员变量和静态成员函数 static

#### 友元函数 友元类 friend

#### 什么是多态？

#### 面向对象三大基本特性，五大基本原则？