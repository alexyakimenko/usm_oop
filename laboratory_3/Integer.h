#pragma once

class Integer {
    private:
        int value;
    public:
        Integer();
        Integer(int);
        int get();
        void display();
        Integer operator =(int);
        Integer& operator ++();
        Integer operator ++(int);
        friend Integer& operator --(Integer&); 
        friend Integer operator --(Integer&, int); 
        Integer operator +(Integer&);
        Integer operator +(int);
        friend Integer operator -(Integer&, Integer&);
        Integer operator -(int);
};