//
// Assignment 2
// Daniela Gigliotti
// COM SCI X 414.20 (Fall 2018)
//

// Declare libraries
#include <stdio.h>

// Define function prototypes
void CollectVal(void);  // Collect values from source file
void CalcRatio(void);   // Calculate current ratio for each year
void CalcAvg(void);     // Calculate average for all years
void Report(void);  // Print details and calculations to output file


// Define constants for each year
const int yearA = 2010;
const int yearB = 2011;
const int yearC = 2012;


// Define variables
float assetA;   // Current Assets for yearA
float assetB;   // Current Assets for yearB
float assetC;   // Current Assets for yearC
float liabA;    // Current Liabilities for yearA
float liabB;    // Current Liabilities for yearB
float liabC;    // Current Liabilities for yearC
float currRatA; // Current Ratio for yearA
float currRatB; // Current Ratio for yearB
float currRatC; // Current Ratio for yearC
float avgAssets;    // Average Assets for all years
float avgLiab;      // Average Liabilities for all years
float avgCurrRatio; // Average Current Ratio for all years
char name[31];  // Company name


// Declare input and output files
FILE *inputfile;
FILE *outputfile;


// Main function to open report and call other functions
float main(void){

    // Open file with current assets and current liabilities
    inputfile = fopen("c:\\class\\current.txt", "r");

    // Call functions
    CollectVal();  // Collect assets and liabilities for each year from source file
  	CalcRatio();   // Calculate current ratio for each year
	CalcAvg();     // Calculate average assets, liabilities, and current ratio
	Report();      // Print details and calculations to output file

    return 0;
}


// Collect values from file
void CollectVal(void) {
    fgets(name, 31, inputfile);
    fscanf(inputfile, "%f%f\n", &assetA, &liabA);
    fscanf(inputfile, "%f%f\n", &assetB, &liabB);
    fscanf(inputfile, "%f%f\n", &assetC, &liabC);

    // Close source file
    fclose(inputfile);
}


// Calculate current ratio for each year
void CalcRatio(void) {
    currRatA = assetA/liabA;
    currRatB = assetB/liabB;
    currRatC = assetC/liabC;
}


// Calculate average assets, liabilities, and current ratio for the three years
void CalcAvg(void) {
    avgAssets = ((assetA + assetB + assetC)/3);
    avgLiab = ((liabA + liabB + liabC)/3);
    avgCurrRatio = ((currRatA + currRatB + currRatC)/3);
}


// Print details and calculations to output file
void Report(void) {

    // Open and write to output file
    outputfile = fopen ("c:\\class\\dgigliotti-cr.txt","w");

    // Write to output file
    fprintf(outputfile,"%sCurrent Ratio Report\n\n", name);
    fprintf(outputfile, "               Current           Current         Current\n");
    fprintf(outputfile, "Year           Assets            Liabilities       Ratio\n");
    fprintf(outputfile,"--------------------------------------------------------\n");
    fprintf(outputfile, "%d            %6.0f            %6.0f            %4.2f\n", yearA, assetA, liabA, currRatA);
    fprintf(outputfile, "%d            %6.0f            %6.0f            %4.2f\n", yearB, assetB, liabB, currRatB);
    fprintf(outputfile, "%d            %6.0f            %6.0f            %4.2f\n", yearC, assetC, liabC, currRatC);
    fprintf(outputfile,"--------------------------------------------------------\n");
    fprintf(outputfile, "Average         %6.0f            %6.0f            %4.2f\n\n", avgAssets, avgLiab, avgCurrRatio);
    fprintf(outputfile, "This report was produced by Daniela Gigliotti.");

     // Close output file
    fclose(outputfile);
}

