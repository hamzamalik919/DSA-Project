#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <sstream>
#include<algorithm>
using namespace std;

struct Course
{
	string course="";
	string name = "";
	vector<string> prerequisite;
};
void loadCourses(vector<Course>* courses) {
	string path;
	cout << "Enter file name: ";
	getline(cin>>ws, path);
	cout << "Loading text file " << path << endl;


	ifstream file(path);
	if (file.is_open())
	{
		string data;
		
		while (getline(file, data))
		{
			string str;
			stringstream ss(data);
			Course temp;
			int count = 0;
			while (getline(ss, str, ','))
			{
				if (count == 0)
				{
					temp.course = str;
				}
				else if (count == 1)
				{
					temp.name = str;
				}
				else
				{
					temp.prerequisite.push_back(str);
				}
				count++;
			}
			courses->push_back(temp);
				
		}
	}
	else
	{
		cout << "Can't open file.";
		exit(0);
	}
}

void printCourselist(vector<Course>* courses)
{
	cout << "Here is a sample schedule." << endl;
	for (int i = 0; i < courses->size(); i++)
	{
		cout << courses->at(i).course << ", " << courses->at(i).name << endl;
	}
}

void printCourse(vector<Course>* courses)
{
	
	string id;
	cout << "What course do you want to know about? ";
	getline(cin >> ws, id);
	for (int i = 0; i < courses->size(); i++)
	{
		if (courses->at(i).course == id)
		{
			cout << courses->at(i).course << ", "<< courses->at(i).name << endl;
			cout << "Prerequisite: " ;
			for (int j = 0; j < courses->at(i).prerequisite.size(); j++)
			{
				cout << courses->at(i).prerequisite.at(j) << ",";
			}
			cout << endl;
			return;
		}
		
	}

	cout << "Course not found."<<endl;
}

int main(int argc, char* argv[]) {

	vector<Course> courseList;
	int choice = 0;
	cout << "Welcome to the course planner." << endl;
	while (choice != 4) {
		cout << "Menu:" << endl;
		cout << "  1. Load Data Structure." << endl;
		cout << "  2. Print Course List." << endl;
		cout << "  3. Print Course." << endl;
		cout << "  4. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			loadCourses(&courseList);
			cout << courseList.size() << " courses read" << endl;
			break;

		case 2:
			printCourselist(&courseList);
			break;

		case 3:
			printCourse(&courseList);
			break;
		default:
			cout << choice << " is not a valid option." << endl;
			break;
		}
	}

	cout << "Thank you for using the course planner!" << endl;
	system("pause");
	return 0;
}