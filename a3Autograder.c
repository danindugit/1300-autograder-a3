// make clean && make a3=A3.c && ./autoGrader commonWealth.txt.txt > output.txt

#include <stdio.h>
#include <string.h>
#include <math.h>

#define COUNTRIES 15
#define MEDALCAT 3
#define MAX_LENGTH_CNAME 100

// student functions
void readFromFile(char fName[30], int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100]);
void findTotalPerCountry(int country[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES]);
int findTotalPerMedal(int country[COUNTRIES][MEDALCAT], int totalAllMedals[COUNTRIES], int *whichMedal);
void hHistogram(char countryNames[COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);
// void vHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);
int searchCountry(char countryName[100], char countryNames[COUNTRIES][100], int totalAllCountries[COUNTRIES]);
void rankTopThreeByTotal(int totalMedals[COUNTRIES], char countryNames[COUNTRIES][100]);
void rankTopThreeByMedal(int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100]);
int findAllWithNoXMedals(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES]);
int findAllWithOnlyXMedals(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES]);
int findCountryIndexWithMinOrMaxLength(int minOrMax, char countryNames[COUNTRIES][100]);

// solution functions
void readFromFileExpected(char fName[30], int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100]);
void findTotalPerCountryExpected(int country [COUNTRIES][MEDALCAT], int totalAllCountries [COUNTRIES]);
void rankTopThreeByTotalExpected(int totalMedals[COUNTRIES], char countryNames[COUNTRIES][100]);
void rankTopThreeByMedalExpected(int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100]);
int findAllWithNoXMedalsExpected(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES]);
int findAllWithOnlyXMedalsExpected(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES]);
int findCountryIndexWithMinOrMaxLengthExpected(int minOrMax, char countryNames[COUNTRIES][100]);

//Test functions
double readFromFileTest(char* filename, int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100]);
double findTotalPerCountryTest(int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES], char countryNamesExpected[COUNTRIES][100]);


int main(int argc, char *argv[]) {

    fprintf(stderr, "Welcome to the A3 Autograder\n");

    int country[COUNTRIES][MEDALCAT];
    int totalAllMedals[MEDALCAT];
    int row, maxMedal, whichMedal, totalM;
    int totalAllCountries[COUNTRIES];
    char countryNames[COUNTRIES][100];
    char name[100];
    int indexOfCountries[COUNTRIES];
    int cIndex, minOrMax;
    int choice;

    // results
    int findAllWithNoXMedalsResult = 0;
    int findAllWithOnlyXMedalsResult = 0;

    // expected
    int countryExpected[COUNTRIES][3];
    char countryNamesExpected[COUNTRIES][100];
    int totalAllCountriesExpected[COUNTRIES];

    // marks
    double readFromFileMark = 10.0;
    double findTotalPerCountryMark = 8.0;
    double findTotalPerMedalMark = 6.0;
    double rankTopThreeByTotalMark = 0;
    double rankTopThreeByMedalMark = 0;
    int findAllWithNoXMedalsMark = 0;
    int findAllWithOnlyXMedalsMark = 0;

    // ----------- Testing readFromFile ----------- //

    fprintf(stderr, "TESTING readFromFile (10)\n");
    readFromFileMark = readFromFileTest(argv[1], country, countryExpected, countryNames, countryNamesExpected);
    fprintf(stderr, "%.1lf/10\n", readFromFileMark);

    // ----------- Testing findTotalPerCountry ----------- //

    fprintf(stderr, "TESTING findTotalPerCountry (8)\n");
    findTotalPerCountryMark = findTotalPerCountryTest(country, countryExpected, totalAllCountries, totalAllCountriesExpected, countryNamesExpected);
    fprintf(stderr, "%.1lf/8\n", findTotalPerCountryMark);

    // ----------- Testing findTotalPerMedal ----------- //


    // ----------- Testing hHistogram ----------- //


    // ----------- Testing searchCountry ----------- //


    // ----------- Testing rankTopThreeByTotal ----------- //

    fprintf(stderr, "TESTING rankTopThreeByTotal (8)\n");
    fprintf(stderr, "Student's Output:\n");
    printf("TESTING RANK TO 3 BY TOTAL\n");
    rankTopThreeByTotal(totalAllCountries, countryNames);
    printf("TESTING RANK TO 3 BY TOTAL\n");
    fprintf(stderr, "\nExpected Ouput:\n");
    fprintf(stderr, "Australia (178)\nEngland (176)\nCanada (92)\n");
    fprintf(stderr, "Please assign a grade out of 8 for how well the student's output matches the expected output:\n");
    do
    {
        scanf("%lf", &rankTopThreeByTotalMark);
        if (rankTopThreeByTotalMark < 0 || rankTopThreeByTotalMark > 8)
        {
            fprintf(stderr, "Please enter a valid number betwen 0 and 8\n");
        }
    } while (rankTopThreeByTotalMark < 0 || rankTopThreeByTotalMark > 8);

    // ----------- Testing rankTopThreeByTotal ----------- //

    // ----------- Testing rankTopThreeByMedal ----------- //

    fprintf(stderr, "TESTING rankTopThreeByMedal (8)\n");
    fprintf(stderr, "Student's Output:\n");
    rankTopThreeByMedal(country, countryNames);
    fprintf(stderr, "\nExpected Ouput:\n");
    fprintf(stderr, "Australia (67)\nEngland (57)\nCanada (26)\n");
    fprintf(stderr, "Please assign a grade out of 8 for how well the student's output matches the expected output:\n");
    do
    {
        scanf("%lf", &rankTopThreeByMedalMark);
        if (rankTopThreeByMedalMark < 0 || rankTopThreeByMedalMark > 8)
        {
            fprintf(stderr, "Please enter a valid number betwen 0 and 8\n");
        }
    } while (rankTopThreeByMedalMark < 0 || rankTopThreeByMedalMark > 8);

    // ----------- Testing rankTopThreeByMedal ----------- //

    // ----------- Testing findAllWithNoXMedals ----------- //

    fprintf(stderr, "TESTING findAllWithNoXMedals (12)\n");
    // gold
    findAllWithNoXMedalsResult = findAllWithNoXMedals(country, 1, indexOfCountries);
    if (findAllWithNoXMedalsResult != 3)
    {
        fprintf(stderr, "TEST CASE FAILED\n Count -- %d != 3\n", findAllWithNoXMedalsResult);
    }
    else
    {
        findAllWithNoXMedalsMark++;
        // expected indices: 12, 13, 14
        for (int i = 0; i < findAllWithNoXMedalsResult; i++)
        {
            if (indexOfCountries[i] == 12 || indexOfCountries[i] == 13 || indexOfCountries[i] == 14)
            {
                findAllWithNoXMedalsMark++;
            }
        }
    }
    // silver
    findAllWithNoXMedalsResult = findAllWithNoXMedals(country, 2, indexOfCountries);
    if (findAllWithNoXMedalsResult != 3)
    {
        fprintf(stderr, "TEST CASE FAILED\n Count -- %d != 3\n", findAllWithNoXMedalsResult);
    }
    else
    {
        findAllWithNoXMedalsMark++;
        // expected indices: 9, 11, 13
        for (int i = 0; i < findAllWithNoXMedalsResult; i++)
        {
            if (indexOfCountries[i] == 9 || indexOfCountries[i] == 11 || indexOfCountries[i] == 13)
            {
                findAllWithNoXMedalsMark++;
            }
        }
    }
    // bronze
    findAllWithNoXMedalsResult = findAllWithNoXMedals(country, 3, indexOfCountries);
    if (findAllWithNoXMedalsResult != 3)
    {
        fprintf(stderr, "TEST CASE FAILED\n Count -- %d != 3\n", findAllWithNoXMedalsResult);
    }
    else
    {
        findAllWithNoXMedalsMark++;
        // expected indices: 10, 11, 14
        for (int i = 0; i < findAllWithNoXMedalsResult; i++)
        {
            if (indexOfCountries[i] == 10 || indexOfCountries[i] == 11 || indexOfCountries[i] == 14)
            {
                findAllWithNoXMedalsMark++;
            }
        }
    }
    fprintf(stderr, "Mark for findAllWithNoXMedals = %d\n", findAllWithNoXMedalsMark);

    // ----------- Testing findAllWithNoXMedals ----------- //

    // ----------- Testing findAllWithOnlyXMedals ----------- //

    fprintf(stderr, "TESTING findAllWithOnlyXMedals (12)\n");
    // gold
    findAllWithOnlyXMedalsResult = findAllWithOnlyXMedals(country, 1, indexOfCountries);
    if (findAllWithOnlyXMedalsResult != 1)
    {
        fprintf(stderr, "TEST CASE FAILED\n Count -- %d != 3\n", findAllWithOnlyXMedalsResult);
    }
    else
    {
        findAllWithOnlyXMedalsMark += 2;
        // expected index = 11
        if (indexOfCountries[0] == 11)
        {
            findAllWithOnlyXMedalsMark += 2;
        }
    }
    // silver
    findAllWithOnlyXMedalsResult = findAllWithOnlyXMedals(country, 2, indexOfCountries);
    if (findAllWithOnlyXMedalsResult != 1)
    {
        fprintf(stderr, "TEST CASE FAILED\n Count -- %d != 3\n", findAllWithOnlyXMedalsResult);
    }
    else
    {
        findAllWithOnlyXMedalsMark += 2;
        // expected index = 14
        if (indexOfCountries[0] == 14)
        {
            findAllWithOnlyXMedalsMark += 2;
        }
    }
    // bronze
    findAllWithOnlyXMedalsResult = findAllWithOnlyXMedals(country, 3, indexOfCountries);
    if (findAllWithOnlyXMedalsResult != 1)
    {
        fprintf(stderr, "TEST CASE FAILED\n Count -- %d != 3\n", findAllWithOnlyXMedalsResult);
    }
    else
    {
        findAllWithOnlyXMedalsMark += 2;
        // expected index = 13
        if (indexOfCountries[0] == 13)
        {
            findAllWithOnlyXMedalsMark += 2;
        }
    }
    fprintf(stderr, "Mark for findAllWithOnlyXMedals = %d\n", findAllWithOnlyXMedalsMark);

    // ----------- Testing findAllWithOnlyXMedals ----------- //


    // ----------- Testing findCountryIndexWithMinOrMaxLength  ----------- //


    // ----------- Testing findCountryIndexWithMinOrMaxLength  ----------- //

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

void readFromFileExpected(char fName[30], int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100])
{

    int row;
    FILE *fPtr = fopen(fName, "r");
    row = 0;

    while (!feof(fPtr))
    {

        fscanf(fPtr, "%s %d %d %d\n", countryNames[row], &country[row][0], &country[row][1], &country[row][2]);
        row++;
    }
}

void findTotalPerCountryExpected(int country [COUNTRIES][MEDALCAT], int totalAllCountries [COUNTRIES]){
   

   printf ("In findTotal\n");
   
   for (int i = 0; i < COUNTRIES; i++) {
   
      totalAllCountries [i] = 0;
   
      for (int j = 0; j < 3; j++) {
          
          totalAllCountries [i] += country [i][j];
      }
    }
   
   return ;
}

void rankTopThreeByTotalExpected(int totalMedals[COUNTRIES], char countryNames[COUNTRIES][100])
{
    int currentMax, currentIndex;

    for (int i = 0; i < 3; i++)
    {
        findMax(totalMedals, &currentMax, &currentIndex);

        printf("%s (%d)\n", countryNames[currentIndex], totalMedals[currentIndex]);
        totalMedals[currentIndex] = -1000;
    }

    return;
}

void rankTopThreeByMedalExpected(int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100])
{
    int gold[COUNTRIES];

    int currentMax, currentIndex;

    for (int i = 0; i < COUNTRIES; i++)
    {
        gold[i] = country[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        findMax(gold, &currentMax, &currentIndex);

        printf("%s (%d)\n", countryNames[currentIndex], gold[currentIndex]);
        gold[currentIndex] = -1000;
    }
}

int findAllWithNoXMedalsExpected(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES])
{
    int total = 0;

    int gold[COUNTRIES], silver[COUNTRIES], bronze[COUNTRIES];

    for (int i = 0; i < COUNTRIES; i++)
    {
        indexOfCountries[i] = -1;
    }

    for (int i = 0; i < COUNTRIES; i++)
    {
        gold[i] = country[i][0];
    }

    for (int i = 0; i < COUNTRIES; i++)
    {
        silver[i] = country[i][1];
    }

    for (int i = 0; i < COUNTRIES; i++)
    {
        bronze[i] = country[i][2];
    }

    for (int i = 0; i < COUNTRIES; i++)
    {

        switch (indexMedal)
        {

        case 0:
            if (gold[i] == 0)
            {
                indexOfCountries[i] = 1; // index becomes 1 when 0 medal is found for a country
                total++;
            }
            break;
        case 1:
            if (silver[i] == 0)
            {
                indexOfCountries[i] = 1; // index becomes 1 when 0 medal is found for a country
                total++;
            }
            break;

        case 2:
            if (bronze[i] == 0)
            {
                indexOfCountries[i] = 1; // index becomes 1 when 0 medal is found for a country
                total++;
            }
            break;
        }
    }
    return total;
}

int findAllWithOnlyXMedalsExpected(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES])
{
    int total = 0;

    int gold[COUNTRIES], silver[COUNTRIES], bronze[COUNTRIES];

    for (int i = 0; i < COUNTRIES; i++)
    {
        indexOfCountries[i] = -1;
    }

    for (int i = 0; i < COUNTRIES; i++)
    {
        gold[i] = country[i][0];
    }

    for (int i = 0; i < COUNTRIES; i++)
    {
        silver[i] = country[i][1];
    }

    for (int i = 0; i < COUNTRIES; i++)
    {
        bronze[i] = country[i][2];
    }

    for (int i = 0; i < COUNTRIES; i++)
    {

        switch (indexMedal)
        {

        case 0:
            if (gold[i] >= 0 && silver[i] == 0 && bronze[i] == 0)
            {
                indexOfCountries[i] = 1; // index becomes 1 when 0 medal is found for a country
                total++;
            }
            break;
        case 1:
            if (gold[i] == 0 && silver[i] >= 0 && bronze[i] == 0)
            {
                indexOfCountries[i] = 1; // index becomes 1 when 0 medal is found for a country
                total++;
            }
            break;

        case 2:
            if (gold[i] == 0 && silver[i] == 0 && bronze[i] >= 0)
            {
                indexOfCountries[i] = 1; // index becomes 1 when 0 medal is found for a country
                total++;
            }
            break;
        }
    }

    return total;
}

int findCountryIndexWithMinOrMaxLengthExpected(int minOrMax, char countryNames[COUNTRIES][100])
{
    int m = strlen(countryNames[0]);
    int index;

    if (minOrMax == 1)
    { // for min

        for (int i = 0; i < COUNTRIES; i++)
        {

            if (strlen(countryNames[i]) < m)
            {
                m = strlen(countryNames[i]);
                index = i;
            }
        }
    }
    else
    { // for max
        for (int i = 0; i < COUNTRIES; i++)
        {

            if (strlen(countryNames[i]) > m)
            {
                m = strlen(countryNames[i]);
                index = i;
            }
        }
    }

    return index;
}

double readFromFileTest(char* filename, int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100]) {
    double readFromFileMark = 10.0;
    readFromFileExpected(filename, countryExpected, countryNamesExpected);
    readFromFile(filename, country, countryNames);
    for (int i = 0; i < COUNTRIES; i++)
    {
        if (strcmp(countryNames[i], countryNamesExpected[i]) != 0)
        {
            fprintf(stderr, "TEST CASE FAILED\nCountry name -- %s != %s\n", countryNames[i], countryNamesExpected[i]);
            readFromFileMark -= 0.5;
        }
        for (int j = 0; j < MEDALCAT; j++)
        {
            if (country[i][j] != countryExpected[i][j])
            {
                fprintf(stderr, "TEST CASE FAILED\nCountry: %s Medal: %d != %d\n", countryNames[i], country[i][j], countryExpected[i][j]);
                readFromFileMark -= 0.5;
            }
        }
    }

    if (readFromFileMark < 0.0)
    {
        readFromFileMark = 0.0;
    }

    return readFromFileMark;
}

double findTotalPerCountryTest(int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES], char countryNamesExpected[COUNTRIES][100]) {
    double findTotalPerCountryMark = 10.0;
    findTotalPerCountryExpected(countryExpected, totalAllCountriesExpected);
    findTotalPerCountry(country, totalAllCountries);

    for (int i = 0; i < COUNTRIES; i++) {
        if (totalAllCountries[i] != totalAllCountriesExpected[i])
            {
                fprintf(stderr, "TEST CASE FAILED\n%s: %d != %d\n", countryNamesExpected[i], totalAllCountries[i], totalAllCountriesExpected[i]);
                findTotalPerCountryMark -= 0.5;
            }
    }

    if (findTotalPerCountryMark == 0.5)
    {
        findTotalPerCountryMark = 0.0;
    }

    return findTotalPerCountryMark;
}
