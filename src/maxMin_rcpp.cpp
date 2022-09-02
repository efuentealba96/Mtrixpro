#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
NumericMatrix maxMin_cpp(NumericMatrix matrixA, NumericMatrix matrixB){
  int n = matrixA.nrow();
  int m = matrixA.ncol();
  int l = matrixB.ncol();
  
  NumericMatrix matrixC(n);
  
  for(int i = 0; i < n; i++){
    for(int k = 0; k < l; k++ ){
      NumericVector temp(n);
      for(int j = 0; j < m; j++){
        if(matrixA(i,j) < matrixB(j,k)){
          temp.insert(j,matrixA(i,j));
        }else{
          temp.insert(j,matrixB(j,k));
        }
      }
      matrixC(i,k) = max(temp);
    }
  }
  return matrixC;
}


