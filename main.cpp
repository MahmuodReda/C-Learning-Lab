#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

/*********************************************************************** */
/// Simple example function (unused in main)
/// Checks if 'body' starts with 'prefix'
bool starts_with2(std::string body, std::string prefix)
{
  if (prefix.size() > body.size())
    return false;
  return std::equal(prefix.begin(), prefix.end(), body.begin());
}

/// EnhancedString: extends std::string by adding utility functions
class EnhancedString : public std::string
{
public:
  /// Inherit all std::string constructors
  using std::string::string;

  /// Checks if the current string starts with 'prefix'
  bool starts_with(std::string prefix)
  {
    if (prefix.size() > this->size())
      return false;
    return std::equal(prefix.begin(), prefix.end(), this->begin());
  }

  /// Checks if the current string ends with 'suffix'
  bool ends_with(std::string suffix)
  {
    if (suffix.size() > this->size())
      return false;
    return std::equal(suffix.rbegin(), suffix.rend(), this->rbegin());
  }

  /// Converts all characters to uppercase (in-place)
  void to_upper()
  {
    std::transform(this->begin(), this->end(), this->begin(),
                   [](unsigned char c)
                   { return std::toupper(c); });
  }

  /// Converts all characters to lowercase (in-place)
  void to_lower()
  {
    std::transform(this->begin(), this->end(), this->begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
  }

  /// Reverses the string (in-place)
  void reverse()
  {
    std::reverse(this->begin(), this->end());
  }
};

int main()
{
  std::cout << std::boolalpha; // print bools as true/false

  /// Create an EnhancedString initialized with a literal
  EnhancedString s = "Hello, World!";

  /// Test starts_with()
  std::cout << s.starts_with("Hello") << std::endl; // true
  std::cout << s.starts_with("Hell@") << std::endl; // false

  /// Convert to uppercase
  s.to_upper();
  std::cout << s << std::endl;

  /// Convert to lowercase
  s.to_lower();
  std::cout << s << std::endl;

  /// Reverse the string
  s.reverse();
  std::cout << s << std::endl;

  return 0;
}

// true
// false
// HELLO, WORLD!
// hello, world!
// !dlrow ,olleh