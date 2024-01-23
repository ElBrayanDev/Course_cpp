/*
# SONG PLAYER
In this challenge you will create a menu driven application that
will simulate a user playing songs from a playlist of songs.

We will use a list to simulate the user selecting the the first song in the playlist and
then selecting next and previous to play forward of backwards through the
playlist.

Please refer to the video demo run.

We will also allow users to add new song to the playlist and they
will be added prior to the currently playing song.
The menu looks as follows:

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
========================
Enter a selection (Q to quit):

And the available playlist is modeled as a std::list<Song>
I will provide the Song class. Following are the songs in the playlist.
I grabbed these from the pop charts, you can use them or change
them to any songs you wish.

God's Plan            Drake                        5
Never Be The Same     Camila Cabello               5
Pray For Me           The Weekend and K. Lamar     4
The Middle            Zedd, Maren Morris & Grey    5
Wait                  Maroone 5                    4
Whatever It Takes     Imagine Dragons              6

I have provided the starting project.
Have fun!

Note:
If you have trouble reading input, you can clear std::cin and
ignore everything in the buffer with:

std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

Make sure you #include <limits> to use it.

todo

* last song in list
* save final playlist on a file and read it from the same source
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <fstream>
#include <algorithm>
#include <numeric>

#include <limits>
#include <list>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    string name;
    string artist;
    int rating;

public:
    Song() = default;
    Song(string name, string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}

    string get_name() const { return name; }
    string get_artist() const { return artist; }
    int get_rating() const { return rating; }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }

    string get_name() { return name; }
    string get_artist() { return artist; }
    int get_rating() { return rating; }
};

/// @brief allows to output Song objects with <<
/// @param os output stream
/// @param s Song obj
/// @return defined output stream
std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

/// @brief Displays by using << the current Song depending on the iterator
/// @param song
void play_current_song(const Song &song)
{
    cout << "\nPlaying: \n"
         << song << endl;
}

/// @brief displays all the list of Song obj, uses <<
/// @param playlist std::list<Song> &
/// @param current_song Song & - relies on iterator
void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    for (const auto &c : playlist)
    {
        cout << c << endl;
    }

    play_current_song(current_song);
}

/// @brief reads the system file "songs.txt"
/// @param playlist std::list<Song> &
void read_file(std::list<Song> &playlist)
{
    string name{}, artist{};
    int score{};
    std::ifstream input;
    input.open("songs.txt");

    if (!input)
    {
        cerr << "Wasn't able to open file 'songs.txt'" << endl;
    }
    else
    {
        while (getline(input, name) && getline(input, artist) && input >> score >> std::ws)
        {
            playlist.emplace_back(name, artist, score);
        }
    }
}

/// @brief Plays the first song of the list
/// @param playlist std::list<Song> &
/// @param current_song std::list<Song>::iterator &
void play_first_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    cout << "Playing first song" << endl;
    current_song = playlist.begin();
    play_current_song(*current_song);
}

/// @brief Plays the last song of the list
/// @param playlist std::list<Song> &
/// @param current_song std::list<Song>::iterator &
void play_last_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    cout << "Playing last song" << endl;
    current_song = playlist.end();
    current_song--;
    play_current_song(*current_song);
}

/// @brief Plays the next song of the list, relies on iterator position
/// @param playlist std::list<Song> &
/// @param current_song std::list<Song>::iterator &
void play_next_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    cout << "Playing next song" << endl;

    //! checks if it is the last song

    current_song++;
    if (current_song == playlist.end())
    {
        cout << "Wrapping to start of playlist" << endl;
        current_song = playlist.begin();
    }

    play_current_song(*current_song);
}

/// @brief Plays the previous song of the list, relies on iterator position
/// @param playlist std::list<Song> &
/// @param current_song std::list<Song>::iterator &
void play_previous_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    cout << "Playing previous song" << endl;

    //! checks if it is the first song

    if (current_song == playlist.begin())
    {
        cout << "Wrapping to start of playlist" << endl;
        current_song = playlist.end();
    }
    current_song--;

    play_current_song(*current_song);
}

/// @brief Adds a new song before the iterator actual position
/// @param playlist std::list<Song> &
/// @param current_song std::list<Song>::iterator &
void add_new_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    cout << "Adding a new song" << endl;
    string name{}, artist{};
    int score{};

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Type the name of the song: ";
    getline(cin, name);
    cout << "Name of the artist: ";
    getline(cin, artist);
    cout << "Rating: ";
    cin >> score;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    playlist.insert(current_song, Song(name, artist, score));
    current_song--;
    play_current_song(*current_song);
}

/// @brief Saves the current playlist to the same "songs.txt" file
/// @param playlist std::list<Song> &
/// @param current_song std::list<Song>::iterator &
void save_playlist(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    cout << "Saving playlist in 'songs.txt' " << endl;

    std::ofstream output;
    output.open("songs.txt");

    if (!output)
    {
        cerr << "Wasn't able to open file 'songs.txt'" << endl;
    }
    else
    {
        for (const auto &c : playlist)
        {
            output << c.get_name() << endl
                   << c.get_artist() << endl
                   << c.get_rating() << endl;
        }
    }
}

/// @brief displays menu with user options
void display_menu()
{
    cout << "\nF - Play First Song" << endl;
    cout << "L - Play Last Song" << endl;
    cout << "N - Play Next song" << endl;
    cout << "P - Play Previous song" << endl;
    cout << "A - Add and play a new Song at current location" << endl;
    cout << "D - Display the current playlist" << endl;
    cout << "S - Save the current playlist in a text file" << endl;
    cout << "===============================================" << endl;
    cout << "Enter a selection (Q to quit): ";
}

/// @brief gets the option based on display_menu and uses the action defined by choice
/// @param choice user char typed
/// @param playlist list of Song
/// @param current_song Song got by *it
void action(char choice, std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    switch (choice)
    {
    case 'F':
        play_first_song(playlist, current_song);
        break;

    case 'L':
        play_last_song(playlist, current_song);
        break;

    case 'N':
        play_next_song(playlist, current_song);
        break;

    case 'P':
        play_previous_song(playlist, current_song);
        break;

    case 'A':
        add_new_song(playlist, current_song);
        break;

    case 'S':
        save_playlist(playlist, current_song);
        break;

    case 'D':
        display_playlist(playlist, *current_song);
        break;

    case 'Q':
        cout << "Closing Program" << endl;
        break;

    default:
        break;
    }
}

int main()
{
    std::list<Song> playlist{};
    char choice{};

    read_file(playlist);

    std::list<Song>::iterator current_song = playlist.begin();

    display_playlist(playlist, *current_song);

    do
    {
        display_menu();
        cin >> choice;
        cout << endl;
        choice = std::toupper(choice);
        action(choice, playlist, current_song);

    } while (choice != 'Q');

    cout << "Thanks for listening!" << endl;
    return 0;
}