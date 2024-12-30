// Auto cannot be used as parameters
// int foo(auto a);

class Dog {
  public:

    // Auto cannot be initialized with non-static members
    // auto name_ = "";

    // Integral or enum must be initialized in the class, other types must be outside. 
    // static const auto name_ = "";
    static const auto age_ = 1; 

    // Auto cannot be used in top-level array type
    // auto array_[] = {1, 2, 3};
};