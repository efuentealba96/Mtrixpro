#include <Rcpp.h>
using namespace Rcpp;
//' [[Rcpp::export]]
//' @name maxMin_cpp
//' @title maxMin_cpp
//' @description Esta funcion se encarga de buscar el maximo de los minimos de ambas matrices
//' para devolver una matriz diferente con los valores encontrados.
//' @param A es una matriz numerica de dimención nxn
//' @param B es una matriz numerica de dimención nxn
//' @return regresa una matriz numerica de dimencion nxn
//' @examples
//' A <- matrix(round(runif(n, min = 0, max = 1), 1), nrow = 3, ncol = 3)
//' B <- matrix(round(runif(n, min = 0, max = 1), 1), nrow = 3, ncol = 3)
//' diag(A) <- 1
//' diag(B) <- 1
//' set.seed(123)
//' result <- maxMin_cpp(A,B)
//' result
//' @export
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


