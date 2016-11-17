#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream File;
    ofstream outFile;
     
    char status,answer;
    
    string LastName, FirstName, address;
    
    long phoneNumber, phoneNumber2;
    
    float amount;
    
    File.open("potentials.txt"); //read file
    
    while( !File.eof() ) //set conditions
    {
           File >> status;
           File >> FirstName;
           File >> LastName;
           File >> phoneNumber;
           File >> phoneNumber2;
           
           cout << "Customer's name: " << FirstName << ", " << LastName << endl;
           cout << "Customer's Phone Number: " << phoneNumber << phoneNumber2 << endl; 
           
           if( status == 'X')
           {
               cout << "Call and offer a credit card with a 7.9% intrest rate" << endl;
           }
           else
           {
               cout << "Call and offer a credit card with a 12.9% intrest rate" << endl;
           }
               
           cout << "\tEnter 'A' to accept the card \n\tEnter 'T' to transfer a balance \n\tEnter 'D' to decline the card:" << endl;
           cin >> answer;
           
           if( answer == 'A')
           {
               cout << "Ask for an address to send the card to." << endl;
               cin.ignore();
               getline(cin,address);
               cout << "Accepted!" <<endl;
               cout << "Tell the customer 'Thank you for your service and you will \nbe receiveing your card soon! Happy spending!" << endl << endl;
               
               outFile.open("confirmed.txt");   //open file and save info to it       
               outFile << FirstName << ", ";
               outFile << LastName << " ";
               outFile << status << " ";
               outFile << answer << endl;          
               
           }
           else if ( answer == 'T' )
           {
                if ( status == 'X' )
                {
                     cout << "No transfer limit!" << endl;
                     cout << "Ask how much they'd like to transfer." << endl;
                     cin.ignore();
                     cin >> amount;
                     cout << "Accepted!" << endl;                     
                }
                else
                {
                    cout << "$1000 transfer limit" << endl;
                    cout << "Ask how much they'd like to transfer." << endl;
                    cin.ignore();
                    cin >> amount;
                    if(amount<1000)
                    {
                        cout << "Accepted!" << endl;
                    }
                    else
                    {
                        cout << "Not acceptable." << endl;
                    }
                    cout << "Ask for an address to send the card to." << endl;
                    cin.ignore();
                    getline(cin,address);
                    cout << "Accepted!" << endl;
                    cout << "Tell the customer: 'Thank you for your service and you will be receiveing your card soon! Happy spending!" << endl << endl;
                    
                    outFile.open("confirmed.txt");         
                    outFile << FirstName << ", ";
                    outFile << LastName << " ";
                    outFile << status << " ";
                    outFile << answer << " ";
                    outFile << amount << endl; 
                    
                }
           }
           else if ( answer == 'D' )
           {
                if ( status == 'X' )
                {
                     cout << "Tell the customer: 'You will receive cash back rewards if you choose this better card. Call (911)867-5309 for more information.'"<< endl << endl; 
                }
                else
                {
                    cout << "Tell the customer: 'Thank you for your time.'" << endl << endl; 
                }
           }              
    }              
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
