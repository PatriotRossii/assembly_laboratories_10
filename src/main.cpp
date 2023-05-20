#include <immintrin.h>
#include <iostream>

extern "C" void calculate_(volatile __m256 *vec1, volatile __m256 *vec2, __m256 *add, __m256 *sub, __m256 *mul, __m256 *div);

static void OutputVector(
  const char* msg,
  volatile __m256 *array
) {
  std::cout << msg;
  for (int i = 0; i != 8; ++i) {
    std::cout << (*array)[i] << ' ';
  }
  std::cout << '\n';
}

static void PrintResult(
	const char* msg,
  volatile __m256 *b, volatile __m256 *a,
  __m256 *add, __m256 *sub, __m256 *mul, __m256 *div
) {
  std::cout << msg << '\n';

  OutputVector("a = ", a);
  OutputVector("b = ", b);

  std::cout << '\n';

  OutputVector("a + b = ", add);
  OutputVector("a - b = ", sub);
  OutputVector("a * b = ", mul);
  OutputVector("a / b = ", div);

  std::cout << '\n' << std::endl;
}

int main() {
  {
    volatile __m256 evens = _mm256_setr_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
    volatile __m256 odds = _mm256_setr_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);
    __m256 add, sub, mul, div;
    calculate_(&odds, &evens, &add, &sub, &mul, &div);
    PrintResult("Пример 1", &odds, &evens, &add, &sub, &mul, &div);
  }
  {
    volatile __m256 vec1 = _mm256_setr_ps(75.0, 24.0, 51.0, 19.0, 48.0, 11.0, 11.0, 75.0);
    volatile __m256 vec2 = _mm256_setr_ps(27.0, 62.0, 5.0, 83.0, 55.0, 25.0, 46.0, 69.0);
    __m256 add, sub, mul, div;
    calculate_(&vec2, &vec1, &add, &sub, &mul, &div);
    PrintResult("Пример 2", &vec2, &vec1, &add, &sub, &mul, &div);
  }
}