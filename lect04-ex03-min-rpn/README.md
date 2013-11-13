Lecture 04, Exercise 03, pRPN with algorithms
=============================================

This exercise was to improve the Persistent Reverse Polish Notation
Calculator to make it template-based and can work with the previously
implemented fraction type. The fraction type had to be improved for this exercise to support more operators.

Known issues
------------

* In the main.cpp file I had to include the fraction.cpp file instead of just the header file wo get the project to compile/link. Unfortunately I could not determine where the real cause of this error resides.
* Can't compile the `std::for_each` command


Important note
--------------

This project might not work outside of eclipse as it depends on the pvector and
fraction which is referenced through some eclipse settings instead of a correct Makefile.


Change history
--------------

* Initial commit /rko, 2013-11-13
