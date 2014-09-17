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
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Not a correct args\n");
        return -1;
    }
    bool cipher = false;
    unsigned char key[] = {'1', '1', '1', '2', '2', '2', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    char result[1024];
    memset(result, 0, sizeof(result));
    AES aes(key);
    if (strcmp(argv[1], "-c") == 0) { // Cipher
        aes.Bm53Cipher(argv[2], result);
        cipher = true;
    } else if (strcmp(argv[1], "-i") == 0) { // InvCipher
        aes.Bm53InvCipher(argv[2], result);
        cipher = false;
    } else {
        printf("Not a correct args\n");
        return (-1);
    }
    printf("The %s result : %s\n", cipher ? "cipher" : "invcipher", result);
}

int cipher(char *srcFile, char *dstFile) {
    return 0;
}
