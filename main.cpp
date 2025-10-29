#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read an integer offset from user input
    int offset;
    std::cin >> offset;

    // Initialize a vector with sample values
    std::vector<int> v{10, 12, 30, 1, 2, 0, 31};

    // Sort the vector using a lambda function that adds 'offset' before comparison
    // Note: Adding the same offset to both elements does not affect the sort order
    std::sort(v.begin(), v.end(), [offset](int num1, int num2) {
        return (num1 + offset) < (num2 + offset);
    });

    // Print the sorted vector elements separated by spaces
    std::for_each(v.begin(), v.end(), [](int num) {
        std::cout << num << " ";
    });

    return 0;
}


 // wiht c++ insights c++ 20 
// #include <iostream>
// #include <vector>
// #include <algorithm>

// int main()
// {
//   int offset;
//   std::cin.operator>>(offset);
//   std::vector<int, std::allocator<int> > v = std::vector<int, std::allocator<int> >{std::initializer_list<int>{10, 12, 30, 1, 2, 0, 31}, std::allocator<int>()};
    
//   class __lambda_15_35
//   {
//     public: 
//     inline /*constexpr */ bool operator()(int num1, int num2) const
//     {
//       return (num1 + offset) < (num2 + offset);
//     }
    
//     private: 
//     int offset;
//     public: 
//     // inline /*constexpr */ __lambda_15_35 & operator=(const __lambda_15_35 &) /* noexcept */ = delete;
//     // inline /*constexpr */ __lambda_15_35(const __lambda_15_35 &) noexcept = default;
//     // inline /*constexpr */ __lambda_15_35(__lambda_15_35 &&) noexcept = default;
//     __lambda_15_35(int & _offset)
//     : offset{_offset}
//     {}
    
//   };
  
//   std::sort(v.begin(), v.end(), __lambda_15_35{offset});
    
//   class __lambda_20_39
//   {
//     public: 
//     inline /*constexpr */ void operator()(int num) const
//     {
//       std::operator<<(std::cout.operator<<(num), " ");
//     }
    
//     using retType_20_39 = void (*)(int);
//     inline constexpr operator retType_20_39 () const noexcept
//     {
//       return __invoke;
//     };
    
//     private: 
//     static inline /*constexpr */ void __invoke(int num)
//     {
//       __lambda_20_39{}.operator()(num);
//     }
    
//     public: 
//     // inline /*constexpr */ __lambda_20_39(__lambda_20_39 &&) noexcept = default;
//     // /*constexpr */ __lambda_20_39() = default;
    
//   };
  
//   std::for_each(v.begin(), v.end(), __lambda_20_39{});
//   return 0;
// }