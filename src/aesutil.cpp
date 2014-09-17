#include <stdio.h>
#include "aes.h"
/*
int main(int argc, char *argv[])
{
    //char mingwen[] = "360TOP1�ݳ�Ʒ";
    char mingwen[] = "www.baidu.com";
    char miwen_hex[1024];
    //char miwen_hex[] = "8FEEEFE524F8B68DC1FCA2899AC1A6B82E636F6D";
    char result[1024];
    unsigned char key[] = "hsylgwk-20120101";
    //unsigned char key[] = "111222";
    AES aes(key);
	aes.Bm53Cipher(mingwen,miwen_hex);
    printf("%s\n",miwen_hex);
    //aes.Bm53InvCipher("27781ec819a6cca1c56f47da4faedf2c", result);
    aes.Bm53InvCipher(miwen_hex, result);
    printf("%s\n",result);
    getchar();
    return 0;
}
*/
unsigned char key[] = {'1', '1', '1', '2', '2', '2', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
AES aes(key);
int cipher_file(const char *srcFile, const char *dstFile);
int incipher_file(const char *srcFile, const char *dstFile);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Not a correct args\n");
        return -1;
    }
    bool cipher = false;
    char result[1024];
    memset(result, 0, sizeof(result));
    if (strcmp(argv[1], "-c") == 0) { // Cipher
        aes.Cipher(argv[2], result);
        cipher = true;
    } else if (strcmp(argv[1], "-i") == 0) { // InvCipher
        aes.InvCipher(argv[2], result);
        cipher = false;
    } else if (strcmp(argv[1], "-if") == 0) {
        printf("inciper file\n");
        incipher_file(argv[2], argv[3]);
        return (-1);
    } else if (strcmp(argv[1], "-cf") == 0) {
        printf("ciper file\n");
        cipher_file(argv[2], argv[3]);
        return (-1);
    }
    printf("srcLen = %d, dstLen = %d\n", strlen(argv[2]), strlen(result));
    printf("The %s result : %s\n", cipher ? "cipher" : "invcipher", result);
}

int cipher_file(const char *srcFile, const char *dstFile) {

    FILE *fpsrc = NULL;
    FILE *fpdst = NULL;
    if ((fpsrc = fopen(srcFile, "r")) == NULL) {
        return -1;
    }

    if ((fpdst = fopen(dstFile, "w")) == NULL) {
        return -2;
    }
    char src[1024 + 1];
    char result[2048 + 1];
    size_t read = -1;
    memset(src, 0, sizeof(src));
    while ((read = fread(src, 1, sizeof(src) - 1, fpsrc)) > 0) {
        src[read] = 0;
        memset(result, 0, sizeof(result));
        aes.Cipher(src, result);
        int outlen = strlen(result);
        printf("read : %d, outlen = %d\n", read, outlen);
        fwrite(result, 1, outlen, fpdst);
        memset(src, 0, sizeof(src));
    }
    fclose(fpsrc);
    fclose(fpdst);
    return 0;
}

int incipher_file(const char *srcFile, const char *dstFile) {

    FILE *fpsrc = NULL;
    FILE *fpdst = NULL;
    if ((fpsrc = fopen(srcFile, "r")) == NULL) {
        return -1;
    }

    if ((fpdst = fopen(dstFile, "w")) == NULL) {
        return -2;
    }
    char src[2048 + 1];
    char result[1024 + 1];
    size_t read = -1;
    memset(src, 0, sizeof(src));
    while ((read = fread(src, 1, sizeof(src) - 1, fpsrc)) > 0) {
        src[read] = 0;
        memset(result, 0, sizeof(result));
        aes.InvCipher(src, result);
        int outlen = strlen(result);
        printf("read : %d, outlen = %d\n", read, outlen);
        fwrite(result, 1, strlen(result), fpdst);
        memset(src, 0, sizeof(src));
    }
    fclose(fpsrc);
    fclose(fpdst);
    return 0;
}

