#include <iostream>
#include <cmath>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


const int MaxWorkers = 5000;


class Worker {

public:
	string WorkerNameStock[MaxWorkers];
	string WorkerUserNameStock[MaxWorkers];
	string WorkerTimeStock[MaxWorkers];

	void WorkerName(string Name, string UserName, int Number) {

		WorkerNameStock[Number] = Name;
		WorkerUserNameStock[Number] = UserName;
		//cout << "Worker Full Name is : " << WorkerNameStock[Number] << " " << WorkerUserNameStock[Number];
		ofstream outfile("names.txt");
		for (int a = 0; a < MaxWorkers; a++) {
			outfile << WorkerNameStock[a] << " " << WorkerUserNameStock[a] << endl;
		}
		outfile.close();

	}
	void JoinTime(int Number) {

		time_t zaman = time(nullptr);// Şuanki Zamanı Aldık;
		char zaman_str[26];//char karakter dizisi olarak sakladık;
		ctime_s(zaman_str, sizeof zaman_str, &zaman);//zaman dilimini zaman_str e yazdırdık;

		WorkerTimeStock[Number] = zaman_str;

		ofstream outfile("Time.txt");
		for (int a = 0; a < MaxWorkers; a++) {
			outfile << WorkerTimeStock[a];
		}
		outfile.close();
		//cout << "Worker Entering Time: " << WorkerTimeStock[Number] << endl;

	}

	void WorkerNameReadFile() {

		ifstream infile("names.txt");
		int count = 0;
		string line;
		while (getline(infile, line)) {
			string name, username;
			istringstream iss(line);
			iss >> name >> username;
			WorkerNameStock[count] = name;
			WorkerUserNameStock[count] = username;
			count++;
		}

		infile.close();

	}
	void WorkerTimeReadFile() {
		ifstream infile("Time.txt");
		int count = 0;
		string line;
		while (getline(infile, line)) {
			string time;
			WorkerTimeStock[count] = line;
			count++;
			
			/*string time;
			istringstream iss(line);
			iss >> time;
			WorkerTimeStock[count] = time;
			count++;*/

		}
	}


};







int main()
{
	
	Worker NameObject;
	int Number;
	int Choose;
	string Answer;
	string Name;
	string UserName;
	NameObject.WorkerNameReadFile();
	NameObject.WorkerTimeReadFile();

	CHOOSE:

	cout << "If U Want To See Worker Info Write: 1" << endl << "If U Want To Add Worker Write: 2 " << endl<<"If U Want To Close Program Write: 3 ";
	cin >> Choose;

	if (Choose == 3) {

	CLOSE:

		return 0;

	}

	else if (Choose == 1) {



	SEEWORKERINFO:

		cout << "Please Write Worker Number: ";
		cin >> Number;
		system("cls");
		cout << "Worker Name Is: " << NameObject.WorkerNameStock[Number - 1] << " " << NameObject.WorkerUserNameStock[Number - 1] << "\nWorker Join Date Is: " << NameObject.WorkerTimeStock[Number - 1] << endl;

			ANSWER:
			cout << "Do U Want To Go Choose Screen ? Yes/No: ";
			cin >> Answer;
			if (Answer == "YES" || Answer == "yes" || Answer == "Yes") {
				system("cls");
				goto CHOOSE;
			}
			else if (Answer == "NO" || Answer == "No" || Answer == "no") {
				system("cls");
				goto CLOSE;
			}
			else {
				system("cls");
				cout << "Please Write YES OR NO!!!" << endl;
				goto ANSWER;
			}
		
	
	}


	else if (Choose == 2) {

	ADDWORKER:

		cout << "Please Enter Worker Name: ";
		cin >> Name;
		system("cls");
		cout << "Please Enter Worker Username: ";
		cin >> UserName;
		system("cls");
		cout << "Please Enter Worker Number: ";
		cin >> Number;
		system("cls");

		NameObject.JoinTime(Number - 1);
		NameObject.WorkerName(Name, UserName, Number - 1);

		cout << "Do U Want To Continue ? Writing Yes/No: ";
		cin >> Answer;
		if (Answer == "Yes" || Answer == "YES" || Answer == "yes") {
			goto ADDWORKER;
		}
		else if (Answer == "No" || Answer == "NO" || Answer == "no") {
			system("cls");
			goto CHOOSE;
		}
	}
	

	else {
		cout << "Please Write Just 1 or 2 or 3: " << endl;
		goto CHOOSE;
	}


		
		



}
