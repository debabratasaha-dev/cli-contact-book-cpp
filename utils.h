#pragma once
#include <vector>
#include "contacts.h"
using namespace std;

void viewAll(vector<Contact>& contacts);
string toUpperCase(string str);
void add(vector<Contact>& contacts);
size_t search(vector<Contact> contacts, string key);
void edit(vector<Contact>& contacts, int pos);
void del(vector<Contact>& contacts, int pos);
void exitProgram(vector<Contact>& contacts);
