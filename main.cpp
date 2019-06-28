#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "course.h"
using namespace std;


int main(){

	int size;
	Course **roster;			//create dynamic Course object
	ifstream inFile;			//object for file extraction
	ofstream outFile;			//object for file insertion
	string fileName, subject;	//strings for name of file and course subject, respectively
	char lastName[21];			//cstring to store last name of student from course
	char firstName[21];			//cstring to store first name of student from course

	//prompt user to enter name of file to read from
	cout << "Please enter the name of the input file." << endl;
	cout << "Filename: ";
	cin >> fileName;

	//prints error message if file is not found and aborts program
	if(!inFile){
		cerr << "Error: file not found." << endl;
	}
	
	inFile.open(fileName);			//opens specified file to begin reading
	inFile >> size;					//reads in size
	inFile.ignore();				//ignores newline character so it's not read in by cstring

	roster = new Course *[size];	//dynamically allocates space in coure roster based on file size
	for(int i = 0; i < size; i++){

		inFile.getline(lastName, 21, ',');		//reads in last name from file
		inFile.ignore();						//ignores whitespace so it's not read in by firstName
		inFile.getline(firstName, 21, '\n');	//reads in first name from file
		inFile >> subject;						//reads in course subject from file

		//series of if-else statements to create derived objects based on the subject
		if(subject=="Math"){
			Math *m = new Math(firstName, lastName, MATH);		// derived class is initialized
			double q[5], test1, test2, exam;					//set of variables created to read in appropriate data from file
			for(int i = 0; i < 5; i++)							//data is read into variables
				inFile >> q[i];
			inFile >> test1 >> test2 >> exam;
			m->Read(q, test1, test2, exam);						//public Read() function called to store data into object
			roster[i] = m;										//attach object to array
		}														//rinse and repeat...
		else if(subject=="English"){
			English *e = new English(firstName, lastName, ENGLISH);
			double att, proj, mid, exam;
			inFile >> att >> proj >> mid >> exam;
			e->Read(att, proj, mid, exam);
			roster[i] = e;
		}
		else if(subject=="History"){
			History *h = new History(firstName, lastName, HISTORY);
			double paper, mid, exam;
			inFile >> paper >> mid >> exam;
			h->Read(paper, mid, exam);
			roster[i] = h;
		}
		inFile.ignore();	//ignores newline character so it wont be read into name when loop repeats
	}
	inFile.close();			//CLOSE FILE
	
	cout << "Please enter name of the outputfile." << endl;
	cout << "Filename: ";
	cin >> fileName;

	outFile.open(fileName);	//OPEN FILE TO WRITE GRADE REPORT TO

	//Produce grade report for respective class
	outFile << "Student Grade Summary" << endl;
	outFile << "---------------------" << endl;

	outFile << "\nENGLISH CLASS\n\n";

	outFile << "Student\t\t\t\t\tFinal\tFinal\tLetter" << endl;
	outFile << "Name\t\t\t\t\tExam\tAvg\tGrade" << endl;
	outFile << "----------------------------------------------------------------" << endl;

	for(int i = 0; i < size; i++){
		if(roster[i]->getSubject()==ENGLISH){
			outFile << roster[i]->getNameF() << " " << roster[i]->getNameL();
			for(int j = strlen(roster[i]->getNameF())+strlen(roster[i]->getNameL()); j < 39; j++)
				outFile.put(' ');
			outFile<< roster[i]->getFinal() << "\t" << roster[i]->computeAvg() << "\t" << roster[i]->letterGrade() << endl;
		}
	}

	outFile << "\nHISTORY CLASS\n\n";

	outFile << "Student\t\t\t\t\tFinal\tFinal\tLetter" << endl;
	outFile << "Name\t\t\t\t\tExam\tAvg\tGrade" << endl;
	outFile << "----------------------------------------------------------------" << endl;
	
	for(int i = 0; i < size; i++){
		if(roster[i]->getSubject()==HISTORY){
			outFile << roster[i]->getNameF() << " " << roster[i]->getNameL();
			for(int j = strlen(roster[i]->getNameF())+strlen(roster[i]->getNameL()); j < 39; j++)
				outFile.put(' ');
			outFile<< roster[i]->getFinal() << "\t" << roster[i]->computeAvg() << "\t" << roster[i]->letterGrade() << endl;
		}
	}
	
	outFile << "\nMATH CLASS\n\n";

	outFile << "Student\t\t\t\t\tFinal\tFinal\tLetter" << endl;
	outFile << "Name\t\t\t\t\tExam\tAvg\tGrade" << endl;
	outFile << "----------------------------------------------------------------" << endl;
	
	for(int i = 0; i < size; i++){
		if(roster[i]->getSubject()==MATH){
			outFile << roster[i]->getNameF() << " " << roster[i]->getNameL();
			for(int j = strlen(roster[i]->getNameF())+strlen(roster[i]->getNameL()); j < 39; j++)
				outFile.put(' ');
			outFile<< roster[i]->getFinal() << "\t" << roster[i]->computeAvg() << "\t" << roster[i]->letterGrade() << endl;
		}
	}

	outFile.close();		//CLOSE GRADE REPORT FILE

	cout << "Processing Complete" << endl;
	
	//dynamically deallocate memory
	for(int i = 0; i < size; i++)
		delete [] roster[i];
	delete [] roster;

	return 0;
}


