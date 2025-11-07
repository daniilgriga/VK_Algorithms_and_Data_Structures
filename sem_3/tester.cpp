#include "algorithms.hpp"

int main ()
{
    // 1.
    std::cout << "[1]: sqrt(9): " << algs::sqrt_binary (9) << std::endl;
    std::cout << "[1]: sqrt(45): " << algs::sqrt_binary (45) << std::endl;

    // 2.
    std::cout << "[2.1 (binary)]:   " << algs::copy_time_binary (100, 10, 10) << std::endl;
    std::cout << "[2.2 (analytic)]: " << algs::copy_time_analytic (100, 10, 10) << std::endl;

    // 3.
    std::vector<int> anml = {1, 2, 2};
    std::vector<int> fd = {7, 1};
    std::cout << "[3.1]: " <<  algs::feed_animals_sort (anml, fd) << std::endl;

    // 4.
    const std::string a = "uio";
    const std::string b = "oeiu";
    std::cout << "[4]: a = '" << a << "' | b = '" << b << "' -> '" <<  algs::find_extra_letter (a, b) << "'" << std::endl;

    // 5.
    std::vector<int> data = {2, 7, 11, 15};
    int target = 9;

    std::cout << "[5]: data = ";
    algs::print_vector (data);
    std::cout << "     target = '" << target << "' -> ";
    std::vector<int> ans = algs::two_sum (data, target);
    algs::print_vector (ans);

    // 6.1 (sorts tests)
    std::vector<int> vec = algs::generate_rand_vector (10);
    std::vector<int> cp_vec = vec;
    std::cout << "[6]: vec = ";
    algs::print_vector (vec);

    algs::shell_sort (cp_vec, algs::ShellSeq_t::HIBBARD);
    std::cout << "[6 (hibbard)]: ";
    algs::print_vector (cp_vec);

    cp_vec = vec;
    algs::shell_sort (cp_vec, algs::ShellSeq_t::PRATT);
    std::cout << "[6 (pratt)]: ";
    algs::print_vector (cp_vec);

    cp_vec = vec;
    algs::shell_sort (cp_vec, algs::ShellSeq_t::CIURA);
    std::cout << "[6 (ciura)]: ";
    algs::print_vector (cp_vec);

    return 0;
}
