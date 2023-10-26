//Roee shahmoon 206564759
//Noam Klainer 316015411

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main_n;
char ListString[10][20] = { '0' };


int getSize(int a, int b) {
    int flag1 = 1;
    int input = 0;
    while ((input < a) || (input > b) || (flag1)) {
        input = 0;
        int first_num = 0;
        printf("Please enter a number between %d and %d:", a, b);
        char number[200];
        fflush(stdin);
        fgets(number, 200, stdin);

        for (int i = 0; i < strlen(number) - 1; i++) {
            if ((number[i]) < 48 && (number[i]) != 32 || (number[i]) > 57) {
                flag1 = 1;
                break;
            }

            if (i > 0) {
                if (first_num && (number[i] != 32) && number[i - 1] == 32) {
                    flag1 = 1;
                    break;
                }
            }
            if ((number[i]) != 32) {
                input = input * 10 + (int)number[i] - '0';
                first_num = 1;
            }
            {

                flag1 = 0;

            }

        }

        {


        }
    }
    return input;


}

void printArray(char arr[][20], int size) {
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            printf("%c\n", arr[i][j]);
        }
    }
}


void printMenu() {

    printf("The menu:\n"
           "=========\n"
           "0. Exit\n"
           "1. Insert words\n"
           "2. Print words\n"
           "3. Sort words lexicographic\n"
           "4. Sort words by length\n"
           "5. Sort words by ascii sum\n"
           "6. Sort words by ascii average\n"
           "7. Sort each word by ascii\n"
           "8. Sort all words as one\n");
}


int checkString(char list[]) {
    char temp[200];
    fflush(stdin);
    gets(temp);
    if (strlen(temp) >= 20) {
        return 0;
    }
    //printf("Temp is %s\n", temp);
    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] < 65 || (temp[i] > 90 && temp[i] < 97) || temp[i] > 122) {
            return 0;

        }
        strcpy(list, temp);
    }
    return 1;
}


void insertStrings(char list[][20], int y) {


    for (int i = 0; i < y; ++i) {
        char string[20];
        printf("Please enter word #%d:\n", (i + 1));
        while (!checkString(string)) {
            printf("Wrong input, try again:\n");
        }
        for (int k = 0; k < 20; k++) {
            list[i][k] = string[k];
            //            printf("%c\n", list[i][k]);
        }
    }
}

int asciiSum(char string1[]) {
    int asciisum = 0;
    int len = strlen(string1);
    for (int i = 0; i < len; i++) {
        asciisum = asciisum + string1[i];
    }
    return asciisum;
}

double asciiAvg(char string[]) {
    double asciiavg = 0;
    int len = strlen(string);
    asciiavg = ((double)asciiSum(string)) / (double)strlen(string);
    return asciiavg;
}

void printWords(char print_list[][20], int w) {
    char temp[20];
    int sum = 0;
    printf("The words are:\n==============\n");
    for (int i = 0; i < w; i++) {
        strcpy(temp, print_list[i]);
        for (int j = 0; j < strlen(print_list[i]); j++) {
            sum = sum + print_list[i][j];

        }
        if (i == 9) {
            printf("%d:(ascii sum %4d, ascii avg %6.2lf)%s\n", i + 1, sum, ((double)sum / strlen(print_list[i])), temp);
        }
        if (i < 9)
        {


            printf("0%d:(ascii sum %4d, ascii avg %6.2lf)%s\n", i + 1, sum, ((double)sum / strlen(print_list[i])), temp);
            sum = 0;
        }

    }

}
void sortString(char string[20]) {
    char temp;
    int len = strlen(string);
    for (int step = 0; step < len; step++) {
        for (int i = 0; i < len - step - 1; i++) {
            char a = string[i];
            char b = string[i + 1];
            if ((b - a) < 0) {
                temp = string[i];
                string[i] = string[i + 1];
                string[i + 1] = temp;
            }
        }
    }
}

void sortStringsLexicographic(char unLexico[][20], int n) {
    //    printArray(unLexico,n);
    char temp[20];
    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n - step - 1; i++) {
            if (strcmp(unLexico[i], unLexico[i + 1]) > 0) {
                strcpy(temp, unLexico[i]);
                strcpy(unLexico[i], unLexico[i + 1]);
                strcpy(unLexico[i + 1], temp);

            }
        }
    }
}

void sortStringsByLength(char unLength[][20], int n) {
    char temp[20];
    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n - step - 1; i++) {
            int num = strlen(unLength[i]) > strlen(unLength[i + 1]);
            if (num > 0) {
                strcpy(temp, unLength[i]);
                strcpy(unLength[i], unLength[i + 1]);
                strcpy(unLength[i + 1], temp);
            }
        }
    }
}


void sortStringsByAsciiSum(char unsortedsum[][20], int n) {
    char temp[20];
    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n - step - 1; i++) {
            int num = asciiSum(unsortedsum[i]) - asciiSum(unsortedsum[i + 1]);
            if (num > 0) {
                strcpy(temp, unsortedsum[i]);
                strcpy(unsortedsum[i], unsortedsum[i + 1]);
                strcpy(unsortedsum[i + 1], temp);
            }
        }
    }
}
void sortStringsByAsciiAvg(char unsortedavg[][20], int n) {
    char temp[20];
    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n - step - 1; i++) {
            double num = asciiAvg(unsortedavg[i]) - asciiAvg(unsortedavg[i + 1]);
            if (num > 0) {
                strcpy(temp, unsortedavg[i]);
                strcpy(unsortedavg[i], unsortedavg[i + 1]);
                strcpy(unsortedavg[i + 1], temp);
            }
        }
    }
}

void sortEachString(char unsortAscii[10][20], int n) {
    char temp;
    int subtractAsci;
    int len;
    for (int i = 0; i < n; i++) {
        for (int step = 0; step < len; step++) {
            len = strlen(unsortAscii[i]);
            for (int j = 0; j < len - step - 1; j++) {
                char x = unsortAscii[i][j];
                char y = unsortAscii[i][j + 1];
                subtractAsci = y - x;
                if (subtractAsci < 0) {                            //if word is ba ;(97 - 98 ) < 0  do switch
                    temp = unsortAscii[i][j];
                    unsortAscii[i][j] = unsortAscii[i][j + 1];
                    unsortAscii[i][j + 1] = temp;
                }
            }
        }
    }
}

void sortAllAsOne(char unsortAsciiBig[][20], int n) {
    char happyStr[200] = {""};
    int len;
    for (int i = 0; i < n; i++) {
        strcat(happyStr, unsortAsciiBig[i]);
    }
    sortString(happyStr);   //happyStr get sorted

    int lenHappy = strlen(happyStr);
    for (int k = 0; k < lenHappy; k++) {
        for (int i = 0; i < n; i++) {
            len = strlen(unsortAsciiBig[i]);
            for (int j = 0; j < len; j++) {
                unsortAsciiBig[i][j] = happyStr[k];
                k++;
            }
        }
    }
}


int main() {
    int eror = 1;
    int finish = 1;
    int N = 0;
    int state1_flag = 0;
    printMenu();
    int num = getSize(0, 99);
    while (finish) {
        while (num > 8 && eror <= 5) {

            if (eror == 5) {
                printf("5 errors, bye bye.\n");
                finish = 0;
                break;
            }

            printf("You made %d errors from 5, try again,\n", eror);
            printMenu();
            num = getSize(0, 99);
            eror++;

        }
        while (0 <= num && num <= 8) {
            if (num == 0) {
                printf("You chose to end the program, bye!!!\n");
                finish = 0;
                exit(0);
            }
            if (num == 1) {

                printf("Enter new word count,\n");
                N = getSize(2, 10);
                main_n = N;

                insertStrings(ListString, N);

                N = main_n;
                state1_flag = 1;
                printMenu();
                num = getSize(0, 99);
            }

            if (num == 2) {
                if (state1_flag) {
                    printWords(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }
                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }

            if (num == 3) {
                if (state1_flag) {
                    sortStringsLexicographic(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }

                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }



            if (num == 4) {
                if (state1_flag) {
                    sortStringsByLength(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }
                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }

            if (num == 5) {
                if (state1_flag) {
                    sortStringsByAsciiSum(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }

                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }
            if (num == 6) {
                if (state1_flag) {
                    sortStringsByAsciiAvg(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }
                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }
            if (num == 7) {
                if (state1_flag) {
                    sortEachString(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }
                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }
            if (num == 8) {
                if (state1_flag) {
                    sortAllAsOne(ListString, N);
                    printMenu();
                    num = getSize(0, 99);
                }

                else if (!state1_flag) {
                    printf("There are no words, cannot operate.\n");
                    printMenu();
                    num = getSize(0, 99);
                }
            }
        }
    }
}