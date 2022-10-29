#include <iostream>     /* array-mean-max-fcn.cpp */
using namespace std;	

const int NUM_STUDENTS = 5;

// score is a constant pointer 
float mean_score(float score[], int size)
{
    float sum_score = 0.0; // Don't forget initializing the sum to 0
    for (int j = 0; j < size; j++)
        sum_score += score[j]; // Accumulate the scores
    return sum_score/size;
}

float max_score(float score[], int size)
{
  cout << "size of array = " <<
    sizeof( score )/sizeof( float ) << endl;  // warning: score is a constant pointer
  
  // Initialize the max score to that of the first student
  float max_score = score[0];
  for (int j = 1; j < size; j++)
    if (max_score < score[j])
      max_score = score[j];
  return max_score;
}

// For static array only
// A reference to a static array must know the size of the array
float max_score_r(float (&score)[NUM_STUDENTS])
{
  int size = sizeof( score )/sizeof( float );
  cout << "size of array = " << size  <<  endl;
  
  // Initialize the max score to that of the first student
  float max_score = score[0];
  for (int j = 1; j < size; j++)
    if (max_score < score[j])
      max_score = score[j];
  return max_score;
}

// For static array only
// Template actually calculates the length of the array automatically at the time of function call
template <size_t N>
float max_score2(float (&score)[N])
{
  int size = sizeof( score )/sizeof( float );
  cout << "size of array = " << size << ";  N= " << N << endl;
  
  // Initialize the max score to that of the first student
  float max_score = score[0];
  for (int j = 1; j < size; j++)
    if (max_score < score[j])
      max_score = score[j];
  return max_score;
}

int main()	
{

  // const int NUM_STUDENTS = 5;

  const int  i = 10;
  const int & j = 10;
  cout << &i << " " << &j << endl;
    
    float score[NUM_STUDENTS];
    
    for (int j = 0; j < NUM_STUDENTS; j++)
        if (!(cin >> score[j])) return -1;
    
    cout << "mean score = " << mean_score(score, NUM_STUDENTS) << "\n\n";
    cout << "max score = "  << max_score(score, NUM_STUDENTS) << "\n";
    cout << "max score = "  << max_score_r(score) << endl;
    cout << "max score = "  << max_score2(score) << endl;


    return 0;
}
