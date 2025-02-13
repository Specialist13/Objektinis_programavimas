#include "headers_vector.h"

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
    cout << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)\n"<<"-----------------------------------------------------------------\n";
    for (auto x:studentai){
        cout << std::left<<std::setw(25)<< x.vardas << std::setw(25)<< x.pavarde << std::setw(25)<< std::fixed << std::setprecision(2) <<vidurkis(x.pazymiai, x.egzaminas) << std::setw(25)<<mediana(x.pazymiai, x.egzaminas)<< endl;
    }
}

int skaiciu_ivesties_tikrinimas(string &tekstas) {
    int reiksme;
    while (true) {
        cout << tekstas;
        cin >> reiksme;
        if (cin.fail()) {
            cout << "Įveskite tinkamą skaičių!\n";
            cin.clear();
            cin.ignore();
        }
        else {
            cin.ignore();
            return reiksme;
        }
    }
}

void ranka (Stud &laikinas, vector<Stud> &studentai){
    string tekstas;
    cout<<"Veskite duomenis apie studentus. Kai norėsite baigti, įveskite 'n' kaip studento vardą.\n";
    while (laikinas.vardas!="n"){
        cout << "Įveskite studento vardą: ";
        cin >> laikinas.vardas;
        if (laikinas.vardas=="n"){
            break;
        }
        cout << "Įveskite studento pavardę: ";
        cin >> laikinas.pavarde;
        cout<<"Veskite jo pažymius. Kai norėsite baigti, įveskite '0'.\n";
        while (true){
            tekstas="Įveskite pažymį: ";
            int pazymys=skaiciu_ivesties_tikrinimas(tekstas);
            if (pazymys==0 && laikinas.pazymiai.size()==0){
                cout<<"Studentas turi turėti bent vieną pažymį. Bandykite dar kartą.\n";
                continue;
            }
            else if (pazymys==0){
                break;
            }
            else if (pazymys<0 || pazymys>10){
                cout<<"Neteisingas pažymys. Bandykite dar kartą.\n";
                continue;
            }
            laikinas.pazymiai.push_back(pazymys);
        }
        tekstas="Įveskite studento egzamino pažymį: ";
        laikinas.egzaminas=skaiciu_ivesties_tikrinimas(tekstas);
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvestis(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}

void pazymiu_generavimas (Stud &laikinas, vector<Stud> &studentai){
    srand(time(NULL));

    cout<<"Veskite duomenis apie studentus. Kai norėsite baigti, įveskite 'n' kaip studento vardą.\n";
    while (laikinas.vardas!="n"){
        cout << "Įveskite studento vardą: ";
        cin >> laikinas.vardas;
        if (laikinas.vardas=="n"){
            break;
        }
        cout << "Įveskite studento pavardę: ";
        cin >> laikinas.pavarde;
        int n=rand()%10+1;
        for (int j=0; j<n; j++){
            int pazymys=rand()%10+1;
            laikinas.pazymiai.push_back(pazymys);
        }
        laikinas.egzaminas=rand()%10+1;;
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvestis(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}

void visko_generavimas (Stud &laikinas, vector<Stud> &studentai){
    srand(time(NULL));

    vector<string> vyriskiVardai = {
        "Jonas", "Petras", "Marius", "Tadas", "Rokas", "Darius", "Arnas", "Justas", "Edvinas", "Tomas",
        "Paulius", "Simas", "Lukas", "Andrius", "Rytis", "Ernestas", "Giedrius", "Mantas", "Deividas", "Vilius",
        "Mindaugas", "Martynas", "Saulius", "Vytautas", "Tautvydas", "Sigitas", "Algirdas", "Gintaras", "Julius", "Remigijus",
        "Kestas", "Vaidotas", "Audrius", "Augustas", "Nerijus", "Gediminas", "Raimundas", "Juozas", "Dainius", "Arvydas",
        "Evaldas", "Zygimantas", "Vytenis", "Laurynas", "Arminas", "Rolandas", "Alvydas", "Laimonas", "Dominykas", "Tautvilas"
    };
    
    vector<string> moteriskiVardai = {
        "Ona", "Ieva", "Lina", "Egle", "Asta", "Rima", "Greta", "Aiste", "Monika", "Laura",
        "Jurgita", "Dovile", "Karolina", "Viktorija", "Gabija", "Sandra", "Vaida", "Aurelija", "Kristina", "Evelina",
        "Ruta", "Egle", "Aiste", "Indre", "Diana", "Viktorija", "Marija", "Aldona", "Gintare", "Alina",
        "Birute", "Rita", "Raimonda", "Virginija", "Irena", "Jolanta", "Solveiga", "Vilma", "Lijana", "Agnė",
        "Saulė", "Nida", "Grazina", "Danutė", "Liuda", "Daiva", "Jadvyga", "Sigita", "Jonė", "Vaida"
    };
    
    vector<string> vyriskosPavardes = {
        "Kazlauskas", "Petrauskas", "Jankauskas", "Paulauskas", "Butkus", "Navickas", "Sabonis", "Rimkus", "Grigas", "Urbonas",
        "Brazinskas", "Šimkus", "Pocius", "Žukauskas", "Daukantas", "Blaževičius", "Stankūnas", "Grybauskas", "Vaičiulis", "Vaitkus",
        "Rutkauskas", "Tamulis", "Kudirka", "Bagdonas", "Pavardenis", "Morkūnas", "Noreika", "Dapkus", "Žilinskas", "Venckus",
        "Kairys", "Janušaitis", "Andriuškevičius", "Šimaitis", "Mockus", "Vaitkevičius", "Matulionis", "Aleknavičius", "Valančius", "Račkauskas",
        "Giedraitis", "Petkevičius", "Radzevičius", "Žiogas", "Kalvaitis", "Baranauskas", "Masiulis", "Gervė", "Balčiūnas", "Mačiulis"
    };
    
    vector<string> moteriskosPavardes = {
        "Kazlauskaitė", "Petrauskaitė", "Jankauskaitė", "Paulauskaitė", "Butkutė", "Navickaitė", "Sabonytė", "Rimkutė", "Grigaitė", "Urbonaitė",
        "Brazinskaitė", "Šimkutė", "Pociūtė", "Žukauskaitė", "Daukantaitė", "Blaževičiūtė", "Stankūnaitė", "Grybauskaitė", "Vaičiulienė", "Vaitkienė",
        "Rutkauskaitė", "Tamulytė", "Kudirkaitė", "Bagdonaitė", "Morkūnaitė", "Noreikaitė", "Dapkutė", "Žilinskaitė", "Venckutė", "Kairytė",
        "Janušaitė", "Andriuškevičiūtė", "Šimaitė", "Mockutė", "Vaitkevičiūtė", "Matulionytė", "Aleknavičiūtė", "Valančiūtė", "Račkauskaitė", "Giedraitė",
        "Petkevičiūtė", "Radzevičiūtė", "Žiogaitė", "Kalvaitė", "Baranauskaitė", "Masiulytė", "Balčiūnaitė", "Mačiulytė", "Gervaitė", "Daukšytė"
    };

    int k=rand()%10+1;
    for (int i=0; i<k; i++){
        int lytis=rand()%2, v=rand()%50, p=rand()%50;
        if (lytis==0){
            laikinas.vardas=vyriskiVardai[v];
            laikinas.pavarde=vyriskosPavardes[p];
        }
        else {
            laikinas.vardas=moteriskiVardai[v];
            laikinas.pavarde=moteriskosPavardes[p];
        }
        int n=rand()%10+1;
        for (int j=0; j<n; j++){
            int pazymys=rand()%10+1;
            laikinas.pazymiai.push_back(pazymys);
        }
        laikinas.egzaminas=rand()%10+1;;
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvestis(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}

int main(){
    Stud laikinas;
    vector<Stud> studentai;
    int rezimas=0;
    cout<<"Sveiki!\n";
    while (rezimas!=4){
        string tekstas="Pasirinkite programos režimą.\n1 - Duomenų įvedimas ranka\n2 - Pažymių generavimas\n3 - Pažymių ir vardų generavimas\n4 - Baigti darbą\nIveskite pasirinkimą: ";
        rezimas=skaiciu_ivesties_tikrinimas(tekstas);
        if (rezimas==4){
            cout<<"Viso gero!\n";
            break;
        }

        else if (rezimas==1){
            ranka(laikinas, studentai);
        }

        else if (rezimas==2){
            pazymiu_generavimas(laikinas, studentai);
        }

        else if (rezimas==3){
            visko_generavimas(laikinas, studentai);
        }

        else {
            cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
        }        
    }
    return 0;
}