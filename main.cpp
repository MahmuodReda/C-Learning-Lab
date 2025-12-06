#include <iostream>
#include <map>
#include <string>

int main()
{
  // ====== MAP (unique keys, ordered) ======
  std::map<int, std::string> mp;

  mp.insert({3, "Three"}); // insert element
  mp[1] = "One";           // insert using operator[]
  mp.emplace(2, "Two");    // emplace (construct in-place)

  // Access element
  std::cout << "mp[1] = " << mp[1] << "\n"; // operator[]

  // Find element
  auto it = mp.find(2); // O(log n)
  if (it != mp.end())
    std::cout << "Found key 2  : " << it->second << "\n";

  // Loop ordered
  std::cout << "\nMAP elements (ordered):\n";
  for (const auto &p : mp)
    std::cout << p.first << " : " << p.second << "\n";

  // Erase element
  mp.erase(3); // remove by key

  // Count (always 0 or 1 in map)
  std::cout << "Count(1) = " << mp.count(1) << "\n";

  // ====== MULTIMAP (duplicate keys allowed, ordered) ======
  std::multimap<int, std::string> mmp;

  mmp.insert({10, "Apple"});
  mmp.insert({10, "Orange"}); // duplicate key allowed
  mmp.emplace(5, "Banana");

  // Count: can be > 1
  std::cout << "\nMULTIMAP Count(10) = " << mmp.count(10) << "\n";

  // Range lookup for all values with same key
  auto range = mmp.equal_range(10); // returns pair of iterators
  std::cout << "\nMULTIMAP values with key 10:\n";
  for (auto i = range.first; i != range.second; ++i)
    std::cout << i->first << " : " << i->second << "\n";

  // Loop entire container
  std::cout << "\nMULTIMAP elements (ordered):\n";
  for (const auto &p : mmp)
    std::cout << p.first << " : " << p.second << "\n";

  return 0;
}
