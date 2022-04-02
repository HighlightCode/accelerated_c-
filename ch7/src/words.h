#ifndef GUARD_words_h
#define GUARD_words_h

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_Collection;
typedef std::map<std::string, Rule_Collection> Grammar;

std::istream count_words(std::istream, std::ostream);

std::vector<std::string> split(std::string&);

std::map<std::string, std::vector<int> >
xref(std::istream&, std::vector<std::string> find_words(const std::string&) = split );

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);


