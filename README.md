# Projek Struktur Data

## Pembagian Tugas

Nanti seorang aku akan bikin konfigurasi avl sama hashnya, jadi supaya aku fokus ke situ besok ini dibagi aja tugasnya. Pembagian seperti berikut:

### Vano:

- remove/RemovePage.hpp

  Aku sudah bikin filenya tapi masih kosong, diisi seperti hpp biasanya.

- remove/RemovePage.cpp

  Bikin implementasi di sini. Berikan input code produk yang akan dihapus.

### Adit:

Ini tolong bang.

- show/filter/\*

- show/sort/\*

- show/ShowPage.cpp

- util/ShowProductPage.cpp

  Ini prioritas bang, nantinya tampilan produk akan dibikin template disini, jadi bikin tabel yang bagus, namun juga responsif.

### Jepe:

Catatan kurang lebih sama seperti punya vano. User memiliki 3 opsi, yaitu menampilkan secara in order, post order, pre order.

- history/HistoryPage.cpp

- history/HistoryPage.hpp

---

## Catatan

Karena tampilan produk dibikin sama semua, maka nanti halaman yang menampilkan produk menggunakan template dari util/ShowProductPage.cpp yang akan dikerjakan oleh sang @muhammadaditya. Yang membedakan hanya pada constructor itu tinggal diganti aja argumennya. Jadi filter, sorting, atau yang berkaitan dengan data dikerjakan sebelum masuk ke constructor tersebut.

## Struktur Menu

```asciidoc
insert/
tampilkan/
├─ filter/
│  ├─ kode produk/
│  ├─ rentang nama/
├─ sorting/
│  ├─ ascending/
│  ├─ descending/
history/
├─ in order/
├─ post order/
├─ pre order/
hapus/

```
