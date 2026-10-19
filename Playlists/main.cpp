#include <iostream>
#include "Playlist.h"
using namespace std;


int main() {
    string playlistTitle;
    Playlist songPlaylist;
    int menuInput = 0;

    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    cout << endl;
    songPlaylist.EnterTitle(playlistTitle);

    do {
        menuInput = songPlaylist.PrintMenu();
    }

    while (menuInput != 1);

    return 0;
}