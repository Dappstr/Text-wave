/*
 Created by Lane Beals 10/24/2021
 Program will create a text wave with a string dictated by the user.
 Still a work in progress.
 */

#include <iostream>
#include <string>
#include <unistd.h> //For usleep()

using namespace std;

/*
Function prototype for making the text wave
It will take in a string from the user and then use a counter for each character in the string
*/
void waveMaker(string str, int counter);

//Function responsible for clearing the shell and setting the cursor to the top left
void printFunc(string str)
{
    cout << "\x1B[2J\x1B[H" << str;
    usleep(100000);
    cout.flush();
}

int main()
{
    int counter = 0;
    string userInput;
    
    cout << "Enter string: ";
    cin >> userInput;
        
    waveMaker(userInput, counter);
    
    return 0;
}

void waveMaker(string str, int counter)
{
    counter = 0;
    
    for(;counter <= str.length(); counter++)
    {
        /*
         Thinking of a way to detect if the first variable is already upper-case
         TO BE CONTINUED
        if (str[0] == std::toupper(str[0]))
        {
            counter++;
        }*/
        
        char c = str[counter];
        str[counter] = std::toupper(c);
        
            for(int x = counter-1; x <= str.length(); x--)
            {
                char y = str[x];
                str[x] = std::tolower(y);
            }
        
        printFunc(str);

        /*
         This loop will iterate in reverse to the previous loop.
         For now it just makes all the letters upper-case until I change it to only make a wave like the prior loop.
         */
        if(counter == str.length())
        {
            for(int x = counter; x >= 0; x--)
            {
                char y = str[x];
                str[x] = std::toupper(y);
                
                printFunc(str);
            }
        }
    }
}
