/*********************************************************************
 * THREADING WITH ARGUMENTS – ALL CASES IN ONE FILE
 * ------------------------------------------------
 * This file demonstrates ALL argument-passing cases with std::thread:
 *
 * 2.1 Pass by value
 * 2.2 Pass multiple arguments
 * 2.3 Pass by reference (WRONG way)
 * 2.4 Pass by reference (CORRECT using std::ref)
 * 2.5 Pass pointer
 * 2.6 Pass object by value
 * 2.7 Pass object by reference
 *
 * All examples are SMALL, ISOLATED, and NUMBERED.
 *********************************************************************/

#include <iostream>
#include <thread>
#include <functional> // std::ref

/*********************************************************************
 * 2.1 PASS BY VALUE
 *********************************************************************/
void byValue(int x)
{
  // Modifies only local copy
  x += 10;
  std::cout << "[2.1] byValue x = " << x << std::endl;
}

/*********************************************************************
 * 2.2 PASS MULTIPLE ARGUMENTS
 *********************************************************************/
void multipleArgs(int a, double b)
{
  std::cout << "[2.2] multipleArgs: " << a << ", " << b << std::endl;
}

/*********************************************************************
 * 2.3 PASS BY REFERENCE (WRONG)
 * std::thread COPIES arguments by default
 *********************************************************************/
void byReferenceWrong(int &x)
{
  x += 10;
}

/*********************************************************************
 * 2.4 PASS BY REFERENCE (CORRECT using std::ref)
 *********************************************************************/
void byReferenceCorrect(int &x)
{
  x += 10;
  std::cout << "[2.4] byReferenceCorrect x = " << x << std::endl;
}

/*********************************************************************
 * 2.5 PASS POINTER
 *********************************************************************/
void byPointer(int *x)
{
  if (x)
    (*x) += 10;
  std::cout << "[2.5] byPointer *x = " << *x << std::endl;
}

/*********************************************************************
 * Helper struct for object examples
 *********************************************************************/
struct Data
{
  int value;
};

/*********************************************************************
 * 2.6 PASS OBJECT BY VALUE
 *********************************************************************/
void objectByValue(Data d)
{
  // Modifies COPY
  d.value = 100;
  std::cout << "[2.6] objectByValue d.value = " << d.value << std::endl;
}

/*********************************************************************
 * 2.7 PASS OBJECT BY REFERENCE
 *********************************************************************/
void objectByReference(Data &d)
{
  d.value = 100;
  std::cout << "[2.7] objectByReference d.value = " << d.value << std::endl;
}

/*********************************************************************
 * MAIN
 *********************************************************************/
int main()
{
  /******************** 2.1 ********************/
  int a = 5;
  std::thread t1(byValue, a);
  t1.join();
  std::cout << "[2.1] main a = " << a << " (unchanged)\n\n";

  // /******************** 2.2 ********************/
  std::thread t2(multipleArgs, 10, 3.14);
  t2.join();
  std::cout << std::endl;

  /******************** 2.3 ********************/
  /*
  int b = 5;
  std::thread t3(byReferenceWrong, b); //  copied, not reference
  t3.join();
  std::cout << "[2.3] main b = " << b << " (UNCHANGED)\n\n";

  */
  // Error expected: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'

  // /******************** 2.4 ********************/
  int c = 5;
  std::thread t4(byReferenceCorrect, std::ref(c)); // ✅ real reference
  t4.join();
  std::cout << "[2.4] main c = " << c << " (MODIFIED)\n\n";

  // /******************** 2.5 ********************/
  int d = 5;
  std::thread t5(byPointer, &d);
  t5.join();
  std::cout << "[2.5] main d = " << d << " (MODIFIED)\n\n";

  // /******************** 2.6 ********************/
  Data data1{5};
  std::thread t6(objectByValue, data1); // copy
  t6.join();
  std::cout << "[2.6] data1.value = " << data1.value << " (UNCHANGED)\n\n";

  // /******************** 2.7 ********************/
  Data data2{5};
  std::thread t7(objectByReference, std::ref(data2));
  t7.join();
  std::cout << "[2.7] data2.value = " << data2.value << " (MODIFIED)\n\n";

  return 0;
}

// [2.1] byValue x = 15
// [2.1] main a = 5 (unchanged)

// [2.2] multipleArgs: 10, 3.14

// [2.4] byReferenceCorrect x = 15
// [2.4] main c = 15 (MODIFIED)

// [2.5] byPointer *x = 15
// [2.5] main d = 15 (MODIFIED)

// [2.6] objectByValue d.value = 100
// [2.6] data1.value = 5 (UNCHANGED)

// [2.7] objectByReference d.value = 100
// [2.7] data2.value = 100 (MODIFIED)
