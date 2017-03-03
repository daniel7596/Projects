#include <windows.h>
#include<iostream>
#include <ctime>
#include<iomanip>
#include<fstream>
#include<cctype>
#include "menu.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hwnd;

struct FnB
{
  int food1 = 0, food2 = 0, food3 = 0;
  int drink1 = 0, drink2 = 0;
  char discounts;
  double grandtotal = 0;
};

void display()
{
  int choice;

  menu show;

  cout << "Which record do you want to see?" << endl;
  cout << "1. Breakfast Records." << endl;
  cout << "2. Lunch Records." << endl;
  cout << "3. Dinner Records." << endl;
  cout << "4. Exit." << endl;


  do
  {
    cout << "\nPlease input your choice: ";
    cin >> choice;

    if (choice == 1)
      show.dispBreakf();
    else if (choice == 2)
      show.dispLunch();
    else if (choice == 3)
      show.dispDinner();
    else if (choice == 4)
      return;
    else  cout << "Wrong choice!!";

  } while (choice != 4);

}

void breakf()
{
  fstream infile;
  infile.open("breakfast.dat", ios::binary | ios::app | ios::out);

  FnB br;

  double A = 9.95, B = 8.95, C = 9.50, D = 1.95, E = 1.95;
  double subtotal, discount = 0, tax;
  char disc;

  menu order;
  int num, number;

  cout << "\n--------------------------------------------------------\n";
  cout << "*                      Breakfast                       *" << endl;
  cout << "--------------------------------------------------------\n";
  cout << "1.Egg Benedict .......... $9.95\n";
  cout << "2.Omelet ................ $8.95\n";
  cout << "3.Pancake ............... $9.50\n";
  cout << "4.Tea ................... $1.95\n";
  cout << "5.Coffee ................ $1.95\n";
  cout << "6.Quit\n";

  do
  {
    cout << "Input: ";
    cin >> num;

    subtotal = order.breakfast(num, br.food1, br.food2, br.food3, br.drink1, br.drink2);

  } while (num != 6);

  cout << "\n--------------------------------------------------------\n";
  cout << fixed << setprecision(2) << "Total = $" << subtotal << "\n";
  cout << "--------------------------------------------------------\n";


  cout << "Coupon?(Y/N)";
  cin >> disc;
  cout << "\n";


  if (disc == 'Y' || disc == 'y')
  {
    int check;
    do
    {

      cout << "Input Code: ";
      cin >> number;

      discount = order.discount(number, subtotal, check);

      if (check == -1)
      {

        cout << "\n--------------------------------------------------------\n";
        cout << fixed << setprecision(2) << "Final total= $" << discount << "\n";
        cout << "--------------------------------------------------------\n";
        br.grandtotal = discount;
        br.discounts = 'y';
      }

    } while (check != -1);
  }
  else
  {
    br.grandtotal = subtotal;
    br.discounts = 'n';
  }

  time_t now = time(0);
  // convert now to string form
  char* dt = ctime(&now);


  cout << setw(17) << "EAT&EAT" << setw(17) << endl;
  cout << "------------------------------" << endl;
  cout << dt;

  cout << endl;

  if (br.food1 != 0)
  {
    cout << br.food1 << "Egg Benedict" << "@9.95" << "---------" << "$ " << br.food1*A << endl;
  }

  if (br.food2 != 0)
  {
    cout << br.food2 << "Omelet" << " " << "@8.95" << "---------" << "$ " << br.food2*B << endl;
  }

  if (br.food3 != 0)
  {
    cout << br.food3 << "Pancake" << " " << "@9.50" << "---------" << "$ " << br.food3*C << endl;
  }

  if (br.drink1 != 0)
  {
    cout << br.drink1 << "Tea" << " " << "@1.95" << "-----------" << "$ " << br.drink1*D << endl;
  }

  if (br.drink2 != 0)
  {
    cout << br.drink2 << "Coffee" << " " << "@1.95" << "--------" << "$ " << br.drink2*E << endl;
  }



  tax = (br.grandtotal*(0.085));
  br.grandtotal += tax;
  if (discount != 0)
    cout << setw(40) << fixed << setprecision(2) << "Discount(50%): $" << discount << endl;
  cout << setw(40) << fixed << setprecision(2) << "Tax(8.5%): $" << tax << endl;

  cout << setw(40) << fixed << setprecision(2) << "Total: $" << br.grandtotal << endl;


  infile.write(reinterpret_cast<char *>(&br), sizeof(br));
  infile.close();
}

void lunch()
{

  fstream infile;
  infile.open("lunch.dat", ios::binary | ios::app | ios::out);

  FnB lu;
  double subtotal, discount;
  char disc;
  menu order;
  int num, number;
  int H = 7.50, S = 8.50, Sa = 8.95, T = 1.95, C = 1.95;
  double tax;

  cout << "\n--------------------------------------------------------\n";
  cout << "*                        Lunch                         *" << endl;
  cout << "--------------------------------------------------------\n";
  cout << "1.Hamburger .......... $7.50\n";
  cout << "2.Sandwich ........... $8.50\n";
  cout << "3.Salad .............. $8.95\n";
  cout << "4.Tea ................ $1.95\n";
  cout << "5.Coffee ............. $1.95\n";
  cout << "6.Quit\n";
  do
  {
    cout << "Input: ";
    cin >> num;

    subtotal = order.lunch(num, lu.food1, lu.food2, lu.food3, lu.drink1, lu.drink2);

  } while (num != 6);

  cout << "\n--------------------------------------------------------\n";
  cout << fixed << setprecision(2) << "Total = $" << subtotal << "\n";
  cout << "--------------------------------------------------------\n";

  cout << "Coupon?(Y/N)";
  cin >> disc;
  cout << "\n";

  if (disc == 'Y' || disc == 'y')
  {
    int check;
    do
    {

      cout << "Input Code: ";
      cin >> number;

      discount = order.discount(number, subtotal, check);

      if (check == -1)
      {

        cout << "\n--------------------------------------------------------\n";
        cout << fixed << setprecision(2) << "Final total= $" << discount << "\n";
        cout << "--------------------------------------------------------\n";
        lu.grandtotal = discount;
        lu.discounts = 'y';
      }

    } while (check != -1);
  }
  else
  {
    lu.grandtotal = subtotal;
    lu.discounts = 'n';
  }
  time_t now = time(0);
  // convert now to string form
  char* dt = ctime(&now);


  cout << setw(17) << "EAT&EAT" << setw(17) << endl;
  cout << "------------------------------" << endl;
  cout << dt;

  cout << endl;

  if (lu.food1 != 0)
  {
    cout << lu.food1 << "Hamburger" << "@7.50" << "---------" << "$ " << lu.food1*H << endl;
  }

  if (lu.food2 != 0)
  {
    cout << lu.food2 << "Sandwich" << " " << "$8.50" << "---------" << "$ " << lu.food2*S << endl;
  }

  if (lu.food3 != 0)
  {
    cout << lu.food3 << "Salad" << " " << "@8.95" << "---------" << "$ " << lu.food3*Sa << endl;
  }

  if (lu.drink1 != 0)
  {
    cout << lu.drink1 << "Tea" << " " << "@1.95" << "-----------" << "$ " << lu.drink1*T << endl;
  }

  if (lu.drink2 != 0)
  {
    cout << lu.drink2 << "Coffee" << " " << "@1.95" << "--------" << "$ " << lu.drink2*C << endl;
  }



  tax = (lu.grandtotal*(0.085));
  lu.grandtotal += tax;
  if (discount != 0)
    cout << setw(40) << fixed << setprecision(2) << "Discount(50%): $" << discount << endl;
  cout << setw(40) << fixed << setprecision(2) << "Tax(8.5%): $" << tax << endl;

  cout << setw(40) << fixed << setprecision(2) << "Total: $" << lu.grandtotal << endl;


  infile.write(reinterpret_cast<char *>(&lu), sizeof(lu));
  infile.close();
}

void dinner()
{

  fstream infile;
  infile.open("dinner.dat", ios::binary | ios::app | ios::out);
  FnB di;
  double subtotal, discount;
  char disc;
  menu order;
  int num, number;
  double C = 12.50, I = 13.95, F = 13.95, Te = 1.95, Co = 1.95;
  double tax;

  cout << "\n--------------------------------------------------------\n";
  cout << "*                        Dinner                        *" << endl;
  cout << "--------------------------------------------------------\n";
  cout << "1.Chicken Fried Steak ....................... $12.50\n";
  cout << "2.Italian Sausage & Chicken over pasta ...... $13.95\n";
  cout << "3.French Roasted Turkey Dinner .............. $13.95\n";
  cout << "4.Tea ....................................... $1.95\n";
  cout << "5.Coffee .................................... $1.95\n";
  cout << "6.Quit\n";
  do
  {
    cout << "Input: ";
    cin >> num;

    subtotal = order.dinner(num, di.food1, di.food2, di.food3, di.drink1, di.drink2);

  } while (num != 6);

  cout << "\n--------------------------------------------------------\n";
  cout << fixed << setprecision(2) << "Total = $" << subtotal << "\n";
  cout << "--------------------------------------------------------\n";

  cout << "Coupon?(Y/N)";
  cin >> disc;
  cout << "\n";

  if (disc == 'Y' || disc == 'y')
  {
    int check;
    do
    {

      cout << "Input Code: ";
      cin >> number;

      discount = order.discount(number, subtotal, check);

      if (check == -1)
      {

        cout << "\n--------------------------------------------------------\n";
        cout << fixed << setprecision(2) << "Final total= $" << discount << "\n";
        cout << "--------------------------------------------------------\n";
        di.grandtotal = discount;
        di.discounts = 'y';
      }

    } while (check != -1);
  }
  else
  {
    di.grandtotal = subtotal;
    di.discounts = 'n';
  }

  time_t now = time(0);
  // convert now to string form
  char* dt = ctime(&now);

  cout << endl;
  cout << "Receipt" << endl;
  cout << setw(17) << "EAT&EAT" << setw(17) << endl;
  cout << "------------------------------" << endl;
  cout << dt;

  cout << endl;

  if (di.food1 != 0)
  {
    cout << di.food1 << " Chicken Fried Steak" << "  @12.50" << "-------------------------" << "$" << di.food1*C << endl;
  }

  if (di.food2 != 0)
  {
    cout << di.food2 << " Italian Sausage & Chicken over Pasta" << "  $8.50" << "---------" << "$" << di.food2*I << endl;
  }

  if (di.food3 != 0)
  {
    cout << di.food3 << " French Roasted Turkey Dinner" << "  @13.95" << "----------------" << "$" << di.food3*F << endl;
  }

  if (di.drink1 != 0)
  {
    cout << di.drink1 << " Tea" << "  @1.95" << "-------------------------------------------" << "$" << di.drink1*Te << endl;
  }

  if (di.drink2 != 0)
  {
    cout << di.drink2 << " Coffee" << "  @1.95" << "----------------------------------------" << "$" << di.drink2*Co << endl;
  }



  tax = (di.grandtotal*(0.085));
  di.grandtotal += tax;
  if (discount != 0)
    cout << setw(52) << fixed << setprecision(2) << "Discount(50%): $" << discount << endl;
  cout << setw(53) << fixed << setprecision(2) << "Tax(8.5%): $" << tax << endl;

  cout << setw(52.5) << fixed << setprecision(2) << "Total: $" << di.grandtotal << endl;


  infile.write(reinterpret_cast<char *>(&di), sizeof(di));
  infile.close();
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow)
{


  MessageBox(hwnd, "Eat and Eat", "Welcome!", MB_OK);
  MSG  msg;
  WNDCLASS wc = { 0 };
  wc.lpszClassName = TEXT("Buttons");
  wc.hInstance = hInstance;
  wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
  wc.lpfnWndProc = WndProc;
  wc.hCursor = LoadCursor(0, IDC_ARROW);


  RegisterClass(&wc);
  CreateWindow(wc.lpszClassName, TEXT("MENU"),
    WS_OVERLAPPEDWINDOW | WS_VISIBLE,
    500, 500, 500, 200, 0, 0, hInstance, 0);

  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  time_t now = time(0);
  // convert now to string form
  char* dt = ctime(&now);
  int out = 0;

  switch (msg)
  {
  case WM_CREATE:
  {

    CreateWindow(TEXT("button"), dt, WS_CHILD | WS_VISIBLE, 0, 0, 500, 30, hwnd, (HMENU)6, 0, 0);
    CreateWindow(TEXT("button"), TEXT("Breakfast"),
      WS_VISIBLE | WS_CHILD,
      20, 50, 80, 25,
      hwnd, (HMENU)1, NULL, NULL);

    CreateWindow(TEXT("button"), TEXT("Lunch"),
      WS_VISIBLE | WS_CHILD,
      120, 50, 80, 25,
      hwnd, (HMENU)2, NULL, NULL);
    CreateWindow(TEXT("button"), TEXT("Dinner"),
      WS_VISIBLE | WS_CHILD,
      220, 50, 80, 25,
      hwnd, (HMENU)3, NULL, NULL);

    CreateWindow(TEXT("button"), TEXT("Find Record"),
      WS_VISIBLE | WS_CHILD,
      320, 50, 80, 25,
      hwnd, (HMENU)4, NULL, NULL);
    CreateWindow(TEXT("button"), TEXT("Exit"),
      WS_VISIBLE | WS_CHILD,
      140, 100, 160, 25,
      hwnd, (HMENU)5, NULL, NULL);
    break;
  }

  case WM_COMMAND:
  {
    if (LOWORD(wParam) == 1) {
      breakf();
    }

    if (LOWORD(wParam) == 2) {
      lunch();

    }
    if (LOWORD(wParam) == 3) {
      dinner();

    }
    if (LOWORD(wParam) == 4) {
      display();

    }

    if (LOWORD(wParam) == 5) {
      PostQuitMessage(0);

    }
    if (LOWORD(wParam) == 6) {
      CreateWindow(TEXT("button"), dt, WS_CHILD | WS_VISIBLE, 0, 0, 500, 30, hwnd, (HMENU)5, 0, 0);
    }

    break;
  }

  case WM_DESTROY:
  {
    PostQuitMessage(0);
    break;
  }
  }

  return DefWindowProc(hwnd, msg, wParam, lParam);
}
