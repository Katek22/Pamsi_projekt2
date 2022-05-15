#include <fstream>
#include <string>
#include <vector>
#include "Function.hh"
#include <time.h>
#include <sys/time.h>

using namespace std;


int main(){

    int count=0;
    int size=0;
    float average;
    int median;

    vector<string> temp_vec;


    count = open_file(temp_vec);
    movie* arr_movie= new movie[count];
    
    cout<<"How many data do you want? (max amount - enter 0)"<<endl;
    cin>>size;
    cout<<endl;
    if(size==0) size=count;
    

    assign_to_movie(arr_movie, temp_vec, size);
    temp_vec.clear();
   
    struct timeval begin,end;
    gettimeofday(&begin,0);

    quicksort(arr_movie,0,size-1);
    //bucketsort(arr_movie,size);
    //mergesort(arr_movie,0,size-1);

    gettimeofday(&end,0);
    long sec=end.tv_sec-begin.tv_sec;
    long microsec=end.tv_usec-begin.tv_usec;
    double elapsed = sec + microsec*1e-6;
    average=average_function(arr_movie,size);
    cout<<"Work time: "<<elapsed<<endl;
    cout<<"Average "<<average<<endl;

    median=median_function(arr_movie,size);
    cout<<"Median "<<median<<endl;


    return 0;
}

/*
    for(int i=size-10; i<size;i++)
    cout<<arr_movie[i].name <<" " << arr_movie[i].rating << endl;
    cout<<"work";
*/
    
    //int *temp_rating;
    //temp_rating = new int[count];
   // cout << arr_movie[499].name << arr_movie[499].rating << endl;
    //for(int i=0;i<count)
    
    //cout<<count<<endl;
 //   string *tab;
 //   tab = new string[count];
  //  copy(temp.begin(), temp.end(),tab);
    //temp.clear();
    //for(int i=0; i<10;i++)
     //  cout<<tab[i]<<endl;
   /*
    int n=10;  //number of array's elements
    int *tab;
    tab = new int[n];
    //for(int i=0;i<n;i++){
     //   cin>>tab[i];
    //}
    int tab1[]={2,5,7,6,9,10,4,2,1,2};
    for(int i=0;i<n;i++)
    {
        tab[i]=tab1[i];
        //cout<<tab1[i]<<" ";
    }
    

    //mergesort(tab,0,n-1);
    //quicksort(tab, 0 ,n-1);
    //bucketsort(tab, n, 10);
    for(int i=0; i<n;i++)
        cout<<tab[i]<<" ";
    */