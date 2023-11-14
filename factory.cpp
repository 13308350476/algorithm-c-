#include"iostream"
#include <vector>
#include<stack>
#include<queue>
#include <unordered_map>
#include <memory>
#include <string>
#include <mutex>
using namespace std;

enum coretype{
    typeA,
    typeB
};

class core {
    public:
        virtual ~core(){};
        virtual void show() = 0;
};

class singlecoreA_: public core {
    public:
        void show(){cout << "this is singlecoreA" << endl;}
};

class singlecoreB_: public core {
    public:
        void show(){cout << "this is singlecoreB" << endl;}
};

class Factory_simple {
    public:
        core* createcore(coretype type) {
            switch(type) {
                case typeA:
                    return new singlecoreA_();
                    break;
                case typeB:
                    return new singlecoreB_();
                    break;
                default:
                    return nullptr;
            }
        };
};


class Factory_classic{
    public:
        virtual ~Factory_classic(){};
        virtual core* cratecore() = 0;
};

class FactoryA: public Factory_classic{
    public:
        core* cratecore() {
            return new singlecoreA_();
        }
};

class computer {
    public:
        virtual ~computer(){};
        virtual void show() = 0;
};

class computer_A: public  computer{
    public:
        void show() {
            cout << "this is computer_A" << endl;
        };
};

class computer_B: public computer {
    public:
        void show() {
            cout << "this is computer_B" << endl;
        };
};

class Factory_abstract{
    public:
        virtual ~Factory_abstract(){};
        virtual core* creatcore() = 0;
        virtual computer* creatcomputer() = 0;
};

class Factory_abstract_A: public Factory_abstract{
    public:
        core* creatcore() {
            return new singlecoreA_();
        }
        computer* creatcomputer() {
            return new computer_A();
        }
};


int main() {
    // Factory_simple* fac = new Factory_simple();
    // core* cor = fac->createcore(typeA);
    // Factory_classic *fac = new FactoryA();
    // core* cor = fac->cratecore();
    Factory_abstract *fac = new Factory_abstract_A();
    core* cor = fac->creatcore();
    computer* com = fac->creatcomputer();
    cor->show();
    com->show();
    return 0;
}