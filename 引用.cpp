/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : 引用.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/28 12:57:54
*  @Last Modified  : 2017/08/18 14:02:03
********************************************************************************
*/

#include <stdio.h>

/*
 * 引用的特点：
 * (1) 引用能够使用任何合法变量名。
 * (2) 引用必须初始化，而且一量初始化后，就不能再成为其它变量的引用。
 * (3) 引用不是变量，不占用存储空间。
 */

/*
 * 以下数据类型不能引用：
 * (1) 无法对void进行引用。
 * (2) 无法对数组进行引用。
 * (3) 没有引用的引用，即不存在如int a; int &b = a; int &&c = b; 这样的引用的引用
 * (4) 没有空引用，引用都必须初始化。
 */

//没有数组的引用，但却有对指针的引用。如下：pn是n的指针，rn是pn的引用。
//int n, *pn = &n, *&rn = pn;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int n = 0;
    int *pn = &n;
    int *&rn = pn;
    *rn = 5;
    printf("%d\n", n);
    return 0;
}

