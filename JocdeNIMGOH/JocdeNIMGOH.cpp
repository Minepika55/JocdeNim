#include <iostream>

#include <vector>

using namespace std;

int main() {
    vector < int > piles = {
      3, 4, 5
    }; //Inicialitza les piles amb 3, 4 i 5 pedres respectivament.
    int jugadorActual = 1; //Jugador 1 comenca primer.
    int menu;

    cout << "***Benvingut al joc del Nim, comencem el joc, l'ordre sera el seguent, primer el Jugador 1 i el Jugador 2 segon***" << endl;
    cout << endl;

    do {
        cout << "1. VS Jugador" << endl;
        cout << "2. VS Maquina" << endl;
        cout << "3. Sortir" << endl;
        cout << "Siusplau tria una opcio: ";
        cin >> menu;

        switch (menu) {
        case 1:
            while (true) {
                int pilaEscollida, pedresTretes;//Inicialitzo les variables per triar les piles i les pedres.
                cout << "***Ara hi ha les seguents pedres a les tres piles " << piles[0] << " Pedres a la Pila 1  " << piles[1] << " Pedres a la Pila 2  " << piles[2] << " Pedres a la Pila 3  " << "***" << endl;//Aqui es mostren les pedres de cada pila.
                do {
                cout << "***Jugador " << jugadorActual << ", trieu una pila i el nombre de pedres que vols treure, nomes pots treure fins a 3 pedres a la vegada.***" << endl;
                cin >> pilaEscollida >> pedresTretes;//Demano que vol triar a el jugador.
                } while (pedresTretes > 3);//Si el jugador intenta treure mes de tres pedres simplement repetim la seleccio de pedres i piles de nou.

                //Assegura que el jugador no intenta treure més pedres del que hi ha a la pila.
                if (pedresTretes > piles[pilaEscollida - 1]) {
                    cout << "No pots treure mes pedres de les que hi ha a la pila!" << endl;
                    continue;
                }

                //Treu les pedres de la pila escollida.
                piles[pilaEscollida - 1] -= pedresTretes;
                cout << "***Ara hi ha " << piles[pilaEscollida - 1] << " pedres a la pila " << pilaEscollida << "***" << endl;
                cout << endl;

                //Comprova si hi ha alguna pila sense pedres.
                bool guanyador = true;
                for (int i = 0; i < piles.size(); i++) {
                    if (piles[i] > 0) {
                        guanyador = false;
                        break;
                    }
                }

                //Si alguna pila te pedres canvia el jugador actual.
                if (!guanyador) {
                    jugadorActual = 3 - jugadorActual;
                }
                else {
                    //Si no hi ha cap pila amb pedres el jugador actual guanya la partida.
                    cout << "***Has guanyat jugador " << jugadorActual << "!***" << endl;
                    break;
                }
            }
            break;
        case 2:
            srand(static_cast <unsigned int> (time(0))); //Creo la seed.
            while (true) {
                int pilatriada, pedrestriades;//Inicialitzo les variables per triar les piles i les pedres.
                cout << "***Ara hi ha les seguents pedres a les tres piles " << piles[0] << " Pedres a la Pila 1  " << piles[1] << " Pedres a la Pila 2  " << piles[2] << " Pedres a la Pila 3  " << "***" << endl;//Aqui es mostren les pedres de cada pila.

                if (jugadorActual == 1){
                    do {
                    cout << "***Jugador " << jugadorActual << ", trieu una pila i el nombre de pedres que vols treure, nomes pots treure fins a 3 pedres a la vegada.***" << endl;
                    cin >> pilatriada >> pedrestriades;//Demano que vol triar a el jugador.
                    } while (pedrestriades > 3);//Si el jugador intenta treure mes de tres pedres simplement repetim la seleccio de pedres i piles de nou.
                }
                else {
                    //L'ordinador tria que fer.
                    pilatriada = rand() % piles.size()+1; //Tria una pila aleatoria.
                    pedrestriades = rand() % piles[pilatriada-1]+1; //Tria les pedres.
                }
                //Assegura que el jugador no intenta treure més pedres del que hi ha a la pila.
                if (pedrestriades > piles[pilatriada - 1]) {
                    cout << "No pots treure mes pedres de les que hi ha a la pila!" << endl;
                    continue;
                }



                //Amb aixp no intentara treure mes pedres de les que hi ha en les piles.
                if (pedrestriades > piles[pilatriada-1]) {
                    pedrestriades = piles[pilatriada-1];
                }

                //Treu les pedres de la pila escollida.
                piles[pilatriada-1] -= pedrestriades;
                cout << "***Ara hi ha " << piles[pilatriada-1] << " pedres a la pila " << pilatriada  << "***" << endl;
                cout << endl;

                //Comprova si hi ha alguna pila sense pedres.
                bool winner = true;
                for (int i = 0; i < piles.size(); i++) {
                    if (piles[i] > 0) {
                        winner = false;
                        break;
                    }
                }

                //Si alguna pila te pedres canvia el jugador actual.
                if (!winner) {
                    jugadorActual = 3 - jugadorActual;
                }
                else {
                    //Si no hi ha cap pila amb pedres el jugador actual guanya la partida.
                    cout << "***L'ordinador ha guanyat!***" << endl;
                    break;
                }
            }
            break;
        case 3:
            cout << "Gracies per jugar al Nim!" << endl;//Si sortim del menu poso un missatge de sortida.
            return 0;
            break;
        default:
            cout << "Opcio invalida." << endl;//I un altre missatge si es posa una opcio invalida.
            break;
        }
    } while (menu != 3);

    return 0;
}