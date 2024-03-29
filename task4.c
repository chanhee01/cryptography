#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM *a) {
    char *number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main() {
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *m1 = BN_new();
    BIGNUM *m2 = BN_new();
    BIGNUM *s1 = BN_new();
    BIGNUM *s2 = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    // I owe you $2000.
    BN_hex2bn(&m1, "49206F776520796F752024323030302E");

    // I owe you $3000.
    BN_hex2bn(&m2, "49206F776520796F752024333030302E");

    BN_mod_exp(s1, m1, d, n, ctx);
    printBN("Signature for $2000: ", s1);

    BN_mod_exp(s2, m2, d, n, ctx);
    printBN("Signature for $3000: ", s2);

    return 0;
}