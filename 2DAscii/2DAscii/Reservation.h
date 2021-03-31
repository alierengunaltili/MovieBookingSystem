//Ali Eren Günaltýlý 21801897 Section 01 CS
#pragma once

class Reservation {
public:
	Reservation();
	Reservation(const long id, const int row, const int col);
	int getrRow();
	void setrRow(int r);
	int getrCol();
	void setrCol(int c);
	void setrID(long i);
	long getrID();
private:
	int relatedRow;
	int relatedCol;
	long relatedId;
};