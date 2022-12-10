# CIS1300-F22-A3-Autograder

# Running the autograder

### `make a3=PLACEHOLDER.c`

PLACEHOLDER.c should be replaced with the studnet's filename

For example: `make a3=khannaSidhantA3.c`

Make sure that givenA3.h is in the same directory as the student's code

### `./autoGrader testData.txt > output.txt`

Don't forget to run `make clean` after each compilation

# Marking the student
- If the student's code runs successfully, a file named output.txt will be created.

- Note that if a student's function is causing seg faults or other terminating errors, just go into the autograder and comment out that function's unit test and give it a zero.

 - At the top there will be the output for hHistogram, rankTopThreeByTotal, and rankTopThreeByMedal copy that and use a text compare (https://text-compare.com/) and compare it to the expected output.

- At the bottom of the ouput, it will generate a filled out marking scheme. You can copy and paste that into courselink. Make sure to change:
    1. "Marked by TA ..." 
    2. Instant Zero (if there are any) marks
    3. General Decudtions (if there are any) marks 
    4. Style marks
    5. hHistogram, rankTopThreeByTotal, and rankTopThreeByMedal marks
    6. You can also add the failing test case (if there are any) if you'd like to
    7. Final mark if there are any deductions

# Associated Links
* https://docs.google.com/document/d/1udPHCuShQIsp0M8cfHoTushJnt4fUSkUvLhefM5Twok/edit?usp=sharing

 * https://text-compare.com/