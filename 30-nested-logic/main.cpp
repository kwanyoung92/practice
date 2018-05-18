#include <iostream>
using namespace std;

class Date {
	private :
		int date;
		int month;
		int year;
	public :
		Date(int date, int month, int year) : date(date), month(month), year(year) {}
		int get_date();
		int get_month();
		int get_year();
};

int Date::get_date() {
	return date;
}

int Date::get_month() {
	return month;
}

int Date::get_year() {
	return year;
}

int calculate_fine(Date actual, Date expec) {
	if(actual.get_year() - expec.get_year() > 0) return 10000;
	else if (actual.get_year() - expec.get_year() < 0) return 0;
	else if (actual.get_month() - expec.get_month() > 0) return (actual.get_month() - expec.get_month()) * 500;
	else {
		if(actual.get_date() - expec.get_date() > 0) return (actual.get_date() - expec.get_date()) * 15;
		else return 0;
	}
}


int main() {
	int actual_date = -1, actual_month = -1, actual_year = -1;
	int expec_date = -1, expec_month = -1, expec_year = -1;

	cin >> actual_date >> actual_month >> actual_year;
	cin >> expec_date >> expec_month >> expec_year;

	Date actual_Date(actual_date, actual_month, actual_year), expec_Date(expec_date, expec_month, expec_year);

	cout << calculate_fine(actual_Date, expec_Date);

	return 0;
}

