//Ali Eren Günaltýlý 21801897 Section 01 CS
#include "Seat.h"
#pragma once
class Movie
{
public:
	Movie();
	Movie(const long movieID, const int audienceRadius);
	~Movie();
	void setID(long ID);
	void setRadius(int radius);
	long getID();
	int getRadius();
	int getRow();
	int getColumn();
	void setRow(int ro);
	void setColumn(int col);
	int getAvailableSeats();
	void setAvailableSeats(int availableSeat);
	void setSeats();
	void printSeatOrder();
	bool makeReservation(const int row, const int column);
	Seat** getSeatOrder();
	void cancelReservation(const int row, const int column);
	void deleteSeats();
	void copySeats(Seat** s, const int r, const int c);
private:
	long movieID;
	int audienceRadius;
	int row;
	int column;
	int availableSeats;
	Seat** seats;
};

