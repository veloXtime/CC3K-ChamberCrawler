#ifndef POTION_H
#define POTION_H
#include <memory>
#include "nonliving.h"
using std::shared_ptr;

//abstract component class, to simplify things 
//decorator and component is the same class
class Potion: public NonLiving 
{
    
    protected:
        int val;
    public:
        Potion(); //there is nothing to return
        virtual int effect(); //an instance of this baseclass always return 0
};

#endif
