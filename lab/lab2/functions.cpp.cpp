#include "functions.h"
#include <iostream>
using namespace std;
void q1() {
	int y = 1, sum = 0, n;
	cout << "enter a number ";
	cin >> n;
	while (y <= n)
	{
		sum += y;
			y++;
	}
	cout << sum << endl;


	
}
	void q2(){
		int x, y,sum=0;
		int remainder = 0;
		cout << "enter a number to check prime or not" << endl;
		cin >> x;
		for (y = 1; y <= x; y++) {
	
			if (x % y == 0) {
				remainder++;
			}
		}
		if (remainder == 2) {
			cout << "the number is prime" << endl;
		
		}
		else {
			cout << "the number is not prime" << endl;
		}
		cout << x << endl;
		}
	
	void q3() {
		int x = 4;
		for (int i = 1; i <= x; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << j << " ";
			}
			cout << endl;
		}

}

	void q4() {
		int x,y;
		cout << "enter number to have factors ";
		cin >> x;
		for (int i = 1; i <= x; i++)
		{
			y = x / i;

			if (y == 0)
			{
				cout << i << endl;
			}
		}
}
	void q5() {

	}

