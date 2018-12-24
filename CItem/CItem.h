//
// Created by martkans on 30.11.18.
//

#ifndef LISTA4_CITEM_H
#define LISTA4_CITEM_H

#include "../Tools/Tools.h"

#define MIN_ITEM_VALUE  1
#define MIN_ITEM_SIZE   1

class CItem {
    public:
        friend class CKnapsackProblem;
        CItem(int value, int size);

    private:
        int value;
        int size;

        bool isValid();
};


#endif //LISTA4_CITEM_H
