#ifndef MOVIE_H
#define MOVIE_H

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
    protected:
    private:
};

#endif // MOVIE_H
