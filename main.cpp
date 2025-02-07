#include "headers.h"

double vidurkis(vector<int> pazymiai, int egzaminas){
    double vid = 0;
    for (int i=0; i<pazymiai.size(); i++){
        vid += pazymiai[i];
    }
    vid = vid/pazymiai.size()*0.4 + egzaminas*0.6;
    return vid;
}

double mediana(vector<int> pazymiai, int egzaminas){
    double med = 0;
    std::sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        med = (pazymiai[pazymiai.size()/2 - 1] + pazymiai[pazymiai.size()/2]) / 2.0;
    } else {
        med = pazymiai[pazymiai.size()/2];
    }
    med = med*0.4 + egzaminas*0.6;
    return med;
}

int main(){
    Stud laikinas;
    vector<Stud> studentai;
    int m;
    cout<<"Iveskite studentu skaiciu: ";
    cin>>m;
    for (int i=0; i<m; i++){
        cout << "\nIveskite studento varda: ";
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

    cout << std::left<<std::setw(20) <<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(20)<<"Galutinis (Vid.)"<<std::setw(20)<<"/ Galutinis (Med.)\n"<<"-----------------------------------------------------------------\n";
    for (auto x:studentai){
        cout << std::left<<std::setw(20)<< x.vardas << std::setw(20)<< x.pavarde << std::setw(20)<< std::fixed << std::setprecision(2) <<vidurkis(x.pazymiai, x.egzaminas) << std::setw(20)<<mediana(x.pazymiai, x.egzaminas)<< endl;
    }
}