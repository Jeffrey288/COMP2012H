#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

const int MAX_STRLEN = 1000;
const int NUM_CHARS_PER_LINE = 10;
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

#define ISWORD(chr) ((('a' <= (chr)) && ((chr) <= 'z')) || \
            (('A' <= (chr)) && ((chr) <= 'Z')) || \
            ((chr) == '-'))

int countWords(const char str[])
{
    int len = 0;
    int isWord = false;
    for (int i=0; str[i]!='\0'; i++) {
        if (
            ISWORD(str[i])
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
    str[n] = '\0';
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

// mary haad a little lamb little lamb
void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE])
{
    int pos=0, word_length=0;
     for (int j = 0; j < MAX_LINES; j++)
    {
        for (int i = 0; i < NUM_CHARS_PER_LINE; i++)
        {
            //remove heading spaces
            if (i==0 && str[pos]==' ')
            {
                pos+=1;
            }
            //place last char as null
            if (i==NUM_CHARS_PER_LINE-1)
            {
                lines[j][i]='\0';
                // word_length=0;
            //copy str into the line i
            }else{
                lines[j][i]=str[pos];
                pos++;
                
            }   
            // if (str[pos]==' '&&str[pos+1]==' ')
            // {
            //     pos+=1;
            // }
            //count length of word
            if(str[pos]!=' '){word_length++;}else{word_length=0;}
            // cout<<word_length<<" ";
            // if(i==NUM_CHARS_PER_LINE-2)cout<<str[pos-1]<<' '<<str[pos]<<"\n";
            //check last word and the next word is connected or not:move backward and copy the word to next line
            if (i==NUM_CHARS_PER_LINE-2 && str[pos]!=' ' && str[pos-1]!=' ')
            {
                if(word_length<NUM_CHARS_PER_LINE-1){
                    lines[j][i-word_length+1]='\0';
                    pos-=word_length;
                }
                // word_length=0;
                // cout<<"pos_char="<<str[pos]<< "\n";
                // cout<<"wordl="<<word_length<<"\n";
                // break;
            }

            if (str[pos]=='\0')
            {
                continue;
            }
        } 
        if (str[pos]=='\0')
            {
                break;
            }
    }
    for (int i = 0; i < MAX_LINES; i++)
    {
        for (int j = NUM_CHARS_PER_LINE-2; j >= 0; j--)
        {
            if (lines[i][j]==' ')
            {
                lines[i][j]='\0';
                // word_length=0;
            } else break;
        }
    }
}

void printLeftJustified(const char str[])
{
    int num_of_lines=1;
    char lines[MAX_LINES][NUM_CHARS_PER_LINE]={};
    convertIntoLines(str,lines);
    for (int i = 0; i < MAX_LINES; i++)
    {
        if (lines[i][0]=='\0')
        {
            num_of_lines=i;
            break;
        }
    }
    
    for (int i = 0; i < num_of_lines; i++)
    {
        cout<<lines[i];
        cout<<"\n";
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
    int dummy_count = 0;

    // cout << "12345678901234567890123456789012345678901234567890" << endl;
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str, lines);
    int num_lines = 0;
    for (num_lines=0; lines[num_lines][0]!='\0'; num_lines++);
    if (num_lines > MAX_LINES) num_lines = MAX_LINES;
    // cout << num_lines << endl;
    for (int i=0; i<num_lines; i++) {
        if (i < num_lines - 1) {

            int betweens = 0;
            int isWord = false;
            for (int j=0; lines[i][j]!='\0'; j++) {
                if (lines[i][j] != ' ') { // is a word character
                    if (!isWord) {
                        isWord = true;
                        betweens++;
                    }
                } else {
                    isWord = false;
                }
            }
            betweens--;
                
            int length = countCharacters(lines[i]);
            int spaces = countNumOccurences(lines[i], " "); // assume not 0
            int cutoff, num;
            if (betweens > 0) {
                cutoff = ((NUM_CHARS_PER_LINE - 1) - length) % betweens; 
                num = ((NUM_CHARS_PER_LINE - 1) - length) / betweens;
            } else {
                cutoff = 0;
                num = ((NUM_CHARS_PER_LINE - 1) - length);
            }
            // if (cutoff == 0) cutoff = betweens;
            // cout << betweens << " " << length << " " << spaces << " " << (NUM_CHARS_PER_LINE - 1) - length << " " << cutoff << " " << num << endl;
            int between = 0;
            int j = 0;
            while (j < length) {
                if (lines[i][j] == ' ') {
                    between++;
                    dummy_count = (between <= cutoff) ? (num + 1) : (num);
                    if (dummy_count > 0) printf("%*c", dummy_count, ' ');
                    while (lines[i][j] == ' ') { j++; cout << " "; }
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

#define ISVOWEL(chr) ((chr) == 'a' || (chr) == 'e' || (chr) == 'i' || (chr) == 'o' || (chr) == 'u' || \
                (chr) == 'A' || (chr) == 'E' || (chr) == 'I' || (chr) == 'O' || (chr) == 'U')


bool isvowel(char vowel[], int target,int size){
    for (int i = 0; i < size; i++)
    {
        if (vowel[i]==target)
        {
            return true;
        }   
    } return false;
}

// How should Japan avoid the tragedy of being colonialized by western countries as happened to Mexico, India, and Africa
void convertStrToPigLatin(char str[])
{
    char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int index_str=0,index_temp1=0,index_temp2=0,index_temp3=0, larger_int=0;
    char temp1[MAX_STRLEN] = {}; // before vowel
    char temp2[MAX_STRLEN] = {}; // after vowel
    char temp3[MAX_STRLEN] = {}; // final result
    bool no_vowel=true;

    while (str[index_str]!='\0')
    {

        if (!isvowel(vowel, str[index_str], 10)||str[index_str]=='.'||str[index_str]==',') // if vowel . ,
        {
            // cout<<index_str<<" ";
            // cout<<str;
            if (index_str<countCharacters(str))
            {
                temp2[index_temp2]=str[index_str];
                index_temp2++;
                temp2[index_temp2]='\0';
            }
            if (str[index_str]==' ')
            {
                temp1[index_temp1]=' ';
                index_temp1++;
                temp1[index_temp1]='\0';
                // temp2[index_temp2+1]='\0';
                // index_temp2++;
            }
        }else{
            no_vowel=false;
            while (str[index_str]!=' ')//&&str[index_str]!='.'&&str[index_str]!=','
            {
                temp1[index_temp1]=str[index_str];
                // temp2[index_temp2]=' ';
                // index_temp2++;
                index_temp1++;
                index_str++;
            }
            if (str[index_str]==' ')
            {
                temp1[index_temp1]=' ';
                index_temp1++;
                temp2[index_temp2]=' ';
                index_temp2++;
                temp2[index_temp2]='\0';
                // temp2[index_temp2+1]='\0';
                // index_temp2++;
            }
            if (index_str==countCharacters(str)-1)
            {
                temp2[index_temp2]=' ';
                temp2[index_temp2+1]='\0';
                break;
                // temp1[index_temp1]=' ';
                // index_temp1++;
                // temp2[index_temp2+1]='\0';
                // index_temp2++;
            }
        } 
        if(no_vowel&&str[index_str]==' '){
            temp1[index_temp1]=' ';
            index_temp1++;
        }
        if (str[index_str]==' '&&str[index_str-1]!=' '&&str[index_str]!='\0')
        {
            no_vowel=true;
        }
        index_str++;
        
    }

    cout<<temp1<<"\n"<<temp2<<"\n";

    for (int i = 0; i < countCharacters(temp2)+1; i++)
    {
        if (temp2[i]==' '&&temp2[i-1]!=' '&&temp2[i-1]!='\0'&&temp2[i+1]!=' '&&temp2[i+1]!='\0')
        {
            temp2[i]='a';
        }
        if (i==countCharacters(temp2))
        {
            temp2[i]='\0';
        }
        // else if(temp2[i]==' ')temp2[i]='e'; 
    }
    
     cout<<temp1<<"\n"<<temp2<<"\n";

    index_temp1=0,index_temp2=0,index_temp3=0;
    for(int i=0;i<countCharacters(temp2);i++)
    {
        if (temp2[index_temp2]==' '&&index_temp2<countCharacters(temp2))
        {
            
         while (temp1[index_temp1]!=' '&&temp1[index_temp1]!='\0')//&&temp1[index_temp1]!='.'&&temp1[index_temp1]!=','
            {
                if(temp1[index_temp1]!='.'&&temp1[index_temp1]!=','){
                temp3[index_temp3]=temp1[index_temp1];
                index_temp3++;
                }
                index_temp1++;
            }
            temp3[index_temp3]='y';
            index_temp3++;
            temp3[index_temp3]='a';
            index_temp3++;
            temp3[index_temp3]='y';
            index_temp3++;
            temp3[index_temp3]=' ';
            index_temp3++;
            index_temp1++;
            if(temp1[index_temp1]==','){
                 temp3[index_temp3]=',';
                index_temp3++;
            }
            if (temp1[index_temp1]=='.')
            {
                 temp3[index_temp3]='.';
                index_temp3++;
            }
        }
        if (temp2[index_temp2]!=' '&&temp2[index_temp2]!='a'&&index_temp2<countCharacters(temp2)) {
            
            while (temp1[index_temp1]!=' '&&temp1[index_temp1]!='\0')//&&temp1[index_temp1]!='.'&&temp1[index_temp1]!=','
            {
                if(temp1[index_temp1]!='.'&&temp1[index_temp1]!=','){
                temp3[index_temp3]=temp1[index_temp1];
                index_temp3++;
                }
                index_temp1++;   
            }
            while (temp2[index_temp2]!=' '&&temp2[index_temp2]!='a'&&temp2[index_temp2]!='\0')
            {   
                temp3[index_temp3]=temp2[index_temp2];
                index_temp2++;
                index_temp3++;
            }
            temp3[index_temp3]='a';
            index_temp3++;
            temp3[index_temp3]='y';
            index_temp3++;
            temp3[index_temp3]=' ';
            index_temp3++;
            index_temp1++;
            if(temp1[index_temp1]==','){
                 temp3[index_temp3]=',';
                index_temp3++;
            }
            if (temp1[index_temp1]=='.')
            {
                 temp3[index_temp3]='.';
                index_temp3++;
            }
        }
       
        index_temp2++;
    }
    // if (str[countCharacters(str)-1]=='.')
    //         {
    //             // cout<<true;
    //             temp3[countCharacters(temp3)-1]='.';
    //             index_temp3++;  
    //         }
    

     for (int i = 0; i < countCharacters(temp3)+1; i++)
     {
        str[i]=temp3[i];
        if (i==countCharacters(temp3))
        {
            str[i]='\0';
        }
     }

    
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

