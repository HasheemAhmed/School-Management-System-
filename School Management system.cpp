#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

/* ----------Update  Student -------------------------------*/

void updatestudent( int count)
{
	system ( "cls" );
	cout << "**********************************************************************" << endl;
	cout << "                          Update Student                              " << endl << endl;
	cout << "**********************************************************************\n" ;

	char yesno;
	do
	{
		string roll;
		cout << "Enter Student Roll no : ";
		cin >> roll;
		
		bool found = false, clear = false;
		int i;
		int j = 0 ;
		
		string names,classes,rolls,phones,grades;
		
		ifstream search("student.txt" , ios :: app);
		ofstream del("temp.txt");
		
		
		while ( !search.eof() )
		{
			getline ( search , names );
			getline ( search , rolls );
			getline ( search , classes );
			getline ( search , phones );
			getline ( search , grades );
			
			if ( roll == rolls )
			{
				cout << "\nName             : ";
				cout << names;
				                                      
				cout << "\nRoll no          : ";
				cout << rolls;
			
				cout << "\nClass            : ";
				cout << classes;
			
				cout << "\nPhone no         : ";
				cout << phones;
				
				cout << "\nGrade of student : ";
				cout << grades;
				
				found = true;
			}
			
			else if ( roll != rolls )
			{
				if( j > 0)
				{
					del << endl;
				}
				
				del << names;
				del << endl << rolls ;
				del << endl << classes ;
				del << endl << phones ;
				del << endl << grades ;
				clear = true;
				
				j++;
			}
		}
		
		search.close();
		del.close();
		
		if ( found == true)
		{
		
			j = 0;
		
			ifstream dele("temp.txt" , ios :: app);
			ofstream updates ( "student.txt" );
			
			while ( !dele.eof() )
			{
				
				getline ( dele , names );
				getline ( dele , rolls );
				getline ( dele , classes );
				getline ( dele , phones );
				getline ( dele , grades );
				
				if( j > 0)
				{
					updates << endl;
				}
				
				updates << names  ;
				updates << endl << rolls  ;
				updates << endl << classes ;
				updates << endl << phones ;
				updates << endl << grades ;
				
				
				j++;
			}
			
			updates.close();
			
			if(clear == false)
			{
				ofstream data("student.txt");
				
				data.clear();
			}
			
			ofstream update ("student.txt" , ios::app);
				
			cout << "\n\n********************************************************\n" ;
			cout << "                      Update the information                \n" ;
			cout << "********************************************************\n\n" ;
			
			cout << "\nEnter the name              : ";
			cin >> ws;
			getline (cin ,names );
			
			                                      
			cout << "\nEnter the Roll no          : ";
			cin >> ws;
			getline ( cin , rolls );
			
			
			cout<<"\nEnter the Class            : ";
			cin >> ws;
			getline ( cin , classes );
			
			
			cout << "\nEnter the Phone no         : ";
			cin >> ws;
			getline ( cin , phones);
			
			
			cout << "\nEnter the Grade of student : ";
			cin >> ws;
			getline (cin , grades );
			
				
			update << endl << names << endl ;
			update << rolls << endl ;
			update << classes << endl ;
			update << phones << endl ;
			update << grades ;
			
		}
		
		else
		{
			cout << "Student not found." ;
		}
		
		cout<<"\n\n********************************************************\n\n";
	
		cout<<"Do you want to update more student? ( y / n)."<<endl;
		cin>>yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout<<"Enter y for yes or n for no : "<<endl;
				cin>>yesno;	
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 

}

/* ----------Delete  Student -------------------------------*/

void deletestudent( int& count)
{
	system ( "cls" );
	cout << "**********************************************************************" << endl;
	cout << "                          Delete Student                              " << endl << endl;
	cout << "**********************************************************************\n" ;

	char yesno;
	do
	{
		string roll;
		cout << "Enter Student Roll no : ";
		cin >> roll;
		
		bool found = false, clear = false;
		int i;
		int j = 0 ;
		
		string names,classes,rolls,phones,grades;
		
		ifstream search("student.txt" , ios :: app);
		ofstream del("temp.txt");
		
		
		while ( !search.eof() )
		{
			getline ( search , names );
			getline ( search , rolls );
			getline ( search , classes );
			getline ( search , phones );
			getline ( search , grades );
			
			if ( roll == rolls )
			{
				cout << "\nName             : ";
				cout << names;
				                                      
				cout << "\nRoll no          : ";
				cout << rolls;
			
				cout << "\nClass            : ";
				cout << classes;
			
				cout << "\nPhone no         : ";
				cout << phones;
				
				cout << "\nGrade of student : ";
				cout << grades;
				
				found = true;
			}
			
			else if ( roll != rolls )
			{
				if( j > 0)
				{
					del << endl;
				}
				
				del << names;
				del << endl << rolls ;
				del << endl << classes ;
				del << endl << phones ;
				del << endl << grades ;
				
				clear = true;
				
				j++;
			}
		}
		
		search.close();
		del.close();
		
		if ( found == true)
		{
		
			j = 0;
			--count;
			
			ofstream totalstudent("totalstudents.txt");
	
			totalstudent << count;
			totalstudent.close();
			
			ofstream updates ( "student.txt" );
			ifstream dele("temp.txt" , ios :: app);
		
			while ( !dele.eof() )
			{
				getline ( dele , names );
				getline ( dele , rolls );
				getline ( dele , classes );
				getline ( dele , phones );
				getline ( dele , grades );
				
				if( j > 0)
				{
					updates << endl;
				}
				
				updates << names  ;
				updates << endl << rolls  ;
				updates << endl << classes ;
				updates << endl << phones  ;
				updates << endl << grades ;
				
				j++;
			}
			
			if(clear == false)
			{
				ofstream data("student.txt");
				
				data.clear();
			}
		}
		
		else
		{
			cout << "Student not found." ;
		}
		
		cout<<"\n\n********************************************************\n\n";
	
		cout<<"Do you want to delete more student? ( y / n)."<<endl;
		cin>>yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout<<"Enter y for yes or n for no : "<<endl;
				cin>>yesno;	
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 

}

/* ----------Search  Student -------------------------------*/

void searchstudent(int count )
{
	system ( "cls" ) ;
	cout << "**********************************************************************" << endl;
	cout << "                          Search Student                              " << endl << endl;
	cout << "**********************************************************************\n";
		
	char yesno;
	do
	{
			
		string roll;
		cout << "Enter Student Roll no : ";
		cin >> roll;
		
		bool found = false;
		int i;
		
		string names,classes,rolls,phones,grades;
		
		ifstream search("student.txt" , ios :: app);
	
		while ( !search.eof())
		{
			getline ( search , names );
			getline ( search , rolls );
			getline ( search , classes );
			getline ( search , phones );
			getline ( search , grades );
			
			if ( roll == rolls) 
			{
				cout << "\nName             : ";
				cout << names;
				                                      
				cout << "\nRoll no          : ";
				cout << rolls;
			
				cout << "\nClass            : ";
				cout << classes;
			
				cout << "\nPhone no         : ";
				cout << phones;
				
				cout << "\nGrade of student : ";
				cout << grades;
				
				found = true;
				break;
			}
			
			
			i++;
			
		}
	
		if ( found == false)
		{
			cout << "No Record Found.";
		}
	
		search.close();

		cout << "\n\n********************************************************\n\n";
	
		cout << "Do you want to search more student? ( y / n)." << endl;
		cin >> yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout << "Enter y for yes or n for no : " << endl;
				cin >> yesno;	
				
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
				
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 
}

/* ----------View Student -------------------------------*/

void viewstudent(int count)
{
	system ( "cls" );
	cout << "**********************************************************************" << endl;
	cout << "                          View Student                              " << endl << endl;
	cout << "**********************************************************************\n\n";
	
	int i = 1;
	string names,classes,rolls,phones,grades;
	
	ifstream data("student.txt" , ios :: app);
	
	while ( !data.eof() ) 
	{
		getline ( data , names );
		getline ( data , rolls );
		getline ( data , classes );
		getline ( data , phones );
		getline ( data , grades );
		
		cout << "\nName             : ";
		cout << names;
		                                      
		cout << "\nRoll no          : ";
		cout << rolls;
	
		cout << "\nClass            : ";
		cout << classes;
	
		cout << "\nPhone no         : ";
		cout << phones;
		
		cout << "\nGrade of student : ";
		cout << grades;
				
		i++;

		cout<<"\n\n********************************************************\n\n";
	} 
	
	cout << "Type any word to go back.";
	char back;
	cin>>back;
}

/* ----------Add Student -------------------------------*/
	
void addstudent(int & count)
{
	system ( "cls" );
	int i=0;
	char yesno;
	
	cout << "**********************************************************************" << endl;
	cout << "                          Adding information                          " << endl << endl;
	cout << "**********************************************************************\n";
		
	do
	{	
		string name, classes, roll, phone, grade;
		
		cout << "\nEnter Student name : ";
		cin >> ws;
		getline (cin,name);
		                                      
		cout << "\nEnter roll no : ";
		cin >> ws;
		getline (cin,roll);
	
		cout << "\nEnter the class : ";
		cin >> ws;
		getline (cin,classes);
	
		cout << "\nEnter Phone no : ";
		cin >> ws;
		getline (cin,phone);
		
		cout << "\nEnter the Grade of student : ";
		cin >> ws;
		getline (cin,grade);	
		
		ofstream addstudent("student.txt" , ios :: app);
		
		if( count > 0)
		{
			addstudent << endl;
		}
		
		addstudent << name ;
		addstudent << endl << roll ;
		addstudent << endl << classes ;
		addstudent << endl << phone ;
		addstudent << endl << grade ;
		addstudent.close();
		
		++count; 
		
		ofstream totalstudent("totalstudents.txt");
	
		totalstudent << count;
		totalstudent.close();
	
		cout << "\n\n********************************************************\n\n";
	
		cout << "Do you want to add more student? ( y / n)."<<endl;
		cin >> yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout << "Enter y for yes or n for no : " << endl;
				cin >> yesno;	
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 	
		
}

/* ---------- Student Function -------------------------------*/

void student()
{
	
	int choice,exit,count=0;
	
	ifstream totals("totalstudents.txt");
	
	totals >> count;
	
	do
	{	
		system ( "cls" );
		cout << "**********************************************************************" << endl;
		cout << "                     Student information                              " << endl << endl;
		cout << "**********************************************************************" << endl << endl;
	
		cout << "1. Add Student information."   << endl;
		cout << "2. View student information."  << endl;
		cout << "3. Search student information." << endl;
		cout << "4. Update student information." << endl;
		cout << "5. Delete student information." << endl;
		cout << "6. Exit" << endl;
		cin >>choice;
		
		switch (choice)
		{	
			case 1 : addstudent(count);    break;
			case 2 : viewstudent(count);   break;
			case 3 : searchstudent(count); break;
			case 4 : updatestudent(count); break;
			case 5 : deletestudent(count); break; 
			case 6 : exit = choice;        break;	
			default:cout<<"Invalid Entry";
		}
	} while ( exit != 6); 
	
}

/* ----------Update  Teacher -------------------------------*/

void updateteacher( int count)
{
	system ( "cls" );
	cout << "**********************************************************************" << endl;
	cout << "                          Update Teacher                              " << endl << endl;
	cout << "**********************************************************************\n" ;

	char yesno;
	do
	{
		string id;
		cout << "Enter Teacher id : ";
		cin >> id;
		
		bool found = false;
		int i;
		int j = 0 ;
		
		string names,subjects,ids,phones,lectures;
		
		ifstream search("teacher.txt" , ios :: app);
		ofstream del("temp.txt");
		
		
		while ( !search.eof() )
		{
			getline ( search , names );
			getline ( search , ids );
			getline ( search , subjects );
			getline ( search , phones );
			getline ( search , lectures );
			
			if ( id == ids )
			{
				cout << "\nName             : ";
				cout << names;
				                                      
				cout << "\nId               : ";
				cout << ids;
			
				cout << "\nSubject            : ";
				cout << subjects;
			
				cout << "\nPhone no         : ";
				cout << phones;
				
				cout << "\nTotal lectures of Teachers : ";
				cout << lectures;
				
				found = true;
			}
			
			else if ( id != ids )
			{
				if( j > 0)
				{
					del << endl;
				}
				
				del << names;
				del << endl << ids ;
				del << endl << subjects ;
				del << endl << phones ;
				del << endl << lectures ;
				
				j++;
			}
		}
		
		search.close();
		del.close();
		
		if ( found == true)
		{
		
			j = 0;
			ofstream updates ( "teacher.txt" );
			ifstream dele("temp.txt" , ios :: app);
			
			while ( !dele.eof() )
			{
				getline ( dele , names );
				getline ( dele , ids );
				getline ( dele , subjects );
				getline ( dele , phones );
				getline ( dele , lectures );
				
				if( j > 0)
				{
					updates << endl;
				}
				
				updates << names  ;
				updates << endl << ids  ;
				updates << endl << subjects ;
				updates << endl << phones ;
				updates << endl << lectures ;
				
				j++;
			}
			
			updates.close();
			
			ofstream update ("teacher.txt" , ios::app);
				
			cout << "\n\n********************************************************\n" ;
			cout << "                      Update the information                \n" ;
			cout << "********************************************************\n\n" ;
			
			cout << "\nEnter the name              : ";
			cin >> ws;
			getline (cin ,names );
			
			                                      
			cout << "\nEnter the id                : ";
			cin >> ws;
			getline ( cin , ids );
			
			
			cout<<"\nEnter the subjects            : ";
			cin >> ws;
			getline ( cin , subjects );
			
			
			cout << "\nEnter the Phone no         : ";
			cin >> ws;
			getline ( cin , phones);
			
			
			cout << "\nEnter the lectures of teacher : ";
			cin >> ws;
			getline (cin , lectures );
			
				
			update << endl << names << endl ;
			update << ids << endl ;
			update << subjects << endl ;
			update << phones << endl ;
			update << lectures ;
			
		}
		
		else
		{
			cout << "Teacher not found." ;
		}
		
		cout<<"\n\n********************************************************\n\n";
	
		cout<<"Do you want to update more Teacher? ( y / n)."<<endl;
		cin>>yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout<<"Enter y for yes or n for no : "<<endl;
				cin>>yesno;	
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 

}

/* ----------Delete  teacher -------------------------------*/

void deleteteacher( int& count)
{
	system ( "cls" );
	cout << "**********************************************************************" << endl;
	cout << "                          Delete Teacher                              " << endl << endl;
	cout << "**********************************************************************\n" ;

	char yesno;
	do
	{
		string id;
		cout << "Enter Teacher id : ";
		cin >> id;
		
		bool found = false;
		int i;
		int j = 0 ;
		
		string names,subjects,ids,phones,lectures;
		
		ifstream search("teacher.txt" , ios :: app);
		ofstream del("temp.txt");
		
		
		while ( !search.eof() )
		{
			getline ( search , names );
			getline ( search , ids );
			getline ( search , subjects );
			getline ( search , phones );
			getline ( search , lectures );
			
			if ( id == ids )
			{
				cout << "\nName             : ";
				cout << names;
				                                      
				cout << "\nId               : ";
				cout << ids;
			
				cout << "\nSubjects         : ";
				cout << subjects;
			
				cout << "\nPhone no         : ";
				cout << phones;
				
				cout << "\nTotal number of lectures : ";
				cout << lectures;
				
				found = true;
			}
			
			else if ( id != ids )
			{
				if( j > 0)
				{
					del << endl;
				}
				
				del << names;
				del << endl << ids ;
				del << endl << subjects ;
				del << endl << phones ;
				del << endl << lectures ;
				
				j++;
			}
		}
		
		search.close();
		del.close();
		
		if ( found == true)
		{
		
			j = 0;
			--count;
			
			ofstream totalteacher("totalteachers.txt");
	
			totalteacher << count;
			totalteacher.close();
		
			ofstream updates ( "teacher.txt" );
			ifstream dele("temp.txt" , ios :: app);
		
			while ( !dele.eof() )
			{
				getline ( dele , names );
				getline ( dele , ids );
				getline ( dele , subjects );
				getline ( dele , phones );
				getline ( dele , lectures );
				
				if( j > 0)
				{
					updates << endl;
				}
				
				updates << names  ;
				updates << endl << ids  ;
				updates << endl << subjects ;
				updates << endl << phones  ;
				updates << endl << lectures ;
				
				j++;
			}
		}
		
		else
		{
			cout << "Teacher not found." ;
		}
		
		cout<<"\n\n********************************************************\n\n";
	
		cout<<"Do you want to delete more Teacher? ( y / n)."<<endl;
		cin>>yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout<<"Enter y for yes or n for no : "<<endl;
				cin>>yesno;	
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 

}

/* ----------Search  teacher -------------------------------*/

void searchteacher(int count )
{
	system ( "cls" ) ;
	cout << "**********************************************************************" << endl;
	cout << "                          Search Teacher                              " << endl << endl;
	cout << "**********************************************************************\n";
		
	char yesno;
	do
	{
			
		string id;
		cout << "Enter Teacher id : ";
		cin >> id;
		
		bool found = false;
		int i;
		
		string names,subjects,ids,phones, lectures;
		
		ifstream search("teacher.txt" , ios :: app);
	
		while ( !search.eof())
		{
			getline ( search , names );
			getline ( search , ids );
			getline ( search , subjects );
			getline ( search , phones );
			getline ( search , lectures );
			
			if ( id == ids) 
			{
				cout << "\nName             : ";
				cout << names;
				                                      
				cout << "\nID               : ";
				cout << ids;
			
				cout << "\nSubjects         : ";
				cout << subjects;
			
				cout << "\nPhone no         : ";
				cout << phones;
				
				cout << "\nTotal lectures of teacher : ";
				cout << lectures;
				
				found = true;
				break;
			}
			
			
			i++;
			
		}
	
		if ( found == false)
		{
			cout << "No Record Found.";
		}
	
		search.close();

		cout << "\n\n********************************************************\n\n";
	
		cout << "Do you want to search more teacher? ( y / n)." << endl;
		cin >> yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout << "Enter y for yes or n for no : " << endl;
				cin >> yesno;	
				
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
				
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 
}

/* ----------View teacher -------------------------------*/

void viewteacher(int count)
{
	system ( "cls" );
	cout << "**********************************************************************" << endl;
	cout << "                          View Teacher                              " << endl << endl;
	cout << "**********************************************************************\n\n";
	
	int i = 1;
	
	string names,subjects,ids,phones,lectures;
	
	ifstream data("teacher.txt" , ios :: app);
	
	while ( !data.eof() ) 
	{
		getline ( data , names );
		getline ( data , ids );
		getline ( data , subjects );
		getline ( data , phones );
		getline ( data , lectures );
		
		cout << "\nName             : ";
		cout << names;
		                                      
		cout << "\nId               : ";
		cout << ids;
	
		cout << "\nSubjects         : ";
		cout << subjects;
	
		cout << "\nPhone no         : ";
		cout << phones;
		
		cout << "\nTotal Leactures of teacher : ";
		cout << lectures;
				
		i++;

		cout<<"\n\n********************************************************\n\n";
	} 
	
	cout << "Type any word to go back.";
	char back;
	cin>>back;
}

/* ----------Add Teacher -------------------------------*/
	
void addteacher(int &count)
{
	system ( "cls" );
	int i=0;
	char yesno;
	
	cout << "**********************************************************************" << endl;
	cout << "                          Adding information                          " << endl << endl;
	cout << "**********************************************************************\n";
		
	do
	{	
		string name, subject, id, phone, lecture;
		
		cout << "\nEnter Teacher name : ";
		cin >> ws;
		getline (cin,name);
		                                      
		cout << "\nEnter id : ";
		cin >> ws;
		getline (cin,id);
	
		cout << "\nEnter the subject : ";
		cin >> ws;
		getline (cin,subject);
	
		cout << "\nEnter Phone no : ";
		cin >> ws;
		getline (cin,phone);
		
		cout << "\nEnter the total lectures of teacher : ";
		cin >> ws;
		getline (cin,lecture);	
		
		ofstream addteacher("teacher.txt" , ios :: app);
		
		if( count > 0)
		{
			addteacher << endl;
		}
		
		addteacher << name ;
		addteacher << endl << id ;
		addteacher << endl << subject ;
		addteacher << endl << phone ;
		addteacher << endl << lecture ;
		addteacher.close();
		
		++count;
	 	ofstream totalteacher("totalteachers.txt");
	
		totalteacher << count;
		totalteacher.close();
		
		cout << "\n\n********************************************************\n\n";
	
		cout << "Do you want to add more teacher? ( y / n)."<<endl;
		cin >> yesno;
		
		if ( yesno == 'y')
		{
			i++;
		}
		else if ( yesno == 'n' )
		{
			break;
		}
		else
		{
			do
			{
				cout << "Enter y for yes or n for no : " << endl;
				cin >> yesno;	
				if ( yesno == 'y')
				{
					i++;
					break;
				}
				else if ( yesno == 'n' )
				{
					break;
				}
			}while (yesno != 'y' || yesno != 'n' );
		}
			
	} while ( yesno !='n' ); 	
		
}

/* ---------- Teacher Function -------------------------------*/

void teacher()
{
	
	int choice,exit,count=0;
	
	ifstream totals("totalteachers.txt");
	
	totals >> count;
	
	do
	{	
		system ( "cls" );
		cout << "**********************************************************************" << endl;
		cout << "                     Teachers information                              " << endl << endl;
		cout << "**********************************************************************" << endl << endl;
	
		cout << "1. Add teacher information."   << endl;
		cout << "2. View teacher information."  << endl;
		cout << "3. Search teacher information." << endl;
		cout << "4. Update teacher information." << endl;
		cout << "5. Delete teacher information." << endl;
		cout << "6. Exit" << endl;
		cin >>choice;
		
		switch (choice)
		{	
			case 1 : addteacher(count);    break;
			case 2 : viewteacher(count);   break;
			case 3 : searchteacher(count); break;
			case 4 : updateteacher(count); break;
			case 5 : deleteteacher(count); break; 
			case 6 : exit = choice;        break;	
			default:cout<<"Invalid Entry";
		}
	} while ( exit != 6); 
	
	
	ofstream totalteachers("totalteachers.txt");
	
	totalteachers << count;
	totalteachers.close();

}

/* ----------Main Function -------------------------------*/

int main()
{
	
	int choice,exit;
	
	do
	{	
		system ( "cls" );
		cout << "**********************************************************************" << endl;
		cout << "                     School Management System                         " << endl << endl;
		cout << "**********************************************************************" << endl << endl;
	
		cout << "1. Student information."   << endl;
		cout << "2. Teachers information."  << endl;
		cout << "3. Exit" << endl;
		cin >>choice;
		
		switch (choice)
		{	
			case 1 : student();     break;
			case 2 : teacher();     break; 
			case 3 : exit = choice; break;	
			default:cout<<"Invalid Entry";
		}
	} while ( exit != 3); 
		
	return 0;
}