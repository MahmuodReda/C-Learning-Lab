#include <iostream>
#include <memory>

/*
============================================================
SECTION 1: RAW POINTERS (BASICS)
============================================================
*/

/*----------------------------------------------------------
1.1 Address-of (&) and Dereference (*)
----------------------------------------------------------*/
void raw_basic()
{
  int x = 10;
  int *p = &x; // p stores address of x

  std::cout << "[1.1] x = " << x << "\n";
  std::cout << "[1.1] *p = " << *p << "\n";

  *p = 20; // modify x through pointer
  std::cout << "[1.1] x after modification = " << x << "\n\n";
}

/*----------------------------------------------------------
1.2 nullptr initialization
----------------------------------------------------------*/
void raw_nullptr()
{
  int *p = nullptr; // safe initialization

  if (p == nullptr)
    std::cout << "[1.2] p is nullptr\n\n";
}

/*
============================================================
SECTION 1.3: CONST AND POINTER COMBINATIONS
============================================================
*/

/*----------------------------------------------------------
1.3.1 Pointer to const value
int const* p
----------------------------------------------------------*/
void pointer_to_const()
{
  int i = 5;
  int j = 8;

  int const *cp = &i; // pointer to const int

  std::cout << "[1.3.1] *cp = " << *cp << "\n";

  // *cp = 10;                   // ERROR: value is const
  cp = &j; // OK: pointer can change target

  std::cout << "[1.3.1] *cp after pointing to j = " << *cp << "\n\n";
}

/*----------------------------------------------------------
1.3.2 Const pointer
int* const p
----------------------------------------------------------*/
void const_pointer()
{
  int i = 5;
  int j = 8;

  int *const pc = &i; // const pointer to int

  *pc = 12; // OK: value can change
  std::cout << "[1.3.2] *pc = " << *pc << "\n";

  // pc = &j;                    // ERROR: pointer is const
  std::cout << "[1.3.2] address unchanged\n\n";
}

/*----------------------------------------------------------
1.3.3 Const pointer to const value
int const* const p
----------------------------------------------------------*/
void const_pointer_to_const()
{
  int i = 5;

  int const *const cpc = &i;

  std::cout << "[1.3.3] *cpc = " << *cpc << "\n";

  // *cpc = 9;                   // ERROR: value is const
  // cpc = &i;                   // ERROR: pointer is const

  std::cout << "[1.3.3] fully immutable pointer\n\n";
}

/*
============================================================
SECTION 1.4: STRUCT AND POINTER ACCESS
============================================================
*/

struct Coord
{
  char x;
  char y;
};

void struct_pointer()
{
  Coord a{12, 34};
  Coord *p = &a;

  char v = p->x; // arrow operator
  char w = p->y;

  char s = (*p).x; // dereference + dot
  char t = (*p).y;

  std::cout << "[1.4] v=" << int(v)
            << " w=" << int(w)
            << " s=" << int(s)
            << " t=" << int(t) << "\n\n";
}

/*
============================================================
SECTION 1.5: DANGLING POINTER (DANGER)
============================================================
*/

void dangling_pointer()
{
  int *p;

  {
    int x = 42;
    p = &x; // p points to x
  } // x destroyed here

  // *p = 7;                     // UNDEFINED BEHAVIOR

  std::cout << "[1.5] dangling pointer example (commented)\n\n";
}

/*
============================================================
SECTION 2: SMART POINTERS
============================================================
*/

/*----------------------------------------------------------
2.1 unique_ptr with int
----------------------------------------------------------*/
void unique_ptr_int()
{
  std::unique_ptr<int> up = std::make_unique<int>(10);

  std::cout << "[2.1] unique_ptr value = " << *up << "\n\n";
}

/*----------------------------------------------------------
2.2 unique_ptr ownership transfer (move)
----------------------------------------------------------*/
void unique_ptr_move()
{
  std::unique_ptr<int> a = std::make_unique<int>(7);
  std::unique_ptr<int> b;

  b = std::move(a); // transfer ownership

  std::cout << "[2.2] a == nullptr: " << (a == nullptr) << "\n";
  std::cout << "[2.2] b value = " << *b << "\n\n";
}

/*----------------------------------------------------------
2.3 unique_ptr with class
----------------------------------------------------------*/
class Data
{
  int value;

public:
  Data(int v) : value(v) {}
  void show() const
  {
    std::cout << "Data value = " << value << "\n";
  }
};

void unique_ptr_class()
{
  std::unique_ptr<Data> p = std::make_unique<Data>(99);
  p->show();
  std::cout << "\n";
}

/*----------------------------------------------------------
2.4 shared_ptr with int
----------------------------------------------------------*/
void shared_ptr_int()
{
  std::shared_ptr<int> sp1 = std::make_shared<int>(100);

  std::cout << "[2.4] value = " << *sp1 << "\n";
  std::cout << "[2.4] use_count = " << sp1.use_count() << "\n";

  {
    std::shared_ptr<int> sp2 = sp1;
    std::cout << "[2.4] use_count after copy = "
              << sp1.use_count() << "\n";
  }

  std::cout << "[2.4] use_count after scope = "
            << sp1.use_count() << "\n\n";
}

/*----------------------------------------------------------
2.5 shared_ptr with class
----------------------------------------------------------*/
void shared_ptr_class()
{
  std::shared_ptr<Data> d1 = std::make_shared<Data>(50);
  std::shared_ptr<Data> d2 = d1;

  std::cout << "[2.5] use_count = " << d1.use_count() << "\n";
  d1->show();
  std::cout << "\n";
}

/*----------------------------------------------------------
2.6 weak_ptr observing shared_ptr
----------------------------------------------------------*/
void weak_ptr_example()
{
  std::shared_ptr<int> sp = std::make_shared<int>(42);
  std::weak_ptr<int> wp = sp;

  std::cout << "[2.6] shared use_count = " << sp.use_count() << "\n";

  if (!wp.expired())
  {
    std::shared_ptr<int> locked = wp.lock();
    std::cout << "[2.6] value via weak_ptr = "
              << *locked << "\n";
  }

  sp.reset(); // destroy object

  if (wp.expired())
    std::cout << "[2.6] object destroyed\n\n";
}

/*
============================================================
MAIN
============================================================
*/
int main()
{
  raw_basic();
  raw_nullptr();

  pointer_to_const();
  const_pointer();
  const_pointer_to_const();

  struct_pointer();
  dangling_pointer();

  unique_ptr_int();
  unique_ptr_move();
  unique_ptr_class();

  shared_ptr_int();
  shared_ptr_class();

  weak_ptr_example();

  return 0;
}
// [1.1] x = 10
// [1.1] *p = 10
// [1.1] x after modification = 20

// [1.2] p is nullptr

// [1.3.1] *cp = 5
// [1.3.1] *cp after pointing to j = 8

// [1.3.2] *pc = 12
// [1.3.2] address unchanged

// [1.3.3] *cpc = 5
// [1.3.3] fully immutable pointer

// [1.4] v=12 w=34 s=12 t=34

// [1.5] dangling pointer example (commented)

// [2.1] unique_ptr value = 10

// [2.2] a == nullptr: 1
// [2.2] b value = 7

// Data value = 99

// [2.4] value = 100
// [2.4] use_count = 1
// [2.4] use_count after copy = 2
// [2.4] use_count after scope = 1

// [2.5] use_count = 2
// Data value = 50

// [2.6] shared use_count = 1
// [2.6] value via weak_ptr = 42
// [2.6] object destroyed
