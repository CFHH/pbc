#include <pbc.h>
#include <pbc_test.h>

#define RAND_GENETATE_PAIRING 0

int testbls();

int main()
{
    int result = testbls();
    return result;
}

int testbls()
{
    int result = 0;
    pairing_s pairing;
#if RAND_GENETATE_PAIRING
    pbc_param_s params;
    pbc_param_init_a_gen(&params, 160, 512);
    pairing_init_pbc_param(&pairing, &params);
#else
    const char *input = "type a\n\
        q 8780710799663312522437781984754049815806883199414208211028653399266475630880222957078625179422662221423155858769582317459277713367317481324925129998224791\n\
        h 12016012264891146079388821366740534204802954401251311822919615131047207289359704531102844802183906537786776\n\
        r 730750818665451621361119245571504901405976559617\n\
        exp2 159\n\
        exp1 107\n\
        sign1 1\n\
        sign0 1\n";
    result = pairing_init_set_buf(&pairing, input, strlen(input));
    if (result != 0)
    {
        return result;
    }
#endif

    element_s g;
    element_init_G2(&g, &pairing);
    element_set0(&g);
    element_random(&g);

    element_s privKey;
    element_init_Zr(&privKey, &pairing);
    element_set0(&privKey);
    element_random(&privKey);

    element_s pubKey;
    element_init_G2(&pubKey, &pairing);
    element_set0(&pubKey);
    element_pow_zn(&pubKey, &g, &privKey);

    element_s h;
    element_init_G1(&h, &pairing);
    element_set0(&h);
    const char* message = "some text to sign";
    //todo hash
    void* hash = (void*)message;
    int hashlen = strlen(message);
    element_from_hash(&h, hash, hashlen);

    element_s signature;
    element_init_G2(&signature, &pairing);
    element_set0(&signature);
    element_pow_zn(&signature, &h, &privKey);

    element_s temp1;
    element_init_GT(&temp1, &pairing);
    element_set0(&temp1);
    pairing_apply(&temp1, &h, &pubKey, &pairing);

    element_s temp2;
    element_init_GT(&temp2, &pairing);
    element_set0(&temp2);
    pairing_apply(&temp2, &signature, &g, &pairing);

    result = element_cmp(&temp1, &temp2);
    if (result != 0)
    {
        return result;
    }

    element_s hf;
    element_init_G1(&hf, &pairing);
    element_set0(&hf);
    const char* hashf = "some text to sign fake";
    element_from_hash(&hf, (void*)hashf, strlen(hashf));
    element_s tempf;
    element_init_GT(&tempf, &pairing);
    element_set0(&tempf);
    pairing_apply(&tempf, &hf, &pubKey, &pairing);
    result = element_cmp(&tempf, &temp2);
    if (result == 0)
    {
        return result;
    }
    element_clear(&tempf);
    element_clear(&hf);

    element_clear(&temp2);
    element_clear(&temp1);
    element_clear(&signature);
    element_clear(&h);
    element_clear(&pubKey);
    element_clear(&privKey);
    element_clear(&g);
    pairing_clear(&pairing);
#if RAND_GENETATE_PAIRING
    pbc_param_clear(&params);
#endif
    return 0;
}

int BlsExample(int argc, char **argv) {
    pairing_t pairing;
    element_t g, h;
    element_t public_key, sig;
    element_t secret_key;
    element_t temp1, temp2;

    pbc_demo_pairing_init(pairing, argc, argv);

    element_init_G2(g, pairing);
    element_init_G2(public_key, pairing);
    element_init_G1(h, pairing);
    element_init_G1(sig, pairing);
    element_init_GT(temp1, pairing);
    element_init_GT(temp2, pairing);
    element_init_Zr(secret_key, pairing);

    printf("Short signature test\n");

    //generate system parameters
    element_random(g);
    element_printf("system parameter g = %B\n", g);

    //generate private key
    element_random(secret_key);
    element_printf("private key = %B\n", secret_key);

    //compute corresponding public key
    element_pow_zn(public_key, g, secret_key);
    element_printf("public key = %B\n", public_key);

    //generate element from a hash
    //for toy pairings, should check that pairing(g, h) != 1
    element_from_hash(h, (void *)"hashofmessage", 13);
    element_printf("message hash = %B\n", h);

    //h^secret_key is the signature
    //in real life: only output the first coordinate
    element_pow_zn(sig, h, secret_key);
    element_printf("signature = %B\n", sig);

    {
        int n = pairing_length_in_bytes_compressed_G1(pairing);
        //int n = element_length_in_bytes_compressed(sig);
        int i;
        unsigned char *data = (unsigned char *)pbc_malloc(n);

        element_to_bytes_compressed(data, sig);
        printf("compressed = ");
        for (i = 0; i < n; i++) {
            printf("%02X", data[i]);
        }
        printf("\n");

        element_from_bytes_compressed(sig, data);
        element_printf("decompressed = %B\n", sig);

        pbc_free(data);
    }

    //verification part 1
    element_pairing(temp1, sig, g);
    element_printf("f(sig, g) = %B\n", temp1);

    //verification part 2
    //should match above
    element_pairing(temp2, h, public_key);
    element_printf("f(message hash, public_key) = %B\n", temp2);

    if (!element_cmp(temp1, temp2)) {
        printf("signature verifies\n");
    }
    else {
        printf("*BUG* signature does not verify *BUG*\n");
    }

    {
        int n = pairing_length_in_bytes_x_only_G1(pairing);
        //int n = element_length_in_bytes_x_only(sig);
        int i;
        unsigned char *data = (unsigned char *)pbc_malloc(n);

        element_to_bytes_x_only(data, sig);
        printf("x-coord = ");
        for (i = 0; i < n; i++) {
            printf("%02X", data[i]);
        }
        printf("\n");

        element_from_bytes_x_only(sig, data);
        element_printf("de-x-ed = %B\n", sig);

        element_pairing(temp1, sig, g);
        if (!element_cmp(temp1, temp2)) {
            printf("signature verifies on first guess\n");
        }
        else {
            element_invert(temp1, temp1);
            if (!element_cmp(temp1, temp2)) {
                printf("signature verifies on second guess\n");
            }
            else {
                printf("*BUG* signature does not verify *BUG*\n");
            }
        }

        pbc_free(data);
    }

    //a random signature shouldn't verify
    element_random(sig);
    element_pairing(temp1, sig, g);
    if (element_cmp(temp1, temp2)) {
        printf("random signature doesn't verify\n");
    }
    else {
        printf("*BUG* random signature verifies *BUG*\n");
    }

    element_clear(sig);
    element_clear(public_key);
    element_clear(secret_key);
    element_clear(g);
    element_clear(h);
    element_clear(temp1);
    element_clear(temp2);
    pairing_clear(pairing);
    return 0;
}

