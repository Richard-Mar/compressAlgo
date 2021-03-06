# `lz77`编码

## Intro

```markdown
LZ77算法是由 Lempel-Ziv 在1977发明的，也是GBA内置的压缩算法。LZ77算法有许多派生算法(这里面包括 LZSS算法)。它们的算法原理上基本都相同，无论是哪种派生算法，LZ77算法总会包含一个动态窗口（Sliding Window）和一个预读缓冲器（Read Ahead Buffer）。
lz77严格意义上来说不是一种算法而是一种编码理论。
```

## Content

```markdown
Lempel Zip（LZ）编码是称为基于字典的编码的那一类算法的一个例子，它是用其发明者的名字（Abraham Lempel 和 Jacob Ziv）命名的。在通信会话的时候它将会产生一个字符串字典。如果接受和发送双方都有这样的字典，那么字符串可以由字典中的索引代替，以减少通信的数据的传输量。这种算法有不同的版本（LZ77、LZ78等）。
—— 《计算机科学导论 第三版》
```

## Algo

```markdown
算法思想

压缩：以纯英文字符串为例，逐个遍历每个字符串，如果当前字典表中还没有该字符，则将该字符加入字典中，键为该字符，值为生成器返回的数字，若有当前字符，则继续加入下一个字符，此时便有两个字符组成了字符串，判断该字符串是否在当前字典中，如果在，则继续添加下一个字符，组成新的字符串，如果不在，则将该字符串加入字典。最终构成的输出字符串，是用字典中的值代替字符串+末尾字符的形式。

解压：传入字符串是数字+字符构成的，故取其中的数字和字符来构建字典，再反向通过查找字典，将传入字符串中的数字用字符串来代替。
```



## Ref

[1\][LZ - 算法](https://zhuanlan.zhihu.com/p/220384402)

