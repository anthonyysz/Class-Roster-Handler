# Class-Roster-Handler
## 1. Introduction
&nbsp;&nbsp;&nbsp;&nbsp;For this project, my assignment was to migrate the existing student system to a new platform using C++. The student data was provided to me in a table. The program needed to include all student information and use function calls to manipulate data. The program needed to use object-oriented programming to create student and roster classes for easier manipulation.

## 2. My task
&nbsp;&nbsp;&nbsp;&nbsp;I created a student and a roster class with accessors and mutators to provide each parameter. I also created a roster class with functions to add and remove students, print all students information or separate the students by degree program, print the average days in courses for each student, and to look at the roster for invalid email addresses. The program needed to be able to add students based on a comma-separated list of student information in a certain order.

## 3. My solution
&nbsp;&nbsp;&nbsp;&nbsp;My program correctly implements classes for the roster and the students. Mutators and accessors properly modify and call the information in each class. My enumerated class stored the potential degree programs as objects instead of strings. When it came to calling the degree program objects for printing, I considered a few different options. The option which used the least amount of code was simply making a list of the objects as strings and mapping each to the corresponding object.

&nbsp;&nbsp;&nbsp;&nbsp;In my [main.cpp file](https://github.com/anthonyysz/Class-Roster-Handler/blob/master/source/main.cpp), I was able to add all the students to the roster and perform some functions to ensure the rest of the code works properly. Below shows what the console will display.

## 4. Looking ahead
&nbsp;&nbsp;&nbsp;&nbsp;This project gave me my first experience in C++, and the time spent figuring this out was extraordinarily helpful. I'd like to try another project like this that instead takes the students though a user-typed input, but I'm sure when I get there I'll have expanded my programming abilities to doing bigger and better things.
