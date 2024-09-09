// NAME : SPARSH GANDHI
// PRN : 123B1B113

#include <iostream>
#include <time.h>

using namespace std;
// Define the structure for a song node
struct Song
{
    string title;
    Song *next;
};
// Define the Playlist class
class Playlist
{
public:
    Song *head;
    // Constructor to initialize the playlist
    Playlist()
    {
        head = nullptr;
    }
    // Destructor to free the memory
    ~Playlist()
    {
        while (head)
        {
            Song *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Function to add a song to the playlist
    void addSong(string title)
    {
        Song *newSong = new Song();
        newSong->title = title;
        newSong->next = nullptr;
        if (!head)
        {
            head = newSong;
        }
        else
        {
            Song *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newSong;
        }
    }
    // Function to remove a song from the playlist
    void removeSong(string title)
    {
        if (!head)
        {
            cout << "Playlist is empty." << endl;
            return;
        }
        if (head->title == title)
        {
            Song *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Song *temp = head;
        while (temp->next)
        {
            if (temp->next->title == title)
            {
                Song *songToRemove = temp->next;
                temp->next = temp->next->next;
                delete songToRemove;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found in the playlist." << endl;
    }
    // Function to shuffle the playlist
    void shuffle()
    {
        if (!head || !head->next)
        {
            return;
        }
        int length = 0;
        Song *temp = head;
        while (temp)
        {
            length++;
            temp = temp->next;
        }
        for (int i = 0; i < length; i++)
        {
            int randomIndex = rand() % length;
            string tempTitle;
            // Find the song at the random index
            Song *randomSong = head;
            for (int j = 0; j < randomIndex; j++)
            {
                randomSong = randomSong->next;
            }
            // Swap the titles of the current song and the random song
            tempTitle = head->title;
            head->title = randomSong->title;
            randomSong->title = tempTitle;
            // Move to the next song
            head = head->next;
        }
    }
    // Function to print the playlist
    void printPlaylist()
    {
        Song *temp = head;
        while (temp)
        {
            cout << temp->title << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    srand(time(0)); // seed for random number generation
    Playlist myPlaylist;
    while (true)
    {
        cout << "Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit: " << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string title;
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            myPlaylist.addSong(title);
        }
        else if (choice == 2)
        {
            string title;
            cout << "Enter song title to remove: ";
            cin.ignore();
            getline(cin, title);
            myPlaylist.removeSong(title);
        }
        else if (choice == 3)
        {
            myPlaylist.shuffle();
        }
        else if (choice == 4)
        {
            myPlaylist.printPlaylist();
        }
        else if (choice == 5)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }
    return 0;
}
// OUTPUT :

//  (base) pccoe@pccoe:~$ gedit playlist2.cpp
// PS C:\Users\gandh\OneDrive\Desktop\C++ Lab Codes> c

//                                                 > cd "c:\Users\gandh\OneDrive\Desktop\C++ Lab Codes\" ; if ($?) { g++ 113_sparsh_gandhi_ass3.cpp -o 113_sparsh_gandhi_ass3 } ; if ($?) { .\113_sparsh_gandhi_ass3 }
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit: 
// 1
// Enter song title: DIL HAARA
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit:
// 1
// Enter song title: SAJNA
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit:
// 1
// Enter song title: ZAALIMA
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit:
// 4
// DIL HAARA
// SAJNA
// ZAALIMA
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit:
// 2
// Enter song title to remove: SAJNA
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit:
// 4
// DIL HAARA
// ZAALIMA
// Enter 1 to add a song, 2 to remove a song, 3 to shuffle the playlist, 4 to print the playlist, or 5 to exit:
// 5
// PS C:\Users\gandh\OneDrive\Desktop\C++ Lab Codes> 