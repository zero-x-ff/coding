// Inner class factory. Static factory object holds the different factory
// methods. Inner class can acces private members of outer class.

#include <cmath>

class Point
{
  // if it is private then you need a member or getter to access it.
  class PointFactory
  {
  public:
    static Point NewCartessianPoints(float x, float y) { return {x, y}; }

    static Point NewPolarPoints(float rho, float theta)
    {
      return {rho * std::cos(theta), rho * std::sin(theta)};
    }
  };

public:
  static PointFactory Factory;

private:
  // Constructor is private to avoid for the user multiple options
  Point(float x, float y) : x_(x), y_(y) {}

  float x_;
  float y_;
};

int main()
{
  auto cp = Point::Factory.NewCartessianPoints(2, 4);
  auto pp = Point::Factory.NewPolarPoints(4, 10);

  return 0;
}
