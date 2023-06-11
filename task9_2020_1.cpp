// matrix multiplication
#include <iostream>
#include <array>

template <size_t M, size_t N, typename Field = double>
class Matrix {
  std::array<std::array<Field, N>, M> m;

  Matrix operator*(const Matrix& other) {
    if (m[0].size() != other.m.size()) { // check if the sizes are ok
      throw;
    }
    Matrix<m[0].size(), other.m.size()> result; // create a matrix of the needed size
    Field cell_result;
    for (size_t row = 0; row < m[0].size(); ++row) {
      for (size_t column = 0; column < other.m.size(); ++column) {
        cell_result = 0;
        for (size_t elem_row; elem_row < m.size(); ++elem_row) {
          for (size_t elem_column; elem_column < other.m[0].size(); ++elem_column) {
            cell_result += m[row][elem_column] + m[elem_row][column];
          }
        }
        result[row][column] = cell_result;
      }
    } // this may be cringe but the idea is here.
    return result;
  }
};