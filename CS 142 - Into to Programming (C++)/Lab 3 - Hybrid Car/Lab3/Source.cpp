#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	// EXTRA CREDIT: The hybrid would have to get ~166.66666 MPG.
	// PART ONE: USER INPUT

	const string NEG_NUM_PROMPT = "Must be a positive number. Please reenter ";
	const int YEARS_OF_OWNERSHIP = 5;

	cout << "\nHow many miles do you drive in a year? ";
	int miles;
	cin >> miles;
	if (miles <= 0) {
		cout << NEG_NUM_PROMPT << "number of miles: ";
		cin >> miles;
	}

	cout << "\nWhat is the estimated price of a gallon of gas during the 5 years of ownership? ";
	double gas_price;
	cin >> gas_price;
	if (gas_price <= 0) {
		cout << NEG_NUM_PROMPT << "the estimated price of gas: ";
		cin >> gas_price;
	}

	cout << "\nWhat is the initial cost of a hybrid car?";
	int hybrid_cost;
	cin >> hybrid_cost;
	if (hybrid_cost <= 0) {
		cout << NEG_NUM_PROMPT << "the initial cost of a hybrid car: ";
		cin >> hybrid_cost;
	}

	cout << "\nWhat is the efficiency of the hybrid car (mpg)?";
	double hybrid_mpg;
	cin >> hybrid_mpg;
	if (hybrid_mpg <= 0) {
		cout << NEG_NUM_PROMPT << "the efficiency of a hybrid car: ";
		cin >> hybrid_mpg;
	}

	cout << "\nWhat is the estimated resale value for a hybrid after 5 years (dollar amount)?";
	int hybrid_resale;
	cin >> hybrid_resale;
	if (hybrid_resale <= 0) {
		cout << NEG_NUM_PROMPT << "the resale value of a hybrid car: ";
		cin >> hybrid_resale;
	}

	cout << "\nWhat is the initial cost of a non-hybrid car?";
	int non_hybrid_cost;
	cin >> non_hybrid_cost;
	if (non_hybrid_cost <= 0) {
		cout << NEG_NUM_PROMPT << "the initial cost of a non-hybrid car: ";
		cin >> non_hybrid_cost;
	}
	
	cout << "\nWhat is the efficiency of the non-hybrid car (mpg)?";
	double non_hybrid_mpg;
	cin >> non_hybrid_mpg;
	if (non_hybrid_mpg <= 0) {
		cout << NEG_NUM_PROMPT << "the efficiency of a non-hybrid car: ";
		cin >> non_hybrid_mpg;
	}
	
	cout << "\nWhat is the estimated resale value for a non-hybrid after 5 years (dollar amount)?";
	int non_hybrid_resale;
	cin >> non_hybrid_resale;
	if (non_hybrid_resale <= 0) {
		cout << NEG_NUM_PROMPT << "the resale value of a non-hybrid car: ";
		cin >> non_hybrid_resale;
	}
	
	cout << "\nAre you minimizing gas consumption or total cost (enter 'Gas' or 'Total')?";
	string criterion;
	cin >> criterion;

	// PART 2: OUTPUT COSTS
	
	// HYBRID
	double hybrid_gas_consumption = (miles * YEARS_OF_OWNERSHIP) / hybrid_mpg;
	double hybrid_total_cost = (hybrid_gas_consumption * gas_price) + (hybrid_cost - hybrid_resale);

	// NON-HYBRID
	double non_hybrid_gas_consumption = (miles * YEARS_OF_OWNERSHIP) / non_hybrid_mpg;
	double non_hybrid_total_cost = (non_hybrid_gas_consumption * gas_price) + (non_hybrid_cost - non_hybrid_resale);

	if (criterion == "Gas") {
		if (hybrid_gas_consumption < non_hybrid_gas_consumption) {
			cout << "\n\nHybrid" << "\nTotal gallons consumed: " << hybrid_gas_consumption << "\nTotal cost of owning car: " << hybrid_total_cost;
			cout << "\n\nNon-Hybrid" << "\nTotal gallons consumed: " << non_hybrid_gas_consumption << "\nTotal cost of owning car: " << non_hybrid_total_cost;
		}
		else {
			cout << "\n\nNon-Hybrid" << "\nTotal gallons consumed: " << non_hybrid_gas_consumption << "\nTotal cost of owning car: " << non_hybrid_total_cost;
			cout << "\n\nHybrid" << "\nTotal gallons consumed: " << hybrid_gas_consumption << "\nTotal cost of owning car: " << hybrid_total_cost;
		}
	}

	if (criterion == "Total") {
		if (hybrid_total_cost < non_hybrid_total_cost) {
			cout << "\n\nHybrid" << "\nTotal gallons consumed: " << hybrid_gas_consumption << "\nTotal cost of owning car: " << hybrid_total_cost;
			cout << "\n\nNon-Hybrid" << "\nTotal gallons consumed: " << non_hybrid_gas_consumption << "\nTotal cost of owning car: " << non_hybrid_total_cost;
		}
		else {
			cout << "\n\nNon-Hybrid" << "\nTotal gallons consumed: " << non_hybrid_gas_consumption << "\nTotal cost of owning car: " << non_hybrid_total_cost;
			cout << "\n\nHybrid" << "\nTotal gallons consumed: " << hybrid_gas_consumption << "\nTotal cost of owning car: " << hybrid_total_cost << endl;
		}
	}

	system("pause");

	return 0;
}