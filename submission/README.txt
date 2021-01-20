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

(1) TRANSLATION WITH 3D SHAPES

    To adapt to a 3D model, we add an z coordinate for the options of a 3D shape. Where 
    we translate the shape, we do the same as the we did for translating 2D shapes, except 
    this time we add an additional number to specfify the translation of the z coordinate.
    The implemenations of the shape class, already considers the optional addition of 3D 
    shape. This is achieved by including an additional variable within the struct called
    z to take allow 3D shapes. The translate method would then take in a translations to 
    adjust the position.

(2) COLLISION WITH 3D SHAPES

    For a collision, we have a collide class. This class is used for defining how shapes 
    collide. To allow a 3D extentions for the detection of 
    
    (A) circle with circle: 
        we do as we did with considering a 2D position using a bouding circle method. An 
        additional variable to caculate the distance of the z coordinates of both circles 
        and compare it with the distance
    (B) square to square:
        This follows the same procedures provided for a 2D axis-aligned bounding box (AABB). 
        For 3D, we consider ensure the max z for either of the boxes is greater than then
        minium of either of the boxes.
    (C) square to circle
        This follows the same procedures provided for an AABB and sphere with 2D shapes,
        except we add an additonal variable to work out the closest z coordinate between
        the sphere and the cube. Including another variable to work out the distance 
        between the z coordinate and the center.

These 3D extentions for dectecting collision has already been consider and implemmented.
This is shown within the collide.cpp file.

With the 3D extentions implemented, the circle and square class, can both act as a 2D 
circle or square, or with as a 3D sphere or cube.

(3) THE GAME WITH 3D SHAPES
    The game class works with only 2D shapes, however this can be easily adapted, by adding a z
    coordinate to the dimentions we want our shapes to be within in.



