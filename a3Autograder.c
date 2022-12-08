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
void findTotalPerCountryExpected(int country[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES]);
int findTotalPerMedalExpected(int country[COUNTRIES][MEDALCAT], int totalAllMedals[MEDALCAT], int *whichMedal);
void hHistogramExpected(char countryNames[COUNTRIES][100], int totalAllCountries[COUNTRIES]);
int searchCountryExpected(char countryName[100], char countryNames[COUNTRIES][100], int totalAllCountries[COUNTRIES]);
void rankTopThreeByTotalExpected(int totalMedals[COUNTRIES], char countryNames[COUNTRIES][100]);
void rankTopThreeByMedalExpected(int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100]);
int findAllWithNoXMedalsExpected(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES]);
int findAllWithOnlyXMedalsExpected(int country[COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries[COUNTRIES]);
int findCountryIndexWithMinOrMaxLengthExpected(int minOrMax, char countryNames[COUNTRIES][100]);

// Test functions
double readFromFileTest(char *filename, int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100]);
double findTotalPerCountryTest(int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES], char countryNamesExpected[COUNTRIES][100]);
double findTotalPerMedalTest(int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], int totalAllMedals[MEDALCAT], int totalAllMedalsExpected[MEDALCAT]);
double hHistogramTest(char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES]);
double searchCountryTest(char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES]);

int main(int argc, char *argv[])
{

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
    int totalAllMedalsExpected[MEDALCAT];

    // marks
    double readFromFileMark = 10.0;
    double findTotalPerCountryMark = 8.0;
    double findTotalPerMedalMark = 6.0;
    double hHistogramMark = 10.0;
    double searchCountryMark = 8.0;
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

    fprintf(stderr, "TESTING findTotalPerMedal (6)\n");
    findTotalPerMedalMark = findTotalPerMedalTest(country, countryExpected, totalAllMedals, totalAllMedalsExpected);
    fprintf(stderr, "%.1lf/6\n", findTotalPerMedalMark);

    // ----------- Testing hHistogram ----------- //

    fprintf(stderr, "TESTING hHistogram (10)\n");
    fprintf(stderr, "NEED TO MANUALLY GRADE\n");
    hHistogramMark = hHistogramTest(countryNames, countryNamesExpected, totalAllCountries, totalAllCountriesExpected);

    // ----------- Testing searchCountry ----------- //

    fprintf(stderr, "TESTING searchCountry (8)\n");
    searchCountryMark = searchCountryTest(countryNames, countryNamesExpected, totalAllCountries, totalAllCountriesExpected);
    fprintf(stderr, "%.1lf/8\n", searchCountryMark);

    // ----------- Testing rankTopThreeByTotal ----------- //

    fprintf(stdout, "TESTING rankTopThreeByTotal\n");
    rankTopThreeByTotal(totalAllCountries, countryNames);
    fprintf(stdout, "TESTING rankTopThreeByTotal\n");

    // ----------- Testing rankTopThreeByTotal ----------- //

    // ----------- Testing rankTopThreeByMedal ----------- //

    fprintf(stdout, "TESTING rankTopThreeByMedal\n");
    rankTopThreeByMedal(country, countryNames);
    fprintf(stdout, "TESTING rankTopThreeByMedal\n");

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

    //     fprintf(stdout,"\n\n\n");
    //     fprintf(stdout,"Instant Zero: NONE\n");
    //     fprintf(stdout,"\tCode that fails to compile with flags (-Wall -std=c99)\n");
    //     fprintf(stdout,"\tCode uses global variables\n");
    //     fprintf(stdout,"\tCode uses goto statements\n");
    //     fprintf(stdout,"\tA main is submitted\n");
    //     fprintf(stdout,"\n");
    //     fprintf(stdout,"General Deductions: 0\n");
    //     fprintf(stdout,"\t-2.5 (5%%) for each unique warning\n");
    //     fprintf(stdout,"\t-5 (10%%) for incorrect filename (lastnameFirstnameA2.c)\n");
    //     fprintf(stdout,"\tLateness\n");
    //     fprintf(stdout,"\n");
    //     fprintf(stdout,"Style: 5/5\n");
    //     fprintf(stdout,"\t-2 Header comment\n");
    //     fprintf(stdout,"\t-1 Variable namming\n");
    //     fprintf(stdout,"\t-1 Commenting\n");
    //     fprintf(stdout,"\t-1 Consistent spacing / Readability\n");
    //     fprintf(stdout,"\n");
    //     fprintf(stdout,"Program Specifications: %d/45\n", totalMarks);
    //     fprintf(stdout,"\tisBasePair %d/4\n", isBasePairMark);
    //     fprintf(stdout,"\tisItaDnaSequence %d/8\n", isItaDnaSequenceMark);
    //     fprintf(stdout,"\treverse  %d/5\n", reverseMark);
    //     fprintf(stdout,"\tcomplementIt  %d/6\n", complementItMark);
    //     fprintf(stdout,"\tisItPalindrome %d/4\n", isItPalindromeMark);
    //     fprintf(stdout,"\tisStrandDnaPalindrome  %d/4\n", isStrandDnaPalindromeMark);
    //     fprintf(stdout,"\thowMany %d/3\n", howManyMark);
    //     fprintf(stdout,"\tdnaToMrna %d/5\n", dnaToMrnaMark);
    //     fprintf(stdout,"\ttranslateDnaToMrnaProteins  6/6\n");
    //     fprintf(stdout,"\n");
    //     fprintf(stdout,"TOTAL %d/50\n", totalMarks+5);
    //     fprintf(stdout,"\n");
    //     fprintf(stdout,"Marked by TA Or Brener\n");

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

void findTotalPerCountryExpected(int country[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES])
{

    printf("In findTotal\n");

    for (int i = 0; i < COUNTRIES; i++)
    {

        totalAllCountries[i] = 0;

        for (int j = 0; j < 3; j++)
        {

            totalAllCountries[i] += country[i][j];
        }
    }

    return;
}

int findTotalPerMedalExpected(int country[COUNTRIES][MEDALCAT], int totalAllMedals[MEDALCAT], int *whichMedal)
{
    int max;
    int i, j;

    printf("In findTotalPerMedal\n");

    for (j = 0; j < MEDALCAT; j++)
    {

        totalAllMedals[j] = 0;
    }

    for (i = 0; i < COUNTRIES; i++)
    {
        for (j = 0; j < MEDALCAT; j++)
        {

            totalAllMedals[j] += country[i][j];
        }
    }

    max = totalAllMedals[0];
    *whichMedal = 0;

    for (int i = 0; i < MEDALCAT; i++)
    {

        if (totalAllMedals[i] >= max)
        {

            max = totalAllMedals[i];
            *whichMedal = i;
        }
    }
    return max;
}

void hHistogramExpected(char countryNames[COUNTRIES][100], int totalAllCountries[COUNTRIES])
{

    printf("In hHistogram\n");

    for (int i = 0; i < COUNTRIES; i++)
    {
        printf("%-10s: ", countryNames[i]);

        for (int j = 0; j < round(totalAllCountries[i] / 2.0); j++)
        {
            printf("*");
        }

        printf(" (%d)\n", totalAllCountries[i]);
        // getchar();
    }

    return;
}

int searchCountryExpected(char countryName[100], char countryNames[COUNTRIES][100], int totalAllCountries[COUNTRIES])
{

    printf("In searchCountry\n");

    int index = -1;

    for (int i = 0; i < COUNTRIES; i++)
    {

        if (strcmp(countryName, countryNames[i]) == 0)
        {
            index = i;
        }
    }

    if (index != -1)
    {
        return totalAllCountries[index];
    }
    else
    {
        return -1;
    }
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

double readFromFileTest(char *filename, int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100])
{
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

double findTotalPerCountryTest(int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES], char countryNamesExpected[COUNTRIES][100])
{
    double findTotalPerCountryMark = 8.0;
    findTotalPerCountryExpected(countryExpected, totalAllCountriesExpected);
    findTotalPerCountry(country, totalAllCountries);

    for (int i = 0; i < COUNTRIES; i++)
    {
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

double findTotalPerMedalTest(int country[COUNTRIES][MEDALCAT], int countryExpected[COUNTRIES][MEDALCAT], int totalAllMedals[MEDALCAT], int totalAllMedalsExpected[MEDALCAT])
{
    double findTotalPerMedalMark = 6.0;
    char medals[3][100] = {"Gold", "Silver", "Bronze"};
    int choice = 1;
    int outputExpected = findTotalPerMedalExpected(countryExpected, totalAllMedalsExpected, &choice);
    int output = findTotalPerMedal(country, totalAllMedals, &choice);

    for (int i = 0; i < MEDALCAT; i++)
    {
        if (totalAllMedals[i] != totalAllMedalsExpected[i])
        {
            fprintf(stderr, "TEST CASE FAILED\n%s: %d != %d\n", medals[i], totalAllMedals[i], totalAllMedalsExpected[i]);
            findTotalPerMedalMark -= 2.0;
        }
    }

    return findTotalPerMedalMark;
}

double hHistogramTest(char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES])
{
    double hHistogramMark = 10.0;

    fprintf(stdout, "\n\nhHistogram Expected\n\n");
    hHistogramExpected(countryNamesExpected, totalAllCountriesExpected);
    fprintf(stdout, "\n\nhHistogram Student's output\n\n");
    hHistogram(countryNames, totalAllCountries);
    fprintf(stdout, "\n\n\n\n");

    return hHistogramMark;
}

double searchCountryTest(char countryNames[COUNTRIES][100], char countryNamesExpected[COUNTRIES][100], int totalAllCountries[COUNTRIES], int totalAllCountriesExpected[COUNTRIES])
{
    double searchCountryMark = 8.0;
    int outputExpected = 0;
    int output = 0;

    for (int i = 0; i < COUNTRIES; i++)
    {
        outputExpected = searchCountryExpected(countryNamesExpected[i], countryNamesExpected, totalAllCountriesExpected);
        output = searchCountry(countryNames[i], countryNames, totalAllCountries);
        if (output != outputExpected)
        {
            fprintf(stderr, "TEST CASE FAILED\n%s: %d != %d\n", countryNamesExpected[i], output, outputExpected);
            searchCountryMark -= 0.5;
        }
    }

    outputExpected = searchCountryExpected("Russia", countryNamesExpected, totalAllCountriesExpected);
    output = searchCountry("Russia", countryNames, totalAllCountries);
    if (output != outputExpected)
    {
        fprintf(stderr, "TEST CASE FAILED\n%s: %d != %d\n", "Russia", output, outputExpected);
        searchCountryMark -= 0.5;
    }

    return searchCountryMark;
}
