#include <Rcpp.h>
using namespace Rcpp;
//' [[Rcpp::export]]
//' @name cbind_rcpp
//' @title cbind_rcpp
//' @description Esta fución une un vector y una matriz siempre y cuando el largo
//' del vector sea igual a la candidad de filas que tiene la matriz.
//' @param A es una matriz numerica de dimención nxm
//' @param B es un vector de largo n
//' @return matriz con los datos del vector insertados en una nueva columna
//' @examples
//' matriz <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
//' vector <- c(1:3)
//' set.seed(123)
//' result <- cbind_rcpp(matriz,vector)
//' result
//' @export
NumericMatrix cbind_rcpp(NumericMatrix A,NumericVector B){
  
  if(B.size() == A.nrow()){
    NumericMatrix newMatrix(A.nrow(),A.ncol()+1);
    NumericVector aux;
    for(int i = 0; i < B.size(); i++){
      aux = A.row(i);
      aux.push_back(B(i));
      newMatrix.row(i) = aux;
    }
    return newMatrix;
  }else{
    Rcout<<"length of vector 'B' is diferent that number rows of A";
  }
  
  return 1;
}


