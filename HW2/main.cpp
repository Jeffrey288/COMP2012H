#include <iostream>
#include <climits>
#include <cstdio>

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

int countCharacters(const char str[])
{
    int len;
    for (len=0; str[len]!='\0'; len++);
    return len; // Replace this line with your implementation
}

int countWords(const char str[])
{
    int len = 0;
    int isWord = false;
    for (int i=0; str[i]!='\0'; i++) {
        if (
            (('a' <= str[i]) && (str[i] <= 'z')) ||
            (('A' <= str[i]) && (str[i] <= 'Z')) ||
            (str[i] == '-')
        ) // is a word character
        {
            if (!isWord) {
                isWord = true;
                len++;
            }
        } else {
            isWord = false;
        }
    }

    return len; // Replace this line with your implementation
}

void swapString(char str[], const char target[], const char to[])
{
    int tar_len = countCharacters(target);
    int to_len = countCharacters(to);
    int str_len = countCharacters(str);
    int new_str[MAX_STRLEN];
    int n = 0; // new string counter
    int i = 0; // old string counter
    while (i < str_len) {
        bool replace_flag = false;
        for (int j=0; (j<tar_len && i+j<str_len); j++) {
            if (str[i+j] != target[j]) break;
            if (j == tar_len - 1) replace_flag = true;
        }
        if (replace_flag) {
            for (int j=0; j<to_len; j++) {
                new_str[n] = to[j];
                n++;
            }
            i += tar_len;
        } else {
            new_str[n] = str[i];
            n++;
            i++;
        }
    }
    for (int k=0; k<n; k++) str[k] = new_str[k];
    // cout << "Not Implemented" << endl; // Replace this line with your implementation
}

#define IS_UPPERCASE(chr) ('A' <= (chr) && (chr) <= 'Z')
#define IS_LOWERCASE(chr) ('a' <= (chr) && (chr) <= 'z')
void encryptText(char str[], int shift)
{
    int _shift = (shift > 0) ? (shift % 26) : ((26 - (-shift) % 26) % 26);
    for (int i=0; str[i]!='\0'; i++) {
        if (IS_UPPERCASE(str[i]))
            str[i] = (str[i] - 'A' + _shift) % 26 + 'A';
        else if (IS_LOWERCASE(str[i]))
            str[i] = (str[i] - 'a' + _shift) % 26 + 'a';
    }
}

int countNumOccurences(const char str[], const char target[])
{
    int tar_len = countCharacters(target);
    int str_len = countCharacters(str);
    int i = 0;
    int count = 0;
    while (i < str_len) {
        bool match_flag = false;
        for (int j=0; (j<tar_len && i+j<str_len); j++) { // matching flag
            if (str[i+j] != target[j]) break;
            if (j == tar_len - 1) match_flag = true;
        }
        if (match_flag) {
            count++;
            i += tar_len;
        } else {
            i++;
        }
    }
    return count; // Replace this line with your implementation
}

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE])
{
    bool isWord = 0;
    int word_len = 0;
    int str_len = countCharacters(str);
    int line_len = 0;
    int line_no = 0;
    int space_no = 0; // definition: no of space characters to be printed
        // before the previous word
    for (int i=0; i<=str_len; i++) {
        if (str[i] == ' ' || str[i] == '\0') { // the previous word has finished
            // cout << (int) str[i] << " ";
            // cout << line_len << " " << space_no << endl;
            if (isWord) {
                if (line_len + word_len + space_no > NUM_CHARS_PER_LINE - 1) {
                    lines[line_no][line_len] = '\0';
                    line_no++;
                    line_len = 0;
                    space_no = 0;
                }
                for (int j=0; j<space_no; j++) {
                    lines[line_no][line_len++] = ' ';
                }
                space_no = 0;
                for (int j=0; j<word_len; j++) {
                    lines[line_no][line_len++] = str[i-word_len+j];
                }
                isWord = false;
            }
            space_no++; // no need if (line_len > 0) here
        } else {
            if (!isWord) {
                isWord = true;
                word_len = 1;
            } else {
                word_len++;
            }
        }
    }
    lines[line_no][line_len] = '\0';
    for (int i=line_no+1; i<MAX_LINES; i++) {
        lines[i][0] = '\0';
    }
}

void printLeftJustified(const char str[])
{
    // cout << "12345678901234567890123456789012345678901234567890" << endl;
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str, lines);
    for (int i=0; lines[i][0]!='\0'; i++) {
        cout << lines[i] << endl;
    }
}

void printRightJustified(const char str[])
{
    // cout << "12345678901234567890123456789012345678901234567890" << endl;
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str, lines);
    int spaces;
    for (int i=0; lines[i][0]!='\0'; i++) {
        spaces = (NUM_CHARS_PER_LINE - 1) - countCharacters(lines[i]);
        if (spaces > 0)
            printf("%*c%s\n", spaces, ' ', lines[i]);
        else
            cout << lines[i] << endl;
    }
}

void printJustified(const char str[])
{
    // cout << "12345678901234567890123456789012345678901234567890" << endl;
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str, lines);
    int num_lines = 0;
    for (num_lines=0; lines[num_lines][0]!='\0'; num_lines++);
    // cout << num_lines << endl;
    for (int i=0; i<num_lines; i++) {
        if (i < num_lines - 1) {
            int betweens = countWords(lines[i]) - 1; // assume not 0
            int length = countCharacters(lines[i]);
            int spaces = countNumOccurences(lines[i], " "); // assume not 0
            int cutoff = (spaces + (NUM_CHARS_PER_LINE - 1) - length) % betweens; 
            int num = (spaces + (NUM_CHARS_PER_LINE - 1) - length) / betweens;
            // if (cutoff == 0) cutoff = betweens;
            // cout << betweens << " " << length << " " << spaces << " " << spaces + (NUM_CHARS_PER_LINE - 1) - length << " " << cutoff << " " << num << endl;
            int between = 0;
            int j = 0;
            while (j < length) {
                if (lines[i][j] == ' ') {
                    between++;
                    printf("%*c", (between <= cutoff) ? (num + 1) : (num), ' ');
                    while (lines[i][j] == ' ') j++;
                } else {
                    cout << lines[i][j];
                    j++;
                }
            }
            cout << endl;
            // printf("%*c%s\n", (NUM_CHARS_PER_LINE - 1) - countCharacters(lines[i]), ' ', lines[i]);
        } else {
            cout << lines[i] << endl;
        }
    }
}

void convertStrToPigLatin(char str[])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes end here. Please do not modify codes below
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

void printPigLatin(const char str[])
{
    char pigLatin[MAX_STRLEN];
    for (int i = 0; i < MAX_STRLEN; ++i)
    {
        pigLatin[i] = str[i];
    }
    convertStrToPigLatin(pigLatin);
    int strLen = countCharacters(pigLatin);
    for (int i = 0; i < strLen; ++i)
    {
        if (pigLatin[i] >= 'A' && pigLatin[i] <= 'Z')
        {
            pigLatin[i] = 'a' + pigLatin[i] - 'A';
        }
    }
    cout << pigLatin << endl;
}

void printMainDisplay(const char str[])
{
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

int main()
{
    int choice = 0;
    char str[MAX_STRLEN];

    cout << "Enter text: ";
    cin.getline(str, MAX_STRLEN, '\n');

    do
    {
        printMainDisplay(str);
        cin >> choice;
    } while (choice < 1 || choice > 9);

    if (choice == 1)
    {
        cout << "Total character count: " << countCharacters(str) << endl;
    }
    else if (choice == 2)
    {
        cout << "Total word count: " << countWords(str) << endl;
    }
    else if (choice == 3)
    {
        cout << "Enter the shift amount for the caeser cipher encryption (rotation encryption): ";
        int shift;
        cin >> shift;
        encryptText(str, shift);
        cout << str << endl;
    }
    else if (choice == 4)
    {
        cout << "Enter the string to find and replace: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << "Enter the string to replace it with: ";
        char to[MAX_STRLEN];
        cin.getline(to, MAX_STRLEN, '\n');

        swapString(str, target, to);
        cout << str << endl;
    }
    else if (choice == 5)
    {
        cout << "Enter the string to count the occurences of: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << '"' << target << '"' << " appears in the text " << countNumOccurences(str, target) << " time(s).\n";
    }
    else if (choice == 6)
    {
        printLeftJustified(str);
    }
    else if (choice == 7)
    {
        printRightJustified(str);
    }
    else if (choice == 8)
    {
        printJustified(str);
    }
    else if (choice == 9)
    {
        printPigLatin(str);
    }
}
