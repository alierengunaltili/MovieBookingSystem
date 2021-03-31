//Ali Eren Günaltýlý 21801897 Section 01 CS

#include "MovieBookingSystem.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <string>
#pragma warning(disable : 4996)
using namespace std;


MovieBookingSystem::MovieBookingSystem() {
	//ptr = new Movie[5];
	ptr = NULL;
	counter = 0;
	res = NULL;
	resSize = 0;
}

MovieBookingSystem::~MovieBookingSystem() {
	delete[]ptr;
	delete[]res;

}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius) {
	time_t rawtime;
	int column;
	int row;

	//radius check
	if (audienceRadius > 7 || audienceRadius < 0) {
		cout << "Type valid audience radius for movie between 7 and 0 inclusive.  " << endl;
		return;
	}
	for (int i = 0; i < counter; i++) {
		if (ptr[i].getID() == movieID) {
			rawtime = (const time_t)movieID;
			cout << "The movie is already on the list which is at  " << ctime(&rawtime);
			return;
		}
	}
	if (numOfColumn % (audienceRadius + 1) == 0) {
		column = numOfColumn / (audienceRadius + 1);
	}
	else {
		column = (numOfColumn / (audienceRadius + 1)) + 1;
	}
	if (numOfRow % (audienceRadius + 1) == 0) {
		row = numOfRow / (audienceRadius + 1);
	}
	else {
		row = (numOfRow / (audienceRadius + 1)) + 1;
	}

	rawtime = (const time_t)movieID;
	cout << "Addition of movie is done , Currently added movie at " << ctime(&rawtime);


	Movie* tmp = ptr;
	//cout << "1111" << endl;
	ptr = new Movie[counter + 1];
	for (int i = 0; i < counter; i++) {
		ptr[i].setAvailableSeats(tmp[i].getAvailableSeats());
		ptr[i].setColumn(tmp[i].getColumn());
		ptr[i].setID(tmp[i].getID());
		ptr[i].setRadius(tmp[i].getRadius());
		ptr[i].setRow(tmp[i].getRow());
		ptr[i].setSeats();
		//cout << tmp[i].getRow() << endl;
	}

	ptr[counter].setID(movieID);
	ptr[counter].setRadius(audienceRadius);
	ptr[counter].setRow(row);
	ptr[counter].setColumn(column);
	int available_seats = row * column;
	ptr[counter].setAvailableSeats(available_seats);
	ptr[counter].setSeats();
	
	delete[]tmp;
	tmp = NULL;
	//cout << "3333" << endl;
	counter++;
}




void MovieBookingSystem::cancelMovie(const long movieID) {
	bool isFind = false;
	time_t rawtime;
	int index = -1;
	rawtime = (const time_t)movieID;
	
	for (int i = 0; i < counter; i++) {
		if (ptr[i].getID() == movieID) {
			index = i;
			isFind = true;
		}
	}

	if (!isFind) {
		cout << "Movie you have tried to cancel is not valit at " << ctime(&rawtime);
		return;
	}
	Movie* tmp = ptr;
	ptr = new Movie[counter - 1];

	for (int i = 0; i < index; i++) {
		ptr[i].setAvailableSeats(tmp[i].getAvailableSeats());
		ptr[i].setColumn(tmp[i].getColumn());
		ptr[i].setID(tmp[i].getID());
		ptr[i].setRadius(tmp[i].getRadius());
		ptr[i].setRow(tmp[i].getRow());
		//cout << " burassýý a" << endl;
		ptr[i].copySeats(tmp[i].getSeatOrder(), tmp[i].getRow(), tmp[i].getColumn());
	}

	for (int i = index + 1; i < counter; i++) {
		ptr[i - 1].setAvailableSeats(tmp[i].getAvailableSeats());
		ptr[i-1].setColumn(tmp[i].getColumn());
		ptr[i-1].setID(tmp[i].getID());
		ptr[i-1].setRadius(tmp[i].getRadius());
		ptr[i-1].setRow(tmp[i].getRow());
		ptr[i-1].copySeats(tmp[i].getSeatOrder(), tmp[i].getRow(), tmp[i].getColumn());
	}

	cout << "Movie cancellation has been done for movie at " << ctime(&rawtime);
	for (int i = 0; i < resSize; i++) {
		if (res[i].getrID() == movieID) {
			res[i].setrID(-1);
		}
	}
	delete[] tmp;
	tmp = NULL;
	counter--;
}

void MovieBookingSystem::showAllMovies() {
	time_t rawtime;
	cout << "Movies on show : " << endl;
	for (int i = 0; i < counter; i++) {
		rawtime = (const time_t)ptr[i].getID();
		cout <<  "(" << ptr[i].getAvailableSeats() << " available seats) " << "Movie at : " << ctime(&rawtime)  ;
	}
}

void MovieBookingSystem::showMovie(const long movieID) {
	bool isFinded = false;
	for (int i = 0; i < counter; i++) {
		if (ptr[i].getID() == movieID) {
			time_t rawtime;
			rawtime = (const time_t)ptr[i].getID();
			cout << "Movie currently has " << ptr[i].getAvailableSeats() << " available seats. Which is at "  << ctime(&rawtime);
			ptr[i].printSeatOrder();
			isFinded = true;
		}
	}
	if (isFinded) {
		return;
	}
	else {
		time_t rawtime;
		rawtime = (const time_t)movieID;
		cout << "The movie doesn't exist, at time " << ctime(&rawtime);
	}
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
	int tmp_col;
	int returnedValue = 0;
	int tmp_row;
	tmp_col = col - 65;
	Movie* tmp = NULL;
	bool isFinded = false;
	int index = 0;
	for (int i = 0; i < counter; i++) {
		if (ptr[i].getID() == movieID) {
			tmp = &ptr[i];
			isFinded = true;
			index = i;
		}
	}

	if (isFinded) {
		//tmp->makeReservation(row, col);
		bool isOccupied;
		int tmp_row;
		if ((row - 1) % (tmp->getRadius() + 1) == 0) {
			tmp_row = (row - 1) / (tmp->getRadius() + 1);
		}
		else {
			time_t rawtime;
			rawtime = (const time_t)movieID;
			cout << "Seat " << col << row  <<  " is not occupiable movie at " << ctime(&rawtime);
			return -1;
		} 
		int tmp1 = col;
		tmp1 = col - 65;
		if ((tmp1 % (tmp->getRadius() + 1)) == 0) {
			tmp1 = tmp1 / (tmp->getRadius() + 1);
		}
		else {
			cout << "Invalid row and column for movie with ID: " << movieID << endl;
			return -1;
		}
		//cout << row << " -  " << col << endl;
		//cout << "reservation row " << tmp_row << " reservation col " << tmp1 << endl;
		isOccupied = ptr[index].makeReservation(tmp_row, tmp1);
		time_t rawtime;
		rawtime = (const time_t)movieID;
		if (!isOccupied) {
			cout << "Seat " << col << row << " is not available for " << ctime(&rawtime) << endl;
			return -1;
 		}
		cout << "Reservation is done for " << col << row << " movie at " << ctime(&rawtime);

		if (resSize > 0) {
			Reservation* tmp_res = new Reservation[resSize];
			for (int i = 0; i < resSize; i++) {
				tmp_res[i] = res[i];
			}
			
			delete[]res;
			res = NULL;
			res = new Reservation[resSize + 1];
			for (int i = 0; i < resSize; i++) {
				res[i] = tmp_res[i];
			}
			res[resSize].setrCol(tmp1);
			res[resSize].setrRow(tmp_row);
			res[resSize].setrID(movieID);
			resSize++;
			delete[] tmp_res;

		}
		else {
			res = new Reservation[resSize + 1];
			res[resSize].setrCol(tmp1);
			res[resSize].setrRow(tmp_row);
			res[resSize].setrID(movieID);
			resSize++;
		}

		returnedValue = resSize - 1;

	}
	else {
		cout << "Given Movie with ID cannot be founded" << endl;
		return -1;
	}

	return returnedValue;
}

void MovieBookingSystem::cancelReservations(const int numRes, const int* resCode) {
	int indexOfMovie;
	int tmp_row;
	int tmp_col;
	char columnChar;

	for (int i = 0; i < numRes; i++) {
		if (resCode[i] < 0  || resCode[i] > resSize)  {
			cout << "Some reservation codes is not valid. Cancellation is failed. " << endl;
			return;
		}
		int tmp;
		tmp = resCode[i];
		if (res[tmp].getrID() <= 0) {
			cout << "Some reservation codes is not valid. Cancellation is failed. " << endl;
			return;
		}
	}

	for (int i = 0; i < numRes; i++) {
		int currentRadius = 0;
		int tmp2;
		tmp2 = resCode[i];
		for (int j = 0; j < counter; j++) {
			if (res[tmp2].getrID() == ptr[j].getID()) {
				ptr[j].cancelReservation(res[tmp2].getrRow(), res[tmp2].getrCol());
				currentRadius = ptr[j].getRadius();
			}
		}
		const char ch = 65 + (res[tmp2].getrCol() * (currentRadius + 1));
		time_t rawtime;
		rawtime = (const time_t)res[tmp2].getrID();
		cout << "Res Code:  " << (resCode[i]) << " , "  <<  ch << (res[tmp2].getrRow() * (currentRadius + 1)) + 1
			 << " is cancelled for movie " << ctime(&rawtime) << endl;
		res[tmp2].setrID(-1);
	}

}

void MovieBookingSystem::showReservation(const int resCode) {
	if (resCode < 0) {
		cout << "There is no reservation with this reservation code " << resCode << endl;
		return;
	}

	int tmp = resCode;

	if (res[tmp].getrID() < 0 || resCode > resSize) {
		cout << "There is no reservation with this reservation code " << resCode << endl;
		return;
	}
	int currentRadius = 0;
	for (int i = 0; i < counter; i++) {
		if (res[tmp].getrID() == ptr[i].getID()) {
			currentRadius = ptr[i].getRadius();
		}
	}
	const char ch = 65 + (res[tmp].getrCol() * (currentRadius + 1));

	time_t rawtime;
	rawtime = (const time_t)res[tmp].getrID();
	cout << "Reservation with code: " << resCode << " ,Seat: " << ch
		<< (res[tmp ].getrRow() * (currentRadius + 1)) + 1 << " In movie at " <<  ctime(&rawtime);
	}