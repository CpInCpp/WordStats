/*
Project 3:  Word Stats.

This project successfully imports the text from words.txt and outputs various stats about the words of that file.
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;


int main(){

    ifstream fin;
    ofstream fout;

    // Open input file to read-in the data
    char inFilename[] = "//users/stefanienelson/desktop/words.txt";
    fin.open(inFilename);
    if (fin.is_open()) {
        // Input file opened successfully
        cout << "Input file " << inFilename << " opened successfully\n";
        }
        else{
            // Input file failed to open
            cout << "Input file " << inFilename << " failed to open\n";
            exit(1);
            }

            // Open output file to write the results
            char outFilename[] = "//users/stefanienelson/desktop/output.txt";
            fout.open(outFilename);
            if (fin.is_open()) {
                // Input file opened successfully
                cout << "Output file " << outFilename << " opened successfully\n";

            }
            else{
                // Input file failed to open
                cout << "Output file " << outFilename << " failed to open\n";
                exit(1);
            }


    int numberWords = 0;
    int numberLetters = 0;
    const int charLimit = 50;
    const int distrLimit = 13;

    // Read-in the data in the input file
    char word[charLimit]; //80 bytes of memory to be allocated per word.  At one byte per element, this is also the number of allowed characters per word.
    int n=0;    //set counter, n to zero.
    int maxLetter = 0;  //set maximum letter count to zero.
    int lenFreq[charLimit]={0};  //initialize an array for number of letters per word with the same number of elements as the expected character limit.
    int letFreq[26]={0}; // initialize an array for a frequency distribution of different letters.

    while (!fin.eof()) {
        fin >> word;

        lenFreq[strlen(word)]++;

        for (int l=0; l<strlen(word); l++){ //this loop will count each letter and place the number into array, letFreq.
            char c = word[l];
            if ('c'>=97 && 'c'<=122){
                letFreq[c-97]++;
            }
        }
        numberWords++;
        numberLetters += strlen(word);
    }


    //******************************
    //This block is just for finding the remainder of words outside
    // of the length distribution from 1-13

    int remainder=0;      //initialize int remainder and set to zero
    for (int i=distrLimit+1; i<charLimit; i++){       //add the remaining elements of the length frequency array
        remainder += lenFreq[i];
    }

    //int remainder = numberWords-sum;
    //*******************************


        cout << "Number of words in file words.txt: " << numberWords << endl;
        cout << "Number of words in file words.txt: " << numberLetters << endl;
        cout << "max word length: " << distance(lenFreq,max_element(lenFreq, lenFreq+13)) << endl;

        system("pause");

//basic stats of the word file:
        fout << "Number of words: " << numberWords << endl;
        fout << "Number of letters: " << numberLetters << endl;
        fout << "Average length of words: " << numberLetters/numberWords << endl;
        fout << "Maximum word length: " << distance(lenFreq,max_element(lenFreq, lenFreq+13)) << endl;
 //Frequency distribution of word length:
        fout << endl;
        fout << "******************************" << endl;
        fout << endl;
        fout << "Frequency distribution of word length from 1 to " << distrLimit << ":" << endl;
            for (int k=1; k<distrLimit+1; k++){ //start at k=1, because there are no 0 letter words.
                fout << "Number of "<< k << " letter words: " << lenFreq[k] << endl;
            }
        fout << "Number of words of any other number of letters: " << remainder << endl;
            int sumW = 0;
            for (int w=0; w<distrLimit+1; w++){
                sumW += lenFreq[w];
            }
                if((sumW+remainder) == numberWords){
                    cout << endl;
                    cout << "YAY! Sum of frequency distribution for word length (and the remainder) \nis equal to the total number of words." << endl;
                    cout << endl;
                }else{
                    cout << endl;
                    cout << "OH NO! Sum of frequency distribution for word length (and the remainder) \n is NOT equal to the total number of words." << endl;
                    cout << endl;
                }
//Frequency distribution of each letter of the alphabet:
        fout << endl;
        fout << "******************************" << endl;
        fout << endl;
        fout << "Frequency distribution for each letter of the alphabet: " << endl;
            int sumL = 0;
            for (int l=0; l<26; l++){
                fout << "Frequency of letter '" << char(97+l) << "': " << letFreq[l] << endl;

                sumL += letFreq[l];
            }
//This is a checksum between all of the sum of the elements in letFreq and numberLetters.  They should be the same.
        if (sumL==numberLetters){
            cout << endl;
            cout << "Sum of frequency distribution is equal to the total number of letters." << endl;
            cout << endl;
        }else{
            cout << endl;
            cout << "Something is wrong.  The sum of the frequency distribution does NOT match the number of letters." << endl;
            cout << endl;
        }


        // Close input and output files
        fin.close();


    return 0;
}
