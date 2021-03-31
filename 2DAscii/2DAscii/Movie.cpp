//Ali Eren Günaltýlý 21801897 Section 01 CS
#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie() {
	//default constructor
	movieID = 0;
	audienceRadius = 0;
	availableSeats = 0;
	row = 1;
	column = 1;
	seats = NULL;
}

Movie::~Movie() {
	
	for (int i = 0; i < row; i++) {
		delete[] seats[i];
	}
	delete[] seats;
	seats = NULL;
}

void Movie::deleteSeats() {
	if (seats != NULL) {
		for (int i = 0; i < row; i++) {
			seats[i] = NULL;
			delete[] seats[i];
		}
		seats = NULL;
		delete[] seats;
	}
}
Movie::Movie(const long movieID, const int audienceRadius) {
	setID(movieID);
	setRadius(audienceRadius);
}

int Movie::getRadius() {
	return audienceRadius;
}
long Movie::getID() {
	return movieID;
}

void Movie::setID(const long id) {
	movieID = id;
}

void Movie::setRadius(const int radius) {
	if (radius >= 0 && radius <= 7) {
		audienceRadius = radius;
	}

	else {
		cout << "type valid radius value for movie " << endl;
	}
}

void Movie::setColumn(int movieCol) {
	if (movieCol > 0 && movieCol < 30) {
		column = movieCol;
	}
	else {
		column = 1;
	}
}

void Movie::setRow(int Mrow) {
	if (Mrow > 0 && Mrow < 32) {
		row = Mrow;
	}
	else {
		row = 1;
	}
}

void Movie::setAvailableSeats(int availableSeat) {
	availableSeats = availableSeat;
}

int Movie::getRow() {
	return row;
}

int Movie::getColumn() {
	return column;
}

void Movie::copySeats(Seat** s, const int r, const int columnn) {
	if (seats != NULL) {
		for (int i = 0; i < row; i++) {
			delete[] seats[i];
			seats[i] = NULL;
		}
		delete[] seats;
		seats = NULL;
	}
	
	
	seats = new Seat *[r];
	for (int i = 0; i < r; i++) {
		seats[i] = new Seat[columnn];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < column; j++) {
			seats[i][j] = s[i][j];
		}
	}
}
void Movie::setSeats() {
	
	if ((row != 0) && (column != 0)) {
		seats = new Seat * [row];
		for (int i = 0; i < row; i++) {
			seats[i] = new Seat[column];
		}
	}
	else
		seats = NULL;
}

Seat** Movie::getSeatOrder() {
	return seats;
}


int Movie::getAvailableSeats() {
	return availableSeats;
}

bool Movie::makeReservation(const int Rrow, const int Rcolumn) {
	
	if (seats[Rrow][Rcolumn].getAvailable()) {
		seats[Rrow][Rcolumn].setAvailable(0);
		availableSeats--;
		return true;
		printSeatOrder();
	}
	else {
		return false;
	}
}

void Movie::cancelReservation(const int Rrow, const int Rcolumn) {
	seats[Rrow][Rcolumn].setAvailable(1);
	availableSeats++;
}

void Movie::printSeatOrder() {
	for (int i = 0; i < column ; i++) {
		if (i == 0) {
			cout << "  ";
		}
		char ch = 65 + (i * (audienceRadius + 1));
		cout << " " << ch;
	}
	cout << " " << endl;
	for (int i = 0; i < row; i++) {
		cout << 1 + (i * (audienceRadius + 1));
		if ((1 + (i * (audienceRadius + 1))) >= 10) {
			cout << " ";
		}
		else {
			cout << "  ";
		}
		
		for (int j = 0; j < column ; j++) {
			if ((*(seats + i))[j].getAvailable()) {
				cout << "O ";
			}
			else {
				cout << "X ";
			}
		}
		cout << " " << endl;
	}
	cout << " " << endl;
} 


