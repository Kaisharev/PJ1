#pragma once
#include <string>

class IAccount {
    public:
        virtual ~IAccount () = default;
        virtual std::string getId () const = 0;
        virtual double getBalance () const = 0;
        virtual bool canWithdraw (double amount) {
            return amount <= getBalance ();
        }
        virtual void withdraw (double amount) = 0;
        virtual void deposit (double amount) = 0;
        virtual std::string type () const = 0;
};