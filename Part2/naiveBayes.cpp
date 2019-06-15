//
// Created by Bryce Randolph on 11/16/2017.
//

// Project: Project 2,
// Name: Bryce Randolph & Timothy Gallagher 
// Class: CS 242
// Date: 11/29/17

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
  //something like this is probably what we need 
  ofstream f;
  string filename;

  cout << "Please enter a file name to write: ";
  getline( cin, filename );

  f.open( filename.c_str() );
  f.close();


  //I think this stuff might not be useful. We probably need cin file input, not command line arguments
  // input using arguments for filenmaes of training data and test data
  if ( argc != 2 ) // argc should be 2 for correct execution with one input
    // We print argv[0] assuming it is the program name
    cout<<"usage: "<< argv[0] <<" <filename>\n";
  else {
    // We assume argv[1] is the first filename to open
    ifstream the_file ( argv[1] );
    // check to see if file opening succeeded
    if ( !the_file.is_open() )
      cout<<"Could not open file\n";
    else {
      char x;
      // the_file.get ( x ) returns false if the end of the file is reached or an error occurs
      while ( the_file.get ( x ) )
	cout<< x;
    }
    // the_file is closed implicitly here
  }
  

  //need to input dictionary.txt without using argument 


  //inputting article type(
  /*
  ifstream inputClass("toy.class.txt");
  float Sports = 0.0;
  float Informatics = 0.0;
  float TotalDocuments = 0.0;
  vector <int> Documents;
  int in1;
  
  while (inputClass >> in1)//gets total document number
    {
      Documents.push_back(in1);
      TotalDocuments++;
    }
  for(int j=0;j<Documents.size();j++)//decides if Sports or Info
    {
      if (Documents[j] == 1)
	Sports ++;
      if (Documents[j] == 0)
	Informatics ++;
    }
  
  inputClass.close();//close input
  */
  //cout checking 
  //cout << TotalDocuments <<endl;
  // cout << Sports<<endl;
  // cout << Informatics<<endl;
  //inputting bitstring bank
  ifstream inputBank("toy.data.txt");
  // int in2;
  // vector<string> Bank;
  // vector<string> BankI;
  string AllWords;
  float Sw1=0.0;//initializing all the variables to store word count
  float Sw2=0.0;
  float Sw3=0.0;
  float Sw4=0.0;
  float Sw5=0.0;
  float Sw6=0.0;
  float Sw7=0.0;
  float Sw8=0.0;
  
  float Iw1=0.0;
  float Iw2=0.0;
  float Iw3=0.0;
  float Iw4=0.0;
  float Iw5=0.0;
  float Iw6=0.0;
  float Iw7=0.0;
  float Iw8=0.0;
  int i=0;
  while(getline(inputBank, AllWords))//counting the number of each word occurrence
    {
      
      if(Documents[i] == 1)
	{
	  if (AllWords[0] =='1')
	    Sw1++;
	  if (AllWords[2] =='1')
	    Sw2++;
	  if (AllWords[4] =='1')
	    Sw3++;
	  if (AllWords[6] =='1')
	    Sw4++;
	  if (AllWords[8] =='1')
	    Sw5++;
	  if (AllWords[10] =='1')
	    Sw6++;
	  if (AllWords[12] =='1')
	    Sw7++;
	  if (AllWords[14] =='1')
	    Sw8++;
	}
      if (Documents[i] == 0)
	{
	  if (AllWords[0] =='1')
	    Iw1++;
	  if (AllWords[2] =='1')
	    Iw2++;
	  if (AllWords[4] =='1')
	    Iw3++;
	  if (AllWords[6] =='1')
	    Iw4++;
	  if (AllWords[8] =='1')
	    Iw5++;
	  if (AllWords[10] =='1')
	    Iw6++;
	  if (AllWords[12] =='1')
	    Iw7++;
	  if (AllWords[14] =='1')
	    Iw8++;
	}
      i++;
    }
  inputBank.close();
  /*cout<<"Sw"<<endl;
  cout<<Sw1<<" "<<Sw2<<" "<<Sw3<<" "<<Sw4<<" "<<Sw5<<" "<<Sw6<<" "<<Sw7<<" "<<Sw8<<endl;
  cout<<"Iw"<<endl;
  cout<<Iw1<<" "<<Iw2<<" "<<Iw3<<" "<<Iw4<<" "<<Iw5<<" "<<Iw6<<" "<<Iw7<<" "<<Iw8<<endl;
  */
  //code for the two bitstrings we will be testing
  ifstream inputTest("toytest.data.txt");
  vector <string> TestWords;
  string test;
  float s1=0.0;
  float s2=0.0;//For sports
  float s3=0.0;
  float s4=0.0;
  float s5=0.0;
  float s6=0.0;
  float s7=0.0;
  float s8=0.0;
  
  float i1=0.0;
  float i2=0.0;
  float i3=0.0;
  float i4=0.0;//for informatics
  float i5=0.0;
  float i6=0.0;
  float i7=0.0;
  float i8=0.0;
  
  i=0;
  float sportsprop=0.0;
  float informaticsprop=0.0;

   while(getline(inputTest, test))//calculate components of sports probability
    {
        TestWords.push_back(test);;
	 // cout << test << "\n";
    
      
	if (test[0] =='0')
	  s1=1-(Sw1/Sports);
	if (test[0] =='1')
	  s1=Sw1/Sports;
	if (test[2] =='0')
	  s2=1-(Sw2/Sports);
	if (test[2] =='1')
	  s2=(Sw2/Sports);
	if (test[4] =='0')
	  s3=1-(Sw3/Sports);
	if (test[4] =='1')
	  s3=(Sw3/Sports);
	if (test[6] =='0')
	  s4=1-(Sw4/Sports);
	if (test[6] =='1')
	  s4=(Sw4/Sports);
	if (test[8] =='0')
	  s5=1-(Sw5/Sports);
	if (test[8] =='1')
	  s5=(Sw5/Sports);
	if (test[10] =='0')
	  s6=1-(Sw6/Sports);
	if (test[10] =='1')
	  s6=(Sw6/Sports);
	if (test[12] =='0')
	  s7=1-(Sw7/Sports);
	if (test[12] =='1')
	  s7=(Sw7/Sports);
	if (test[14] =='0')
	  s8=1-(Sw8/Sports);
	if (test[14] =='1')
	  s8=(Sw8/Sports);

	if (test[0] =='0')
	  i1=1-(Iw1/Informatics);
	if (test[0] =='1')
	  i1=(Iw1/Informatics);
	if (test[2] =='0')
	  i2=1-(Iw2/Informatics);
	if (test[2] =='1')
	  i2=(Iw2/Informatics);
	if (test[4] =='0')
	  i3=1-(Iw3/Informatics);
	if (test[4] =='1')
	  i3=(Iw3/Informatics);
	if (test[6] =='0')
	  i4=1-(Iw4/Informatics);
	if (test[6] =='1')
	  i4=(Iw4/Informatics);
	if (test[8] =='0')
	  i5=1-(Iw5/Informatics);
	if (test[8] =='1')
	  i5=(Iw5/Informatics);
	if (test[10] =='0')
	  i6=1-(Iw6/Informatics);
	if (test[10] =='1')
	  i6=(Iw6/Informatics);
	if (test[12] =='0')
	  i7=1-(Iw7/Informatics);
	if (test[12] =='1')
	  i7=(Iw7/Informatics);
	if (test[14] =='0')
	  i8=1-(Iw8/Informatics);
	if (test[14] =='1')
	  i8=(Iw8/Informatics);
        test="";

	sportsprop = (Sports/TotalDocuments)*s1*s2*s3*s4*s5*s6*s7*s8;
	informaticsprop = (Informatics/TotalDocuments)*i1*i2*i3*i4*i5*i6*i7*i8;
	cout<<"Test case "<<(i+1) <<endl;
	cout<<"\tp(S|b) = "<< sportsprop <<endl;
	cout<<"\tp(I|b) = "<< informaticsprop <<endl; 
	i++;
    }
   // cout<<TestWords[0]<<endl;
   // cout<<TestWords[1]<<endl;
   /*	sportsprop = (Sports/TotalDocuments)*s1*s2*s3*s4*s5*s6*s7*s8;
	informaticsprop = (Informatics/TotalDocuments)*i1*i2*i3*i4*i5*i6*i7*i8;
	cout<<"Test case 1"<<endl;
	cout<<"\tp(S|b) = "<< sportsprop <<endl;
	cout<<"\tp(I|b) = "<< informaticsprop <<endl; 
  
		
  
   */
  
	inputTest.close();


	//cout<<"s(1-8)"<<endl;
	// cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<" "<<s7<<" "<<s8<<endl;
	//cout<<"i(1-8)"<<endl;
	//cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6<<" "<<i7<<" "<<i8<<endl;
	
  
  return 0;
  
}

