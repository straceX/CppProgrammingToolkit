#include <iostream>
#include<string>
#include<bitset>

/* Lets write test code that test whether a string is a rotated form of another string*/
/*result must be oneliner :)*/
bool is_rotate(const std::string &s1, const std::string &s2);

/*Find how many character include*/
size_t count_character(const std::string &sparam,char ch);

/*Find how many words include*/
size_t count_words(const std::string &sparam, const std::string &sword);

/*Find all words and replace*/
size_t replace_all_words(std::string& sparam, const std::string& from, const std::string& to);

/*Control string value's characters unique*/
bool is_string_character_unique(const std::string &sparam);