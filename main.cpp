#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

/*
------------------------------
C++ Midterm
Travel Expense Program 
By Jack Kelly & Matthew Golab
( 12 / 10 / 2019 )
------------------------------
*/


// global variables (can be accessed/changed by any function)

string name = "";
int numDays = 0;
double airFare = 0.0;
double arriveHour = 0.0;
double departHour = 0.0;
bool rental;
double nightlyHotelRate = 0.0;

// total catagory cost for each expense catagory ( program output )
double carRentalCost = 0.0;
double totalMileage = 0.0;
double totalParking = 0.0;
double totalParkingCostAllowed = 0.0;
double totalTaxiCost = 0.0;
double totalTaxiCostAllowed = 0.0;
double totalConferenceFees = 0.0;
double totalHotel = 0.0;
double totalHotelCostAllowed = 0.0;
double totalMeals = 0.0;
double totalMealsAllowed = 0.0;
int taxiDays = 0;

//constants for the cost of things that vary based on miles driven or days spent on the trip
const double vehicleAllowancePerMile = 0.58;
const double allowedParkingFeesPerDay = 12.00;
const double allowedTaxiFeesPerDay = 40.00;
const double allowedHotelFeesPerDay = 90.00;

// function prototypes for each function
void getName();
void depart();
void arrive();
void numOfDays();
void airfare();
void taxiRides();
void hotelStay();
void parkingFeesf();
void conferenceFeesf();
void breakfastf();
void lunchf();
void dinnerf();

// deals with the amount of car costs
void privateCar();
void milesDrivenf();
void carRental();

// check weather or not meals were eaten and their cost
void checkDepartMeals();
void checkArriveMeals();

//generate the expense report with the correct formatting 
void generateReport();

int main() {

 cout << setprecision(2) << fixed;
                  

 // cout a formatted box with program information.
 cout << endl << "|-----------------------------|" << endl << "|      C++ Midterm 2018       |" << endl << "|                             |" << endl << "| By: Jack Kelly & Matt Golab |" << endl << "|-----------------------------|" << endl << endl;

 // collect information to generate expense report.

 getName();
 numOfDays(); 
 depart(); 
 arrive(); 
 airfare(); 
 carRental(); 
 milesDrivenf(); 
 parkingFeesf();
 taxiRides();
 conferenceFeesf();
 hotelStay();


 // set limit on costs that allow 'x' amount of $ per day to be spent on them.

 totalTaxiCostAllowed = ( allowedTaxiFeesPerDay * numDays ); 

 totalParkingCostAllowed = (allowedParkingFeesPerDay * numDays ); 

 totalHotelCostAllowed = ( allowedHotelFeesPerDay * ( (numDays - 1) ) ) ; // reason for -1 is that no hotel will be paid for on the last day of the trip.
 
 totalHotel = ( nightlyHotelRate * ( (numDays - 1) ) ); // reason for -1 is that no hotel will be paid for on the last day of the trip. 


 // if the employee spends less than allowed, the amount allowed is set equal to the amount spent.

 if ( totalTaxiCost < totalTaxiCostAllowed ){
   totalTaxiCostAllowed = totalTaxiCost;
 }

 if ( totalHotel < totalHotelCostAllowed ){
   totalHotelCostAllowed = totalHotel;
 }

 if ( totalParking < totalParkingCostAllowed ){
   totalParkingCostAllowed = totalParking;
 }


 // for loop used for collecting values that differ by day (breakfast, luunch, dinner)
for ( int i = 1; i <= numDays; i++ ) {
  cout << endl << "Day " << i << endl << "-----"<< endl;


  // check what day of the trip it is, as on the first and last days of the trip, only certain meals are allowed. 

  if ( i == 1 ){
    checkDepartMeals(); // check if a meal was paid for by the company upon departure to trip
  }
  else if ( i == numDays ){
     checkArriveMeals(); // check if a meal was paid for by the company upon arrival home
  }
  else{ 
  breakfastf();
  lunchf();
  dinnerf();
  }

  cout << endl;
 }

 generateReport();

 cout << "Expense Report Generated!";
}

void getName(){

  cout << "Employee Name: ";
  getline(cin,name);

}

void arrive( ){

  cout << "What time did you arrive home on the last day of the trip? - (24 Hour HH.MM)\nTime: "; 
  cin >> arriveHour;

  while ( arriveHour > 24.0 || arriveHour < 0.0 ){
    cout << "Invalid time. Please enter time: ";
    cin >> arriveHour;
  }

}

void depart(){
  
  cout << "What time did you depart on the first day of the trip? - (24 Hour HH.MM)\nTime: ";
  cin >> departHour;

  while ( departHour > 24.0 || departHour < 0.0 ){
    cout << "Invalid time. Please enter time: ";
    cin >> departHour;
  }

}


void conferenceFeesf(){

  cout << "Enter amount of any registration fees : $";
  cin >> totalConferenceFees;

  while ( totalConferenceFees < 0 ){
    cout <<"Invalid amount. Enter the amount of any registration fees: $";
    cin >> totalConferenceFees;
  }

}

void parkingFeesf(){

  cout << "Enter amount of any parking fees : $";
  cin >> totalParking;

  while ( totalParking < 0 ){
    cout <<"Invalid amount. Enter the amount of any parking fees: $";
    cin >> totalParking;
  }

}

void milesDrivenf(){

 cout << "How many miles did you drive in your personal vehicle?: ";
 double milesDriven;
  cin >> milesDriven;

 while (milesDriven <= 0)
 {
   cout << "Invalid entry. Please enter your total mileage:";
   cin >> milesDriven;
 }

  totalMileage = (milesDriven * vehicleAllowancePerMile);

}

void numOfDays()
{
  cout << "How many days were you on the trip?: ";
  cin >> numDays;

  while (numDays < 1)
  {
    cout << "Invalid number of days. How many days were you on the trip? : ";
    cin >> numDays;
  }
}

void  airfare()
{
  cout << "Enter amount spent on round trip airfare : $";
  cin >> airFare;

  while (airFare < 0){
  cout << "Invalid dollar amount. Please enter the amount spent on round trip airfare: $";
  cin >> airFare;
  }
}

void carRental(){

  cout << "Enter amount of any car rentals : $";
  cin >> carRentalCost;

  while ( carRentalCost < 0 ){
    cout <<"Invalid amount for car rental. Enter the amount of any car rentals: $";
    cin >> carRentalCost;
  }
}

void taxiRides(  )
{
  cout << "Please enter your total taxi fees. (Anything over $40 / day is on you): $";
  cin >> totalTaxiCost;
  
  while (totalTaxiCost < 0)
  {
    cout << "Invaid taxi amount. Please enter your total taxi fees:";
    cin >> totalTaxiCost;
  }
}

void hotelStay()
{
  cout << "Please enter the nightly hotel rate. (Anything over 90$/night is on you): $";
  cin >> nightlyHotelRate;

  while(nightlyHotelRate < 0)
  {
    cout << "Invalid hotel stay amount. Please enter the nightly hotel rate: $";
    cin >> nightlyHotelRate;
  }
}


void breakfastf(){

    cout << "How much was spent at breakfast? : $";
    double bfCost;
    cin >> bfCost;

    while ( bfCost < 0 ){
      cout << "Invalid amount. How much was spent at breakfast?: $";
      cin >> bfCost;
    }
    totalMeals += bfCost; 

    // incriment total amount of meal costs allowed. if the meal is cheaper than the allowed cost, only add the cost of the meal to the allowed cost.
    if ( bfCost < 18.00 ){
      totalMealsAllowed += bfCost;
    }
    else { 
      totalMealsAllowed += 18.00;
    }
}

void lunchf(){

    cout << "How much was spent at lunch?: $";
    double lunchCost;
    cin >> lunchCost;
    
    while ( lunchCost < 0 ){
      cout << "Invalid amount. How much was spent at lunch?: $";
      cin >> lunchCost;
    }
    totalMeals += lunchCost; 

    // incriment total amount of meal costs allowed. if the meal is cheaper than the allowed cost, only add the cost of the meal to the allowed cost.
    if ( lunchCost < 12.00 ){
      totalMealsAllowed += lunchCost;
    }
    else { 
      totalMealsAllowed += 12.00;
    }
}

void dinnerf(){

    cout << "How much was spent at dinner?: $";
    double dinnerCost;
    cin >> dinnerCost;
    
    while ( dinnerCost < 0 ){
      cout << "Invalid amount. How much was spent at dinner?: $";
      cin >> dinnerCost;
    }
    totalMeals += dinnerCost; 

    // incriment total amount of meal costs allowed. if the meal is cheaper than the allowed cost, only add the cost of the meal to the allowed cost.
    if ( dinnerCost < 20.00 ){
      totalMealsAllowed += dinnerCost;
    }
    else {
      totalMealsAllowed += 20.00;
    }
}

void checkDepartMeals(){

  if ( departHour < 7.0 ){
  breakfastf();
  lunchf();
  dinnerf();
  }
  else if ( departHour < 12.0 ){
    lunchf();
     dinnerf();
  }
  else if (departHour < 18.0 ){
     dinnerf();
  }
  else { 
    cout << "No meals allowed on day of departure if departure time is past 18.00 (HH.MM)" << endl;
 }
}

void checkArriveMeals(){

  if ( arriveHour > 19.0 ){
    breakfastf();
    lunchf();
    dinnerf();
  }
  else if ( arriveHour > 13.0 ){
    breakfastf();
    lunchf();
  }
  else if ( arriveHour > 8.0 ){
    breakfastf();
  }
  else { 
    cout << "No meals allowed on day of arrival if arrival time is before 8.00 (HH.MM)" << endl;
  }
}

void generateReport(){

  ofstream myFile; // create out file stream called "myFile".

  myFile.open("Expense_Report.txt"); // open the file called "Expense_Report.txt" - if it doesnt exist it will be created.

  myFile << setprecision(2) << fixed; // set precision as 2 so program shows 2 decimal places for every double value.

  // writing the results to the file.

  myFile << "Employee Expense Report for " << name << endl;
  
  myFile << endl; // skip a line.

  myFile << "Total Days: " << numDays << endl;
  myFile << "Departure time: " << departHour << " (24 Hour HH.MM)      Return time: " << arriveHour << " (24 Hour HH.MM)" << endl;

  myFile << endl; // skip a line.

  myFile << setw(25) << right << "Spent" << setw(15) << right << "Allowed" << endl;
  myFile << setw(25) << right << "-----" << setw(15) << right << "-------" << endl;


  myFile << setw(15) << left << "AirFare" << setw(10) << right << airFare << setw(15) << right << airFare << endl;

  myFile << setw(15) << left << "Car Rental" << setw(10) << right << carRentalCost << setw(15) << right << carRentalCost << endl;
  
  myFile << setw(15) << left << "Mileage" << setw(10) << right << totalMileage << setw(15) << right << totalMileage << endl;

  myFile << setw(15) << left << "Parking" << setw(10) << right << totalParking << setw(15) << right << totalParkingCostAllowed << endl;

  myFile << setw(15) << left << "Taxis" << setw(10) << right << totalTaxiCost << setw(15) << right << totalTaxiCostAllowed << endl;

  myFile << setw(15) << left << "Registration" << setw(10) << right << totalConferenceFees  << setw(15) << right << totalConferenceFees << endl;

  myFile << setw(15) << left << "Hotels" << setw(10) << right << totalHotel  << setw(15) << right << totalHotelCostAllowed << endl;

  myFile << setw(15) << left << "Meals" << setw(10) << right << totalMeals  << setw(15) << right << totalMealsAllowed << endl;

  myFile << endl; // skip a line.

  double totalSpent = ( airFare + carRentalCost + totalMileage + totalParking + totalTaxiCost + totalConferenceFees + totalHotel + totalMeals );

  double totalAllowed = ( airFare + carRentalCost + totalMileage + totalParkingCostAllowed + totalTaxiCostAllowed + totalConferenceFees +  totalHotelCostAllowed + totalMealsAllowed);

  myFile << setw(15) << left << "Totals" << setw(10) << right << totalSpent << setw(15) << right << totalAllowed;

  myFile.close(); // closes and saves file.
}

