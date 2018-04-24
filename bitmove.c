/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : bitmove.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/01 23:07:08
*  @Last Modified  : 2017/10/12 00:05:33
********************************************************************************
*/

#include <stdio.h>

/*
********************************************************************************
* Note : 1. 对于无符号数来说不管是左移还是右移使用的都是逻辑移位。即移动所有位，缺失位补0。
*           比如无符号数左移1位则最低补0，无符号数右移1位则最高位补0。
*        2. 有符号数左移使用的是逻辑左移，和无符号的移位方式一样。
*        3. 有符号数右移使用的是算术右移。空出位补符号位。
*           比如一个负数右位3位，空出位补符号位1，则移位后最高3位应该为111。
*           比如一个正数右位3位，空出位补符号位0，则移位后最高3位应该为000。
********************************************************************************
*/

int main(int argc, char *argv[])
{
    unsigned int ui = 0x80000000;
    unsigned int uj = 0x00000001;
    signed int si = 0x80000000; //赋值为负数
    signed int sj = 0x40000000; //赋值为正数

    //无符号数右移，空出位补0。相当于除以2的n次方。
    printf("%#x >> 1：%#x\n", ui, ui >> 1);
    //无符号数左移，空出位补0。相当于乘以2的3次方。
    printf("%d << 3：%d\n", uj, uj << 3);
    //有符号数负数右移，空出位补上符号位1，则最高3位为111。相当于除以2的n次方。
    printf("%#x >> 3：%#x\n", si, si >> 3);
    //有符号数负数左移，低位补0。相当于除以2的n次方。
    printf("%#x << 3：%#x\n", sj, sj << 3);
    //有符号数正数左移，空出位补0，相当于乘以2的1次方，但是数据超限了。
    printf("%#x << 1：%#x\n", sj, sj << 1);

    return 0;
}
