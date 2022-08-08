//
// Created by 58468 on 2022/8/8.
//
#include "helper.h"

using namespace std;
using namespace std::chrono;

/**
 * 冒泡排序
 * @param nums
 * @return
 */
void bubble_sort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
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
    bubble_sort(nums);
    auto end = system_clock::now();

    printf("output:\n");
    print_nums(nums);

    duration<double, std::milli> fp_ms = end - start;
    printf("cost %f ms\n", fp_ms.count());
    cout << (check_result(nums) ? "CORRECT." : "INCORRECT!") << endl;

    return 0;
}