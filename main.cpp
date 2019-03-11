#include <iostream>
#include <math.h>
#include "Funktionen.h"

using namespace std;

int main()
{

// Variablendeklarierung
int n_seg = 0;
int w_seg;
// Head
cout << "Druckverlustrechner für Rohrstrecken mit dem Medium Luft  v1.0" << endl << endl;
cout << "Bitte geben Sie an, aus wie vielen Segmenten Ihre Rohrstrecke besteht" << endl << endl;

cout << endl;

cin >> n_seg;
double Druckarray[n_seg];

cout << endl;

cout << "Wählbare Rohreinbauelemente: " << endl << endl;
cout << "Siehe Handbuch für genaue Teildefinition!" << endl << endl << endl;
cout << "1: Rohreinlauf" << endl << endl;
cout << "2: Rohrauslauf" << endl << endl;
cout << "3: plötzliche Rohrerweiterung" << endl << endl;
cout << "4: Diffusor" << endl << endl;
cout << "5: Konfusor" << endl << endl;
cout << "6: plötzliche Rohrverengung" << endl << endl;
cout << "7: Düse" << endl << endl;
cout << "8: Krümmer" << endl << endl;
cout << "9: Kniestück" << endl << endl;
cout << "10: Dehnungsausgleicher" << endl << endl;
cout << "11: Regelarmatur" << endl << endl;
cout << "12: gerader Rohrabschnitt" << endl << endl;

// Programmstart
cout << "Bitte wählen sie Ihr erstes Streckensegment aus!" << endl << endl;

cin >> w_seg;























/*int i;

for (i=0; i<n_seg; i++)
{
  Druckarray[i] = 2;
}

for (i=0; i<n_seg; i++)
{
cout << Druckarray[i] << endl;
}
cout << "Bitte wählen sie Ihr erstes Streckensegment aus!" << endl;
*/



}
