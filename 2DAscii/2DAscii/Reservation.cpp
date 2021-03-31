//Ali Eren Günaltýlý 21801897 Section 01 CS
#include "Reservation.h"


Reservation::Reservation() {
	setrCol(0);
	setrRow(0);
	setrID(0);
}

Reservation::Reservation(const long id,  const int row, const int col) {
	setrCol(col);
	setrRow(row);
	setrID(id);
}

void Reservation::setrCol(int c) {
	relatedCol = c;
}

void Reservation::setrRow(int r) {
	relatedRow = r;
}

int Reservation::getrCol() {
	return relatedCol;
}

int Reservation::getrRow() {
	return relatedRow;
}

long Reservation::getrID() {
	return relatedId;
}

void Reservation::setrID(long i) {
	relatedId = i;
}

