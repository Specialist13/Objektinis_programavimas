#include "headers.h"

int main(){
    Stud laikinas;
    vector<Stud> studentai;

    for (int i=0; i<1; i++){
        cout << "Iveskite studento varda: ";
        cin >> laikinas.vardas;
        cout << "\nIveskite studento pavarde: ";
        cin >> laikinas.pavarde;
        cout << "\nIveskite, kiek studentas gavo pazymiu: ";
        int n;
        cin>>n;
        for (int j=0; j<n; j++){
            cout << "\nIveskite pazymi: ";
            int pazymys;
            cin>>pazymys;
            laikinas.pazymiai.push_back(pazymys);
        }
        cout << "\nIveskite studento egzamino pazymi: ";
        cin >> laikinas.egzaminas;
        studentai.push_back(laikinas);
    }

    
}