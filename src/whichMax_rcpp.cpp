#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
DataFrame whichMax(NumericMatrix matrix_A){
  NumericVector rows(matrix_A.nrow(),NumericVector::get_na());
  NumericVector columns(matrix_A.nrow(),NumericVector::get_na());
  double value = matrix_A(0,0);
  int filas = matrix_A.nrow();
  int columnas = matrix_A.ncol();
  
  for(int i = 0;i < filas; i++){
    for(int j = 0; j < columnas;j++){

      if(matrix_A(i,j) == value){
        rows.push_back(i+1);
        columns.push_back(j+1);
        
      }else if(matrix_A(i,j) > value){
        value = matrix_A(i,j);
        rows.erase(0,rows.size());
        columns.erase(0,columns.size());
        rows.push_back(i+1);
        columns.push_back(j+1);
      }
    }
  }
  DataFrame maxValues = DataFrame::create(Named("fila")=na_omit(rows),Named("columnas") = na_omit(columns));
  return maxValues;
}
