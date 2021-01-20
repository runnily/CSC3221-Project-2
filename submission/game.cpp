/**
 * Game.h: This module implements the game 
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 9/01/21
 */ 
#ifndef GAME_HEADER
#define GAME_HEADER

#include "game.h"

#endif

using namespace std::chrono; 

Game::Game(coordinate dim, vector<Shape*> shapes):dim(dim){

    this->shapes->swap(shapes);
}

void Game::play() {
    while (shapes->size() > 1) {
        //*shapes = (*this).collide(shapes, dim);
        (*this).bruteForce(shapes);
        (*this).translate();
    }
}

vector<Shape*> Game::collide(vector<Shape*>* group, coordinate ratio) {

    if (group->size() > 4) {
        vector<Shape* >* group1 = new vector<Shape* >(); // take advantage of heap memoery
        vector<Shape* >* group2 = new vector<Shape* >(); // disadvantage more memory use -> or a 2N operation
        ratio.x /= 2;
        split(ratio, group, group1, group2); // split
        if (group1->size() > 1 && group2->size() > 1){ // if most of the shapes lies on one side dont use recursion
            *group1 = (*this).collide(group1, ratio);
            *group2 = (*this).collide(group2, ratio);

            group = new vector<Shape*>();
            group->insert(group->end(), group1->begin(), group1->end());
            group->insert(group->end(), group2->begin(), group2->end());
        } 

        delete group1;
        delete group2;
        group1 = nullptr;
        group2 = nullptr;
    }
    (*this).bruteForce(group);
    return *group;
}

void Game::split(coordinate div, vector<Shape*>* group, vector<Shape*>* group1, vector<Shape* >* group2) {
    
    for (int i = 0; i < group->size(); i++) { // n
        Shape* shape = &(*(*group)[i]);
        num X = 0;
        // performs a split
        if (shape->type() == CIRCLE) {
            Circle* circle = (Circle*) shape;
            X = circle->getCenter().x + circle->getRadius();
        }
        if (shape->type() == SQUARE) {
            Square* square = (Square*) shape;
            X = square->getMaxX();
        }

        // check if X is greater
        if (X >= div.x) {
            group1->push_back(shape);
        } else {
            group2->push_back(shape);
        }
    }
}

void Game::bruteForce(vector<Shape*>* group) {
    vector<int> positions = vector<int>();
    for (int i = 0; i < group->size(); i++) {
        vector<Shape*> collisions = vector<Shape*>(); // collects the vector of shapes
        bool collide = false;
        for (int n = i+1; n < group->size(); n++) { // look at right hand side
            if (find(positions.begin(), positions.end(), n) == positions.end()) { // ensure n has not been deleted
                if (group->at(i)->collide(group->at(n))) { 
                    positions.push_back(n);
                    collide = true;
                    collisions.push_back(group->at(n)); // push back
                }
            }
        } 
        if (collide) {
            (*this).output(group->at(i), collisions);
            delete (*group)[i];
            (*group)[i] = nullptr;
            collide = false;
        }
    }
   removeShapes(group, positions);
}

void Game::output(Shape* shape, vector<Shape*> collisions) {
    Square *square;
    Circle *circle;

    cout << "-----------------------------------------" << endl;
    if (shape->type() == SQUARE) {
        cout << "THE SQUARE WITH COORDS OF: " << endl;
        square = (Square*) shape;
        cout << *square << endl;
    } else {
        cout << "THE CIRCLE WITH COORDS OF: " << endl;
        circle = (Circle*) shape;
        cout << *circle << endl;
    }
    cout << "COLLIDED WITH: " << endl;
    for (int i = 0; i<collisions.size(); i++) {
        if (shape->type() == SQUARE) {
        square = (Square*) collisions[i];
        cout << *square << endl;
        } else {
        circle = (Circle*) collisions[i];
        cout << *circle << endl;
        }
    }
    cout << "-----------------------------------------" << endl;
}


void Game::translate() {
    vector<int> positions = vector<int>();
    for (int i = 0; i < shapes->size(); i++) {
        num maxX = 0;
        num minX = 0;
        num minY = 0;
        num maxY = 0;
        if ((*shapes)[i]->type() == SQUARE) {
            Square* square = (Square*) (*shapes)[i];
            maxX = square->getMaxX();
            maxY = square->getMaxY();
            minX = square->getMinX();
            minY = square->getMinY();
            
        } else {
            Circle* circle = (Circle*) (*shapes)[i];
            maxX = circle->getCenter().x + circle->getRadius();
            maxY = circle->getCenter().y + circle->getRadius();
            minX = circle->getCenter().x;
            minY = circle->getCenter().y;
        }
        num x = (rand() % 5) + 1;
        num y = (rand() % 5) + 1;
        coordinate move = {x, y};

        if ((maxX + move.x) > dim.x) {
            positions.push_back(i);
        }

        if ((maxY + move.y) > dim.y) {
            positions.push_back(i);
        }

        (*shapes)[i]->translate(move);
    }
    removeShapes(shapes, positions);
}

Game::~Game() {
    for (int i = 0; i < shapes->size(); i++) {
        delete (*shapes)[i]; // dereference the shape
        (*shapes)[i] = NULL; // allow shape to equal null
    }
    delete shapes; // delete shapes
    shapes = NULL; // resiagn
}

void Game::removeShapes(vector<Shape*>* group, vector<int> positions) {
    for (int i = 0; i < positions.size(); i++) {
        int pos = positions[i];
        delete group->at(pos);
        group->at(pos) = nullptr;
    }
    group->erase(std::remove(group->begin(), group->end(), nullptr), group->end()); // remove empty elements
}

/**
 * SetUp: This is a helper function which is called by main. This would allows us to 
 *        set up an vector of square and circles with random numbers. The dimentions 
 *        of the shape must be the same as the dimention of the dimention being used for 
 *          
 */
vector<Shape*> setup(int numberOfSquares, int numberOfCircle, coordinate dim) {
    vector<Shape*> shapes;
    for (int i = 0; i<numberOfSquares; i++) {
        num minY = (rand() % (int) (dim.y/2)) + 1;
        num minX = (rand() % (int) (dim.x/2)) + 1;
        num maxX = minX + minY;
        num maxY = minY + minY;
        vector<coordinate> coords = {coordinate {minX,maxY}, coordinate{maxX,maxY}, coordinate{minX,minY}, coordinate{maxX,minY}};
        Square* s = new Square(coords);
        shapes.push_back(&(*s));
        s = NULL; // ensure s is pointing at nothing
    }
    for (int i = 0; i<numberOfCircle; i++) { 
        num x = (rand() % (int) (dim.x/2)) + 1;
        num y = (rand() % (int) (dim.y/2)) + 1;
        coordinate center = {x, y};
        vector<coordinate> coords(1);
        coords[0] = center;
        num radius = (rand() % (int) (dim.x)) + 1;
        Circle* c = new Circle(coords, radius);
        shapes.push_back(&(*c));
        c = NULL; // ensure c is now pointing at nothing
    }
    return shapes;

}

int main() {
    coordinate dim = {500,500}; // <-- adjust size here
    int numberOfSqaure = 50;
    int numberOfCircle = 60;
    vector<Shape*> v = setup(numberOfSqaure , numberOfCircle, dim); 
    Game start = Game(dim, v);
    start.play();
   
    return 0;
}