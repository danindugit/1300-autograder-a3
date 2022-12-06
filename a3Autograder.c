//make clean && make a3=A3.c && ./autoGrader commonWealth.txt.txt > output.txt

#include <stdio.h>
#include <string.h>
#include <math.h>

#define COUNTRIES 15
#define MEDALCAT 3
#define MAX_LENGTH_CNAME 100

void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][100]);
void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT],int totalAllCountries [COUNTRIES]);
int findTotalPerMedal (int country [COUNTRIES][MEDALCAT],int totalAllMedals [COUNTRIES], int * whichMedal);
void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);
// void vHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);
int searchCountry (char countryName [100], char countryNames [COUNTRIES][100], int totalAllCountries [COUNTRIES]);
void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][100]);
void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][100]);
int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT],int indexMedal, int indexOfCountries [COUNTRIES]);
int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT],int indexMedal, int indexOfCountries [COUNTRIES]);
int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][100]);


int main (int argc, char * argv[]) {

    fprintf(stderr, "Welcome to the A3 Autograder\n");

    //results

    char inputString[100][100];

    //expected


    //marks


    // ----------- Testing isBasePair ----------- // 


 
//     // ----------- Printing Mark ----------- //

//     int totalMarks = isBasePairMark + isItaDnaSequenceMark + reverseMark + 
//     complementItMark + isItPalindromeMark + isStrandDnaPalindromeMark + howManyMark + dnaToMrnaMark + 6;
 
//     printf("\n\n\n");
//     printf("Instant Zero: NONE\n");
//     printf("\tCode that fails to compile with flags (-Wall -std=c99)\n");
//     printf("\tCode uses global variables\n");
//     printf("\tCode uses goto statements\n");
//     printf("\tA main is submitted\n");
//     printf("\n");
//     printf("General Deductions: 0\n");
//     printf("\t-2.5 (5%%) for each unique warning\n");
//     printf("\t-5 (10%%) for incorrect filename (lastnameFirstnameA2.c)\n");
//     printf("\tLateness\n");
//     printf("\n");
//     printf("Style: 5/5\n");
//     printf("\t-2 Header comment\n");
//     printf("\t-1 Variable namming\n");
//     printf("\t-1 Commenting\n");
//     printf("\t-1 Consistent spacing / Readability\n");
//     printf("\n");
//     printf("Program Specifications: %d/45\n", totalMarks);
//     printf("\tisBasePair %d/4\n", isBasePairMark);
//     printf("\tisItaDnaSequence %d/8\n", isItaDnaSequenceMark);
//     printf("\treverse  %d/5\n", reverseMark);
//     printf("\tcomplementIt  %d/6\n", complementItMark);
//     printf("\tisItPalindrome %d/4\n", isItPalindromeMark);
//     printf("\tisStrandDnaPalindrome  %d/4\n", isStrandDnaPalindromeMark);
//     printf("\thowMany %d/3\n", howManyMark);
//     printf("\tdnaToMrna %d/5\n", dnaToMrnaMark);
//     printf("\ttranslateDnaToMrnaProteins  6/6\n");
//     printf("\n");
//     printf("TOTAL %d/50\n", totalMarks+5);
//     printf("\n");
//     printf("Marked by TA Or Brener\n");

    fprintf(stderr, "CONGRADULATIONS, finished marking this student!\n");
    
    
    return 0;
}
