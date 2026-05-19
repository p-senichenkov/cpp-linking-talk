#include "cpplib.h"

#include <algorithm>
#include <ranges>

void sort_range(int* begin, int* end) {
    std::ranges::subrange sbr(begin, end);
    std::ranges::sort(sbr);
}
