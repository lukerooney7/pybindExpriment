#include "pybind11/pybind11.h"
#include "z3++.h"

namespace py = pybind11;

using namespace z3;
//Example propagator to be extended
class EmptyPropagator : public user_propagator_base {
public:
    // Pass a pointer to the user_propagator_base constructor
    EmptyPropagator(solver& s) : user_propagator_base(&s) {}

    void push() override {
    }

    void pop(unsigned num) override {
    }

    void fixed(const expr& e, const expr& value) override {
    }

    // Need to understand this
    user_propagator_base* fresh(z3::context&) override {
        return this;
    }
};


PYBIND11_MODULE(propagator, m) {
    m.doc() = "Example Empty Propagator using pybind11";

    // Was throwing an error that python could not find user_propagator_base,
    // so nee to also expose it as well as the empty propagator
    py::class_<user_propagator_base>(m, "UserPropagatorBase")
        .def("push", &user_propagator_base::push)
        .def("pop", &user_propagator_base::pop)
        .def("fixed", &user_propagator_base::fixed)
        .def("fresh", &user_propagator_base::fresh);

   // Expose empty propagator
   py::class_<EmptyPropagator, user_propagator_base>(m, "EmptyPropagator")
    .def(py::init<solver&>())  // Should solver be reference or pointer?!?!
    .def("push", &EmptyPropagator::push)
    .def("pop", &EmptyPropagator::pop)
    .def("fixed", &EmptyPropagator::fixed)
    .def("fresh", &EmptyPropagator::fresh);
}
