/**
 * Date: 2022/08/06
 * 插入排序
 * 生成N个随机整数，进行插入排序，打印结果和耗时
 *
 * 运行方法： ./insertion_sort N， N为一个int范围内的数字
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
vector<int> generate_random_numbers(int N) {
    vector<int> result(N);

    srand(time(NULL));
    for (size_t i = 0; i < N; ++i) {
        result[i] = (rand() % N) - N / 4;
    }
    return result;
}


/**
 * 打印数列
 * @param nums
 */
void print_nums(const vector<int>& nums) {
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
 * 插入排序
 * @param nums
 * @return
 */
vector<int> insertion_sort(const vector<int>& nums) {
    vector<int> result;

    result.push_back(nums[0]);

    for (size_t i = 1; i < nums.size(); ++i) {
        size_t k = 0;
        while (k < result.size() && nums[i] >= result[k]) {
            k++;
        }
        if (k >= result.size()) {
            result.push_back(nums[i]);
        } else {
            result.insert(result.begin() + k, nums[i]);
        }
    }
    return result;
}


/**
 * 检查结果
 * @param result
 * @return
 */
bool check_result(const vector<int>& result) {
    for (size_t i = 0; i < result.size() - 1; ++i) {
        if (result[i] > result[i+1])
            return false;
    }
    return true;
}


int main(int argc, char** argv) {
    if (argc < 2) {
        print_help(argv[0]);
        return -1;
    }

    int N = atoi(argv[1]);
    assert(N > 0);

    vector<int> nums = generate_random_numbers(N);

    printf("input:\n");
    print_nums(nums);

    auto start = system_clock::now();
    vector<int> result = insertion_sort(nums);
    auto end = system_clock::now();

    printf("output:\n");
    print_nums(result);

    duration<double, std::milli> fp_ms = end - start;
    printf("cost %f ms\n", fp_ms.count());
    cout << (check_result(result) ? "CORRECT." : "INCORRECT!") << endl;

    return 0;
}