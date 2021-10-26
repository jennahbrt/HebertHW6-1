/** A program that opens a text file, given as a command line arguement.
* it then copies the contents of the file line by line into a second file, 
* also given by a command line argument. 
**/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define FILE_PATH "/home/debian/hw6/HebertHW6-1"

int main(int argc, char *argv[]){
 if(argc!=3){
  cout << endl;
  cout << "This file requires the name of two files as inputs" << endl;
  cout << "the first file should be the source, the second the destination" << endl;
  cout << "also, both files need to be in the working directory" << endl;
  return 3;
 }

string pwd(getenv("PWD"));
cout << "The working directory is" << endl;
cout << pwd <<endl;

string src(argv[1]);
cout << "The file to be copied is " << src << endl;
cout << endl;

string fileNameSrc = "/" + src;
string pathNameSrc = pwd + fileNameSrc;

fstream fsSrc;
string line;
fsSrc.open((pathNameSrc).c_str(), std::fstream::in);


string des(argv[2]);
cout << "The file to be copied to is " << des << endl;
cout << endl;

string fileNameDest = "/" + des;
string pathNameDest = pwd + fileNameDest;

fstream fsDest;
fsDest.open((pathNameDest).c_str(), std::fstream::out);

while(getline(fsSrc,line)){
  fsDest << line << endl;
 }
fsDest.close();
fsSrc.close();

cout << "All done!" << endl;

}
