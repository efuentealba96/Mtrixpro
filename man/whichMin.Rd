% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{whichMin}
\alias{whichMin}
\title{whichMin}
\usage{
whichMin(A)
}
\arguments{
\item{A}{es una matriz numerica de dimención nxm}
}
\value{
retorna un data.frame
}
\description{
Esta funcion devuelve un data.frame en donde se encuentran las 
coordenadas de los valores minimos ubicados dentro de la matriz.
}
\examples{
matriz <- matrix(round(runif(9, 1, 10)), nrow = 3, ncol = 3)
set.seed(123)
matriz
result <- whichMin(matriz)
result
}
