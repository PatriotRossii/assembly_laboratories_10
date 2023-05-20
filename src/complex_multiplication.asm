global complex_multiplication_

complex_multiplication_:
	vmovaps ymm1, [rdi]
	vmovaps ymm0, [rsi]

	vaddps  ymm2, ymm0, ymm1
	vmovaps [rdx], ymm2
	vsubps  ymm2, ymm0, ymm1
	vmovaps [rcx], ymm2
	vmulps  ymm2, ymm0, ymm1
	vdivps  ymm0, ymm0, ymm1
	vmovaps [r8], ymm2
	vmovaps [r9], ymm0
	ret
