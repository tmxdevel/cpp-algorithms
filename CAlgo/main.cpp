#include <iostream>
#include <vector>

#include "algo_utils.h"
#include "algo_sort.h"

using namespace std;

bool lessInt(const float *lhs, const float *rhs) {
    return *lhs <= *rhs;
}

int main()
{
    std::vector<float> rnd_list = AlgoUtils::gen_random_list(10, 0.f, 10.f);
    std::vector<float> rnd_list2 = rnd_list;

    for(auto val : rnd_list) {
        cout << val << endl;
    }

    cout << "==========================" << endl;

    Algo::bubble_sort<float>(rnd_list.data(), rnd_list.data() + rnd_list.size(), &lessInt);

    for(auto val : rnd_list) {
        cout << val << endl;
    }

    cout << "==========================" << endl;

    Algo::quick_sort<float>(rnd_list2.data(), rnd_list2.data() + rnd_list2.size(), &lessInt);

    for(auto val : rnd_list) {
        cout << val << endl;
    }

    return 0;
}
