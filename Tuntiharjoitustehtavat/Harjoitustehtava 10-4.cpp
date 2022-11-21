    // 10. Tunti Viope 10 - 3
    // Struct funktion paluuarvona
    
    #include<iostream>
    #include<string>

    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;


    struct Opiskelija
    {
        string etunimi, sukunimi, opiskelijanumero;
        int opintopisteet;
    };

    // Funktio luomaan opiskelijoiden tiedot
    Opiskelija luoOpiskelija(Opiskelija &opiskelija){
        
        // Funktio viittaa tietueen taulukkoon jolloin ylimaaraisia taulukoita tai tietueita ei tule

        cout << "Anna opiskelijan etunimi: ";
        cin >> opiskelija.etunimi;

        cout << "Anna opiskelijan sukunimi: ";
        cin >> opiskelija.sukunimi;

        cout << "Anna opiskelijan opiskelijanumero: ";
        cin >> opiskelija.opiskelijanumero;

        cout << "Anna opiskelijan opintopisteet: ";
        cin >> opiskelija.opintopisteet;

        cout << endl; 

        return opiskelija;
    }

    // "const Opiskelija &opiskelija" Vain luku-oikeus tietueen tietoihin
    void tulostaOpiskelijanTiedot(const Opiskelija &opiskelija, int count){

        cout << "Opiskelijan numero " << count << " tiedot." << endl;

        cout << "Etunimi: " << opiskelija.etunimi << endl;

        cout << "Sukunimi: " << opiskelija.sukunimi << endl;

        cout << "Opiskelijanumero: " << opiskelija.opiskelijanumero << endl;

        cout << "Opintopisteet: " << opiskelija.opintopisteet << endl << endl;
        
    }

    int main() {
        setlocale(LC_ALL, "fi_FI");
        
        int opiskelijat_lkm, count = 1;

        cout << "Kuinka monelle opiskelijalle luodaan tiedot? (MAX 20): ";
        cin >> opiskelijat_lkm;
        cout << endl;

        // Luodaan tietueesta taulukko, jonka koon maarittaa "opiskelijat_lkm" 
        Opiskelija opiskelija[opiskelijat_lkm]; 

        // Luodaan taulukon paikalle i tiedot kutsumalla funktiota
        for (int i = 0; i < opiskelijat_lkm; i++)
        {
            // Kutsutaan funktiota luomaan tiedot opiskelijoille
            luoOpiskelija(opiskelija[i]);
        }

        // Kutsutaan funktiota, joka tulostaa tiedot
        for (int i = 0; i < opiskelijat_lkm; i++)
        {
            // Kutsutaan tietueen tiedoilla funktiota
            tulostaOpiskelijanTiedot(opiskelija[i], count++);

        }
        
        
        return 0;
    }
