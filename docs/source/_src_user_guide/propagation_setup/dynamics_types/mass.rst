=============
Mass Dynamics
=============

Propagating the mass of a body is typically (but not exclusively) coupled with the use of a thrust model. For a full description of mass-rate models and thrust models, see (TODO and TODO). Defining mass propagation settings is done similarly to the translational and rotational dynamics:

    .. tabs::

         .. tab:: Python

          .. toggle-header:: 
             :header: Required **Show/Hide**

          .. literalinclude:: /_src_snippets/simulation/environment_setup/full_mass_setup.py
             :language: python

         .. tab:: C++

          .. literalinclude:: /_src_snippets/simulation/environment_setup/req_create_bodies.cpp
             :language: cpp

where the final two inputs are optional (see :func:`~tudatpy.numerical_simulation.propagation_setup.propagator.mass`)
