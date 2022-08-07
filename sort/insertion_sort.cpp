/**
 * Date: 2022/08/06
 * 插入排序
 * 生成N个随机整数，进行插入排序，打印结果和耗时
 *
 * 运行方法： ./insertion_sort N， N为一个int范围内的数字
 */
#include "helper.h"

using namespace std;
using namespace std::chrono;

/**
 * 插入排序
 * @param nums
 * @return
 */
vector<int> insertion_sort(const vector<int>& nums) {
    vector<int> result;

    result.push_back(nums[0]);

    for (size_t i = 1; i < nums.size(); ++i) {
        int key = nums[i];
        size_t k = 0;
        while (k < result.size() && key >= result[k]) {
            k++;
        }
        if (k >= result.size()) {
            result.push_back(key);
        } else {
            result.insert(result.begin() + k, key);
        }
    }
    return result;
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