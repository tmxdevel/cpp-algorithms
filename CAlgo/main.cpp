#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include <sys/time.h>

#include "algo_utils.h"
#include "algo_sort.h"
#include "algo_2d.h"
#include "data_structures/linked_list.h"
#include "testing/algobenchs.h"

#define LINUX_BENCH

using namespace std;

template <class Duration>
    using sys_time = std::chrono::time_point<std::chrono::system_clock, Duration>;
using sys_nanoseconds = sys_time<std::chrono::nanoseconds>;


bool lessInt(const float *lhs, const float *rhs) {
    return *lhs <= *rhs;
}

int main()
{
    Algo::LinkedList<std::string> ll;

    ll.append("test3");
    ll.push("test2");
    ll.push("test1");
    ll.append("test4");

    auto head = ll.head();
    for(auto n = head; n != nullptr; n = n->next) {
        cout << n->data << "   ";
    }
    cout << endl << ll.count() << endl;

    return 0;
}
