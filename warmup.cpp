// =====================================================================
//  C++ WARM-UP  ·  African Olympiad Academy
//
//  The question descriptions are in README.md. Read them there.
//  This file holds the data, one worked example, and your answers.
//
//  BUILD AND RUN:   g++ -std=c++17 -Wall -o run warmup.cpp && ./run
//            or:    ./run.sh
//
//  Work on ONE question at a time. Write it, run it, check the output
//  against the README, commit it, move on.
// =====================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


/**
 * THE RECORD
 * One delivery: who brought it, how much, and what grade it was given.
 */
struct Delivery {
    string farmer;
    double kg;
    char   grade;
};


/**
 * THE DATA
 * Do not change these. Every expected answer in the README comes from exactly this data.
 */

// Q1 — one morning's weights, in the order they were weighed
vector<double> morningWeights = {
    45.5, 80.0, 12.0, -3.0, 66.5, 20.0, 31.0, 95.0, 50.0, 18.5, 0.0, 72.0
};

// Q2, Q3, Q4, Q7, Q8 — the day's logbook
vector<Delivery> logbook = {
    {"Keza",    45.5, 'A'},
    {"Bonu",    80.0, 'B'},
    {"Isanda",  20.0, 'A'},
    {"Keza",    12.0, 'C'},
    {"Onyinye", 66.5, 'B'},
    {"Karimi",  31.0, 'A'},
    {"Karimi",  31.0, 'A'},
    {"Keza",    18.5, 'B'},
    {"Bonu",    50.0, 'C'},
    {"Isanda",  20.0, 'A'},
    {"Onyinye", 72.0, 'A'}
};   // yes, one of these rows is in here twice. Q8 is about that.

// Q5 — records as the volunteers typed them, before any checking. Several of these are wrong. That is the point.
struct RawRecord {
    string id;
    string kg;        // text, because a volunteer can type anything
    char   grade;
};

vector<RawRecord> rawRecords = {
    {"F012", "45.5",  'A'},
    {"F7",   "20",    'A'},
    {"F033", "heavy", 'B'},
    {"F021", "0",     'C'},
    {"F044", "80",    'b'},
    {"F055", "",      'A'},
    {"F066", "31.5",  'D'},
    {"F077", "92",    'B'}
};

// Q6 — an Igisoro board. 16 pits, in sowing order.
//      Position 0 is unused so that board[1] really is pit 1.
vector<int> board = {0, 0, 0, 1, 0, 0, 4, 1, 0, 0, 2, 2, 0, 1, 5, 0, 0};


// ---------------------------------------------------------------------
//  A HELPER YOU MAY FIND USEFUL
// ---------------------------------------------------------------------
void printBoard(const vector<int> &b) {
    for (int i = 1; i <= 16; i++) cout << b[i] << " ";
    cout << "\n";
}
int findFarmer(const vector<Delivery> &log, string name) {
    for (int i = 0; i < log.size(); i++) {
        if (log[i].farmer == name) {
            return i;  
    }
 }
 return -1;  
}

int main() {

    // =================================================================
    //  WORKED EXAMPLE  ·  not a question
    //
    //  This is the house style: walk the data once, keep what you need
    //  as you go, print at the end. Read it before you start Q1.
    //
    //  It answers: how many deliveries were grade A, and what was the
    //  heaviest single delivery in the whole logbook?
    // =================================================================
    unordered_map<string, double> farmertot;
    unordered_map<string, double> farmerdev;
    vector<string> farmer;
   


    int gradeACount = 0;
    Delivery heaviest = logbook[0];        // start from a REAL entry,
                                           // never from a made-up 0
    for (Delivery d : logbook) {
        if (d.grade == 'A') {
            gradeACount++;
        }
        if (d.kg > heaviest.kg) {
            heaviest = d;                  // keep the WHOLE record,
        }                                  // not just the number
    }

    cout << "=== Worked example ===\n";
    cout << "Grade A deliveries: " << gradeACount << "\n";
    cout << "Heaviest: " << heaviest.farmer << " with "
         << heaviest.kg << " kg\n\n";


    // =================================================================
    //  Q1  ·  THE WEIGHING SESSION          (see README)
    //  Uses: morningWeights
    // =================================================================

    cout << "=== Q1 ===\n";
    double w;
    double b=0;
    double tot=0;
    int bg=1;
    int vran=0;
    int vgng=0;
    int v=0;
    for (int i=1;i<13;i++){
        cin>> w;
        tot+=w;
        if (w>b){
            b=w;
            bg=i;
        }
        if (w<1 || w>79){
            if (vran>vgng){
                vgng=vran;
            }
            vran=0;

        }
        else{
            v++;
            vran++;

        }
    }    
cout << "total " << tot << " kg" << std::endl;
cout << "Valid: " << v << " of 12" << std::endl;
cout << "Heaviest: " << b << " at position " << bg
        << endl << "Longest valid run: " << vgng << std::endl;




    cout << "\n";


    // =================================================================
    //  Q2  ·  GRADE SUMMARY                 (see README)
    //  Uses: logbook
    // =================================================================

    cout << "=== Q2 ===\n";
long long totA=0;
long long totB=0;
long long totC=0;
double akg=0;
double bkg=0;
double ckg=0;
for(int s=0;s<logbook.size();s++){
    if (logbook[s].grade=='A' or logbook[s].grade=='a' ){
akg+=logbook[s].kg;
totA++;
    }
    if (logbook[s].grade=='B' or logbook[s].grade=='b' ){
     bkg+=logbook[s].kg;
totB++;   
    }
    if (logbook[s].grade=='c' or logbook[s].grade=='C' ){
      ckg+=logbook[s].kg;
totC++;  
    }
}
cout<<" Grade A: "<< totA << " deliveries, "<< akg << " kg total, "<< (akg)/totA << " kg average";
cout<<" Grade B: "<< totB << " deliveries, "<< bkg << " kg total, "<< (bkg)/totB << " kg average";
cout<<" Grade C: "<< totC << " deliveries, "<< ckg << " kg total, "<< (ckg)/totC << " kg average";



    cout << "\n";


    // =================================================================
    //  Q3  ·  WHO IS WHO                    (see README)
    //  Uses: logbook, and the findFarmer function you write below main
    // =================================================================

    cout << "=== Q3 ===\n";
    for(int p=0;p<logbook.size();p++){
        farmertot.try_emplace(logbook[p].farmer,0);
        farmerdev.try_emplace(logbook[p].farmer,0);
        if(farmertot[logbook[p].farmer]==0){
            farmer.push_back(logbook[p].farmer);
        }
        farmertot[logbook[p].farmer]+=logbook[p].kg;
        farmerdev[logbook[p].farmer]++;

    }
    string bigW= farmer[0];
    string bigde= farmer[0];
    for (int q=0;q<farmer.size();q++){
        
        if (farmertot[farmer[q]]>farmertot[bigW]){
            bigW=farmer[q];
        }
        if (farmerdev[farmer[q]]>farmerdev[bigde]){
            bigde=farmer[q];
        }
    }
    cout<< " Most Deliveries: " << bigde << " (" << farmerdev[bigde] << " )" << endl;
    cout<< " Most Kg: " << bigW << " (" << farmertot[bigW] << " kg)" << endl;




    cout << "\n";


    // =================================================================
    //  Q4  ·  PAYMENT RUN WITH A DAILY CAP  (see README)
    //  Uses: logbook, and the payment function you write below main
    // =================================================================

    cout << "=== Q4 ===\n";





    cout << "\n";


    // =================================================================
    //  Q5  ·  THE VALIDATION REPORT         (see README)
    //  Uses: rawRecords
    // =================================================================

    cout << "=== Q5 ===\n";





    cout << "\n";

    // =================================================================
    //  Q6  ·  IGISORO: A FULL TURN          (see README)
    //  Uses: board
    // =================================================================

    cout << "=== Q6 ===\n";



    
    // =================================================================
    //  STRETCH  ·  optional
    // =================================================================

    // =================================================================
    //  Q7  ·  SORT THE LOGBOOK              (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q7 ===\n";





    // =================================================================
    //  Q8  ·  SPOTTING DOUBLE-ENTRIES       (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q8 ===\n";





    return 0;
}


// =====================================================================
//  FUNCTIONS YOU WRITE
//
//  C++ reads a file top to bottom, so a function must be DECLARED above
//  the place that calls it. These two are declared here at the bottom,
//  which main() cannot see — so move them ABOVE main(), or leave a
//  one-line declaration up there. Working that out is part of Q3.
// =====================================================================

// Q3:  return the position of the first delivery by this farmer,
//      or -1 if the farmer is not in the log at all.
//


// Q4:  what one delivery earns, before any cap is applied.
//      Grade A pays 10% above the rate, B pays the rate,
//      anything else pays 20% below it. The rate is 450.
//
// double payment(double kg, char grade) {
//
// }
