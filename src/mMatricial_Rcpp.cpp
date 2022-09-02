#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
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

