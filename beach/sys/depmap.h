#ifndef _H_DEPMAP
#define _H_DEPMAP

enum dependancy_atom_required {
    NON_DEPENDANCY,
    EQUAL_TO,
    GREATER_THAN,
    LESS_THAN,
    GREATER_THAN_OR_EQUAL_TO,
    LESS_THAN_OR_EQUAL_TO,
    ANY_VERSION,
    LATEST
};
/**
 * @brief Set the dependancy map value object
 * 
 * @param parent A package's parent identifier.
 * @param name The Package name.
 * @param version0 *.0.0
 * @param version1 0.*.0
 * @param version2 0.0.*
 * @param dar Dependancy atom operand.
 * @param required_version0 *.0.0
 * @param required_version1 0.*.0
 * @param required_version2 0.0.*
 * @param required_by What package (names) require this?
 * @return int 
 */
int set_dm_value(int parent, char name[], int version0, int version1, int version2, enum dependancy_atom_required dar, int required_version0, int required_version1, int required_version2, char **required_by);
/**
 * @brief Get the dependancy map value object
 * 
 * @param id A package's identifier.
 * @return char* 
 */
char *get_dm_value(int id); // id: parent
/**
 * @brief Override a dependancy map value object
 * 
 * @param parent A package's parent identifier.
 * @param name The Package name.
 * @param version0 *.0.0
 * @param version1 0.*.0
 * @param version2 0.0.*
 * @param dar Dependancy atom operand.
 * @param required_version0 *.0.0
 * @param required_version1 0.*.0
 * @param required_version2 0.0.*
 * @param required_by What package (names) require this?
 * @return int 
 */
int override_dm_value(int parent, char name[], int version0, int version1, int version2, enum dependancy_atom_required dar, int required_version0, int required_version1, int required_version2, char **required_by);


#endif