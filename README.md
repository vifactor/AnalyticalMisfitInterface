Classes that implement the idea of relaxed interfaces containing 
straight misfit dislocations.
Two types of interfaces are considered:
- Cubic interface
- Hexagonal interface

Classes provide the methods for calculation of 
the analytical correlation function and its coefficients.

Mathematica files with analytical integrals
are also added to the repository and can be used for 
verification and tests.

*Build*
mkdir build & cd build
cmake ..
make

By defaults tests are not built. To build them use: 
cmake -DBUILD_TESTING=ON ..
