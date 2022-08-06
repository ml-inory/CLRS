# -*- coding : utf-8 -*-
import os
import time
import matplotlib.pyplot as plt

# 设置字体
plt.rcParams["font.sans-serif"]=["SimHei"]
# 正常显示负号
plt.rcParams["axes.unicode_minus"]=False

# 可执行文件路径
BIN_DIR = 'bin'
# 排序
RANKING_ALGO = (
    'insertion_sort',
)


# 获取程序路径
def get_program_path(algo):
    return os.path.join(BIN_DIR, algo + '.exe')


# 测试排序
def test_ranking():
    N = [10, 100, 1000, 2000, 5000, 10000, 20000, 50000, 100000]

    for algo in RANKING_ALGO:
        program = get_program_path(algo)
        t = []
        for n in N:
            start = time.time()
            os.system('%s %d' % (program, n))
            end = time.time()
            t.append((end - start) * 1000.0)

        plt.plot(N, t, label=algo)
    plt.title(u'排序算法')
    plt.xlim([N[0], N[-1]])
    plt.legend()
    plt.grid()
    plt.xlabel(u'数据量')
    plt.ylabel(u'耗时(ms)')
    plt.show()


def main():
    test_ranking()


if __name__ == '__main__':
    main()