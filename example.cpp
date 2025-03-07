#include <pybind11/pybind11.h>
namespace py = pybind11;

// Example function
int add(int a, int b) {
    return a + b;
}

// Binding code
PYBIND11_MODULE(example, m) {
    m.doc() = "Example module using pybind11";
    m.def("add", &add, "A function that adds two numbers");
}