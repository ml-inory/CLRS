/**
 * Date: 2022/08/07
 *
 */
#ifndef CLRS_HELPER_H
#define CLRS_HELPER_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>
#include <chrono>


/**
 * 打印帮助
 * @param program   程序名称
 */
void print_help(const char* program) {
    printf("Usage: %s [number of int]\n", program);
}


/**
 * 产生随机的N个数字
 * @param N
 * @return
 */
std::vector<int> generate_random_numbers(int N) {
    std::vector<int> result(N);

    srand(time(NULL));
    for (size_t i = 0; i < N; ++i) {
        result[i] = (rand() % 20) - N / 4;
    }
    return result;
}


/**
 * 打印数列
 * @param nums
 */
void print_nums(const std::vector<int>& nums) {
    size_t len = nums.size();

    printf("(%d)\t", len);
    if (len <= 20) {
        for (int n : nums) {
            printf("%d ", n);
        }
    } else {
        for (size_t i = 0; i < 10; ++i) {
            printf("%d ", nums[i]);
        }
        printf(" ... ");
        for (size_t i = len - 10; i < len; ++i) {
            printf("%d ", nums[i]);
        }
    }

    printf("\n\n");
}


/**
 * 检查结果
 * @param result
 * @return
 */
bool check_result(const std::vector<int>& result) {
    for (size_t i = 0; i < result.size() - 1; ++i) {
        if (result[i] > result[i+1])
            return false;
    }
    return true;
}

#endif //CLRS_HELPER_H
