#include <iostream>
#include<vector>
#include <iomanip>
#include "MyRead.h"
#include<string>
#include<cctype>
#include<fstream>

using namespace std;

void LodDataFromFileToVector(string FileName,vector<string>& VFileContent)
{
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::in);//Read Mod 

		if (MyFile.is_open())
		{
			string Line;
			while(getline(MyFile,Line))

			{
				VFileContent.push_back(Line);
			}
				
		}
		MyFile.close();
}

void SaveVectorToFile(string FileName, vector<string> VFileContent)
{
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::out);//Write Mod 

	if (MyFile.is_open())
	{
		for (string& Line : VFileContent)
		{
			if (Line != "")
			{
				MyFile << Line<<endl;
			}
		}
	}
	MyFile.close();
}


void DeleteRecordFromFile(string FileName, string Record, string UpdateTo)
{
	vector <string>VFileContent;
	LodDataFromFileToVector(FileName, VFileContent);

	
		for (string &Line : VFileContent)
		{
			if (Line==Record)
			{
				Line=UpdateTo;
			}
		}
		SaveVectorToFile(FileName,VFileContent);
}

void PrintFileContent(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName,ios::in );//Read Mode 

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile,Line))
		{
			cout << Line<<endl;
		}
		MyFile.close();
	}
}

int main()
{
	cout << "File content Befor Deleting it  " << endl;
	 PrintFileContent("MyFile.txt");
	
	DeleteRecordFromFile("MyFile.txt", "Ail","osman");

	cout << "content After Deleting it " << endl;
	PrintFileContent("MyFile.txt");

	
}
	

