//Ali Eren Günaltýlý 21801897 Section 01 CS
#pragma once
#include "Movie.h"
#include "Reservation.h"

class MovieBookingSystem {
public:
	const static int numOfRow = 30;
	const static int numOfColumn = 26;
	MovieBookingSystem();
	~MovieBookingSystem();
	void addMovie(const long movieID, const int audienceRadius);
	void cancelMovie(const long movieID);
	void showAllMovies();
	void showMovie(const long movieID);
	int makeReservation(const long movieID, const int row, const char col);
	void cancelReservations(const int numRes, const int* resCode);
	void showReservation(const int resCode);
	//int getCounter();
private:
	Movie* ptr;
	int counter;
	Reservation* res;
	int resSize;
};

