#pragma once
class Student
{
	private:
		char nume[100];
		struct Nota
		{
			float math, eng, hist;
		}nota;
	public:
		void initName(char s[100]);
		void initMath(float val);
		void initEng(float val);
		void initHist(float val);
		float average();
		char* getName();
		float getMath();
		float getEng();
		float getHist();
};