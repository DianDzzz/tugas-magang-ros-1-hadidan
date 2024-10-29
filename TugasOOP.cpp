#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data pemain
struct Player {
    string uuid;
    string name;
    int level;
    string rank; // rank dapat berupa "bronze", "silver", "gold", "diamond"
};

// Class untuk menyimpan data tim
class Team {
public:
    string teamName;
    string gameMode;
    Player players[4];
    int playerCount = 0;

    // Tambahkan pemain ke tim
    void addPlayer(const string& uuid, const string& name, int level, const string& rank) {
        if (playerCount < 4) {
            players[playerCount].uuid = uuid;
            players[playerCount].name = name;
            players[playerCount].level = level;
            players[playerCount].rank = rank;
            playerCount++;
        }
    }
};

// Class untuk mengelola data pertandingan Bedwars
class BedwarsManager {
private:
    Team teams[100];
    int teamCount = 0;

public:
    // Tambah tim baru ke sistem
    void createTeam(const string& gameMode, const string& teamName) {
        if (teamCount < 100) {
            teams[teamCount].gameMode = gameMode;
            teams[teamCount].teamName = teamName;
            teamCount++;
        }
    }

    // Tambah pemain ke tim berdasarkan indeks tim
    void addPlayerToTeam(int teamIndex, const string& uuid, const string& name, int level, const string& rank) {
        if (teamIndex >= 0 && teamIndex < teamCount) {
            teams[teamIndex].addPlayer(uuid, name, level, rank);
        }
    }

    // Tampilkan data semua tim
    void displayTeams() const {
        for (int i = 0; i < teamCount; i++) {
            cout << "Tim " << teams[i].teamName << " (Mode: " << teams[i].gameMode << "):\n";
            for (int j = 0; j < teams[i].playerCount; j++) {
                cout << " - " << teams[i].players[j].name 
                     << " (" << teams[i].players[j].rank << "), Level: " 
                     << teams[i].players[j].level << "\n";
            }
        }
    }

    // Edit data pemain di dalam tim
    void editPlayerInTeam(int teamIndex, int playerIndex, const string& name, int level) {
        if (teamIndex >= 0 && teamIndex < teamCount && playerIndex >= 0 && playerIndex < teams[teamIndex].playerCount) {
            teams[teamIndex].players[playerIndex].name = name;
            teams[teamIndex].players[playerIndex].level = level;
            cout << "Data pemain berhasil diupdate.\n";
        } else {
            cout << "Tim atau pemain tidak ditemukan.\n";
        }
    }

    // Hapus tim berdasarkan indeks
    void deleteTeam(int teamIndex) {
        if (teamIndex >= 0 && teamIndex < teamCount) {
            for (int i = teamIndex; i < teamCount - 1; i++) {
                teams[i] = teams[i + 1];
            }
            teamCount--;
            cout << "Tim berhasil dihapus.\n";
        } else {
            cout << "Tim tidak ditemukan.\n";
        }
    }
};

int main() {
    BedwarsManager manager;
    int choice, teamIndex, playerIndex;
    string gameMode, teamName, uuid, name, rank;
    int level;

    do {
        cout << "\n Sistem Manajemen Bedwars \n";
        cout << "(1) Tambah Tim\n";
        cout << "(2) Tambah Pemain ke Tim\n";
        cout << "(3) Tampilkan Data Tim\n";
        cout << "(4) Edit Pemain\n";
        cout << "(5) Hapus Tim\n";
        cout << "(0/exit) Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan mode permainan (solo, duo, trio, squad): ";
                cin >> gameMode;
                cout << "Masukkan nama tim: ";
                cin >> teamName;
                manager.createTeam(gameMode, teamName);
                break;

            case 2:
                cout << "Masukkan indeks tim: ";
                cin >> teamIndex;
                cout << "Masukkan UUID: ";
                cin >> uuid;
                cout << "Masukkan nama pemain: ";
                cin >> name;
                cout << "Masukkan level pemain: ";
                cin >> level;
                cout << "Masukkan rank (bronze, silver, gold, diamond): ";
                cin >> rank;
                manager.addPlayerToTeam(teamIndex, uuid, name, level, rank);
                break;

            case 3:
                manager.displayTeams();
                break;

            case 4:
                cout << "Masukkan indeks tim: ";
                cin >> teamIndex;
                cout << "Masukkan indeks pemain: ";
                cin >> playerIndex;
                cout << "Masukkan nama baru: ";
                cin >> name;
                cout << "Masukkan level baru: ";
                cin >> level;
                manager.editPlayerInTeam(teamIndex, playerIndex, name, level);
                break;

            case 5:
                cout << "Masukkan indeks tim: ";
                cin >> teamIndex;
                manager.deleteTeam(teamIndex);
                break;

            case 0:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);

    return 0;
}
