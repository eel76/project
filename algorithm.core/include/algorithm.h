#pragma once
#include <any>
#include <function>

class Callback;
using Algorithm = std::function<std::any (std::any, Callback&)>;
