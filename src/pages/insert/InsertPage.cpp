#include "InsertPage.hpp"
#include "../../core/input/Input.hpp"
#include "../../core/input/InputBuilder.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../../entity/Product.hpp"
#include "../util/PausePage.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using Pages::Insert::InsertPage, std::cout, std::endl, std::setw, std::setfill,
    Core::Input::Input, Core::Input::InputBuilder, Entity::Product;

void InsertPage::execute() {
    this->clearScreen();

    auto productRepository = Repositories::ProductRepositoryFactory::getInstance();
    InputBuilder inputBuilder;

    cout << "╔════════════════════════════════════╗" << endl;
    cout << "║                                    ║" << endl;
    cout << "║            INPUT PRODUK            ║" << endl;
    cout << "║                                    ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;

    Input *inputCode = inputBuilder.setPrefix("\nInput Code Produk\t: ")->build();
    inputBuilder.fresh();
    Input *inputName = inputBuilder.setPrefix("Input Nama Produk\t: ")->build();
    inputBuilder.fresh();
    Input *inputPrice = inputBuilder.setPrefix("Input Harga Produk\t: ")->build();

    try {
        inputCode->execute();
        inputName->execute();
        inputPrice->execute();

        float price = std::stof(inputPrice->getRawInput());

        productRepository->insert(
            new Product({inputCode->getRawInput(), inputName->getRawInput(), price}));

        cout << "\n[SUKSES] Produk berhasil ditambahkan\n";
    } catch (const std::invalid_argument &e) {
        cout << "\n[ERROR] Input harga tidak valid. Harap masukkan angka yang benar.\n";
    } catch (const std::out_of_range &e) {
        cout << "\n[ERROR] Harga produk terlalu besar untuk diproses.\n";
    } catch (const std::exception &e) {
        cout << "\n[ERROR] Terjadi kesalahan: " << e.what() << endl;
    }

    this->renderPageDirectly(new Util::PausePage());
    delete inputCode;
    delete inputName;
    delete inputPrice;
}