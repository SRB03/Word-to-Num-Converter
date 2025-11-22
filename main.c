#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
int word_to_number(const char *word);
void to_lowercase(char *str);
long long convert_words_to_number(const char *input);

int main() {
    char input[512];
    printf("Enter number in words: ");
    if (!fgets(input, sizeof(input), stdin)) return 0;

    long long result = convert_words_to_number(input);
    printf("Numeric value: %lld\n", result);
    return 0;
}


void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}


int word_to_number(const char *word) {
    if (!strcmp(word, "one")) return 1;
    if (!strcmp(word, "two")) return 2;
    if (!strcmp(word, "three")) return 3;
    if (!strcmp(word, "four")) return 4;
    if (!strcmp(word, "five")) return 5;
    if (!strcmp(word, "six")) return 6;
    if (!strcmp(word, "seven")) return 7;
    if (!strcmp(word, "eight")) return 8;
    if (!strcmp(word, "nine")) return 9;
    if (!strcmp(word, "ten")) return 10;
    if (!strcmp(word, "eleven")) return 11;
    if (!strcmp(word, "twelve")) return 12;
    if (!strcmp(word, "thirteen")) return 13;
    if (!strcmp(word, "fourteen")) return 14;
    if (!strcmp(word, "fifteen")) return 15;
    if (!strcmp(word, "sixteen")) return 16;
    if (!strcmp(word, "seventeen")) return 17;
    if (!strcmp(word, "eighteen")) return 18;
    if (!strcmp(word, "nineteen")) return 19;
    if (!strcmp(word, "twenty")) return 20;
    if (!strcmp(word, "thirty")) return 30;
    if (!strcmp(word, "forty")) return 40;
    if (!strcmp(word, "fifty")) return 50;
    if (!strcmp(word, "sixty")) return 60;
    if (!strcmp(word, "seventy")) return 70;
    if (!strcmp(word, "eighty")) return 80;
    if (!strcmp(word, "ninety")) return 90;
    if (!strcmp(word, "hundred")) return 100;
    if (!strcmp(word, "thousand")) return 1000;
    if (!strcmp(word, "lakh")) return 100000;
    if (!strcmp(word, "lakhs")) return 100000;
    if (!strcmp(word, "crore")) return 10000000;
    if (!strcmp(word, "crores")) return 10000000;
    if (!strcmp(word, "million")) return 1000000;
    if (!strcmp(word, "millions")) return 1000000;
    if (!strcmp(word, "billion")) return 1000000000;
    if (!strcmp(word, "billions")) return 1000000000;
    return -1;
}

long long convert_words_to_number(const char *input) {
    char buf[512];
    strncpy(buf, input, sizeof(buf)-1);
    buf[sizeof(buf)-1] = '\0';

    char *token = strtok(buf, " \n");
    long long total = 0;
    long long current = 0;

    while (token != NULL) {
        to_lowercase(token);
        int value = word_to_number(token);

        if (value == 100) {
            if (current == 0) current = 1;
            current *= 100;
        } else if (value >= 1000) {
            if (current == 0) current = 1;
            current *= (long long)value;
            total += current;
            current = 0;
        } else if (value != -1) {
            current += value;
        } else {
            printf("Unrecognized word: %s\n", token);
        }

        token = strtok(NULL, " \n");
    }

    total += current;
    return total;
}
