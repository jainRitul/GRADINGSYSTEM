#include <iostream>
#include <map>
#include <cmath>
using namespace std;

string toUpper(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (islower(str[i]))
            str[i] -= ' ';
    }
    return str;
}

pair<int, int> getHighestLowest(string grades[], int n, map<string, int> mp)
{
    int highestGrade = mp[toUpper(grades[0])];
    int lowestGrade = highestGrade;

    for (int i = 1; i < n; i++)
    {
        int val = mp[toUpper(grades[i])];
        if (val > highestGrade)
            highestGrade = val;
        if (val < lowestGrade)
            lowestGrade = val;
    }

    return {highestGrade, lowestGrade};
}

int main()
{
    // Initializing the map for storing grades and their grade point.
    map<string, int> mp;
    mp.insert({"O", 10});
    mp.insert({"A+", 9});
    mp.insert({"A", 8});
    mp.insert({"B+", 7});
    mp.insert({"B", 6});
    mp.insert({"P", 5});
    mp.insert({"F", 0});

    // Reverse map to get Grade according the point
    map<int, string> rmp;
    for (auto p : mp)
    {
        rmp.insert({p.second, p.first});
    }

    // Initialize the number of students and the grades array.
    int num_students;
    cout << "Enter the number of total students: ";
    cin >> num_students;
    string grades[num_students];

    // Get the student names and grades from the user.
    for (int i = 0; i < num_students; i++)
    {
        cout << "Enter the name of student " << i + 1 << ": ";
        string name;
        cin >> name;

        cout << "Enter the grade of student " << i + 1 << ": ";
        cin >> grades[i];
    }

    // Calculate the average grade.
    int total_grades = 0;
    for (int i = 0; i < num_students; i++)
    {
        total_grades += mp[toUpper(grades[i])];
    }

    float average_grade = (float)total_grades / num_students;

    // Find the highest and lowest grades.
    pair<int, int> highLowpair = getHighestLowest(grades, num_students, mp);
    int highest_grade = highLowpair.first;
    int lowest_grade = highLowpair.second;

    // Display the results.
    cout << "The average grade is " << rmp[round(average_grade)] << endl;
    cout << "The highest grade is " << rmp[highest_grade] << endl;
    cout << "The lowest grade is " << rmp[lowest_grade] << endl;

    return 0;
}