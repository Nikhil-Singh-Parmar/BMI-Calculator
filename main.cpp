#include<iostream>
#include<vector>
#include<string>
using namespace std;

void
printBMI (vector < int >roll_no, vector < string > names,
	  vector < float >heights, vector < float >weights,
	  vector < float >BMI, int no)
{
  for (int i = 0; i < no; i++)
    {
      cout << roll_no[i] << " " << names[i] << " " << heights[i] << " " <<
	weights[i] << " " << BMI[i] << "\n";
    }
}

void
printBMIOverWeight (vector < string > names, vector < float >BMI, int no)
{
  cout << "List of Students having BMI under overweight category\n";
  for (int i = 0; i < no; i++)
    {
      if (BMI[i] >= 25.0 and BMI[i] <= 29.9)
	{
	  cout << names[i] << "\n";
	}
    }
}

void
printHealthy (vector < string > names, vector < float >BMI, int no)
{
  cout << "List of Students having BMI under Healthy category\n";
  for (int i = 0; i < no; i++)
    {
      if (BMI[i] >= 18.5 and BMI[i] <= 24.9)
	{
	  cout << names[i] << "\n";
	}
    }
}

void
updateHeight (vector < int >roll_no, vector < float >&heights, int no)
{
  int num;
  cout << "Enter roll number of student whose Height need to be changed\n";
  cin >> num;
  int index = -1;
  for (int i = 0; i < no; i++)
    {
      if (roll_no[i] == num)
	{
	  index = i;
	}
    }
  if (index != -1)
    {
      float temp;
      cout << "Enter New Height \n";
      cin >> temp;
      heights[index] = temp;
    }
  else
    {
      cout <<
	"The roll number you entered does not matches with our data please try again with another roll number\n";
    }

}

void
updateWeight (vector < int >roll_no, vector < float >&weights, int no)
{
  float num;
  cout << "Enter roll number of student whose Weight need to be changed\n";
  cin >> num;
  int index = -1;
  for (int i = 0; i < no; i++)
    {
      if (roll_no[i] == num)
	{
	  index = i;
	}
    }

  if (index != -1)
    {
      float temp;
      cout << "Enter New Weight \n";
      cin >> temp;
      weights[index] = temp;
    }
  else
    {
      cout <<
	"The roll number you entered does not matches with our data please try again with another roll number\n";
    }

}

int
main ()
{

  int no;

  cout << "Enter Number of Students Present in the Class\n";

  cin >> no;

  vector < int >roll_no;

  vector < string > names;

  vector < float >heights;

  vector < float >weights;

  for (int i = 1; i <= no; i++)

    {
      int temp_roll_no;

      cout << "Enter Roll Number of " << i << " student\n";

      cin >> temp_roll_no;

      roll_no.push_back (temp_roll_no);


      string temp_name;

      cout << "Enter Name of " << i << " student\n";

      cin >> temp_name;

      names.push_back (temp_name);


      float temp_height;

      cout << "Enter Height of " << i << " student\n";

      cin >> temp_height;

      heights.push_back (temp_height);


      float temp_weight;

      cout << "Enter Weight of " << i << " student\n";

      cin >> temp_weight;

      weights.push_back (temp_weight);


    }
  vector < float >BMI;
  for (int i = 0; i < no; i++)
    {
      BMI.push_back (weights[i] / (heights[i] * heights[i]));
    }
  int val = 0;

  while (val != -1)
    {

      cout << "Enter 1 to Print BMI of Every student\n";
      cout <<
	"Enter 2 to Print all student names who are under overweight category\n";
      cout <<
	"Enter 3 to Print all student names who are under healthy category\n";
      cout << "Enter 4 to Update height of a student\n";
      cout << "Enter 5 to update Weight of a student\n";
      cout << "Enter -1 to Exit\n";
      cin >> val;

      if (val == 1)
	{
	  printBMI (roll_no, names, heights, weights, BMI, no);
	}
      else if (val == 2)
	{
	  printBMIOverWeight (names, BMI, no);
	}
      else if (val == 3)
	{
	  printHealthy (names, BMI, no);
	}
      else if (val == 4)
	{
	  updateHeight (roll_no, heights, no);

	}
      else if (val == 5)
	{
	  updateWeight (roll_no, weights, no);

	}
    }

}
