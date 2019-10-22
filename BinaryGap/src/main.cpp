
#include "solutions.h"

#include <iostream>

int main(void)
{
  int result = -1;
  Codility::BinaryGap<1> question1;
  Codility::BinaryGap<2> question2;
  result = question1.solution(1);
  std::cout << "result: " << result << std::endl;

  result = question2.solution(1);
  std::cout << "result: " << result << std::endl;

  return 0;
}
