#include "Movie.hh"


//constructor
 movie::movie(){
    rating=0;
    name="";
}

 movie::movie(string _name, int digit){
    name=_name;
    rating=digit;
}
