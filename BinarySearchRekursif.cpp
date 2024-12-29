#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu
#include <fstream>
#include <algorithm> // Untuk sort

using namespace std;

// Fungsi Binary Search Rekursif
int binarySearchRecursive(const vector<string>& judul, int left, int right, const string& target) {
    if (left > right)
        return -1; // Judul tidak ditemukan

    int mid = left + (right - left) / 2; // Hindari overflow
    if (judul[mid] == target)
        return mid; // Judul ditemukan
    else if (judul[mid] < target)
        return binarySearchRecursive(judul, mid + 1, right, target); // Cari di bagian kanan
    else
        return binarySearchRecursive(judul, left, mid - 1, target); // Cari di bagian kiri
}

int main() {
    // Membaca dataset dari file
    ifstream file("judul.txt"); // Ganti dengan nama file Anda
    if (!file) {
        cerr << "Error: Tidak dapat membuka file." << endl;
        return 1;
    }

    vector<string> judul;
    string line;
    while (getline(file, line)) { // Membaca file per baris (judul)
        judul.push_back(line);
    }
    file.close();

    // Pastikan dataset terurut
    sort(judul.begin(), judul.end());

    // Input judul yang dicari
    cout << "Masukkan judul yang ingin dicari: ";
    string target;
    cin.ignore(); // Membersihkan buffer input
    getline(cin, target);

    // Pengukuran waktu
    auto start = chrono::high_resolution_clock::now();
    int result = binarySearchRecursive(judul, 0, judul.size() - 1, target);
    auto end = chrono::high_resolution_clock::now();

    // Hasil pencarian
    if (result != -1)
        cout << "Judul ditemukan di indeks " << result << endl;
    else
        cout << "Judul tidak ditemukan" << endl;

    // Waktu eksekusi dalam detik
    chrono::duration<double> duration = end - start;
    cout << "Waktu eksekusi: " << duration.count() << " detik" << endl;
    cout << "Total judul: " << judul.size() << endl;

    return 0;
}
