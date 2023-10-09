#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct SJF {//Struct to store
	int P;//process number
	int arrivalT;//arrival Time 
	int burstT;//Burst Time
	int waitT;//Waiting Time
};

int main() {
	int total = 0, Zcount=0,p,Twait=0,Ctime=0;//Ctime is current time Twait is total wait avgW is average wait time
	SJF temp;


	cout << "Hello" << endl << "Enter the number of Processes" << endl;
	cin >> p;//enters number of processes
	
	vector<SJF>process(p); //creates vector--> dont know why this works but the '(p)' needs to be there

	for (int i = 0; i < p; i++)//sets and pairs up processes to burst time
	{
		process[i].P=i+1;
		cout << "Enter Arrival time for P" << process[i].P << ": "; //creates individual process arrivals
		cin >> process[i].arrivalT;

		cout << "Enter Burst time for P" << process[i].P << ": ";//creates individual process burst times
		cin >> process[i].burstT;
		Twait += process[i].burstT;//counts total wait time
	}

	for (int i = 0; i < process.size(); i++)
	{
		for (int j = 0; j <process.size() ; j++)
		{
			if (process[i].burstT<process[j].burstT)// looks for the largest burst time then swaps processes
			{
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}


	float avgW=0;
	for (int i = 0; i < process.size(); i++)//itterates through vector to calculate wait times
	{
		Ctime += process[i].burstT;//calculates completion time
		process[i].waitT = Ctime - (process[i].arrivalT + process[i].burstT);//calculates wait time for each process
		if (process[i].waitT<0)//if math makes negative time make it 0 instead
		{
			process[i].waitT = 0;
		}
		avgW += process[i].waitT;//collects all average waits
		cout << "P" << process[i].P << "\t" << process[i].arrivalT << "\t" << process[i].burstT << "\t" << process[i].waitT << endl;
	}
	avgW = avgW / p;//calculates average wait time
	cout << "Total Wait= " << Twait << endl << "Average wait= " << avgW << endl;
}