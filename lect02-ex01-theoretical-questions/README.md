Lecture 02, Exercise 01, Theoretical Questions
==============================================

Which of these lines belong into the header file? Why?


Header file
-----------

* Could also be local variables of a function
** char ch;
** string s;

* Because of the extern statement
** extern int error_number;

* Function declaration
** static double sq(double);
** extern "C" void c_swap(int *a, int *b);
** double sqrt(double);

* Constant definition
** const double pi=3.5;

* Type definition
** struct fraction { int c; int d; };
** struct user;

* Namespace definition
** namespace NS { int a; }

* Not in the header file
** int count=1;
** char *name="It's me";
** char *prog[]={"echo","hello","world!",NULL};
** void swap(int &a, int &b) { int c=a; a=b; b=c; } 


Change history
--------------

* Initial commit /rko, 2013-10-30
