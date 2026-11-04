#pragma once
#include <map>
#include <memory>
#include <stdexcept>

#include "IAccount.h"
class Bank {
    private:
        std::map<std::string, std::unique_ptr<IAccount>> map;

    public:
        void add (std::unique_ptr<IAccount> account) {
            map.emplace (account->getId (), std::move (account));
        }
        IAccount& getAccountById (const std::string& id) {
            if (map.find (id) == map.end ()) {
                throw std::out_of_range ("Nije u opsegu, RIP");
            }
            return *(map.at (id));
        }

        const IAccount& getAccountById (const std::string& id) const {
            if (map.find (id) == map.end ()) {
                throw std::out_of_range ("Nije u opsegu, RIP");
            }
            return *(map.at (id));
        }

        void transfer (const std::string& from, const std::string& to, double amount) {
            if (map.find (to) == map.end () || map.find (from) == map.end ()) {
                throw std::out_of_range ("Nije u opsegu, RIP");
            }

            if (!map.at (from)->canWithdraw (amount)) {
                throw std::domain_error ("Ne možete transferovat");

            } else {
                map.at (from)->withdraw (amount);
                map.at (to)->deposit (amount);
            }
        }

        void serialize (std::ostream& os) {
            for (auto& acc : map) {
                IAccount& account = *acc.second;
                os << account.type () << ' ' << account.getId () << ' ' << account.getBalance () << '\n';
            }
        }
};