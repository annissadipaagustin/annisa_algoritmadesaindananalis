#include <iostream> // Untuk input/output
using namespace std;

class contoh {
	private:
		int nilai; // Variabel private
	public: 
	// Constructor ? dipanggil saat objek dibuat
		contoh (int n) {
			nilai = n; 
		}
		// Method untuk mengambil nilai
		int getNum() {
			return nilai; 
		}
		// Destructor belum dibuat di sini, bisa ditambahkan jika perlu
};

int main() {
	contoh obj(10); // Membuat objek, constructor dipanggil
	cout << "nilai yang diinput: " << obj.getNum() << // Cetak nilai
endl;
    return 0;
}
