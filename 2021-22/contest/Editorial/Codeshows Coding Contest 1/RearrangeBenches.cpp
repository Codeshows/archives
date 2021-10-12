Method 1:

#include<bits/stdc++.h>
using namespace std;

vector < vector < int >> REARRANGE (vector < vector < int >>&A, int p, int q)
{
  int m = A.size (), n = A[0].size ();
  int s=m*n;
  
  vector < vector < int >>B (p, vector < int >(q, 0));
  int x=0,y=0;
  for (int i = 0; i < m; i++)
    {
        for(int j=0;j<n;++j)
      {

         B[x][y] = A[i][j];
         y++;
         
          if (y == q) 
          {
                    y = 0;    // updating x and y when we reached the end of a row
                    x++;
          }
      }
    }
  return B;
  
}


int main ()
{
  int m, n, p, q;
  cin >> m >> n >> p >> q;

  vector < vector < int >>A (m , vector < int >(n , 0));

  for (int i = 0; i < m; ++i)	//taking input of 2-d array.
    {
      for (int j = 0; j < n; ++j)
	{
	  cin >> A[i][j];
	}
    }

  int s = m * n;		//s gives the number of elements present in the given matrix A. 

  int rearrange_size = p * q;	//rearrange_size gives the number of elements that has to be present in the final matrix B.

  if (rearrange_size != s)	//if the no. of elements are not equal in the given and the final matrix then it is not possible to rearrange the given matrix and so we return the original matrix.
  {
      
      for (int i = 0; i < m; ++i)	//output A itself.
	 {
	   for (int j = 0; j < n; ++j)
	    {
	      cout << A[i][j] << " ";
	    }
	   cout << endl;
	 }
	 exit(0);
  }



  vector < vector < int >>B(p,vector<int>(q,0));

  B = REARRANGE (A, p, q); //calling the rearrange function

  for (int i = 0; i < p; ++i)	//output the final 2-d array B.
    {
      for (int j = 0; j < q; ++j)
	{
	  cout << B[i][j] << " ";
	}
      cout << endl;
    }
  return 0;
}

------------------------------------------------------------------------

Method 2:

#include<bits/stdc++.h>
using namespace std;

vector < vector < int >> REARRANGE (vector < vector < int >>&A, int p, int q)
{
  int m = A.size (), n = A[0].size ();
  int s=m*n;
  
  vector < vector < int >>B (p, vector < int >(q, 0));
  
  for (int i = 0; i < s; i++)
    {
      //i/q will give us the row number of output matrix(B). We will move to New row after every q elements and thus dividing by q will give the row number.

      //i%q will give us the column number of output matrix(B). We will be begin from start of new row after every q elements and this the remainder will give column of current row.

      //The same happens in i/n and i%n but for the A matrix

      B[i / q][i % q] = A[i / n][i % n];
    }
  return B;
  
}


int main ()
{
  int m, n, p, q;
  cin >> m >> n >> p >> q;

  vector < vector < int >>A (m , vector < int >(n , 0));

  for (int i = 0; i < m; ++i)	//taking input of 2-d array.
    {
      for (int j = 0; j < n; ++j)
	{
	  cin >> A[i][j];
	}
    }

  int s = m * n;		//s gives the number of elements present in the given matrix A. 

  int rearrange_size = p * q;	//rearrange_size gives the number of elements that has to be present in the final matrix B.

  if (rearrange_size != s)	//if the no. of elements are not equal in the given and the final matrix then it is not possible to rearrange the given matrix and so we return the original matrix.
  {
      
      for (int i = 0; i < m; ++i)	//output A itself.
	 {
	   for (int j = 0; j < n; ++j)
	    {
	      cout << A[i][j] << " ";
	    }
	   cout << endl;
	 }
	 exit(0);
  }



  vector < vector < int >>B(p,vector<int>(q,0));

  B = REARRANGE (A, p, q); //calling the rearrange function

  for (int i = 0; i < p; ++i)	//output the final 2-d array B.
    {
      for (int j = 0; j < q; ++j)
	{
	  cout << B[i][j] << " ";
	}
      cout << endl;
    }
  return 0;
}

