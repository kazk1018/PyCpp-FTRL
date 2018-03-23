#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include "ftrl.h"

namespace py = pybind11;

namespace {
    PYBIND11_MODULE(ftrl, m) {
        m.doc() = "ftrl library";

        py::class_<ftrl::FTRL>(m, "FTRL")
                .def(py::init<const ftrl::DenseVector&, double, double, double, double>(), "Initialize ftrl")
                .def("fit", &ftrl::FTRL::Fit, "Fit a training data")
                .def("get_weight", &ftrl::FTRL::GetWeight, "Get weights")
                .def("predict", &ftrl::FTRL::Predict, "Predict a new vector");
    }
} // namespace
