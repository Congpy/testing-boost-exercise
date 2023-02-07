#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(printData)
{
  std::string test;
  MatrixXd A(3,3), expectedA;
  
  A << 1, 2, 3,
    4, 5, 6,
    7, 8, 9;

  matrixIO::saveData("../csvText.csv", A);
  expectedA = matrixIO::openData("../csvText.csv", 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(A(i, j) == expectedA(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
