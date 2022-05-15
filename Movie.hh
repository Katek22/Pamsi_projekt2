#ifndef MOV_HH
#define MOV_HH

#include <iostream>
#include <string>

using namespace std;


//class of the movie, contain two elements and two constructors; string name - name of the film, int rating -  movie rating 
class movie{
    public:
    string name;
    int rating;
    
    movie();
    movie(string _name, int digit);
};


#endif