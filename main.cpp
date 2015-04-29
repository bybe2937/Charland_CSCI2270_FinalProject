#include <iostream>
#include "Movie.h"
#include <fstream>

using namespace std;
void printMenu();
int main()
{
    Movie database; ///Creating the initial database.
    string input = "-1";
    while (input != "8")
    {
        printMenu();
        getline(cin, input);
        if(input == "1")
        {
            database.readFromFile();
        }
        else if(input == "2")
        {
            string title, genre, read, inRating;
            int rating;
            bool isRead;
            cout << "Input title" << endl;
            getline(cin, title);
            cout << "Input Genre" << endl;
            getline(cin , genre);
            cout << "Have you read it?(y/n)" << endl;
            getline(cin, read);
            if(read == "y")
                isRead = true;
            else
                isRead = false;
            if(isRead)
            {
                cout << "How would you rate it (1-10)" << endl;
                getline(cin, inRating);
                rating = stoi(inRating);

            }
            else
                rating = -1;

            database.addBook(title, genre, isRead, rating);
        }
        else if(input == "3")
        {
            string title, genre, read, inRating;
            int rating;
            bool isRead;
            cout << "Input title" << endl;
            getline(cin, title);
            cout << "Input Genre" << endl;
            getline(cin , genre);
            cout << "Have you seen it?(y/n)" << endl;
            getline(cin, read);
            if(read == "y")
                isRead = true;
            else
                isRead = false;
            if(isRead)
            {
                cout << "How would you rate it (1-10)" << endl;
                getline(cin, inRating);
                rating = stoi(inRating);

            }
            else
                rating = -1;

            database.addMovie(title, genre, isRead, rating);
        }
        else if(input == "4")
        {
            string title, inRating;
            int rating;
            cout << "Title: " << endl;
            getline(cin, title);
            cout << "How would you rate it?(1-10)" << endl;
            getline(cin, inRating);
            rating = stoi(inRating);
            database.updateMovie(title, rating);
        }
        else if(input == "5")
        {
            string title, inRating;
            int rating;
            cout << "Title: " << endl;
            getline(cin, title);
            cout << "How would you rate it?(1-10)" << endl;
            getline(cin, inRating);
            rating = stoi(inRating);
            database.updateBook(title, rating);
        }
        else if(input == "6")
        {
            string genre;
            cout << "What Genre?" << endl;
            getline(cin, genre);
            Moovie output = database.randMovie(genre);
            if(output.title != "-1")
                cout << "Go watch this: " << output.title << endl;
        }
        else if(input == "7")
        {
            string genre;
            cout << "What Genre?" << endl;
            getline(cin, genre);
            Book output = database.randBook(genre);
            if(output.title != "-1")
                cout << "Go read this: " << output.title << endl;
        }
    }
    database.writeToFile(); /// overwrites to the same filename as read in. Keeps the database after the manager is closed
    cout << "Later!"<< endl;

    return 0;
}
void printMenu()
{
    cout << "Main Menu" << endl;
    cout << "1. Read in data" << endl;
    cout << "2. Add book" << endl;
    cout << "3. Add Movie" << endl;
    cout << "4. Mark as Watched" << endl;
    cout << "5. Mark as Read" << endl;
    cout << "6. Pick me a movie!" << endl;
    cout << "7. Pick me a book!" << endl;
    cout << "8. Quit" << endl;
}
