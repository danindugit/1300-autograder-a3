#include <stdio.h>
#include <string.h>
#include <math.h>

#define COUNTRIES 15
#define MEDALCAT 3
#define MAX_LENGTH_CNAME 100

void findMax (int arr [COUNTRIES], int * maxValue, int * maxIndex);

void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][100]);

void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT],
                int totalAllCountries [COUNTRIES]);

int findTotalPerMedal (int country [COUNTRIES][MEDALCAT],
                int totalAllMedals [COUNTRIES], int * whichMedal);

void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);

void vHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);

int searchCountry (char countryName [100], char countryNames [COUNTRIES][100], int totalAllCountries [COUNTRIES]);

void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][100]);


void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][100]);

/* this function returns the total number of countries with no medal = indexMedal (1 for Gold, 2 for Silver...
it stores the indices of all countries that do not have a medal = indexMedal
Note that indexMedal is the input given to the function, whereas indexOfCountries and total number of countries are the outputs
*/

int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT],
						  int indexMedal, int indexOfCountries [COUNTRIES]);

/* this function returns the total number of countries with ONLY medals where medal = indexMedal (1 for Gold, 2 for Silver...
it stores the indices of all countries that have ONLY medal = indexMedal
Note that indexMedal is the input given to the function, whereas indexOfCountries and total number of countries are the outputs
*/

int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT],
						  int indexMedal, int indexOfCountries [COUNTRIES]);

/* return the index of the countryName that has min or max length - use 1 for min and 2 for max)
If there are more than 1 countryNames with the same length, then take your pick and return just one of them
 */
int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][100]);


// int main (int argc, char * argv[]) {

   
//    int country [COUNTRIES][3];
   
//    int totalAllMedals [3];
//    int row, maxMedal, whichMedal, totalM;
   
//    int totalAllCountries [COUNTRIES];
   
//    char countryNames [COUNTRIES][100];
//    char name [100];
   
//    int indexOfCountries [COUNTRIES];
//    int cIndex, minOrMax;
//    int choice;
    
//     readFromFile (argv[1], country, countryNames);

//    //char countryNames [COUNTRIES][100] = {"Japan", "USA", "China", "ROC", "UK", "Australia", "Kosova", "Italy", "France", "Canada"};
   
//     do {
//         printf ("\nHere is the menu \n\n");
//         printf ("1. Display all country names read from file and the total number of medals won by each\n");
//         printf ("2.    Function 2 - Find total number of medals won by each country\n");
//         printf ("3.    Function 3 - Finds total number of medals in each category (Gold, Silver, Bronze)\n");
//         printf ("4.    Function 4 – Display horizontal histogram\n");
//         printf ("5.    Function 5 – Search for a country and return the total number of medals won by it\n");
//         printf ("6.    Function 6 – Rank and display top three countries in order of total medals won\n");
//         printf ("7.    Function 7 – Rank and display top three countries in order of total gold medals won\n");
//         printf ("8.    Function 8 – Find and display all countries that won no X medals, given X as either Gold, Silver or Bronze\n");
//         printf ("9.    Function 9 – Find and display all countries that won ONLY X medals, given X as either Gold, Silver or Bronze\n");
//         printf ("10.   Function 10 – Find and display name of the country that has minimum or maximum length among all countries read in option 1\n");
//         //printf ("10.   Function 11 - Display Vertical Histogram\n");
//         printf ("11.    Exit\n");
        
//         printf ("Enter your choice: ");
//         scanf ("%d", &choice);
        
//         switch (choice) {
//             case 1:
                
//                 /* This loop is only to check if the values are correctly read from the file and placed in arrays*/
//                 for (int i = 0; i < COUNTRIES; i++) {
                    
//                     printf ("Country: %s, ", countryNames [i]);
//                     printf ("Gold = %d, Silver = %d, Bronze = %d\n", country [i][0], country [i] [1], country [i][2]);
                    
//                 }
//                 break;
//             case 2:
//                 findTotalPerCountry (country, totalAllCountries);
                
//                 for (row = 0; row < COUNTRIES; row++) {
                    
//                     printf ("Country %s = %d \n", countryNames [row], totalAllCountries [row]);
//                 }
//                 break;
//             case 3:
//                 maxMedal = findTotalPerMedal (country, totalAllMedals, &whichMedal);
                
//                 for (row = 0; row < 3; row++) {
                    
//                     printf ("Medal = ");
                    
//                     switch (row) {
                            
//                         case 0: printf ("Gold, ");
//                             break;
                            
//                         case 1: printf ("Silver, ");
//                             break;
                            
//                         case 2: printf ("Bronze, ");
//                             break;
//                     }
                    
//                     printf ("Total = %d \n", totalAllMedals [row]);
//                 }
                
//                 printf ("Maximum number of medals = %d in category (", maxMedal);
                
//                 switch (whichMedal) {
                        
//                     case 0: printf ("Gold) \n");
//                         break;
                        
//                     case 1: printf ("Silver) \n");
//                         break;
                        
//                     case 2: printf ("Bronze) \n");
//                         break;
//                 }
                
//                 break;
//             case 4:
//                 printf ("Printing Histogram \n");
//                 hHistogram (countryNames, totalAllCountries);
//                 break;
                
//             case 5:
//                 printf ("Searching for which country? ");
//                 scanf (" %s", name);
                
//                 int countM = searchCountry (name, countryNames, totalAllCountries);
                
//                 if (countM != -1) {
//                     printf ("Found it - %s has a total of %d medals\n", name, countM);
//                 }
//                 else {
//                     printf ("Country name not found in this database\n");
//                 }
                
//                 break;
//             case 6:
//                 printf ("Rank top three Based on total number of medals\n");
                
//                 rankTopThreeByTotal (totalAllCountries, countryNames);
//                 break;
//             case 7:
//                 printf ("Rank top three Based on Gold medals\n");
                
//                 rankTopThreeByMedal (country, countryNames);
//                 break;
//             case 8:
//                 printf ("Which medal do you want to look for - Type 0 for Gold, 1 for Silver, 2 for Bronze? ");
//                 scanf ("%d", &whichMedal);
                
//                 printf ("Number of countries with no ");
                
//                 switch (whichMedal) {
                        
//                     case 0: printf ("Gold ");
//                         break;
                        
//                     case 1: printf ("Silver ");
//                         break;
                        
//                     case 2: printf ("Bronze ");
//                         break;
//                 }
                
//                 totalM = findAllWithNoXMedals (country, whichMedal, indexOfCountries);
                
//                 printf ("medals = %d \n", totalM);
                
//                 for (int i = 0; i < COUNTRIES; i++) {
                    
//                     if (indexOfCountries [i] != -1) {
//                         printf ("%s \n", countryNames [i]);
//                     }
//                 }

//                 break;
//             case 9:
//                 printf ("Which medal do you want to look for - Type 0 for Gold, 1 for Silver, 2 for Bronze? ");
//                 scanf ("%d", &whichMedal);
                
//                 printf ("Number of countries with ONLY ");
                
//                 switch (whichMedal) {
                        
//                     case 0: printf ("Gold ");
//                         break;
                        
//                     case 1: printf ("Silver ");
//                         break;
                        
//                     case 2: printf ("Bronze ");
//                         break;
//                 }
                
//                 totalM = findAllWithOnlyXMedals (country, whichMedal, indexOfCountries);
                
//                 printf ("medals = %d \n", totalM);
                
//                 for (int i = 0; i < COUNTRIES; i++) {
                    
//                     if (indexOfCountries [i] != -1) {
//                         printf ("%s \n", countryNames [i]);
//                     }
//                 }
                
//                 break;
//             case 10:
//                 printf ("Do you want min (enter 1) or max (enter 2)? ");
//                 scanf ("%d", &minOrMax);
                
//                 cIndex = findCountryIndexWithMinOrMaxLength (minOrMax, countryNames);
                
//                 printf ("The country name with ");
                
//                 switch (minOrMax) {
                        
//                     case 1: printf ("minimum "); break;
//                     case 2: printf ("maximum "); break;
//                 }
                
//                 printf ("length = %s\n", countryNames [cIndex]);
//                 break;
             
//            /* case 11:
//                 printf ("Printing Vertical Histogram \n");
//                 vHistogram (countryNames, totalAllCountries);
//                 break;
//              */
//             case 11: printf ("Ok Bye for now\n");
//                 break;
//             default: printf ("That is an invalid choice\n");
                
//         }
        
//     } while (choice != 11);
    
    
//    return 0;
// }

void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][100]) {
    
    int row;
    FILE * fPtr = fopen (fName, "r");
    row = 0;
    
    while (!feof (fPtr)) {
        
        fscanf (fPtr, "%s %d %d %d\n", countryNames [row], &country [row] [0], &country [row] [1], &country [row] [2]);
        row++;
    }
    
}

void findTotalPerCountry (int country [COUNTRIES][MEDALCAT], int totalAllCountries [COUNTRIES]){
   

   printf ("In findTotal\n");
   
   for (int i = 0; i < COUNTRIES; i++) {
   
      totalAllCountries [i] = 0;
   
      for (int j = 0; j < 3; j++) {
          
          totalAllCountries [i] += country [i][j];
      }
    }
   
   return ;
}

/* returns the max one */

int findTotalPerMedal (int country [COUNTRIES][MEDALCAT],
                       int totalAllMedals [MEDALCAT], int * whichMedal){             // index = 1 for Gold, 2 for Silver, 3 for Bronze

   int max;
    int i, j;
    
   printf ("In findTotalPerMedal\n");
    
    for (j = 0; j < MEDALCAT; j++) {
        
        totalAllMedals [j] = 0;
    }
   
    for (i = 0; i < COUNTRIES; i++) {
        for (j = 0; j < MEDALCAT; j++) {
   
          totalAllMedals [j] += country [i][j];
        }
    }
   
   max = totalAllMedals [0];
   *whichMedal = 0;
   
   for (int i = 0; i < MEDALCAT; i++) {
   
      if (totalAllMedals [i] >= max) {
      
         max = totalAllMedals [i];
         *whichMedal = i;
      }
   }
   return max;
}


void hHistogram (char countryNames [COUNTRIES][100], int totalAllCountries[COUNTRIES]){

   printf ("In hHistogram\n");
 
   for (int i = 0; i < COUNTRIES; i++) {
      printf ("%-10s: ", countryNames [i]);
      
      for (int j = 0; j < round(totalAllCountries [i] / 2.0); j++) {
          printf ("*");
      }
      
      printf (" (%d)\n", totalAllCountries [i]);
       //getchar();
   }
   
   return ;
}



int searchCountry (char countryName [100], char countryNames [COUNTRIES][100], int totalAllCountries[COUNTRIES]){

   printf ("In searchCountry\n");
   
   int index = -1;
   
   for (int i = 0; i < COUNTRIES; i++) {
   
      if (strcmp (countryName, countryNames [i]) == 0) {
         index = i;
      }
   }
   
   if (index != -1) {
       return totalAllCountries [index];
   }
   else {
       return -1;
   }
}

void findMax (int arr [COUNTRIES], int * maxValue, int * maxIndex) {
    
    *maxValue = arr [0];
    
    
    for (int i = 0; i < COUNTRIES; i++) {
       
       if (arr [i] >= *maxValue) {
       
          *maxValue = arr [i];
          *maxIndex = i;
       }
    }
    
}

void rankTopThreeByTotal (int totalAllCountries[COUNTRIES], char countryNames [COUNTRIES][100]) {

   //printf ("In rankTopThreeByTotal\n");
   
   int currentMax, currentIndex;
   
   for (int i = 0; i < 3; i++) {
      findMax (totalAllCountries, &currentMax, &currentIndex);
      
      printf ("%s (%d)\n", countryNames [currentIndex], totalAllCountries [currentIndex]);
      totalAllCountries [currentIndex] = -1000;
   }   
   
   return ;
}

void rankTopThreeByMedal (int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][100]) {
   
    int gold [COUNTRIES];
                  
    int currentMax, currentIndex;
   
    for (int i = 0; i < COUNTRIES; i++) {
        gold [i] = country [i][0];
    }
    
    for (int i = 0; i < 3; i++) {
       findMax (gold, &currentMax, &currentIndex);
      
       printf ("%s (%d)\n", countryNames [currentIndex], gold [currentIndex]);
       gold [currentIndex] = -1000;
   }   

}

/* this function returns the total number of countries with no medal = indexMedal (1 for Gold, 2 for Silver...
it stores the indices of all countries that do not have a medal = indexMedal
Note that indexMedal is the input given to the function, whereas indexOfCountries and total number of countries are the outputs
*/

int findAllWithNoXMedals (int country [COUNTRIES][MEDALCAT],
						  int indexMedal, int indexOfCountries [COUNTRIES]){

   int total = 0;
    
    int gold [COUNTRIES], silver [COUNTRIES], bronze [COUNTRIES];
   
   for (int i = 0; i < COUNTRIES; i++) {
      indexOfCountries [i] = -1;
   }

    for (int i = 0; i < COUNTRIES; i++) {
        gold [i] = country [i][0];
    }
    
    for (int i = 0; i < COUNTRIES; i++) {
        silver [i] = country [i][1];
    }
    
    for (int i = 0; i < COUNTRIES; i++) {
        bronze [i] = country [i][2];
    }
                  
   for (int i = 0; i < COUNTRIES; i++) {
   
       switch (indexMedal) {
       
           case 0:
                  if (gold [i] == 0) {
                     indexOfCountries [i] = 1;       // index becomes 1 when 0 medal is found for a country
                     total++;
                  }
                  break;
          case 1: if (silver [i] == 0) {
                     indexOfCountries [i] = 1;       // index becomes 1 when 0 medal is found for a country
                     total++;
                  }
                  break;
                         
          case 2: if (bronze [i] == 0) {
                     indexOfCountries [i] = 1;       // index becomes 1 when 0 medal is found for a country
                     total++;
                  }
                  break;
        }
    }
      return total;
}

int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT],
						    int indexMedal, int indexOfCountries [COUNTRIES]){


   int total = 0;
   
    int gold [COUNTRIES], silver [COUNTRIES], bronze [COUNTRIES];
    
    for (int i = 0; i < COUNTRIES; i++) {
        indexOfCountries [i] = -1;
    }
    
    for (int i = 0; i < COUNTRIES; i++) {
        gold [i] = country [i][0];
    }
    
    for (int i = 0; i < COUNTRIES; i++) {
        silver [i] = country [i][1];
    }
    
    for (int i = 0; i < COUNTRIES; i++) {
        bronze [i] = country [i][2];
    }
                  
   for (int i = 0; i < COUNTRIES; i++) {
   
        switch (indexMedal) {
       
          case 0: if (gold [i] >= 0 && silver [i] == 0 && bronze [i] == 0) {
                     indexOfCountries [i] = 1;       // index becomes 1 when 0 medal is found for a country
                     total++;
                  }
                  break;
          case 1: if (gold [i] == 0 && silver [i] >= 0 && bronze [i] == 0) {
                     indexOfCountries [i] = 1;       // index becomes 1 when 0 medal is found for a country
                     total++;
                  }
                  break;
                         
          case 2: if (gold [i] == 0 && silver [i] == 0 && bronze [i] >= 0) {
                     indexOfCountries [i] = 1;       // index becomes 1 when 0 medal is found for a country
                     total++;
                  }
                  break;
        }
    }
   
   return total;
}


/* return the index of the countryName that has min or max length - use 1 for min and 2 for max)
If there are more than 1 countryNames with the same length, then take your pick and return just one of them*/
int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][100]) {

   int m = strlen (countryNames [0]);
   int index;

   if (minOrMax == 1) {       // for min
   
       for (int i = 0; i < COUNTRIES; i++) {
       
           if (strlen (countryNames [i]) < m) {
               m = strlen (countryNames [i]);
               index = i;    
           }
       }
   
    }
    else {                    // for max
      for (int i = 0; i < COUNTRIES; i++) {
       
           if (strlen (countryNames [i]) > m) {
               m = strlen (countryNames [i]);
               index = i;
           }
       }
    }
    
    return index;   
}

// this was a student's code - NEEDS TO BE FIXED

// //intializes function, passes down arguments countryNames and totalMedals
// void vHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]){
    
//     int maxMedals = 0, maxMedalsR = 0; //initializes variable and sets it to zero
//     int totalMedalsR [COUNTRIES] = {0};
    
//     printf("    "); //prints 4 blank spaces
    
//     //loops through every country
//     for (int i = 0; i < COUNTRIES; i++) {
//         printf("%-11d", totalMedals[i]); //prints the total amount of medals of each country
        
//         if (totalMedals[i] > maxMedals) { //if the total amount of medals is greater than maxMedals
//             maxMedals = totalMedals[i]; //maxMedals is set to the total amount of medals of that country
//         }
//     }
    
//     printf("\n"); //print and newline
    
//     maxMedalsR = (int) round (maxMedals / 2.0);
    
//     for(int j = 0; j < COUNTRIES; j++) {
        
//         totalMedalsR [j] = (int) round (totalMedals [j] / 2.0);
//     }
    
//     //loops starting with the country with the most amount of medals decreaments to zero
//     for (int i = maxMedalsR; i >= 0; i--) {
        
//         printf ("    ");
//         //loops through every country
//         for(int j = 0; j < COUNTRIES; j++) {
//             if (totalMedalsR [j] > i) { //if the country's total medals are greater or equal to i
//                 printf("%-11c", '*'); //outputs a star
//             }
//             else { //if not
//                 printf("%-11c", ' '); //outputs a space
//             }
//         }
//         printf("\n"); //prints two new lines
//     }
    
//     printf("   "); //prints 3 blank spances
    
//     //loops through every country
//     for (int i = 0; i < COUNTRIES; i++){
//         printf("%-11s", countryNames[i]); //outputs each country
//     }
    
//     printf("\n"); //prints a newline
// }




