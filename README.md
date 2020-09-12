<h1>Pathfinder - finding the shortest path between given cities.</h1>

#Quickstart
Just write `make` and binary called 'pathfinder' will be
compiled.
To run programm:
./pathfinder file_name
file_name - file, which contains information about distances
between cities. PS. I attached file with example.

##File Syntax:
number_of_cities$
A-B,x$
B-C,Y$
C-D,Z$
PS. 
$ - newline
number_of_cities - must be number of unique cities.

###Example:
File:
4$
Greenland-Bananal,8$
Fraser-Greenland,10$
Bananal-Fraser,3$
Java-Fraser,5$

Output in stdout will look like:
========================================$
Path: Greenland -> Bananal$
Route: Greenland -> Bananal$
Distance: 8$
========================================$
========================================$
Path: Greenland -> Fraser$
Route: Greenland -> Fraser$
Distance: 10$
========================================$
========================================$
Path: Greenland -> Java$
Route: Greenland -> Fraser -> Java$
Distance: 10 + 5 = 15$
========================================$
========================================$
Path: Bananal -> Fraser$
Route: Bananal -> Fraser$
Distance: 3$
========================================$
========================================$
Path: Bananal -> Java$
Route: Bananal -> Fraser -> Java$
Distance: 3 + 5 = 8$
========================================$
========================================$
Path: Fraser -> Java$
Route: Fraser -> Java$
Distance: 5$
========================================$
