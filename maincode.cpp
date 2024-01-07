#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Global variable to store SGPA across semesters
float sgpa = 0;

// Class definition for the calculator
class calculator {
public:
    string subname;
    int numsub = 0, credits = 0, tcredits = 0, ccount = 0;
    float tcount = 0, gpoints = 0, tgpoints = 0, totalgpoints = 0;

    // Function to get grade for the calculated SGPA
    void getgrade();

    // Function to get details and calculate SGPA for a semester
    float getdata();

};

// Function to get grade based on SGPA
void calculator::getgrade() {
    if (sgpa <= 10.00 && sgpa >= 9.00)
        cout << "Grade: A+" << endl;
    else if (sgpa <= 8.99 && sgpa >= 8.00)
        cout << "Grade: A" << endl;
    else if (sgpa <= 7.99 && sgpa >= 7.00)
        cout << "Grade: B+" << endl;
    else if (sgpa <= 6.99 && sgpa >= 6.00)
        cout << "Grade: B" << endl;
    else if (sgpa <= 5.99 && sgpa >= 5.00)
        cout << "Grade: C" << endl;
    else
        cout << "Grade: F (fail)" << endl;
}

// Function to get details and calculate SGPA for a semester
float calculator::getdata() {
    cout << "Enter number of Subjects: ";
    cin >> numsub;
    for (int i = 0; i < numsub; i++) {
        cout << "\nSubject " << i + 1 << " Name: ";
        cin >> subname;
        cout << "Enter Credits: ";
        cin >> credits;
    ABCD:
        cout << "Enter Grade points scored: ";
        cin >> gpoints;
        if (gpoints > 10.00 || gpoints < 0.00) {
            cout << "Invalid!! It should be between (0-10) only!" << endl;
            goto ABCD;
        }
        tgpoints = credits * gpoints;
        tcredits += credits;
        totalgpoints += tgpoints;
    }
    sgpa = totalgpoints / tcredits;
    cout << "\nTotal Credits: " << tcredits << endl;
    cout << "\nSGPA:  " << setprecision(3) << sgpa << endl;
    return sgpa;
}

int main() {
    int rollno, enrno;
    string name, course, nam;
    int r1, r2, numsem = 0;
    float rsgpa, sumsgpa = 0, rcgpa = 0;
    float res1 = 0, res2 = 0, res3 = 0, res4 = 0, res5 = 0, res6 = 0, res7 = 0, res8 = 0;
    float cgp2 = 0, cgp3 = 0, cgp4 = 0, cgp5 = 0, cgp6 = 0, cgp7 = 0, tcgpa = 0;
    calculator sem1, sem2, sem3, sem4, sem5, sem6, sem7, sem8, tsem, rcgp;

    // User inputs for personal information
    cout << "Enter your Name: ";
    getline(cin, nam);
    cout << "Enter Enrollment number: ";
    cin >> enrno;

repeat:
    again:
    cout << "Enter number of Semesters: ";
    cin >> numsem;
    cout << "\nTo enter SGPA of Semesters directly, Press 1:" << endl;
    cout << "To enter details of each semester, Press any number:" << endl;
    cin >> r1;

    switch (r1) {
    case 1:
        // Directly entering SGPA for each semester
        for (int i = 0; i < numsem; i++) {
            cout << "Enter SGPA of Sem " << i + 1 << ": ";
            cin >> rsgpa;
            sumsgpa += rsgpa;
        }
        rcgpa = sumsgpa / numsem;
        cout << "\nCGPA: " << rcgpa;
        sgpa = rcgpa;
        cout << endl;
        rcgp.getgrade();
        break;

    default:
        // Entering details for each semester
        if (numsem > 0 && numsem < 8) {
            cout << "\nSemester 1:" << endl;
            int r1;
            res1 = sem1.getdata();
            sem1.getgrade();
            cout << "CGPA:  NA" << endl;
            if (numsem == 1)
                goto AB;

            cout << "\n\nSemester 2: " << endl;
            res2 = sem2.getdata();
            sem2.getgrade();
            cgp2 = (res1 + res2) / 2;
            cout << "CGPA:  " << setprecision(3) << cgp2;
            if (numsem == 2)
                goto AB;

            cout << "\n\nSemester 3: " << endl;
            res3 = sem3.getdata();
            sem3.getgrade();
            cgp3 = (res1 + res2 + res3) / 3;
            cout << "CGPA:  " << setprecision(3) << cgp3;
            if (numsem == 3)
                goto AB;

            cout << "\n\nSemester 4: " << endl;
            res4 = sem4.getdata();
            sem4.getgrade();
            cgp4 = (res1 + res2 + res3 + res4) / 4;
            cout << "CGPA:  " << setprecision(3) << cgp4;
            if (numsem == 4)
                goto AB;

            cout << "\n\nSemester 5: " << endl;
            res5 = sem5.getdata();
            sem5.getgrade();
            cgp5 = (res1 + res2 + res3 + res4 + res5) / 5;
            cout << "CGPA:  " << setprecision(3) << cgp5;
            if (numsem == 5)
                goto AB;

            cout << "\n\nSemester 6: " << endl;
            res6 = sem6.getdata();
            sem6.getgrade();
            cgp6 = (res1 + res2 + res3 + res4 + res5 + res6) / 6;
            cout << "CGPA:  " << setprecision(3) << cgp6;
            if (numsem == 6)
                goto AB;

            cout << "\n\nSemester 7: " << endl;
            res7 = sem7.getdata();
            sem7.getgrade();
            cgp7 = (res1 + res2 + res3 + res4 + res5 + res6 + res7) / 7;
            cout << "CGPA:  " << setprecision(3) << cgp7;
            if (numsem == 7)
                goto AB;

            cout << "\n\nSemester 8: " << endl;
            res8 = sem8.getdata();
            sem7.getgrade();
            tcgpa = (res1 + res2 + res3 + res4 + res5 + res6 + res7 + res8) / numsem;
            cout << "CGPA:  " << setprecision(3) << tcgpa;
        }
    AB:
        cout << "\n----------------------------------" << endl;
        cout << endl;
        cout << "FINAL REPORT CARD\n";
        cout << endl;

        cout << "Name: " << nam << endl;
        cout << "Enrollment Number: " << enrno << endl;
        cout << endl;
        cout << "        Sem1\tSem2\tSem3\tSem4\tSem5\tSem6\tSem7\tSem8" << endl;
        cout << endl;
        cout << "SGPA:  " << res1 << "\t" << res2 << "\t" << res3 << "\t" << res4 << "\t" << res5 << "\t" << res6 << "\t" << res7 << "\t" << res8 << endl;
        cout << endl;
        cout << "CGPA:  " << "NA" << "  \t" << cgp2 << "\t" << cgp3 << "\t" << cgp4 << "\t" << cgp5 << "\t" << cgp6 << "\t" << cgp7 << "\t" << tcgpa << endl;
    }
    cout << "\nTo repeat again, press 1: " << endl;
    cout << "To close program, press other number" << endl;
    cin >> r2;
    switch (r2) {
    case 1:
        goto repeat;
        break;
    default:
        return 0;
    }
}
