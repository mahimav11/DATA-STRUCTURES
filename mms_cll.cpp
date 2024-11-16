#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    string artist;
    double duration;
    Node* next;
};

class MusicManagement {
    Node* last;

public:
    MusicManagement() {
        last = NULL;
    }

    // Add a song at the start
    void addSongAtStart() {
        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter song title: ";
        getline(cin, newNode->title);
        cout << "Enter artist: ";
        getline(cin, newNode->artist);
        cout << "Enter duration (in minutes): ";
        cin >> newNode->duration;

        if (last == NULL) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "Song added at the start of the playlist.\n";
    }

    // Add a song at the end
    void addSongAtEnd() {
        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter song title: ";
        getline(cin, newNode->title);
        cout << "Enter artist: ";
        getline(cin, newNode->artist);
        cout << "Enter duration (in minutes): ";
        cin >> newNode->duration;

        if (last == NULL) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Song added to the end of the playlist.\n";
    }

    // Add a song after a specified position
    void addSongAfterPosition(int pos) {
        if (last == NULL) {
            cout << "The playlist is empty. Adding song as the first song.\n";
            addSongAtEnd();
            return;
        }

        Node* temp = last->next;
        int count = 1;

        // Traverse to the specified position
        while (count < pos && temp != last) {
            temp = temp->next;
            count++;
        }

        if (count != pos) {
            cout << "Position out of range. Adding song at the end.\n";
            addSongAtEnd();
            return;
        }

        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter song title: ";
        getline(cin, newNode->title);
        cout << "Enter artist: ";
        getline(cin, newNode->artist);
        cout << "Enter duration (in minutes): ";
        cin >> newNode->duration;

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == last) {
            last = newNode;
        }

        cout << "Song added after position " << pos << ".\n";
    }

    // Display all songs
    void displaySongs() const {
        if (last == NULL) {
            cout << "No songs in the playlist.\n";
            return;
        }

        Node* temp = last->next;
        cout << "\nSongs List:\n";
        cout << "Title\t\tArtist\t\tDuration\n";
        do {
            cout << temp->title << "\t\t" << temp->artist << "\t\t" << temp->duration << " min\n";
            temp = temp->next;
        } while (temp != last->next);
    }

    // Delete the first song
    void deleteFirstSong() {
        if (last == NULL) {
            cout << "The playlist is empty.\n";
            return;
        }

        Node* temp = last->next;
        if (last == temp) {
            last = NULL;
        } else {
            last->next = temp->next;
        }
        delete temp;
        cout << "First song deleted from the playlist.\n";
    }

    // Delete the last song
    void deleteLastSong() {
        if (last == NULL) {
            cout << "The playlist is empty.\n";
            return;
        }

        Node* temp = last->next;
        if (last == temp) {
            delete last;
            last = NULL;
        } else {
            while (temp->next != last) {
                temp = temp->next;
            }
            temp->next = last->next;
            delete last;
            last = temp;
        }
        cout << "Last song deleted from the playlist.\n";
    }
         void searchSong(const string& title) const {
        if (last == NULL) {
            cout << "The playlist is empty.\n";
            return;
        }

        Node* temp = last->next;
        bool found = false;
        do {
            if (temp->title == title) {
                cout << "Song found!\n";
                cout << "Title: " << temp->title << "\nArtist: " << temp->artist << "\nDuration: " << temp->duration << " min\n";
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != last->next);

        if (!found) {
            cout << "Song titled '" << title << "' not found in the playlist.\n";
        }
    }
    // Delete a song at a specified position
    void deleteSongAtPosition(int pos) {
        if (last == NULL) {
            cout << "The playlist is empty.\n";
            return;
        }

        if (pos == 1) {
            deleteFirstSong();
            return;
        }

        Node* temp = last->next;
        Node* prev = NULL;
        int count = 1;

        while (count < pos && temp != last) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (count != pos) {
            cout << "Position out of range.\n";
            return;
        }

        prev->next = temp->next;
        if (temp == last) {
            last = prev;
        }
        delete temp;
        cout << "Song at position " << pos << " deleted from the playlist.\n";
    }
    int countSongs() const {
        if (last == NULL) {
            return 0;
        }

        int count = 0;
        Node* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);

        return count;
    }
    ~MusicManagement() {
        if (last == NULL) return;

        Node* temp = last->next;
        while (temp != last) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete last;
        last = NULL;
    }
};

int main() {
    MusicManagement music;
    int choice, pos;
    string title;

    do {
        cout << "\nSelect an option:\n";
        cout << "1. Add a song at the start\n";
        cout << "2. Add a song at the end\n";
        cout << "3. Add a song after a position\n";
        cout << "4. Display all songs\n";
        cout << "5. Delete the first song\n";
        cout << "6. Delete the last song\n";
        cout << "7. Delete song at position\n";
        cout<<  "8.Search Song\n";
        cout<< "9. Count Songs\n"; 
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                music.addSongAtStart();
                break;
            case 2:
                music.addSongAtEnd();
                break;
            case 3:
                cout << "Enter the position after which to add: ";
                cin >> pos;
                music.addSongAfterPosition(pos);
                break;
            case 4:
                music.displaySongs();
                break;
            case 5:
                music.deleteFirstSong();
                break;
            case 6:
                music.deleteLastSong();
                break;
            case 7:
                cout << "Enter the position to delete: ";
                cin >> pos;
                music.deleteSongAtPosition(pos);
                break;
            case 8: cin.ignore();
                cout << "Enter the title of the song to search: ";
                getline(cin, title);
                music.searchSong(title);
                break;
            case 9: cout << "Total number of songs: " << music.countSongs() << endl;
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 11);

    return 0;
}
