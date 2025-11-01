/**

* @brief Separate even and odd numbers in an array using lambda and std::for_each.
  */
  #include <iostream>
  #include <vector>
  #include <algorithm>

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    std::vector<int> even, odd;

    std::for_each(arr.begin(), arr.end(), [&even, &odd](int val) {
    if (val % 2 == 0)
        even.push_back(val);
    else
        odd.push_back(val);

    });


    std::cout << "Even: ";

    for (int v : even) std::cout << v << " ";

    std::cout << "\nOdd: ";

    for (int v : odd) std::cout << v << " ";


    return 0;


}

