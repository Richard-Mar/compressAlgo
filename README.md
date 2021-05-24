# 项目介绍

此项目为生物计算编程2021春季学期大作业

group_index：6

contributors：马睿锋、阿克卓力、白杰

## 一、项目介绍

### 1.来源

大作业项目来源于大作业选题一：

### 2.项目背景与意义

​		DNA测序在许多生物信息学应用中发挥着重要的作用,而测序技术正在开发和生产测序数据的速度随着技术进步的同时飞速加快，而下一代高通量测序技术的发展显著降低了测序成本，这使得测序数据文件的大小和生成速度指数级上升，这些技术在一次运行中会产生大量的数据，这在将来将会增加，并可能超过存储容量的限制。越来越庞大的数据量对于存储的硬件而言是一个亟需解决的新的问题。
​		

​		通过压缩算法减少数据文件大小，减少存储需求是一条解决该问题的合理途径，对于DNA而言也存在其合理性和必要性，DNA序列中，存在大量的冗余、重复片段，可以利用合适的算法进行压缩，减小数据文件大小。然而，传统的压缩算法压缩效率不高，压缩增益低，没有利用到DNA序列的冗余特性和数据特征。

​		`SeqCompress` 算法 [1] ，相比传统压缩算法而言，其基于统计模型与算术编码的特性，能很好地处理以 `fasta\fastq` 格式存储的DNA序列，利用到DNA的冗余性和ATCG 序列的存储特征，具有较好的压缩增益。
​		`Optimal Seed Based Compression Algorithm` 算法 [2] 是一种基于种子的压缩算法，可以识别并匹配子字符串，并双向扩展，通过设定阈值，确定扩展终止的条件，然后删除扩展的子序列，并将其余符号链接起来，形成新的序列，记录种子的入口位置信息，实现数据量的压缩。

​		我们计划通过研究以上算法在C框架下的实现，讨论分析算法的复杂度，并于传统压缩算法进行比较，对比其压缩增益、解压、压缩时间等指标，确定各个算法的优缺点，并尝试改进算法。

### 3.相关工作

1. DNA序列压缩算法可以分为有损算法或无损算法。这些算法可以是标准模式、垂直模式或水平模式。传统的基于文本的压缩算法遵循标准的文本压缩方法。然而，这些算法不能利用生物数据中的冗余性。这种算法的例子包括 `gzip `和` bzip2` 。
2. `DNACompress` 算法也是基于匹配机制的压缩算法，识别显著的近似重复区域，然后通过指向它们早期发生的指针对这些重复区域进行编码。非重复区域也使用算术编码进行编码。从而实现数据量的减少。

## 二、研究方法

### 1.研究方法

- 系统平台： `CentOS 7 Ubuntu 20.04`
- 编程框架：C语言、Python 应用包： `matplotlib.pyplot`
  通过C语言实现DNA压缩算法，Python进行算法复杂度的可视化与数据分析。

### 2.计划步骤

```markdown
1. 阅读文献，查阅已有的研究方法
2. 确定思路，选择一组算法为主要模板，尝试进行应用。
3. 参考已有的算法进行改进，寻求更高的压缩率或者是更快速，更低的复杂度或者是进行其他方面的
   优化
4. 通过C语言自己实现优化后的算法，并使用数据集测试算法的复杂度，比较各算法的时间复杂度与
   空间复杂度
5. 有可能的话，尝试对另一种算法也进行进一步优化。
```

### 3.计划安排Cancel changes

 ```markdown
 5月8日~5月11日 		阅读文献综述，确定最终选题
 5月11日~5月15日 	  项目开题报告
 5月16日~5月25日		在C语言框架下，实现参考文献的算法，理解算法含义。比较两组算法从中选择较为合适的一组为后续使用和优化改进的主要目标。
 5月26日~5月31日 	  实现算法的应用、实现和编写python程序进行统计各个算法的时间空间复杂度，分析优劣
 6月1日~6月5日		  算法优化与可视化 ，准备展示所需的素材等
 6月6日~6月12日		  PPT与项目展示，打包等收尾工作
 ```



## 三.项目参考文献

[1] Muhammad Sardaraza, Muhammad Tahirb, Ataul AzizIkramc, Hassan Bajwad ,"SeqCompress:
An algorithm for biological sequence compression",Genomics,Volume 104, Issue 4,Pages 225-
228,October 2014https://doi.org/10.1016/j.ygeno.2014.08.007

[2] Pamela Vinitha Eric, Gopakumar Gopalakrishnan, Muralikrishnan Karunakaran, "An Optimal
Seed Based Compression Algorithm for DNA Sequences", Advances in Bioinformatics, vol. 2016,
Article ID 3528406, 7 pages, 2016. https://doi.org/10.1155/2016/3528406

