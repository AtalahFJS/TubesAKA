#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu
#include <fstream>
#include <algorithm> // Untuk sort

using namespace std;

// Fungsi Binary Search Rekursif
int binarySearchRecursive(const vector<string>& judul, int left, int right, const string& target) {
    if (left > right)
        return -1; // Kata tidak ditemukan

    int mid = left + (right - left) / 2; // Hindari overflow
    if (judul[mid] == target)
        return mid; // Kata ditemukan
    else if (judul[mid] < target)
        return binarySearchRecursive(judul, mid + 1, right, target); // Cari di bagian kanan
    else
        return binarySearchRecursive(judul, left, mid - 1, target); // Cari di bagian kiri
}

int main() {
    // Membaca dataset dari file
    ifstream file("dataJudulBuku.txt");
    if (!file) {
        cerr << "Error: Tidak dapat membuka file." << endl;
        return 1;
    }

    vector<string> judul;
    string kata;
    while (file >> kata) { // Membaca setiap kata dari file
        judul.push_back(kata);
    }
    file.close();

    // Pastikan dataset terurut
    sort(judul.begin(), judul.end());

    // Input kata yang dicari
    cout << "Masukkan kata yang ingin dicari: ";
    string target;
    cin >> target;

    // Pengukuran waktu
    auto start = chrono::high_resolution_clock::now();
    int result = binarySearchRecursive(judul, 0, judul.size() - 1, target);
    auto end = chrono::high_resolution_clock::now();

    // Hasil pencarian
    if (result != -1)
        cout << "Kata ditemukan di indeks " << result << endl;
    else
        cout << "Kata tidak ditemukan" << endl;

    // Waktu eksekusi
    chrono::duration<double> duration = end - start;
    cout << "Waktu eksekusi: " << duration.count() << " detik" << endl;

    return 0;
}
