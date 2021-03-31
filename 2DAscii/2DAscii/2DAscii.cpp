// 2DAscii.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "MovieBookingSystem.h"
#include "Seat.h"
#include "Movie.h"
#include <iostream>
using namespace std;
#include <string>

//void makeRes(Seat** seat ,const int row, const char column);
int main()
{
    MovieBookingSystem M;
    int* codes = new int[2];
    M.showAllMovies();
    cout << endl;
    M.addMovie(1614791273, 0);
    M.addMovie(1614801273, 3);
    M.addMovie(1615801273, 1);
    cout << endl;
    M.showAllMovies();
    cout << endl;
    M.addMovie(1614791273, 2);
    cout << endl;
    codes[1] = M.makeReservation(1614801273, 1, 'A');
    codes[0] = M.makeReservation(1614801273, 9, 'A');
    cout << endl;
    M.showMovie(1614801273);
    cout << endl;
    M.showReservation(codes[0]);
    cout << endl;
    M.cancelReservations(2, codes);
    cout << endl;
    codes[0] = M.makeReservation(1614801273, 1, 'A');
    M.makeReservation(1614801273, 1, 'A');
    M.makeReservation(1614801273, 5, 'E');
    M.makeReservation(1614801273, 5, 'M');
    cout << endl;
    codes[1] = -1;
    M.cancelReservations(2, codes);
    M.showReservation(codes[0]);
    cout << endl;
    M.makeReservation(1614801273, 12, 'D');
    cout << endl;
    M.showMovie(1614801273);
    cout << endl;
    M.cancelMovie(1614801273);
    M.showReservation(codes[0]);
    cout << endl;
    M.cancelMovie(1614801273);
    M.addMovie(1614801273, 4);
    M.showMovie(1614801273);
    M.showAllMovies();
    //1614791273 = 20.07
    codes[0] = M.makeReservation(1614791273, 5, 'K');
    codes[1] = M.makeReservation(1614791273, 16, 'U');
    M.showAllMovies();
    M.showMovie(1614791273);
    M.showReservation(codes[1]);
    codes[1] = -1;
    M.cancelReservations(2, codes);
    M.showMovie(1614791273);
    codes[1] = M.makeReservation(1614801273, 21, 'K');
    M.showAllMovies();
    M.cancelMovie(1614791273);
    M.cancelReservations(2, codes);
    M.showMovie(1614791273);
    M.showAllMovies();
    M.addMovie(1614791273, 8);
    M.addMovie(1614791273, 5);
    M.showMovie(1614791273);
    M.makeReservation(1614791273, 1, 'A');
    M.makeReservation(1614791273, 25, 'S');
    M.makeReservation(1614791273, 25, 'Y');
    M.showMovie(1614791273);
    M.showAllMovies();

    //codes[1] = 
 //   codes[0] = M.makeReservation(16)
    delete[] codes;

    //newcodes[0] = M.makeReservation(1615801273, 26, 'C');
    //newcodes[1] = M.makeReservation(1614791273, )
    //M.showAllMovies();
    return 0;
}
   
   