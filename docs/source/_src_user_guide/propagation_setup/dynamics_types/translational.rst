.. _translational_dynamics:

======================
Translational Dynamics
======================

Basic settings for propagating translational dynamics require:

* The names of the bodies that are to be propagated
* The centers of propagation w.r.t. which they are to be propagated
* Acceleration models that are to be used for the dynamics
* Initial state, in Cartesian elements with the same frame orientation as the environment (see :ref:`creating_celestial_bodies`)
* Termination time of propagation

Such a propagation is defined as follows:

    .. tabs::

         .. tab:: Python

          .. toggle-header:: 
             :header: Required **Show/Hide**

          .. literalinclude:: /_src_snippets/simulation/environment_setup/basic_translational_setup.py
             :language: python

         .. tab:: C++

          .. literalinclude:: /_src_snippets/simulation/environment_setup/req_create_bodies.cpp
             :language: cpp

With these settings, the body "Vehicle" will be propagated w.r.t. body "Earth", using given acceleration models (see :ref:`acceleration_model_setup`), a given initial state which defines the initial Cartesian state of the center of mass of "Vehicle" w.r.t. the center of mass of "Earth". The propagation will terminate once the ``simulation_end_epoch`` epoch is reached.

Additional options that can be used for the propagation (see :func:`~tudatpy.numerical_simulation.propagation_setup.propagator.translational`):

* Specifying an alternative formulation for the translational state (see list below). Default: Cowell formulation (Cartesian position and velocity) is used
* Specifying variables that are to be saved during the propagation (see :ref:`simulation_propagator_setup`). Default: None
* Requesting terminal output during the propagation (see :ref:`simulation_output_variables`) . Default: None

These additional options can be provided as follows:

    .. tabs::

         .. tab:: Python

          .. toggle-header:: 
             :header: Required **Show/Hide**

          .. literalinclude:: /_src_snippets/simulation/environment_setup/full_translational_setup.py
             :language: python

         .. tab:: C++

          .. literalinclude:: /_src_snippets/simulation/environment_setup/req_create_bodies.cpp
             :language: cpp
             
This example defines a termination condition using a dependent variable: the simulation should stop when the propagated vehicle reaches an altitude of 25.0 km. Next to that, the propagator is asked to save the total acceleration, Keplerian state, latitude, and longitude of the spacecraft as dependent variables.

.. _translational_dynamics_propagators:

Translational Dynamics Propagators
==================================

Tudat(Py) currently supports seven types of translational propagators, each having its own advantages and drawbacks. They are exposed in the ``propagation_setup.propagator`` module:

  - Cartesian coordinates (with ``cowell`` propagator); state size: 6
  - Cartesian coordinates (with ``encke`` propagator); state size: 6
  - Keplerian elements (with ``gauss_keplerian``); state size: 6
  - Modified equinoctial elements (with ``gauss_modified_equinoctial`` propagator); state size: 6
  - Unified state model with quaternions, or USM7 (with ``unified_state_model_quaternions`` propagator); state size: 7
  - Unified state model with modified Rodrigues parameters, or USM6 (with ``unified_state_model_modified_rodrigues_parameters`` propagator); state size: 7
  - Unified state model with exponential map, or USMEM (with ``unified_state_model_exponential_map`` propagator); state size: 7
