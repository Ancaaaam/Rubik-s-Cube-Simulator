# Rubik-s-Cube-Simulator

The input contains the codification of cube's colours, the initial cube's scramble(given as a 2D string array) and the set of movements.

The Rubik's Cube move notation is :
U- up clockwise
D- down clockwise
R- right clockwise
L- left clockwise
F- front clockwise
B- back clockwise
U'- up counterclockwise
D'- down  counterclockwise
R'-right  counterclockwise
L'-left  counterclockwise
F'- front  counterclockwise
B' - back  counterclockwise

I refer to front face as face 1, back face as face 2, up face as face 3, down face as face 4, left face as face 5 and right face as face 6. I assigned numbers to each colour, in the order they were given by the user
in the first line of the input(1- first colour, 2 - second colour etc) and save the state of cube's scramble in digits codification in a matrix(a[8][5][5]).For every clockwise move, I saved in a matrix the proccessing order of the little sqaures( see the comments after declaring v[8][102]). 

For the counterclockwise movements, I apply the clockwise's algorithms three times.

The program exports the cube's scramble after applying the movements.
