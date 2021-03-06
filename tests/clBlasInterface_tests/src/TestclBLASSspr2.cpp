#include <iostream>
#include "HPL_clBLAS.h"

#define N 5

int check(bool is_ok)
{
  if(is_ok) {
    std::cout << "Test is PASSED. \n";
    return 0;
  } else {
    std::cout << "Test is FAILED. \n";
    return -1;
  }
}

int test1()
{
  HPL::Array<float, 1> AP((N * N + N) / 2);
  HPL::Array<float, 1> x(N);
  HPL::Array<float, 1> y(N);
  


  for(int i = 0; i < (N*N+N)/2; i++) {
    AP(i) = i + 1;
  }
  
  for(int i = 0; i < N; i++) {
     x(i) = 1 << i + 1;
     y(i) = 1 << i + 2;
  }

  HPL_clblasSetup();

  clblasSspr2( clblasUpper, x, y, AP);
  
  HPL_clblasTeardown();

  return check((AP(0) == 17.f) && (AP(4) == 261.f) && (AP(7) == 264.f) && (AP(10) == 523.f) && (AP(14) == 4111.f));
}

int test2()
{
  HPL::Array<float, 1> AP((N * N + N) / 2);
  HPL::Array<float, 1> x(N);
  HPL::Array<float, 1> y(N);

  for(int i = 0; i < (N*N+N)/2; i++) {
    AP(i) = i + 1;
  }

  for(int i = 0; i < N; i++) {
     x(i) = 1 << i + 1;
     y(i) = 1 << i + 2;
  }

  HPL_clblasSetup();

  clblasSspr2(clblasLower, x, y, AP);

  HPL_clblasTeardown();

  return check((AP(0) == 17.f) && (AP(4) == 133.f) && (AP(7) == 264.f) && (AP(10) == 267.f) && (AP(14) == 4111.f));
}

int main()
{
    test1();
    test2();
}
