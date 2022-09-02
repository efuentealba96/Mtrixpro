#include <Rcpp.h>
using namespace Rcpp;
//' [[Rcpp::export]]
//' @name mMatrix_rcpp
//' @title mMatrix_rcpp
//' @description Esta funcion ejecuta la multipliacion de dos matrices
//' @param A es una matriz numerica de dimención nxm
//' @param B es una matriz numerica de dimención mxm
//' @return regresa una matriz resultante de la multipliacion
//' @examples
//' A <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
//' V <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
//' set.seed(123)
//' result <- mMatrix_rcpp(A,B)
//' result
//' @export
NumericMatrix mMatrix_rcpp(NumericMatrix A,NumericMatrix B){
  NumericMatrix C (A.nrow(),B.ncol());
  if(A.nrow() == B.ncol()){
    for(int i = 0; i < A.nrow(); i++){
      for(int j = 0; j < B.ncol();j++){
        for(int k = 0;k < B.ncol();k++){
          C(i,j) += A(i,k) * B(k,j);
        }
      }
    }
  }else{
    Rcout << "No operable";
  }
  return C;
}
