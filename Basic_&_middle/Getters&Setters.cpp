#include <iostream>



using namespace std;

class Movie {
    private: // Encapsulation: private members can only be accessed through public getter and setter methods
        string title;
        string director;
        int year;
        string rating;
    public: // Getters and Setters: public methods to access and modify private members
        void setTitle(string aTitle) {
            title = aTitle;
        }
        string getTitle() {
            return title;
        }
        void setDirector(string aDirector) {
            director = aDirector;
        }
        string getDirector() {
            return director;
        }
        void setYear(int aYear) {
            year = aYear;
        }
        int getYear() {
            return year;
        }
        void setRating(string aRating) {
            rating = aRating;
        }
        string getRating() {
            return rating;
        }
};

int main() {
    Movie movie1;
    movie1.setTitle("Inception");
    movie1.setDirector("Christopher Nolan");
    movie1.setYear(2010);
    movie1.setRating("PG-13");

    cout << "Title: " << movie1.getTitle() << endl;
    cout << "Director: " << movie1.getDirector() << endl;
    cout << "Year: " << movie1.getYear() << endl;
    cout << "Rating: " << movie1.getRating() << endl;

    return 0;
}

