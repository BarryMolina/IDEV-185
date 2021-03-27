//
// Created by Barry Molina on 3/23/21.
//

#ifndef MOLINA_ASSIGNMENT9_FILINGSTATUS_H
#define MOLINA_ASSIGNMENT9_FILINGSTATUS_H

// Specifies the filer's tax filing status
enum class FilingStatus {
    Single,
    Jointly,
    HeadOfHousehold
};

// Array of strings for each filing status enum
static const char *status_str [] = {"Single", "Jointly", "Head of household"};

#endif //MOLINA_ASSIGNMENT9_FILINGSTATUS_H
