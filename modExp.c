#include <stdio.h>
#include <gmp.h>

int main(){
	mpz_t res;
	mpz_init(res);
	mpz_t base;
	mpz_init(base);
	FILE *fp;
	fp = fopen("modExp.in", "r");
	// read base from file
	mpz_inp_str(base, fp, 0);

	mpz_t exp;
	mpz_init(exp);
	// read exp from file
	mpz_inp_str(exp, fp, 0);
	
	mpz_t mod;
	mpz_init(mod);
	// read mod from file
	mpz_inp_str(mod, fp, 0);

	mpz_powm_sec(res, base, exp, mod);
	gmp_printf("res: %Zx\n", res);

	return 0;
}
