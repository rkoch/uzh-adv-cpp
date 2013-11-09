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

* Initial commit /rko, 2013-10-31

