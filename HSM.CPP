#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAXPATIENTS 100
struct patient
{
char FirstName[50];
char LastName[50];
char ID[20];
};
class queue
{
public:
queue(void);
int AddPatientAtEnd(patient p);
int AddPatientAtBeginning(patient p);
patient getNextPatient(void);
int RemoveDeadPatient(patient *p);
void OutputList(void);
char DepartmentName[50];
private :
int NumberOfPatients;
patient List[MAXPATIENTS];
};
queue::queue()
{
NumberOfPatients=0;
}
int queue::AddPatientAtEnd(patient p)
{
if(NumberOfPatients>=MAXPATIENTS)
{
return 0;
}
else
List[NumberOfPatients]=p;
NumberOfPatients;
return 1;
}
int queue::AddPatientAtBeginning(patient p)
{int i;
if(NumberOfPatients>=MAXPATIENTS)
{
return 0;
}
for(i=NumberOfPatients-1;i>=0;i--)
{
List[i+1]=List[i];
}
List[0]=p;
NumberOfPatients++;
return 1;
}
patient queue::getNextPatient(void)
{
int i;
patient p;
if(NumberOfPatients ==0)
{
strcpy(p.ID,"");
return p;
}
p=List[0];
NumberOfPatients--;
for(i=0;i<NumberOfPatients;i++)
{List[i]=List[i+1];
}
return p;
}
int queue::RemoveDeadPatient(patient *p)
{
int i,j,found=0;
for(i=0;i<NumberOfPatients;i++)
{
if(stricmp(List[i].ID,p->ID)==0)
{
*p=List[i];
found=1;
NumberOfPatients;
for(j=1;j<NumberOfPatients;j++)
{
List[j]=List[j+1];
}
}}
return found;
}
void queue::OutputList(void)
{ int i;
if(NumberOfPatients==0)
{cout<<"queue is empty";
}
else
{
for(i=0;i<NumberOfPatients;i++)
{
cout<<""<<List[i].FirstName;
cout<<" "<<List[i].LastName;
cout<<" "<<List[i].ID;
}
}
}
patient InputPatient(void)
{
patient p;
cout<<"Please enter data for new patient First name:\n\n\n ";
cin.getline(p.FirstName,sizeof(p.FirstName));
cout<<"Last Name:\n\n\n ";
cin.getline(p.LastName,sizeof(p.LastName));
cout<<"Social security  number:\n\n\n ";
cin.getline(p.ID,sizeof(p.ID));
if(p.FirstName[0]==0 || p.LastName[0]==0 || p.ID[0]==0)
{
strcpy(p.ID,"");
cout<<"error:data not valid.operation cancelled.";
getch();
}
return p;
}



void OutputPatient (patient * p)
{
   // this function outputs patient data to the screen
   if (p == NULL || p->ID[0]==0)
	{
		cout << "No patient";
		return;
	}
   else
   cout << "Patient data:\n\n";
   cout << "First name:\n\n " << p->FirstName;

   cout << "Last name:\n\n " << p->LastName;
   cout << "Social security number:\n\n " << p->ID;
}


int ReadNumber()
{
   // this function reads an integer number from the keyboard.
   // it is used because input with cin >> doesn't work properly!
   char buffer[20];
   cin.getline(buffer, sizeof(buffer));
   return atoi(buffer);
}


void DepartmentMenu (queue * q)
{
   // this function defines the user interface with menu for one
   int choice = 0, success;  patient p;
   while (choice != 6)
	{
	   // clear screen
	   clrscr();
	   // print menu
	   cout << "Welcome to department:\n " << q->DepartmentName;
	   cout << "Please enter your choice:\n";
	   cout << "1:  Add normal patient\n";
	   cout << "2:  Add critically ill patient\n";
	   cout << "3:  Take out patient for operation\n";
	   cout << "4:  Remove dead patient from queue\n";
	   cout << "5:  List queue\n";
	   cout << "6:  Change department or exit\n\n";
	   // get user choice
	   choice = ReadNumber();
		// do indicated action
	switch (choice)
	  {
		case 1:   // Add normal patient
		p = InputPatient();
		if (p.ID[0])
		   {
			success = q->AddPatientAtEnd(p);
			clrscr();
			  if (success)
			    {
				cout << "Patient added:";

			    }
		else
		   {
			// error
			cout << "Error: The queue is full. Cannot add patient:";
		   }
			OutputPatient(&p);
			cout << "Press any key";
			getch();
	  }
	 break;

      case 2:   // Add critically ill patient
	 p = InputPatient();
	 if (p.ID[0])
	     {
		success = q->AddPatientAtBeginning(p);
		clrscr();
		  if (success)
			{
			  cout << "Patient added:";
			}
		  else
			{
			  // error
			  cout << "Error: The queue is full. Cannot add patient:";
			}

			  OutputPatient(&p);
			  cout << "Press any key";
			  getch();
	     }
	 break;

      case 3:   // Take out patient for operation
	 p = q->getNextPatient();
	 clrscr();
	 if (p.ID[0])
	    {
	       cout << "Patient to operate:";

	       OutputPatient(&p);}
	 else
	    {
	       cout << "There is no patient to operate.";
	    }
	       cout << "Press any key";
	       getch();
	       break;

      case 4:   // Remove dead patient from queue
	 p = InputPatient();
	 if (p.ID[0])
	   {
		success = q->RemoveDeadPatient(&p);
		clrscr();
		  if (success)
		      {
			cout << "Patient removed:";
		      }
		  else
		      {
			// error
			cout << "Error: Cannot find patient:";
		      }
		OutputPatient(&p);
		cout << "Press any key";
		getch();
	   }
	 break;

      case 5:   // List queue
	 clrscr();
	 q->OutputList();
	 cout << "Press any key";
	 getch();  break;
	 }
      }
}


// main function defining queues and main menu
void main ()
{
   int i, MenuChoice = 0;
   // define three queues
   queue departments[3];
   // set department names
   strcpy (departments[0].DepartmentName, "Heart clinic\n\n");
   strcpy (departments[1].DepartmentName, "Lung clinic\n\n");
   strcpy (departments[2].DepartmentName, "Plastic surgery\n\n");

   while (MenuChoice != 4)
	{
	   // clear screen
	   clrscr();
	   // print menu
	   cout << "Welcome to Software City Hospital";
	   cout << "Please enter your choice:";
	  for (i = 0; i < 3; i++)
		{
		   // write menu item for department i
		   cout << "" << (i+1) << ":  " << departments[i].DepartmentName;
		}
	  cout << "4:  Exit";
	  // get user choice
	  MenuChoice = ReadNumber();
	  // is it a department name?
		if (MenuChoice >= 1 && MenuChoice <= 3)
		    {
			// call submenu for department
			// (using pointer arithmetics here:)
			DepartmentMenu (departments + (MenuChoice-1));
		    }
	}
}


