// Description : This program will read in four files, training data, training class, test data, and test class
// files and calculate a successful rate of correctly classifying the documents.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

// Global variable to hold the dictionary size
int dictionarySize = 48;

int main ()
{
  string file, file2, file3, file4;
  cout << "Enter the names of the training data, training class, test data and test class files (in that order): ";
  
  // Read in the name of the second file. This file will be used to determine whether the document is spam or ham.
  // Whether a test document is spam or ham will be used to calculate the probability of a spam or ham document
  // containing a particular word.
  cin >> file2;

  // Read in the name of the first file. This file will be used to determine whether a word is present in a document.
  // These words will be used to calculate the probability of them appearing in spam or ham documents that we are
  // testing.
  cin >> file;
  // Read in the name of the third file. This file will contain the words that are present in the documents that we
  // will be testing.
  cin >> file3;
  // Read in the name of the fourth file. This file will contain the actual classification of the documents that we
  // will be testing. This will be used to calculate our detection rate of spam documents.
  cin >> file4;

  // Open the second document
  ifstream input (file.c_str());
  if (input.fail())
    {
      cout << "First file not found\n";
      exit (1);
    }
  // Array to store the documents that will be used to calculate the probability of a word
  // appearing in a spam or ham document
  // Represented by 1 or 0
  string documentsArray;

  // The number of documents that will be used to calculate the probability of a word appearing
  // in a spam or ham document
  int documentsSize = 0;
  while(getline(input, documentsArray))
    documentsSize++;
  
  // Array to hold all of the classifications of the documents to be used for calculating probabilities of words
  // appearing in a spam or ham document
  int Documents [documentsSize];

  // Close and open the file to reset the getline pointer
  input.close();
  input.open(file.c_str());
  
  // Variables to hold the number of spam and ham documents
  float Spam, Ham = 0;
  
  // Read in numbers from the text file
  // If 1 then increment the spam document counter
  // If 0 then increment the ham document counter
  int i = 0;
  float DocumentsSize = 0.0;
  while (input >> Documents[i])
    {
      if (Documents[i] == 1)
	Spam++;
      if (Documents[i] == 0)
	Ham++;
      i++;
      DocumentsSize++;
    }
  input.close();
  
  // Open the second file
  ifstream input2 (file2.c_str());
  if (input2.fail())
    {
      cout << "Second file not found\n";
      exit (2);
    }
  
  // Variable to hold each word from all of the documents
  string AllWords;
  
  // Arrays to hold the number of times each word appears in a spam document or a ham document
  int SW[dictionarySize];
  int HW[dictionarySize];

  // Initialize each word count to 0
  for (int a = 0; a < dictionarySize; a++)
    SW[a] = 0;
  for (int a = 0; a < dictionarySize; a++)
    HW[a] = 0;

  // Loop to count the number of times a word appears in a spam document or a ham document
  i = 0;
  while(getline(input2, AllWords))
    {
      int b = 0;
      int c = 0;
	if (Documents[i] == 1)
	  while(b < dictionarySize)
	    {
	      if (AllWords[c] == '1')
		SW[b] = SW[b] + 1;
	      b++;
	      c = c + 2;
	    }
	if (Documents[i] == 0)
	  while(b < dictionarySize)
	    {
	      if (AllWords[c] == '1')
		HW[b] = HW[b] + 1;
	      b++;
	      c = c + 2;
	    }
	i++;
    }
  input2.close();

  // Arrays to hold the probabilities of particular words appearing in a spam document or a ham document
  float pWS [dictionarySize];
  float pWH [dictionarySize];

  // Initializing each probability to 0
  for (int a = 0; a < dictionarySize; a++)
    pWS[a] = SW[a] / Spam;
  for (int a = 0; a < dictionarySize; a++)
    pWH[a] = HW[a] / Ham;

  // Open the third file
  ifstream input3 (file3.c_str());
  if (input3.fail())
    {
      cout << "Third file not found\n";
      exit (3);
    }

  string temp;
  int evaluating = 0;
  while (getline(input3, temp))
    evaluating++;
    
  // Array to hold the classifications of the documents that we tested
  int classification[evaluating];

  input3.close();
  input3.open(file3.c_str());

  // Loop to calculate the probabilites of the documents being spam or ham
  i = 0;
  while (getline(input3, AllWords))
    {
      int d = 0;
      int e = 0;
      float pSB = Spam / DocumentsSize;
      while (d < dictionarySize)
	{
	  if (AllWords[e] == '1')
	    {
	      pSB *= pWS[d];
	    }
	  if (AllWords[e] == '0')
	    {
	      pSB *= 1 - pWS[d];
	    }
	  d++;
	  e = e + 2;
	}
      d = 0;
      e = 0;
      float pHB = Ham / DocumentsSize;
      while (d < dictionarySize)
	{
	  if (AllWords[e] == '1')
	    {
	      pHB *= pWH[d];
	    }
	  if (AllWords[e] == '0')
	    {
	      pHB *= 1 - pWH[d];
	    }
	  d++;
	  e = e + 2;
	}
      if (pSB > pHB)
	classification[i] = 1;
      if (pHB > pSB)
	classification[i] = 0;
      i++;
    }

  input3.close();
 
  // Open the fourth file
  ifstream input4 (file4.c_str());
  if (input4.fail())
    {
      cout << "Fourth File not found\n";
      exit (3);
    }

  // Array to hold the actual classification of the documents
  int classificationActual[evaluating];

  i = 0;
  while (getline(input4, temp))
    {
      if (temp == "1")
	{
	  classificationActual[i] = 1;
	}
      if (temp == "0")
	{
	  classificationActual[i] = 0;
	}
      i++;
    }

  // Count the number of times our program correctly detects a spam document
  // and count the correct number of spam documents 
  float success = 0.0;
  int spam = 0;
  for (int i = 0; i < evaluating; i++)
    {
      if (classificationActual[i] == classification[i])
	success++;
    }
  
  // Calculate the detection rate of the program
  float detectRate = (success / evaluating) * 100;

  cout << "Training using " << DocumentsSize << " cases" << endl;
  cout << "Evaluating " << evaluating << " test cases" << endl;
  cout << "Successful detection rate of " << detectRate << '%' << endl;

  input4.close();
  return 0;
}
