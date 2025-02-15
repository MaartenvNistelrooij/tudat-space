.. _acceleration_model_setup:

========================
Acceleration Model Setup
========================

In Tudat, an acceleration acting on a body is defined by

*  The body undergoing acceleration
*  The body exerting the acceleration
*  The type and settings of the acceleration

A user defines these settings for each acceleration in their simulation. These settings are then used to create the acceleration models:


    .. tabs::

         .. tab:: Python

          .. toggle-header:: 
             :header: Required **Show/Hide**

          .. literalinclude:: /_src_snippets/simulation/propagation_setup/acceleration_models/acceleration_setup.py
             :language: python

         .. tab:: C++

          .. literalinclude:: /_src_snippets/simulation/environment_setup/req_create_bodies.cpp
             :language: cpp

where a spherical harmonic (degree and order 5) gravitational acceleration, and aerodynamic acceleration, of the Earth are defined, as well as a point-mass gravity of Sun and Moon. The variable ``accelerations_settings_vehicle`` denotes the list of bodies exerting accelerations, and the types of accelerations, and the variable ``acceleration_settings`` associates this list with the body undergoing the acceleration. The function ``create_acceleration_models`` creates the list of models that compute the accelerations during the propagation.

When propagating multiple bodies (see :ref:`multi_body_propagation`), the same list of settings may be re-used for multiple bodies. Below, an example is given for the definition of ``acceleration_settings`` for multiple bodies (``Vehicle1`` and ``Vehicle2``) which are undergoing identical accelerations:

    .. tabs::

         .. tab:: Python

          .. toggle-header:: 
             :header: Required **Show/Hide**

          .. literalinclude:: /_src_snippets/simulation/propagation_setup/acceleration_models/acceleration_setup_multi_vehicle.py
             :language: python

         .. tab:: C++

          .. literalinclude:: /_src_snippets/simulation/environment_setup/req_create_bodies.cpp
             :language: cpp

Or separate acceleration settings may be defined for separate bodies, and then combined into a ``acceleration_settings`` variable. Below, an example for such a case is given when propagating the Earth and Moon: 

    .. tabs::

         .. tab:: Python

          .. toggle-header:: 
             :header: Required **Show/Hide**

          .. literalinclude:: /_src_snippets/simulation/propagation_setup/acceleration_models/acceleration_setup_multi.py
             :language: python

         .. tab:: C++

          .. literalinclude:: /_src_snippets/simulation/environment_setup/req_create_bodies.cpp
             :language: cpp


