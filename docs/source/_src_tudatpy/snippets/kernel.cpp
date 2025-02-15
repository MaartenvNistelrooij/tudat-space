#include <pybind11/pybind11.h>

#include <tudat/config.hpp>

#include "expose_astro.h"
#include "expose_constants.h"
#include "expose_example.h"
#include "expose_interface.h"
#include "expose_io.h"
#include "expose_math.h"
#include "expose_simulation.h"

namespace py = pybind11;

PYBIND11_MODULE(kernel, m) {

  // Disable automatic function signatures in the docs.
  // NOTE: the 'options' object needs to stay alive
  // throughout the whole definition of the module.
  py::options options;
  options.enable_function_signatures( );
  options.enable_user_defined_docstrings( );

  // Export the tudat version.
  m.attr("_tudat_version") = TUDAT_VERSION;
  m.attr("_tudat_version_major") = TUDAT_VERSION_MAJOR;
  m.attr("_tudat_version_minor") = TUDAT_VERSION_MINOR;
  m.attr("_tudat_version_patch") = TUDAT_VERSION_PATCH;

  // more submodule definitions...

  // simulation module
  auto simulation = m.def_submodule("simulation");
  tudatpy::expose_simulation(simulation);

  // more submodule definitions...

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}