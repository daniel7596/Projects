#include<iostream>
#include<fstream>

using namespace std;

class menu
{
public:
  double breakfast(int, int &, int&, int&, int&, int&);
  double lunch(int, int &, int&, int&, int&, int&);
  double dinner(int, int &, int&, int&, int&, int&);
  double discount(int, double, int &);
  void dispBreakf();
  void dispLunch();
  void dispDinner();
  menu();
  ~menu();

private:
  struct FnB
  {
    int food1 = 0, food2 = 0, food3 = 0;
    int drink1 = 0, drink2 = 0;
    char discounts;
    double grandtotal = 0;
  };

};

menu::~menu()
{
}

menu::menu()
{
}

void menu::dispBreakf()
{
  int num;
  fstream file;
  file.open("breakfast.dat", ios::binary | ios::in);

  if (!file)
    cout << "File is not available!";
  else {

    FnB data;
    cout << "Enter the record number you want to see: ";
    cin >> num;
    file.seekg((num - 1) * sizeof(data), ios::beg);
    file.read(reinterpret_cast<char *>(&data), sizeof(data));

    cout << "Egg Benedict: " << data.food1 << endl;
    cout << "Omelet: " << data.food2 << endl;
    cout << "Pancake: " << data.food3 << endl;
    cout << "Tea: " << data.drink1 << endl;
    cout << "Coffee: " << data.drink2 << endl;
    if (data.discounts == 'y')
      cout << "Discount = YES" << endl;
    else cout << "Discount = NO" << endl;
    cout << fixed << setprecision(2) << "Grandtotal = " << data.grandtotal;
    cout << "\n--------------------------------------------------------\n";
    file.close();
  }
}

void menu::dispLunch()
{
  int num;
  fstream file;
  file.open("lunch.dat", ios::binary | ios::in);

  if (!file)
    cout << "File is not available!";
  else {

    FnB data;
    cout << "Enter the record number you want to see: ";
    cin >> num;
    file.seekg((num - 1) * sizeof(data), ios::beg);
    file.read(reinterpret_cast<char *>(&data), sizeof(data));
    cout << "Hamburger: " << data.food1 << endl;
    cout << "Sandwich: " << data.food2 << endl;
    cout << "Salad: " << data.food3 << endl;
    cout << "Tea: " << data.drink1 << endl;
    cout << "Coffee: " << data.drink2 << endl;
    if (data.discounts == 'y')
      cout << "Discount = YES" << endl;
    else cout << "Discount = NO" << endl;
    cout << fixed << setprecision(2) << "Grandtotal = " << data.grandtotal;
    cout << "\n--------------------------------------------------------\n";
    file.close();
  }
}

void menu::dispDinner()
{
  int num;
  fstream file;
  file.open("dinner.dat", ios::binary | ios::in);

  if (!file)
    cout << "File is not available!";
  else {

    FnB data;
    cout << "Enter the record number you want to see: ";
    cin >> num;
    file.seekg((num - 1) * sizeof(data), ios::beg);
    file.read(reinterpret_cast<char *>(&data), sizeof(data));
    cout << "Chicken Fried Steak: " << data.food1 << endl;
    cout << "Italian Sausage & Chicken over pasta: " << data.food2 << endl;
    cout << "French Roasted Turkey Dinner: " << data.food3 << endl;
    cout << "Tea: " << data.drink1 << endl;
    cout << "Coffee: " << data.drink2 << endl;
    if (data.discounts == 'y')
      cout << "Discount = YES" << endl;
    else cout << "Discount = NO" << endl;
    cout << fixed << setprecision(2) << "Grandtotal = " << data.grandtotal;
    cout << "\n--------------------------------------------------------\n";

    file.close();
  }
}


double menu::breakfast(int num, int &food1, int &food2, int &food3, int &drink1, int &drink2)
{
  static double total;
  double A = 9.95, B = 8.95, C = 9.50, D = 1.95, E = 1.95;
  static int quantityA, quantityB, quantityC, quantityD, quantityE;

  int order = 0;
  switch (num)
  {
  case 1: cout << "How many order: ";
    cin >> order;


    quantityA += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityA << " Egg Benedict\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 2: cout << "How many order: ";
    cin >> order;

    quantityB += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityB << " Omelet\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 3: cout << "How many order: ";
    cin >> order;

    quantityC += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityC << " Pancake\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 4: cout << "How many order: ";
    cin >> order;

    quantityD += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityD << " Tea\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 5: cout << "How many order: ";
    cin >> order;

    quantityE += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityE << " Coffee\n";
    cout << "--------------------------------------------------------\n\n";

    break;
    break;

  case 6: num = 7;
    break;

  default: cout << "Wrong input!";
  }
  food1 = quantityA;
  food2 = quantityB;
  food3 = quantityC;
  drink1 = quantityD;
  drink2 = quantityE;
  total = (quantityA*A) + (quantityB*B) + (quantityC*C) + (quantityD*D) + (quantityE*E);

  return total;
}

double menu::lunch(int num, int &food1, int &food2, int &food3, int &drink1, int &drink2)
{
  double A = 7.50, B = 8.50, C = 8.95, D = 1.95, E = 1.95;
  static double total;
  static int quantityA, quantityB, quantityC, quantityD, quantityE;

  int order = 0;
  switch (num)
  {
  case 1: cout << "How many order: ";
    cin >> order;

    quantityA += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityA << " Hamburger\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 2: cout << "How many order: ";
    cin >> order;

    quantityB += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityB << " Sandwich\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 3: cout << "How many order: ";
    cin >> order;

    quantityC += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityC << " Salad\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 4: cout << "How many order: ";
    cin >> order;

    quantityD += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityD << " Tea\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 5: cout << "How many order: ";
    cin >> order;

    quantityE += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityE << " Coffee\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 6: num = 6;
    break;

  default: cout << "Wrong input!";
  }

  food1 = quantityA;
  food2 = quantityB;
  food3 = quantityC;
  drink1 = quantityD;
  drink2 = quantityE;
  total = (quantityA*A) + (quantityB*B) + (quantityC*C) + (quantityD*D) + (quantityE*E);
  return total;
}

double menu::dinner(int num, int &food1, int &food2, int &food3, int &drink1, int &drink2)
{
  double A = 12.50, B = 13.95, C = 13.95, D = 1.95, E = 1.95;
  static double total;
  static int quantityA, quantityB, quantityC, quantityD, quantityE;

  int order = 0;
  switch (num)
  {
  case 1: cout << "How many order: ";
    cin >> order;

    quantityA += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityA << " Chicken Fried Steak\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 2: cout << "How many order: ";
    cin >> order;

    quantityB += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityB << " Italian Sausage & Chicken over pasta \n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 3: cout << "How many order: ";
    cin >> order;

    quantityC += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityC << " French Roasted Turkey Dinner \n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 4: cout << "How many order: ";
    cin >> order;

    quantityD += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityD << " Tea\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 5: cout << "How many order: ";
    cin >> order;

    quantityE += order;

    cout << "\n--------------------------------------------------------\n";
    cout << "You order: " << quantityE << " Coffee\n";
    cout << "--------------------------------------------------------\n\n";

    break;

  case 6: num = 6;
    break;

  default: cout << "Wrong input!";
  }

  food1 = quantityA;
  food2 = quantityB;
  food3 = quantityC;
  drink1 = quantityD;
  drink2 = quantityE;
  total = (quantityA*A) + (quantityB*B) + (quantityC*C) + (quantityD*D) + (quantityE*E);
  return total;
}

double menu::discount(int number, double subtotal, int & check)
{
  const int SIZE = 10;
  int code[SIZE] = { 100102, 171923, 868285, 639274, 217492, 305729, 104925, 294640, 884433, 264102 };
  int value = -1;
  int counter = 0;
  double total;
  bool found = false;

  while (counter < SIZE && !found)
  {
    if (code[counter] == number)
    {
      found = true;
      value = counter;
    }
    counter++;
  }

  if (value == -1)
  {

    check = 0;
    cout << "Invalid!\n\n";
  }
  else
  {
    check = -1;
    cout << "Discount 50%\n";
    total = subtotal - ((subtotal)*(0.5));
  }
  return total;
}
