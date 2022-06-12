#include "../std_lib_facilities.h"
#include "Matrices.h"
namespace Matrices
{
Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    
    a.resize(_rows, vector<double>(_cols));
    
    for (int i = 0; i < _rows; i++)
       {
           
           for(int j=0;j < _cols; j++)
           {
               a[i][j] = 0;
           }
        }
    //vector<vector<double> > matrixA(rows, vector<double>(cols,0));

}
Matrix operator+(const Matrix& a, const Matrix& b)
{
    if(a.getRows()!= b.getRows() || a.getCols() != b.getCols())
    {
         throw ("Incomatable sizes \n");
    }
    else
        {
            Matrix c(a.getRows(),a.getCols());
            //vector<vector<double> > c(a.getRows(), vector<double>(a.getCols()));
            for (int i = 0; i < a.getRows(); i++)
            {
                for(int j=0;j < a.getCols(); j++)
                {
                    c(i,j) = a(i,j) + b(i,j);
                }
            }
            
            return c;

        }
}

Matrix operator*(const Matrix& a, const Matrix& b)
{
   
  
    if (a.getCols()!= b.getRows())
     {
         throw ("incomatable sizes");
         
     }
    else
    {
        Matrix c(a.getRows(), b.getCols());
        int i,j,k;
        double s = 0.0;
        for(k =0; k<b.getCols(); k++)
          {  for(i=0; i<a.getRows(); i++)
             {  
                s = 0.0;
                for(j = 0; j< a.getCols(); j++)
                    {
                        s += a(i,j) * b(j,k);
                    }
                
                c(i,k) = s;
             }
          }
        return c;
    }
}

bool operator==(const Matrix& a, const Matrix& b)
{
    if(a.getRows()!= b.getRows() || a.getCols() != b.getCols())
    {
         
         return false;
    }
    for (int i = 0; i < a.getRows(); i++)
            {
                for(int j=0;j < a.getCols(); j++)
                {
                    if(a(i,j) != b(i,j))
                        return false;
                }
            }
    return true;


}
bool operator!=(const Matrix& a, const Matrix& b)
{
    if(a.getRows()!= b.getRows() || a.getCols() != b.getCols())
    {
         
         return true;
    }
    for (int i = 0; i < a.getRows(); i++)
            {
                for(int j=0;j < a.getCols(); j++)
                {
                    if(a(i,j) != b(i,j))
                        return true;
                }
            }
    return false;
}
ostream& operator<<(ostream& os,Matrix const& a){
 
 int i, j;
 for(i=0; i< a.getRows(); i++)
 {
    cout << "         ";
    for(j=0; j<a.getCols(); j++)
       os << a(i,j) << "\t";
    os << "\n";
   }
 return os;
 }

void Matrix::addCoordinate(double x, double y)
{
    a.resize(rows, vector<double>(cols+1));
    cols++;
    a.at(0).push_back(x);
    a.at(1).push_back(y);
}

RotationMatrix::RotationMatrix(double theta) : Matrix(2,2)
{
    a[0][0] = cos(theta);
    a[0][1] = -sin(theta);
    a[1][0] = sin(theta);
    a[1][1] = cos(theta);
}

ScalingMatrix::ScalingMatrix(double scale) : Matrix(2,2)
{
    a[0][0] = scale;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = scale;
}
TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2,nCols) 
{
    for(int col = 0;col < nCols ; col++)
    {
        a[0][col] = xShift;
    }
    for(int col = 0;col < nCols ; col++)
    {
        a[1][col] = yShift;
    }
}

}
