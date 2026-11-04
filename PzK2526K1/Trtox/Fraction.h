#pragma once
#include <fstream>
#include <numeric>
class Fraction {
    private:
        int numerator_;
        int denominator_;

    public:
        Fraction () : numerator_ (1), denominator_ (1) {};

        Fraction (int num, int den) : numerator_ (num), denominator_ (den) {};
        int getNum () const {
            return this->numerator_;
        }
        int getDen () const {
            return this->denominator_;
        }

        double getVal () const {
            return static_cast<double> (this->numerator_) / this->denominator_;
        }

        void setNum (int num) {
            this->numerator_ = num;
        }
        void setDen (int den) {
            this->denominator_ = den;
        }

        /* Дефинисати методу normalize којом се врши нормализација разломка (скраћивање
и пребацивање минуса у бројилац). */

        void normalize () {
            if (this->denominator_ < 0) {
                this->denominator_ = -(this->denominator_);
                this->numerator_ = -(this->numerator_);
            }
            int gcd = std::gcd (std::abs (this->numerator_), std::abs (this->denominator_));
            this->numerator_ /= gcd;
            this->denominator_ /= gcd;
        }
        Fraction operator+ (const Fraction& other) const {
            int newNumerator = this->numerator_ * other.denominator_ + other.numerator_ * this->denominator_;
            int newDenominator = this->denominator_ * other.denominator_;

            Fraction result (newNumerator, newDenominator);
            result.normalize ();
            return result;
        }
        Fraction operator- (const Fraction& other) const {
            int newNumerator = this->numerator_ * other.denominator_ - other.numerator_ * this->denominator_;
            int newDenominator = this->denominator_ * other.denominator_;

            Fraction result (newNumerator, newDenominator);
            result.normalize ();
            return result;
        }
        Fraction operator* (const Fraction& other) const {
            int newNumerator = this->numerator_ * other.numerator_;
            int newDenominator = this->denominator_ * other.denominator_;

            Fraction result (newNumerator, newDenominator);
            result.normalize ();
            return result;
        }
        Fraction operator+ (const int& other) const {
            int newNumerator = this->numerator_ + other * this->denominator_;
            int newDenominator = this->denominator_;

            Fraction result (newNumerator, newDenominator);
            result.normalize ();
            return result;
        }
        Fraction operator- (const int& other) const {
            int newNumerator = this->numerator_ - other * this->denominator_;
            int newDenominator = this->denominator_;

            Fraction result (newNumerator, newDenominator);
            result.normalize ();
            return result;
        }
        Fraction operator* (const int& other) const {
            int newNumerator = this->numerator_ * other;
            int newDenominator = this->denominator_;

            Fraction result (newNumerator, newDenominator);
            result.normalize ();
            return result;
        }
        bool operator> (const Fraction& other) const {
            return this->getVal () > other.getVal ();
        }
        bool operator< (const Fraction& other) const {
            return this->getVal () < other.getVal ();
        }
        bool operator>= (const Fraction& other) const {
            return this->getVal () >= other.getVal ();
        }
        bool operator<= (const Fraction& other) const {
            return this->getVal () <= other.getVal ();
        }
        bool operator== (const Fraction& other) const {
            return this->getVal () == other.getVal ();
        }

        bool operator> (const int& other) const {
            return this->getVal () > other;
        }
        bool operator< (const int& other) const {
            return this->getVal () < other;
        }
        bool operator>= (const int& other) const {
            return this->getVal () >= other;
        }
        bool operator<= (const int& other) const {
            return this->getVal () <= other;
        }
        bool operator== (const int& other) const {
            return this->getVal () == other;
        }
        friend std::ostream& operator<< (std::ostream& os, const Fraction& fr) {
            os << fr.numerator_ << "/" << fr.denominator_;
            return os;
        }
};