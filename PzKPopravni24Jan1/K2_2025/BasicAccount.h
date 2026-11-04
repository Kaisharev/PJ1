#pragma once
#include <stdexcept>

#include "IAccount.h"
class BasicAccount : public IAccount {
    private:
        std::string _id;
        double _balance;

    public:
        BasicAccount (std::string id, double balance) : _id (id), _balance (balance) {};
        std::string getId () const override {
            return this->_id;
        }
        double getBalance () const override {
            return this->_balance;
        }
        void withdraw (double amount) override {
            if (!(amount > 0.0)) throw std::invalid_argument ("amount must be positive");

            if (!canWithdraw (amount)) throw std::domain_error ("Ne možete povući sa računa više no što imate!");
            _balance -= amount;
        }
        void deposit (double amount) override {
            if (!(amount > 0.0)) throw std::invalid_argument ("amount must be positive");

            _balance += amount;
        }
        std::string type () const override {
            return "BasicAccount";
        }
};