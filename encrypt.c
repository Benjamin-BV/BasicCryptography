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
            fputc(copy, decrypted);
            decrypt[i] = copy - (i - 18);
            if(decrypt[i] > 125){
                decrypt[i] = copy - 2;
            }
            if(decrypt[i] < 32){
                decrypt[i] = copy + 2;
            }
            fputc(decrypt[i], encrypted);
    }

    printf("%s\n", decrypt);

}
