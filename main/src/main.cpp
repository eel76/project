#include "store.h"
#include <iostream>
#include <queue>
#include <stack>
#include <variant>

using BinaryOperation = std::function<double(double, double)>;

struct Operand
{
  double asDouble;
};

using Token = std::variant<Operand, BinaryOperation>;

struct model
{
  double value;
};

auto draw ()
{
  return [] (auto const& model)
    {
      std::cout << "current value: " << model.value << '\n';
    };
}

struct digit_action
{
  int digit { 0 };

  model operator() (model m) const
  {
    return { m.value * 10 + digit };
  }
};

struct plus_action
{
  model operator() (model m) const
  {
    return m;
  }
};

struct minus_action
{
  model operator() (model m) const
  {
    return m;
  }
};

template <class Store>
void dispatch (Store& store, char event)
{
  switch (event)
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      store.dispatch (digit_action { event - '0' });
      break;
    case '+':
      store.dispatch (plus_action {});
      break;
    case '-':
      store.dispatch (minus_action {});
      break;
    default:
      break;
    }  
}

int main ()
{
  auto store = Store{ model{}, draw () };
  auto event = char{};

  while (std::cin >> event)
    dispatch (store, event);
}
