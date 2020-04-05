// Factory method offers static methods to create objects. Without, both
// constructors would use floats.

#include <cmath>

class Point
{
public:
  static Point NewCartessianPoint(float x, float y) { return {x, y}; }
  static Point NewPolarPoint(float rho, float theta)
  {
    return {rho * std::cos(theta), rho * std::sin(theta)};
  }

  float GetX() const { return x_; }
  float GetY() const { return y_; }

private:
  Point(float x, float y) : x_(x), y_(y) {}

  float x_;
  float y_;
};

int main()
{
  auto cp = Point::NewCartessianPoint(2, 4);
  auto pp = Point::NewPolarPoint(4, 10);
}
