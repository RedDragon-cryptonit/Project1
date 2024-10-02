#include <iostream>
#include <cmath>

using namespace std;

double calculate_Pe(double A, double Ga) {
  if (A < 1) {
    return 4.75 * pow(A, 1.4) * pow(Ga, -0.17);
  }
  else {
    return 2.25 * pow(10, -3) * pow(A, -3.3) * pow(Ga, 0.29);
  }
}

double calculate_A(double W, double Re) {
  return W * pow(Re, 0.11);
}

int main() {
  const double Ga = 0.9 * pow(10, 5);
  const double Re = 6.1 * pow(10, 4);
  double W_values[] = { 0.1, 0.2, 0.5, 0.75, 0.85 };
  int size = sizeof(W_values) / sizeof(W_values[0]);

  cout << "W\tA\tPe" << endl;

  for (int i = 0; i < size; i++) {
    double W = W_values[i];
    double A = calculate_A(W, Re);
    double Pe = calculate_Pe(A, Ga);

    cout << W << "\t" << A << "\t" << Pe << endl;
  }

  return 0;
}