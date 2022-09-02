#include <iostream>
using namespace std;

const char MONTHS[13][20] = {
    "",
    "January",
    "Feburary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char DOTW[8][20] = {
    "Su",
    "Mo",
    "Tu",
    "We",
    "Th",
    "Fr",
    "Sa",
    "Su"
};

#define is_gap_year(year) ((year)%4==0 && (year)%100!=0) || (year)%400==0
#define no_of_days(year, month) \
    ((is_gap_year(year))?(NO_OF_DAYS_GAP[month]):(NO_OF_DAYS_NORMAL[month]))
const int NO_OF_DAYS_NORMAL[13] = {0, 
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const int NO_OF_DAYS_GAP[13] = {0, 
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// convention: 1 ~ 7 for the days of the week
/* Every year that is exactly divisible by four is a leap year,
    except for years that are exactly divisible by 100, 
    but these centurial years are leap years if they are 
    exactly divisible by 400. For example, the years 1700, 
    1800, and 1900 are not leap years, but the year 2000 is. */
const int DOTW1800JAN = 3;
#define dotw_mod7(num) num = (((num) - 1) % 7 + 1);
int starting_dotw(int year, int month) {
    int dotw_jan = DOTW1800JAN 
        + (year - 1800) // every year contributes +1 to dtow
        + (year - 1801)/4 // gap year contributes +2
        - (year - 1801)/100 // but every 100 years is not gap year
        + (year - 1601)/400; // but every 400 years is a gap year
    dotw_mod7(dotw_jan)
    int dotw_month = dotw_jan;
    bool gap_year_flag = is_gap_year(year);
    if (!gap_year_flag)
        for (int m = 1; m < month; m++) dotw_month += NO_OF_DAYS_NORMAL[m];
    else
        for (int m = 1; m < month; m++) dotw_month += NO_OF_DAYS_GAP[m];
    dotw_mod7(dotw_month)
    return dotw_month;
}

void print_three_months(int, int, int, int, int, int);

int main() {

    // Testing starting_dotw

    // for (int i=1800; i<3999; i+=17) {
    //     cout << i;
    //     for (int j=1; j<=12; j++) {
    //         cout << " " << starting_dotw(i, j);
    //     }
    //     cout << endl;
    // }
    // return 0;
    
    int input_year;
    int input_month;
    char input_first_day;
    char input_orientation;
    
    do {
        cout << "Enter year (in range 1800-9999): ";
        cin >> input_year;
    } while (!(1800 <= input_year && input_year <= 9999));
    
    do {
        cout << "Enter month (in range 1-12): ";
        cin >> input_month;
    } while (!((1 <= input_month && input_month <= 12) || 
        (input_month == -1) || 
        (input_month == -3)));

    if (1 <= input_month && input_month <= 12) {

        do {
            cout << "Enter the first day of week ('s' for Sunday, 'm' for Monday): ";
            cin >> input_first_day;
        } while (!(input_first_day == 's' || input_first_day == 'm'));

        do {
            cout << "Print horizontally (h) or vertically (v): "; 
            cin >> input_orientation;
        } while (!(input_orientation == 'h' || input_orientation == 'v'));

        int dotw_counter = 0;
        int starting_day = 0;
        if (input_orientation == 'h') {
            
            if (input_first_day == 's') {

                cout << MONTHS[input_month] << " " << input_year << endl;
                cout << "Su Mo Tu We Th Fr Sa" << endl;
                dotw_counter = starting_dotw(input_year, input_month) % 7;
                // so now 0 corresponds to sunday
                for (int i=0; i<dotw_counter; i++) cout << "   "; 
                for (int m=1; m<=no_of_days(input_year, input_month); m++) {
                    dotw_counter++;
                    printf("%2d ", m);
                    if (dotw_counter > 6) {
                        cout << endl;
                        dotw_counter = 0;
                    }
                }

            } else if (input_first_day == 'm') {

                cout << MONTHS[input_month] << " " << input_year << endl;
                cout << "Mo Tu We Th Fr Sa Su" << endl;
                dotw_counter = starting_dotw(input_year, input_month);
                for (int i=1; i<dotw_counter; i++) cout << "   "; 
                for (int m=1; m<=no_of_days(input_year, input_month); m++) {
                    dotw_counter++;
                    printf("%2d ", m);
                    if (dotw_counter > 7) {
                        cout << endl;
                        dotw_counter = 1;
                    }
                }

            } else {cout << "something is wrong";}

        } else if (input_orientation == 'v') {

            if (input_first_day == 's') {

                cout << MONTHS[input_month] << " " << input_year << endl;
                starting_day = starting_dotw(input_year, input_month) % 7;
                // so now 0 corresponds to sunday
                for (int w=0; w<7; w++) {
                    cout << DOTW[w];
                    for (int d=1-starting_day+w; d<=no_of_days(input_year, input_month); d+=7) {
                        if (d < 1) cout << "   ";
                        else printf(" %2d", d);
                    }
                    cout << endl;
                }

            } else if (input_first_day == 'm') {

                cout << MONTHS[input_month] << " " << input_year << endl;
                starting_day = starting_dotw(input_year, input_month);
                for (int w=1; w<=7; w++) {
                    cout << DOTW[w];
                    for (int d=1-starting_day+w; d<=no_of_days(input_year, input_month); d+=7) {
                        if (d < 1) cout << "   ";
                        else printf(" %2d", d);
                    }
                    cout << endl;
                }

            } else {cout << "something is wrong";}
        } else {cout << "something is very wrong";}

    } else if (input_month == -1) {

        cout << "Year " << input_year << endl;
        for (int i=0; i<4; i++) {
            printf("%22s %22s %s\n", MONTHS[1+3*i], MONTHS[2+3*i], MONTHS[3+3*i]);
            print_three_months(input_year, 1+3*i, input_year, 2+3*i, input_year, 3+3*i);
        }

    }


    
}

void print_three_months(int y1, int m1, int y2, int m2, int y3, int m3) {
        
    int calendar_counter = 0;
    int dotw_counters[3] = {
        0, 0, 0
    };
    int day_counters[3] = {
        1-starting_dotw(y1, m1)%7, 1-starting_dotw(y2, m2)%7, 1-starting_dotw(y3, m3)%7
    };
    int num_of_days[3] = {
        no_of_days(y1, m1), no_of_days(y2, m2), no_of_days(y3, m3)
    };
    int finished_counter = 0;
    printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa");
    // so now 0 corresponds to sunday

    while (finished_counter != 8) {

        while (dotw_counters[calendar_counter] < 7) {
            if (day_counters[calendar_counter] < 1 || day_counters[calendar_counter] > num_of_days[calendar_counter])
                cout << "   ";
            else printf("%2d ", day_counters[calendar_counter]);
        }
        cout << " ";
        if (day_counters[calendar_counter] > num_of_days[calendar_counter]) 
            finished_counter |= 1 << calendar_counter;
        calendar_counter++;

        if (calendar_counter > 2) {
            cout << endl;
            calendar_counter = 0;
        }
    }
    if (calendar_counter != 0) cout << endl;

}
