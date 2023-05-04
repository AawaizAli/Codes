#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char chars[5][6];
char word_search[256], end[] = "END";

int right(int i, int j){
    for (int k = 1 ; k < strlen(word_search) - 1 ; k++){
        if((j+k) > 5 || chars[i][j+k] != word_search[k]) {
	        return 0;
	    }
    }
}

int left(int i, int j){
    for (int k = 1 ; k < strlen(word_search) - 1 ; k++){
        if((j-k) < 0 || chars[i][j-k] != word_search[k]) {
	        return 0;
	    }
    }
}

int up(int i, int j){
    for (int k = 1 ; k < strlen(word_search) - 1 ; k++){
        if((i-k) < 0 || chars[i-k][j] != word_search[k]) {
	        return 0;
        }
    }
}

int down(int i, int j){
    for (int k = 1 ; k < strlen(word_search) - 1 ; k++){
        if((i+k) > 4|| chars[i+k][j] != word_search[k]) {
	        return 0;
	    }
    }
}

int main(){
    int index=0, i, j, res, flag1, flag2, flag3, flag4, score = 0;
    char found;
    
    printf("Aawaiz Ali 22k-4573 \n\n");

    while (1)
    {
    
    //assigning random characters
    srand((unsigned) time(NULL));
    for(i = 0 ; i < 5 ; i++){
        for(j = 0 ; j < 6 ; j++){
            chars[i][j] = (char)((rand() % 26)+65);
        }
    }

    //adding roll no.
    chars[4][0] = (char)52;
    chars[4][1] = (char)53;
    chars[4][2] = (char)55;
    chars[4][3] = (char)51;

    //printing array
    for(i = 0 ; i < 5 ; i++){
        for(j = 0 ; j < 6 ; j++){
            printf("%c\t", chars[i][j]);
        }
        printf("\n");
    }

    puts("Enter word: ");
    fgets(word_search, 256, stdin);

    while (strcmp(word_search,end) != 0)
    {
    found = 'N';
    for(i = 0 ; i < 5 ; i++){
        for(j = 0 ; j < 6 ; j++){
            if (chars[i][j] == word_search[0]){
                flag1 = 1;
                flag2 = 1;
                flag3 = 1;
                flag4 = 1;
                flag1 = right(i,j);
                flag2 = left(i,j);
                flag3 = up(i,j);
                flag4 = down(i,j);
                if (flag1 != 0 || flag2 != 0 || flag3 != 0 || flag4 != 0){
                    found = 'Y';
                }
            }
        }
    }

    if (found == 'Y'){
        printf("%s is present! --> Score: %d\n", word_search, ++score);
    } else {
        printf("%s is not present! --> Score: %d\n", word_search, --score);
    }

    puts("Enter word: ");
    gets(word_search);

    }
    printf("The score is %d\n\n", score);
    }
}