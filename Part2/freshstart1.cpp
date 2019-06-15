// Author : Bryce Randolph and Tim Gallagher
// Assignment : Project 2
// Filename : freshstart.cpp//%%%%%%%%%change this later&&&&&&&&%%%%%%
// Date : Fall 2017
// Description : 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <sstream>

using namespace std;

// Global variable to hold the dictionary size(probably not needed)
int dictionarySize = 354; 

vector<string> split(const string& s, char delimiter);//function prototypes
//int checkWord(string word, const vector<string>& sonnet);
int checkWord(string word, const string & sonnet);
//void populateFeature(const vector<string>& sonnet, const vector<string>& dictionary, vector<int>& currentFeature);
void populateFeature(const string & sonnet, const vector<string>& dictionary, vector<int>& currentFeature);

int main() {

  string file1, file2, file3, file4;//eTrain,sTrain,sTest,eTest

  vector<string> dictionary;//holding dictionary

  vector<string> doc1;//holding each file
  vector<string> doc2;
  vector<string> doc3;
  vector<string> doc4;

  string storage1;
  string storage2;
  string storage3;
  string storage4;


    vector<string> words1;//holds all single words in a file
    vector<string> words2;
   vector<string> words3;
   vector<string> words4;


  float total1 = 0.0;//total sonnets in files
  float total2 = 0.0;
  float total3 = 0.0;
  float total4 = 0.0;


  ifstream dict("/Users/student/Desktop/Part2/dictionary.txt");
  if (dict.fail()) {
    cout << "Dictionary file not found\n";
    exit(1);
  }
  string dictWords;

  while (getline(dict, dictWords))
    dictionary.push_back(dictWords);


  int numWords = dictWords.size();
  cout << "Total number of words in dictionary: " << dictionary.size() << endl;


    vector<vector<int> > feature1(numWords);
    vector<vector<int> > feature2(numWords);
    vector<vector<int> > feature3(numWords);
    vector<vector<int> > feature4(numWords);




  //  cout<<"Enter the names of the Shakespearean training file, Elizabethan training file, Shakespearean test file and Elizabethan test file (in that order):";

  // cin>>file1;
  // cin>>file2;
  // cin>>file3;
  // cin>>file4;


  ifstream input1("/Users/student/Desktop/Part2/ShakespeareData_train_50.txt");//doc1
  if (input1.fail()) {
    cout << "First file not found\n";
    exit(1);
  }
  while (getline(input1, storage1)) {
    doc1.push_back(storage1);
    total1++;
  };
    ifstream input2("/Users/student/Desktop/Part2/ElizabethanData_train_50.txt");//doc1
    if (input2.fail()) {
        cout << "Second file not found\n";
        exit(1);
    }
    while (getline(input2, storage2)) {
        doc2.push_back(storage2);
        total2++;
    }
    ifstream input3("/Users/student/Desktop/Part2/ShakespeareData_test_50.txt");//doc1
    if (input3.fail()) {
        cout << "Third file not found\n";
        exit(1);
    }
    while (getline(input3, storage3)) {
        doc3.push_back(storage3);
        total3++;
    }
    ifstream input4("/Users/student/Desktop/Part2/ElizabethanData_test_50.txt");//doc1
    if (input4.fail()) {
        cout << "Fourth file not found\n";
        exit(1);
    }
    while (getline(input4, storage4)) {
        doc4.push_back(storage4);
        total4++;
    }



  int testCount0 = 0;
  int testCount1 = 0;
  int populate = 0;
  bool debug = true;
    vector<int> temp1(dictionary.size());
    vector<int> temp2(dictionary.size());
    vector<int> temp3(dictionary.size());
    vector<int> temp4(dictionary.size());




  for (int i = 0; i < doc1.size(); i++) { // Looping through the document until end of document

      words1 = split(doc1[i], ' ');
      temp1.clear();

      for (int j = 0; j < dictionary.size(); j++) {




          // Looping thru words of each sonnet, creating words[i] which holds a word of a sonnet
          //cout << "j = " << j << ' ' << words1[j] << '\n';
          int ones = 0;
          int zeroes = 0;




          for (int k = 0; k < words1.size(); k++) { // Looping thru dictionary and trying to find word matches
              if (dictionary[j]== words1[k]){
                  ones++;
              }else{
                  zeroes++;
              }
          }



          if (ones == 1)
              temp1.push_back(1);
          else
              temp1.push_back(0);
          int k = 0;
      }
      int f = 0;
      feature1.push_back(temp1);
      //words1.clear();
  };

    for (int i = 0; i < doc2.size(); i++) { // Looping through the document until end of document

        words2 = split(doc2[i], ' ');
        temp2.clear();

        for (int j = 0; j < dictionary.size(); j++) {




            // Looping thru words of each sonnet, creating words[i] which holds a word of a sonnet
            //cout << "j = " << j << ' ' << words1[j] << '\n';
            int ones = 0;
            int zeroes = 0;




            for (int k = 0; k < words2.size(); k++) { // Looping thru dictionary and trying to find word matches
                if (dictionary[j]== words2[k]){
                    ones++;
                }else{
                    zeroes++;
                }
            }



            if (ones == 1)
                temp2.push_back(1);
            else
                temp2.push_back(0);
        }
        feature2.push_back(temp2);
        //words2.clear();
    };

    for (int i = 0; i < doc3.size(); i++) { // Looping through the document until end of document

        words3 = split(doc3[i], ' ');
        temp3.clear();

        for (int j = 0; j < dictionary.size(); j++) {




            // Looping thru words of each sonnet, creating words[i] which holds a word of a sonnet
            //cout << "j = " << j << ' ' << words1[j] << '\n';
            int ones = 0;
            int zeroes = 0;




            for (int k = 0; k < words3.size(); k++) { // Looping thru dictionary and trying to find word matches
                if (dictionary[j]== words3[k]){
                    ones++;
                }else{
                    zeroes++;
                }
            }



            if (ones == 1)
                temp3.push_back(1);
            else
                temp3.push_back(0);
            int k = 0;
        }
        int f = 0;
        feature3.push_back(temp3);
        //words3.clear();
    };

    for (int i = 0; i < doc4.size(); i++) { // Looping through the document until end of document

        words1 = split(doc4[i], ' ');
        temp4.clear();

        for (int j = 0; j < dictionary.size(); j++) {




            // Looping thru words of each sonnet, creating words[i] which holds a word of a sonnet
            //cout << "j = " << j << ' ' << words1[j] << '\n';
            int ones = 0;
            int zeroes = 0;




            for (int k = 0; k < words4.size(); k++) { // Looping thru dictionary and trying to find word matches
                if (dictionary[j]== words4[k]){
                    ones++;
                }else{
                    zeroes++;
                }
            }



            if (ones == 1)
                temp4.push_back(1);
            else
                temp4.push_back(0);
            int k = 0;
        }
        int f = 0;
        feature4.push_back(temp4);
        //words4.clear();
    };


    temp1.clear();
    temp2.clear();
    temp3.clear();
    temp4.clear();
    int a = 0;


    vector<float> colTotal1;
    vector<float> colTotal2;
    vector<float> colTotal3;
    vector<float> colTotal4;

    float pushit1;
    float pushit2;
    float pushit3;
    float pushit4;
    vector<float> fractions1;
    vector<float> fractions2;
    vector<float> fractions3;
    vector<float> fractions4;



    for(int m=0; m < dictionary.size(); m++) {
        pushit1 = 0.0;
        for (int n = 0; n < doc1.size(); n++) {
            if (feature1[n][m] == 1)
                pushit1++;
        }
        colTotal1.push_back(pushit1);
    }
    float frac;
    int testcount1=0;
    for(int d=0;d<colTotal1.size();d++)
    {
        frac = (colTotal1[d] + 1)/(doc1.size()+2);
        fractions1.push_back(frac);
        testcount1++;

        cout<<fractions1[d]<<endl;
    }
    cout<<testcount1<<endl;
//-------------------------------------------------------------------
    for(int m=0; m < dictionary.size(); m++) {
        pushit2 = 0.0;
        for (int n = 0; n < doc2.size(); n++) {
            if (feature2[n][m] == 1)
                pushit2++;
        }
        colTotal2.push_back(pushit2);
    }
    frac == 0.0;
    testcount1=0;
    for(int d=0;d<colTotal2.size();d++)
    {
        frac = (colTotal2[d] + 1)/(doc2.size()+2);
        fractions2.push_back(frac);
        testcount1++;

        cout<<fractions2[d]<<endl;
    }
    cout<<testcount1<<endl;





//    for(int m=0; m<words1.size();m++) {
//        pushit1 = 0.0;
//        for (int n = 0; n < dictionary.size(); n++) {
//            if (feature1[m][n] == 1)
//                pushit1++;
//
//        }
//        colTotal1.push_back(pushit1);
//    }
//    float frac;
//    int testcount1=0;
//    for(int d=0;d<colTotal1.size();d++)
//    {
////frac =  colTotal[i]/doc1.size();
//        frac = (colTotal1[d] + 1)/(float)(doc1.size()+2);
//        fractions1.push_back(frac);
//        testcount1++;
//
//        cout<<fractions1[d]<<endl;
//    }
//    cout<<testcount1<<endl;
//
//
//    //-----------------------------------------------------
//    for(int m=0; m< doc2.size();m++) {
//        pushit2 = 0.0;
//        for (int n = 0; n < dictionary.size(); n++) {
//            if (feature2[n][m] == 1)
//                pushit2++;
//
//        }
//        colTotal2.push_back(pushit2);
//    }
//    float frac1 = 0.0;
//    int testcount2 = 0;
//    for(int d=0;d<colTotal2.size();d++)
//    {
////frac =  colTotal[i]/doc1.size();
//        frac1 = (colTotal2[d] + 1)/(float)(doc2.size()+2);
//        fractions2.push_back(frac1);
//        testcount2++;
//
//        cout<<fractions2[d]<<endl;
//    }
//    cout<<testcount2<<endl;

    //vector <int> testData;

    int guessShake = 0;
    int guessEliza= 0;
    float probShake = 0.0;
    float probEliza =0.0;

    float shakeTotal = (float)doc1.size() / (float)(doc1.size() + (float)doc2.size());
    float elizaTotal = (float)doc2.size() / (float)(doc1.size() + (float)doc2.size());

    for (int i = 0; i<feature3.size(); i++)
    {

        for (int j = 0; j < dictionary.size(); j++)
        {
            if (feature3[i][j] == 1)
            {
                probShake+=log(fractions1[j]);
                probEliza+=log(fractions2[j]);


            } else
            {
                //1- (prob of word to total)
                probShake+=log(1-fractions1[j]);
                probEliza+=log(1-fractions2[j]);

            }

        }
        probShake+=log(shakeTotal);
        probEliza+=log(elizaTotal);

        if(probShake>probEliza)
            guessShake++;

        probShake = 0.0;
        probEliza =0.0;


    }
   // probShake+=log((float)doc1.size() / (doc1.size() + doc2.size()));
    //probEliza+=log((float)doc2.size() / (doc1.size() + doc2.size()));
   /* probShake+= shakeTotal;
    probEliza+= elizaTotal;
    cout << probShake << endl;
    cout << probEliza << endl;
    if(probShake>probEliza)
        guessShake++;

    else
        guessEliza++;

    */
    int u = 0;

}





//int checkWord(string word, const vector<string>& sonnet)
  int checkWord(string word, const string & sonnet)
{
  //Linear search to check if word exists in the array sonnet
  for (int i=0; i<sonnet.size(); ++i)
    {
      //if (!sonnet[i].compare(word))
      if (!sonnet.compare(word))
      return 1;
    }
  
  return 0;
  
}

//void populateFeature(const vector<string>& sonnet, const vector<string>& dictionary, vector<int>& currentFeature)
void populateFeature(const string& sonnet, const vector<string>& dictionary, vector<int>& currentFeature)
{
  
  //Go through each word in dictinary and check if it exists in sonnet
  for (int i=0; i<dictionary.size(); ++i)
    {
      currentFeature[i] = checkWord(dictionary[i], sonnet);
    }
  
}


vector<string> split(const string& s, char delimiter)
{
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (tokenStream >> token)
    tokens.push_back(token);
  return tokens;
}
