/*2. Ampliar el programa del ejercicio anterior, para que almacene datos de hasta 3 canciones
en un vector de estructura. Luego crear un men� que permita las opciones:

a. agregar una nueva canci�n

b. mostrar todas las canciones

c. buscar una canci�n por titulo
*/

#include <iostream>

using namespace std;

struct song {
    string artist = " ";
    string title = " ";
    int duration = 0;
    int size = 0;
};


void add_song(song *);

void show_playlist(song *);

void search_song(song *);

int main() {

    struct song song1[3];
    int option = 0;

    cout << "0) salir." << endl;
    cout << "1) Agregar una nueva cancion" << endl;
    cout << "2) Mostrar todas las canciones" << endl;
    cout << "3) Buscar una cancion por titulo" << endl;

    do {
        cout << "ingrese opcion: " << endl;
        cin >> option;
        switch (option) {
            case 1:
                add_song(song1);
                break;
            case 2:
                show_playlist(song1);
                break;
            case 3:
                search_song(song1);
                break;
            default:
                cout << "Porfavor, ingrese una opcion valida" << endl;
        }
    } while (option != 0);

    return 0;
}

void add_song(song *s) {
    for (int ii = 0; ii < 3; ii++) {
        cout << "Ingrese el artista del temaiken" << endl;
        getline(cin, s[ii].artist, '.');
        cout << "Ingrese el titulo del temaiken" << endl;
        getline(cin, s[ii].title, '.');
        cout << "Ingrese la duracion del temaiken" << endl;
        cin >> s[ii].duration;
        cout << "Ingrese el tamanio del temaiken" << endl;
        cin >> s[ii].size;
    }


}

void show_playlist(song *s) {

    for (int ii = 0; ii < 3; ii++) {
        cout << "Artista: " << s[ii].artist << endl;
        cout << "Titulo: " << s[ii].title << endl;
        cout << "Duracion: " << s[ii].duration << " segundos" << endl;
        cout << "Tamanio:  " << s[ii].size << " kb" << endl;
        cout << endl;
    }

}

void search_song(song *s) {
    string title_s = " ";

    cout << "Ingrese el titulo de la cancion que desea buscar" << endl;
    getline(cin, title_s, '.');
    for (int ii = 0; ii < 3; ii++) {
        if (s[ii].title == title_s) {
            cout << "Artista: " << s[ii].artist << endl;
            cout << "Titulo: " << s[ii].title << endl;
            cout << "Duracion: " << s[ii].duration << " segundos" << endl;
            cout << "Tamanio:  " << s[ii].size << " kb" << endl;
        }
    }
}
				
				
