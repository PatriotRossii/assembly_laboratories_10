#include <immintrin.h>
#include <stdio.h>

void complex_multiplication(__m256 vec1, __m256 vec2, __m256 *add, __m256 *sub, __m256 *mul, __m256 *div) {
	*add = _mm256_add_ps(vec1, vec2);
	*sub = _mm256_sub_ps(vec1, vec2);
	*mul = _mm256_mul_ps(vec1, vec2);
	*div = _mm256_div_ps(vec1, vec2);
}

int main() {
  __m256 evens = _mm256_setr_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
  __m256 odds = _mm256_setr_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

  __m256 add, sub, mul, div;
  complex_multiplication(evens, odds, &add, &sub, &mul, &div);

  for (int i = 0; i != 8; ++i) {
  	printf(
  		"add = %f, sub = %f, mul = %f, div = %f\n",
  		((float*)&add)[i], ((float*)&sub)[i], ((float*)&mul)[i], ((float*)&div)[i]
  	);
  }
}