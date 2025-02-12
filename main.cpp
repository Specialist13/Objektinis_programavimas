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
        med = double((pazymiai[pazymiai.size()/2 - 1] + pazymiai[pazymiai.size()/2])) / 2.0;
    } else {
        med = pazymiai[pazymiai.size()/2];
    }
    
    med = med*0.4 + egzaminas*0.6;
    return med;
}

void isvestis (vector<Stud> studentai){
    cout << std::left<<std::setw(20) <<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(20)<<"Galutinis (Vid.)"<<std::setw(20)<<"/ Galutinis (Med.)\n"<<"-----------------------------------------------------------------\n";
    for (auto x:studentai){
        cout << std::left<<std::setw(20)<< x.vardas << std::setw(20)<< x.pavarde << std::setw(20)<< std::fixed << std::setprecision(2) <<vidurkis(x.pazymiai, x.egzaminas) << std::setw(20)<<mediana(x.pazymiai, x.egzaminas)<< endl;
    }
}

void ranka (Stud &laikinas, vector<Stud> &studentai){
    cout<<"Veskite duomenis apie studentus. Kai norėsite baigti, įveskite 'n' kaip studento vardą.\n";
    while (laikinas.vardas!="n"){
        cout << "Iveskite studento varda: ";
        cin >> laikinas.vardas;
        if (laikinas.vardas=="n"){
            break;
        }
        cout << "Iveskite studento pavarde: ";
        cin >> laikinas.pavarde;
        cout << "Iveskite, kiek studentas gavo pazymiu: ";
        int n;
        cin>>n;
        for (int j=0; j<n; j++){
            cout << "Iveskite pazymi: ";
            int pazymys;
            cin>>pazymys;
            laikinas.pazymiai.push_back(pazymys);
        }
        cout << "Iveskite studento egzamino pazymi: ";
        cin >> laikinas.egzaminas;
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvestis(studentai);
    studentai.clear();
}

int main(){
    Stud laikinas;
    vector<Stud> studentai;
    int rezimas=0;
    cout<<"Sveiki!\n";
    while (rezimas!=4){
        cout<<"Pasirinkite programos režimą.\n1 - Duomenų įvedimas ranka\n2 - Pažymių generavimas\n3 - Pažymių ir vardų generavimas\n4 - Baigti darbą\nIveskite pasirinkimą: ";
        cin>>rezimas;
        if (rezimas==4){
            cout<<"Viso gero!\n";
            break;
        }

        else if (rezimas==1){
            ranka(laikinas, studentai);
        }

        else if (rezimas==2){
            continue;
        }

        else if (rezimas==3){
            continue;
        }

        else {
            cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
        }        
    }
    return 0;
}