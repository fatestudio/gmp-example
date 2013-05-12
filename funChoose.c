#include <stdio.h>
#include <gmp.h>
#include <stdbool.h>

bool factorial(mpz_t ret, mpz_t n, mpz_t stop){
	mpz_set_ui(ret, 1);
	mpz_t _1;
	mpz_init(_1);
	mpz_set_ui(_1, 1);

	mpz_t n2;
	mpz_init(n2);
	mpz_set(n2, n);

	while(mpz_cmp(n2, stop) > 0){
		mpz_mul(ret, ret, n2);
		mpz_sub(n2, n2, _1);
	}
	mpz_clear(n2);

	return true;
}

bool choose(mpz_t ret, mpz_t n, mpz_t k){
	mpz_t _0;
	mpz_init(_0);
	
	mpz_t left;
	mpz_init(left);
	factorial(left, n, k);
//	gmp_printf("left: %Zd\n", left);
	
	mpz_t right;
	mpz_init(right);
	mpz_t temp;
	mpz_init(temp);
	mpz_sub(temp, n, k);

	factorial(right, temp, _0);
	mpz_clear(temp);
//	gmp_printf("right: %Zd\n", right);
	printf("size of right: %d\n", mpz_sizeinbase(right, 2));

	mpz_cdiv_q(ret, left, right);
	mpz_clear(left);
	mpz_clear(right);

	return true;
}

int main(){
	mpz_t n;
	mpz_init(n);
	mpz_set_ui(n, 50000);
	mpz_t k;
	mpz_init(k);
	mpz_set_ui(k, 50);
	
	mpz_t res;
	mpz_init(res);
	choose(res, n, k);

	// print a mpz_t number
	gmp_printf("result: %Zd\n", res);
	return 0;
}
