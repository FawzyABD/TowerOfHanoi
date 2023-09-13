#include "Stackt.cpp"
#include <string>
#include <cmath>


void displayAll(ArrStack<int> &S, ArrStack<int> &T, ArrStack<int> &A)
{

	S.display();
	T.display();
	A.display();
	if (T.Top != T.size - 1) 
	{
		cout << '\n' << "NEXT MOVE: " << endl;

	}
}


void Towers(int N, ArrStack<int> &Source, ArrStack<int> &Target, ArrStack<int> &Aux)
{
	if (N == 1) 
	{
		//Move the only disk to target
		Target.push(Source.pop());
		displayAll(Source, Target, Aux);
		

	}
	else if (N>0)
	{

		Towers(N - 1, Source, Aux, Target);
		Towers(1, Source, Target, Aux);
		Towers(N - 1, Aux, Target, Source);

	}

	//it works
	//Target and Aux switch places draw it to see it

};
//use pass by reference it should be the correct choice


long double TowersTime(int N, ArrStack<int>& Source, ArrStack<int>& Target, ArrStack<int>& Aux, long double &counter)
{
	if (N == 1)
	{
		//Move the only disk to target
		Target.push(Source.pop());
		//displayAll(Source, Target, Aux);
		counter++;


	}
	else if (N > 0)
	{

		TowersTime(N - 1, Source, Aux, Target, counter);
		TowersTime(1, Source, Target, Aux, counter);
		TowersTime(N - 1, Aux, Target, Source, counter);

	}

	//it works
	//Target and Aux switch places draw it to see it

	return counter;
}

long long endOfUniverse(const int disks) 
{
	double time = 1;
	unsigned long long temp = 0;
	double hours = 0;
	double mins = 0;
	double secs = 0;
	
	for (int i = 0; i < disks; i++) 
	{
		time *=2 ;


	}
	hours = (time-1)/3600;
	temp = fmod((time - 1), 3600);
	mins = temp / 60;
	secs = temp % 60;

	cout << "The universe will end in: " << hours << " Hours " <<mins<<" Mins " <<secs<<" Seconds" << endl;

	return time;


}


void addToStack(ArrStack<int> *x, int y) 
{
	x->push(y);


}


void runTOH(int N, ArrStack<int>&S, ArrStack<int>&T, ArrStack<int>&A) 
{
	
	for (int i = 0; i < S.size; i++)
	{
		addToStack(&S, (S.size - i));
	}
	int x = pow(2, N) - 1;

	cout << "Number of moves needed: " << x<< endl;
	displayAll(S, T, A);
	Towers(S.size, S, T, A);



}


int main()
{

	char key;
	const int disks = 64;

	cout << "Chose which program you would like to run: " << endl;
	cout << "1: Towers of Hanoi." << '\n' << "2: End of the Universe." << endl;
	cin >> key;


	if (key == '1')
	{
		ArrStack<int> S('S');
		ArrStack<int> T(S.size, 'T');
		ArrStack<int> A(S.size, 'A');

		runTOH(S.size, S, T, A);
	}
	else if (key == '2') {
		endOfUniverse(disks);

	}
	else { cout << "Not Valid."; }




	
	


	system("pause");
	return 0;

		
}

