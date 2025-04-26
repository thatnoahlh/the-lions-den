#include <iostream> 
#include <fstream> 
#include <string> 

using namespace std; 

int main () { 

    string date; 
    string entry; 

    cout << "Enter date for Journal entry (YYYY-MM-DD):"; 
    getline (cin, date); 

    cout << "How are you feeling today?" << '\n';  
    getline (cin, entry); 

    ofstream file ("journal.txt", ios::app); 

    if (file.is_open()) { 

        file << "Date: " << date << '\n'; 
        file << "Entry: " << entry << '\n'; 

        file << "-----------------------------\n"; 

        file.close(); 

        cout << "Entry saved to journal!" << endl; 

    } else { 

        cout << "Could not open file" << endl; 

    } 

    return 0; 

} 
