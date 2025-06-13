#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter total number of courses :" << endl;
    cin >> n;
    double grade;
    int credit;
    double totalgradepoint = 0;
    int totalcredit = 0;

    for (int i = 1; i <= n; i++)
    {
        cout<<"\nCourse"<<i<<":\n";
        cout<<"Enter grade (out of 10): ";
        cin>> grade;
        cout<<"Enter credit hours :";
        cin>> credit;

       totalgradepoint += grade * credit;
       totalcredit += credit;

    }

      double CGPA = totalgradepoint/totalcredit;
      cout<<"Final CGPA "<<CGPA<<endl;
    return 0;
}