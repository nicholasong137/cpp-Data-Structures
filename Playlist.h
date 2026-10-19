#pragma once
#include<string>

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(std::string id, std::string name, std::string artist, int length, PlaylistNode* nextLoc = nullptr);
        
        // Accessors
        std::string GetID() const;
        std::string GetSongName() const;
        std::string GetArtistName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext();

        // Functions
        void InsertAfter(PlaylistNode* nodePtr);
        void SetNext(PlaylistNode* nodePtr);
        void PrintPlaylistNode();

    private:
        std::string uniqueID = "none";
        std::string songName = "none";
        std::string artistName = "none";
        int songLength = 0;
        PlaylistNode* nextNodePtr = nullptr;
};

class Playlist {
    public:
        Playlist();
        int PrintMenu();
        void OutputFullPlaylist();
        void AddMenu();
        void EnterTitle(std::string tmpTitle);
        void RemoveSong();
        void ChangeSongPos();
        void OutputSongByArtist();
        void OutputTotTime();
        
    private:
        char userInput;
        std::string playlistTitle;

        // Used to keep track of num of songs in the list (might be changed later on depending on Add and Remove function)
        int numSongs = 0;

        PlaylistNode* headSong = nullptr;
        PlaylistNode* tailSong = nullptr;
};