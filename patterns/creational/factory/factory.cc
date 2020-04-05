// Factory as a independed class offering methods to create objects.

#include <cmath>

class Point
{
public:
    friend class PointFactory;
  float GetX() const { return x_; }
  float GetY() const { return y_; }

private:
  Point(float x, float y) : x_(x), y_(y) {}

  float x_;
  float y_;
};

struct PointFactory
{
  static Point NewCartessianPoint(float x, float y) { return {x, y}; }

  static Point NewPolarPoint(float r, float theta)
  {
    return {r * std::cos(theta), r * std::sin(theta)};
  }
};


int main()
{
  auto cp = PointFactory::NewCartessianPoint(2, 4);
  auto pp = PointFactory::NewPolarPoint(4, 10);
}
