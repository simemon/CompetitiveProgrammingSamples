#include <iostream>
#include <unordered_set>
#define N 4

using namespace std;

void printMatrix(int matrix[N][N])
{
  for(int i=0; i < N; i++)
  {
    for(int j=0; j < N; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void nullifyRow(int matrix[N][N], int row)
{
  for(int i=0;i<N;++i)
    matrix[row][i] = 0;  
}

void nullifyCol(int matrix[N][N], int col)
{
  for(int i=0;i<N;++i)
    matrix[i][col] = 0;  
}

void nullifyMatrix(int matrix[N][N])
{
  bool firstRowZero = false;
  bool firstColZero = false;
  for(int i=0; i < N; i++)
  {
    if(matrix[0][i] == 0)
      firstRowZero = true;
    
    if(matrix[i][0] == 0)
      firstColZero = true;

    if(firstRowZero and firstColZero)
      break;
  }
  
  cout << firstRowZero << endl;
  cout << firstColZero << endl;
  
  for(int i =1 ; i < N; ++i)
  {
    for(int j = 1; j < N; ++j)
    {
      if(matrix[i][j] == 0)
      {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  
  for(int i=1; i< N; ++i)
  {
    if(matrix[i][0] == 0)
      nullifyRow(matrix, i);
  }
  
  for(int i=1; i< N; ++i)
  {
    if(matrix[0][i] == 0)
      nullifyCol(matrix, i);
  }
  
  if(firstRowZero)
    nullifyRow(matrix, 0);
  
  if(firstColZero)
    nullifyCol(matrix, 0);
}


int main() 
{
  int matrix[N][N] = {
    {1,0,3,4},
    {5,0,7,8},
    {9,10,11,12},
    {13,14,15,0}
  };
  
  printMatrix(matrix);
  
  cout  << "\n\n" << endl;
  
  nullifyMatrix(matrix);
  
  printMatrix(matrix);
  
  return 0;
}
