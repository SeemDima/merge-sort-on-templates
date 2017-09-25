#include "gtest/gtest.h"
#include "merge_sort.h"
#include <ctime>

class spec_class
{
public:
    int data;
    int operator <= (spec_class b)
    {
        return this->data <= b.data ? 1: 0;
    }
};

class comp
{
public:
    int operator () (int a, int b)
    {
        return a > b ? 1: 0;
    }
    int operator () (double a, double b)
    {
        return a > b ? 1: 0;
    }
    int operator () (spec_class a, spec_class b)
    {
        return a.data > b.data ? 1: 0;
    }
};

comp my_comp;
void print_vec(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
void print_vec(std::vector<double> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::setprecision(4);
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
void print_vec(std::vector<spec_class> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i].data << ", ";
    }
    std::cout << std::endl;
}
TEST(merge_sort_test, empty_data)
{
    std::vector<int> empty_arr;
    my_merge_sort(empty_arr.begin(), empty_arr.end(), my_comp);
    EXPECT_EQ(empty_arr.size(), size_t(0));
}
TEST(merge_sort_test, vec_int_already_sorted)
{
    std::vector<int> int_arr = {0, 1, 2, 3, 4, 5};
    my_merge_sort(int_arr.begin(), int_arr.end(), my_comp);

    for (size_t i = 0; i < int_arr.size(); ++i)
    {
        if (int_arr[i] != int(i))
        {
            FAIL();
        }
    }
}
TEST(merge_sort_test, vec_int_not_sorted)
{
    std::vector<int> int_arr = {3, 2, 4, 0, 1, 5};
    my_merge_sort(int_arr.begin(), int_arr.end(), my_comp);
    for (size_t i = 0; i < int_arr.size(); ++i)
    {
        if (int_arr[i] != int(i))
        {
            FAIL();
        }
    }
}
TEST(merge_sort_test, vec_int_random)
{
    srand(time(0));
    std::vector<int> int_arr;
    for (int i = 0; i < 10; ++i)
    {
        int_arr.push_back(std::rand() % 100);
    }
    my_merge_sort(int_arr.begin(), int_arr.end(), my_comp);
    for(size_t i = 0; i < int_arr.size() - 1; ++i)
    {
        if (int_arr[i + 1] < int_arr[i])
        {
            FAIL();
        }
    }
}
TEST(merge_sort_test, vec_double)
{
    srand(time(0));
    std::vector<double> double_arr;
    for (int i = 0; i < 100; ++i)
    {
        double_arr.push_back(double(std::rand())/double(RAND_MAX));
    }
    my_merge_sort(double_arr.begin(), double_arr.end(), my_comp);
    for(size_t i = 0; i < double_arr.size() - 1; ++i)
    {
        if ((double_arr[i + 1] - double_arr[i]) <= 0.00001)
        {
            FAIL();
        }
    }
}

TEST(merge_sort_test, vec_spec_class)
{
    int arr_size = 10;
    srand(time(0));
    std::vector<spec_class> spec_class_arr(arr_size);
    for (int i = 0; i < arr_size; ++i)
    {
        spec_class_arr[i].data = rand() % 50;
    }
    my_merge_sort(spec_class_arr.begin(), spec_class_arr.end(), my_comp);
    for(size_t i = 0; i < spec_class_arr.size() - 1; ++i)
    {
        if (spec_class_arr[i].data > spec_class_arr[i + 1].data)
        {
            FAIL();
        }
    }
}
