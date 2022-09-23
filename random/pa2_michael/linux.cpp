#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_STRLEN = 1000;
const int NUM_CHARS_PER_LINE = 50;
const int MAX_LINES = 15;

int countCharacters(const char str[]);
int countWords(const char str[]);
int countNumOccurences(const char str[], const char target[]);

void swapString(char str[], const char target[], const char to[]);
void encryptText(char str[], int shift);

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE]);
void printRightJustified(const char str[]);
void printLeftJustified(const char str[]);

void convertStrToPigLatin(char word[]);
void printPigLatin(const char str[]);

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes start here. Please do not modify codes above
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++

int countCharacters(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int countWords(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != ' ' && str[i] != ',' && str[i] != '.')
            && (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '.' || str[i + 1] == '\0')) {
            count++;
        }
    }
    return count;
}

void swapString(char str[], const char target[], const char to[]) {
    int counter = 0;
    int len = countCharacters(str);
    int to_len = countCharacters(to);
    // cout << len << endl << endl;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target[counter]) {
            counter++;
        } else {
            counter = 0;
        }

        if (target[counter] == '\0') {
            int beginning = i - counter + 1;
            // cout << beginning << endl;
            // cout << counter + beginning << endl;
            for (int j = beginning; str[j] != '\0'; j++) {
                // cout << j << "    " << str[j + counter] << endl;
                str[j] = str[j + counter];
                // cout << str << endl;
                if (str[j] == '\0') {
                    break;
                }
            }
            len -= counter;
            i -= counter;
            // cout << len << "       " << i << endl;
            // cout << str << endl;
            for (int j = len; j >= beginning; j--) {
                // cout << j << "    " << str[j] << endl;
                str[j + to_len] = str[j];
                // cout << str << endl;
            }

            len += to_len;
            i += to_len;
            // cout << len << "       " << i << endl;

            for (int j = beginning; j < beginning + to_len; j++) {
                str[j] = to[j - beginning];
            }
            // cout << str << endl;

            // cout << (str[len] == '\0');
            counter = 0;
        }
    }
}

void encryptText(char str[], int shift) {
    int factor = (abs(shift) / 26 + 1) * 26;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] + factor + shift - 'a') % 26 + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] + factor + shift - 'A') % 26 + 'A';
        }
    }
}

int countNumOccurences(const char str[], const char target[]) {
    int occurences = 0;
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target[counter]) {
            counter++;
        } else {
            counter = 0;
        }
        if (target[counter] == '\0') {
            occurences++;
            counter = 0;
        }
    }
    return occurences;
}

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE]) {
    int beginning_str = -1;
    int beginning_lines = -1;

    int curr_line = 0;
    int next_free_space = 0;
    bool start = false;

    for (int i = 0; str[i] != '\0'; i++) {
        // negate whitespace in front of line
        if (str[i] != ' ') {
            start = true;
        }

        // mark down beginning of word
        if (beginning_str == -1 && (str[i] != ' ' && str[i] != ',' && str[i] != '.')) {
            beginning_str = i;
            beginning_lines = next_free_space;
            // cout << str[i] << "     " << beginning_str << "       " << beginning_lines << endl;
        } else if ((str[i] == ' ' || str[i] == ',' || str[i] == '.')) {
            beginning_str = -1;
            beginning_lines = -1;
        }

        if (start) {
            lines[curr_line][next_free_space] = str[i];
            next_free_space++;

            // if at the end of the line
            if (next_free_space == NUM_CHARS_PER_LINE - 1) {
                // if word is not complete then forcibly end the string at the beginning of the word
                // cout << "L\n";
                // cout << lines[curr_line] << endl;
                // cout << str[i] << "   " << str[i + 1] << endl;
                if ((str[i] != ' ' && str[i] != ',' && str[i] != '.')
                    && (str[i + 1] != ' ' && str[i + 1] != ',' && str[i + 1] != '.' && str[i + 1] != '\0')) {
                    // cout << "lol\n";
                    for (int j = beginning_lines; j <= next_free_space; j++) {
                        lines[curr_line][j] = '\0';
                    }
                    i = beginning_str - 1;
                }
                // terminate the string at the end
                else {
                    // cout << "lel\n";
                    lines[curr_line][next_free_space] = '\0';
                    // cout << lines[curr_line] << endl << endl;
                }
                // reset word start markers
                beginning_str = -1;
                beginning_lines = -1;


                // remove trailing whitespace
                for (int j = NUM_CHARS_PER_LINE - 1; j >= 0; j--) {
                    // cout << lines[curr_line][j - 1] << lines[curr_line][j] << lines[curr_line][j + 1] << endl;
                    if ((lines[curr_line][j] == ' ' || lines[curr_line][j] == '\0') && lines[curr_line][j - 1] != '\0'
                        && lines[curr_line][j - 1] != ' ') {
                        // cout << lines[curr_line][j] << "     " << j << "        " << lines[curr_line][j - 1]
                        // << "         kek\n";

                        lines[curr_line][j] = '\0';
                        break;
                    }
                }
                // cout << lines[curr_line] << endl << endl;
                // cout << "count  " << countCharacters(lines[curr_line]) << endl;
                // cout << lines[curr_line] << endl << endl;

                // go to next line
                start = false;
                next_free_space = 0;
                curr_line++;
            }
        }
    }
    // end the final line and terminate all other unused lines
    lines[curr_line][next_free_space] = '\0';
    for (int j = next_free_space; j >= 0; j--) {
        // cout << lines[curr_line][j - 1] << lines[curr_line][j] << lines[curr_line][j + 1] << endl;
        if ((lines[curr_line][j] == ' ' || lines[curr_line][j] == '\0') && lines[curr_line][j - 1] != '\0'
            && lines[curr_line][j - 1] != ' ') {
            // cout << lines[curr_line][j] << "     " << j << "        " << lines[curr_line][j - 1] << "         kek\n";

            lines[curr_line][j] = '\0';
            break;
        }
    }

    for (int j = NUM_CHARS_PER_LINE - 1; j >= 0; j--) {
        // cout << lines[curr_line][j - 1] << lines[curr_line][j] << lines[curr_line][j + 1] << endl;
        if ((lines[curr_line][j] == ' ' || lines[curr_line][j] == '\0') && lines[curr_line][j - 1] != '\0'
            && lines[curr_line][j - 1] != ' ') {
            // cout << lines[curr_line][j] << "     " << j << "        " << lines[curr_line][j - 1] << "         kek\n";

            lines[curr_line][j] = '\0';
            break;
        }
    }
    for (int i = curr_line + 1; i < MAX_LINES; i++) {
        lines[i][0] = '\0';
    }

    // for (int i = 0; i < MAX_LINES; i++) {
    //     cout << lines[i] << endl;
    // }
}

void printLeftJustified(const char str[]) {
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str, lines);
    for (int i = 0; i < MAX_LINES; i++) {
        if (lines[i][0] == '\0') {
            break;
        } else {
            cout << lines[i] << endl;
        }
    }
}

void printRightJustified(const char str[]) {
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str, lines);
    for (int i = 0; i < MAX_LINES; i++) {
        if (lines[i][0] == '\0') {
            break;
        } else {
            int len = countCharacters(lines[i]);
            for (int j = 0; j <= len; j++) {
                lines[i][NUM_CHARS_PER_LINE - 1 - j] = lines[i][len - j];
            }
            for (int j = 0; j < NUM_CHARS_PER_LINE - 1 - len; j++) {
                lines[i][j] = ' ';
            }
            cout << lines[i] << endl;
        }
    }
}

void printJustified(const char str[]) {
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    int temp = -1;
    convertIntoLines(str, lines);
    for (int i = 0; i < MAX_LINES - 1; i++) {
        // don't modify the last line
        if (lines[i + 1][0] == '\0') {
            temp = i;
            break;
        } else {
            int counter = 0;
            int len = countCharacters(lines[i]);
            int amt_of_spaces = NUM_CHARS_PER_LINE - 1 - len;
            // cout << "spaces needed:  " << amt_of_spaces << endl;

            // loop until x amount of spaces are added
            while (amt_of_spaces > 0) {
                // find the end of a block of whitespace and add one
                if (lines[i][counter] == ' ' && lines[i][counter + 1] != ' ') {
                    // cout << counter << endl;
                    for (int j = len; j >= counter; j--) {
                        lines[i][j + 1] = lines[i][j];
                    }
                    // cout << lines[i] << endl;
                    amt_of_spaces--;
                    counter += 2;
                    len++;
                } else {
                    counter++;
                }

                // wrap around
                if (counter >= len) {
                    counter = 0;
                }
            }
            cout << lines[i] << endl;
        }
    }
    cout << lines[temp] << endl;
}

void convertStrToPigLatin(char str[]) {
    int beginning = -1;
    int ending = -1;
    int len = countCharacters(str);

    for (int i = 0; str[i] != '\0'; i++) {
        // find beginning of word
        if (beginning == -1 && (str[i] != ' ' && str[i] != ',' && str[i] != '.')) {
            beginning = i;
        }

        // find end of word
        if ((str[i] != ' ' && str[i] != ',' && str[i] != '.')
            && (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '.' || str[i + 1] == '\0')) {
            // cout << beginning << "        " << i << endl;
            ending = i;

            // if word starts with a vowel just append "yay"
            if (str[beginning] == 'a' || str[beginning] == 'e' || str[beginning] == 'i' || str[beginning] == 'o'
                || str[beginning] == 'u' || str[beginning] == 'A' || str[beginning] == 'E' || str[beginning] == 'I'
                || str[beginning] == 'O' || str[beginning] == 'U') {
                // cout << "vowel\n";
                // move everything behind the word 3 spaces back to make space for "yay"
                for (int j = len; j >= ending; j--) {
                    // cout << j << "    " << str[j] << endl;
                    str[j + 3] = str[j];
                    // cout << str << endl;
                }
                str[ending + 1] = 'y';
                str[ending + 2] = 'a';
                str[ending + 3] = 'y';
                i += 3;
                len += 3;
            }
            // move all the letters to the back of the word until a vowel is in front and append "ay
            else {
                // cout << "const" << endl;
                for (int j = len; j >= ending; j--) {
                    // cout << j << "    " << str[j] << endl;
                    str[j + 2] = str[j];
                    // cout << str << endl;
                }

                // append "ay"
                str[ending + 1] = 'a';
                str[ending + 2] = 'y';
                i += 2;
                len += 2;

                // find the vowel in the word
                int vowel_pos = -1;
                for (int j = beginning; j <= ending; j++) {
                    if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u'
                        || str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
                        vowel_pos = j;
                        break;
                    }
                }
                // cout << "vowel: " << vowel_pos << endl;

                // if vowel exists, keep moving the first char to the back until the vowel is in front
                if (vowel_pos != -1) {
                    for (int j = 0; j < vowel_pos - beginning; j++) {
                        char temp = str[beginning];
                        for (int k = beginning; k < ending; k++) {
                            str[k] = str[k + 1];
                        }
                        str[ending] = temp;
                    }
                }
            }

            beginning = -1;
            ending = -1;
        }
    }
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes end here. Please do not modify codes below
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

void printPigLatin(const char str[]) {
    char pigLatin[MAX_STRLEN];
    for (int i = 0; i < MAX_STRLEN; ++i) {
        pigLatin[i] = str[i];
    }
    convertStrToPigLatin(pigLatin);
    int strLen = countCharacters(pigLatin);
    for (int i = 0; i < strLen; ++i) {
        if (pigLatin[i] >= 'A' && pigLatin[i] <= 'Z') {
            pigLatin[i] = 'a' + pigLatin[i] - 'A';
        }
    }
    cout << pigLatin << endl;
}

void printMainDisplay(const char str[]) {
    cout << str << endl
         << "===================================\n"
         << "1. Character Count\n"
         << "2. Word Count\n"
         << "3. Encrypt (Caeser Cipher)\n"
         << "4. Find and Replace String Globally\n"
         << "5. Find Frequency of String\n"
         << "6. Print Left Align Text\n"
         << "7. Print Right Align Text\n"
         << "8. Print Left-Right Align Text\n"
         << "9. Print Pig Latin\n"
         << "Please make your choice: ";
}

int main() {
    int choice = 0;
    char str[MAX_STRLEN];

    cout << "Enter text: ";
    cin.getline(str, MAX_STRLEN, '\n');

    do {
        printMainDisplay(str);
        cin >> choice;
    } while (choice < 1 || choice > 9);

    if (choice == 1) {
        cout << "Total character count: " << countCharacters(str) << endl;
    } else if (choice == 2) {
        cout << "Total word count: " << countWords(str) << endl;
    } else if (choice == 3) {
        cout << "Enter the shift amount for the caeser cipher encryption (rotation encryption): ";
        int shift;
        cin >> shift;
        encryptText(str, shift);
        cout << str << endl;
    } else if (choice == 4) {
        cout << "Enter the string to find and replace: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << "Enter the string to replace it with: ";
        char to[MAX_STRLEN];
        cin.getline(to, MAX_STRLEN, '\n');

        swapString(str, target, to);
        cout << str << endl;
    } else if (choice == 5) {
        cout << "Enter the string to count the occurences of: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << '"' << target << '"' << " appears in the text " << countNumOccurences(str, target) << " time(s).\n";
    } else if (choice == 6) {
        printLeftJustified(str);
    } else if (choice == 7) {
        printRightJustified(str);
    } else if (choice == 8) {
        printJustified(str);
    } else if (choice == 9) {
        printPigLatin(str);
    }
}
