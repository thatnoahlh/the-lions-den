#include <iostream> 
#include <string> 

using namespace std; 

int main() { 

    int numQuestions = 10; 
    string answers; 
    char input; 

    cout << "Welcome to the questionaire!" << endl; 

    for (int i = 1; i < numQuestions + 1; i++) { 

        cout << "Question 1:" << '\n'; 
        cout << "How often do you feel overwhelmed by your daily responsibilities?" << endl; 
        cout << "a) Rarely or never" << "   " << "b) Occasionally" << endl; 
        cout << "c) Often" << "    " << "d) Almost all the time" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 2:" << '\n'; 
        cout << "How would you describe your energy levels throughout the day?" << endl; 
        cout << "a) High and consistent" << "   " << "b) Mostly good, with some dips" << endl; 
        cout << "c) Low, often tired" << "    " << "d) Exhausted or drained most of the time" << endl; 

        cin >> input; 
        answers += input;

        cout << "Question 3:" << '\n'; 
        cout << "How often do you feel anxious or worried?" << endl;  
        cout << "a) Rarely" << "    " << "b) Sometimes" << endl; 
        cout << "c) Frequently" << "    " << "d) Constantly" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 4:" << '\n'; 
        cout << "How do you usually sleep at night?" << endl; 
        cout << "a) I sleep well and feel rested" << "    " << "b) I sleep okay, but sometimes wake up tired" << endl; 
        cout << "c) I have trouble falling or staying asleep" << "    " << "d) I rarely get restful sleep" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 5:" << '\n'; 
        cout << "How do you feel about yourself most of the time?" << endl; 
        cout << "a) I like and accept who I am" << "    " << "b) I’m okay, but struggle with self-doubt" << endl; 
        cout << "c) I often criticize myself" << "    " << "d) I don’t like myself at all" << endl; 

        cin >> input; 
        answers += input;

        cout << "Question 6:" << '\n'; 
        cout << "How interested are you in things you used to enjoy?" << endl; 
        cout << "a) Very interested" << "    " << "b) Somewhat interested" << endl; 
        cout << "c) Not as much as before" << "    " << "d) Not interested at all" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 7:" << '\n'; 
        cout << "How often do you feel sad or down?" << endl; 
        cout << "a) Rarely" << "    " << "b) Occasionally" << endl; 
        cout << "c) Often" << "    " << "d) Nearly every day" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 8:" << '\n'; 
        cout << "How connected do you feel to the people around you?" << endl; 
        cout << "a) Very connected" << "    " << "b) Somewhat connected" << endl; 
        cout << "c) Often lonely" << "    " << "d) Very isolated" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 9:" << '\n'; 
        cout << "How do you handle challenges or stressful situations?" << endl; 
        cout << "a) I stay calm and manage them well" << "    " <<  "b) I struggle sometimes, but usually figure it out"
        << endl; 
        cout << "c) I often feel stuck or panicked" << "    " << "d) I feel overwhelmed and avoid them" << endl; 

        cin >> input; 
        answers += input; 

        cout << "Question 10:" << '\n'; 
        cout << "How motivated do you feel to get things done?" << endl; 
        cout << "a) Very motivated" << "   " << "b) Usually motivated" << endl; 
        cout << "c) Struggle with motivation" << "    " << "d) No motivation at all" << endl; 

        cin >> input; 
        answers += input; 

        //cout << "Your results: " << answers << '\n'; 

    
    int countA, countB, countC, countD; 

    for (char input : answers) { 

        switch (tolower (input)) { 

            case 'a': countA++; break;  

            case 'b': countB++; break;  

            case 'c': countC++; break; 

            case 'd': countD++; break; 

        } 

    } 


    cout << "Your results: " << '\n'; 
    cout << "Total 'A' answers: " << countA << endl; 
    cout << "Total 'B' answers: " << countB << endl; 
    cout << "Total 'C' answers: " << countC << endl; 
    cout << "Total 'D' answers: " << countD << endl; 

    for (size_t j = 0; j < answers.length(); j++) { 

        if (countA > 5) { 

            cout << "Your answers are mostly 'A'" << endl; 
            cout << "You are Mentally Resilient & Balanced" << endl; 
            break; 
        } 

        if (countB > 5) { 

            cout << "Your answers are mostly 'B'" << endl; 
            cout << "You are Generally Okay, With Room to Improve" << endl; 
            break; 
        } 

        if (countC > 5) { 

            cout << "Your answers are mostly 'C'" << endl; 
            cout << "You are Feeling Stuck or Worn Down" << endl; 
            break; 
        } 

        if (countD > 5) { 

            cout << "Your answers are mostly 'D'" << endl; 
            cout << "You are Struggling Significantly" << endl; 
            break; 
        } 

    } 

    break; 

    }  

    return 0; 
} 
