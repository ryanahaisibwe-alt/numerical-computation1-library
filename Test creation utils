// test_creation_utils.cpp
// Build:  g++ -std=c++17 -Wall -Wextra -o test_creation test_creation_utils.cpp
// Run:    ./test_creation
#include <cmath>
#include <iostream>
#include <vector>

#include "creation_utils.hpp"

using nc::Shape;

static int g_pass = 0, g_fail = 0;

#define CHECK(cond)                                                        \
    do {                                                                   \
        if (cond) {                                                        \
            ++g_pass;                                                      \
        } else {                                                           \
            ++g_fail;                                                      \
            std::cout << "  FAIL (line " << __LINE__ << "): " #cond "\n";  \
        }                                                                  \
    } while (0)

#define CHECK_THROWS(expr)                                                 \
    do {                                                                   \
        bool threw = false;                                                \
        try { (void)(expr); } catch (const std::exception&) { threw = true; } \
        CHECK(threw);                                                      \
    } while (0)

template <class T>
bool equals(const Array<T>& a, const Shape& shape, const std::vector<T>& vals) {
    if (a.shape() != shape || a.size() != vals.size()) return false;
    for (std::size_t i = 0; i < vals.size(); ++i)
        if (a[i] != vals[i]) return false;
    return true;
}

static bool near(double a, double b) { return std::fabs(a - b) < 1e-12; }

// ---------------------------------------------------------------------------
void test_creation() {
    std::cout << "creation\n";

    auto z = nc::zeros<double>({2, 3});
    CHECK(equals<double>(z, {2, 3}, {0, 0, 0, 0, 0, 0}));

    auto o = nc::ones<int>({3});
    CHECK(equals<int>(o, {3}, {1, 1, 1}));

    auto f = nc::full<double>({2, 2}, 7.5);
    CHECK(equals<double>(f, {2, 2}, {7.5, 7.5, 7.5, 7.5}));

    CHECK_THROWS(nc::zeros<double>({}));        // no dimensions
    CHECK_THROWS(nc::ones<double>({3, 0}));     // zero-sized dimension

    // arange
    CHECK(equals<double>(nc::arange<double>(0, 5, 2), {3}, {0, 2, 4}));
    CHECK(equals<double>(nc::arange<double>(5, 0, -1), {5}, {5, 4, 3, 2, 1}));
    CHECK(equals<double>(nc::arange<double>(0, 1, 0.25), {4}, {0, 0.25, 0.5, 0.75}));
    CHECK(equals<int>(nc::arange<int>(0, 4), {4}, {0, 1, 2, 3}));  // default step
    CHECK_THROWS(nc::arange<double>(0, 5, 0));  // zero step
    CHECK_THROWS(nc::arange<double>(5, 0, 1));  // empty range
    CHECK_THROWS(nc::arange<double>(0, 5, -1)); // wrong step sign

    // linspace
    auto l = nc::linspace<double>(0, 1, 5);
    CHECK(l.shape() == Shape{5});
    CHECK(near(l[0], 0.0) && near(l[1], 0.25) && near(l[2], 0.5) &&
          near(l[3], 0.75) && near(l[4], 1.0));
    auto l2 = nc::linspace<double>(0, 1, 4, false);
    CHECK(near(l2[0], 0.0) && near(l2[3], 0.75));
    CHECK(equals<double>(nc::linspace<double>(3, 9, 1), {1}, {3}));
    CHECK_THROWS(nc::linspace<double>(0, 1, 0));

    // eye
    CHECK(equals<double>(nc::eye<double>(3), {3, 3}, {1, 0, 0, 0, 1, 0, 0, 0, 1}));
    CHECK_THROWS(nc::eye<double>(0));
}

// ---------------------------------------------------------------------------
void test_concatenate() {
    std::cout << "concatenate\n";
    using A = Array<double>;

    // 1-D
    auto a1 = A::from_values({3}, {1, 2, 3});
    auto b1 = A::from_values({2}, {4, 5});
    CHECK(equals<double>(nc::concatenate<double>({a1, b1}, 0), {5}, {1, 2, 3, 4, 5}));

    // 2-D, two 2x3 arrays
    auto a = A::from_values({2, 3}, {1, 2, 3, 4, 5, 6});
    auto b = A::from_values({2, 3}, {7, 8, 9, 10, 11, 12});
    CHECK(equals<double>(nc::concatenate<double>({a, b}, 0), {4, 3},
                         {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
    CHECK(equals<double>(nc::concatenate<double>({a, b}, 1), {2, 6},
                         {1, 2, 3, 7, 8, 9, 4, 5, 6, 10, 11, 12}));

    // different sizes along the join axis are fine
    auto c = A::from_values({1, 3}, {100, 101, 102});
    CHECK(equals<double>(nc::concatenate<double>({a, c}, 0), {3, 3},
                         {1, 2, 3, 4, 5, 6, 100, 101, 102}));

    // 3-D along the middle axis
    auto p = A::from_values({2, 2, 2}, {1, 2, 3, 4, 5, 6, 7, 8});
    auto q = A::from_values({2, 1, 2}, {100, 101, 102, 103});
    CHECK(equals<double>(nc::concatenate<double>({p, q}, 1), {2, 3, 2},
                         {1, 2, 3, 4, 100, 101, 5, 6, 7, 8, 102, 103}));

    // three arrays at once
    CHECK(equals<double>(nc::concatenate<double>({a1, a1, a1}, 0), {9},
                         {1, 2, 3, 1, 2, 3, 1, 2, 3}));

    // inputs are untouched
    CHECK(equals<double>(a, {2, 3}, {1, 2, 3, 4, 5, 6}));

    // errors
    CHECK_THROWS(nc::concatenate<double>({a, c}, 1));    // row counts differ
    CHECK_THROWS(nc::concatenate<double>({a, a1}, 0));   // ndim differs
    CHECK_THROWS(nc::concatenate<double>({a, b}, 2));    // axis out of range
    CHECK_THROWS(nc::concatenate<double>({}, 0));        // nothing to join

    // vstack / hstack
    CHECK(equals<double>(nc::vstack<double>({a, b}), {4, 3},
                         {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
    CHECK(equals<double>(nc::hstack<double>({a, b}), {2, 6},
                         {1, 2, 3, 7, 8, 9, 4, 5, 6, 10, 11, 12}));
    CHECK(equals<double>(nc::hstack<double>({a1, b1}), {5}, {1, 2, 3, 4, 5}));
    CHECK_THROWS(nc::vstack<double>({a1, b1}));          // 1-D not allowed
}

// ---------------------------------------------------------------------------
void test_split() {
    std::cout << "split\n";
    using A = Array<double>;

    // equal sections along axis 1
    auto m = A::from_values({2, 6}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    auto parts = nc::split(m, 3, 1);
    CHECK(parts.size() == 3);
    CHECK(equals<double>(parts[0], {2, 2}, {1, 2, 7, 8}));
    CHECK(equals<double>(parts[1], {2, 2}, {3, 4, 9, 10}));
    CHECK(equals<double>(parts[2], {2, 2}, {5, 6, 11, 12}));

    // equal sections along axis 0
    auto t = A::from_values({4, 2}, {1, 2, 3, 4, 5, 6, 7, 8});
    auto rows = nc::split(t, 2, 0);
    CHECK(equals<double>(rows[0], {2, 2}, {1, 2, 3, 4}));
    CHECK(equals<double>(rows[1], {2, 2}, {5, 6, 7, 8}));

    // errors
    CHECK_THROWS(nc::split(m, 4, 1));   // 6 not divisible by 4
    CHECK_THROWS(nc::split(m, 0, 1));   // zero sections
    CHECK_THROWS(nc::split(m, 2, 2));   // axis out of range

    // split at indices
    auto v = nc::arange<double>(1, 11);  // 1..10
    auto pieces = nc::split_at(v, {3, 7}, 0);
    CHECK(pieces.size() == 3);
    CHECK(equals<double>(pieces[0], {3}, {1, 2, 3}));
    CHECK(equals<double>(pieces[1], {4}, {4, 5, 6, 7}));
    CHECK(equals<double>(pieces[2], {3}, {8, 9, 10}));

    // split_at with no indices returns one copy of the array
    auto whole = nc::split_at(v, {}, 0);
    CHECK(whole.size() == 1 && whole[0] == v);

    CHECK_THROWS(nc::split_at(v, {0}, 0));     // index at start
    CHECK_THROWS(nc::split_at(v, {10}, 0));    // index at end
    CHECK_THROWS(nc::split_at(v, {5, 3}, 0));  // not increasing
    CHECK_THROWS(nc::split_at(v, {3, 3}, 0));  // repeated
    CHECK_THROWS(nc::split_at(v, {3}, 1));     // axis out of range
}

// ---------------------------------------------------------------------------
void test_round_trip() {
    std::cout << "round trip\n";

    Array<double> a({4, 6, 6});
    for (std::size_t i = 0; i < a.size(); ++i) a[i] = static_cast<double>(i);

    CHECK(nc::concatenate(nc::split(a, 2, 0), 0) == a);
    CHECK(nc::concatenate(nc::split(a, 3, 1), 1) == a);
    CHECK(nc::concatenate(nc::split(a, 2, 2), 2) == a);
    CHECK(nc::concatenate(nc::split_at(a, {1, 5}, 1), 1) == a);

    // integer type works too
    auto ints = nc::arange<int>(0, 12);
    CHECK(nc::concatenate(nc::split(ints, 4, 0), 0) == ints);
}

// ---------------------------------------------------------------------------
int main() {
    test_creation();
    test_concatenate();
    test_split();
    test_round_trip();

    std::cout << "\nPassed: " << g_pass << "   Failed: " << g_fail << "\n";
    return g_fail == 0 ? 0 : 1;
}
