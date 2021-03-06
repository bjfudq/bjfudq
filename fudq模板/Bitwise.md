## 位运算总结

总结来自：http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/

---

#### 6 种基础的位运算
```
&   -  bitwise and
|   -  bitwise or
^   -  bitwise xor
~   -  bitwise not
<<  -  bitwise shift left
>>  -  bitwise shift right
```

---

#### 1. Check if the integer is even or odd.

判断整数奇偶性。

```
if ((x & 1) == 0) {
    x is even
}
else {
    x is odd
}
```

**Sample1**
```
    00101011
&   00000001   (note: 1 is the same as 00000001)
    --------
    00000001
```

**Sample2**
```
    01100010
&   00000001
    --------
    00000000
```

---

#### 2. Test if the n-th bit is set.

查看整数的第 n 位上是否是 1。

```
if (x & (1<<n)) {
    n-th bit is set
}
else {
    n-th bit is not set
}
```

**Sample1**

查看 122 二进制的第 3 位上是否是 1。

```
    01111010      (122 in binary)
&   00001000      (1 << 3)
    --------
    00001000
```

**Sample2**

查看 -33 二进制的第 5 位上是否是 1。

```
    11011111      (-33 in binary)
&   00100000      (1 << 5)
    --------
    00000000
```

---

#### 3. Set the n-th bit.

将整数 x 的第 n 位设为 1。

```
y = x | (1 << n)
```

**Sample1**

将 120 的第 2 位设为 1。

```
    01111000    (120 in binary)
|   00000100    (1 << 2)
    --------
    01111100
```

**Sample2**

将 -120 的第 6 位设为 1。

```
    10001000   (-120 in binary)
|   01000000   (1 << 6)
    --------
    11001000
```

---

#### 4. Unset the n-th bit.

将整数 x 的第 n 位设为 0。

```
y = x & ~(1 << n)
```

**Sample**

```
    01111111    (127 in binary)
&   11101111    (~(1 << 4))
    --------
    01101111
```

---

#### 5. Toggle the n-th bit.

将整数 x 的第 n 位取反。

```
y = x ^ (1 << n)
```

**Sample1**

```
    01110101
^   00100000
    --------
    01010101
```

**Sample2**

```
    01010101
^   00100000
    --------
    01110101
```

---

#### 6. Turn off the rightmost 1-bit.

将 x 最右边的 1 设为 0。

```
y = x & (x - 1)
```

**Samples**

```
    01010111    (x = 01010111)
&   01010110    (x - 1)
    --------
    01010110

    01011000    (x = 01011000)
&   01010111    (x-1)
    --------
    01010000

    10000000    (x = -128)
&   01111111    (x - 1 = 127 (with overflow))
    --------
    00000000

    11111111    (x = all bits 1)
&   11111110    (x - 1)
    --------
    11111110

    00000000    (x = no rightmost 1-bits)
&   11111111    (x - 1)
    --------
    00000000
```

---

#### 7. Isolate the rightmost 1-bit.

将 x 最右边的 1 单独取出来。

```
y = x & (-x)
```

**Samples**

```
    10111100  (x)
&   01000100  (-x)
    --------
    00000100

    01110000  (x)
&   10010000  (-x)
    --------
    00010000

    00000001  (x)
&   11111111  (-x)
    --------
    00000001

    10000000  (x = -128)
&   10000000  (-x = -128)
    --------
    10000000

    11111111  (x = all bits one)
&   00000001  (-x)
    --------
    00000001

    00000000  (x = all bits 0, no rightmost 1-bit)
&   00000000  (-x)
    --------
    00000000
```

---

#### 8. Right propagate the rightmost 1-bit.

将 x 最右边的 1 后面的 0 都置为 1。

```
y = x | (x - 1)
```

**Samples**

```
    10111100  (x)
|   10111011  (x - 1)
    --------
    10111111

    01110111  (x)
|   01110110  (x - 1)
    --------
    01110111

    00000001  (x)
|   00000000  (x - 1)
    --------
    00000001

    10000000  (x = -128)
|   01111111  (x - 1 = 127)
    --------
    11111111

    11111111  (x = -1)
|   11111110  (x - 1 = -2)
    --------
    11111111

    00000000  (x)
|   11111111  (x - 1)
    --------
    11111111
```

---

#### 9. Isolate the rightmost 0-bit.

设 p 为整数 x 最右边 0 的位置，y 则为`1 << p`。

```
y = ~x & (x + 1)
```

**Samples**

```
    10111100  (x)
    --------
    01000011  (~x)
&   10111101  (x + 1)
    --------
    00000001

    01110111  (x)
    --------
    10001000  (~x)
&   01111000  (x + 1)
    --------
    00001000

    00000001  (x)
    --------
    11111110  (~x)
&   00000010  (x + 1)
    --------
    00000010

    10000000  (x = -128)
    --------
    01111111  (~x)
&   10000001  (x + 1)
    --------
    00000001

    11111111  (x = no rightmost 0-bit)
    --------
    00000000  (~x)
&   00000000  (x + 1)
    --------
    00000000

    00000000  (x)
    --------
    11111111  (~x)
&   00000001  (x + 1)
    --------
    00000001
```

---

#### 10. Turn on the rightmost 0-bit.

将 x 最右边的 0 置为 1。

```
y = x | (x + 1)
```

**Samples**

```
    10111100  (x)
|   10111101  (x + 1)
    --------
    10111101

    01110111  (x)
|   01111000  (x + 1)
    --------
    01111111

    00000001  (x)
|   00000010  (x + 1)
    --------
    00000011

    10000000  (x = -128)
|   10000001  (x + 1)
    --------
    10000001

    11111111  (x = no rightmost 0-bit)
|   00000000  (x + 1)
    --------
    11111111

    00000000  (x)
|   00000001  (x + 1)
    --------
    00000001
```

---
