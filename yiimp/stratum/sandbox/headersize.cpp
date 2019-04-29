#include <stdio.h>
#include <stdint.h>


int main() {
	struct __attribute__((__packed__)) {
		uint32_t version;
		char prevblock[32];
		char merkleroot[32];
		char stakeroot[32];
		uint16_t votebits;
		char finalstate[6];
		uint16_t voters;
		uint8_t freshstake;
		uint8_t revoc;
		uint32_t poolsize;
		uint32_t nbits;
		uint64_t sbits;
		uint32_t height;
		uint32_t size;
		uint32_t ntime;
		uint32_t nonce;
		unsigned char extra[32];
		uint32_t stakever;
		uint32_t hashtag[3];
	} header;

	printf("wew: %i\n", sizeof(header));

	return 0;
}
