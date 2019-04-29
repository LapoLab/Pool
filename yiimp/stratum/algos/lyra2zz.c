#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "lyra2zz.h"

#include <sha3/sph_blake.h>

#define _ALIGN(x) __attribute__ ((aligned(x)))

extern uint64_t lyra2z_height;

#ifdef __cplusplus
extern "C" {
#endif

extern int LYRA2ZZ(void *K, uint64_t kLen, const void *pwd, uint64_t pwdlen, const void *salt, uint64_t saltlen, uint64_t timeCost, uint64_t nRows, uint64_t nCols);

#ifdef __cplusplus
}
#endif


void lyra2zz_hash(const char* input, char* output, uint32_t len)
{
    sph_blake256_context ctx_blake;

    uint32_t _ALIGN(64) hashA[8], hashB[8];

	sph_blake256_set_rounds(14);

    sph_blake256_init(&ctx_blake);
    sph_blake256 (&ctx_blake, input, 112);
    sph_blake256_close (&ctx_blake, hashA);

	LYRA2ZZ(hashB, 32, hashA, 32, hashA, 32, 8, 8, 8);

	memcpy(output, hashB, 32);
}

#ifdef L2ZZ_TEST

const char *s0 = "0400000036e3b61fc3ec610b42c0e912f6af747e03dedbd3b41746e83c3f75c700000000ba3d9d0cb2feb952445990b0bd16cf774685f7327ee6822dc7d4cfb0f998ca525bcfc96a810a3e1c4072a61640ff68e73d3cfaaef687661de36b4e50f81d1f4a2fc6995109becad5b27e7c66";

int hex2bin(void *output, const char *hexstr, size_t len)
{
	unsigned char *p = (unsigned char *) output;
	char hex_byte[4];
	char *ep;

	hex_byte[2] = '\0';

	while (*hexstr && len) {
		if (!hexstr[1]) {
			printf("hex2bin str truncated");
			return 0;
		}
		hex_byte[0] = hexstr[0];
		hex_byte[1] = hexstr[1];
		*p = (unsigned char) strtol(hex_byte, &ep, 16);
		if (*ep) {
			printf("hex2bin failed on '%s'", hex_byte);
			return 0;
		}
		p++;
		hexstr += 2;
		len--;
	}

	return (len == 0 && *hexstr == 0) ? 1 : 0;
}

static void hash_test()
{
	unsigned char buf[112];
	hex2bin(buf, s0, 112);

	uint32_t _ALIGN(64) output[8];

	lyra2zz_hash((const char*) buf, (char*)output, 112);
}

int main(void)
{
	hash_test();
	return 0;
}

#endif
