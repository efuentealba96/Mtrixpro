#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
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
