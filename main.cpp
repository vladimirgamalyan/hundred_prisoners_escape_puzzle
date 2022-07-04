#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

int main(int argc, char *argv[]) {
    std::cout << "100 prisoners escape puzzle\n";

    const int prisoners_count = 100;
    const int prisoner_try_count = 50;
    const int iteration_count = 1000000;

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::vector<int> boxes(prisoners_count);

    int good_iteration_count = 0;
    for (auto iteration = 0; iteration < iteration_count; ++iteration) {
        std::iota(std::begin(boxes), std::end(boxes), 0);
        std::shuffle(std::begin(boxes), std::end(boxes), rng);

        bool good_iteration = true;
        for (auto prisoner = 0; prisoner < prisoners_count; ++prisoner) {
            bool found = false;
            auto cur_box = prisoner;
            for (auto try_count = 0; try_count < prisoner_try_count; ++try_count) {
                auto number_in_box = boxes[cur_box];
                if (number_in_box == prisoner) {
                    found = true;
                    break;
                }
                cur_box = number_in_box;
            }
            if (!found) {
                good_iteration = false;
                break;
            }
        }
        if (good_iteration)
            ++good_iteration_count;
    }

    auto result = static_cast<double>(good_iteration_count) / iteration_count;
    std::cout << result << '\n';

    return EXIT_SUCCESS;
}
