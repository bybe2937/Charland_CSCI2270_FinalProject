#include "Movie.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
Movie::Movie()
{
    //ctor
}
void Movie::addMovie(std::string title, std::string genre, bool seen, int rating)
{
    Moovie toAdd;
    toAdd.title = title;
    toAdd.genre = genre;
    toAdd.seen = seen;
    toAdd.rating = rating;
    Movies.push_back(toAdd);

}
void Movie::addBook(std::string title, std::string genre, bool read, int rating)
{
    Book toAdd;
    toAdd.title = title;
    toAdd.genre = genre;
    toAdd.read = read;
    toAdd.rating = rating;
    Books.push_back(toAdd);
}
void Movie::deleteMovie(std::string title)
{
    ///Not in use yet. Can't decide if it should be implemented.
}
void Movie::deleteBook(std::string title)
{
    ///Not in use yet. Can't decide if it should be implemented or not.
}
void Movie::writeToFile()
{
    ofstream outfile;
    outfile.open("BookMovieList.txt", ofstream::out | ofstream::trunc);
    outfile << "Movies" << '\n';
    for(int i =0; i < Movies.size(); i++)
    {
        outfile<< Movies[i].title << ',' << Movies[i].genre << ',' << Movies[i].rating << ',' << Movies[i].seen << '\n';

    }
    outfile << "Books" << '\n';
    for (int i =0; i< Books.size(); i++)
    {
        outfile << Books[i].title << ',' << Books[i].genre << ',' << Books[i].rating << ',' << Books[i].read << '\n';
    }

}
void Movie::readFromFile()
{
    string line, word, title, genre;
    int rating;
    bool seen;
    bool isMovies = true;
    stringstream ss;
    ifstream infile;
    infile.open("BookMovieList.txt");  /// This is the same filename that it outputs to.
    if(infile.is_open())
    {
        getline(infile, line);
        while(getline(infile, line))
        {
            ss << line;
            if(line == "Books")  ///This pulls the header off of the Books section of the file and makes it do books instead
            {
                isMovies = false;
                getline(infile, line);
                ss.clear();
                ss << line;
            }
            if(isMovies)
            {
                for(int i =0; i < 4; i++)
                {
                    getline(ss, word, ',');
                    if(i == 0)
                    {
                        title = word;
                    }
                    else if (i == 1)
                    {
                        genre = word;
                    }
                    else if(i == 2)
                    {
                        rating = stoi(word);
                    }
                    else if(i == 3)
                    {
                        seen = stoi(word);
                    }
                }
                Moovie temp; ///Creates a movie object and adds it to movie vector
                temp.genre = genre;
                temp.rating = rating;
                temp.title = title;
                temp.seen = seen;
                Movies.push_back(temp);
                cout << "Movie Added "<< temp.title << endl;
            }
            else
            {
                for(int i =0; i < 4; i++)
                {
                    getline(ss, word, ',');
                    cout << word << ' ' << i << endl;
                    if(i == 0)
                    {
                        title = word;
                    }
                    else if (i == 1)
                    {
                        genre = word;
                    }
                    else if(i == 2)
                    {
                        rating = stoi(word);
                    }
                    else if(i == 3)
                    {
                        seen = stoi(word);
                    }
                }
                Book temp;
                temp.genre = genre;
                temp.rating = rating; ///Creates a book object to add to the vector
                temp.title = title;
                temp.read = seen;
                Books.push_back(temp);
                cout << "Book Added " << temp.title << endl;
            }
        }
    }
    else
        cout << "File not found" << endl;
}
Moovie Movie::findMovie(std::string title)
{

}
Book Movie::findBook(std::string title)
{

}
Book Movie::randBook(std::string genre)
{

}
Moovie Movie::randMovie(std::string genre)
{

}
void Movie::updateBook(std::string title, int rating)
{

}
void Movie::updateMovie(std::string title, int rating)
{

}
