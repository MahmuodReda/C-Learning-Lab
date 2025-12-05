#include <iostream>
#include <vector>
#include <memory>

// Interface (pure abstract class)
class Drawable
{
public:
  virtual void draw() const = 0; // must be implemented
  virtual ~Drawable() {}
};

// Base class holding common data
class Shape
{
protected:
  std::string name;

public:
  Shape(const std::string &n) : name(n) {}
  virtual ~Shape() {}
};

// Circle inherits Shape + implements Drawable
class Circle : public Shape, public Drawable
{
private:
  double radius;

public:
  Circle(double r) : Shape("Circle"), radius(r) {}

  void draw() const override
  {
    std::cout << "Drawing Circle with radius = " << radius << "\n";
  }
};

// Rectangle inherits Shape + implements Drawable
class Rectangle : public Shape, public Drawable
{
private:
  double w, h;

public:
  Rectangle(double width, double height)
      : Shape("Rectangle"), w(width), h(height) {}

  void draw() const override
  {
    std::cout << "Drawing Rectangle ("
              << w << " x " << h << ")\n";
  }
};

// Triangle inherits Shape + implements Drawable
class Triangle : public Shape, public Drawable
{
private:
  double a, b, c;

public:
  Triangle(double x, double y, double z)
      : Shape("Triangle"), a(x), b(y), c(z) {}

  void draw() const override
  {
    std::cout << "Drawing Triangle with sides: "
              << a << ", " << b << ", " << c << "\n";
  }
};

// Test
int main()
{
  // Polymorphic collection of Drawable*
  std::vector<std::unique_ptr<Drawable>> objects;

  objects.push_back(std::make_unique<Circle>(5));
  objects.push_back(std::make_unique<Rectangle>(3, 6));
  objects.push_back(std::make_unique<Triangle>(3, 4, 5));

  // Polymorphism: call draw() through Drawable*
  for (const auto &obj : objects)
    obj->draw();

  return 0;
}
// Drawing Circle with radius = 5
// Drawing Rectangle (3 x 6)
// Drawing Triangle with sides: 3, 4, 5