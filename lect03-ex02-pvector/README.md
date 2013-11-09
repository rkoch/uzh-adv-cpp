Lecture 03, Exercise 02, pvector
================================

This exercise was to create a persistent vector datatype, which stores its
values on terminating and reads them again when instantiated again.


Known issues
------------

* On instantiating the vector reads the values from the file using the ">>" operator,
  which reads the lines formatted (split on whitespace). This causes the vector to split
  longer string values (for example a sentence which more than one word) into different
  entries in the vector.


Change history
--------------

* Added several new methods which are used by pRPN (exercise 3.3) /rko, 2013-11-09
* Initial commit /rko, 2013-10-31

