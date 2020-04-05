// In functional factory, factories are represented as lambda functions i.e.

#include <functional>
#include <map>
#include <memory>
#include <string>

struct Car
{
  virtual ~Car() = default;
  virtual void Build() const = 0;
};

struct HighClassCar : public Car
{
  void Build() const override {}
};

struct MiddleClassCar : public Car
{
  void Build() const override {}
};

class CarGeneratorFactory
{
public:
  CarGeneratorFactory()
  {
    factories_["E200"] = []() { return std::make_unique<MiddleClassCar>(); };

    factories_["911Carrera"] = []() {
      return std::make_unique<HighClassCar>();
    };
  }

  std::unique_ptr<Car> BuildCar(const std::string &type)
  {
    return factories_[type]();
  }

private:
  std::map<std::string, std::function<std::unique_ptr<Car>()>> factories_;
};

int main()
{
  CarGeneratorFactory factory;
  auto E200 = factory.BuildCar("E200");
}
