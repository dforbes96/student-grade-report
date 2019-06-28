#ifndef COURSE_H
#define COURSE_H

enum Subject{HISTORY, ENGLISH, MATH};

//base class to be inherited from
class Course{

public:
	virtual double computeAvg()=0;		//calcuates final grade of course
	virtual double getFinal()=0;		//returns final exam grade
	virtual char letterGrade()=0;		//returns letter grade from course

	double getSubject();		//returns subject of Course
	const char* getNameF();		//returns first name of student
	const char* getNameL();		//returns last name of student
	


protected:
	char lastName[21];
	char firstName[21];
	Subject curriculum;
};

class History: public Course{

public:
	History(const char* nameF, const char* nameL, Subject c);
	double computeAvg();
	double getFinal();
	void Read(double paper, double mid, double exam);
	char letterGrade();

private:
	double termPaper, midterm, finalHis;

};

class English: public Course{

public:
	English(const char* nameF, const char* nameL, Subject c);
	double computeAvg();
	double getFinal();
	void Read(double att, double proj, double mid, double exam);
	char letterGrade();

private:
	double attendance, project, midterm, finalEng;

};

class Math: public Course{

public:
	Math(const char* nameF, const char* nameL, Subject c);
	double computeAvg();
	double getFinal();
	void Read(double quizzes[], double t1, double t2, double exam);
	char letterGrade();

private:
	double quiz[5];
	double test1, test2, finalMath;

};

#endif