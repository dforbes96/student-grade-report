#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include "course.h"
using namespace std;

double Course::getSubject(){ return curriculum; }

const char* Course::getNameL(){ return lastName; }

const char* Course::getNameF(){ return firstName; }

Math::Math(const char* nameF, const char* nameL, Subject s){

	strcpy(firstName, nameF);
	strcpy(lastName, nameL);
	curriculum = s;

}

English::English(const char* nameF, const char* nameL, Subject s){

	strcpy(firstName, nameF);
	strcpy(lastName, nameL);
	curriculum = s;

}

History::History(const char* nameF, const char* nameL, Subject s){

	strcpy(firstName, nameF);
	strcpy(lastName, nameL);
	curriculum = s;

}

void Math::Read(double q[], double t1, double t2, double exam){
	for(int i = 0; i < 5; i++)
		quiz[i] = q[i];
	test1 = t1;
	test2 = t2;
	finalMath = exam;

}

void English::Read(double att, double proj, double mid, double exam){
	attendance = att;
	project = proj;
	midterm = mid;
	finalEng = exam;
}

void History::Read(double paper, double mid, double exam){
	termPaper = paper;
	midterm = mid;
	finalHis = exam;

}

double Math::computeAvg(){
	double quizAvg = 0;
	for(int i = 0; i < 5; i++)
		quizAvg += quiz[i];
	quizAvg/=5;

	return (quizAvg*.15) + (test1*.25) + (test2*.25) + (finalMath*.35);
}

double English::computeAvg(){
	return (attendance*.10) + (project*.30) + (midterm*.30) + (finalEng*.30);
}

double History::computeAvg(){
	return (termPaper*.25) + (midterm*.35) + (finalHis*.40);
}

double Math::getFinal(){ return finalMath; }

double English::getFinal(){ return finalEng; }

double History::getFinal(){ return finalHis; }

char Math::letterGrade(){
	char mark;

	if(getFinal() >= 90)
		mark = 'A';
	else if(getFinal() >= 80)
		mark = 'B';
	else if(getFinal() >= 70)
		mark = 'C';
	else if(getFinal() >= 60)
		mark = 'D';
	else mark = 'F';

	return mark;
}

char English::letterGrade(){
	char mark;

	if(getFinal() >= 90)
		mark = 'A';
	else if(getFinal() >= 80)
		mark = 'B';
	else if(getFinal() >= 70)
		mark = 'C';
	else if(getFinal() >= 60)
		mark = 'D';
	else mark = 'F';

	return mark;
}

char History::letterGrade(){
	char mark;

	if(getFinal() >= 90)
		mark = 'A';
	else if(getFinal() >= 80)
		mark = 'B';
	else if(getFinal() >= 70)
		mark = 'C';
	else if(getFinal() >= 60)
		mark = 'D';
	else mark = 'F';

	return mark;
}