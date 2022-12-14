% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{mMatrix_rcpp}
\alias{mMatrix_rcpp}
\title{mMatrix_rcpp}
\usage{
mMatrix_rcpp(A, B)
}
\arguments{
\item{A}{es una matriz numerica de dimención nxm}

\item{B}{es una matriz numerica de dimención mxm}
}
\value{
regresa una matriz resultante de la multipliacion
}
\description{
Esta funcion ejecuta la multipliacion de dos matrices
}
\examples{
A <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
B <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
set.seed(123)
A
B
result <- mMatrix_rcpp(A,B)
result
}
