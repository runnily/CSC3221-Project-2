CONTENTS
1. FILES AND EXPLANATION
2. COMPILING TEST AND APPLICATION
3. PROCESS TO A 3D EXTENTION
4. UNDERSTANDING THE TEST FILES
------------------------------------------------------------------------------
FILES AND EXPLANATION

(1) circle.cpp  -   An implementation of a circle shape
(2) circle.h    -   Contains the definition of a circle shape
(3) collide.cpp -   An implementation to check if a shape collides or not.
(4) collide.h   -   Contains the defintion of shapes colliding
(5) game.cpp    -   An implementation of the game
(6) game.h      -   Contains the defintions of how the game works
(7) Makefile    -   To compile all the files
(8) shape.cpp   -   An abstract class implemenations of shape
(9) shape.h     -   Conatins the definition and an abstract shape class
(10) square.cpp -   An implemenations of a square shape
(11) square.h   -   Contains the definition of a square shape
(12) test.txt   -   An example output of a game
------------------------------------------------------------------------------
COMPILING TEST AND APPLICATION

Within this directory, there should be a Makefile. This will allow you to 
compile the test program. The relevant make command will create an output application. 

You could do this using source code either (vscode etc) and open a terminal, or using
your local terminal on your machine. 

To compile tests, enter the following at the command line prompt in the submission directory:
    # make

To clean up before compiling do:
    # make clean

Assuming compilation is done. The following binary output application and -o files will be 
included in this directory:

    circle.o    
    game.o     
    shape.o
    square.o
    test (The output game application)

Within the command line you could run the output application
    # ./test 
This would run the test file and show the output within terminal

OR you could run 
    # ./test > test.txt
This would allow the output of the test to show within the test.txt file.
------------------------------------------------------------------------------
PROCESS TO A 3D EXTENTION

To adapt to a 3D model, we add an z coordinate for optional 3D shape.

