#include <Rcpp.h>
using namespace Rcpp;
//' [[Rcpp::export]]
//' @name rbind_rcpp
//' @title rbind_rcpp
//' @description Esta fución une un vector y una matriz siempre y cuando el largo
//' del vector sea igual a la candidad de columnas que tiene la matriz.
//' @param A es una matriz numerica de dimención nxm
//' @param B es un vector de largo m
//' @return matriz con los datos del vector insertados en una nueva fila
//' @examples
//' matriz <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
//' vector <- c(1:3)
//' set.seed(123)
//' result <- rbind_rcpp(matriz,vector)
//' result
//' @export
NumericMatrix rbind_rcpp(NumericMatrix A,NumericVector B){
  
  if(B.size() == A.ncol()){
    NumericMatrix newMatrix(A.nrow()+1,A.ncol());
    NumericVector aux;
    for(int i = 0; i < B.size(); i++){
      aux = A.column(i);
      aux.push_back(B(i));
      newMatrix.column(i) = aux;
    }
    return newMatrix;
  }else{
    Rcout<<"length of vector 'B' is diferent that number columns of A";
  }
  
  return 1;
}