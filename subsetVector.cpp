#include<bits/stdc++.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//string IntToString (int a);

bool isSum(int sum, vector <int> vect);

void printVect(vector <int> vect);

bool is_number(string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void printSubset(int arr[], int n, int j, vector <int> vect, int sum)
{
    if(j >= n)
        return;
    if(isSum(sum, vect))
        printVect(vect);

    for(int i = j+1; i < n; i++)
    {
        vector <int> vect2;
        vect2 = vect;
        vect2.push_back(arr[i]);
        printSubset(arr,n,i,vect2, sum);
    }
}

int main()
{
	int arr[] = { -4, -3, -2, -1, 0 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	string inputsum;
	cout<<"Input sum: ";
	cin>>inputsum;
    int sum;

	while(!is_number(inputsum)){
        cout<<"Input a correct integer!"<<endl;
        cin>>inputsum;
	}
	istringstream ( inputsum ) >> sum; //to int


    for(int i = 0; i < n; i++)
    {
        vector <int> vect;
        vect.push_back(arr[i]);
	    printSubset(arr, n,i,vect, sum);
    }
	return 0;
}

bool isSum(int sum, vector <int> vect){

    int len = vect.size();
    int a = 0;
    for (int i =0; i < len; ++i)
        a+= vect.at(i);


    if(a == sum) return true;

    return false;
}

void printVect(vector <int> vect){
    int len = vect.size();

    for(int i=0; i<len; i++)
    {
        cout<<vect.at(i)<<"\t";
    }

    cout<<endl;
}
