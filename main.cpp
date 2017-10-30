
//  main.cpp
//  ClassRoomManagementSystem
//
//  Created by Ashraf Saber on 5/24/16.

#include <iostream>
#include "Student.cpp"
using namespace std;

// Definition of student struct with 3 parameters: id, score and letterGrade
struct student
{
    string id;              // declaration of the id variable  of data type string for the student struct
    double score;           // declaration of the numerical score variable of data type double
    string letterGrade;     // declaration of the letter grade variable of data type string
};

// array of struct definition
student studentsInClass[50];

//******************************************verifyID Function*******************************************//
//                                                                                                      //
// The purpose of this function is to verify that the string id of value a is not already existing      //
// in the array of structs of type student                                                              //
// The function reads two parameters:                                                                   //
// 1) the student id a of data type string                                                              //
// 2) the array of structs of type student                                                              //
// The function loops through the array and looks for a string that matches the value of a.             //
// Then, if an item of value a exists in the array the function return a true. Else, it returns false   //
//                                                                                                      //
//********************************************************************************************************

bool verifyID(string a, student b[] )
{
    int i=0;          // counter declaration and initialization
    bool flag = true; // flag declaration and initialization
    
    // do-while loop to ensure that the loop goes through the array as long as the flag is false
    // and the counter is less than the array length
    do
    {
        if (b[i].id == a) // checking if the element at index i of array b is equivalent to the value of string a
        {
            flag =true;  // if the condition is true, then value of the flag is true
        } else
        {
            flag=false;  // else it is false
        }
        i++;
    }
    while (( flag == false) && ( i <50));
    return flag;
}

// function to remove a student from the array of structs
//****************************************removeStudent Function******************************************
//                                                                                                      //
// The purpose of this function is to remove a student from the array of structs                        //
// The function reads two parameters:                                                                   //
// 1) the student id a of data type string                                                              //
// 2) the array of structs of data type student                                                         //
// The function loops through the array and looks for a string that matches the value of a.             //
// Then, the value that matches that of the provided id is changed to ""                                //
//                                                                                                      //
//********************************************************************************************************

void removeStudent(string e, student f[] )
{
    string studentToRemove = "";
    
    for (int i=0; i<50; i++)
    {
        if ( f[i].id == e)
        {
            string c = f[i].id;
            f[i].id= "";
            f[i].score= 0.0;
            cout<< "\nYou have successfully removed Student id "
            << c <<endl;
        }
    }
}

//******************************************assignGrade Function******************************************
//                                                                                                      //
// The purpose of this function is to assign a numerical grade to student                               //
// The function reads three parameters:                                                                 //
// 1) the numerical grade g of data type double                                                         //
// 2) the student id j of data type string                                                              //
// 3) the array of structs of data type student                                                         //
// The function loops through the array and looks for a string that matches the value of j.             //
// Then, the value of the double g is assigned to the score parameter of the struct                     //
//                                                                                                      //
//********************************************************************************************************

void assignGrade(double g, string j, student k[] )
{
    for(int i=0; i < 50 ; i++)
    {
        if (j == k[i].id)
        {
            k[i].score = g;
        }
    
    }
}

//******************************************updateGrade Function******************************************
//                                                                                                      //
// The purpose of this function is to assign a new grade to an existing grade                           //
// The function reads three parameters:                                                                 //
// 1) the numerical grade l of data type double                                                         //
// 2) the student id m of data type string                                                              //
// 3) the array of structs of data type student                                                         //
// The function loops through the array and looks for a string that matches the value of m.             //
// Then, the value of the double l is assigned to the score parameter of the struct.                    //
// Finally the user is prompted with both the old and the new                                           //
// grades.                                                                                              //
//                                                                                                      //
//********************************************************************************************************


void updateGrade(double l, string m, student n[])
{
    for(int i=0; i < 50 ; i++)
    {
        if (m == n[i].id)
        {
            cout<<"Previous score was "<<  n[i].score ;
            cout << ". Now the new score is: " << l << endl;
            n[i].score = l;
        }
    }
}


//******************************************countGrades Function******************************************
//                                                                                                      //
// The purpose of this function is to count the number of each letter grade in the class room           //
// The function reads one parameter:                                                                    //
// 1) the array of structs of data type student                                                         //
// The function loops through the array and counts the number of scores yiielding each letter grade     //
// Then, the value of each letter grade is counted                                                      //
//                                                                                                      //
//********************************************************************************************************

void countGrades(student h[])
{
    int countA =0, countB=0, countC=0, countD=0, countF=0;
    
    for(int i=0; i < 50; i++)
    {
        if (h[i].id != "")
        {
            if ( h[i].score >= 90)
            {
                countA+=1;
                h[i].letterGrade ="A";
            } else if (h[i].score >= 80)
            {
                countB+=1;
                h[i].letterGrade ="B";
            } else if (h[i].score >= 70)
            {
                countC+=1;
                h[i].letterGrade ="C";
            } else if (h[i].score >= 60)
            {
                countD+=1;
                 h[i].letterGrade ="D";
            } else
            {
                countF+=1;
                h[i].letterGrade ="F";
            }
        }
    }
    
    
    cout<< "\nNumber of A's in class: " << countA << endl;
    cout<< "Number of B's in class: " << countB << endl;
    cout<< "Number of C's in class: " << countC << endl;
    cout<< "Number of D's in class: " << countD << endl;
    cout<< "Number of F's in class: " << countF << endl;

}


//*********************************************average Function*******************************************
//                                                                                                      //
// The purpose of this function is to calculate the average of numerical scores in the class            //
// The function reads one parameter:                                                                    //
// 1) the array of structs of data type student                                                         //
// The function loops through the array and calculates the average for each value in the array of       //
// structs where the id is not null                                                                     //
//                                                                                                      //
//********************************************************************************************************

double average(student o[])
{
    int arraySum =0, denom =0;
    double avg;
    
    for(int s=0; s<50 ; s++)
    {
        if(o[s].id !="")
        {
            arraySum+= o[s].score;
            denom+=1;
        }
    }
    if(denom) // if (denom !=0)
    {    avg = arraySum/denom;  //????????
        return avg;
    } else
    {
        return 0;
    }
}

//**************************************highestGradeId Function*******************************************
//                                                                                                      //
// The purpose of this function is to find the id in the array of student stucts that corresponds to    //
// the highest numerical score                                                                          //
// The function reads one parameter:                                                                    //
// 1) the array of structs of data type student                                                         //
// The function loops through the array and looks for the max score in the array of structs and         //
// returns its corresponding id                                                                         //
//                                                                                                      //
//********************************************************************************************************

string highestGradeId(student v[])
{
    double max = v[0].score;
    string topId = v[0].id;
    
    for (int i=0; i<50; i++)
    {
        if (v[i].id != "")
        {
            if (v[i].score > max)
            {
                max = v[i].score;
                topId= v[i].id;
            }
        }
        
    }
    
    return topId;
}

//*****************************************printReport Function*******************************************
//                                                                                                      //
// The purpose of this function is to print a class report that lists the following:                    //
// 1) each id with its corresponding grade                                                              //
// 2) the highest score and its corresponding id                                                        //
// 3) the count of each letter grade                                                                    //
//                                                                                                      //
// The function reads one parameter:                                                                    //
// 1) the array of structs of data type student                                                         //
// The function loops through the array and prints each id with its corresponding grade.                //
// Then, the function prints the average and the highest grade.                                         //
//                                                                                                      //
//********************************************************************************************************

void printReport(student c[])
{
    cout<<"\n********Class Report********\n\n"<<endl;
    
    for (int i=0; i < 50; i++)
    {
        if (c[i].id != "")
        {
            cout<<"ID: " ;
            cout<<c[i].id ;
            cout<<" Score: ";
            cout<<c[i].score<<endl;
        }else
        {}
        
    }
    
    // Printing Class Average
    cout<<"\nThe Class Average is: ";
    double classAverage = average(c);
    cout<< classAverage << endl;
    
    // Printing Highest Grade
    cout<<"\nThe Highest Grade Student is: ";
    string studentHighestGrade = highestGradeId(c);
    cout << studentHighestGrade;
    cout<<" Grade: ";
    double valueOfHighestScore= 0.0;
    
    for (int i=0; i<50; i++)
    {
        if (c[i].id == studentHighestGrade)
        {
            valueOfHighestScore = c[i].score;
        }
    }
    
    cout << valueOfHighestScore <<endl;
    
    // Printing The Letter Grade Count
    countGrades(c);
    
    cout<<"\n *******End of Report*******\n"<<endl;
}

// main function
int main( )
{
    int userChoice;
    string studentId, studentGrade;
    double  studentScore =0.0, updatedGrade=0.0;
    int i=0;
    
    // Variable declaration
    string line,line2;

    string input,idToRemove;

    string idToAssignGrade, idToUpdate;
    
    double assignedGrade;
    
    do{
        // Printing the menu on the screen
        cout<<"\n1)Add Students to Class";
        cout<<"\n2)Remove Students from Class";
        cout<<"\n3)Set Grade for a Student";
        cout<<"\n4)Update Grade for a Student";
        cout<<"\n5)Print Report";
        cout<<"\n6)Exit\n"<<endl;

        cin>> input;
        while (!(input== "1" || input=="2" || input=="3" || input=="4" || input=="5" || input=="6"))
        {
            cout<<"\nPlease input a valid choice from the menu: ";
            cin>>input;
        }
 
        userChoice = stoi(input);
    
        // Validating user choice
        while(userChoice !=1 && userChoice !=2 && userChoice !=3 && userChoice !=4 && userChoice !=5 && userChoice !=6)
        {
            cout<<"\nPlease input a valid choice from the menu: ";
            cin >>userChoice;
        }
        
        switch (userChoice)
        {
            case 1:
                // Adding a student
                

                
                // Prompting the user for the id
                cout<<"\nKindly input ID: ";
                cin >> studentId;
                
                // Verifying Id
                while( verifyID(studentId, studentsInClass ) == true )
                {
                    cout<<"\nThis ID already exists. Please input a valid Id: ";
                    cin >>studentId;
                }
                
                // Prompting the user for Numerical Score
                cout<< "\nKindly input Numerical Score:    (Enter s to Skip)\n";
                cin>> line;
                
                // Checking whether or not the user decides to skip
                if (line == "s" || line == "S")
                {
                // If the user decides to skip, nothing happens and we proceed to the next question
                } else  // However, if a user decides to input a numerical score, the string is parsed into double
                {
                    studentScore = stold(line);
                    while (studentScore <0 || studentScore>100)
                    {
                        cout<<"Please input a valid score between 0 and 100";
                        cin>>studentScore;
                    }
                    
                }
                
                // Prompting the user for letter grade
                cout<< "Kindly input Letter Grade (A/B/C/D/F):    (Enter s to Skip)\n";
                cin >> line2;
                
                while (!(line2 == "s" || line2 == "S" || line2 == "a" || line2 == "A" || line2 == "b" || line2 == "B"
                         || line2 == "c" || line2 == "C" || line2 == "D" || line2 == "d" ))
                {
                    cout<< "Kindly input a valid choice:    (Enter s to Skip)";
                    cin >> line2;
                }
                
                // Checking whether or not the user decides to skip
                if (line2 == "s" || line2 == "S")
                {
                // If the user decides to skip, nothing happens and we proceed to the next question
                } else  // However, if a user decides to input a letter grade the value is stored into the variable studentGrade
                {
                    studentGrade = line2;
                }
                    
                studentsInClass[i].id = studentId ;
                studentsInClass[i].score = studentScore;
                studentsInClass[i].letterGrade= studentGrade;
                
                i++;
                break;
                
            case 2:
                // Removing a student
                
                //Prompting the user for id to remove
                cout<<"Please provide id to remove: "<<endl;
                cin>> idToRemove;
                
                // Verifying Id
                while( verifyID(idToRemove, studentsInClass ) == false )
                {
                    cout<<"This ID does not exist. Please input a valid Id:  ";
                    cin >>idToRemove;
                }
                
                removeStudent(idToRemove, studentsInClass);
                
                break;
                
            case 3:
                // Set grade
                cout<< "Input the ID to assign numerical grade: ";
                cin>>idToAssignGrade;
                
                // Verifying Id
                while( verifyID(idToAssignGrade, studentsInClass ) == false )
                {
                    cout<<"This ID does not exist. Please input a valid Id:  ";
                    cin >>idToAssignGrade;
                }
                
                // Prompting the user to input a numerical grade from 0-100
                do{
                    cout<<"Input numerical grade (0-100): ";
                    cin>> assignedGrade;
                }while(assignedGrade <0 || assignedGrade >100);
                
                assignGrade(assignedGrade,idToAssignGrade,studentsInClass);
                
                break;
                
            case 4:
                // Update grade
                cout<<"\nInput student id:";
                cin>> idToUpdate;
                
                // Verifying Id
                while( verifyID(idToUpdate, studentsInClass ) == false )
                {
                    cout<<"This ID does not exist. Please input a valid Id:  ";
                    cin >>idToUpdate;
                }
                
                
                // Prompting the user to input a numerical grade from 0-100
                do{
                    cout<<"Input numerical grade (0-100): ";
                    cin>> updatedGrade;
                }while(updatedGrade <0 || updatedGrade >100);
                
                updateGrade(updatedGrade, idToUpdate, studentsInClass);
                
                break;
            case 5:
                // Print Report
                printReport(studentsInClass);
                break;
          
            case 6:
                // Exit
                cout<< "\nThank you. Have a good day :)"<<endl;
                break;
            
            default:
                break;
        }
        
    
    } while (userChoice != 6);
    return 0;
}


