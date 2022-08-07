/**
 * Date: 2022/08/07
 * 归并排序
 *
 * 运行方法： ./merges_sort N， N为一个int范围内的数字
 */
#include "helper.h"

using namespace std;
using namespace std::chrono;


/**
 * 合并两个数组
 * @param nums
 * @param p
 * @param q
 * @param r
 */
void merge(vector<int>& nums, int p, int q, int r) {
    if (p >= q || q >= r) return;
    int n1 = 0;
    int n2 = 0;
    int i = p;
    vector<int> L1(nums.begin() + p, nums.begin() + q);
    vector<int> L2(nums.begin() + q, nums.begin() + r);

    L1.push_back(INT_MAX);
    L2.push_back(INT_MAX);

    while (i < r) {
        if (L1[n1] <= L2[n2]) {
            nums[i] = L1[n1];
            n1++;
        } else {
            nums[i] = L2[n2];
            n2++;
        }
        i++;
    }
}


/**
 * 归并排序
 * @param nums
 * @return
 */
void merge_sort(vector<int>& nums, int p, int r) {
    if (p < r && r - p > 1) {
        int q = (p + r) / 2;
        merge_sort(nums, p, q);
        merge_sort(nums, q, r);
        merge(nums, p, q, r);
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
    merge_sort(nums, 0, N);
    auto end = system_clock::now();

    printf("output:\n");
    print_nums(nums);

    duration<double, std::milli> fp_ms = end - start;
    printf("cost %f ms\n", fp_ms.count());
    cout << (check_result(nums) ? "CORRECT." : "INCORRECT!") << endl;

    return 0;
}