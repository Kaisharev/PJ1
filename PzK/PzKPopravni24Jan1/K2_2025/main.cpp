#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

// Uključi svoje header fajlove ovdje
#include "Bank.h"
#include "BasicAccount.h"
#include "CreditAccount.h"

// --- POMOĆNI MAKRO ZA TESTIRANJE IZUZETAKA ---
// Ovaj makro pokušava izvršiti kod. Ako kod NE baci izuzetak,
// assert će prekinuti program jer očekujemo grešku.
#define ASSERT_THROWS(statement)                                                                                     \
    do {                                                                                                             \
        try {                                                                                                        \
            statement;                                                                                               \
            std::cerr << "FAIL: Ocekivan izuzetak u liniji " << __LINE__ << ", ali nista nije baceno." << std::endl; \
            assert (false);                                                                                          \
        } catch (...) {                                                                                              \
            /* OK: Izuzetak je uhvacen, test prolazi */                                                              \
        }                                                                                                            \
    } while (0)

// ==========================================
// 1. & 2. TESTIRANJE RAČUNA
// ==========================================
void testBasicAccount () {
    std::cout << "Testiram BasicAccount... ";

    // Kreiranje
    BasicAccount acc ("B1", 100.0);
    assert (acc.getId () == "B1");
    assert (acc.getBalance () == 100.0);
    assert (acc.type () == "BasicAccount");

    // Deposit
    acc.deposit (50.0);
    assert (acc.getBalance () == 150.0);

    // Withdraw (validan)
    acc.withdraw (50.0);
    assert (acc.getBalance () == 100.0);

    // Withdraw (nevalidan - nema dovoljno sredstava)
    // BasicAccount ne smije u minus
    ASSERT_THROWS (acc.withdraw (150.0));

    // Stanje mora ostati nepromijenjeno nakon neuspjelog povlačenja
    assert (acc.getBalance () == 100.0);

    std::cout << "OK!" << std::endl;
}

void testCreditAccount () {
    std::cout << "Testiram CreditAccount... ";

    // ID, Balance=100, Limit=200 (znaci moze do -200)
    CreditAccount acc ("C1", 100.0, 200.0);
    assert (acc.type () == "CreditAccount");

    // Povlačenje koje ide u minus (validno jer je unutar limita)
    // 100 - 250 = -150. To je > -200.
    acc.withdraw (250.0);
    assert (acc.getBalance () == -150.0);

    // Povlačenje preko limita
    // Trenutno -150. Limit je -200. Ako skinemo jos 60, idemo na -210. To ne smije.
    ASSERT_THROWS (acc.withdraw (60.0));

    // Stanje ostaje -150
    assert (acc.getBalance () == -150.0);

    std::cout << "OK!" << std::endl;
}

// ==========================================
// 3. TESTIRANJE BANKE (Add & Get)
// ==========================================
void testBankBasics () {
    std::cout << "Testiram Bank (Add/Get)... ";

    Bank bank;
    // unique_ptr se ne moze kopirati, moramo koristiti std::move ili kreirati direktno
    bank.add (std::make_unique<BasicAccount> ("BA1", 500.0));

    // Validno dohvatanje
    IAccount& acc = bank.getAccountById ("BA1");
    assert (acc.getId () == "BA1");
    assert (acc.getBalance () == 500.0);

    // Dohvatanje nepostojećeg
    ASSERT_THROWS (bank.getAccountById ("DUH"));

    std::cout << "OK!" << std::endl;
}

// ==========================================
// 4. TESTIRANJE TRANSFERA
// ==========================================
void testTransfer () {
    std::cout << "Testiram Transfer... ";

    Bank bank;
    bank.add (std::make_unique<BasicAccount> ("USER1", 1000.0));
    bank.add (std::make_unique<BasicAccount> ("USER2", 100.0));

    // 1. Uspješan transfer
    bank.transfer ("USER1", "USER2", 200.0);
    assert (bank.getAccountById ("USER1").getBalance () == 800.0);
    assert (bank.getAccountById ("USER2").getBalance () == 300.0);

    // 2. Neuspješan transfer (nema para)
    // USER2 ima 300, pokušava poslati 500
    ASSERT_THROWS (bank.transfer ("USER2", "USER1", 500.0));

    // Provjera da pare nisu nestale (rollback ili check-first logika)
    assert (bank.getAccountById ("USER2").getBalance () == 300.0);
    assert (bank.getAccountById ("USER1").getBalance () == 800.0);

    // 3. Neuspješan transfer (pogrešan ID)
    ASSERT_THROWS (bank.transfer ("USER1", "NEPOSTOJI", 50.0));

    std::cout << "OK!" << std::endl;
}

// ==========================================
// 5. TESTIRANJE SERIJALIZACIJE
// ==========================================
void testSerialization () {
    std::cout << "Testiram Serijalizaciju... ";

    Bank bank;
    bank.add (std::make_unique<BasicAccount> ("B_ACC", 100.0));
    bank.add (std::make_unique<CreditAccount> ("C_ACC", -50.0, 500.0));

    std::stringstream ss;
    bank.serialize (ss);
    std::string output = ss.str ();

    // Provjeravamo da li string sadrži ključne podatke
    // std::string::npos znači "nije pronađeno"
    assert (output.find ("B_ACC") != std::string::npos);
    assert (output.find ("100") != std::string::npos);
    assert (output.find ("BasicAccount") != std::string::npos);  // Provjera type()

    assert (output.find ("C_ACC") != std::string::npos);
    assert (output.find ("CreditAccount") != std::string::npos);

    std::cout << "OK!" << std::endl;
}

int main () {
    try {
        testBasicAccount ();
        testCreditAccount ();
        testBankBasics ();
        testTransfer ();
        testSerialization ();

        std::cout << "\n---------------------------------------------------\n";
        std::cout << "SVI TESTOVI SU USPJESNO PROSLI! CESTITAM KOLEGA/INICE!";
        std::cout << "\n---------------------------------------------------\n";
    } catch (const std::exception& e) {
        std::cerr << "NEUHVACEN IZUZETAK U MAINU: " << e.what () << std::endl;
        return 1;
    }

    return 0;
}