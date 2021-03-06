/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : 等差数组的排序算法.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/07/02 15:20:22
*  @Last Modified  : 2017/09/17 11:07:59
********************************************************************************
*/

#include <stdio.h>

/*
 * 题：有1, 2, ..., n 的数组打乱后存放在数组里，求排序算法。要求时间复杂度为O(N)，空
 * 间复杂度为O(1)，使用交换，而且一次只能交换两个数字。
 * 解析：这种等差数列在排好序以后，值和它所在下标存在固定的关系，比如这个题目排好序
 * 后，数值所在下标为数值减一。所以知道数值就知道了它所在下标。
 */
void sort(int a[], int n)
{
    if(a == NULL || n <= 0)
        return;
    
    for(int i = 0; i < n; ++i)
    {
        while(a[i] - 1 != i) //如果数值不在它应该所处的位置上，则交换到它应该处的位置上。
        {
            int value = a[i];
            int valueIndex = value - 1; //数值减一即为这个数值在排序中的位置。
            a[i] = a[valueIndex];
            a[valueIndex] = value;
        }
    }
}

/*
 * 题：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但
 * 不知道有几个数字是重复的，也不知道每个数字重复了几次。请找出任意一个重复的数字。
 * 解析：可以排序后遍历，但效果不理想。可以用以下方法，时间复杂度为On。
 */
bool duplicate(int numbers[], int length, int *duplication)
{
    if(numbers == NULL || length < 2) return false;
    for(int i = 0; i < length; ++i)
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            //交换numbers[i] 和 numbers[numbers[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 2, 5, 6, 4, 8, 9, 7, 10};
    sort(a, sizeof(a)/sizeof(a[0]));
    for(unsigned i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
