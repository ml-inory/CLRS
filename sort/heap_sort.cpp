//
// Created by 58468 on 2022/8/14.
//
#include "helper.h"

#include <cmath>

using namespace std;
using namespace std::chrono;

/**
 * 获取左节点
 * @param i
 * @return
 */
inline int get_left_node(int i) {
    return 2 * i + 1;
}

/**
 * 获取右节点
 * @param i
 * @return
 */
inline int get_right_node(int i) {
    return 2 * i + 2;
}

/**
 * 获取父节点
 * @param i
 * @return
 */
inline int get_parent(int i) {
    if (i == 0)
        return -1;
    else
        return (i - 1) / 2;
}

inline int get_brother(int i) {
    if (i % 2 == 0)
        return i - 1;
    else
        return i + 1;
}

void swap(int& lhs, int& rhs) {
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

void print_tree(vector<int>& nums) {
    int num_level = log2(nums.size() * 1.0) + 1;
    int k = 0;
    for (int i = 0; i < num_level; i++) {
        for (int n = 0; n < num_level - i - 1; n++) {
            printf("\t");
        }
        for (int n = 0; n < pow(2, i); n++, k++) {
            if (k >= nums.size()) {
                printf("\n");
                return;
            }
            printf("%d\t", nums[k]);
        }
        printf("\n");
    }
}

/**
 * 大堆化
 * @param nums
 */
void max_heapify(vector<int>& nums, int i, int N) {
    if (i < 0)  return;
    int left = get_left_node(i);
    int right = get_right_node(i);

    if (left < N) {
        if (nums[left] > nums[i]) {
            if (right < N) {
                if (nums[right] > nums[left]) {
                    swap(nums[i], nums[right]);
                    max_heapify(nums, right, N);
                } else {
                    swap(nums[i], nums[left]);
                    max_heapify(nums, left, N);
                }
            } else {
                swap(nums[i], nums[left]);
                max_heapify(nums, left, N);
            }
        } else {
            if (right < N && nums[right] > nums[i]) {
                swap(nums[i], nums[right]);
                max_heapify(nums, right, N);
            }
        }
    }

    int parent = get_parent(i);
    if (parent < 0)     return;
    max_heapify(nums, parent, N);
}



/**
 * 堆排序
 * @param nums
 * @return
 */
void heap_sort(vector<int>& nums) {
    int N = nums.size();
    while (N > 0) {
        max_heapify(nums, get_parent(N - 1), N);
        print_tree(nums);
        swap(nums[0], nums[N - 1]);
        N--;
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
//    print_tree(nums);

    auto start = system_clock::now();
    heap_sort(nums);
    auto end = system_clock::now();

    printf("output:\n");
    print_nums(nums);
//    print_tree(nums);

    duration<double, std::milli> fp_ms = end - start;
    printf("cost %f ms\n", fp_ms.count());
    cout << (check_result(nums) ? "CORRECT." : "INCORRECT!") << endl;

    return 0;
}