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

void rotateMatrix(int matrix[N][N])
{
  int level = N / 2;
  for(int l = 1; l <= level; l++)
  {
    for(int i = l - 1; i < N - l - 1; ++i)
    {
      for(int j = l - 1; j < N - l - 1; ++j)
      {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[N - j - l][i];
        matrix[N - j - l][i] = matrix[N - i - l][N - j - l];
        matrix[N - i - l][N - j - l] = matrix[j][N - i - l];
        matrix[j][N - i - l] = temp;
      }
    }
  }
  
}

int main() 
{
  int matrix[N][N] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  
  printMatrix(matrix);
  
  cout  << "\n\n" << endl;
  
  rotateMatrix(matrix);
  
  printMatrix(matrix);
  
  return 0;
}
