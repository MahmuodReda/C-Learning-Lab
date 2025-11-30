#include <iostream>
#include <string>
#include <vector>

/**
 * @class mydata
 * @brief Demonstrates normal constructor and initializer_list constructor.
 */
class mydata
{
public:
    int x;
    int y;

    /**
     * @brief Normal constructor initializing x and y.
     * @param x Initial value for x.
     * @param y Initial value for y.
     */
    mydata(int x, int y) : x(x), y(y)
    {
        std::cout << "mydata constructor" << std::endl;
    }

    /**
     * @brief Initializer list constructor.
     * @param v List of integers to print during construction.
     */
    mydata(std::initializer_list<int> v)
    {
        std::cout << "initializer list constructor" << std::endl;
        for (auto i : v)
        {
            std::cout << i << std::endl;
        }
    }
};

/**
 * @brief Demonstrates all major std::string constructors.
 */
void construct_test()
{
    std::string s = "Hello, World!";

    /** Copy constructor */
    std::string str1(s);

    /** Copy constructor (assignment-style) */
    std::string str2 = s;

    /** Move constructor */
    std::string str3(std::move(s));

    /** Range constructor */
    std::string str4(str1.begin(), str1.end());

    /** Substring constructor (pos=7, len=5 → "World") */
    std::string str5(str1, 7, 5);

    /** Constructing from vector<char> */
    std::vector<char> v = {'a', 'b', 'c', 'd', 'e'};
    std::string str6(v.begin(), v.end());

    /** Initializer list constructor */
    std::string str7({'a', 'b', 'c', 'd', 'e'});

    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;
    std::cout << "str5 = " << str5 << std::endl;
    std::cout << "str6 = " << str6 << std::endl;
}

/**
 * @brief Entry point of the program.
 * @return int Exit code.
 */
int main()
{
    construct_test();

    /** Normal constructor */
    mydata m{1, 2};

    /** Initializer list constructor */
    mydata m2{3, 4, 5};

    return 0;
}

// str1 = Hello, World!
// str3 = Hello, World!
// str5 = World
// str6 = abcde
// initializer list constructor
// 1
// 2
// initializer list constructor
// 3
// 4
// 5