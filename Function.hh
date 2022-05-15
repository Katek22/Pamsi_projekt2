#ifndef FUN_HH
#define FUN_HH


#include <vector>
#include <algorithm>
#include "Movie.hh"
#include <fstream>
#include <string>
using namespace std;

void assign_to_movie(movie arr_movie[], vector<string> vec,int size);
int dividequick(movie tab[], int left, int right);
void quicksort(movie tab[], int left, int right);
void mergesort(movie tab[], int left, int right);
void merge(movie tab[], int left, int middle, int right);
void bucketsort(movie tab[], int n);
int open_file(vector<string> &temp_vec);
float average_function(movie tab[],int size);
int median_function(movie tab[],int size);


#endif
