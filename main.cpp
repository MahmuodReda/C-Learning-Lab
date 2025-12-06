#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
  // ====== UNORDERED_MAP (unique keys, hash table) ======
  std::unordered_map<int, std::string> ump;

  ump.insert({1, "One"});
  ump[5] = "Five";         // operator[]
  ump.emplace(3, "Three"); // emplace (hash-table insert)

  // Access
  std::cout << "ump[5] = " << ump[5] << "\n";

  // Find element (O(1) average)
  auto it = ump.find(3);
  if (it != ump.end())
    std::cout << "Found key 3 : " << it->second << "\n";

  // Unordered printing (no guaranteed order)
  std::cout << "\nUNORDERED_MAP elements:\n";
  for (const auto &p : ump)
    std::cout << p.first << " : " << p.second << "\n";

  // Erase element
  ump.erase(1);

  // Bucket count (hash table info)
  std::cout << "Bucket count = " << ump.bucket_count() << "\n";

  // ====== UNORDERED_MULTIMAP (duplicate keys allowed, hash table) ======
  std::unordered_multimap<int, std::string> ummp;

  ummp.insert({10, "Red"});
  ummp.insert({10, "Blue"}); // duplicate key allowed
  ummp.emplace(2, "Green");

  // Count: can be more than one
  std::cout << "\nUNORDERED_MULTIMAP Count(10) = " << ummp.count(10) << "\n";

  // equal_range for fetching all elements with same key
  auto range = ummp.equal_range(10);
  std::cout << "\nUNORDERED_MULTIMAP values with key 10:\n";
  for (auto i = range.first; i != range.second; ++i)
    std::cout << i->first << " : " << i->second << "\n";

  // Loop entire container
  std::cout << "\nUNORDERED_MULTIMAP elements:\n";
  for (const auto &p : ummp)
    std::cout << p.first << " : " << p.second << "\n";

  return 0;
}
