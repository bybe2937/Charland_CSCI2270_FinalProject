#endif // MOVIE_H

#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>

struct Moovie
{
    std::string title;
    bool seen;
    int rating;
    std::string genre;
};
struct Book
{
    std::string title;
    bool read;
    int rating;
    std::string genre;
};
class Movie
{
    public:
        Movie();
        void addMovie(std::string title, std::string genre, bool seen, int rating);
        void addBook(std::string title, std::string genre, bool read, int rating);
        void deleteMovie(std::string title);
        void deleteBook(std::string title);
        void writeToFile();
        void readFromFile();
        Moovie findMovie(std::string title);
        Book findBook(std::string title);
        Book randBook(std::string genre);
        Moovie randMovie(std::string genre);
        void updateBook(std::string title, int rating);
        void updateMovie(std::string title, int rating);
		void printBookGenres();
		void printMovieGenres();

    protected:
    private:
        std::vector<Book> Books;
        std::vector<Moovie> Movies;
};

#endif // MOVIE_H
