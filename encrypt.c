#include <string.h>
#include <stdio.h>
#include <stdlib.h>
    void decrypt(FILE * decrypted, FILE *encrypted);
int main(){
    FILE *decrypted = fopen("file.txt", "r");
    FILE *encrypted = fopen("encrypted.txt", "w");
    decrypt(decrypted, encrypted);
}
void decrypt(FILE *decrypted, FILE *encrypted){
    char copy;
    char decrypt[32];

        for(int i = 0; (copy = fgetc(decrypted)) != EOF; i++){
            fputc(copy, encrypted);
            decrypt[i] = copy + (i - 18);
            fputc(decrypt[i], decrypted);
    }

    printf("%s\n", decrypt);

}
