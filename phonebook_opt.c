#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"


/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */

entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    int index = hash(lastName);
    entry *temp;
    temp = pSlot[index].pNext;

    while (temp != NULL) {
        if (strcasecmp(lastName, temp->lastName) == 0) {
            return temp;
        }

        temp = temp->pNext;
    }
    return NULL;

}

entry *append(char lastName[], entry *e)
{
    /* TODO: implement */
    int index = hash(lastName);
    slot = (entry *) malloc(sizeof(entry));

    /* need to check if slot is empty or not */
    if (pSlot[index].pNext == NULL) {
        pSlot[index].pNext = slot;
        strcpy(slot->lastName, lastName);
    } else {
        slot->pNext = pSlot[index].pNext;
        pSlot[index].pNext = slot;
        strcpy(slot->lastName, lastName);
    }

    return e;

}

int hash(char lastName[])
{
    unsigned long hash = 5381;

    while(*lastName) {
        hash = ((hash << 5) + hash) + (*lastName++);
    }

    return hash%HASH_TABLE_SIZE;
}
