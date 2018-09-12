# 2018.9.10
## 2015级沈阳工业大学信息科学与工程学院计算机科学与技术算法课设
### A组
> 1, 2题为签到题， 得出公式计算答案即可
> 第4题，直线分割平面的进阶版-折线分割平面，推导出公式，然后求和（实际上就是等差数列求和），然后再加1。
> 第3题，求最长递增子序列，这题比较坑的地方在于用普通的pd来写会超时，这题有O(nlogn)时间复杂度的解法：
>> 设一个辅助数组，遍历原数组，
>> 然后找到每个数组应该被插入的位置
>> 其中找到应该插入位置的过程使用O(logn)的算法来实现(如二分查找)
>> 故最终的时间复杂度为O(nlogn)
> 第5题，hdu的2100，26进制算法A B C ... X Y Z每个字母代表一个数字0 1 2 ... 23 24 25，给出俩大写的字符串，求结果。
>> 要注意前导0的去除
> 第6题，hdu1062，
>> 使用优先队列+BFS求解
> 第7题，codeforce 45B，这题读懂题意就很easy，可惜我看题看了俩个多小时还是没有明白，最后基友给讲解的题意（我的六级证是假的2333...）
>> 看懂题意， 理解公式的意思，
>> 注意题目中出现的变量以及他们在题中所给的公式中的用途，
>> 理解B[i]代表着传递次数，然后就很easy了
> 第8题，hdu的2553，八皇后问题，在此不做解释了。。。。

### B组（2018.9.12）
> 第一题，属于签到题，找到规律后很好写
>> 先增序排序，得到排序后数组啊a[]，然后求和，
>> sum = a[0] * 2 + a[1] * 3 + …… + a[n - 2] * n + a[n - 1] * n;
> 第二题，空心三角形，属于杭电水题之一， 不多说了
> 第三题，看电视节目
>> 给n个节目的开始和结束时间（整数），求最多能看完多少节目
>> 用贪心来求解
>> 先根据每个节目的开始时间对节目进行排序，用的归并排序（O(nlogn)）
>> 设置初始结束时间为0
>> 开始遍历数组，
>> 求出节目开始时间大于结束时间，并且节目结束时间最小的节目，总数+1（很显然，下一个节目就看你了，而且介于当前节目和下一个节目之间的节目可以直接略过了）
>> 输出结果
> 第四题，0-1背包，动态规划，不用多说
> 第五题，最长公共子序列，同样动态规划，同样不用多说
> 第六题，排序，对就是排序，据说O(n^2)也能过，不过我用了归并，前面第三题刚写，直接拿来用
> 第七题，找钱，动态规划和分支界限法（回溯）都可以解，暴力也能解，不过随着钱币种类增多。。。。
> 第八题，矩阵连乘问题， 同样用动态规划求解。

# 2018.9.11
## hduoj1003
> 求最大子段和以及始末位置，暴力求解为n^2算法，不过超时
> 参照[解题报告](https://blog.csdn.net/podongfeng_/article/details/26858541)，了解到一个O(n)的算法，利用了最优解的前一段数的和和后一段数的和必然小于0或者不存在这个特点：
> 从0~n-1遍历数组
>> 判断当前缓存的最大值（hereSum）是否小于0
>>> 若小于0，则将当前缓存的最大值更改为当前值，并更改缓存的始末位置（hereStart, hereEnd）
>>> 若不小于0，则将当前缓存的最大值加上当前值，并更改缓存的结束位置为当前位置
>> 判断当前缓存的最大值是否大于保存的最大值（maxSum）
>>> 若大于，则更改保存的最大值为当前缓存的最大值，并更改保存的始末位置（maxStart, maxEnd）
> 结束输出结果

## 写了一个归并排序的demo
> 算是复习，发现自己好多东西知道原理，但是动手写代码却写不出来

