#include<iostream>
#include<string>
#include "Playlist.h"
using namespace std;

// PlaylistNodeClass
// PlaylistNode constructor
PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    this->nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(std::string id, std::string name, std::string artist, int length, PlaylistNode* nextLoc) {
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = length;
    this->nextNodePtr = nextLoc;
}

// Accessor-------------------------------------------------------
// GetID: returns the song ID
string PlaylistNode::GetID() const {
    return uniqueID;
}

// GetSongName: returns song name
string PlaylistNode::GetSongName() const {
    return songName;
}

// GetArtistName: returns artist's name
string PlaylistNode::GetArtistName() const {
    return artistName;
}

// GetSongLength: returns duration of song (in seconds)
int PlaylistNode::GetSongLength() const {
    return songLength;
}

// GetNext(): returns address of the next node in the list
PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}
// Accessor-------------------------------------------------------

// Functions_______________________________________________________________________________
// InsertAfter: inserts the address after a specific declared address
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* tmpNext = nullptr;
    
    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tmpNext;
}

// SetNext: set a specific address as the next address
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    this->nextNodePtr = nodePtr;
}

// PrintPlaylistNode: prints information about song in current node 
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
    cout << endl;
}
// Functions_______________________________________________________________________________

// Playlist Class==========================================================================
Playlist::Playlist() {
    userInput = 'n';
    playlistTitle = "none";
    numSongs = 0;
    headSong = nullptr;
    tailSong = nullptr;
}

// EnterTitle
void Playlist::EnterTitle(string tmpTitle) {
    playlistTitle = tmpTitle;
}


// User interactive menu
int Playlist::PrintMenu() {
    string removeID;

    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;

    cin >> userInput;

    switch (userInput) {
        case 'a':
            AddMenu();
            break;
        case 'd':
        cout << "REMOVE SONG" << endl;
            RemoveSong();
            break;
        case 'c':
            cout << "CHANGE POSITION OF SONG" << endl;
            ChangeSongPos();
            break;
        case 's':
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            OutputSongByArtist();
            break;
        case 't':
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            OutputTotTime();
            break;
        case 'o':
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if (numSongs == 0) {
                cout << "Playlist is empty" << endl;
                cout << endl;
            } 
            else {
                OutputFullPlaylist();
            }
            break;
        case 'q':
            exit(0);
            break;

        default:
            cout << "Option unavailable" << endl;
            cout << endl;
    }
    return 0;
}

// Adds a new song to the end of the list
void Playlist::AddMenu() {
    string tmpID;
    string tmpName;
    string tmpArtist;
    int tmpLength;
    PlaylistNode* addingSong = nullptr;

    cout <<"ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> tmpID;
    cin.ignore();
    cout << "Enter song's name:" << endl;
    getline(cin, tmpName);
    cout << "Enter artist's name:" << endl;
    getline(cin, tmpArtist);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> tmpLength;
    cout << endl;

    numSongs++;
    addingSong = new PlaylistNode(tmpID, tmpName, tmpArtist, tmpLength);

    if (headSong == nullptr) {
        headSong = addingSong;
        // tailSong = addingSong;
        // headSong->InsertAfter(tailSong);
    } else if (tailSong == nullptr) {
        headSong->InsertAfter(addingSong);
        tailSong = addingSong;
    } else if (headSong == tailSong) {
        headSong->InsertAfter(addingSong);
        tailSong = addingSong;
    }
    else {
        tailSong->InsertAfter(addingSong);
        tailSong = addingSong;
    }
}

// OutputFullPlaylist
void Playlist::OutputFullPlaylist() {
    int i = 1;
    PlaylistNode* currSong = nullptr;

    currSong = headSong;
    while (currSong != nullptr) {
        cout << i << "." << endl;
        currSong->PrintPlaylistNode();
        currSong = currSong->GetNext();
        i++;
    }
}

// Remove a song
void Playlist::RemoveSong() {
    string removeID;
    PlaylistNode* currSong = nullptr;
    PlaylistNode* tmpNode = nullptr;
    PlaylistNode* prevSong = nullptr;

    cout << "Enter song's unique ID:" << endl;
    cin >> removeID;

    if(removeID == headSong->GetID()) {
        if (numSongs == 1) {
            cout << '"' << headSong->GetID() << '"' << " removed" << endl;
            cout << endl;
            delete headSong;
            headSong = nullptr;
            numSongs--;
            return;
        } else {
            cout << '"' << headSong->GetID() << '"' << " removed" << endl;
            cout << endl;
            tmpNode = headSong->GetNext();
            delete headSong;
            headSong = tmpNode;
            numSongs--;
            return;
        }
    }

    if (removeID == tailSong->GetID()) {
        if (numSongs == 2) {
            cout << '"' << tailSong->GetID() << '"' << " removed" << endl;
            cout << endl;
            delete tailSong;
            headSong->InsertAfter(tailSong);
            tailSong = nullptr;
            numSongs--;
            return;
        } else {
            cout << '"' << tailSong->GetID() << '"' << " removed" << endl;
            cout << endl;
            delete tailSong;
            tailSong = prevSong;
            numSongs--;
            return;
        }
    }

    currSong = headSong;

    while (currSong != nullptr) {
        if (removeID == currSong->GetID()) {
            tmpNode = currSong->GetNext();
            cout << '"' << currSong->GetSongName() << '"' << " removed" << endl;
            cout << endl;
            prevSong->SetNext(tmpNode);
            delete currSong;
        }
        prevSong = currSong;
        currSong = currSong->GetNext();
    }

    numSongs--;
}

// Change the position of a song in the playlist
void Playlist::ChangeSongPos() {
    int currPos;
    int newPos;
    int i = 1;

    // currSong is the song to be manipulated
    //  tmpNode is the song you want to change positions (aka current position input's song)
    PlaylistNode* currSong= nullptr;
    PlaylistNode* prevSong = nullptr;
    PlaylistNode* newPosPrev = nullptr;
    PlaylistNode* tmpNode = nullptr;        
    PlaylistNode* afterSong = nullptr;


    cout << "Enter song's current position:" << endl;
    cin >> currPos;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;

    if (currPos == newPos) {
        cout << "The song is already in this position" << endl;
        return;
    }

    currSong = headSong;
    while (currSong != nullptr) {
        if (i == currPos-1) {
            break;
        }
        currSong = currSong->GetNext();
        i++;
    }

    if (currPos == 1) {
        prevSong = nullptr;
        tmpNode = headSong;
    } else {
        prevSong = currSong; // Song before the one in current position
        tmpNode = prevSong->GetNext(); // Song in the current position
        afterSong = tmpNode->GetNext(); // Song after the current position
    }
    

    currSong = headSong;
    i = 1;
    while(currSong != nullptr) {
        if (i == newPos-1) {
            break;
        }
        currSong = currSong->GetNext();
        i++;
    }

    if (newPos == 1) {
        newPosPrev = nullptr;
        currSong = headSong;
    } else {
        newPosPrev = currSong; // Song before new position
        currSong = newPosPrev->GetNext(); // Song in new position
    }

    PlaylistNode* tmpSong = nullptr;
    tmpSong = new PlaylistNode(
        tmpNode->GetID(),
        tmpNode->GetSongName(),
        tmpNode->GetArtistName(),
        tmpNode->GetSongLength()
    );

    delete tmpNode;

    // headSong = first song in the playlist
    // tailSong = last song in the playlist
    // newPosPrev = song before the new position
    // currSong = song in new position
    // tmpSong = newly created song in position u want to move (points to nothing)
    // prevSong = song before tmpSong
    // afterSong = song after tmpSong

    // Moving the headSong
    if (currPos == 1) {
        headSong = headSong->GetNext();
        currSong->InsertAfter(tmpSong);
        // If headSong is moved to tailSong 
        if (newPos >= numSongs) {
            tailSong = tmpSong;
        }
    }
    // Moving the tailSong
    else if (currPos == numSongs) {
        tailSong = prevSong;
        tailSong->SetNext(nullptr);
        // If tailSong is moved to headSong
        if (newPos <= 1) {
            tmpSong->SetNext(headSong);
            headSong = tmpSong;
        }
        else {
            newPosPrev->InsertAfter(tmpSong);
        }
      
    }
    else {
        // Moving up the list
        prevSong->SetNext(afterSong);
        if (newPos < currPos) {
            // Moving to the headSong
            if (newPos <= 1) {
                tmpSong->SetNext(headSong);
                headSong = tmpSong;
            } else {
                newPosPrev->InsertAfter(tmpSong);
            }
        }
        // Moving down the list
        else if (newPos > currPos) {
            // Moving to the tailSong
            if (newPos >= numSongs) {
                tailSong->InsertAfter(tmpSong);
                tailSong = tmpSong;
            } else {
                currSong->InsertAfter(tmpSong);
            }
        }
    }
    cout << '"' << tmpSong->GetSongName() << '"' << " moved to position " << newPos << endl;
    cout << endl;
}

// Output songs by specific artist
void Playlist::OutputSongByArtist() {
    PlaylistNode* currSong = nullptr;
    string userArtistName;
    int i = 1;

    cin.ignore();
    cout << "Enter artist's name:" << endl;
    getline(cin, userArtistName);
    cout << endl;
    
    currSong = headSong;

    while ( currSong != nullptr) {
        if (userArtistName == currSong->GetArtistName()) {
            cout << i << '.' << endl;
            currSong->PrintPlaylistNode();
        }
        currSong = currSong->GetNext();
        i++;
    }
}

// Output total duration of all songs in playlist
void Playlist::OutputTotTime() {
    PlaylistNode* currSong = nullptr;
    int timeInSec = 0;

    currSong = headSong;
    while(currSong != nullptr) {
        timeInSec += currSong->GetSongLength();
        currSong = currSong->GetNext();
    }

    cout << "Total time: " << timeInSec << " seconds" << endl;
    cout << endl;
}