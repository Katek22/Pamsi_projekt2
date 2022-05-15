#include "Function.hh"

// function assign proper records from vector to movie array
void assign_to_movie(movie arr_movie[], vector<string> vec,int size)
{

        for(int i=0;i<size;i++)
    {
        string temp;
        
        int first=vec[i].find_first_of(',');
        int last=vec[i].find_last_of(',');
        string name = vec[i].substr(first+1,last-first-1);
        string value = vec[i].substr(last+1);
        int digit=stoi(value);
        arr_movie[i]=movie(name,digit);
    }

     
}

//auxiliary function to quicksort 
int dividequick(movie tab[], int left, int right)
{
    int pivot = tab[(left + right)/2].rating;
    int beginning = left, end = right;

    while(true)
    {   
        while (tab[end].rating > pivot) end--;      
        while (tab[beginning].rating < pivot) beginning++;

        if(beginning < end) 
        {
            swap(tab[beginning++], tab[end--]);
        }
        else return end;
    }
}

//quicksort function 
void quicksort(movie tab[], int left, int right)
{
    if(left < right)
    {
        int m = dividequick(tab, left, right);
        quicksort(tab, left, m);
        quicksort(tab, m+1, right);
    }
}

//mergesort function
void mergesort(movie tab[], int left, int right){


    if(left >= right)
    return;
    
    int middle = left + (right-left)/2;

    mergesort(tab, left, middle);
    mergesort(tab,middle+1, right);
    merge(tab, left, middle, right);
}

//auxiliary function, which merge arrays
void merge(movie tab[], int left, int middle, int right)
{

    int temp_arr_one = middle - left + 1;
    int temp_arr_two = right - middle;

    movie *left_arr = new movie[temp_arr_one];
    movie *right_arr = new movie[temp_arr_two];

    for(int i=0;i < temp_arr_one;i++)
        left_arr[i] = tab[left+i];
    for(int j=0;j < temp_arr_two;j++)
        right_arr[j] = tab[middle+j+1];

    int index_arr_one = 0, index_arr_two = 0;
    int index_merged_arr = left;

    while(index_arr_one < temp_arr_one && index_arr_two < temp_arr_two)
    {
        if(left_arr[index_arr_one].rating <= right_arr[index_arr_two].rating)
        {
            tab[index_merged_arr] = left_arr[index_arr_one];
            index_arr_one++;
        }
        else
        {
            tab[index_merged_arr] = right_arr[index_arr_two];
            index_arr_two++;
        }
        index_merged_arr++;
    }

    while(index_arr_one < temp_arr_one)
    {
        tab[index_merged_arr] = left_arr[index_arr_one];
        index_merged_arr++;
        index_arr_one++;
    }

    while(index_arr_two < temp_arr_two)
    {
        tab[index_merged_arr] = right_arr[index_arr_two];
        index_merged_arr++;
        index_arr_two++;
    }
}

//bucketsort function
void bucketsort(movie tab[], int n)
{
    vector<movie> bucket[10];
    
    for(int i=0;i<n;i++)
    {
        int temp = tab[i].rating-1;
        bucket[temp].push_back(tab[i]);
    }

    int z=0;

    for(int i=0; i<10;i++)
        for(int j=0; j<bucket[i].size();j++)
            tab[z++]=bucket[i][j];
    
}


//function save and filtr data from file to vector
int open_file(vector<string> &temp_vec )
{
    int count = 0;
    fstream file("projekt2_dane.csv",ios::in);
        if(file.is_open())
    {   
        string str;
        string::iterator it;
        while(getline(file,str))
        {   
            it=str.end();
            it--;
            if(*it=='0')  
            {
               temp_vec.push_back(str);
               count++;
            }
        }
    }
    return count;

}

//function counting average of rating 
float average_function(movie tab[],int size)
{
    int av=0;
    float sum=0,temp=0;
    for(int i=0;i<size;i++)
    temp=temp+tab[i].rating;

    sum=temp/size;

    return sum;
}

//function counting median 
int median_function(movie tab[],int size)
{
    int median=0;
    median=tab[size/2].rating;

    return median;
    
}
